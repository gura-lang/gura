//----------------------------------------------------------------------------
// wxScrolled
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_SCROLLED_H__
#define __CLASS_WX_SCROLLED_H__
#include <wx/scrolwin.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxScrolled
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_Scrolled);

//----------------------------------------------------------------------------
// Object declaration for wxScrolled
//----------------------------------------------------------------------------
class Object_wx_Scrolled : public Object {
protected:
	wxScrolled *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_Scrolled)
public:
	inline Object_wx_Scrolled(wxScrolled *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_Scrolled(Class *pClass, wxScrolled *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_Scrolled();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxScrolled *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxScrolled *GetEntity() {
		return static_cast<wxScrolled *>(_pEntity);
	}
	inline wxScrolled *ReleaseEntity() {
		wxScrolled *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxScrolled");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
