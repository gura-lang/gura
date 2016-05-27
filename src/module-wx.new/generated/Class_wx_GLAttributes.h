//----------------------------------------------------------------------------
// wxGLAttributes
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_GLATTRIBUTES_H__
#define __CLASS_WX_GLATTRIBUTES_H__
#include <wx/glcanvas.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxGLAttributes
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_GLAttributes);

//----------------------------------------------------------------------------
// Object declaration for wxGLAttributes
//----------------------------------------------------------------------------
class Object_wx_GLAttributes : public Object_wx_GLAttribsBase {
public:
	Gura_DeclareObjectAccessor(wx_GLAttributes)
public:
	inline Object_wx_GLAttributes(wxGLAttributes *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_GLAttribsBase(Gura_UserClass(wx_GLAttributes), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_GLAttributes(Class *pClass, wxGLAttributes *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_GLAttribsBase(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_GLAttributes();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxGLAttributes *GetEntity() {
		return static_cast<wxGLAttributes *>(_pEntity);
	}
	inline wxGLAttributes *ReleaseEntity() {
		wxGLAttributes *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxGLAttributes");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
