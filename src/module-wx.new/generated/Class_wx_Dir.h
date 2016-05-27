//----------------------------------------------------------------------------
// wxDir
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_DIR_H__
#define __CLASS_WX_DIR_H__
#include <wx/dir.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxDir
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_Dir);

//----------------------------------------------------------------------------
// Object declaration for wxDir
//----------------------------------------------------------------------------
class Object_wx_Dir : public Object {
protected:
	wxDir *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_Dir)
public:
	inline Object_wx_Dir(wxDir *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_Dir(Class *pClass, wxDir *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_Dir();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxDir *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxDir *GetEntity() {
		return static_cast<wxDir *>(_pEntity);
	}
	inline wxDir *ReleaseEntity() {
		wxDir *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxDir");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
