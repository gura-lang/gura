//=============================================================================
// PropHandler
//=============================================================================
#ifndef __GURA_PROPHANDLER_H__
#define __GURA_PROPHANDLER_H__

#include "Value.h"

namespace Gura {

class GURA_DLLDECLARE PropHandler {
public:
	virtual ~PropHandler();
	virtual Value DoSetProp(Environment &env, const Value &value) = 0;
	virtual Value DoGetProp(Environment &env) = 0;
};

class GURA_DLLDECLARE PropHandlerMap :
	public std::unordered_map <const Symbol *, PropHandler *, Symbol::Hasher, Symbol::EqualTo> {
public:
	inline PropHandlerMap() {}
	~PropHandlerMap();
};

}

#endif
