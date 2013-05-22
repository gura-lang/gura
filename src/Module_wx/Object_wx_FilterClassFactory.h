//----------------------------------------------------------------------------
// wxFilterClassFactory
// extracted from fltfactory.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_FILTERCLASSFACTORY_H__
#define __OBJECT_WX_FILTERCLASSFACTORY_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxFilterClassFactory
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_FilterClassFactory);

//----------------------------------------------------------------------------
// Object declaration for wxFilterClassFactory
//----------------------------------------------------------------------------
class Object_wx_FilterClassFactory : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_FilterClassFactory)
public:
	inline Object_wx_FilterClassFactory(wxFilterClassFactory *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_FilterClassFactory), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_FilterClassFactory(Class *pClass, wxFilterClassFactory *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_FilterClassFactory();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxFilterClassFactory *GetEntity() {
		return dynamic_cast<wxFilterClassFactory *>(_pEntity);
	}
	inline wxFilterClassFactory *ReleaseEntity() {
		wxFilterClassFactory *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxFilterClassFactory");
		return true;
	}
public:
	static void DoAssignConstructor(Environment &env, Signal sig);
};

}}

#endif
