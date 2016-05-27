//----------------------------------------------------------------------------
// wxArrayString
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_ARRAYSTRING_H__
#define __CLASS_WX_ARRAYSTRING_H__
#include <wx/arrstr.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxArrayString
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_ArrayString);

//----------------------------------------------------------------------------
// Object declaration for wxArrayString
//----------------------------------------------------------------------------
class Object_wx_ArrayString : public Object {
protected:
	wxArrayString *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_ArrayString)
public:
	inline Object_wx_ArrayString(wxArrayString *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_ArrayString(Class *pClass, wxArrayString *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_ArrayString();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxArrayString *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxArrayString *GetEntity() {
		return static_cast<wxArrayString *>(_pEntity);
	}
	inline wxArrayString *ReleaseEntity() {
		wxArrayString *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxArrayString");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
