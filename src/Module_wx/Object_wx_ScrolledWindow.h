//----------------------------------------------------------------------------
// wxScrolledWindow
// extracted from scrolwin.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_SCROLLEDWINDOW_H__
#define __OBJECT_WX_SCROLLEDWINDOW_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxScrolledWindow
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_ScrolledWindow);

//----------------------------------------------------------------------------
// Object declaration for wxScrolledWindow
//----------------------------------------------------------------------------
class Object_wx_ScrolledWindow : public Object_wx_Panel {
public:
	Gura_DeclareObjectAccessor(wx_ScrolledWindow)
public:
	inline Object_wx_ScrolledWindow(wxScrolledWindow *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Panel(Gura_UserClass(wx_ScrolledWindow), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_ScrolledWindow(Class *pClass, wxScrolledWindow *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Panel(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_ScrolledWindow();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxScrolledWindow *GetEntity() {
		return dynamic_cast<wxScrolledWindow *>(_pEntity);
	}
	inline wxScrolledWindow *ReleaseEntity() {
		wxScrolledWindow *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxScrolledWindow");
		return true;
	}
public:
	static void DoAssignConstructor(Environment &env, Signal sig);
};

}}

#endif
