//----------------------------------------------------------------------------
// wxRichTextObject
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_RICHTEXTOBJECT_H__
#define __CLASS_WX_RICHTEXTOBJECT_H__
#include <wx/richtext/richtextbuffer.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxRichTextObject
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_RichTextObject);

//----------------------------------------------------------------------------
// Object declaration for wxRichTextObject
//----------------------------------------------------------------------------
class Object_wx_RichTextObject : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_RichTextObject)
public:
	inline Object_wx_RichTextObject(wxRichTextObject *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_RichTextObject), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_RichTextObject(Class *pClass, wxRichTextObject *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_RichTextObject();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxRichTextObject *GetEntity() {
		return static_cast<wxRichTextObject *>(_pEntity);
	}
	inline wxRichTextObject *ReleaseEntity() {
		wxRichTextObject *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxRichTextObject");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
