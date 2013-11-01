//----------------------------------------------------------------------------
// wxZipInputStream
// extracted from zipstrm.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_ZIPINPUTSTREAM_H__
#define __CLASS_WX_ZIPINPUTSTREAM_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxZipInputStream
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_ZipInputStream);

//----------------------------------------------------------------------------
// Object declaration for wxZipInputStream
//----------------------------------------------------------------------------
class Object_wx_ZipInputStream : public Object_wx_ArchiveInputStream {
public:
	Gura_DeclareObjectAccessor(wx_ZipInputStream)
public:
	inline Object_wx_ZipInputStream(wxZipInputStream *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_ArchiveInputStream(Gura_UserClass(wx_ZipInputStream), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_ZipInputStream(Class *pClass, wxZipInputStream *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_ArchiveInputStream(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_ZipInputStream();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxZipInputStream *GetEntity() {
		return dynamic_cast<wxZipInputStream *>(_pEntity);
	}
	inline wxZipInputStream *ReleaseEntity() {
		wxZipInputStream *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxZipInputStream");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
