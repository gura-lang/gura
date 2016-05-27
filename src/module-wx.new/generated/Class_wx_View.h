//----------------------------------------------------------------------------
// wxView
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_VIEW_H__
#define __CLASS_WX_VIEW_H__
#include <wx/docview.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxView
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_View);

//----------------------------------------------------------------------------
// Object declaration for wxView
//----------------------------------------------------------------------------
class Object_wx_View : public Object_wx_EvtHandler {
public:
	Gura_DeclareObjectAccessor(wx_View)
public:
	inline Object_wx_View(wxView *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_EvtHandler(Gura_UserClass(wx_View), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_View(Class *pClass, wxView *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_EvtHandler(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_View();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxView *GetEntity() {
		return static_cast<wxView *>(_pEntity);
	}
	inline wxView *ReleaseEntity() {
		wxView *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxView");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
