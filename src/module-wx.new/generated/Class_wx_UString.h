//----------------------------------------------------------------------------
// wxUString
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_USTRING_H__
#define __CLASS_WX_USTRING_H__
#include <wx/ustring.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxUString
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_UString);

//----------------------------------------------------------------------------
// Object declaration for wxUString
//----------------------------------------------------------------------------
class Object_wx_UString : public Object {
protected:
	wxUString *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_UString)
public:
	inline Object_wx_UString(wxUString *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_UString(Class *pClass, wxUString *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_UString();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxUString *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxUString *GetEntity() {
		return static_cast<wxUString *>(_pEntity);
	}
	inline wxUString *ReleaseEntity() {
		wxUString *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxUString");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
