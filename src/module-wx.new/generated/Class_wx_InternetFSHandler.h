//----------------------------------------------------------------------------
// wxInternetFSHandler
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_INTERNETFSHANDLER_H__
#define __CLASS_WX_INTERNETFSHANDLER_H__
#include <wx/fs_inet.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxInternetFSHandler
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_InternetFSHandler);

//----------------------------------------------------------------------------
// Object declaration for wxInternetFSHandler
//----------------------------------------------------------------------------
class Object_wx_InternetFSHandler : public Object_wx_FileSystemHandler {
public:
	Gura_DeclareObjectAccessor(wx_InternetFSHandler)
public:
	inline Object_wx_InternetFSHandler(wxInternetFSHandler *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_FileSystemHandler(Gura_UserClass(wx_InternetFSHandler), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_InternetFSHandler(Class *pClass, wxInternetFSHandler *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_FileSystemHandler(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_InternetFSHandler();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxInternetFSHandler *GetEntity() {
		return static_cast<wxInternetFSHandler *>(_pEntity);
	}
	inline wxInternetFSHandler *ReleaseEntity() {
		wxInternetFSHandler *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxInternetFSHandler");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
