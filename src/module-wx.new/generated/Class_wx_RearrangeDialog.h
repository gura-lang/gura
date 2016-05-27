//----------------------------------------------------------------------------
// wxRearrangeDialog
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_REARRANGEDIALOG_H__
#define __CLASS_WX_REARRANGEDIALOG_H__
#include <wx/rearrangectrl.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxRearrangeDialog
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_RearrangeDialog);

//----------------------------------------------------------------------------
// Object declaration for wxRearrangeDialog
//----------------------------------------------------------------------------
class Object_wx_RearrangeDialog : public Object_wx_Dialog {
public:
	Gura_DeclareObjectAccessor(wx_RearrangeDialog)
public:
	inline Object_wx_RearrangeDialog(wxRearrangeDialog *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Dialog(Gura_UserClass(wx_RearrangeDialog), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_RearrangeDialog(Class *pClass, wxRearrangeDialog *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Dialog(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_RearrangeDialog();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxRearrangeDialog *GetEntity() {
		return static_cast<wxRearrangeDialog *>(_pEntity);
	}
	inline wxRearrangeDialog *ReleaseEntity() {
		wxRearrangeDialog *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxRearrangeDialog");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
