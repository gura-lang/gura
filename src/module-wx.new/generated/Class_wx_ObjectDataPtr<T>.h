//----------------------------------------------------------------------------
// wxObjectDataPtr<T>
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_OBJECTDATAPTR<T>_H__
#define __CLASS_WX_OBJECTDATAPTR<T>_H__
#include <wx/object.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxObjectDataPtr<T>
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_ObjectDataPtr<T>);

//----------------------------------------------------------------------------
// Object declaration for wxObjectDataPtr<T>
//----------------------------------------------------------------------------
class Object_wx_ObjectDataPtr<T> : public Object {
protected:
	wxObjectDataPtr<T> *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_ObjectDataPtr<T>)
public:
	inline Object_wx_ObjectDataPtr<T>(wxObjectDataPtr<T> *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_ObjectDataPtr<T>(Class *pClass, wxObjectDataPtr<T> *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_ObjectDataPtr<T>();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxObjectDataPtr<T> *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxObjectDataPtr<T> *GetEntity() {
		return static_cast<wxObjectDataPtr<T> *>(_pEntity);
	}
	inline wxObjectDataPtr<T> *ReleaseEntity() {
		wxObjectDataPtr<T> *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxObjectDataPtr<T>");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
