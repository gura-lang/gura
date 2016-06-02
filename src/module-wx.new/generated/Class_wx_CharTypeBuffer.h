//----------------------------------------------------------------------------
// wxCharTypeBuffer
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_CHARTYPEBUFFER_H__
#define __CLASS_WX_CHARTYPEBUFFER_H__
#include <wx/buffer.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxCharTypeBuffer
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_CharTypeBuffer);

//----------------------------------------------------------------------------
// Object declaration for wxCharTypeBuffer
//----------------------------------------------------------------------------
class Object_wx_CharTypeBuffer : public Object_wx_ScopedCharTypeBuffer {
public:
	Gura_DeclareObjectAccessor(wx_CharTypeBuffer)
public:
	inline Object_wx_CharTypeBuffer(wxCharTypeBuffer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_ScopedCharTypeBuffer(Gura_UserClass(wx_CharTypeBuffer), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_CharTypeBuffer(Class *pClass, wxCharTypeBuffer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_ScopedCharTypeBuffer(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_CharTypeBuffer();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxCharTypeBuffer *GetEntity() {
		return static_cast<wxCharTypeBuffer *>(_pEntity);
	}
	inline wxCharTypeBuffer *ReleaseEntity() {
		wxCharTypeBuffer *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxCharTypeBuffer");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
