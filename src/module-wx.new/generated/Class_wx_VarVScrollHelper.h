//----------------------------------------------------------------------------
// wxVarVScrollHelper
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_VARVSCROLLHELPER_H__
#define __CLASS_WX_VARVSCROLLHELPER_H__
#include <wx/vscroll.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxVarVScrollHelper
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_VarVScrollHelper);

//----------------------------------------------------------------------------
// Object declaration for wxVarVScrollHelper
//----------------------------------------------------------------------------
class Object_wx_VarVScrollHelper : public Object_wx_VarScrollHelperBase {
public:
	Gura_DeclareObjectAccessor(wx_VarVScrollHelper)
public:
	inline Object_wx_VarVScrollHelper(wxVarVScrollHelper *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_VarScrollHelperBase(Gura_UserClass(wx_VarVScrollHelper), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_VarVScrollHelper(Class *pClass, wxVarVScrollHelper *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_VarScrollHelperBase(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_VarVScrollHelper();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxVarVScrollHelper *GetEntity() {
		return static_cast<wxVarVScrollHelper *>(_pEntity);
	}
	inline wxVarVScrollHelper *ReleaseEntity() {
		wxVarVScrollHelper *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxVarVScrollHelper");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
