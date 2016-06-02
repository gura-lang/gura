//----------------------------------------------------------------------------
// wxXLocale
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_XLOCALE_H__
#define __CLASS_WX_XLOCALE_H__
#include <wx/xlocale.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxXLocale
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_XLocale);

//----------------------------------------------------------------------------
// Object declaration for wxXLocale
//----------------------------------------------------------------------------
class Object_wx_XLocale : public Object {
protected:
	wxXLocale *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_XLocale)
public:
	inline Object_wx_XLocale(wxXLocale *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_XLocale(Class *pClass, wxXLocale *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_XLocale();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxXLocale *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxXLocale *GetEntity() {
		return static_cast<wxXLocale *>(_pEntity);
	}
	inline wxXLocale *ReleaseEntity() {
		wxXLocale *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxXLocale");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
