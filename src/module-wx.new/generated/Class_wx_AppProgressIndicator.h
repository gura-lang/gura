//----------------------------------------------------------------------------
// wxAppProgressIndicator
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_APPPROGRESSINDICATOR_H__
#define __CLASS_WX_APPPROGRESSINDICATOR_H__
#include <wx/appprogress.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxAppProgressIndicator
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_AppProgressIndicator);

//----------------------------------------------------------------------------
// Object declaration for wxAppProgressIndicator
//----------------------------------------------------------------------------
class Object_wx_AppProgressIndicator : public Object {
protected:
	wxAppProgressIndicator *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_AppProgressIndicator)
public:
	inline Object_wx_AppProgressIndicator(wxAppProgressIndicator *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_AppProgressIndicator(Class *pClass, wxAppProgressIndicator *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_AppProgressIndicator();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxAppProgressIndicator *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxAppProgressIndicator *GetEntity() {
		return static_cast<wxAppProgressIndicator *>(_pEntity);
	}
	inline wxAppProgressIndicator *ReleaseEntity() {
		wxAppProgressIndicator *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxAppProgressIndicator");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
