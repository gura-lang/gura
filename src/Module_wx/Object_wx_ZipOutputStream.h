//----------------------------------------------------------------------------
// wxZipOutputStream
// extracted from zipstrm.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_ZIPOUTPUTSTREAM_H__
#define __OBJECT_WX_ZIPOUTPUTSTREAM_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxZipOutputStream
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_ZipOutputStream);

//----------------------------------------------------------------------------
// Object declaration for wxZipOutputStream
//----------------------------------------------------------------------------
class Object_wx_ZipOutputStream : public Object_wx_ArchiveOutputStream {
public:
	Gura_DeclareObjectAccessor(wx_ZipOutputStream)
public:
	inline Object_wx_ZipOutputStream(wxZipOutputStream *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_ArchiveOutputStream(Gura_UserClass(wx_ZipOutputStream), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_ZipOutputStream(Class *pClass, wxZipOutputStream *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_ArchiveOutputStream(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_ZipOutputStream();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxZipOutputStream *GetEntity() {
		return dynamic_cast<wxZipOutputStream *>(_pEntity);
	}
	inline wxZipOutputStream *ReleaseEntity() {
		wxZipOutputStream *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxZipOutputStream");
		return true;
	}
public:
	static void DoAssignConstructor(Environment &env, Signal sig);
};

}}

#endif
