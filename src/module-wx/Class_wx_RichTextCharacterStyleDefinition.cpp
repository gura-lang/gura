//----------------------------------------------------------------------------
// wxRichTextCharacterStyleDefinition
// extracted from richtextcharacterstyledefinition.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_RichTextCharacterStyleDefinition: public wxRichTextCharacterStyleDefinition, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_RichTextCharacterStyleDefinition *_pObj;
public:
	inline wx_RichTextCharacterStyleDefinition(const wxString& name) : wxRichTextCharacterStyleDefinition(name), _sig(NULL), _pObj(NULL) {}
	~wx_RichTextCharacterStyleDefinition();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_RichTextCharacterStyleDefinition *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_RichTextCharacterStyleDefinition::~wx_RichTextCharacterStyleDefinition()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_RichTextCharacterStyleDefinition::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextCharacterStyleDefinition
//----------------------------------------------------------------------------
Gura_DeclareFunction(RichTextCharacterStyleDefinition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_RichTextCharacterStyleDefinition));
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(RichTextCharacterStyleDefinition)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxString name = wxEmptyString;
	if (args.IsValid(0)) name = wxString::FromUTF8(args.GetString(0));
	wx_RichTextCharacterStyleDefinition *pEntity = new wx_RichTextCharacterStyleDefinition(name);
	Object_wx_RichTextCharacterStyleDefinition *pObj = Object_wx_RichTextCharacterStyleDefinition::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_RichTextCharacterStyleDefinition(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

//----------------------------------------------------------------------------
// Object implementation for wxRichTextCharacterStyleDefinition
//----------------------------------------------------------------------------
Object_wx_RichTextCharacterStyleDefinition::~Object_wx_RichTextCharacterStyleDefinition()
{
}

Object *Object_wx_RichTextCharacterStyleDefinition::Clone() const
{
	return NULL;
}

String Object_wx_RichTextCharacterStyleDefinition::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextCharacterStyleDefinition:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

//----------------------------------------------------------------------------
// Class implementation for wxRichTextCharacterStyleDefinition
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextCharacterStyleDefinition)
{
	Gura_AssignFunction(RichTextCharacterStyleDefinition);
}

Gura_ImplementDescendantCreator(wx_RichTextCharacterStyleDefinition)
{
	return new Object_wx_RichTextCharacterStyleDefinition((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
