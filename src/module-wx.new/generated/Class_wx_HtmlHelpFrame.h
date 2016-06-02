//----------------------------------------------------------------------------
// wxHtmlHelpFrame
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_HTMLHELPFRAME_H__
#define __CLASS_WX_HTMLHELPFRAME_H__
#include <wx/html/helpfrm.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxHtmlHelpFrame
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_HtmlHelpFrame);

//----------------------------------------------------------------------------
// Object declaration for wxHtmlHelpFrame
//----------------------------------------------------------------------------
class Object_wx_HtmlHelpFrame : public Object_wx_Frame {
public:
	Gura_DeclareObjectAccessor(wx_HtmlHelpFrame)
public:
	inline Object_wx_HtmlHelpFrame(wxHtmlHelpFrame *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Frame(Gura_UserClass(wx_HtmlHelpFrame), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_HtmlHelpFrame(Class *pClass, wxHtmlHelpFrame *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Frame(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_HtmlHelpFrame();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxHtmlHelpFrame *GetEntity() {
		return static_cast<wxHtmlHelpFrame *>(_pEntity);
	}
	inline wxHtmlHelpFrame *ReleaseEntity() {
		wxHtmlHelpFrame *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxHtmlHelpFrame");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
