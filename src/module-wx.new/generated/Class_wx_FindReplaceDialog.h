//----------------------------------------------------------------------------
// wxFindReplaceDialog
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_FINDREPLACEDIALOG_H__
#define __CLASS_WX_FINDREPLACEDIALOG_H__
#include <wx/fdrepdlg.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxFindReplaceDialog
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_FindReplaceDialog);

//----------------------------------------------------------------------------
// Object declaration for wxFindReplaceDialog
//----------------------------------------------------------------------------
class Object_wx_FindReplaceDialog : public Object_wx_Dialog {
public:
	Gura_DeclareObjectAccessor(wx_FindReplaceDialog)
public:
	inline Object_wx_FindReplaceDialog(wxFindReplaceDialog *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Dialog(Gura_UserClass(wx_FindReplaceDialog), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_FindReplaceDialog(Class *pClass, wxFindReplaceDialog *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Dialog(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_FindReplaceDialog();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxFindReplaceDialog *GetEntity() {
		return static_cast<wxFindReplaceDialog *>(_pEntity);
	}
	inline wxFindReplaceDialog *ReleaseEntity() {
		wxFindReplaceDialog *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxFindReplaceDialog");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
