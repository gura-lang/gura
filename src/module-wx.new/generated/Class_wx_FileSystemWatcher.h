//----------------------------------------------------------------------------
// wxFileSystemWatcher
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_FILESYSTEMWATCHER_H__
#define __CLASS_WX_FILESYSTEMWATCHER_H__
#include <wx/fswatcher.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxFileSystemWatcher
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_FileSystemWatcher);

//----------------------------------------------------------------------------
// Object declaration for wxFileSystemWatcher
//----------------------------------------------------------------------------
class Object_wx_FileSystemWatcher : public Object_wx_EvtHandler {
public:
	Gura_DeclareObjectAccessor(wx_FileSystemWatcher)
public:
	inline Object_wx_FileSystemWatcher(wxFileSystemWatcher *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_EvtHandler(Gura_UserClass(wx_FileSystemWatcher), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_FileSystemWatcher(Class *pClass, wxFileSystemWatcher *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_EvtHandler(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_FileSystemWatcher();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxFileSystemWatcher *GetEntity() {
		return static_cast<wxFileSystemWatcher *>(_pEntity);
	}
	inline wxFileSystemWatcher *ReleaseEntity() {
		wxFileSystemWatcher *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxFileSystemWatcher");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
