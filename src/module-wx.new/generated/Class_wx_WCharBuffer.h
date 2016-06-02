//----------------------------------------------------------------------------
// wxWCharBuffer
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_WCHARBUFFER_H__
#define __CLASS_WX_WCHARBUFFER_H__
#include <wx/buffer.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxWCharBuffer
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_WCharBuffer);

//----------------------------------------------------------------------------
// Object declaration for wxWCharBuffer
//----------------------------------------------------------------------------
class Object_wx_WCharBuffer : public Object_wx_CharTypeBuffer {
public:
	Gura_DeclareObjectAccessor(wx_WCharBuffer)
public:
	inline Object_wx_WCharBuffer(wxWCharBuffer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_CharTypeBuffer(Gura_UserClass(wx_WCharBuffer), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_WCharBuffer(Class *pClass, wxWCharBuffer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_CharTypeBuffer(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_WCharBuffer();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxWCharBuffer *GetEntity() {
		return static_cast<wxWCharBuffer *>(_pEntity);
	}
	inline wxWCharBuffer *ReleaseEntity() {
		wxWCharBuffer *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxWCharBuffer");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
