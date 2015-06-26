//----------------------------------------------------------------------------
// wxContextHelpButton
// extracted from cshelp.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_CONTEXTHELPBUTTON_H__
#define __CLASS_WX_CONTEXTHELPBUTTON_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxContextHelpButton
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_ContextHelpButton);

//----------------------------------------------------------------------------
// Object declaration for wxContextHelpButton
//----------------------------------------------------------------------------
class Object_wx_ContextHelpButton : public Object_wx_BitmapButton {
public:
	Gura_DeclareObjectAccessor(wx_ContextHelpButton)
public:
	inline Object_wx_ContextHelpButton(wxContextHelpButton *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_BitmapButton(Gura_UserClass(wx_ContextHelpButton), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_ContextHelpButton(Class *pClass, wxContextHelpButton *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_BitmapButton(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_ContextHelpButton();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxContextHelpButton *GetEntity() {
		return dynamic_cast<wxContextHelpButton *>(_pEntity);
	}
	inline wxContextHelpButton *ReleaseEntity() {
		wxContextHelpButton *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxContextHelpButton");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
