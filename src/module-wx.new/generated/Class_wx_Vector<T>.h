//----------------------------------------------------------------------------
// wxVector<T>
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_VECTOR<T>_H__
#define __CLASS_WX_VECTOR<T>_H__
#include <wx/vector.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxVector<T>
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_Vector<T>);

//----------------------------------------------------------------------------
// Object declaration for wxVector<T>
//----------------------------------------------------------------------------
class Object_wx_Vector<T> : public Object {
protected:
	wxVector<T> *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_Vector<T>)
public:
	inline Object_wx_Vector<T>(wxVector<T> *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_Vector<T>(Class *pClass, wxVector<T> *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_Vector<T>();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxVector<T> *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxVector<T> *GetEntity() {
		return static_cast<wxVector<T> *>(_pEntity);
	}
	inline wxVector<T> *ReleaseEntity() {
		wxVector<T> *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxVector<T>");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
