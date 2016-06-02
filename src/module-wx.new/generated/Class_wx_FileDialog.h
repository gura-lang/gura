//----------------------------------------------------------------------------
// wxFileDialog
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_FILEDIALOG_H__
#define __CLASS_WX_FILEDIALOG_H__
#include <wx/filedlg.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxFileDialog
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_FileDialog);

//----------------------------------------------------------------------------
// Object declaration for wxFileDialog
//----------------------------------------------------------------------------
class Object_wx_FileDialog : public Object_wx_Dialog {
public:
	Gura_DeclareObjectAccessor(wx_FileDialog)
public:
	inline Object_wx_FileDialog(wxFileDialog *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Dialog(Gura_UserClass(wx_FileDialog), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_FileDialog(Class *pClass, wxFileDialog *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Dialog(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_FileDialog();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxFileDialog *GetEntity() {
		return static_cast<wxFileDialog *>(_pEntity);
	}
	inline wxFileDialog *ReleaseEntity() {
		wxFileDialog *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxFileDialog");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
