//----------------------------------------------------------------------------
// wxRichTextCommand
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_RICHTEXTCOMMAND_H__
#define __CLASS_WX_RICHTEXTCOMMAND_H__
#include <wx/richtext/richtextbuffer.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxRichTextCommand
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_RichTextCommand);

//----------------------------------------------------------------------------
// Object declaration for wxRichTextCommand
//----------------------------------------------------------------------------
class Object_wx_RichTextCommand : public Object_wx_Command {
public:
	Gura_DeclareObjectAccessor(wx_RichTextCommand)
public:
	inline Object_wx_RichTextCommand(wxRichTextCommand *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Command(Gura_UserClass(wx_RichTextCommand), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_RichTextCommand(Class *pClass, wxRichTextCommand *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Command(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_RichTextCommand();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxRichTextCommand *GetEntity() {
		return static_cast<wxRichTextCommand *>(_pEntity);
	}
	inline wxRichTextCommand *ReleaseEntity() {
		wxRichTextCommand *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxRichTextCommand");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
