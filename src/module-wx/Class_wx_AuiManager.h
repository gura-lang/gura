//----------------------------------------------------------------------------
// wxAuiManager
// extracted from auimanager.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_AUIMANAGER_H__
#define __CLASS_WX_AUIMANAGER_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxAuiManager
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_AuiManager);

//----------------------------------------------------------------------------
// Object declaration for wxAuiManager
//----------------------------------------------------------------------------
class Object_wx_AuiManager : public Object_wx_EvtHandler {
public:
	Gura_DeclareObjectAccessor(wx_AuiManager)
public:
	inline Object_wx_AuiManager(wxAuiManager *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_EvtHandler(Gura_UserClass(wx_AuiManager), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_AuiManager(Class *pClass, wxAuiManager *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_EvtHandler(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_AuiManager();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxAuiManager *GetEntity() {
		return dynamic_cast<wxAuiManager *>(_pEntity);
	}
	inline wxAuiManager *ReleaseEntity() {
		wxAuiManager *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxAuiManager");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
