#include "Module_jpeg.h"
#include "Object_tag.h"
#include "Object_ifd.h"

Gura_BeginModule(jpeg)

//-----------------------------------------------------------------------------
// Object_tag implementation
//-----------------------------------------------------------------------------
Object_tag::Object_tag(unsigned short id, unsigned short type, const Symbol *pSymbol, const Value &value) :
			Object(Gura_UserClass(Tag)),
			_id(id), _type(type), _pSymbol(pSymbol), _value(value)
{
}

Object_tag::Object_tag(unsigned short id, unsigned short type, const Symbol *pSymbol, Object_ifd *pObjIFD) :
			Object(Gura_UserClass(Tag)),
			_id(id), _type(type), _pSymbol(pSymbol), _pObjIFD(pObjIFD)
{
}

void Object_tag::Print(int indentLevel) const
{
	Signal sig;
	const TypeInfo *pTypeInfo = TypeToInfo(_type);
	if (IsIFDPointer()) {
		::printf("%*s%s [%04x]\n", indentLevel * 2, "", GetSymbol()->GetName(), _id);
		GetObjectIFD()->GetTagOwner().Print(indentLevel + 1);
	} else {
		::printf("%*s%s [%04x], %s [%04x], %s\n", indentLevel * 2, "",
			GetSymbol()->GetName(), _id,
			(pTypeInfo == NULL)? "(unknown)" : pTypeInfo->name, _type,
			_value.ToString(sig).c_str());
	}
}

bool Object_tag::DoDirProp(Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(sig, symbols)) return false;
	symbols.insert(Gura_UserSymbol(id));
	symbols.insert(Gura_UserSymbol(name));
	symbols.insert(Gura_UserSymbol(symbol));
	symbols.insert(Gura_UserSymbol(type));
	symbols.insert(Gura_UserSymbol(value));
	symbols.insert(Gura_UserSymbol(ifd));
	return true;
}

Value Object_tag::DoGetProp(Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	Environment &env = *this;
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(id))) {
		return Value(_id);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(name))) {
		return Value(env, _pSymbol->GetName());
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(symbol))) {
		return Value(_pSymbol);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(type))) {
		return Value(_type);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(value))) {
		return _value;
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(ifd))) {
		if (IsIFDPointer()) return Value(Object_ifd::Reference(GetObjectIFD()));
		return Value::Null;
	}
	evaluatedFlag = false;
	return Value::Null;
}

String Object_tag::ToString(Signal sig, bool exprFlag)
{
	return String("<jpeg.Tag>");
}

//-----------------------------------------------------------------------------
// Gura interfaces for Tag
//-----------------------------------------------------------------------------
// implementation of class Tag
Gura_ImplementUserClass(Tag)
{
}

//-----------------------------------------------------------------------------
// TagList
//-----------------------------------------------------------------------------
Object_tag *TagList::FindById(unsigned short id)
{
	foreach (TagList, ppObjTag, *this) {
		Object_tag *pObjTag = *ppObjTag;
		if (pObjTag->GetId() == id) return pObjTag;
	}
	return NULL;
}

Object_tag *TagList::FindBySymbol(const Symbol *pSymbol)
{
	foreach (TagList, ppObjTag, *this) {
		Object_tag *pObjTag = *ppObjTag;
			if (pObjTag->GetSymbol() == pSymbol) return pObjTag;
	}
	return NULL;
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

}}
