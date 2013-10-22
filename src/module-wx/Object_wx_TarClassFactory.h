//----------------------------------------------------------------------------
// wxTarClassFactory
// extracted from tarstrm.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_TARCLASSFACTORY_H__
#define __OBJECT_WX_TARCLASSFACTORY_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxTarClassFactory
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_TarClassFactory);

//----------------------------------------------------------------------------
// Object declaration for wxTarClassFactory
//----------------------------------------------------------------------------
class Object_wx_TarClassFactory : public Object_wx_ArchiveClassFactory {
public:
	Gura_DeclareObjectAccessor(wx_TarClassFactory)
public:
	inline Object_wx_TarClassFactory(wxTarClassFactory *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_ArchiveClassFactory(Gura_UserClass(wx_TarClassFactory), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_TarClassFactory(Class *pClass, wxTarClassFactory *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_ArchiveClassFactory(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_TarClassFactory();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxTarClassFactory *GetEntity() {
		return dynamic_cast<wxTarClassFactory *>(_pEntity);
	}
	inline wxTarClassFactory *ReleaseEntity() {
		wxTarClassFactory *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxTarClassFactory");
		return true;
	}
};

}}

#endif
