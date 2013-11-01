//----------------------------------------------------------------------------
// wxHelpProvider
// extracted from helpprov.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_HELPPROVIDER_H__
#define __CLASS_WX_HELPPROVIDER_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxHelpProvider
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_HelpProvider);

//----------------------------------------------------------------------------
// Object declaration for wxHelpProvider
//----------------------------------------------------------------------------
class Object_wx_HelpProvider : public Object {
protected:
	wxHelpProvider *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_HelpProvider)
public:
	inline Object_wx_HelpProvider(wxHelpProvider *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_HelpProvider)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_HelpProvider(Class *pClass, wxHelpProvider *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_HelpProvider();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxHelpProvider *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = NULL, _pObserver = NULL, _ownerFlag = false; }
	inline wxHelpProvider *GetEntity() { return _pEntity; }
	inline wxHelpProvider *ReleaseEntity() {
		wxHelpProvider *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != NULL) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxHelpProvider");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
