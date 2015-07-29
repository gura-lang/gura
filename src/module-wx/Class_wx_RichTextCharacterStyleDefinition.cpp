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
	//Gura::Signal *_pSig;
	Object_wx_RichTextCharacterStyleDefinition *_pObj;
public:
	inline wx_RichTextCharacterStyleDefinition(const wxString& name) : wxRichTextCharacterStyleDefinition(name), _pObj(nullptr) {}
	~wx_RichTextCharacterStyleDefinition();
	inline void AssocWithGura(Object_wx_RichTextCharacterStyleDefinition *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_RichTextCharacterStyleDefinition::~wx_RichTextCharacterStyleDefinition()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_RichTextCharacterStyleDefinition::GuraObjectDeleted()
{
	_pObj = nullptr;
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
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxString name = wxEmptyString;
	if (args.IsValid(0)) name = wxString::FromUTF8(args.GetString(0));
	wx_RichTextCharacterStyleDefinition *pEntity = new wx_RichTextCharacterStyleDefinition(name);
	Object_wx_RichTextCharacterStyleDefinition *pObj = Object_wx_RichTextCharacterStyleDefinition::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_RichTextCharacterStyleDefinition(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

//----------------------------------------------------------------------------
// Object implementation for wxRichTextCharacterStyleDefinition
//----------------------------------------------------------------------------
Object_wx_RichTextCharacterStyleDefinition::~Object_wx_RichTextCharacterStyleDefinition()
{
}

Object *Object_wx_RichTextCharacterStyleDefinition::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextCharacterStyleDefinition::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextCharacterStyleDefinition:");
	if (GetEntity() == nullptr) {
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
	return new Object_wx_RichTextCharacterStyleDefinition((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
