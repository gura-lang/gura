//----------------------------------------------------------------------------
// wxTreeCtrl
// extracted from treectrl.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_TREECTRL_H__
#define __OBJECT_WX_TREECTRL_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxTreeCtrl
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_TreeCtrl);

//----------------------------------------------------------------------------
// Object declaration for wxTreeCtrl
//----------------------------------------------------------------------------
class Object_wx_TreeCtrl : public Object_wx_Control {
public:
	Gura_DeclareObjectAccessor(wx_TreeCtrl)
public:
	inline Object_wx_TreeCtrl(wxTreeCtrl *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(Gura_UserClass(wx_TreeCtrl), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_TreeCtrl(Class *pClass, wxTreeCtrl *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_TreeCtrl();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxTreeCtrl *GetEntity() {
		return dynamic_cast<wxTreeCtrl *>(_pEntity);
	}
	inline wxTreeCtrl *ReleaseEntity() {
		wxTreeCtrl *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxTreeCtrl");
		return true;
	}
public:
	static void DoAssignConstructor(Environment &env, Signal sig);
};

}}

#endif
