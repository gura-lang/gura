//----------------------------------------------------------------------------
// wxInitializer
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_INITIALIZER_H__
#define __CLASS_WX_INITIALIZER_H__
#include <wx/init.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxInitializer
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_Initializer);

//----------------------------------------------------------------------------
// Object declaration for wxInitializer
//----------------------------------------------------------------------------
class Object_wx_Initializer : public Object {
protected:
	wxInitializer *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_Initializer)
public:
	inline Object_wx_Initializer(wxInitializer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_Initializer(Class *pClass, wxInitializer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_Initializer();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxInitializer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxInitializer *GetEntity() {
		return static_cast<wxInitializer *>(_pEntity);
	}
	inline wxInitializer *ReleaseEntity() {
		wxInitializer *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxInitializer");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
