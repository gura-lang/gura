//----------------------------------------------------------------------------
// wxHtmlFilter
// extracted from htfilter.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_HTMLFILTER_H__
#define __OBJECT_WX_HTMLFILTER_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxHtmlFilter
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_HtmlFilter);

//----------------------------------------------------------------------------
// Object declaration for wxHtmlFilter
//----------------------------------------------------------------------------
class Object_wx_HtmlFilter : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_HtmlFilter)
public:
	inline Object_wx_HtmlFilter(wxHtmlFilter *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_HtmlFilter), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_HtmlFilter(Class *pClass, wxHtmlFilter *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_HtmlFilter();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxHtmlFilter *GetEntity() {
		return dynamic_cast<wxHtmlFilter *>(_pEntity);
	}
	inline wxHtmlFilter *ReleaseEntity() {
		wxHtmlFilter *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxHtmlFilter");
		return true;
	}
public:
	static void DoAssignConstructor(Environment &env, Signal sig);
};

}}

#endif
