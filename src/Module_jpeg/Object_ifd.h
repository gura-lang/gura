#ifndef __JPEG_OBJECT_IFD_H__
#define __JPEG_OBJECT_IFD_H__
#include <gura.h>
#include "Object_Tag.h"

Gura_BeginModule(jpeg)

//-----------------------------------------------------------------------------
// Object_ifd declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(ifd);

class Object_ifd : public Object {
private:
	TagOwner _tagOwner;
public:
	Gura_DeclareObjectAccessor(ifd)
public:
	Object_ifd();
	virtual ~Object_ifd();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	virtual Value IndexGet(Environment &env, Signal sig, const Value &valueIdx);
	virtual bool DoDirProp(Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Signal sig, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
	inline TagOwner &GetTagOwner() { return _tagOwner; }
	inline const TagOwner &GetTagOwner() const { return _tagOwner; }
};

Object_ifd *ParseIFD_BE(Environment &env, Signal sig,
			char *buff, size_t bytesAPP1, size_t offset, size_t *pOffsetNext);
Object_ifd *ParseIFD_LE(Environment &env, Signal sig,
			char *buff, size_t bytesAPP1, size_t offset, size_t *pOffsetNext);

}}

#endif
