//----------------------------------------------------------------------------
// wxZipEntry
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_ZIPENTRY_H__
#define __CLASS_WX_ZIPENTRY_H__
#include <wx/zipstrm.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxZipEntry
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_ZipEntry);

//----------------------------------------------------------------------------
// Object declaration for wxZipEntry
//----------------------------------------------------------------------------
class Object_wx_ZipEntry : public Object_wx_ArchiveEntry {
public:
	Gura_DeclareObjectAccessor(wx_ZipEntry)
public:
	inline Object_wx_ZipEntry(wxZipEntry *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_ArchiveEntry(Gura_UserClass(wx_ZipEntry), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_ZipEntry(Class *pClass, wxZipEntry *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_ArchiveEntry(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_ZipEntry();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxZipEntry *GetEntity() {
		return static_cast<wxZipEntry *>(_pEntity);
	}
	inline wxZipEntry *ReleaseEntity() {
		wxZipEntry *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxZipEntry");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
