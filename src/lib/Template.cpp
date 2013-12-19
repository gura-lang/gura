#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Template
//-----------------------------------------------------------------------------
Template::Template() : _cntRef(1), _pExprOwnerForInit(new ExprOwner()),
								_pValueMap(new ValueMap()), _pStreamDst(NULL)
{
}

bool Template::Read(Environment &env, Signal sig,
			SimpleStream &streamSrc, bool autoIndentFlag, bool appendLastEOLFlag)
{
	Parser parser(autoIndentFlag, appendLastEOLFlag);
	return parser.ParseStream(env, sig, this, streamSrc);
}

bool Template::Render(Environment &env, Signal sig, SimpleStream *pStreamDst)
{
	Template *pTemplateTop = NULL;
	for (Template *pTemplate = this; pTemplate != NULL;
							pTemplate = pTemplate->GetTemplateSuper()) {
		if (!pTemplate->Prepare(env, sig)) return false;
		pTemplate->SetStreamDst(pStreamDst);
		pTemplateTop = pTemplate;
	}
	if (pTemplateTop->GetFuncForBody() == NULL) return true;
	AutoPtr<Args> pArgs(new Args());
	pArgs->SetThis(Value(new Object_template(env, Reference())));
	AutoPtr<Environment> pEnvBlock(new Environment(&env, ENVTYPE_local));
	pTemplateTop->GetFuncForBody()->Eval(*pEnvBlock, sig, *pArgs);
	for (Template *pTemplate = this; pTemplate != NULL;
							pTemplate = pTemplate->GetTemplateSuper()) {
		pTemplate->SetStreamDst(NULL);
	}
	return !sig.IsSignalled();
}

bool Template::Prepare(Environment &env, Signal sig)
{
	AutoPtr<Processor> pProcessor(new Processor());
	AutoPtr<Environment> pEnvBlock(new Environment(&env, ENVTYPE_local));
	pEnvBlock->AssignValue(Gura_Symbol(this_),
				Value(new Object_template(env, Reference())), EXTRA_Public);
	_pValueMap->clear();
	pProcessor->PushSequence(new Expr::SequenceRoot(pEnvBlock.release(),
									_pExprOwnerForInit->Reference()));
	pProcessor->Run(sig);
	return !sig.IsSignalled();
}

const ValueEx *Template::LookupValue(const Symbol *pSymbol) const
{
	for (const Template *pTemplate = this; pTemplate != NULL;
							pTemplate = pTemplate->GetTemplateSuper()) {
		const ValueMap &valueMap = pTemplate->GetValueMap();
		ValueMap::const_iterator iter = valueMap.find(pSymbol);
		if (iter != valueMap.end()) return &iter->second;
	}
	return NULL;
}

//-----------------------------------------------------------------------------
// Template::Parser
//-----------------------------------------------------------------------------
Template::Parser::Parser(bool autoIndentFlag, bool appendLastEOLFlag) :
		_autoIndentFlag(autoIndentFlag), _appendLastEOLFlag(appendLastEOLFlag)
{
}

