//----------------------------------------------------------------------------
// wxHtmlListBox
// extracted from htmllbox.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_HTMLLISTBOX_H__
#define __OBJECT_WX_HTMLLISTBOX_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxHtmlListBox
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_HtmlListBox);

//----------------------------------------------------------------------------
// Object declaration for wxHtmlListBox
//----------------------------------------------------------------------------
class Object_wx_HtmlListBox : public Object_wx_VListBox {
public:
	Gura_DeclareObjectAccessor(wx_HtmlListBox)
public:
	inline Object_wx_HtmlListBox(wxHtmlListBox *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_VListBox(Gura_UserClass(wx_HtmlListBox), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_HtmlListBox(Class *pClass, wxHtmlListBox *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_VListBox(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_HtmlListBox();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxHtmlListBox *GetEntity() {
		return dynamic_cast<wxHtmlListBox *>(_pEntity);
	}
	inline wxHtmlListBox *ReleaseEntity() {
		wxHtmlListBox *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxHtmlListBox");
		return true;
	}
public:
	static void OnModuleEntry(Environment &env, Signal sig);
};

}}

#endif
