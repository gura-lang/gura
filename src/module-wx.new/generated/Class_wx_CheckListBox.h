//----------------------------------------------------------------------------
// wxCheckListBox
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_CHECKLISTBOX_H__
#define __CLASS_WX_CHECKLISTBOX_H__
#include <wx/checklst.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxCheckListBox
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_CheckListBox);

//----------------------------------------------------------------------------
// Object declaration for wxCheckListBox
//----------------------------------------------------------------------------
class Object_wx_CheckListBox : public Object_wx_ListBox {
public:
	Gura_DeclareObjectAccessor(wx_CheckListBox)
public:
	inline Object_wx_CheckListBox(wxCheckListBox *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_ListBox(Gura_UserClass(wx_CheckListBox), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_CheckListBox(Class *pClass, wxCheckListBox *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_ListBox(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_CheckListBox();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxCheckListBox *GetEntity() {
		return static_cast<wxCheckListBox *>(_pEntity);
	}
	inline wxCheckListBox *ReleaseEntity() {
		wxCheckListBox *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxCheckListBox");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
