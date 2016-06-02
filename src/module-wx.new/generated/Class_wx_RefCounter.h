//----------------------------------------------------------------------------
// wxRefCounter
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_REFCOUNTER_H__
#define __CLASS_WX_REFCOUNTER_H__
#include <wx/object.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxRefCounter
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_RefCounter);

//----------------------------------------------------------------------------
// Object declaration for wxRefCounter
//----------------------------------------------------------------------------
class Object_wx_RefCounter : public Object {
protected:
	wxRefCounter *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_RefCounter)
public:
	inline Object_wx_RefCounter(wxRefCounter *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_RefCounter(Class *pClass, wxRefCounter *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_RefCounter();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxRefCounter *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxRefCounter *GetEntity() {
		return static_cast<wxRefCounter *>(_pEntity);
	}
	inline wxRefCounter *ReleaseEntity() {
		wxRefCounter *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxRefCounter");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
