//----------------------------------------------------------------------------
// wxFilePickerCtrl
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_FILEPICKERCTRL_H__
#define __CLASS_WX_FILEPICKERCTRL_H__
#include <wx/filepicker.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxFilePickerCtrl
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_FilePickerCtrl);

//----------------------------------------------------------------------------
// Object declaration for wxFilePickerCtrl
//----------------------------------------------------------------------------
class Object_wx_FilePickerCtrl : public Object_wx_PickerBase {
public:
	Gura_DeclareObjectAccessor(wx_FilePickerCtrl)
public:
	inline Object_wx_FilePickerCtrl(wxFilePickerCtrl *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_PickerBase(Gura_UserClass(wx_FilePickerCtrl), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_FilePickerCtrl(Class *pClass, wxFilePickerCtrl *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_PickerBase(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_FilePickerCtrl();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxFilePickerCtrl *GetEntity() {
		return static_cast<wxFilePickerCtrl *>(_pEntity);
	}
	inline wxFilePickerCtrl *ReleaseEntity() {
		wxFilePickerCtrl *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxFilePickerCtrl");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
