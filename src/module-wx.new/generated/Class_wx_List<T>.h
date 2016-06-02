//----------------------------------------------------------------------------
// wxList<T>
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_LIST<T>_H__
#define __CLASS_WX_LIST<T>_H__
#include <wx/list.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxList<T>
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_List<T>);

//----------------------------------------------------------------------------
// Object declaration for wxList<T>
//----------------------------------------------------------------------------
class Object_wx_List<T> : public Object {
protected:
	wxList<T> *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_List<T>)
public:
	inline Object_wx_List<T>(wxList<T> *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_List<T>(Class *pClass, wxList<T> *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_List<T>();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxList<T> *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxList<T> *GetEntity() {
		return static_cast<wxList<T> *>(_pEntity);
	}
	inline wxList<T> *ReleaseEntity() {
		wxList<T> *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxList<T>");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
