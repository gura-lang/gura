//----------------------------------------------------------------------------
// wxZipOutputStream
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_ZIPOUTPUTSTREAM_H__
#define __CLASS_WX_ZIPOUTPUTSTREAM_H__
#include <wx/zipstrm.h>

Gura_BeginModuleScope(wx)

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
	virtual String ToString(bool exprFlag);
	inline wxZipOutputStream *GetEntity() {
		return static_cast<wxZipOutputStream *>(_pEntity);
	}
	inline wxZipOutputStream *ReleaseEntity() {
		wxZipOutputStream *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxZipOutputStream");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
