//----------------------------------------------------------------------------
// wxCollapsiblePane
// extracted from collpane.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_COLLAPSIBLEPANE_H__
#define __OBJECT_WX_COLLAPSIBLEPANE_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxCollapsiblePane
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_CollapsiblePane);

//----------------------------------------------------------------------------
// Object declaration for wxCollapsiblePane
//----------------------------------------------------------------------------
class Object_wx_CollapsiblePane : public Object_wx_Control {
public:
	Gura_DeclareObjectAccessor(wx_CollapsiblePane)
public:
	inline Object_wx_CollapsiblePane(wxCollapsiblePane *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(Gura_UserClass(wx_CollapsiblePane), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_CollapsiblePane(Class *pClass, wxCollapsiblePane *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_CollapsiblePane();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxCollapsiblePane *GetEntity() {
		return dynamic_cast<wxCollapsiblePane *>(_pEntity);
	}
	inline wxCollapsiblePane *ReleaseEntity() {
		wxCollapsiblePane *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxCollapsiblePane");
		return true;
	}
public:
	static void OnModuleEntry(Environment &env, Signal sig);
};

}}

#endif
