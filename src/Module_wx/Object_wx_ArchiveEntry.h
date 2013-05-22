//----------------------------------------------------------------------------
// wxArchiveEntry
// extracted from archive.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_ARCHIVEENTRY_H__
#define __OBJECT_WX_ARCHIVEENTRY_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxArchiveEntry
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_ArchiveEntry);

//----------------------------------------------------------------------------
// Object declaration for wxArchiveEntry
//----------------------------------------------------------------------------
class Object_wx_ArchiveEntry : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_ArchiveEntry)
public:
	inline Object_wx_ArchiveEntry(wxArchiveEntry *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_ArchiveEntry), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_ArchiveEntry(Class *pClass, wxArchiveEntry *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_ArchiveEntry();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxArchiveEntry *GetEntity() {
		return dynamic_cast<wxArchiveEntry *>(_pEntity);
	}
	inline wxArchiveEntry *ReleaseEntity() {
		wxArchiveEntry *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxArchiveEntry");
		return true;
	}
};

}}

#endif
