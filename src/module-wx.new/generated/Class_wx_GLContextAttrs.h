//----------------------------------------------------------------------------
// wxGLContextAttrs
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_GLCONTEXTATTRS_H__
#define __CLASS_WX_GLCONTEXTATTRS_H__
#include <wx/glcanvas.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxGLContextAttrs
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_GLContextAttrs);

//----------------------------------------------------------------------------
// Object declaration for wxGLContextAttrs
//----------------------------------------------------------------------------
class Object_wx_GLContextAttrs : public Object_wx_GLAttribsBase {
public:
	Gura_DeclareObjectAccessor(wx_GLContextAttrs)
public:
	inline Object_wx_GLContextAttrs(wxGLContextAttrs *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_GLAttribsBase(Gura_UserClass(wx_GLContextAttrs), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_GLContextAttrs(Class *pClass, wxGLContextAttrs *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_GLAttribsBase(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_GLContextAttrs();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxGLContextAttrs *GetEntity() {
		return static_cast<wxGLContextAttrs *>(_pEntity);
	}
	inline wxGLContextAttrs *ReleaseEntity() {
		wxGLContextAttrs *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxGLContextAttrs");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
