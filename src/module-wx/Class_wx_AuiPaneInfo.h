//----------------------------------------------------------------------------
// wxAuiPaneInfo
// extracted from auipaneinfo.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_AUIPANEINFO_H__
#define __CLASS_WX_AUIPANEINFO_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxAuiPaneInfo
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_AuiPaneInfo);

//----------------------------------------------------------------------------
// Object declaration for wxAuiPaneInfo
//----------------------------------------------------------------------------
class Object_wx_AuiPaneInfo : public Object {
protected:
	wxAuiPaneInfo *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_AuiPaneInfo)
public:
	inline Object_wx_AuiPaneInfo(wxAuiPaneInfo *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AuiPaneInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_AuiPaneInfo(Class *pClass, wxAuiPaneInfo *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_AuiPaneInfo();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxAuiPaneInfo *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = NULL, _pObserver = NULL, _ownerFlag = false; }
	inline wxAuiPaneInfo *GetEntity() { return _pEntity; }
	inline wxAuiPaneInfo *ReleaseEntity() {
		wxAuiPaneInfo *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != NULL) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxAuiPaneInfo");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
