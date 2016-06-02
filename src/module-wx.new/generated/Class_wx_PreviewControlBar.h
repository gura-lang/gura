//----------------------------------------------------------------------------
// wxPreviewControlBar
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_PREVIEWCONTROLBAR_H__
#define __CLASS_WX_PREVIEWCONTROLBAR_H__
#include <wx/print.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxPreviewControlBar
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_PreviewControlBar);

//----------------------------------------------------------------------------
// Object declaration for wxPreviewControlBar
//----------------------------------------------------------------------------
class Object_wx_PreviewControlBar : public Object_wx_Panel {
public:
	Gura_DeclareObjectAccessor(wx_PreviewControlBar)
public:
	inline Object_wx_PreviewControlBar(wxPreviewControlBar *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Panel(Gura_UserClass(wx_PreviewControlBar), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_PreviewControlBar(Class *pClass, wxPreviewControlBar *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Panel(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_PreviewControlBar();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxPreviewControlBar *GetEntity() {
		return static_cast<wxPreviewControlBar *>(_pEntity);
	}
	inline wxPreviewControlBar *ReleaseEntity() {
		wxPreviewControlBar *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxPreviewControlBar");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
