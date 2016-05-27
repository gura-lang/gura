//----------------------------------------------------------------------------
// wxCharBuffer
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_CHARBUFFER_H__
#define __CLASS_WX_CHARBUFFER_H__
#include <wx/buffer.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxCharBuffer
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_CharBuffer);

//----------------------------------------------------------------------------
// Object declaration for wxCharBuffer
//----------------------------------------------------------------------------
class Object_wx_CharBuffer : public Object_wx_CharTypeBuffer {
public:
	Gura_DeclareObjectAccessor(wx_CharBuffer)
public:
	inline Object_wx_CharBuffer(wxCharBuffer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_CharTypeBuffer(Gura_UserClass(wx_CharBuffer), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_CharBuffer(Class *pClass, wxCharBuffer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_CharTypeBuffer(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_CharBuffer();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxCharBuffer *GetEntity() {
		return static_cast<wxCharBuffer *>(_pEntity);
	}
	inline wxCharBuffer *ReleaseEntity() {
		wxCharBuffer *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxCharBuffer");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
