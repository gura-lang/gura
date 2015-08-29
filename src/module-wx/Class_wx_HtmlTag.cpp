//----------------------------------------------------------------------------
// wxHtmlTag
// extracted from httag.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_HtmlTag: public wxHtmlTag, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_HtmlTag *_pObj;
public:
	//inline wx_HtmlTag(wxHtmlTag * parent, const wxString& source, int pos, int end_pos, wxHtmlTagsCache* cache, wxHtmlEntitiesParser * entParser) : wxHtmlTag(parent, source, pos, end_pos, cache, entParser), _pObj(nullptr) {}
	~wx_HtmlTag();
	inline void AssocWithGura(Object_wx_HtmlTag *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_HtmlTag::~wx_HtmlTag()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_HtmlTag::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlTag
//----------------------------------------------------------------------------
Gura_DeclareFunction(HtmlTag)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_HtmlTag));
	DeclareArg(env, "parent", VTYPE_wx_HtmlTag, OCCUR_Once);
	DeclareArg(env, "source", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "end_pos", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "cache", VTYPE_wx_HtmlTagsCache, OCCUR_Once);
	DeclareArg(env, "entParser", VTYPE_wx_HtmlEntitiesParser, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(HtmlTag)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wxHtmlTag *parent = Object_wx_HtmlTag::GetObject(arg, 0)->GetEntity();
	wxString source = wxString::FromUTF8(arg.GetString(1));
	int pos = arg.GetInt(2);
	int end_pos = arg.GetInt(3);
	wxHtmlTagsCache *cache = Object_wx_HtmlTagsCache::GetObject(arg, 4)->GetEntity();
	wxHtmlEntitiesParser *entParser = Object_wx_HtmlEntitiesParser::GetObject(arg, 5)->GetEntity();
	wx_HtmlTag *pEntity = new wx_HtmlTag(parent, source, pos, end_pos, cache, entParser);
	Object_wx_HtmlTag *pObj = Object_wx_HtmlTag::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_HtmlTag(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlTag, GetAllParams)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlTag, GetAllParams)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlTag *pThis = Object_wx_HtmlTag::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetAllParams();
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_HtmlTag, GetBeginPos)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlTag, GetBeginPos)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlTag *pThis = Object_wx_HtmlTag::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetBeginPos();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_HtmlTag, GetEndPos1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlTag, GetEndPos1)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlTag *pThis = Object_wx_HtmlTag::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetEndPos1();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_HtmlTag, GetEndPos2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlTag, GetEndPos2)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlTag *pThis = Object_wx_HtmlTag::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetEndPos2();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_HtmlTag, GetName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlTag, GetName)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlTag *pThis = Object_wx_HtmlTag::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetName();
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_HtmlTag, GetParam)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "par", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "with_commas", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlTag, GetParam)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlTag *pThis = Object_wx_HtmlTag::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString par = wxString::FromUTF8(arg.GetString(0));
	bool with_commas = false;
	if (arg.IsValid(1)) with_commas = arg.GetBoolean(1);
	wxString rtn = pThis->GetEntity()->GetParam(par, with_commas);
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_HtmlTag, GetParamAsColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "par", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "clr", VTYPE_wx_Colour, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlTag, GetParamAsColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlTag *pThis = Object_wx_HtmlTag::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString par = wxString::FromUTF8(arg.GetString(0));
	wxColour *clr = Object_wx_Colour::GetObject(arg, 1)->GetEntity();
	bool rtn = pThis->GetEntity()->GetParamAsColour(par, clr);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_HtmlTag, GetParamAsInt)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "par", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlTag, GetParamAsInt)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_HtmlTag *pThis = Object_wx_HtmlTag::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString par = wxString::FromUTF8(arg.GetString(0));
	int value = arg.GetInt(1);
	bool rtn = pThis->GetEntity()->GetParamAsInt(par, value);
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlTag, HasEnding)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlTag, HasEnding)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlTag *pThis = Object_wx_HtmlTag::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->HasEnding();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_HtmlTag, HasParam)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "par", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlTag, HasParam)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlTag *pThis = Object_wx_HtmlTag::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString par = wxString::FromUTF8(arg.GetString(0));
	bool rtn = pThis->GetEntity()->HasParam(par);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_HtmlTag, ScanParam)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "par", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "format", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlTag, ScanParam)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_HtmlTag *pThis = Object_wx_HtmlTag::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString par = wxString::FromUTF8(arg.GetString(0));
	wxString format = wxString::FromUTF8(arg.GetString(1));
	int value = arg.GetInt(2);
	wxString rtn = pThis->GetEntity()->ScanParam(par, format, value);
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxHtmlTag
//----------------------------------------------------------------------------
Object_wx_HtmlTag::~Object_wx_HtmlTag()
{
}

Object *Object_wx_HtmlTag::Clone() const
{
	return nullptr;
}

String Object_wx_HtmlTag::ToString(bool exprFlag)
{
	String rtn("<wx.HtmlTag:");
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
// Class implementation for wxHtmlTag
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlTag)
{
	Gura_AssignFunction(HtmlTag);
	Gura_AssignMethod(wx_HtmlTag, GetAllParams);
	Gura_AssignMethod(wx_HtmlTag, GetBeginPos);
	Gura_AssignMethod(wx_HtmlTag, GetEndPos1);
	Gura_AssignMethod(wx_HtmlTag, GetEndPos2);
	Gura_AssignMethod(wx_HtmlTag, GetName);
	Gura_AssignMethod(wx_HtmlTag, GetParam);
	Gura_AssignMethod(wx_HtmlTag, GetParamAsColour);
	Gura_AssignMethod(wx_HtmlTag, GetParamAsInt);
	Gura_AssignMethod(wx_HtmlTag, HasEnding);
	Gura_AssignMethod(wx_HtmlTag, HasParam);
	Gura_AssignMethod(wx_HtmlTag, ScanParam);
}

Gura_ImplementDescendantCreator(wx_HtmlTag)
{
	return new Object_wx_HtmlTag((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
