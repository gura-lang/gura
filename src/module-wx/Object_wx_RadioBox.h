//----------------------------------------------------------------------------
// wxRadioBox
// extracted from radiobox.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_RADIOBOX_H__
#define __OBJECT_WX_RADIOBOX_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxRadioBox
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_RadioBox);

//----------------------------------------------------------------------------
// Object declaration for wxRadioBox
//----------------------------------------------------------------------------
class Object_wx_RadioBox : public Object_wx_Control {
public:
	Gura_DeclareObjectAccessor(wx_RadioBox)
public:
	inline Object_wx_RadioBox(wxRadioBox *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(Gura_UserClass(wx_RadioBox), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_RadioBox(Class *pClass, wxRadioBox *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_RadioBox();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxRadioBox *GetEntity() {
		return dynamic_cast<wxRadioBox *>(_pEntity);
	}
	inline wxRadioBox *ReleaseEntity() {
		wxRadioBox *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxRadioBox");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
