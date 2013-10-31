//----------------------------------------------------------------------------
// wxCheckListBox
// extracted from checklst.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_CHECKLISTBOX_H__
#define __OBJECT_WX_CHECKLISTBOX_H__

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
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxCheckListBox *GetEntity() {
		return dynamic_cast<wxCheckListBox *>(_pEntity);
	}
	inline wxCheckListBox *ReleaseEntity() {
		wxCheckListBox *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxCheckListBox");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
