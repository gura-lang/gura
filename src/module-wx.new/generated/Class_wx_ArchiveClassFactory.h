//----------------------------------------------------------------------------
// wxArchiveClassFactory
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_ARCHIVECLASSFACTORY_H__
#define __CLASS_WX_ARCHIVECLASSFACTORY_H__
#include <wx/archive.h>

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
		return static_cast<wxArchiveClassFactory *>(_pEntity);
	}
	inline wxArchiveClassFactory *ReleaseEntity() {
		wxArchiveClassFactory *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxArchiveClassFactory");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
