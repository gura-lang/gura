//----------------------------------------------------------------------------
// wxGLContext
// extracted from glcontext.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_GLCONTEXT_H__
#define __OBJECT_WX_GLCONTEXT_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxGLContext
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_GLContext);

//----------------------------------------------------------------------------
// Object declaration for wxGLContext
//----------------------------------------------------------------------------
class Object_wx_GLContext : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_GLContext)
public:
	inline Object_wx_GLContext(wxGLContext *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_GLContext), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_GLContext(Class *pClass, wxGLContext *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_GLContext();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxGLContext *GetEntity() {
		return dynamic_cast<wxGLContext *>(_pEntity);
	}
	inline wxGLContext *ReleaseEntity() {
		wxGLContext *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxGLContext");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
