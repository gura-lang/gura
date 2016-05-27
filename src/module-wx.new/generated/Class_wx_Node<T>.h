//----------------------------------------------------------------------------
// wxNode<T>
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_NODE<T>_H__
#define __CLASS_WX_NODE<T>_H__
#include <wx/list.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxNode<T>
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_Node<T>);

//----------------------------------------------------------------------------
// Object declaration for wxNode<T>
//----------------------------------------------------------------------------
class Object_wx_Node<T> : public Object {
protected:
	wxNode<T> *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_Node<T>)
public:
	inline Object_wx_Node<T>(wxNode<T> *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_Node<T>(Class *pClass, wxNode<T> *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_Node<T>();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxNode<T> *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxNode<T> *GetEntity() {
		return static_cast<wxNode<T> *>(_pEntity);
	}
	inline wxNode<T> *ReleaseEntity() {
		wxNode<T> *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxNode<T>");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
