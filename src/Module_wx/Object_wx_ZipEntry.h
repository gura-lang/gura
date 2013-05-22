//----------------------------------------------------------------------------
// wxZipEntry
// extracted from zipstrm.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_ZIPENTRY_H__
#define __OBJECT_WX_ZIPENTRY_H__

Gura_BeginModule(wx)

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
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxZipEntry *GetEntity() {
		return dynamic_cast<wxZipEntry *>(_pEntity);
	}
	inline wxZipEntry *ReleaseEntity() {
		wxZipEntry *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxZipEntry");
		return true;
	}
public:
	static void DoAssignConstructor(Environment &env, Signal sig);
};

}}

#endif
