//----------------------------------------------------------------------------
// wxDocManager
// extracted from docmanag.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_DOCMANAGER_H__
#define __OBJECT_WX_DOCMANAGER_H__

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
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxDocManager *GetEntity() {
		return dynamic_cast<wxDocManager *>(_pEntity);
	}
	inline wxDocManager *ReleaseEntity() {
		wxDocManager *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxDocManager");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
