//----------------------------------------------------------------------------
// wxRichTextStyleListCtrl
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_RICHTEXTSTYLELISTCTRL_H__
#define __CLASS_WX_RICHTEXTSTYLELISTCTRL_H__
#include <wx/richtext/richtextstyles.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxRichTextStyleListCtrl
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_RichTextStyleListCtrl);

//----------------------------------------------------------------------------
// Object declaration for wxRichTextStyleListCtrl
//----------------------------------------------------------------------------
class Object_wx_RichTextStyleListCtrl : public Object_wx_Control {
public:
	Gura_DeclareObjectAccessor(wx_RichTextStyleListCtrl)
public:
	inline Object_wx_RichTextStyleListCtrl(wxRichTextStyleListCtrl *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(Gura_UserClass(wx_RichTextStyleListCtrl), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_RichTextStyleListCtrl(Class *pClass, wxRichTextStyleListCtrl *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_RichTextStyleListCtrl();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxRichTextStyleListCtrl *GetEntity() {
		return static_cast<wxRichTextStyleListCtrl *>(_pEntity);
	}
	inline wxRichTextStyleListCtrl *ReleaseEntity() {
		wxRichTextStyleListCtrl *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxRichTextStyleListCtrl");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
