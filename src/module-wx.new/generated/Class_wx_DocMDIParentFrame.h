//----------------------------------------------------------------------------
// wxDocMDIParentFrame
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_DOCMDIPARENTFRAME_H__
#define __CLASS_WX_DOCMDIPARENTFRAME_H__
#include <wx/docmdi.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxDocMDIParentFrame
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_DocMDIParentFrame);

//----------------------------------------------------------------------------
// Object declaration for wxDocMDIParentFrame
//----------------------------------------------------------------------------
class Object_wx_DocMDIParentFrame : public Object_wx_MDIParentFrame {
public:
	Gura_DeclareObjectAccessor(wx_DocMDIParentFrame)
public:
	inline Object_wx_DocMDIParentFrame(wxDocMDIParentFrame *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_MDIParentFrame(Gura_UserClass(wx_DocMDIParentFrame), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_DocMDIParentFrame(Class *pClass, wxDocMDIParentFrame *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_MDIParentFrame(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_DocMDIParentFrame();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxDocMDIParentFrame *GetEntity() {
		return static_cast<wxDocMDIParentFrame *>(_pEntity);
	}
	inline wxDocMDIParentFrame *ReleaseEntity() {
		wxDocMDIParentFrame *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxDocMDIParentFrame");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
