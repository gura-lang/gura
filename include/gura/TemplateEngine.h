#ifndef __GURA_TEMPLATEENGINE_H__
#define __GURA_TEMPLATEENGINE_H__

#include "Parser.h"

namespace Gura {

//-----------------------------------------------------------------------------
// TemplateEngine
//-----------------------------------------------------------------------------
class DLLDECLARE TemplateEngine {
public:
	typedef std::vector<Expr_Caller *> ExprCallerStack;
private:
	bool _autoIndentFlag;
	bool _appendLastEOLFlag;
	Parser _parser;
public:
	TemplateEngine(bool autoIndentFlag, bool appendLastEOLFlag);
	bool EvalStream(Environment &env, Signal sig,
					SimpleStream &streamSrc, SimpleStream &streamDst);
private:
	bool ParseScript(Environment &env, Signal sig,
			const char *strIndent, const char *strScript, SimpleStream &streamDst,
			ExprOwner &exprOwnerRoot, ExprCallerStack &exprCallerStack);
};

}

#endif
