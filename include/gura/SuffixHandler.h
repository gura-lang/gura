//=============================================================================
// SuffixHandler
//=============================================================================
#ifndef __GURA_SUFFIXHANDLER_H__
#define __GURA_SUFFIXHANDLER_H__

#include "Common.h"
#include "Signal.h"

namespace Gura {

class Environment;

//-----------------------------------------------------------------------------
// SuffixHandler
//-----------------------------------------------------------------------------
class SuffixHandler {
public:
	virtual Value DoEval(Environment &env, Signal sig, const char *str) const = 0;
};

//-----------------------------------------------------------------------------
// SuffixHandlerMap
//-----------------------------------------------------------------------------
class SuffixHandlerMap : public std::map<const Symbol *, SuffixHandler *> {
public:
	~SuffixHandlerMap();
};

}
#endif
