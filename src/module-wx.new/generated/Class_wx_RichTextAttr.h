//----------------------------------------------------------------------------
// wxRichTextAttr
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_RICHTEXTATTR_H__
#define __CLASS_WX_RICHTEXTATTR_H__
#include <wx/richtext/richtextbuffer.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxRichTextAttr
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_RichTextAttr);

//----------------------------------------------------------------------------
// Object declaration for wxRichTextAttr
//----------------------------------------------------------------------------
class Object_wx_RichTextAttr : public Object_wx_TextAttr {
public:
	Gura_DeclareObjectAccessor(wx_RichTextAttr)
public:
	inline Object_wx_RichTextAttr(wxRichTextAttr *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_TextAttr(Gura_UserClass(wx_RichTextAttr), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_RichTextAttr(Class *pClass, wxRichTextAttr *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_TextAttr(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_RichTextAttr();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxRichTextAttr *GetEntity() {
		return static_cast<wxRichTextAttr *>(_pEntity);
	}
	inline wxRichTextAttr *ReleaseEntity() {
		wxRichTextAttr *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxRichTextAttr");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
