//----------------------------------------------------------------------------
// wxUniChar
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_UNICHAR_H__
#define __CLASS_WX_UNICHAR_H__
#include <wx/unichar.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxUniChar
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_UniChar);

//----------------------------------------------------------------------------
// Object declaration for wxUniChar
//----------------------------------------------------------------------------
class Object_wx_UniChar : public Object {
protected:
	wxUniChar *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_UniChar)
public:
	inline Object_wx_UniChar(wxUniChar *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_UniChar(Class *pClass, wxUniChar *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_UniChar();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxUniChar *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxUniChar *GetEntity() {
		return static_cast<wxUniChar *>(_pEntity);
	}
	inline wxUniChar *ReleaseEntity() {
		wxUniChar *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxUniChar");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
