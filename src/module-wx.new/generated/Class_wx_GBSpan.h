//----------------------------------------------------------------------------
// wxGBSpan
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_GBSPAN_H__
#define __CLASS_WX_GBSPAN_H__
#include <wx/gbsizer.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxGBSpan
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_GBSpan);

//----------------------------------------------------------------------------
// Object declaration for wxGBSpan
//----------------------------------------------------------------------------
class Object_wx_GBSpan : public Object {
protected:
	wxGBSpan *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_GBSpan)
public:
	inline Object_wx_GBSpan(wxGBSpan *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_GBSpan(Class *pClass, wxGBSpan *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_GBSpan();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxGBSpan *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxGBSpan *GetEntity() {
		return static_cast<wxGBSpan *>(_pEntity);
	}
	inline wxGBSpan *ReleaseEntity() {
		wxGBSpan *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxGBSpan");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
