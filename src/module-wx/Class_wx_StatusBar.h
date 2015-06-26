//----------------------------------------------------------------------------
// wxStatusBar
// extracted from statusbr.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_STATUSBAR_H__
#define __CLASS_WX_STATUSBAR_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxStatusBar
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_StatusBar);

//----------------------------------------------------------------------------
// Object declaration for wxStatusBar
//----------------------------------------------------------------------------
class Object_wx_StatusBar : public Object_wx_Window {
public:
	Gura_DeclareObjectAccessor(wx_StatusBar)
public:
	inline Object_wx_StatusBar(wxStatusBar *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Window(Gura_UserClass(wx_StatusBar), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_StatusBar(Class *pClass, wxStatusBar *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Window(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_StatusBar();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxStatusBar *GetEntity() {
		return dynamic_cast<wxStatusBar *>(_pEntity);
	}
	inline wxStatusBar *ReleaseEntity() {
		wxStatusBar *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxStatusBar");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
