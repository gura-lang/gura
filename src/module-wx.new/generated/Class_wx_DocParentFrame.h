//----------------------------------------------------------------------------
// wxDocParentFrame
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_DOCPARENTFRAME_H__
#define __CLASS_WX_DOCPARENTFRAME_H__
#include <wx/docview.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxDocParentFrame
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_DocParentFrame);

//----------------------------------------------------------------------------
// Object declaration for wxDocParentFrame
//----------------------------------------------------------------------------
class Object_wx_DocParentFrame : public Object_wx_Frame {
public:
	Gura_DeclareObjectAccessor(wx_DocParentFrame)
public:
	inline Object_wx_DocParentFrame(wxDocParentFrame *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Frame(Gura_UserClass(wx_DocParentFrame), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_DocParentFrame(Class *pClass, wxDocParentFrame *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Frame(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_DocParentFrame();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxDocParentFrame *GetEntity() {
		return static_cast<wxDocParentFrame *>(_pEntity);
	}
	inline wxDocParentFrame *ReleaseEntity() {
		wxDocParentFrame *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxDocParentFrame");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
