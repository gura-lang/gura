//----------------------------------------------------------------------------
// wxHyperlinkCtrl
// extracted from hyperlink.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_HYPERLINKCTRL_H__
#define __OBJECT_WX_HYPERLINKCTRL_H__

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
		return dynamic_cast<wxHyperlinkCtrl *>(_pEntity);
	}
	inline wxHyperlinkCtrl *ReleaseEntity() {
		wxHyperlinkCtrl *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxHyperlinkCtrl");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
