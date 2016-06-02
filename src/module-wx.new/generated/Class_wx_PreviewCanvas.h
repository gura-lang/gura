//----------------------------------------------------------------------------
// wxPreviewCanvas
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_PREVIEWCANVAS_H__
#define __CLASS_WX_PREVIEWCANVAS_H__
#include <wx/print.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxPreviewCanvas
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_PreviewCanvas);

//----------------------------------------------------------------------------
// Object declaration for wxPreviewCanvas
//----------------------------------------------------------------------------
class Object_wx_PreviewCanvas : public Object {
protected:
	wxPreviewCanvas *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_PreviewCanvas)
public:
	inline Object_wx_PreviewCanvas(wxPreviewCanvas *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_PreviewCanvas(Class *pClass, wxPreviewCanvas *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_PreviewCanvas();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxPreviewCanvas *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxPreviewCanvas *GetEntity() {
		return static_cast<wxPreviewCanvas *>(_pEntity);
	}
	inline wxPreviewCanvas *ReleaseEntity() {
		wxPreviewCanvas *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxPreviewCanvas");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
