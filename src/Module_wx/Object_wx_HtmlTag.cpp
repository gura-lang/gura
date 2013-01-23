//----------------------------------------------------------------------------
// wxHtmlTag
// extracted from httag.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_HtmlTag: public wxHtmlTag, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_HtmlTag *_pObj;
public:
	//inline wx_HtmlTag(wxHtmlTag * parent, const wxString& source, int pos, int end_pos, wxHtmlTagsCache* cache, wxHtmlEntitiesParser * entParser) : wxHtmlTag(parent, source, pos, end_pos, cache, entParser), _sig(NULL), _pObj(NULL) {}
	~wx_HtmlTag();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_HtmlTag *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_HtmlTag::~wx_HtmlTag()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_HtmlTag::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlTag
//----------------------------------------------------------------------------
Gura_DeclareFunction(HtmlTag)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
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
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxHtmlTag *parent = Object_wx_HtmlTag::GetObject(args, 0)->GetEntity();
	wxString source = wxString::FromUTF8(args.GetString(1));
	int pos = args.GetInt(2);
	int end_pos = args.GetInt(3);
	wxHtmlTagsCache *cache = Object_wx_HtmlTagsCache::GetObject(args, 4)->GetEntity();
	wxHtmlEntitiesParser *entParser = Object_wx_HtmlEntitiesParser::GetObject(args, 5)->GetEntity();
	wx_HtmlTag *pEntity = new wx_HtmlTag(parent, source, pos, end_pos, cache, entParser);
	Object_wx_HtmlTag *pObj = Object_wx_HtmlTag::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_HtmlTag(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlTag, GetAllParams)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlTag, GetAllParams)
{
	Object_wx_HtmlTag *pSelf = Object_wx_HtmlTag::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString rtn = pSelf->GetEntity()->GetAllParams();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_HtmlTag, GetBeginPos)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlTag, GetBeginPos)
{
	Object_wx_HtmlTag *pSelf = Object_wx_HtmlTag::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rtn = pSelf->GetEntity()->GetBeginPos();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_HtmlTag, GetEndPos1)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlTag, GetEndPos1)
{
	Object_wx_HtmlTag *pSelf = Object_wx_HtmlTag::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rtn = pSelf->GetEntity()->GetEndPos1();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_HtmlTag, GetEndPos2)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlTag, GetEndPos2)
{
	Object_wx_HtmlTag *pSelf = Object_wx_HtmlTag::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rtn = pSelf->GetEntity()->GetEndPos2();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_HtmlTag, GetName)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlTag, GetName)
{
	Object_wx_HtmlTag *pSelf = Object_wx_HtmlTag::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString rtn = pSelf->GetEntity()->GetName();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_HtmlTag, GetParam)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "par", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "with_commas", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlTag, GetParam)
{
	Object_wx_HtmlTag *pSelf = Object_wx_HtmlTag::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString par = wxString::FromUTF8(args.GetString(0));
	bool with_commas = false;
	if (args.IsValid(1)) with_commas = args.GetBoolean(1);
	wxString rtn = pSelf->GetEntity()->GetParam(par, with_commas);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_HtmlTag, GetParamAsColour)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "par", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "clr", VTYPE_wx_Colour, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlTag, GetParamAsColour)
{
	Object_wx_HtmlTag *pSelf = Object_wx_HtmlTag::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString par = wxString::FromUTF8(args.GetString(0));
	wxColour *clr = Object_wx_Colour::GetObject(args, 1)->GetEntity();
	bool rtn = pSelf->GetEntity()->GetParamAsColour(par, clr);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_HtmlTag, GetParamAsInt)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "par", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlTag, GetParamAsInt)
{
#if 0
	Object_wx_HtmlTag *pSelf = Object_wx_HtmlTag::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString par = wxString::FromUTF8(args.GetString(0));
	int value = args.GetInt(1);
	bool rtn = pSelf->GetEntity()->GetParamAsInt(par, value);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlTag, HasEnding)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlTag, HasEnding)
{
	Object_wx_HtmlTag *pSelf = Object_wx_HtmlTag::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->HasEnding();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_HtmlTag, HasParam)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "par", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlTag, HasParam)
{
	Object_wx_HtmlTag *pSelf = Object_wx_HtmlTag::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString par = wxString::FromUTF8(args.GetString(0));
	bool rtn = pSelf->GetEntity()->HasParam(par);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_HtmlTag, ScanParam)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "par", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "format", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlTag, ScanParam)
{
#if 0
	Object_wx_HtmlTag *pSelf = Object_wx_HtmlTag::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString par = wxString::FromUTF8(args.GetString(0));
	wxString format = wxString::FromUTF8(args.GetString(1));
	int value = args.GetInt(2);
	wxString rtn = pSelf->GetEntity()->ScanParam(par, format, value);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxHtmlTag
//----------------------------------------------------------------------------
Object_wx_HtmlTag::~Object_wx_HtmlTag()
{
}

Object *Object_wx_HtmlTag::Clone() const
{
	return NULL;
}

String Object_wx_HtmlTag::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.HtmlTag:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_HtmlTag::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(HtmlTag);
}

//----------------------------------------------------------------------------
// Class implementation for wxHtmlTag
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlTag)
{
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
	return new Object_wx_HtmlTag((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
