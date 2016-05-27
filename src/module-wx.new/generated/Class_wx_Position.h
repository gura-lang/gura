//----------------------------------------------------------------------------
// wxPosition
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_POSITION_H__
#define __CLASS_WX_POSITION_H__
#include <wx/position.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxPosition
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_Position);

//----------------------------------------------------------------------------
// Object declaration for wxPosition
//----------------------------------------------------------------------------
class Object_wx_Position : public Object {
protected:
	wxPosition *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_Position)
public:
	inline Object_wx_Position(wxPosition *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_Position(Class *pClass, wxPosition *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_Position();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxPosition *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxPosition *GetEntity() {
		return static_cast<wxPosition *>(_pEntity);
	}
	inline wxPosition *ReleaseEntity() {
		wxPosition *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxPosition");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
