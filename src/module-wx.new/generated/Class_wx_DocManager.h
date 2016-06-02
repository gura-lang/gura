//----------------------------------------------------------------------------
// wxDocManager
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_DOCMANAGER_H__
#define __CLASS_WX_DOCMANAGER_H__
#include <wx/docview.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxDocManager
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_DocManager);

//----------------------------------------------------------------------------
// Object declaration for wxDocManager
//----------------------------------------------------------------------------
class Object_wx_DocManager : public Object_wx_EvtHandler {
public:
	Gura_DeclareObjectAccessor(wx_DocManager)
public:
	inline Object_wx_DocManager(wxDocManager *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_EvtHandler(Gura_UserClass(wx_DocManager), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_DocManager(Class *pClass, wxDocManager *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_EvtHandler(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_DocManager();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxDocManager *GetEntity() {
		return static_cast<wxDocManager *>(_pEntity);
	}
	inline wxDocManager *ReleaseEntity() {
		wxDocManager *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxDocManager");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
