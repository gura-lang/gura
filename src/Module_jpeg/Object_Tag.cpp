#include "Module_jpeg.h"
#include "Object_Tag.h"
#include "Object_ifd.h"

Gura_BeginModule(jpeg)

//-----------------------------------------------------------------------------
// Object_Tag implementation
//-----------------------------------------------------------------------------
Object_Tag::Object_Tag(unsigned short tag, unsigned short type, const Symbol *pSymbol, const Value &value) :
			Object(Gura_UserClass(Tag)),
			_tag(tag), _type(type), _pSymbol(pSymbol), _value(value)
{
}

Object_Tag::Object_Tag(unsigned short tag, unsigned short type, const Symbol *pSymbol, Object_ifd *pObjIFD) :
			Object(Gura_UserClass(Tag)),
			_tag(tag), _type(type), _pSymbol(pSymbol), _pObjIFD(pObjIFD)
{
}

void Object_Tag::Print(int indentLevel) const
{
	Signal sig;
	const TagInfo *pTagInfo = TagToInfo(_tag);
	const TypeInfo *pTypeInfo = TypeToInfo(_type);
	if (IsIFDPointer()) {
		::printf("%*s%s [%04x]\n", indentLevel * 2, "",
			(pTagInfo == NULL)? "(unknown)" : pTagInfo->name, _tag);
		GetObjectIFD()->GetTagOwner().Print(indentLevel + 1);
	} else {
		::printf("%*s%s [%04x], %s [%04x], %s\n", indentLevel * 2, "",
			(pTagInfo == NULL)? "(unknown)" : pTagInfo->name, _tag,
			(pTypeInfo == NULL)? "(unknown)" : pTypeInfo->name, _type,
			_value.ToString(sig).c_str());
	}
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
void TagList::Print(int indentLevel) const
{
	foreach_const (TagList, ppObjTag, *this) {
		const Object_Tag *pObjTag = *ppObjTag;
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
		Object_Tag *pObjTag = *ppObjTag;
		Object::Delete(pObjTag);
	}
	clear();
}

}}
