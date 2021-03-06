//----------------------------------------------------------------------------
// wxHelpProvider
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_HELPPROVIDER_H__
#define __CLASS_WX_HELPPROVIDER_H__
#include <wx/cshelp.h>

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
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_HelpProvider(Class *pClass, wxHelpProvider *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_HelpProvider();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxHelpProvider *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxHelpProvider *GetEntity() {
		return static_cast<wxHelpProvider *>(_pEntity);
	}
	inline wxHelpProvider *ReleaseEntity() {
		wxHelpProvider *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxHelpProvider");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
