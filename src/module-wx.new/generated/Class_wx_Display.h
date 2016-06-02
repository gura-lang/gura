//----------------------------------------------------------------------------
// wxDisplay
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_DISPLAY_H__
#define __CLASS_WX_DISPLAY_H__
#include <wx/display.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxDisplay
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_Display);

//----------------------------------------------------------------------------
// Object declaration for wxDisplay
//----------------------------------------------------------------------------
class Object_wx_Display : public Object {
protected:
	wxDisplay *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_Display)
public:
	inline Object_wx_Display(wxDisplay *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_Display(Class *pClass, wxDisplay *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_Display();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxDisplay *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxDisplay *GetEntity() {
		return static_cast<wxDisplay *>(_pEntity);
	}
	inline wxDisplay *ReleaseEntity() {
		wxDisplay *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxDisplay");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
