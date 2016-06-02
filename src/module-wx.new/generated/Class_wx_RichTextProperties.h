//----------------------------------------------------------------------------
// wxRichTextProperties
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_RICHTEXTPROPERTIES_H__
#define __CLASS_WX_RICHTEXTPROPERTIES_H__
#include <wx/richtext/richtextbuffer.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxRichTextProperties
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_RichTextProperties);

//----------------------------------------------------------------------------
// Object declaration for wxRichTextProperties
//----------------------------------------------------------------------------
class Object_wx_RichTextProperties : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_RichTextProperties)
public:
	inline Object_wx_RichTextProperties(wxRichTextProperties *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_RichTextProperties), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_RichTextProperties(Class *pClass, wxRichTextProperties *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_RichTextProperties();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxRichTextProperties *GetEntity() {
		return static_cast<wxRichTextProperties *>(_pEntity);
	}
	inline wxRichTextProperties *ReleaseEntity() {
		wxRichTextProperties *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxRichTextProperties");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
