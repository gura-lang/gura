//----------------------------------------------------------------------------
// wxUniCharRef
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_UNICHARREF_H__
#define __CLASS_WX_UNICHARREF_H__
#include <wx/unichar.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxUniCharRef
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_UniCharRef);

//----------------------------------------------------------------------------
// Object declaration for wxUniCharRef
//----------------------------------------------------------------------------
class Object_wx_UniCharRef : public Object {
protected:
	wxUniCharRef *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_UniCharRef)
public:
	inline Object_wx_UniCharRef(wxUniCharRef *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_UniCharRef(Class *pClass, wxUniCharRef *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_UniCharRef();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxUniCharRef *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxUniCharRef *GetEntity() {
		return static_cast<wxUniCharRef *>(_pEntity);
	}
	inline wxUniCharRef *ReleaseEntity() {
		wxUniCharRef *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxUniCharRef");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
