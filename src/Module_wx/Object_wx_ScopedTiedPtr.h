//----------------------------------------------------------------------------
// wxScopedTiedPtr
// extracted from scpdptr.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_SCOPEDTIEDPTR_H__
#define __OBJECT_WX_SCOPEDTIEDPTR_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxScopedTiedPtr
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_ScopedTiedPtr);

//----------------------------------------------------------------------------
// Object declaration for wxScopedTiedPtr
//----------------------------------------------------------------------------
class Object_wx_ScopedTiedPtr : public Object_wx_ScopedPtr {
public:
	Gura_DeclareObjectAccessor(wx_ScopedTiedPtr)
public:
	inline Object_wx_ScopedTiedPtr(wxScopedTiedPtr *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_ScopedPtr(Gura_UserClass(wx_ScopedTiedPtr), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_ScopedTiedPtr(Class *pClass, wxScopedTiedPtr *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_ScopedPtr(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_ScopedTiedPtr();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxScopedTiedPtr *GetEntity() {
		return dynamic_cast<wxScopedTiedPtr *>(_pEntity);
	}
	inline wxScopedTiedPtr *ReleaseEntity() {
		wxScopedTiedPtr *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxScopedTiedPtr");
		return true;
	}
public:
	static void OnModuleEntry(Environment &env, Signal sig);
};

}}

#endif
