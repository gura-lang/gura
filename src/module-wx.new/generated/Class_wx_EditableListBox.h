//----------------------------------------------------------------------------
// wxEditableListBox
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_EDITABLELISTBOX_H__
#define __CLASS_WX_EDITABLELISTBOX_H__
#include <wx/editlbox.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxEditableListBox
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_EditableListBox);

//----------------------------------------------------------------------------
// Object declaration for wxEditableListBox
//----------------------------------------------------------------------------
class Object_wx_EditableListBox : public Object_wx_Panel {
public:
	Gura_DeclareObjectAccessor(wx_EditableListBox)
public:
	inline Object_wx_EditableListBox(wxEditableListBox *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Panel(Gura_UserClass(wx_EditableListBox), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_EditableListBox(Class *pClass, wxEditableListBox *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Panel(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_EditableListBox();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxEditableListBox *GetEntity() {
		return static_cast<wxEditableListBox *>(_pEntity);
	}
	inline wxEditableListBox *ReleaseEntity() {
		wxEditableListBox *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxEditableListBox");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
