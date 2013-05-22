//----------------------------------------------------------------------------
// wxDelegateRendererNative
// extracted from delgrend.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_DELEGATERENDERERNATIVE_H__
#define __OBJECT_WX_DELEGATERENDERERNATIVE_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxDelegateRendererNative
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_DelegateRendererNative);

//----------------------------------------------------------------------------
// Object declaration for wxDelegateRendererNative
//----------------------------------------------------------------------------
class Object_wx_DelegateRendererNative : public Object_wx_RendererNative {
public:
	Gura_DeclareObjectAccessor(wx_DelegateRendererNative)
public:
	inline Object_wx_DelegateRendererNative(wxDelegateRendererNative *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_RendererNative(Gura_UserClass(wx_DelegateRendererNative), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_DelegateRendererNative(Class *pClass, wxDelegateRendererNative *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_RendererNative(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_DelegateRendererNative();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxDelegateRendererNative *GetEntity() {
		return dynamic_cast<wxDelegateRendererNative *>(_pEntity);
	}
	inline wxDelegateRendererNative *ReleaseEntity() {
		wxDelegateRendererNative *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxDelegateRendererNative");
		return true;
	}
public:
	static void DoAssignConstructor(Environment &env, Signal sig);
};

}}

#endif
