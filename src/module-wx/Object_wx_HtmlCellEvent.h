//----------------------------------------------------------------------------
// wxHtmlCellEvent
// extracted from htwindow.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_HTMLCELLEVENT_H__
#define __OBJECT_WX_HTMLCELLEVENT_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxHtmlCellEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_HtmlCellEvent);

//----------------------------------------------------------------------------
// Object declaration for wxHtmlCellEvent
//----------------------------------------------------------------------------
class Object_wx_HtmlCellEvent : public Object_wx_CommandEvent {
public:
	Gura_DeclareObjectAccessor(wx_HtmlCellEvent)
public:
	inline Object_wx_HtmlCellEvent(wxHtmlCellEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_CommandEvent(Gura_UserClass(wx_HtmlCellEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_HtmlCellEvent(Class *pClass, wxHtmlCellEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_CommandEvent(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_HtmlCellEvent();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxHtmlCellEvent *GetEntity() {
		return dynamic_cast<wxHtmlCellEvent *>(_pEntity);
	}
	inline wxHtmlCellEvent *ReleaseEntity() {
		wxHtmlCellEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxHtmlCellEvent");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
