//----------------------------------------------------------------------------
// wxArchiveClassFactory
// extracted from archive.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_ARCHIVECLASSFACTORY_H__
#define __CLASS_WX_ARCHIVECLASSFACTORY_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxArchiveClassFactory
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_ArchiveClassFactory);

//----------------------------------------------------------------------------
// Object declaration for wxArchiveClassFactory
//----------------------------------------------------------------------------
class Object_wx_ArchiveClassFactory : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_ArchiveClassFactory)
public:
	inline Object_wx_ArchiveClassFactory(wxArchiveClassFactory *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_ArchiveClassFactory), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_ArchiveClassFactory(Class *pClass, wxArchiveClassFactory *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_ArchiveClassFactory();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxArchiveClassFactory *GetEntity() {
		return dynamic_cast<wxArchiveClassFactory *>(_pEntity);
	}
	inline wxArchiveClassFactory *ReleaseEntity() {
		wxArchiveClassFactory *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxArchiveClassFactory");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
