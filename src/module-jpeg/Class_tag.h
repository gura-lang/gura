#ifndef __JPEG_CLASS_TAG_H__
#define __JPEG_CLASS_TAG_H__
#include <gura.h>

Gura_BeginModuleScope(jpeg)

class Object_ifd;

//-----------------------------------------------------------------------------
// Object_tag declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(tag);

class Object_tag : public Object {
private:
	unsigned short _tagId;
	unsigned short _type;
	const Symbol *_pSymbol;
	Value _value;
	AutoPtr<Object_ifd> _pObjIFD;	// this may be NULL
public:
	Gura_DeclareObjectAccessor(tag)
public:
	Object_tag(unsigned short tagId, unsigned short type, const Symbol *pSymbol, const Value &value);
	Object_tag(unsigned short tagId, unsigned short type, const Symbol *pSymbol, Object_ifd *pObjIFD);
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(bool exprFlag);
	inline unsigned short GetId() const { return _tagId; }
	inline unsigned short GetType() const { return _type; }
	inline bool IsTypeSHORTorLONG() const { return _type == TYPE_SHORT || _type == TYPE_LONG; }
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
class TagList : public std::vector<Object_tag *> {
public:
	Object_tag *FindById(unsigned short tagId);
	Object_tag *FindBySymbol(const Symbol *pSymbol);
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

Gura_EndModuleScope(jpeg)

#endif