bool Template::Parser::ParseStream(Environment &env, Signal sig,
								Template *pTemplate, SimpleStream &streamSrc)
{
	AutoPtr<StringRef> pSourceName(new StringRef(streamSrc.GetName()));
	char chMarker = '$';
	enum {
		STAT_LineTop, STAT_Indent, STAT_String,
		STAT_ScriptPre, STAT_ScriptFirst, STAT_ScriptSecond,
		STAT_Script, STAT_ScriptPost,
		STAT_Comment, STAT_Comment_LineTop,
		STAT_CommentEnd_Second, STAT_CommentEnd_SeekR, STAT_CommentEnd_Marker,
		STAT_CommentPost,
	} stat = STAT_LineTop;
	bool stringAheadFlag = false;
	String str;
	String strTmplScript;
	String strIndent;
	int cntLine = 0;
	int cntLineTop = 0;
	int nDepth = 0;
	_exprLeaderStack.clear();
	if (pTemplate->GetFuncForBody() == NULL) {
		AutoPtr<FunctionCustom> pFunc(new FunctionCustom(env,
				Gura_Symbol(_anonymous_), new Expr_Block(), FUNCTYPE_Instance));
		pFunc->SetMode(RSLTMODE_Void, FLAG_DynamicScope);
		pTemplate->SetFuncForBody(pFunc.release());
	}
	Expr_Block *pExprBlockRoot = dynamic_cast<Expr_Block *>(
									pTemplate->GetFuncForBody()->GetExprBody());
	for (;;) {
		int chRaw = streamSrc.GetChar(sig);
		if (sig.IsSignalled()) return false;
		if (chRaw < 0) break;
		char ch = static_cast<char>(chRaw);
		bool continueFlag = false;
		do {
			continueFlag = false;
			switch (stat) {
			case STAT_LineTop: {
				if (ch == '\n') {
					str += ch;
				} else if (IsWhite(ch)) {
					continueFlag = true;
					stat = STAT_Indent;
				} else if (ch == chMarker) {
					stat = STAT_ScriptPre;
				} else {
					stringAheadFlag = true;
					continueFlag = true;
					stat = STAT_String;
				}
				break;
			}
			case STAT_Indent: {
				if (IsWhite(ch)) {
					strIndent += ch;
				} else if (ch == chMarker) {
					stat = STAT_ScriptPre;
				} else {
					str += strIndent;
					strIndent.clear();
					stringAheadFlag = true;
					continueFlag = true;
					stat = STAT_String;
				}
				break;
			}
			case STAT_String: {
				if (ch == chMarker) {
					stat = STAT_ScriptPre;
				} else if (ch == '\n') {
					str += ch;
					stringAheadFlag = false;
					stat = STAT_LineTop;
				} else {
					str += ch;
				}
				break;
			}
			case STAT_ScriptPre: {
				if (ch == '{') {
					if (!str.empty()) {
						ExprOwner &exprOwner = _exprLeaderStack.empty()?
							pExprBlockRoot->GetExprOwner() :
							_exprLeaderStack.back()->GetBlock()->GetExprOwner();
						Expr *pExpr = new Expr_TmplString(pTemplate, str);
						pExpr->SetSourceInfo(pSourceName->Reference(), 0, 0);
						exprOwner.push_back(pExpr);
						str.clear();
					}
					cntLineTop = cntLine;
					nDepth = 1;
					strTmplScript.clear();
					stat = STAT_ScriptFirst;
				} else if (ch == chMarker) {
					str += strIndent;
					strIndent.clear();
					str += ch;
					stringAheadFlag = true;
					stat = STAT_String;
				} else {
					str += strIndent;
					strIndent.clear();
					str += ch;
					stringAheadFlag = true;
					continueFlag = true;
					stat = STAT_String;
				}
				break;
			}
			case STAT_ScriptFirst: {
				if (ch == '=') {
					stat = STAT_ScriptSecond;
				} else {
					continueFlag = true;
					stat = STAT_Script;
				}
				break;
			}
			case STAT_ScriptSecond: {
				if (ch == '=') {
					stat = STAT_Comment;
				} else {
					strTmplScript += '=';
					continueFlag = true;
					stat = STAT_Script;
				}
				break;
			}
			case STAT_Script: {
				if (ch == '{') {
					strTmplScript += ch;
					nDepth++;
				} else if (ch == '}') {
					nDepth--;
					if (nDepth > 0) {
						strTmplScript += ch;
						break;
					}
					stat = STAT_ScriptPost;
				} else {
					strTmplScript += ch;
				}
				break;
			}
			case STAT_ScriptPost: {
				const char *strPost = (ch == '\n')? "\n" : "";
				if (!CreateTmplScript(env, sig,
						strIndent.c_str(), strTmplScript.c_str(), strPost,
						pTemplate, pExprBlockRoot,
						pSourceName.get(), cntLineTop, cntLine)) return false;
				strIndent.clear();
				strTmplScript.clear();
				if (ch == '\n') {
					stringAheadFlag = false;
					stat = STAT_LineTop;
				} else {
					stringAheadFlag = true;
					continueFlag = true;
					stat = STAT_String;
				}
				break;
			}
			case STAT_Comment: {
				if (ch == '=') {
					stat = STAT_CommentEnd_Second;
				} else if (ch == '\n') {
					stringAheadFlag = false;
					stat = STAT_Comment_LineTop;
				} else {
					// nothing to do
				}
				break;
			}
			case STAT_Comment_LineTop: {
				if (ch == '=') {
					stat = STAT_CommentEnd_Second;
				} else if (ch == '\n') {
					// nothing to do
				} else if (IsWhite(ch)) {
					// nothing to do
				} else {
					stringAheadFlag = true;
					stat = STAT_Comment;
				}
				break;
			}
			case STAT_CommentEnd_Second: {
				if (ch == '=') {
					stat = STAT_CommentEnd_SeekR;
				} else if (ch == '\n') {
					stringAheadFlag = false;
					stat = STAT_Comment_LineTop;
				} else {
					stringAheadFlag = true;
					stat = STAT_Comment;
				}
				break;
			}
			case STAT_CommentEnd_SeekR: {
				if (ch == '}') {
					stat = STAT_CommentEnd_Marker;
				} else if (ch == '\n') {
					stringAheadFlag = false;
					stat = STAT_Comment_LineTop;
				} else {
					stringAheadFlag = true;
					stat = STAT_Comment;
				}
				break;
			}
			case STAT_CommentEnd_Marker: {
				if (ch == chMarker) {
					stat = STAT_CommentPost;
				} else if (ch == '\n') {
					stringAheadFlag = false;
					stat = STAT_Comment_LineTop;
				} else {
					stringAheadFlag = true;
					stat = STAT_Comment;
				}
				break;
			}
			case STAT_CommentPost: {
				if (!stringAheadFlag && ch == '\n') {
					stringAheadFlag = false;
					continueFlag = false;
					stat = STAT_LineTop;
				} else {
					stringAheadFlag = true;
					continueFlag = true;
					stat = STAT_String;
				}
				break;
			}
			}
		} while (continueFlag);
		if (ch == '\n') cntLine++;
	}
	if (!strTmplScript.empty()) {
		const char *strPost = "";
		if (!CreateTmplScript(env, sig,
				strIndent.c_str(), strTmplScript.c_str(), strPost,
				pTemplate, pExprBlockRoot,
				pSourceName.get(), cntLineTop, cntLine)) return false;
	}
	if (!_exprLeaderStack.empty()) {
		sig.SetError(ERR_SyntaxError, "lacking end statement for block expression");
		return false;
	}
	if (!str.empty()) {
		Expr *pExpr = new Expr_TmplString(pTemplate, str);
		pExpr->SetSourceInfo(pSourceName->Reference(), 0, 0);
		pExprBlockRoot->GetExprOwner().push_back(pExpr);
		str.clear();
	}
	return true;
}

