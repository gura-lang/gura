//----------------------------------------------------------------------------
// wxRichTextFormattingDialogFactory
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_RICHTEXTFORMATTINGDIALOGFACTORY_H__
#define __CLASS_WX_RICHTEXTFORMATTINGDIALOGFACTORY_H__
#include <wx/richtext/richtextformatdlg.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxRichTextFormattingDialogFactory
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_RichTextFormattingDialogFactory);

//----------------------------------------------------------------------------
// Object declaration for wxRichTextFormattingDialogFactory
//----------------------------------------------------------------------------
class Object_wx_RichTextFormattingDialogFactory : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_RichTextFormattingDialogFactory)
public:
	inline Object_wx_RichTextFormattingDialogFactory(wxRichTextFormattingDialogFactory *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_RichTextFormattingDialogFactory), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_RichTextFormattingDialogFactory(Class *pClass, wxRichTextFormattingDialogFactory *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_RichTextFormattingDialogFactory();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxRichTextFormattingDialogFactory *GetEntity() {
		return static_cast<wxRichTextFormattingDialogFactory *>(_pEntity);
	}
	inline wxRichTextFormattingDialogFactory *ReleaseEntity() {
		wxRichTextFormattingDialogFactory *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxRichTextFormattingDialogFactory");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
