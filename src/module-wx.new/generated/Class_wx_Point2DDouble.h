//----------------------------------------------------------------------------
// wxPoint2DDouble
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_POINT2DDOUBLE_H__
#define __CLASS_WX_POINT2DDOUBLE_H__
#include <wx/geometry.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxPoint2DDouble
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_Point2DDouble);

//----------------------------------------------------------------------------
// Object declaration for wxPoint2DDouble
//----------------------------------------------------------------------------
class Object_wx_Point2DDouble : public Object {
protected:
	wxPoint2DDouble *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_Point2DDouble)
public:
	inline Object_wx_Point2DDouble(wxPoint2DDouble *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_Point2DDouble(Class *pClass, wxPoint2DDouble *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_Point2DDouble();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxPoint2DDouble *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxPoint2DDouble *GetEntity() {
		return static_cast<wxPoint2DDouble *>(_pEntity);
	}
	inline wxPoint2DDouble *ReleaseEntity() {
		wxPoint2DDouble *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxPoint2DDouble");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
