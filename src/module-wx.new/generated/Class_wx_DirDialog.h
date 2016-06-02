//----------------------------------------------------------------------------
// wxDirDialog
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_DIRDIALOG_H__
#define __CLASS_WX_DIRDIALOG_H__
#include <wx/dirdlg.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxDirDialog
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_DirDialog);

//----------------------------------------------------------------------------
// Object declaration for wxDirDialog
//----------------------------------------------------------------------------
class Object_wx_DirDialog : public Object_wx_Dialog {
public:
	Gura_DeclareObjectAccessor(wx_DirDialog)
public:
	inline Object_wx_DirDialog(wxDirDialog *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Dialog(Gura_UserClass(wx_DirDialog), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_DirDialog(Class *pClass, wxDirDialog *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Dialog(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_DirDialog();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxDirDialog *GetEntity() {
		return static_cast<wxDirDialog *>(_pEntity);
	}
	inline wxDirDialog *ReleaseEntity() {
		wxDirDialog *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxDirDialog");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
