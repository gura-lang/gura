#ifndef __JPEG_OBJECT_TAG_H__
#define __JPEG_OBJECT_TAG_H__
#include <gura.h>

Gura_BeginModule(jpeg)

class Object_ifd;

//-----------------------------------------------------------------------------
// Object_Tag declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(Tag);

class Object_Tag : public Object {
private:
	unsigned short _tag;
	unsigned short _type;
	const Symbol *_pSymbol;
	Value _value;
	AutoPtr<Object_ifd> _pObjIFD;	// this may be NULL
public:
	Gura_DeclareObjectAccessor(Tag)
public:
	Object_Tag(unsigned short tag, unsigned short type, const Symbol *pSymbol, const Value &value);
	Object_Tag(unsigned short tag, unsigned short type, const Symbol *pSymbol, Object_ifd *pObjIFD);
	inline unsigned short GetTag() const { return _tag; }
	inline unsigned short GetType() const { return _type; }
	inline const Symbol *GetSymbol() const { return _pSymbol; }
	inline const Value &GetValue() const { return _value; }
	inline bool IsIFDPointer() const { return _pObjIFD.get() != NULL; }
	inline Object_ifd *GetObjectIFD() { return _pObjIFD.get(); }
	inline const Object_ifd *GetObjectIFD() const { return _pObjIFD.get(); }
	void Print(int indentLevel = 0) const;
};

//-----------------------------------------------------------------------------
// TagList declaration
//-----------------------------------------------------------------------------
class TagList : public std::vector<Object_Tag *> {
public:
	void Print(int indentLevel = 0) const;
};

//-----------------------------------------------------------------------------
// TagOwner declaration
//-----------------------------------------------------------------------------
class TagOwner : public TagList {
public:
	inline TagOwner() {}
	~TagOwner();
	void Clear();
};

}}

#endif
