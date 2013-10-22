//----------------------------------------------------------------------------
// wxRichTextCharacterStyleDefinition
// extracted from richtextcharacterstyledefinition.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_RICHTEXTCHARACTERSTYLEDEFINITION_H__
#define __OBJECT_WX_RICHTEXTCHARACTERSTYLEDEFINITION_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxRichTextCharacterStyleDefinition
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_RichTextCharacterStyleDefinition);

//----------------------------------------------------------------------------
// Object declaration for wxRichTextCharacterStyleDefinition
//----------------------------------------------------------------------------
class Object_wx_RichTextCharacterStyleDefinition : public Object_wx_RichTextStyleDefinition {
public:
	Gura_DeclareObjectAccessor(wx_RichTextCharacterStyleDefinition)
public:
	inline Object_wx_RichTextCharacterStyleDefinition(wxRichTextCharacterStyleDefinition *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_RichTextStyleDefinition(Gura_UserClass(wx_RichTextCharacterStyleDefinition), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_RichTextCharacterStyleDefinition(Class *pClass, wxRichTextCharacterStyleDefinition *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_RichTextStyleDefinition(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_RichTextCharacterStyleDefinition();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxRichTextCharacterStyleDefinition *GetEntity() {
		return dynamic_cast<wxRichTextCharacterStyleDefinition *>(_pEntity);
	}
	inline wxRichTextCharacterStyleDefinition *ReleaseEntity() {
		wxRichTextCharacterStyleDefinition *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxRichTextCharacterStyleDefinition");
		return true;
	}
};

}}

#endif