bool Template::Parser::CreateTmplScript(Environment &env, Signal sig,
			const char *strIndent, const char *strTmplScript, const char *strPost,
			Template *pTemplate, Expr_Block *pExprBlockRoot,
			StringRef *pSourceName, int cntLineTop, int cntLineBtm)
{
	Class *pClass = env.LookupClass(VTYPE_template);
	Expr *pExprLast = NULL;
	AutoPtr<Expr_TmplScript> pExprTmplScript(new Expr_TmplScript(
			pTemplate, strIndent, strPost, _autoIndentFlag, _appendLastEOLFlag));
	pExprTmplScript->SetSourceInfo(pSourceName->Reference(), cntLineTop + 1, cntLineBtm + 1);
	if (*strTmplScript == '=') {
		strTmplScript++;
		AutoPtr<ExprOwner> pExprOwnerPart(new ExprOwner());
		do {
			Gura::Parser parser(pSourceName->GetString(), cntLineTop);
			if (!parser.ParseString(env, sig, *pExprOwnerPart, "this.", false)) return false;
			if (!parser.ParseString(env, sig, *pExprOwnerPart, strTmplScript, true)) return false;
		} while (0);
		do {
			ExprOwner &exprOwner = pExprTmplScript->GetExprOwner();
			Gura::Parser parser(pSourceName->GetString(), cntLineTop);
			if (!parser.ParseString(env, sig, exprOwner, "this._R_", false)) return false;
			if (!parser.ParseString(env, sig, exprOwner, strTmplScript, true)) return false;
		} while (0);
		ExprOwner &exprOwnerForPresent = _exprLeaderStack.empty()?
				pExprBlockRoot->GetExprOwner() :
				_exprLeaderStack.back()->GetBlock()->GetExprOwner();
		exprOwnerForPresent.push_back(Expr::Reference(pExprTmplScript.get()));
		foreach (ExprOwner, ppExpr, *pExprOwnerPart) {
			Expr *pExpr = *ppExpr;
			pTemplate->GetExprOwnerForInit().push_back(Expr::Reference(pExpr));
			pExprLast = pExpr;
		}
		if (!pExprLast->IsCaller()) return true;
		Expr_Caller *pExprLastCaller = dynamic_cast<Expr_Caller *>(pExprLast);
		if (pExprLastCaller->GetBlock() == NULL) {
			Callable *pCallable = NULL;
			if (pExprLastCaller->GetCar()->IsMember()) {
				Expr_Member *pExprCar = dynamic_cast<Expr_Member *>(pExprLastCaller->GetCar());
				if (pExprCar->GetLeft()->IsSymbol() &&
						dynamic_cast<Expr_Symbol *>(pExprCar->GetLeft())->GetSymbol()->
														IsIdentical(Gura_Symbol(this_))) {
					pCallable = pExprCar->GetRight()->LookupCallable(*pClass, sig);
				}
			} else {
				pCallable = pExprLastCaller->LookupCallable(env, sig);
			}
			sig.ClearSignal();
			if (pCallable != NULL && pCallable->GetBlockOccurPattern() == OCCUR_Once) {
				Expr_Block *pExprBlock = new Expr_Block();
				pExprLastCaller->SetBlock(pExprBlock);
				_exprLeaderStack.push_back(pExprLastCaller);
			}
		} else if (pExprLastCaller->GetBlock()->GetExprOwner().empty()) {
			_exprLeaderStack.push_back(pExprLastCaller);
		}
	} else {
		AutoPtr<ExprOwner> pExprOwnerPart(new ExprOwner());
		Gura::Parser parser(pSourceName->GetString(), cntLineTop);
		if (!parser.ParseString(env, sig, *pExprOwnerPart, strTmplScript, true)) return false;
		ExprOwner::iterator ppExpr = pExprOwnerPart->begin();
		//::printf("[%s], [%s], [%s]\n", strIndent, strTmplScript, strPost);
		if (ppExpr != pExprOwnerPart->end()) {
			// check if the first Expr is a trailer
			Expr *pExpr = *ppExpr;
			Callable *pCallable = pExpr->LookupCallable(env, sig);
			sig.ClearSignal();
			if (pCallable != NULL && pCallable->IsTrailer()) {
				pExprTmplScript->SetStringIndent("");
				if (_exprLeaderStack.empty()) {
					sig.SetError(ERR_SyntaxError, "unmatching trailer expression");
					sig.AddExprCause(pExprTmplScript.get());
					return false;
				}
				if (!pCallable->IsEndMarker()) {
					Expr_Caller *pExprCaller = NULL;
					if (pExpr->IsCaller()) {
						pExprCaller = dynamic_cast<Expr_Caller *>(Expr::Reference(pExpr));
					} else {
						pExprCaller = new Expr_Caller(Expr::Reference(pExpr), NULL, NULL);
						pExprCaller->SetSourceInfo(pSourceName->Reference(),
										pExpr->GetLineNoTop(), pExpr->GetLineNoBtm());
					}
					_exprLeaderStack.back()->SetTrailer(pExprCaller);
					pExprLast = pExprCaller;
				}
				_exprLeaderStack.pop_back();
				ppExpr++;
			}
		}
		if (ppExpr != pExprOwnerPart->end()) {
			for ( ; ppExpr != pExprOwnerPart->end(); ppExpr++) {
				Expr *pExpr = *ppExpr;
				pExprTmplScript->GetExprOwner().push_back(Expr::Reference(pExpr));
				pExprLast = pExpr;
			}
			ExprOwner &exprOwnerForPresent = _exprLeaderStack.empty()?
					pExprBlockRoot->GetExprOwner() :
					_exprLeaderStack.back()->GetBlock()->GetExprOwner();
			exprOwnerForPresent.push_back(Expr::Reference(pExprTmplScript.get()));
		}
		if (pExprLast == NULL) return true;
		if (!pExprLast->IsCaller()) return true;
		Expr_Caller *pExprLastCaller = dynamic_cast<Expr_Caller *>(pExprLast);
		if (pExprLastCaller->GetBlock() == NULL) {
			Callable *pCallable = NULL;
			if (pExprLastCaller->GetCar()->IsMember()) {
				Expr_Member *pExprCar = dynamic_cast<Expr_Member *>(pExprLastCaller->GetCar());
				if (pExprCar->GetLeft()->IsSymbol() &&
						dynamic_cast<Expr_Symbol *>(pExprCar->GetLeft())->GetSymbol()->
														IsIdentical(Gura_Symbol(this_))) {
					pCallable = pExprCar->GetRight()->LookupCallable(*pClass, sig);
				}
			} else {
				pCallable = pExprLastCaller->LookupCallable(env, sig);
			}
			sig.ClearSignal();
			if (pCallable != NULL && pCallable->GetBlockOccurPattern() == OCCUR_Once) {
				Expr_Block *pExprBlock = new Expr_Block();
				pExprLastCaller->SetBlock(pExprBlock);
				_exprLeaderStack.push_back(pExprLastCaller);
				pExprTmplScript->SetStringIndent("");
				pExprTmplScript->SetStringPost("");
			}
		} else if (pExprLastCaller->GetBlock()->GetExprOwner().empty()) {
			_exprLeaderStack.push_back(pExprLastCaller);
			pExprTmplScript->SetStringIndent("");
			pExprTmplScript->SetStringPost("");
		}
	}
	return true;
}

