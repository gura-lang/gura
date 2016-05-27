//----------------------------------------------------------------------------
// wxRect2DDouble
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_RECT2DDOUBLE_H__
#define __CLASS_WX_RECT2DDOUBLE_H__
#include <wx/geometry.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxRect2DDouble
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_Rect2DDouble);

//----------------------------------------------------------------------------
// Object declaration for wxRect2DDouble
//----------------------------------------------------------------------------
class Object_wx_Rect2DDouble : public Object {
protected:
	wxRect2DDouble *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_Rect2DDouble)
public:
	inline Object_wx_Rect2DDouble(wxRect2DDouble *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_Rect2DDouble(Class *pClass, wxRect2DDouble *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_Rect2DDouble();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxRect2DDouble *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxRect2DDouble *GetEntity() {
		return static_cast<wxRect2DDouble *>(_pEntity);
	}
	inline wxRect2DDouble *ReleaseEntity() {
		wxRect2DDouble *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxRect2DDouble");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
