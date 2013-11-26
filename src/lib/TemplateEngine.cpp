#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// TemplateEngine
//-----------------------------------------------------------------------------
TemplateEngine::TemplateEngine(bool autoIndentFlag, bool appendLastEOLFlag) :
		_autoIndentFlag(autoIndentFlag), _appendLastEOLFlag(appendLastEOLFlag)
{
}

bool TemplateEngine::EvalStream(Environment &env, Signal sig,
					SimpleStream &streamSrc, SimpleStream &streamDst)
{
	const char *sourceName = streamSrc.GetName();
	char chPrefix = '$';
	enum {
		STAT_LineTop, STAT_Indent, STAT_String,
		STAT_ScriptPre, STAT_Script, STAT_ScriptPost,
	} stat = STAT_LineTop;
	String str;
	String strScript;
	String strIndent;
	int cntLine = 0;
	int cntLineStart = 0;
	int nDepth = 0;
	AutoPtr<ExprOwner> pExprOwnerRoot(new ExprOwner());
	ExprCallerStack exprCallerStack;
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
				} else {
					continueFlag = true;
					stat = STAT_String;
				}
				break;
			}
			case STAT_Indent: {
				if (IsWhite(ch)) {
					strIndent += ch;
				} else if (ch == chPrefix) {
					stat = STAT_ScriptPre;
				} else {
					str += strIndent;
					strIndent.clear();
					continueFlag = true;
					stat = STAT_String;
				}
				break;
			}
			case STAT_String: {
				if (ch == chPrefix) {
					stat = STAT_ScriptPre;
				} else if (ch == '\n') {
					str += ch;
					stat = STAT_LineTop;
				} else {
					str += ch;
				}
				break;
			}
			case STAT_ScriptPre: {
				if (ch == '{') {
					if (!str.empty()) {
						ExprOwner &exprOwner = exprCallerStack.empty()?
							*pExprOwnerRoot : exprCallerStack.back()->GetBlock()->GetExprOwner();
						exprOwner.push_back(new Expr_TmplString(streamDst, str));
						str.clear();
					}
					cntLineStart = cntLine;
					nDepth = 1;
					strScript.clear();
					stat = STAT_Script;
				} else if (ch == chPrefix) {
					str += strIndent;
					strIndent.clear();
					str += ch;
					stat = STAT_String;
				} else {
					str += strIndent;
					strIndent.clear();
					str += ch;
					continueFlag = true;
					stat = STAT_String;
				}
				break;
			}
			case STAT_Script: {
				if (ch == '{') {
					strScript += ch;
					nDepth++;
				} else if (ch == '}') {
					nDepth--;
					if (nDepth > 0) {
						strScript += ch;
						break;
					}
					stat = STAT_ScriptPost;
				} else {
					strScript += ch;
				}
				break;
			}
			case STAT_ScriptPost: {
				const char *strPost = (ch == '\n')? "\n" : "";
				if (!ParseScript(env, sig,
						strIndent.c_str(), strScript.c_str(), strPost,
						streamDst, *pExprOwnerRoot, exprCallerStack,
						sourceName, cntLineStart)) return false;
				strIndent.clear();
				strScript.clear();
				if (ch == '\n') {
					continueFlag = false;
					stat = STAT_LineTop;
				} else {
					continueFlag = true;
					stat = STAT_String;
				}
				break;
			}
			}
		} while (continueFlag);
		if (ch == '\n') cntLine++;
	}
	if (!strScript.empty()) {
		const char *strPost = "";
		if (!ParseScript(env, sig,
				strIndent.c_str(), strScript.c_str(), strPost,
				streamDst, *pExprOwnerRoot, exprCallerStack,
				sourceName, cntLineStart)) return false;
	}
	if (!exprCallerStack.empty()) {
		sig.SetError(ERR_SyntaxError, "lacking end statement for block expression");
		return false;
	}
	if (!str.empty()) {
		pExprOwnerRoot->push_back(new Expr_TmplString(streamDst, str));
		str.clear();
	}
	
	
	
	
	AutoPtr<Environment> pEnvBlock(new Environment(&env, ENVTYPE_local));
	do {
		Environment &env = *pEnvBlock;
		SeqPostHandler *pSeqPostHandlerEach = NULL;
		foreach_const (ExprList, ppExpr, *pExprOwnerRoot) {
			(*ppExpr)->Exec2(env, sig, pSeqPostHandlerEach, true);
			if (sig.IsSignalled()) return false;
		}
	} while (0);
	return !sig.IsSignalled();
}

