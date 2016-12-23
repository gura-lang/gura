//=============================================================================
// PropHandler
//=============================================================================
#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// PropHandler
//-----------------------------------------------------------------------------
PropHandler::PropHandler(const Symbol *pSymbol, ULong flags) :
	_cntRef(1), _pSymbol(pSymbol), _valType(VTYPE_any), _flags(flags),
	_pHelpProvider(new HelpProvider(this))
{
}

PropHandler::~PropHandler()
{
	_pHelpProvider->SetHolder(nullptr);
}

Value PropHandler::GetProp(Environment &env, const Value &valueThis, const SymbolSet &attrs) const
{
	return DoGetProp(env, valueThis, attrs);
}

Value PropHandler::SetProp(Environment &env, const Value &valueThis, const SymbolSet &attrs, Value &value) const
{
	if (!value.CastType(env, _valType)) return Value::Nil;
	return DoSetProp(env, valueThis, attrs, value);
}

String PropHandler::MakeHelpTitle() const
{
	return _pSymbol->GetName();
}

//-----------------------------------------------------------------------------
// PropHandlerMap
//-----------------------------------------------------------------------------
PropHandlerMap::PropHandlerMap(const PropHandlerMap &propHandlerMap)
{
	foreach_const (PropHandlerMap, iter, propHandlerMap) {
		insert(value_type(iter->first, iter->second->Reference()));
	}
}

PropHandlerMap::~PropHandlerMap()
{
	foreach (PropHandlerMap, iter, *this) {
		PropHandler::Delete(iter->second);
	}
}

void PropHandlerMap::operator=(const PropHandlerMap &propHandlerMap)
{
	foreach_const (PropHandlerMap, iter, propHandlerMap) {
		insert(value_type(iter->first, iter->second->Reference()));
	}
}

}
