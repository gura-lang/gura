//----------------------------------------------------------------------------
// wxRegEx
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_REGEX_H__
#define __CLASS_WX_REGEX_H__
#include <wx/regex.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxRegEx
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_RegEx);

//----------------------------------------------------------------------------
// Object declaration for wxRegEx
//----------------------------------------------------------------------------
class Object_wx_RegEx : public Object {
protected:
	wxRegEx *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_RegEx)
public:
	inline Object_wx_RegEx(wxRegEx *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_RegEx(Class *pClass, wxRegEx *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_RegEx();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxRegEx *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxRegEx *GetEntity() {
		return static_cast<wxRegEx *>(_pEntity);
	}
	inline wxRegEx *ReleaseEntity() {
		wxRegEx *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxRegEx");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
