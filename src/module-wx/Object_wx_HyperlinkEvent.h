//----------------------------------------------------------------------------
// wxHyperlinkEvent
// extracted from hyperlink.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_HYPERLINKEVENT_H__
#define __OBJECT_WX_HYPERLINKEVENT_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxHyperlinkEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_HyperlinkEvent);

//----------------------------------------------------------------------------
// Object declaration for wxHyperlinkEvent
//----------------------------------------------------------------------------
class Object_wx_HyperlinkEvent : public Object_wx_CommandEvent {
public:
	Gura_DeclareObjectAccessor(wx_HyperlinkEvent)
public:
	inline Object_wx_HyperlinkEvent(wxHyperlinkEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_CommandEvent(Gura_UserClass(wx_HyperlinkEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_HyperlinkEvent(Class *pClass, wxHyperlinkEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_CommandEvent(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_HyperlinkEvent();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxHyperlinkEvent *GetEntity() {
		return dynamic_cast<wxHyperlinkEvent *>(_pEntity);
	}
	inline wxHyperlinkEvent *ReleaseEntity() {
		wxHyperlinkEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxHyperlinkEvent");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
