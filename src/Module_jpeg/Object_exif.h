#ifndef __JPEG_OBJECT_EXIF_H__
#define __JPEG_OBJECT_EXIF_H__
#include <gura.h>

Gura_BeginModule(jpeg)

//-----------------------------------------------------------------------------
// Tag declaration
//-----------------------------------------------------------------------------
class IFD;

class Tag {
private:
	unsigned short _tag;
	unsigned short _type;
	Value _value;
	std::auto_ptr<IFD> _pIFD;	// this may be NULL
public:
	inline Tag(unsigned short tag, unsigned short type, const Value &value) :
									_tag(tag), _type(type), _value(value) {}
	inline Tag(unsigned short tag, unsigned short type, IFD *pIFD) :
									_tag(tag), _type(type), _pIFD(pIFD) {}
	inline unsigned short GetTag() const { return _tag; }
	inline unsigned short GetType() const { return _type; }
	inline const Value &GetValue() const { return _value; }
	inline bool IsIFDPointer() const { return _pIFD.get() != NULL; }
	inline IFD *GetIFD() { return _pIFD.get(); }
	inline const IFD *GetIFD() const { return _pIFD.get(); }
	void Print(int indentLevel = 0) const;
};

//-----------------------------------------------------------------------------
// TagList declaration
//-----------------------------------------------------------------------------
class TagList : public std::vector<Tag *> {
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

//-----------------------------------------------------------------------------
// IFD declaration
//-----------------------------------------------------------------------------
class IFD {
private:
	TagOwner _tagOwner;
public:
	TagOwner &GetTagOwner() { return _tagOwner; }
	const TagOwner &GetTagOwner() const { return _tagOwner; }
};

//-----------------------------------------------------------------------------
// Object_exif declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(exif);

class Object_exif : public Object {
private:
	std::auto_ptr<IFD> _pIFD0th;
	std::auto_ptr<IFD> _pIFD1st;
public:
	Gura_DeclareObjectAccessor(exif)
public:
	Object_exif();
	virtual ~Object_exif();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	bool ReadStream(Signal sig, Stream &stream);
};

}}

#endif
