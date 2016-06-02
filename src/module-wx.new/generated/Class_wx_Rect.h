//----------------------------------------------------------------------------
// wxRect
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_RECT_H__
#define __CLASS_WX_RECT_H__
#include <wx/gdicmn.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxRect
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_Rect);

//----------------------------------------------------------------------------
// Object declaration for wxRect
//----------------------------------------------------------------------------
class Object_wx_Rect : public Object {
protected:
	wxRect *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_Rect)
public:
	inline Object_wx_Rect(wxRect *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_Rect(Class *pClass, wxRect *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_Rect();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxRect *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxRect *GetEntity() {
		return static_cast<wxRect *>(_pEntity);
	}
	inline wxRect *ReleaseEntity() {
		wxRect *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxRect");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
