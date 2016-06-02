//----------------------------------------------------------------------------
// wxStatusBarPane
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_STATUSBARPANE_H__
#define __CLASS_WX_STATUSBARPANE_H__
#include <wx/statusbr.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxStatusBarPane
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_StatusBarPane);

//----------------------------------------------------------------------------
// Object declaration for wxStatusBarPane
//----------------------------------------------------------------------------
class Object_wx_StatusBarPane : public Object {
protected:
	wxStatusBarPane *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_StatusBarPane)
public:
	inline Object_wx_StatusBarPane(wxStatusBarPane *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_StatusBarPane(Class *pClass, wxStatusBarPane *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_StatusBarPane();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxStatusBarPane *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxStatusBarPane *GetEntity() {
		return static_cast<wxStatusBarPane *>(_pEntity);
	}
	inline wxStatusBarPane *ReleaseEntity() {
		wxStatusBarPane *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxStatusBarPane");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
