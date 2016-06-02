//----------------------------------------------------------------------------
// wxRichTextCell
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_RICHTEXTCELL_H__
#define __CLASS_WX_RICHTEXTCELL_H__
#include <wx/richtext/richtextbuffer.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxRichTextCell
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_RichTextCell);

//----------------------------------------------------------------------------
// Object declaration for wxRichTextCell
//----------------------------------------------------------------------------
class Object_wx_RichTextCell : public Object_wx_RichTextBox {
public:
	Gura_DeclareObjectAccessor(wx_RichTextCell)
public:
	inline Object_wx_RichTextCell(wxRichTextCell *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_RichTextBox(Gura_UserClass(wx_RichTextCell), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_RichTextCell(Class *pClass, wxRichTextCell *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_RichTextBox(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_RichTextCell();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxRichTextCell *GetEntity() {
		return static_cast<wxRichTextCell *>(_pEntity);
	}
	inline wxRichTextCell *ReleaseEntity() {
		wxRichTextCell *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxRichTextCell");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
