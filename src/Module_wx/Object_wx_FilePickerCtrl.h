//----------------------------------------------------------------------------
// wxFilePickerCtrl
// extracted from filepicker.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_FILEPICKERCTRL_H__
#define __OBJECT_WX_FILEPICKERCTRL_H__

Gura_BeginModule(wx)

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
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxFilePickerCtrl *GetEntity() {
		return dynamic_cast<wxFilePickerCtrl *>(_pEntity);
	}
	inline wxFilePickerCtrl *ReleaseEntity() {
		wxFilePickerCtrl *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxFilePickerCtrl");
		return true;
	}
public:
	static void DoAssignConstructor(Environment &env, Signal sig);
};

}}

#endif
