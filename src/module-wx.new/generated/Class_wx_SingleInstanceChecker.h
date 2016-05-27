//----------------------------------------------------------------------------
// wxSingleInstanceChecker
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_SINGLEINSTANCECHECKER_H__
#define __CLASS_WX_SINGLEINSTANCECHECKER_H__
#include <wx/snglinst.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxSingleInstanceChecker
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_SingleInstanceChecker);

//----------------------------------------------------------------------------
// Object declaration for wxSingleInstanceChecker
//----------------------------------------------------------------------------
class Object_wx_SingleInstanceChecker : public Object {
protected:
	wxSingleInstanceChecker *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_SingleInstanceChecker)
public:
	inline Object_wx_SingleInstanceChecker(wxSingleInstanceChecker *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_SingleInstanceChecker(Class *pClass, wxSingleInstanceChecker *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_SingleInstanceChecker();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxSingleInstanceChecker *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxSingleInstanceChecker *GetEntity() {
		return static_cast<wxSingleInstanceChecker *>(_pEntity);
	}
	inline wxSingleInstanceChecker *ReleaseEntity() {
		wxSingleInstanceChecker *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxSingleInstanceChecker");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
