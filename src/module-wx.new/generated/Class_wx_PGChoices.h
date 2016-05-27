//----------------------------------------------------------------------------
// wxPGChoices
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_PGCHOICES_H__
#define __CLASS_WX_PGCHOICES_H__
#include <wx/propgrid/property.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxPGChoices
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_PGChoices);

//----------------------------------------------------------------------------
// Object declaration for wxPGChoices
//----------------------------------------------------------------------------
class Object_wx_PGChoices : public Object {
protected:
	wxPGChoices *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_PGChoices)
public:
	inline Object_wx_PGChoices(wxPGChoices *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_PGChoices(Class *pClass, wxPGChoices *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_PGChoices();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxPGChoices *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxPGChoices *GetEntity() {
		return static_cast<wxPGChoices *>(_pEntity);
	}
	inline wxPGChoices *ReleaseEntity() {
		wxPGChoices *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxPGChoices");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
