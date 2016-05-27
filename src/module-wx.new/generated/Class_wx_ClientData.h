//----------------------------------------------------------------------------
// wxClientData
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_CLIENTDATA_H__
#define __CLASS_WX_CLIENTDATA_H__
#include <wx/clntdata.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxClientData
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_ClientData);

//----------------------------------------------------------------------------
// Object declaration for wxClientData
//----------------------------------------------------------------------------
class Object_wx_ClientData : public Object {
protected:
	wxClientData *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_ClientData)
public:
	inline Object_wx_ClientData(wxClientData *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_ClientData(Class *pClass, wxClientData *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_ClientData();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxClientData *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxClientData *GetEntity() {
		return static_cast<wxClientData *>(_pEntity);
	}
	inline wxClientData *ReleaseEntity() {
		wxClientData *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxClientData");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
