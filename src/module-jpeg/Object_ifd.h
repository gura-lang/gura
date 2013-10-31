#ifndef __JPEG_OBJECT_IFD_H__
#define __JPEG_OBJECT_IFD_H__
#include <gura.h>
#include "Object_tag.h"

Gura_BeginModuleScope(jpeg)

//-----------------------------------------------------------------------------
// Object_ifd declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(ifd);

class Object_ifd : public Object {
private:
	const Symbol *_pSymbol;
	TagOwner _tagOwner;
public:
	Gura_DeclareObjectAccessor(ifd)
public:
	Object_ifd(const Symbol *pSymbolOfIFD);
	virtual ~Object_ifd();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	virtual Value IndexGet(Environment &env, Signal sig, const Value &valueIdx);
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
	inline const Symbol *GetSymbol() const { return _pSymbol; }
	inline TagOwner &GetTagOwner() { return _tagOwner; }
	inline const TagOwner &GetTagOwner() const { return _tagOwner; }
};

Object_ifd *ParseIFD_BE(Environment &env, Signal sig, const Symbol *pSymbolOfIFD,
			char *buff, size_t bytesAPP1, size_t offset, size_t *pOffsetNext);
Object_ifd *ParseIFD_LE(Environment &env, Signal sig, const Symbol *pSymbolOfIFD,
			char *buff, size_t bytesAPP1, size_t offset, size_t *pOffsetNext);

//-----------------------------------------------------------------------------
// IteratorTag declaration
//-----------------------------------------------------------------------------
class IteratorTag : public Iterator {
private:
	AutoPtr<Object_ifd> _pObjIFD;
	size_t _idx;
public:
	IteratorTag(Object_ifd *pObjIFD);
	virtual Iterator *GetSource();
	virtual bool DoNext(Environment &env, Signal sig, Value &value);
	virtual String ToString(Signal sig) const;
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
};

Gura_EndModuleScope(jpeg)

#endif
