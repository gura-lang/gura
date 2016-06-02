//----------------------------------------------------------------------------
// wxArchiveFSHandler
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_ARCHIVEFSHANDLER_H__
#define __CLASS_WX_ARCHIVEFSHANDLER_H__
#include <wx/fs_arc.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxArchiveFSHandler
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_ArchiveFSHandler);

//----------------------------------------------------------------------------
// Object declaration for wxArchiveFSHandler
//----------------------------------------------------------------------------
class Object_wx_ArchiveFSHandler : public Object_wx_FileSystemHandler {
public:
	Gura_DeclareObjectAccessor(wx_ArchiveFSHandler)
public:
	inline Object_wx_ArchiveFSHandler(wxArchiveFSHandler *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_FileSystemHandler(Gura_UserClass(wx_ArchiveFSHandler), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_ArchiveFSHandler(Class *pClass, wxArchiveFSHandler *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_FileSystemHandler(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_ArchiveFSHandler();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxArchiveFSHandler *GetEntity() {
		return static_cast<wxArchiveFSHandler *>(_pEntity);
	}
	inline wxArchiveFSHandler *ReleaseEntity() {
		wxArchiveFSHandler *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxArchiveFSHandler");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
