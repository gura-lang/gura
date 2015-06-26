//----------------------------------------------------------------------------
// wxArchiveInputStream
// extracted from archive.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_ARCHIVEINPUTSTREAM_H__
#define __CLASS_WX_ARCHIVEINPUTSTREAM_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxArchiveInputStream
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_ArchiveInputStream);

//----------------------------------------------------------------------------
// Object declaration for wxArchiveInputStream
//----------------------------------------------------------------------------
class Object_wx_ArchiveInputStream : public Object_wx_FilterInputStream {
public:
	Gura_DeclareObjectAccessor(wx_ArchiveInputStream)
public:
	inline Object_wx_ArchiveInputStream(wxArchiveInputStream *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_FilterInputStream(Gura_UserClass(wx_ArchiveInputStream), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_ArchiveInputStream(Class *pClass, wxArchiveInputStream *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_FilterInputStream(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_ArchiveInputStream();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxArchiveInputStream *GetEntity() {
		return dynamic_cast<wxArchiveInputStream *>(_pEntity);
	}
	inline wxArchiveInputStream *ReleaseEntity() {
		wxArchiveInputStream *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxArchiveInputStream");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
