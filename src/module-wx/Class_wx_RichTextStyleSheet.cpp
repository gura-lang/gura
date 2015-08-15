//----------------------------------------------------------------------------
// wxRichTextStyleSheet
// extracted from richtextstylesheet.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_RichTextStyleSheet: public wxRichTextStyleSheet, public GuraObjectObserver {
private:
	Object_wx_RichTextStyleSheet *_pObj;
public:
	inline wx_RichTextStyleSheet(const wxRichTextStyleSheet& sheet) : wxRichTextStyleSheet(sheet), _pObj(nullptr) {}
	inline wx_RichTextStyleSheet() : wxRichTextStyleSheet(), _pObj(nullptr) {}
	~wx_RichTextStyleSheet();
	inline void AssocWithGura(Object_wx_RichTextStyleSheet *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_RichTextStyleSheet::~wx_RichTextStyleSheet()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_RichTextStyleSheet::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextStyleSheet
//----------------------------------------------------------------------------
Gura_DeclareFunction(RichTextStyleSheet)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_RichTextStyleSheet));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(RichTextStyleSheet)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_RichTextStyleSheet *pEntity = new wx_RichTextStyleSheet();
	Object_wx_RichTextStyleSheet *pObj = Object_wx_RichTextStyleSheet::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_RichTextStyleSheet(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareMethod(wx_RichTextStyleSheet, AddCharacterStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "def", VTYPE_wx_RichTextCharacterStyleDefinition, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextStyleSheet, AddCharacterStyle)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextStyleSheet *pThis = Object_wx_RichTextStyleSheet::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxRichTextCharacterStyleDefinition *def = Object_wx_RichTextCharacterStyleDefinition::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->AddCharacterStyle(def);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextStyleSheet, AddListStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "def", VTYPE_wx_RichTextListStyleDefinition, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextStyleSheet, AddListStyle)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextStyleSheet *pThis = Object_wx_RichTextStyleSheet::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxRichTextListStyleDefinition *def = Object_wx_RichTextListStyleDefinition::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->AddListStyle(def);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextStyleSheet, AddParagraphStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "def", VTYPE_wx_RichTextParagraphStyleDefinition, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextStyleSheet, AddParagraphStyle)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextStyleSheet *pThis = Object_wx_RichTextStyleSheet::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxRichTextParagraphStyleDefinition *def = Object_wx_RichTextParagraphStyleDefinition::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->AddParagraphStyle(def);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextStyleSheet, AddStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "def", VTYPE_wx_RichTextStyleDefinition, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextStyleSheet, AddStyle)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextStyleSheet *pThis = Object_wx_RichTextStyleSheet::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxRichTextStyleDefinition *def = Object_wx_RichTextStyleDefinition::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->AddStyle(def);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextStyleSheet, DeleteStyles)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextStyleSheet, DeleteStyles)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextStyleSheet *pThis = Object_wx_RichTextStyleSheet::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->DeleteStyles();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextStyleSheet, FindCharacterStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextStyleSheet, FindCharacterStyle)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextStyleSheet *pThis = Object_wx_RichTextStyleSheet::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString name = wxString::FromUTF8(args.GetString(0));
	wxRichTextCharacterStyleDefinition *rtn = (wxRichTextCharacterStyleDefinition *)pThis->GetEntity()->FindCharacterStyle(name);
	return ReturnValue(env, args, Value(new Object_wx_RichTextCharacterStyleDefinition(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_RichTextStyleSheet, FindListStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextStyleSheet, FindListStyle)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextStyleSheet *pThis = Object_wx_RichTextStyleSheet::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString name = wxString::FromUTF8(args.GetString(0));
	wxRichTextListStyleDefinition *rtn = (wxRichTextListStyleDefinition *)pThis->GetEntity()->FindListStyle(name);
	return ReturnValue(env, args, Value(new Object_wx_RichTextListStyleDefinition(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_RichTextStyleSheet, FindParagraphStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextStyleSheet, FindParagraphStyle)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextStyleSheet *pThis = Object_wx_RichTextStyleSheet::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString name = wxString::FromUTF8(args.GetString(0));
	wxRichTextParagraphStyleDefinition *rtn = (wxRichTextParagraphStyleDefinition *)pThis->GetEntity()->FindParagraphStyle(name);
	return ReturnValue(env, args, Value(new Object_wx_RichTextParagraphStyleDefinition(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_RichTextStyleSheet, FindStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextStyleSheet, FindStyle)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextStyleSheet *pThis = Object_wx_RichTextStyleSheet::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString name = wxString::FromUTF8(args.GetString(0));
	wxRichTextStyleDefinition *rtn = (wxRichTextStyleDefinition *)pThis->GetEntity()->FindStyle(name);
	return ReturnValue(env, args, Value(new Object_wx_RichTextStyleDefinition(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_RichTextStyleSheet, GetCharacterStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextStyleSheet, GetCharacterStyle)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextStyleSheet *pThis = Object_wx_RichTextStyleSheet::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t n = args.GetSizeT(0);
	wxRichTextCharacterStyleDefinition *rtn = (wxRichTextCharacterStyleDefinition *)pThis->GetEntity()->GetCharacterStyle(n);
	return ReturnValue(env, args, Value(new Object_wx_RichTextCharacterStyleDefinition(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_RichTextStyleSheet, GetCharacterStyleCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextStyleSheet, GetCharacterStyleCount)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextStyleSheet *pThis = Object_wx_RichTextStyleSheet::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t rtn = pThis->GetEntity()->GetCharacterStyleCount();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextStyleSheet, GetDescription)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextStyleSheet, GetDescription)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextStyleSheet *pThis = Object_wx_RichTextStyleSheet::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetDescription();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_RichTextStyleSheet, GetListStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextStyleSheet, GetListStyle)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextStyleSheet *pThis = Object_wx_RichTextStyleSheet::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t n = args.GetSizeT(0);
	wxRichTextListStyleDefinition *rtn = (wxRichTextListStyleDefinition *)pThis->GetEntity()->GetListStyle(n);
	return ReturnValue(env, args, Value(new Object_wx_RichTextListStyleDefinition(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_RichTextStyleSheet, GetListStyleCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextStyleSheet, GetListStyleCount)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextStyleSheet *pThis = Object_wx_RichTextStyleSheet::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t rtn = pThis->GetEntity()->GetListStyleCount();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextStyleSheet, GetName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextStyleSheet, GetName)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextStyleSheet *pThis = Object_wx_RichTextStyleSheet::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetName();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_RichTextStyleSheet, GetParagraphStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextStyleSheet, GetParagraphStyle)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextStyleSheet *pThis = Object_wx_RichTextStyleSheet::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t n = args.GetSizeT(0);
	wxRichTextParagraphStyleDefinition *rtn = (wxRichTextParagraphStyleDefinition *)pThis->GetEntity()->GetParagraphStyle(n);
	return ReturnValue(env, args, Value(new Object_wx_RichTextParagraphStyleDefinition(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_RichTextStyleSheet, GetParagraphStyleCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextStyleSheet, GetParagraphStyleCount)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextStyleSheet *pThis = Object_wx_RichTextStyleSheet::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t rtn = pThis->GetEntity()->GetParagraphStyleCount();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextStyleSheet, RemoveCharacterStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "def", VTYPE_wx_RichTextStyleDefinition, OCCUR_Once);
	DeclareArg(env, "deleteStyle", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextStyleSheet, RemoveCharacterStyle)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextStyleSheet *pThis = Object_wx_RichTextStyleSheet::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxRichTextStyleDefinition *def = Object_wx_RichTextStyleDefinition::GetObject(args, 0)->GetEntity();
	bool deleteStyle = false;
	if (args.IsValid(1)) deleteStyle = args.GetBoolean(1);
	bool rtn = pThis->GetEntity()->RemoveCharacterStyle(def, deleteStyle);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextStyleSheet, RemoveListStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "def", VTYPE_wx_RichTextStyleDefinition, OCCUR_Once);
	DeclareArg(env, "deleteStyle", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextStyleSheet, RemoveListStyle)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextStyleSheet *pThis = Object_wx_RichTextStyleSheet::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxRichTextStyleDefinition *def = Object_wx_RichTextStyleDefinition::GetObject(args, 0)->GetEntity();
	bool deleteStyle = false;
	if (args.IsValid(1)) deleteStyle = args.GetBoolean(1);
	bool rtn = pThis->GetEntity()->RemoveListStyle(def, deleteStyle);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextStyleSheet, RemoveParagraphStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "def", VTYPE_wx_RichTextStyleDefinition, OCCUR_Once);
	DeclareArg(env, "deleteStyle", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextStyleSheet, RemoveParagraphStyle)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextStyleSheet *pThis = Object_wx_RichTextStyleSheet::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxRichTextStyleDefinition *def = Object_wx_RichTextStyleDefinition::GetObject(args, 0)->GetEntity();
	bool deleteStyle = false;
	if (args.IsValid(1)) deleteStyle = args.GetBoolean(1);
	bool rtn = pThis->GetEntity()->RemoveParagraphStyle(def, deleteStyle);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextStyleSheet, RemoveStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "def", VTYPE_wx_RichTextStyleDefinition, OCCUR_Once);
	DeclareArg(env, "deleteStyle", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextStyleSheet, RemoveStyle)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextStyleSheet *pThis = Object_wx_RichTextStyleSheet::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxRichTextStyleDefinition *def = Object_wx_RichTextStyleDefinition::GetObject(args, 0)->GetEntity();
	bool deleteStyle = false;
	if (args.IsValid(1)) deleteStyle = args.GetBoolean(1);
	bool rtn = pThis->GetEntity()->RemoveStyle(def, deleteStyle);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextStyleSheet, SetDescription)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "descr", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextStyleSheet, SetDescription)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextStyleSheet *pThis = Object_wx_RichTextStyleSheet::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString descr = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetDescription(descr);
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextStyleSheet, SetName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextStyleSheet, SetName)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextStyleSheet *pThis = Object_wx_RichTextStyleSheet::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString name = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetName(name);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxRichTextStyleSheet
//----------------------------------------------------------------------------
Object_wx_RichTextStyleSheet::~Object_wx_RichTextStyleSheet()
{
}

Object *Object_wx_RichTextStyleSheet::Clone() const
{
	wx_RichTextStyleSheet *pEntity = new wx_RichTextStyleSheet(*dynamic_cast<wxRichTextStyleSheet *>(_pEntity));
	Object_wx_RichTextStyleSheet *pObj = new Object_wx_RichTextStyleSheet(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return pObj;
}

String Object_wx_RichTextStyleSheet::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextStyleSheet:");
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
// Class implementation for wxRichTextStyleSheet
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextStyleSheet)
{
	Gura_AssignFunction(RichTextStyleSheet);
	Gura_AssignMethod(wx_RichTextStyleSheet, AddCharacterStyle);
	Gura_AssignMethod(wx_RichTextStyleSheet, AddListStyle);
	Gura_AssignMethod(wx_RichTextStyleSheet, AddParagraphStyle);
	Gura_AssignMethod(wx_RichTextStyleSheet, AddStyle);
	Gura_AssignMethod(wx_RichTextStyleSheet, DeleteStyles);
	Gura_AssignMethod(wx_RichTextStyleSheet, FindCharacterStyle);
	Gura_AssignMethod(wx_RichTextStyleSheet, FindListStyle);
	Gura_AssignMethod(wx_RichTextStyleSheet, FindParagraphStyle);
	Gura_AssignMethod(wx_RichTextStyleSheet, FindStyle);
	Gura_AssignMethod(wx_RichTextStyleSheet, GetCharacterStyle);
	Gura_AssignMethod(wx_RichTextStyleSheet, GetCharacterStyleCount);
	Gura_AssignMethod(wx_RichTextStyleSheet, GetDescription);
	Gura_AssignMethod(wx_RichTextStyleSheet, GetListStyle);
	Gura_AssignMethod(wx_RichTextStyleSheet, GetListStyleCount);
	Gura_AssignMethod(wx_RichTextStyleSheet, GetName);
	Gura_AssignMethod(wx_RichTextStyleSheet, GetParagraphStyle);
	Gura_AssignMethod(wx_RichTextStyleSheet, GetParagraphStyleCount);
	Gura_AssignMethod(wx_RichTextStyleSheet, RemoveCharacterStyle);
	Gura_AssignMethod(wx_RichTextStyleSheet, RemoveListStyle);
	Gura_AssignMethod(wx_RichTextStyleSheet, RemoveParagraphStyle);
	Gura_AssignMethod(wx_RichTextStyleSheet, RemoveStyle);
	Gura_AssignMethod(wx_RichTextStyleSheet, SetDescription);
	Gura_AssignMethod(wx_RichTextStyleSheet, SetName);
}

Gura_ImplementDescendantCreator(wx_RichTextStyleSheet)
{
	return new Object_wx_RichTextStyleSheet((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
