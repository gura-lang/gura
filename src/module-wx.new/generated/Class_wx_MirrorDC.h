//----------------------------------------------------------------------------
// wxMirrorDC
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_MIRRORDC_H__
#define __CLASS_WX_MIRRORDC_H__
#include <wx/dcmirror.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxMirrorDC
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_MirrorDC);

//----------------------------------------------------------------------------
// Object declaration for wxMirrorDC
//----------------------------------------------------------------------------
class Object_wx_MirrorDC : public Object_wx_DC {
public:
	Gura_DeclareObjectAccessor(wx_MirrorDC)
public:
	inline Object_wx_MirrorDC(wxMirrorDC *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_DC(Gura_UserClass(wx_MirrorDC), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_MirrorDC(Class *pClass, wxMirrorDC *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_DC(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_MirrorDC();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxMirrorDC *GetEntity() {
		return static_cast<wxMirrorDC *>(_pEntity);
	}
	inline wxMirrorDC *ReleaseEntity() {
		wxMirrorDC *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxMirrorDC");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
