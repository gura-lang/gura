//----------------------------------------------------------------------------
// wxZipNotifier
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_ZIPNOTIFIER_H__
#define __CLASS_WX_ZIPNOTIFIER_H__
#include <wx/zipstrm.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxZipNotifier
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_ZipNotifier);

//----------------------------------------------------------------------------
// Object declaration for wxZipNotifier
//----------------------------------------------------------------------------
class Object_wx_ZipNotifier : public Object {
protected:
	wxZipNotifier *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_ZipNotifier)
public:
	inline Object_wx_ZipNotifier(wxZipNotifier *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_ZipNotifier(Class *pClass, wxZipNotifier *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_ZipNotifier();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxZipNotifier *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxZipNotifier *GetEntity() {
		return static_cast<wxZipNotifier *>(_pEntity);
	}
	inline wxZipNotifier *ReleaseEntity() {
		wxZipNotifier *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxZipNotifier");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
