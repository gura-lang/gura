//----------------------------------------------------------------------------
// wxGenericDirCtrl
// extracted from dirctrl.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_GENERICDIRCTRL_H__
#define __OBJECT_WX_GENERICDIRCTRL_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxGenericDirCtrl
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_GenericDirCtrl);

//----------------------------------------------------------------------------
// Object declaration for wxGenericDirCtrl
//----------------------------------------------------------------------------
class Object_wx_GenericDirCtrl : public Object_wx_Control {
public:
	Gura_DeclareObjectAccessor(wx_GenericDirCtrl)
public:
	inline Object_wx_GenericDirCtrl(wxGenericDirCtrl *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(Gura_UserClass(wx_GenericDirCtrl), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_GenericDirCtrl(Class *pClass, wxGenericDirCtrl *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_GenericDirCtrl();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxGenericDirCtrl *GetEntity() {
		return dynamic_cast<wxGenericDirCtrl *>(_pEntity);
	}
	inline wxGenericDirCtrl *ReleaseEntity() {
		wxGenericDirCtrl *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxGenericDirCtrl");
		return true;
	}
};

}}

#endif
