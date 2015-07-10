//----------------------------------------------------------------------------
// wxScrolledWindow
// extracted from scrolwin.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_SCROLLEDWINDOW_H__
#define __CLASS_WX_SCROLLEDWINDOW_H__

Gura_BeginModuleScope(wx)

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
	virtual String ToString(bool exprFlag);
	inline wxScrolledWindow *GetEntity() {
		return dynamic_cast<wxScrolledWindow *>(_pEntity);
	}
	inline wxScrolledWindow *ReleaseEntity() {
		wxScrolledWindow *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxScrolledWindow");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
