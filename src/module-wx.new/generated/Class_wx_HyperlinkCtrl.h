//----------------------------------------------------------------------------
// wxHyperlinkCtrl
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_HYPERLINKCTRL_H__
#define __CLASS_WX_HYPERLINKCTRL_H__
#include <wx/hyperlink.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxHyperlinkCtrl
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_HyperlinkCtrl);

//----------------------------------------------------------------------------
// Object declaration for wxHyperlinkCtrl
//----------------------------------------------------------------------------
class Object_wx_HyperlinkCtrl : public Object_wx_Control {
public:
	Gura_DeclareObjectAccessor(wx_HyperlinkCtrl)
public:
	inline Object_wx_HyperlinkCtrl(wxHyperlinkCtrl *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(Gura_UserClass(wx_HyperlinkCtrl), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_HyperlinkCtrl(Class *pClass, wxHyperlinkCtrl *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_HyperlinkCtrl();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxHyperlinkCtrl *GetEntity() {
		return static_cast<wxHyperlinkCtrl *>(_pEntity);
	}
	inline wxHyperlinkCtrl *ReleaseEntity() {
		wxHyperlinkCtrl *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxHyperlinkCtrl");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
