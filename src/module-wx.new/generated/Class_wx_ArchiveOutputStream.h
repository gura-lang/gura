//----------------------------------------------------------------------------
// wxArchiveOutputStream
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_ARCHIVEOUTPUTSTREAM_H__
#define __CLASS_WX_ARCHIVEOUTPUTSTREAM_H__
#include <wx/archive.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxArchiveOutputStream
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_ArchiveOutputStream);

//----------------------------------------------------------------------------
// Object declaration for wxArchiveOutputStream
//----------------------------------------------------------------------------
class Object_wx_ArchiveOutputStream : public Object_wx_FilterOutputStream {
public:
	Gura_DeclareObjectAccessor(wx_ArchiveOutputStream)
public:
	inline Object_wx_ArchiveOutputStream(wxArchiveOutputStream *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_FilterOutputStream(Gura_UserClass(wx_ArchiveOutputStream), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_ArchiveOutputStream(Class *pClass, wxArchiveOutputStream *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_FilterOutputStream(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_ArchiveOutputStream();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxArchiveOutputStream *GetEntity() {
		return static_cast<wxArchiveOutputStream *>(_pEntity);
	}
	inline wxArchiveOutputStream *ReleaseEntity() {
		wxArchiveOutputStream *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxArchiveOutputStream");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
