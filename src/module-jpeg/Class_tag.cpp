#include "stdafx.h"
#include "Class_tag.h"
#include "Class_ifd.h"

Gura_BeginModuleScope(jpeg)

//-----------------------------------------------------------------------------
// Object_tag implementation
//-----------------------------------------------------------------------------
Object_tag::Object_tag(unsigned short tagId, unsigned short type, const Symbol *pSymbol,
					const Value &value, const Value &valueCooked) :
			Object(Gura_UserClass(tag)), _tagId(tagId), _type(type),
			_pSymbol(pSymbol), _value(value), _valueCooked(valueCooked)
{
}

Object_tag::Object_tag(unsigned short tagId, unsigned short type, const Symbol *pSymbol, Object_ifd *pObjIFD) :
			Object(Gura_UserClass(tag)),
			_tagId(tagId), _type(type), _pSymbol(pSymbol), _pObjIFD(pObjIFD)
{
}

void Object_tag::Print(int indentLevel) const
{
	Signal sig;
	const TypeInfo *pTypeInfo = TypeToInfo(_type);
	if (IsIFDPointer()) {
		::printf("%*s%s [%04x]\n", indentLevel * 2, "", GetSymbol()->GetName(), _tagId);
		GetObjectIFD()->GetTagOwner().Print(indentLevel + 1);
	} else {
		::printf("%*s%s [%04x], %s [%04x], %s\n", indentLevel * 2, "",
			GetSymbol()->GetName(), _tagId,
			(pTypeInfo == nullptr)? "(unknown)" : pTypeInfo->name, _type,
			_value.ToString().c_str());
	}
}

bool Object_tag::DoDirProp(Environment &env, SymbolSet &symbols)
{
	Signal &sig = GetSignal();
	if (!Object::DoDirProp(env, symbols)) return false;
	symbols.insert(Gura_UserSymbol(id));
	symbols.insert(Gura_UserSymbol(name));
	symbols.insert(Gura_UserSymbol(symbol));
	symbols.insert(Gura_UserSymbol(type));
	symbols.insert(Gura_UserSymbol(value));
	symbols.insert(Gura_UserSymbol(ifd));
	return true;
}

Value Object_tag::DoGetProp(Environment &env, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(id))) {
		return Value(_tagId);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(name))) {
		return Value(_pSymbol->GetName());
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(symbol))) {
		return Value(_pSymbol);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(type))) {
		return Value(_type);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(typename))) {
		const TypeInfo *pTypeInfo = TypeToInfo(_type);
		return Value((pTypeInfo == nullptr)? "(unknown)" : pTypeInfo->name);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(value))) {
		if (attrs.IsSet(Gura_UserSymbol(cooked))) {
			return _valueCooked;
		} else {
			return _value;
		}
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(ifd))) {
		if (IsIFDPointer()) return Value(Object_ifd::Reference(GetObjectIFD()));
		return Value::Nil;
	}
	evaluatedFlag = false;
	return Value::Nil;
}

String Object_tag::ToString(bool exprFlag)
{
	return String("<jpeg.tag>");
}

//-----------------------------------------------------------------------------
// Gura interfaces for jpeg.tag
//-----------------------------------------------------------------------------
// implementation of class tag
Gura_ImplementUserClass(tag)
{
	Gura_AssignValue(tag, Value(Reference()));
}

//-----------------------------------------------------------------------------
// TagList
//-----------------------------------------------------------------------------
Object_tag *TagList::FindById(unsigned short tagId)
{
	foreach (TagList, ppObjTag, *this) {
		Object_tag *pObjTag = *ppObjTag;
		if (pObjTag->GetId() == tagId) return pObjTag;
	}
	return nullptr;
}

Object_tag *TagList::FindBySymbol(const Symbol *pSymbol)
{
	foreach (TagList, ppObjTag, *this) {
		Object_tag *pObjTag = *ppObjTag;
			if (pObjTag->GetSymbol() == pSymbol) return pObjTag;
	}
	return nullptr;
}

void TagList::Print(int indentLevel) const
{
	foreach_const (TagList, ppObjTag, *this) {
		const Object_tag *pObjTag = *ppObjTag;
		pObjTag->Print(indentLevel);
	}
}

//-----------------------------------------------------------------------------
// TagOwner
//-----------------------------------------------------------------------------
TagOwner::~TagOwner()
{
	Clear();
}

void TagOwner::Clear()
{
	foreach (TagOwner, ppObjTag, *this) {
		Object_tag *pObjTag = *ppObjTag;
		Object::Delete(pObjTag);
	}
	clear();
}

Gura_EndModuleScope(jpeg)
