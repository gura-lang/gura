//=============================================================================
// PropDeclaration
//=============================================================================
#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// PropDeclaration
//-----------------------------------------------------------------------------
PropDeclaration::PropDeclaration(const Symbol *pSymbol, ULong flags) :
	_cntRef(1), _pSymbol(pSymbol), _valType(VTYPE_any), _flags(flags),
	_pHelpProvider(new HelpProvider(this))
{
}

PropDeclaration::~PropDeclaration()
{
	_pHelpProvider->SetHolder(nullptr);
}

Value PropDeclaration::GetProp(Environment &env, const Value &valueThis, const SymbolSet &attrs) const
{
	return DoGetProp(env, valueThis, attrs);
}

Value PropDeclaration::SetProp(Environment &env, const Value &valueThis, const SymbolSet &attrs, Value &value) const
{
	if (!value.CastType(env, _valType, _flags)) return Value::Nil;
	return DoSetProp(env, valueThis, attrs, value);
}

String PropDeclaration::MakeHelpTitle() const
{
	return _pSymbol->GetName();
}

//-----------------------------------------------------------------------------
// PropDeclarationMap
//-----------------------------------------------------------------------------
PropDeclarationMap::PropDeclarationMap(const PropDeclarationMap &propDeclarationMap)
{
	foreach_const (PropDeclarationMap, iter, propDeclarationMap) {
		insert(value_type(iter->first, iter->second->Reference()));
	}
}

PropDeclarationMap::~PropDeclarationMap()
{
	foreach (PropDeclarationMap, iter, *this) {
		PropDeclaration::Delete(iter->second);
	}
}

void PropDeclarationMap::operator=(const PropDeclarationMap &propDeclarationMap)
{
	foreach_const (PropDeclarationMap, iter, propDeclarationMap) {
		insert(value_type(iter->first, iter->second->Reference()));
	}
}

//-----------------------------------------------------------------------------
// PropDeclarationList
//-----------------------------------------------------------------------------
void PropDeclarationList::SortByName()
{
	std::sort(begin(), end(), Comparator());
}

//-----------------------------------------------------------------------------
// PropDeclarationOwner
//-----------------------------------------------------------------------------
PropDeclarationOwner::~PropDeclarationOwner()
{
	Clear();
}

void PropDeclarationOwner::Clear()
{
	foreach (PropDeclarationOwner, ppPropDeclaration, *this) {
		PropDeclaration::Delete(*ppPropDeclaration);
	}
	clear();
}


}
