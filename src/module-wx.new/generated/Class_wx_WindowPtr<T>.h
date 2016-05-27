//----------------------------------------------------------------------------
// wxWindowPtr<T>
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_WINDOWPTR<T>_H__
#define __CLASS_WX_WINDOWPTR<T>_H__
#include <wx/windowptr.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxWindowPtr<T>
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_WindowPtr<T>);

//----------------------------------------------------------------------------
// Object declaration for wxWindowPtr<T>
//----------------------------------------------------------------------------
class Object_wx_WindowPtr<T> : public Object {
protected:
	wxWindowPtr<T> *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_WindowPtr<T>)
public:
	inline Object_wx_WindowPtr<T>(wxWindowPtr<T> *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_WindowPtr<T>(Class *pClass, wxWindowPtr<T> *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_WindowPtr<T>();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxWindowPtr<T> *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxWindowPtr<T> *GetEntity() {
		return static_cast<wxWindowPtr<T> *>(_pEntity);
	}
	inline wxWindowPtr<T> *ReleaseEntity() {
		wxWindowPtr<T> *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxWindowPtr<T>");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
