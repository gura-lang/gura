#ifndef __GURA_TEMPLATEENGINE_H__
#define __GURA_TEMPLATEENGINE_H__

#include "Parser.h"

namespace Gura {

//-----------------------------------------------------------------------------
// TemplateEngine
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE TemplateEngine {
public:
	typedef std::vector<Expr_Caller *> ExprCallerStack;
private:
	bool _autoIndentFlag;
	bool _appendLastEOLFlag;
public:
	TemplateEngine(bool autoIndentFlag, bool appendLastEOLFlag);
	bool EvalStream(Environment &env, Signal sig,
					SimpleStream &streamSrc, SimpleStream &streamDst);
private:
	bool ParseScript(Environment &env, Signal sig,
			const char *strIndent, const char *strScript, const char *strPost,
			SimpleStream &streamDst, ExprOwner &exprOwnerRoot,
			ExprCallerStack &exprCallerStack);
};

}

#endif
