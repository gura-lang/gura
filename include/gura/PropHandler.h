//=============================================================================
// PropHandler
//=============================================================================
#ifndef __GURA_PROPHANDLER_H__
#define __GURA_PROPHANDLER_H__

#include "Value.h"

namespace Gura {

class GURA_DLLDECLARE PropHandler : public HelpProvider::Holder {
public:
	virtual ~PropHandler();
	virtual Value DoSetProp(const Value &valueThis, const SymbolSet &attrs) = 0;
	virtual Value DoGetProp(const Value &valueThis, const Value &value, const SymbolSet &attrs) = 0;
};

class GURA_DLLDECLARE PropHandlerMap :
	public std::unordered_map <const Symbol *, PropHandler *, Symbol::Hasher, Symbol::EqualTo> {
public:
	inline PropHandlerMap() {}
	~PropHandlerMap();
};

}

#endif
