//----------------------------------------------------------------------------
// wxDialog
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_DIALOG_H__
#define __CLASS_WX_DIALOG_H__
#include <wx/dialog.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxDialog
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_Dialog);

//----------------------------------------------------------------------------
// Object declaration for wxDialog
//----------------------------------------------------------------------------
class Object_wx_Dialog : public Object_wx_TopLevelWindow {
public:
	Gura_DeclareObjectAccessor(wx_Dialog)
public:
	inline Object_wx_Dialog(wxDialog *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_TopLevelWindow(Gura_UserClass(wx_Dialog), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_Dialog(Class *pClass, wxDialog *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_TopLevelWindow(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_Dialog();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxDialog *GetEntity() {
		return static_cast<wxDialog *>(_pEntity);
	}
	inline wxDialog *ReleaseEntity() {
		wxDialog *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxDialog");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
