#ifndef __JPEG_OBJECT_EXIF_H__
#define __JPEG_OBJECT_EXIF_H__
#include <gura.h>

Gura_BeginModule(jpeg)

//-----------------------------------------------------------------------------
// Tag declaration
//-----------------------------------------------------------------------------
class Tag {
private:
	unsigned short _tag;
	unsigned short _type;
	Value _value;
public:
	inline Tag(unsigned short tag, unsigned short type, const Value &value) :
									_tag(tag), _type(type), _value(value) {}
	inline unsigned short GetTag() const { return _tag; }
	inline unsigned short GetType() const { return _type; }
	inline const Value &GetValue() const { return _value; }
	void Print() const;
};

class TagList : public std::vector<Tag *> {
public:
	void Print() const;
};

class TagOwner : public TagList {
public:
	~TagOwner();
	void Clear();
};

//-----------------------------------------------------------------------------
// Object_exif declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(exif);

class Object_exif : public Object_dict {
private:
	TagOwner _tagOwner;
public:
	Gura_DeclareObjectAccessor(exif)
public:
	inline Object_exif() : Object_dict(Gura_UserClass(exif), false) {}
	virtual ~Object_exif();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	bool ReadStream(Signal sig, Stream &stream);
};

}}

#endif
