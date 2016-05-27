//----------------------------------------------------------------------------
// wxAddRemoveAdaptor
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_ADDREMOVEADAPTOR_H__
#define __CLASS_WX_ADDREMOVEADAPTOR_H__
#include <wx/addremovectrl.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxAddRemoveAdaptor
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_AddRemoveAdaptor);

//----------------------------------------------------------------------------
// Object declaration for wxAddRemoveAdaptor
//----------------------------------------------------------------------------
class Object_wx_AddRemoveAdaptor : public Object {
protected:
	wxAddRemoveAdaptor *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_AddRemoveAdaptor)
public:
	inline Object_wx_AddRemoveAdaptor(wxAddRemoveAdaptor *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_AddRemoveAdaptor(Class *pClass, wxAddRemoveAdaptor *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_AddRemoveAdaptor();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxAddRemoveAdaptor *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxAddRemoveAdaptor *GetEntity() {
		return static_cast<wxAddRemoveAdaptor *>(_pEntity);
	}
	inline wxAddRemoveAdaptor *ReleaseEntity() {
		wxAddRemoveAdaptor *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxAddRemoveAdaptor");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
