//----------------------------------------------------------------------------
// wxMenu
// extracted from menu.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_MENU_H__
#define __CLASS_WX_MENU_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxMenu
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_Menu);

//----------------------------------------------------------------------------
// Object declaration for wxMenu
//----------------------------------------------------------------------------
class Object_wx_Menu : public Object_wx_EvtHandler {
public:
	Gura_DeclareObjectAccessor(wx_Menu)
public:
	inline Object_wx_Menu(wxMenu *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_EvtHandler(Gura_UserClass(wx_Menu), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_Menu(Class *pClass, wxMenu *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_EvtHandler(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_Menu();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxMenu *GetEntity() {
		return dynamic_cast<wxMenu *>(_pEntity);
	}
	inline wxMenu *ReleaseEntity() {
		wxMenu *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxMenu");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
