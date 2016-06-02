//----------------------------------------------------------------------------
// wxRichTextAction
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_RICHTEXTACTION_H__
#define __CLASS_WX_RICHTEXTACTION_H__
#include <wx/richtext/richtextbuffer.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxRichTextAction
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_RichTextAction);

//----------------------------------------------------------------------------
// Object declaration for wxRichTextAction
//----------------------------------------------------------------------------
class Object_wx_RichTextAction : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_RichTextAction)
public:
	inline Object_wx_RichTextAction(wxRichTextAction *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_RichTextAction), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_RichTextAction(Class *pClass, wxRichTextAction *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_RichTextAction();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxRichTextAction *GetEntity() {
		return static_cast<wxRichTextAction *>(_pEntity);
	}
	inline wxRichTextAction *ReleaseEntity() {
		wxRichTextAction *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxRichTextAction");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
