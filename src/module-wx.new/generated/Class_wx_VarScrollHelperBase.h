//----------------------------------------------------------------------------
// wxVarScrollHelperBase
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_VARSCROLLHELPERBASE_H__
#define __CLASS_WX_VARSCROLLHELPERBASE_H__
#include <wx/vscroll.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxVarScrollHelperBase
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_VarScrollHelperBase);

//----------------------------------------------------------------------------
// Object declaration for wxVarScrollHelperBase
//----------------------------------------------------------------------------
class Object_wx_VarScrollHelperBase : public Object {
protected:
	wxVarScrollHelperBase *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_VarScrollHelperBase)
public:
	inline Object_wx_VarScrollHelperBase(wxVarScrollHelperBase *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_VarScrollHelperBase(Class *pClass, wxVarScrollHelperBase *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_VarScrollHelperBase();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxVarScrollHelperBase *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxVarScrollHelperBase *GetEntity() {
		return static_cast<wxVarScrollHelperBase *>(_pEntity);
	}
	inline wxVarScrollHelperBase *ReleaseEntity() {
		wxVarScrollHelperBase *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxVarScrollHelperBase");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
