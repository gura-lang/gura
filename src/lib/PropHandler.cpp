//=============================================================================
// PropHandler
//=============================================================================
#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// PropHandler
//-----------------------------------------------------------------------------
PropHandler::~PropHandler()
{
}

Value PropHandler::DoGetProp(const Value &valueThis, const SymbolSet &attrs) const
{
	return Value::Nil;
}

Value PropHandler::DoSetProp(const Value &valueThis, const Value &value, const SymbolSet &attrs) const
{
	return Value::Nil;
}

String PropHandler::MakeHelpTitle() const
{
	return _pSymbol->GetName();
}

//-----------------------------------------------------------------------------
// PropHandlerMap
//-----------------------------------------------------------------------------
PropHandlerMap::~PropHandlerMap()
{
	foreach (PropHandlerMap, iter, *this) {
		delete iter->second;
	}
}

}
