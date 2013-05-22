//----------------------------------------------------------------------------
// wxTarEntry
// extracted from tarstrm.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_TARENTRY_H__
#define __OBJECT_WX_TARENTRY_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxTarEntry
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_TarEntry);

//----------------------------------------------------------------------------
// Object declaration for wxTarEntry
//----------------------------------------------------------------------------
class Object_wx_TarEntry : public Object_wx_ArchiveEntry {
public:
	Gura_DeclareObjectAccessor(wx_TarEntry)
public:
	inline Object_wx_TarEntry(wxTarEntry *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_ArchiveEntry(Gura_UserClass(wx_TarEntry), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_TarEntry(Class *pClass, wxTarEntry *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_ArchiveEntry(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_TarEntry();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxTarEntry *GetEntity() {
		return dynamic_cast<wxTarEntry *>(_pEntity);
	}
	inline wxTarEntry *ReleaseEntity() {
		wxTarEntry *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxTarEntry");
		return true;
	}
};

}}

#endif
