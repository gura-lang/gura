//----------------------------------------------------------------------------
// wxFilterFSHandler
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_FILTERFSHANDLER_H__
#define __CLASS_WX_FILTERFSHANDLER_H__
#include <wx/fs_filter.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxFilterFSHandler
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_FilterFSHandler);

//----------------------------------------------------------------------------
// Object declaration for wxFilterFSHandler
//----------------------------------------------------------------------------
class Object_wx_FilterFSHandler : public Object_wx_FileSystemHandler {
public:
	Gura_DeclareObjectAccessor(wx_FilterFSHandler)
public:
	inline Object_wx_FilterFSHandler(wxFilterFSHandler *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_FileSystemHandler(Gura_UserClass(wx_FilterFSHandler), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_FilterFSHandler(Class *pClass, wxFilterFSHandler *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_FileSystemHandler(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_FilterFSHandler();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxFilterFSHandler *GetEntity() {
		return static_cast<wxFilterFSHandler *>(_pEntity);
	}
	inline wxFilterFSHandler *ReleaseEntity() {
		wxFilterFSHandler *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxFilterFSHandler");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
