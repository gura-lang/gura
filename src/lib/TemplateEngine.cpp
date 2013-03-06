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
		STAT_ScriptPre, STAT_Script, STAT_ScriptPost,
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
							exprOwnerRoot : exprCallerStack.back()->GetBlock()->GetExprOwner();
						exprOwner.push_back(new Expr_TemplateString(streamDst, str));
						str.clear();
					}
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
						streamDst, exprOwnerRoot, exprCallerStack)) return false;
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
	}
	if (!strScript.empty()) {
		const char *strPost = "";
		if (!ParseScript(env, sig,
				strIndent.c_str(), strScript.c_str(), strPost,
				streamDst, exprOwnerRoot, exprCallerStack)) return false;
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
			const char *strIndent, const char *strScript, const char *strPost,
			SimpleStream &streamDst, ExprOwner &exprOwnerRoot,
			ExprCallerStack &exprCallerStack)
{
	ExprOwner exprOwnerPart;
	if (!_parser.ParseString(env, sig, exprOwnerPart,
						"<templatescript>", strScript)) return false;
	Expr_TemplateScript *pExprTmplScript = new Expr_TemplateScript(
		streamDst, strIndent, strPost, _autoIndentFlag, _appendLastEOLFlag);
	ExprOwner::iterator ppExpr = exprOwnerPart.begin();
	Expr *pExprLast = NULL;
	//::printf("[%s], [%s], [%s]\n", strIndent, strScript, strPost);
	if (ppExpr != exprOwnerPart.end()) {
		Expr *pExpr = *ppExpr;
		ICallable *pCallable = pExpr->LookupCallable(env, sig);
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
	if (ppExpr != exprOwnerPart.end()) {
		for ( ; ppExpr != exprOwnerPart.end(); ppExpr++) {
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
		ICallable *pCallable = pExprLastCaller->LookupCallable(env, sig);
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

}
