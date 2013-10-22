//----------------------------------------------------------------------------
// wxHtmlHelpFrame
// extracted from hthlpfrm.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_HTMLHELPFRAME_H__
#define __OBJECT_WX_HTMLHELPFRAME_H__

Gura_BeginModule(wx)

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
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxHtmlHelpFrame *GetEntity() {
		return dynamic_cast<wxHtmlHelpFrame *>(_pEntity);
	}
	inline wxHtmlHelpFrame *ReleaseEntity() {
		wxHtmlHelpFrame *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxHtmlHelpFrame");
		return true;
	}
};

}}

#endif
