//----------------------------------------------------------------------------
// wxListBox
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_LISTBOX_H__
#define __CLASS_WX_LISTBOX_H__
#include <wx/listbox.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxListBox
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_ListBox);

//----------------------------------------------------------------------------
// Object declaration for wxListBox
//----------------------------------------------------------------------------
class Object_wx_ListBox : public Object_wx_Control {
public:
	Gura_DeclareObjectAccessor(wx_ListBox)
public:
	inline Object_wx_ListBox(wxListBox *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(Gura_UserClass(wx_ListBox), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_ListBox(Class *pClass, wxListBox *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_ListBox();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxListBox *GetEntity() {
		return static_cast<wxListBox *>(_pEntity);
	}
	inline wxListBox *ReleaseEntity() {
		wxListBox *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxListBox");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
