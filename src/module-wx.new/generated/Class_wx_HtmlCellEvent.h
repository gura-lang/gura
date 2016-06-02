//----------------------------------------------------------------------------
// wxHtmlCellEvent
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_HTMLCELLEVENT_H__
#define __CLASS_WX_HTMLCELLEVENT_H__
#include <wx/html/htmlwin.h>

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
	virtual String ToString(bool exprFlag);
	inline wxHtmlCellEvent *GetEntity() {
		return static_cast<wxHtmlCellEvent *>(_pEntity);
	}
	inline wxHtmlCellEvent *ReleaseEntity() {
		wxHtmlCellEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxHtmlCellEvent");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
