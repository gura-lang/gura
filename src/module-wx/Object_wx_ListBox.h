//----------------------------------------------------------------------------
// wxListBox
// extracted from listbox.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_LISTBOX_H__
#define __OBJECT_WX_LISTBOX_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxListBox
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_ListBox);

//----------------------------------------------------------------------------
// Object declaration for wxListBox
//----------------------------------------------------------------------------
class Object_wx_ListBox : public Object_wx_ControlWithItems {
public:
	Gura_DeclareObjectAccessor(wx_ListBox)
public:
	inline Object_wx_ListBox(wxListBox *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_ControlWithItems(Gura_UserClass(wx_ListBox), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_ListBox(Class *pClass, wxListBox *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_ControlWithItems(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_ListBox();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxListBox *GetEntity() {
		return dynamic_cast<wxListBox *>(_pEntity);
	}
	inline wxListBox *ReleaseEntity() {
		wxListBox *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxListBox");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
