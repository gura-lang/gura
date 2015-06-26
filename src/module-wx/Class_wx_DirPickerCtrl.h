//----------------------------------------------------------------------------
// wxDirPickerCtrl
// extracted from dirpicker.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_DIRPICKERCTRL_H__
#define __CLASS_WX_DIRPICKERCTRL_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxDirPickerCtrl
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_DirPickerCtrl);

//----------------------------------------------------------------------------
// Object declaration for wxDirPickerCtrl
//----------------------------------------------------------------------------
class Object_wx_DirPickerCtrl : public Object_wx_PickerBase {
public:
	Gura_DeclareObjectAccessor(wx_DirPickerCtrl)
public:
	inline Object_wx_DirPickerCtrl(wxDirPickerCtrl *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_PickerBase(Gura_UserClass(wx_DirPickerCtrl), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_DirPickerCtrl(Class *pClass, wxDirPickerCtrl *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_PickerBase(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_DirPickerCtrl();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxDirPickerCtrl *GetEntity() {
		return dynamic_cast<wxDirPickerCtrl *>(_pEntity);
	}
	inline wxDirPickerCtrl *ReleaseEntity() {
		wxDirPickerCtrl *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxDirPickerCtrl");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
