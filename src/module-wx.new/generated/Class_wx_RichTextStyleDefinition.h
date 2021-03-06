//----------------------------------------------------------------------------
// wxRichTextStyleDefinition
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_RICHTEXTSTYLEDEFINITION_H__
#define __CLASS_WX_RICHTEXTSTYLEDEFINITION_H__
#include <wx/richtext/richtextstyles.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxRichTextStyleDefinition
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_RichTextStyleDefinition);

//----------------------------------------------------------------------------
// Object declaration for wxRichTextStyleDefinition
//----------------------------------------------------------------------------
class Object_wx_RichTextStyleDefinition : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_RichTextStyleDefinition)
public:
	inline Object_wx_RichTextStyleDefinition(wxRichTextStyleDefinition *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_RichTextStyleDefinition), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_RichTextStyleDefinition(Class *pClass, wxRichTextStyleDefinition *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_RichTextStyleDefinition();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxRichTextStyleDefinition *GetEntity() {
		return static_cast<wxRichTextStyleDefinition *>(_pEntity);
	}
	inline wxRichTextStyleDefinition *ReleaseEntity() {
		wxRichTextStyleDefinition *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxRichTextStyleDefinition");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
