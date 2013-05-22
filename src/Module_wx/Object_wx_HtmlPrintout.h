//----------------------------------------------------------------------------
// wxHtmlPrintout
// extracted from htprint.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_HTMLPRINTOUT_H__
#define __OBJECT_WX_HTMLPRINTOUT_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxHtmlPrintout
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_HtmlPrintout);

//----------------------------------------------------------------------------
// Object declaration for wxHtmlPrintout
//----------------------------------------------------------------------------
class Object_wx_HtmlPrintout : public Object_wx_Printout {
public:
	Gura_DeclareObjectAccessor(wx_HtmlPrintout)
public:
	inline Object_wx_HtmlPrintout(wxHtmlPrintout *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Printout(Gura_UserClass(wx_HtmlPrintout), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_HtmlPrintout(Class *pClass, wxHtmlPrintout *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Printout(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_HtmlPrintout();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxHtmlPrintout *GetEntity() {
		return dynamic_cast<wxHtmlPrintout *>(_pEntity);
	}
	inline wxHtmlPrintout *ReleaseEntity() {
		wxHtmlPrintout *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxHtmlPrintout");
		return true;
	}
public:
	static void DoAssignConstructor(Environment &env, Signal sig);
};

}}

#endif
