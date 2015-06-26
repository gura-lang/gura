//----------------------------------------------------------------------------
// wxGLCanvas
// extracted from glcanvas.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_GLCANVAS_H__
#define __CLASS_WX_GLCANVAS_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxGLCanvas
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_GLCanvas);

//----------------------------------------------------------------------------
// Object declaration for wxGLCanvas
//----------------------------------------------------------------------------
class Object_wx_GLCanvas : public Object_wx_Window {
public:
	Gura_DeclareObjectAccessor(wx_GLCanvas)
public:
	inline Object_wx_GLCanvas(wxGLCanvas *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Window(Gura_UserClass(wx_GLCanvas), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_GLCanvas(Class *pClass, wxGLCanvas *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Window(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_GLCanvas();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxGLCanvas *GetEntity() {
		return dynamic_cast<wxGLCanvas *>(_pEntity);
	}
	inline wxGLCanvas *ReleaseEntity() {
		wxGLCanvas *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxGLCanvas");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
