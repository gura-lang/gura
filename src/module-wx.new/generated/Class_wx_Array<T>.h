//----------------------------------------------------------------------------
// wxArray<T>
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_ARRAY<T>_H__
#define __CLASS_WX_ARRAY<T>_H__
#include <wx/dynarray.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxArray<T>
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_Array<T>);

//----------------------------------------------------------------------------
// Object declaration for wxArray<T>
//----------------------------------------------------------------------------
class Object_wx_Array<T> : public Object {
protected:
	wxArray<T> *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_Array<T>)
public:
	inline Object_wx_Array<T>(wxArray<T> *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_Array<T>(Class *pClass, wxArray<T> *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_Array<T>();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxArray<T> *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxArray<T> *GetEntity() {
		return static_cast<wxArray<T> *>(_pEntity);
	}
	inline wxArray<T> *ReleaseEntity() {
		wxArray<T> *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxArray<T>");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
