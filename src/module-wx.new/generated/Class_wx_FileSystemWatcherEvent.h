//----------------------------------------------------------------------------
// wxFileSystemWatcherEvent
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_FILESYSTEMWATCHEREVENT_H__
#define __CLASS_WX_FILESYSTEMWATCHEREVENT_H__
#include <wx/fswatcher.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxFileSystemWatcherEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_FileSystemWatcherEvent);

//----------------------------------------------------------------------------
// Object declaration for wxFileSystemWatcherEvent
//----------------------------------------------------------------------------
class Object_wx_FileSystemWatcherEvent : public Object_wx_Event {
public:
	Gura_DeclareObjectAccessor(wx_FileSystemWatcherEvent)
public:
	inline Object_wx_FileSystemWatcherEvent(wxFileSystemWatcherEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Event(Gura_UserClass(wx_FileSystemWatcherEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_FileSystemWatcherEvent(Class *pClass, wxFileSystemWatcherEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Event(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_FileSystemWatcherEvent();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxFileSystemWatcherEvent *GetEntity() {
		return static_cast<wxFileSystemWatcherEvent *>(_pEntity);
	}
	inline wxFileSystemWatcherEvent *ReleaseEntity() {
		wxFileSystemWatcherEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxFileSystemWatcherEvent");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
