//----------------------------------------------------------------------------
// wxRichTextCompositeObject
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_RICHTEXTCOMPOSITEOBJECT_H__
#define __CLASS_WX_RICHTEXTCOMPOSITEOBJECT_H__
#include <wx/richtext/richtextbuffer.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxRichTextCompositeObject
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_RichTextCompositeObject);

//----------------------------------------------------------------------------
// Object declaration for wxRichTextCompositeObject
//----------------------------------------------------------------------------
class Object_wx_RichTextCompositeObject : public Object_wx_RichTextObject {
public:
	Gura_DeclareObjectAccessor(wx_RichTextCompositeObject)
public:
	inline Object_wx_RichTextCompositeObject(wxRichTextCompositeObject *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_RichTextObject(Gura_UserClass(wx_RichTextCompositeObject), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_RichTextCompositeObject(Class *pClass, wxRichTextCompositeObject *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_RichTextObject(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_RichTextCompositeObject();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxRichTextCompositeObject *GetEntity() {
		return static_cast<wxRichTextCompositeObject *>(_pEntity);
	}
	inline wxRichTextCompositeObject *ReleaseEntity() {
		wxRichTextCompositeObject *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxRichTextCompositeObject");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
