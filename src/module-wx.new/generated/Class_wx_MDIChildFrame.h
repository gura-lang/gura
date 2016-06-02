//----------------------------------------------------------------------------
// wxMDIChildFrame
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_MDICHILDFRAME_H__
#define __CLASS_WX_MDICHILDFRAME_H__
#include <wx/mdi.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxMDIChildFrame
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_MDIChildFrame);

//----------------------------------------------------------------------------
// Object declaration for wxMDIChildFrame
//----------------------------------------------------------------------------
class Object_wx_MDIChildFrame : public Object_wx_Frame {
public:
	Gura_DeclareObjectAccessor(wx_MDIChildFrame)
public:
	inline Object_wx_MDIChildFrame(wxMDIChildFrame *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Frame(Gura_UserClass(wx_MDIChildFrame), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_MDIChildFrame(Class *pClass, wxMDIChildFrame *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Frame(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_MDIChildFrame();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxMDIChildFrame *GetEntity() {
		return static_cast<wxMDIChildFrame *>(_pEntity);
	}
	inline wxMDIChildFrame *ReleaseEntity() {
		wxMDIChildFrame *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxMDIChildFrame");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
