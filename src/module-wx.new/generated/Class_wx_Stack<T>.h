//----------------------------------------------------------------------------
// wxStack<T>
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_STACK<T>_H__
#define __CLASS_WX_STACK<T>_H__
#include <wx/stack.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxStack<T>
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_Stack<T>);

//----------------------------------------------------------------------------
// Object declaration for wxStack<T>
//----------------------------------------------------------------------------
class Object_wx_Stack<T> : public Object {
protected:
	wxStack<T> *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_Stack<T>)
public:
	inline Object_wx_Stack<T>(wxStack<T> *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_Stack<T>(Class *pClass, wxStack<T> *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_Stack<T>();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxStack<T> *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxStack<T> *GetEntity() {
		return static_cast<wxStack<T> *>(_pEntity);
	}
	inline wxStack<T> *ReleaseEntity() {
		wxStack<T> *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxStack<T>");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
