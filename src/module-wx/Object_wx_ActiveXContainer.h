//----------------------------------------------------------------------------
// wxActiveXContainer
// extracted from activexcontainer.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_ACTIVEXCONTAINER_H__
#define __OBJECT_WX_ACTIVEXCONTAINER_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxActiveXContainer
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_ActiveXContainer);

//----------------------------------------------------------------------------
// Object declaration for wxActiveXContainer
//----------------------------------------------------------------------------
class Object_wx_ActiveXContainer : public Object_wx_Window {
public:
	Gura_DeclareObjectAccessor(wx_ActiveXContainer)
public:
	inline Object_wx_ActiveXContainer(wxActiveXContainer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Window(Gura_UserClass(wx_ActiveXContainer), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_ActiveXContainer(Class *pClass, wxActiveXContainer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Window(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_ActiveXContainer();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxActiveXContainer *GetEntity() {
		return dynamic_cast<wxActiveXContainer *>(_pEntity);
	}
	inline wxActiveXContainer *ReleaseEntity() {
		wxActiveXContainer *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxActiveXContainer");
		return true;
	}
};

}}

#endif
