//----------------------------------------------------------------------------
// wxRichTextFieldTypeStandard
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_RICHTEXTFIELDTYPESTANDARD_H__
#define __CLASS_WX_RICHTEXTFIELDTYPESTANDARD_H__
#include <wx/richtext/richtextbuffer.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxRichTextFieldTypeStandard
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_RichTextFieldTypeStandard);

//----------------------------------------------------------------------------
// Object declaration for wxRichTextFieldTypeStandard
//----------------------------------------------------------------------------
class Object_wx_RichTextFieldTypeStandard : public Object_wx_RichTextFieldType {
public:
	Gura_DeclareObjectAccessor(wx_RichTextFieldTypeStandard)
public:
	inline Object_wx_RichTextFieldTypeStandard(wxRichTextFieldTypeStandard *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_RichTextFieldType(Gura_UserClass(wx_RichTextFieldTypeStandard), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_RichTextFieldTypeStandard(Class *pClass, wxRichTextFieldTypeStandard *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_RichTextFieldType(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_RichTextFieldTypeStandard();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxRichTextFieldTypeStandard *GetEntity() {
		return static_cast<wxRichTextFieldTypeStandard *>(_pEntity);
	}
	inline wxRichTextFieldTypeStandard *ReleaseEntity() {
		wxRichTextFieldTypeStandard *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxRichTextFieldTypeStandard");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
