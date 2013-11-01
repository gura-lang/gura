//----------------------------------------------------------------------------
// wxRichTextStyleDefinition
// extracted from richtextstyledefinition.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_RICHTEXTSTYLEDEFINITION_H__
#define __OBJECT_WX_RICHTEXTSTYLEDEFINITION_H__

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
		return dynamic_cast<wxRichTextStyleDefinition *>(_pEntity);
	}
	inline wxRichTextStyleDefinition *ReleaseEntity() {
		wxRichTextStyleDefinition *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxRichTextStyleDefinition");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
