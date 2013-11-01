//----------------------------------------------------------------------------
// wxPreviewCanvas
// extracted from prevwin.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_PREVIEWCANVAS_H__
#define __CLASS_WX_PREVIEWCANVAS_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxPreviewCanvas
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_PreviewCanvas);

//----------------------------------------------------------------------------
// Object declaration for wxPreviewCanvas
//----------------------------------------------------------------------------
class Object_wx_PreviewCanvas : public Object_wx_ScrolledWindow {
public:
	Gura_DeclareObjectAccessor(wx_PreviewCanvas)
public:
	inline Object_wx_PreviewCanvas(wxPreviewCanvas *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_ScrolledWindow(Gura_UserClass(wx_PreviewCanvas), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_PreviewCanvas(Class *pClass, wxPreviewCanvas *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_ScrolledWindow(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_PreviewCanvas();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxPreviewCanvas *GetEntity() {
		return dynamic_cast<wxPreviewCanvas *>(_pEntity);
	}
	inline wxPreviewCanvas *ReleaseEntity() {
		wxPreviewCanvas *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxPreviewCanvas");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
