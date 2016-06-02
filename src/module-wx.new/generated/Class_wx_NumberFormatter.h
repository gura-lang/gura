//----------------------------------------------------------------------------
// wxNumberFormatter
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_NUMBERFORMATTER_H__
#define __CLASS_WX_NUMBERFORMATTER_H__
#include <wx/numformatter.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxNumberFormatter
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_NumberFormatter);

//----------------------------------------------------------------------------
// Object declaration for wxNumberFormatter
//----------------------------------------------------------------------------
class Object_wx_NumberFormatter : public Object {
protected:
	wxNumberFormatter *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_NumberFormatter)
public:
	inline Object_wx_NumberFormatter(wxNumberFormatter *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_NumberFormatter(Class *pClass, wxNumberFormatter *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_NumberFormatter();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxNumberFormatter *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxNumberFormatter *GetEntity() {
		return static_cast<wxNumberFormatter *>(_pEntity);
	}
	inline wxNumberFormatter *ReleaseEntity() {
		wxNumberFormatter *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxNumberFormatter");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
