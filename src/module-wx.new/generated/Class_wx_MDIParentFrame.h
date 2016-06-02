//----------------------------------------------------------------------------
// wxMDIParentFrame
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_MDIPARENTFRAME_H__
#define __CLASS_WX_MDIPARENTFRAME_H__
#include <wx/mdi.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxMDIParentFrame
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_MDIParentFrame);

//----------------------------------------------------------------------------
// Object declaration for wxMDIParentFrame
//----------------------------------------------------------------------------
class Object_wx_MDIParentFrame : public Object_wx_Frame {
public:
	Gura_DeclareObjectAccessor(wx_MDIParentFrame)
public:
	inline Object_wx_MDIParentFrame(wxMDIParentFrame *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Frame(Gura_UserClass(wx_MDIParentFrame), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_MDIParentFrame(Class *pClass, wxMDIParentFrame *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Frame(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_MDIParentFrame();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxMDIParentFrame *GetEntity() {
		return static_cast<wxMDIParentFrame *>(_pEntity);
	}
	inline wxMDIParentFrame *ReleaseEntity() {
		wxMDIParentFrame *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxMDIParentFrame");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
