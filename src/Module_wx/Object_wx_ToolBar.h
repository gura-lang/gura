//----------------------------------------------------------------------------
// wxToolBar
// extracted from toolbar.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_TOOLBAR_H__
#define __OBJECT_WX_TOOLBAR_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxToolBar
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_ToolBar);

//----------------------------------------------------------------------------
// Object declaration for wxToolBar
//----------------------------------------------------------------------------
class Object_wx_ToolBar : public Object_wx_ToolBarBase {
public:
	Gura_DeclareObjectAccessor(wx_ToolBar)
public:
	inline Object_wx_ToolBar(wxToolBar *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_ToolBarBase(Gura_UserClass(wx_ToolBar), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_ToolBar(Class *pClass, wxToolBar *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_ToolBarBase(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_ToolBar();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxToolBar *GetEntity() {
		return dynamic_cast<wxToolBar *>(_pEntity);
	}
	inline wxToolBar *ReleaseEntity() {
		wxToolBar *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxToolBar");
		return true;
	}
};

}}

#endif
