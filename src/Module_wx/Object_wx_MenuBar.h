//----------------------------------------------------------------------------
// wxMenuBar
// extracted from menu.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_MENUBAR_H__
#define __OBJECT_WX_MENUBAR_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxMenuBar
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_MenuBar);

//----------------------------------------------------------------------------
// Object declaration for wxMenuBar
//----------------------------------------------------------------------------
class Object_wx_MenuBar : public Object_wx_Window {
public:
	Gura_DeclareObjectAccessor(wx_MenuBar)
public:
	inline Object_wx_MenuBar(wxMenuBar *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Window(Gura_UserClass(wx_MenuBar), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_MenuBar(Class *pClass, wxMenuBar *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Window(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_MenuBar();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxMenuBar *GetEntity() {
		return dynamic_cast<wxMenuBar *>(_pEntity);
	}
	inline wxMenuBar *ReleaseEntity() {
		wxMenuBar *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxMenuBar");
		return true;
	}
};

}}

#endif