//-----------------------------------------------------------------------------
// Expr_TmplString
//-----------------------------------------------------------------------------
Expr *Expr_TmplString::Clone() const
{
	return new Expr_TmplString(*this);
}

Value Expr_TmplString::DoExec(Environment &env, Signal sig, SeqPostHandler *pSeqPostHandler) const
{
	_pTemplate->GetStreamDst()->Print(sig, _str.c_str());
	if (pSeqPostHandler != NULL && !pSeqPostHandler->DoPost(sig, Value::Null)) return Value::Null;
	return Value::Null;
}

void Expr_TmplString::Accept(ExprVisitor &visitor) const
{
	visitor.Visit(this);
}

bool Expr_TmplString::GenerateCode(Environment &env, Signal sig, Stream &stream)
{
	stream.Println(sig, "TmplString");
	return true;
}

bool Expr_TmplString::GenerateScript(Signal sig, SimpleStream &stream,
								ScriptStyle scriptStyle, int nestLevel) const
{
	return false;
}

//-----------------------------------------------------------------------------
// Expr_TmplScript
//-----------------------------------------------------------------------------
Expr *Expr_TmplScript::Clone() const
{
	return new Expr_TmplScript(*this);
}

Value Expr_TmplScript::DoExec(Environment &env, Signal sig, SeqPostHandler *pSeqPostHandler) const
{
	if (GetExprOwner().empty()) return Value::Null;
	Value value;
	SeqPostHandler *pSeqPostHandlerEach = NULL;
	foreach_const (ExprList, ppExpr, GetExprOwner()) {
		value = (*ppExpr)->Exec2(env, sig, pSeqPostHandlerEach, true);
		if (sig.IsSignalled()) return Value::Null;
	}
	if (value.IsInvalid()) return Value::Null;
	_pTemplate->GetStreamDst()->Print(sig, _strIndent.c_str());
	String strLast;
	if (value.Is_string()) {
		strLast = value.GetStringSTL();
	} else if (value.Is_list() || value.Is_iterator()) {
		AutoPtr<Iterator> pIterator(value.CreateIterator(sig));
		if (sig.IsSignalled()) return false;
		Value valueElem;
		while (pIterator->Next(env, sig, valueElem)) {
			foreach_const (String, p, strLast) {
				char ch = *p;
				if (ch == '\n') {
					_pTemplate->GetStreamDst()->PutChar(sig, ch);
					if (_autoIndentFlag && valueElem.IsValid()) {
						_pTemplate->GetStreamDst()->Print(sig, _strIndent.c_str());
					}
				} else {
					_pTemplate->GetStreamDst()->PutChar(sig, ch);
				}
			}
			if (valueElem.Is_string()) {
				strLast = valueElem.GetStringSTL();
			} else if (valueElem.IsInvalid()) {
				strLast.clear();
			} else if (valueElem.Is_number()) {
				strLast = valueElem.ToString();
				if (sig.IsSignalled()) return false;
			} else {
				sig.SetError(ERR_TypeError,
					"template script must return nil, string or number");
				sig.AddExprCause(this);
				return Value::Null;
			}
		}
	} else if (value.Is_number()) {
		strLast = value.ToString();
		if (sig.IsSignalled()) return false;
	} else {
		sig.SetError(ERR_TypeError,
			"template script must return nil, string or number");
		sig.AddExprCause(this);
		return Value::Null;
	}
	foreach_const (String, p, strLast) {
		char ch = *p;
		if (ch != '\n') {
			_pTemplate->GetStreamDst()->PutChar(sig, ch);
		} else if (p + 1 != strLast.end()) {
			_pTemplate->GetStreamDst()->PutChar(sig, ch);
			if (_autoIndentFlag) {
				_pTemplate->GetStreamDst()->Print(sig, _strIndent.c_str());
			}
		} else if (_appendLastEOLFlag) {
			_pTemplate->GetStreamDst()->PutChar(sig, ch);
		}
	}
	_pTemplate->GetStreamDst()->Print(sig, _strPost.c_str());
	return Value::Null;
}

bool Expr_TmplScript::GenerateCode(Environment &env, Signal sig, Stream &stream)
{
	stream.Println(sig, "TmplScript");
	return true;
}

bool Expr_TmplScript::GenerateScript(Signal sig, SimpleStream &stream,
								ScriptStyle scriptStyle, int nestLevel) const
{
	return false;
}

Expr_TmplScript::SequenceEx::SequenceEx(Environment *pEnv) : Sequence(pEnv)
{
}

bool Expr_TmplScript::SequenceEx::DoStep(Signal sig, Value &result)
{
	return false;
}

String Expr_TmplScript::SequenceEx::ToString() const
{
	String str;
	str += "<sequence:expr_tmplscript>";
	return str;
}

}
