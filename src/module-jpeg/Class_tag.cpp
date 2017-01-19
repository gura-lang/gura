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

String Object_tag::ToString(bool exprFlag)
{
	return String("<jpeg.tag>");
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------
// jpeg.tag#id
Gura_DeclareProperty_R(tag, id)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(tag, id)
{
	Object_tag *pObjThis = Object_tag::GetObject(valueThis);
	return Value(pObjThis->GetId());
}

// jpeg.tag#ifd
Gura_DeclareProperty_R(tag, ifd)
{
	SetPropAttr(VTYPE_ifd);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(tag, ifd)
{
	Object_tag *pObjThis = Object_tag::GetObject(valueThis);
	if (pObjThis->IsIFDPointer()) return Value(Object_ifd::Reference(pObjThis->GetObjectIFD()));
	return Value::Nil;
}

// jpeg.tag#name
Gura_DeclareProperty_R(tag, name)
{
	SetPropAttr(VTYPE_string);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(tag, name)
{
	Object_tag *pObjThis = Object_tag::GetObject(valueThis);
	return Value(pObjThis->GetSymbol()->GetName());
}

// jpeg.tag#symbol
Gura_DeclareProperty_R(tag, symbol)
{
	SetPropAttr(VTYPE_symbol);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(tag, symbol)
{
	Object_tag *pObjThis = Object_tag::GetObject(valueThis);
	return Value(pObjThis->GetSymbol());
}

// jpeg.tag#type
Gura_DeclareProperty_R(tag, type)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(tag, type)
{
	Object_tag *pObjThis = Object_tag::GetObject(valueThis);
	return Value(pObjThis->GetType());
}

// jpeg.tag#typename
Gura_DeclareProperty_R(tag, typename)
{
	SetPropAttr(VTYPE_string);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(tag, typename)
{
	Object_tag *pObjThis = Object_tag::GetObject(valueThis);
	const TypeInfo *pTypeInfo = TypeToInfo(pObjThis->GetType());
	return Value((pTypeInfo == nullptr)? "(unknown)" : pTypeInfo->name);
}

// jpeg.tag#value
Gura_DeclareProperty_R(tag, value)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(tag, value)
{
	Object_tag *pObjThis = Object_tag::GetObject(valueThis);
	if (attrs.IsSet(Gura_UserSymbol(cooked))) {
		return pObjThis->GetValueCooked();
	} else {
		return pObjThis->GetValue();
	}
}

//-----------------------------------------------------------------------------
// Gura interfaces for jpeg.tag
//-----------------------------------------------------------------------------
// implementation of class tag
Gura_ImplementUserClass(tag)
{
	// Assignment of properties
	Gura_AssignProperty(tag, id);
	Gura_AssignProperty(tag, ifd);
	Gura_AssignProperty(tag, name);
	Gura_AssignProperty(tag, symbol);
	Gura_AssignProperty(tag, type);
	Gura_AssignProperty(tag, typename);
	Gura_AssignProperty(tag, value);
	// Assignment of value
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
