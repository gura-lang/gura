//----------------------------------------------------------------------------
// wxWindowDC
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_WINDOWDC_H__
#define __CLASS_WX_WINDOWDC_H__
#include <wx/dcclient.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxWindowDC
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_WindowDC);

//----------------------------------------------------------------------------
// Object declaration for wxWindowDC
//----------------------------------------------------------------------------
class Object_wx_WindowDC : public Object_wx_DC {
public:
	Gura_DeclareObjectAccessor(wx_WindowDC)
public:
	inline Object_wx_WindowDC(wxWindowDC *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_DC(Gura_UserClass(wx_WindowDC), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_WindowDC(Class *pClass, wxWindowDC *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_DC(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_WindowDC();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxWindowDC *GetEntity() {
		return static_cast<wxWindowDC *>(_pEntity);
	}
	inline wxWindowDC *ReleaseEntity() {
		wxWindowDC *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxWindowDC");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
