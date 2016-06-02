//----------------------------------------------------------------------------
// wxRichTextFieldType
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_RICHTEXTFIELDTYPE_H__
#define __CLASS_WX_RICHTEXTFIELDTYPE_H__
#include <wx/richtext/richtextbuffer.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxRichTextFieldType
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_RichTextFieldType);

//----------------------------------------------------------------------------
// Object declaration for wxRichTextFieldType
//----------------------------------------------------------------------------
class Object_wx_RichTextFieldType : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_RichTextFieldType)
public:
	inline Object_wx_RichTextFieldType(wxRichTextFieldType *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_RichTextFieldType), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_RichTextFieldType(Class *pClass, wxRichTextFieldType *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_RichTextFieldType();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxRichTextFieldType *GetEntity() {
		return static_cast<wxRichTextFieldType *>(_pEntity);
	}
	inline wxRichTextFieldType *ReleaseEntity() {
		wxRichTextFieldType *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxRichTextFieldType");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
