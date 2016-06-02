//----------------------------------------------------------------------------
// wxVarHScrollHelper
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_VARHSCROLLHELPER_H__
#define __CLASS_WX_VARHSCROLLHELPER_H__
#include <wx/vscroll.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxVarHScrollHelper
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_VarHScrollHelper);

//----------------------------------------------------------------------------
// Object declaration for wxVarHScrollHelper
//----------------------------------------------------------------------------
class Object_wx_VarHScrollHelper : public Object_wx_VarScrollHelperBase {
public:
	Gura_DeclareObjectAccessor(wx_VarHScrollHelper)
public:
	inline Object_wx_VarHScrollHelper(wxVarHScrollHelper *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_VarScrollHelperBase(Gura_UserClass(wx_VarHScrollHelper), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_VarHScrollHelper(Class *pClass, wxVarHScrollHelper *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_VarScrollHelperBase(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_VarHScrollHelper();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxVarHScrollHelper *GetEntity() {
		return static_cast<wxVarHScrollHelper *>(_pEntity);
	}
	inline wxVarHScrollHelper *ReleaseEntity() {
		wxVarHScrollHelper *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxVarHScrollHelper");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
