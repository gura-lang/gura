//----------------------------------------------------------------------------
// wxSVGBitmapHandler
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_SVGBITMAPHANDLER_H__
#define __CLASS_WX_SVGBITMAPHANDLER_H__
#include <wx/dcsvg.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxSVGBitmapHandler
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_SVGBitmapHandler);

//----------------------------------------------------------------------------
// Object declaration for wxSVGBitmapHandler
//----------------------------------------------------------------------------
class Object_wx_SVGBitmapHandler : public Object {
protected:
	wxSVGBitmapHandler *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_SVGBitmapHandler)
public:
	inline Object_wx_SVGBitmapHandler(wxSVGBitmapHandler *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_SVGBitmapHandler(Class *pClass, wxSVGBitmapHandler *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_SVGBitmapHandler();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxSVGBitmapHandler *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxSVGBitmapHandler *GetEntity() {
		return static_cast<wxSVGBitmapHandler *>(_pEntity);
	}
	inline wxSVGBitmapHandler *ReleaseEntity() {
		wxSVGBitmapHandler *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxSVGBitmapHandler");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
