//----------------------------------------------------------------------------
// wxGraphicsGradientStop
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_GRAPHICSGRADIENTSTOP_H__
#define __CLASS_WX_GRAPHICSGRADIENTSTOP_H__
#include <wx/graphics.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxGraphicsGradientStop
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_GraphicsGradientStop);

//----------------------------------------------------------------------------
// Object declaration for wxGraphicsGradientStop
//----------------------------------------------------------------------------
class Object_wx_GraphicsGradientStop : public Object {
protected:
	wxGraphicsGradientStop *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_GraphicsGradientStop)
public:
	inline Object_wx_GraphicsGradientStop(wxGraphicsGradientStop *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_GraphicsGradientStop(Class *pClass, wxGraphicsGradientStop *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_GraphicsGradientStop();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxGraphicsGradientStop *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxGraphicsGradientStop *GetEntity() {
		return static_cast<wxGraphicsGradientStop *>(_pEntity);
	}
	inline wxGraphicsGradientStop *ReleaseEntity() {
		wxGraphicsGradientStop *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxGraphicsGradientStop");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
