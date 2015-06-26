//----------------------------------------------------------------------------
// wxFontList
// extracted from fontlist.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_FontList: public wxFontList, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_FontList *_pObj;
public:
	inline wx_FontList() : wxFontList(), _sig(nullptr), _pObj(nullptr) {}
	~wx_FontList();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_FontList *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_FontList::~wx_FontList()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_FontList::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxFontList
//----------------------------------------------------------------------------
Gura_DeclareFunction(FontListEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_FontList));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(FontListEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_FontList *pEntity = new wx_FontList();
	Object_wx_FontList *pObj = Object_wx_FontList::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_FontList(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_FontList, FindOrCreateFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "point_size", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "family", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "weight", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "underline", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareArg(env, "facename", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "encoding", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FontList, FindOrCreateFont)
{
	Object_wx_FontList *pThis = Object_wx_FontList::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int point_size = args.GetInt(0);
	int family = args.GetInt(1);
	int style = args.GetInt(2);
	int weight = args.GetInt(3);
	bool underline = false;
	if (args.IsValid(4)) underline = args.GetBoolean(4);
	wxString facename = nullptr;
	if (args.IsValid(5)) facename = wxString::FromUTF8(args.GetString(5));
	wxFontEncoding encoding = wxFONTENCODING_DEFAULT;
	if (args.IsValid(6)) encoding = static_cast<wxFontEncoding>(args.GetInt(6));
	wxFont *rtn = (wxFont *)pThis->GetEntity()->FindOrCreateFont(point_size, family, style, weight, underline, facename, encoding);
	return ReturnValue(env, sig, args, Value(new Object_wx_Font(rtn, nullptr, OwnerFalse)));
}

//----------------------------------------------------------------------------
// Object implementation for wxFontList
//----------------------------------------------------------------------------
Object_wx_FontList::~Object_wx_FontList()
{
}

Object *Object_wx_FontList::Clone() const
{
	return nullptr;
}

String Object_wx_FontList::ToString(bool exprFlag)
{
	String rtn("<wx.FontList:");
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
// Class implementation for wxFontList
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FontList)
{
	Gura_AssignFunction(FontListEmpty);
	Gura_AssignMethod(wx_FontList, FindOrCreateFont);
}

Gura_ImplementDescendantCreator(wx_FontList)
{
	return new Object_wx_FontList((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
