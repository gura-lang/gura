//----------------------------------------------------------------------------
// wxRichTextTable
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_RICHTEXTTABLE_H__
#define __CLASS_WX_RICHTEXTTABLE_H__
#include <wx/richtext/richtextbuffer.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxRichTextTable
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_RichTextTable);

//----------------------------------------------------------------------------
// Object declaration for wxRichTextTable
//----------------------------------------------------------------------------
class Object_wx_RichTextTable : public Object_wx_RichTextBox {
public:
	Gura_DeclareObjectAccessor(wx_RichTextTable)
public:
	inline Object_wx_RichTextTable(wxRichTextTable *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_RichTextBox(Gura_UserClass(wx_RichTextTable), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_RichTextTable(Class *pClass, wxRichTextTable *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_RichTextBox(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_RichTextTable();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxRichTextTable *GetEntity() {
		return static_cast<wxRichTextTable *>(_pEntity);
	}
	inline wxRichTextTable *ReleaseEntity() {
		wxRichTextTable *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxRichTextTable");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
