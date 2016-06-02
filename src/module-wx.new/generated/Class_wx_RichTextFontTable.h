//----------------------------------------------------------------------------
// wxRichTextFontTable
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_RICHTEXTFONTTABLE_H__
#define __CLASS_WX_RICHTEXTFONTTABLE_H__
#include <wx/richtext/richtextbuffer.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxRichTextFontTable
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_RichTextFontTable);

//----------------------------------------------------------------------------
// Object declaration for wxRichTextFontTable
//----------------------------------------------------------------------------
class Object_wx_RichTextFontTable : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_RichTextFontTable)
public:
	inline Object_wx_RichTextFontTable(wxRichTextFontTable *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_RichTextFontTable), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_RichTextFontTable(Class *pClass, wxRichTextFontTable *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_RichTextFontTable();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxRichTextFontTable *GetEntity() {
		return static_cast<wxRichTextFontTable *>(_pEntity);
	}
	inline wxRichTextFontTable *ReleaseEntity() {
		wxRichTextFontTable *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxRichTextFontTable");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