bool TemplateEngine::ParseScript(Environment &env, Signal sig,
			const char *strIndent, const char *strScript, const char *strPost,
			SimpleStream &streamDst, ExprOwner &exprOwnerRoot,
			ExprCallerStack &exprCallerStack,
			const char *sourceName, int cntLineStart)
{
	AutoPtr<ExprOwner> pExprOwnerPart(new ExprOwner());
	Parser parser(sourceName, cntLineStart);
	if (!parser.ParseString(env, sig, *pExprOwnerPart, strScript)) return false;
	Expr_TmplScript *pExprTmplScript = new Expr_TmplScript(
		streamDst, strIndent, strPost, _autoIndentFlag, _appendLastEOLFlag);
	ExprOwner::iterator ppExpr = pExprOwnerPart->begin();
	Expr *pExprLast = NULL;
	//::printf("[%s], [%s], [%s]\n", strIndent, strScript, strPost);
	if (ppExpr != pExprOwnerPart->end()) {
		Expr *pExpr = *ppExpr;
		Callable *pCallable = pExpr->LookupCallable(env, sig);
		sig.ClearSignal();
		if (pCallable != NULL && pCallable->IsTrailer()) {
			pExprTmplScript->SetStringIndent("");
			if (exprCallerStack.empty()) {
				sig.SetError(ERR_SyntaxError, "unmatching trailer expression");
				Expr::Delete(pExprTmplScript);
				return false;
			}
			if (!pCallable->IsEndMarker()) {
				Expr_Caller *pExprCaller = pExpr->IsCaller()?
					dynamic_cast<Expr_Caller *>(Expr::Reference(pExpr)) :
					new Expr_Caller(Expr::Reference(pExpr), NULL, NULL);
				exprCallerStack.back()->SetTrailer(pExprCaller);
				pExprLast = pExprCaller;
			}
			exprCallerStack.pop_back();
			ppExpr++;
		}
	}
	if (ppExpr != pExprOwnerPart->end()) {
		for ( ; ppExpr != pExprOwnerPart->end(); ppExpr++) {
			Expr *pExpr = *ppExpr;
			pExprTmplScript->GetExprOwner().push_back(Expr::Reference(pExpr));
			pExprLast = pExpr;
		}
		ExprOwner &exprOwner = exprCallerStack.empty()?
			exprOwnerRoot : exprCallerStack.back()->GetBlock()->GetExprOwner();
		exprOwner.push_back(pExprTmplScript);
	}
	if (pExprLast == NULL || !pExprLast->IsCaller()) return true;
	Expr_Caller *pExprLastCaller = dynamic_cast<Expr_Caller *>(pExprLast);
	if (pExprLastCaller->GetBlock() == NULL) {
		Callable *pCallable = pExprLastCaller->LookupCallable(env, sig);
		sig.ClearSignal();
		if (pCallable != NULL &&
						pCallable->GetBlockOccurPattern() == OCCUR_Once) {
			Expr_Block *pExprBlock = new Expr_Block();
			pExprLastCaller->SetBlock(pExprBlock);
			exprCallerStack.push_back(pExprLastCaller);
			pExprTmplScript->SetStringIndent("");
			pExprTmplScript->SetStringPost("");
		}
	} else if (pExprLastCaller->GetBlock()->GetExprOwner().empty()) {
		exprCallerStack.push_back(pExprLastCaller);
		pExprTmplScript->SetStringIndent("");
		pExprTmplScript->SetStringPost("");
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
	_streamDst.Print(sig, _str.c_str());
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
	_streamDst.Print(sig, _strIndent.c_str());
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
					_streamDst.PutChar(sig, ch);
					if (_autoIndentFlag && valueElem.IsValid()) {
						_streamDst.Print(sig, _strIndent.c_str());
					}
				} else {
					_streamDst.PutChar(sig, ch);
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
				return Value::Null;
			}
		}
	} else if (value.Is_number()) {
		strLast = value.ToString();
		if (sig.IsSignalled()) return false;
	} else {
		sig.SetError(ERR_TypeError,
			"template script must return nil, string or number");
		return Value::Null;
	}
	foreach_const (String, p, strLast) {
		char ch = *p;
		if (ch != '\n') {
			_streamDst.PutChar(sig, ch);
		} else if (p + 1 != strLast.end()) {
			_streamDst.PutChar(sig, ch);
			if (_autoIndentFlag) {
				_streamDst.Print(sig, _strIndent.c_str());
			}
		} else if (_appendLastEOLFlag) {
			_streamDst.PutChar(sig, ch);
		}
	}
	_streamDst.Print(sig, _strPost.c_str());
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
