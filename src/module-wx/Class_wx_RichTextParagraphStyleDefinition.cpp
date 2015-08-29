//----------------------------------------------------------------------------
// wxRichTextParagraphStyleDefinition
// extracted from richtextparagraphstyledefinition.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_RichTextParagraphStyleDefinition: public wxRichTextParagraphStyleDefinition, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_RichTextParagraphStyleDefinition *_pObj;
public:
	inline wx_RichTextParagraphStyleDefinition(const wxString& name) : wxRichTextParagraphStyleDefinition(name), _pObj(nullptr) {}
	~wx_RichTextParagraphStyleDefinition();
	inline void AssocWithGura(Object_wx_RichTextParagraphStyleDefinition *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_RichTextParagraphStyleDefinition::~wx_RichTextParagraphStyleDefinition()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_RichTextParagraphStyleDefinition::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextParagraphStyleDefinition
//----------------------------------------------------------------------------
Gura_DeclareFunction(RichTextParagraphStyleDefinition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_RichTextParagraphStyleDefinition));
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(RichTextParagraphStyleDefinition)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxString name = wxEmptyString;
	if (arg.IsValid(0)) name = wxString::FromUTF8(arg.GetString(0));
	wx_RichTextParagraphStyleDefinition *pEntity = new wx_RichTextParagraphStyleDefinition(name);
	Object_wx_RichTextParagraphStyleDefinition *pObj = Object_wx_RichTextParagraphStyleDefinition::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_RichTextParagraphStyleDefinition(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareMethod(wx_RichTextParagraphStyleDefinition, GetNextStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextParagraphStyleDefinition, GetNextStyle)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextParagraphStyleDefinition *pThis = Object_wx_RichTextParagraphStyleDefinition::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetNextStyle();
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_RichTextParagraphStyleDefinition, SetNextStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphStyleDefinition, SetNextStyle)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextParagraphStyleDefinition *pThis = Object_wx_RichTextParagraphStyleDefinition::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString name = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->SetNextStyle(name);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxRichTextParagraphStyleDefinition
//----------------------------------------------------------------------------
Object_wx_RichTextParagraphStyleDefinition::~Object_wx_RichTextParagraphStyleDefinition()
{
}

Object *Object_wx_RichTextParagraphStyleDefinition::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextParagraphStyleDefinition::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextParagraphStyleDefinition:");
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
// Class implementation for wxRichTextParagraphStyleDefinition
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextParagraphStyleDefinition)
{
	Gura_AssignFunction(RichTextParagraphStyleDefinition);
	Gura_AssignMethod(wx_RichTextParagraphStyleDefinition, GetNextStyle);
	Gura_AssignMethod(wx_RichTextParagraphStyleDefinition, SetNextStyle);
}

Gura_ImplementDescendantCreator(wx_RichTextParagraphStyleDefinition)
{
	return new Object_wx_RichTextParagraphStyleDefinition((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
