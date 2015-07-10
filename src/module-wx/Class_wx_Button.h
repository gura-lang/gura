//----------------------------------------------------------------------------
// wxButton
// extracted from button.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_BUTTON_H__
#define __CLASS_WX_BUTTON_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxButton
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_Button);

//----------------------------------------------------------------------------
// Object declaration for wxButton
//----------------------------------------------------------------------------
class Object_wx_Button : public Object_wx_Control {
public:
	Gura_DeclareObjectAccessor(wx_Button)
public:
	inline Object_wx_Button(wxButton *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(Gura_UserClass(wx_Button), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_Button(Class *pClass, wxButton *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_Button();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxButton *GetEntity() {
		return dynamic_cast<wxButton *>(_pEntity);
	}
	inline wxButton *ReleaseEntity() {
		wxButton *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxButton");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
