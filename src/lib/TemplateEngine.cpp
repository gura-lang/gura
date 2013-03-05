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
	char chPrefix = '$';
	enum {
		STAT_LineTop, STAT_Indent, STAT_String,
		STAT_ScriptPre, STAT_Script,
	} stat = STAT_LineTop;
	String str;
	String strScript;
	String strIndent;
	int nDepth = 0;
	ExprOwner exprOwnerRoot;
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
					str += ch;
					strIndent += ch;
				} else {
					continueFlag = true;
					stat = STAT_String;
				}
				break;
			}
			case STAT_String: {
				if (ch == chPrefix) {
					stat = STAT_ScriptPre;
				} else if (ch == '\n') {
					strIndent.clear();
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
							exprOwnerRoot : exprCallerStack.back()->GetBlock()->GetExprOwner();
						exprOwner.push_back(new Expr_TemplateString(streamDst, str));
						str.clear();
					}
					nDepth = 1;
					strScript.clear();
					stat = STAT_Script;
				} else if (ch == chPrefix) {
					str += ch;
					stat = STAT_String;
				} else {
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
					if (!ParseScript(env, sig, strIndent.c_str(), strScript.c_str(),
							streamDst, exprOwnerRoot, exprCallerStack)) return false;
					stat = STAT_String;
				} else {
					strScript += ch;
				}
				break;
			}
			}
		} while (continueFlag);
	}
	if (!exprCallerStack.empty()) {
		sig.SetError(ERR_SyntaxError, "lacking end statement for block expression");
		return false;
	}
	if (!str.empty()) {
		exprOwnerRoot.push_back(new Expr_TemplateString(streamDst, str));
		str.clear();
	}
	exprOwnerRoot.Exec(env, sig, true);
	//::printf("%s\n", exprOwnerRoot.ToString().c_str());
	return !sig.IsSignalled();
}

bool TemplateEngine::ParseScript(Environment &env, Signal sig,
			const char *strIndent, const char *strScript, SimpleStream &streamDst,
			ExprOwner &exprOwnerRoot, ExprCallerStack &exprCallerStack)
{
	ExprOwner exprOwnerPart;
	if (!_parser.ParseString(env, sig, exprOwnerPart,
						"<templatescript>", strScript)) return false;
	AutoPtr<Expr_TemplateScript> pExprTmplBlock(new Expr_TemplateScript(
		streamDst, strIndent, _autoIndentFlag, _appendLastEOLFlag));
	ExprOwner::iterator ppExpr = exprOwnerPart.begin();
	Expr *pExprLast = NULL;
	if (ppExpr != exprOwnerPart.end()) {
		Expr *pExpr = *ppExpr;
		ICallable *pCallable = pExpr->LookupCallable(env, sig);
		sig.ClearSignal();
		if (pCallable != NULL && pCallable->IsTrailer()) {
			if (exprCallerStack.empty()) {
				sig.SetError(ERR_SyntaxError, "unmatching trailer expression");
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
	if (ppExpr != exprOwnerPart.end()) {
		for ( ; ppExpr != exprOwnerPart.end(); ppExpr++) {
			Expr *pExpr = *ppExpr;
			pExprTmplBlock->GetExprOwner().push_back(Expr::Reference(pExpr));
			pExprLast = pExpr;
		}
		ExprOwner &exprOwner = exprCallerStack.empty()?
			exprOwnerRoot : exprCallerStack.back()->GetBlock()->GetExprOwner();
		exprOwner.push_back(pExprTmplBlock.release());
	}
	if (pExprLast != NULL && pExprLast->IsCaller()) {
		Expr_Caller *pExprCaller = dynamic_cast<Expr_Caller *>(pExprLast);
		if (pExprCaller->GetBlock() == NULL) {
			ICallable *pCallable = pExprCaller->LookupCallable(env, sig);
			sig.ClearSignal();
			if (pCallable != NULL && pCallable->GetBlockOccurPattern() == OCCUR_Once) {
				Expr_Block *pExprBlock = new Expr_Block();
				pExprCaller->SetBlock(pExprBlock);
				exprCallerStack.push_back(pExprCaller);
			}
		}
	}
	return true;
}

}
