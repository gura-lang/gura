//----------------------------------------------------------------------------
// wxSimpleHtmlListBox
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_SIMPLEHTMLLISTBOX_H__
#define __CLASS_WX_SIMPLEHTMLLISTBOX_H__
#include <wx/htmllbox.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxSimpleHtmlListBox
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_SimpleHtmlListBox);

//----------------------------------------------------------------------------
// Object declaration for wxSimpleHtmlListBox
//----------------------------------------------------------------------------
class Object_wx_SimpleHtmlListBox : public Object_wx_HtmlListBox {
public:
	Gura_DeclareObjectAccessor(wx_SimpleHtmlListBox)
public:
	inline Object_wx_SimpleHtmlListBox(wxSimpleHtmlListBox *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_HtmlListBox(Gura_UserClass(wx_SimpleHtmlListBox), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_SimpleHtmlListBox(Class *pClass, wxSimpleHtmlListBox *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_HtmlListBox(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_SimpleHtmlListBox();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxSimpleHtmlListBox *GetEntity() {
		return static_cast<wxSimpleHtmlListBox *>(_pEntity);
	}
	inline wxSimpleHtmlListBox *ReleaseEntity() {
		wxSimpleHtmlListBox *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxSimpleHtmlListBox");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
