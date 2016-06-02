//----------------------------------------------------------------------------
// wxAnyValueType
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_ANYVALUETYPE_H__
#define __CLASS_WX_ANYVALUETYPE_H__
#include <wx/any.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxAnyValueType
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_AnyValueType);

//----------------------------------------------------------------------------
// Object declaration for wxAnyValueType
//----------------------------------------------------------------------------
class Object_wx_AnyValueType : public Object {
protected:
	wxAnyValueType *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_AnyValueType)
public:
	inline Object_wx_AnyValueType(wxAnyValueType *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_AnyValueType(Class *pClass, wxAnyValueType *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_AnyValueType();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxAnyValueType *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxAnyValueType *GetEntity() {
		return static_cast<wxAnyValueType *>(_pEntity);
	}
	inline wxAnyValueType *ReleaseEntity() {
		wxAnyValueType *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxAnyValueType");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
