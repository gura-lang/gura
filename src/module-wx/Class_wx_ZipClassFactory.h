//----------------------------------------------------------------------------
// wxZipClassFactory
// extracted from zipstrm.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_ZIPCLASSFACTORY_H__
#define __CLASS_WX_ZIPCLASSFACTORY_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxZipClassFactory
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_ZipClassFactory);

//----------------------------------------------------------------------------
// Object declaration for wxZipClassFactory
//----------------------------------------------------------------------------
class Object_wx_ZipClassFactory : public Object_wx_ArchiveClassFactory {
public:
	Gura_DeclareObjectAccessor(wx_ZipClassFactory)
public:
	inline Object_wx_ZipClassFactory(wxZipClassFactory *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_ArchiveClassFactory(Gura_UserClass(wx_ZipClassFactory), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_ZipClassFactory(Class *pClass, wxZipClassFactory *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_ArchiveClassFactory(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_ZipClassFactory();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxZipClassFactory *GetEntity() {
		return dynamic_cast<wxZipClassFactory *>(_pEntity);
	}
	inline wxZipClassFactory *ReleaseEntity() {
		wxZipClassFactory *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxZipClassFactory");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
