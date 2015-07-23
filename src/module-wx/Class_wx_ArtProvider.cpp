//----------------------------------------------------------------------------
// wxArtProvider
// extracted from artprov.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_ArtProvider: public wxArtProvider, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_ArtProvider *_pObj;
public:
	~wx_ArtProvider();
	inline void AssocWithGura(Object_wx_ArtProvider *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_ArtProvider::~wx_ArtProvider()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_ArtProvider::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxArtProvider
//----------------------------------------------------------------------------
Gura_DeclareFunction(ArtProvider)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_ArtProvider));
}

Gura_ImplementFunction(ArtProvider)
{
	if (!CheckWxReady(sig)) return Value::Null;
	return Value::Null;
}

Gura_DeclareClassMethod(wx_ArtProvider, Delete)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "provider", VTYPE_wx_ArtProvider, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_ArtProvider, Delete)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxArtProvider *provider = Object_wx_ArtProvider::GetObject(args, 0)->GetEntity();
	bool rtn = wxArtProvider::Delete(provider);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareClassMethod(wx_ArtProvider, GetBitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "id", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "client", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_ArtProvider, GetBitmap)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxArtID id = static_cast<wxArtID>(wxString::FromUTF8(args.GetString(0)));
	wxArtClient client = wxART_OTHER;
	if (args.IsValid(1)) client = static_cast<wxArtClient>(wxString::FromUTF8(args.GetString(1)));
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(2)) size = Object_wx_Size::GetObject(args, 2)->GetEntity();
	wxBitmap rtn = wxArtProvider::GetBitmap(id, client, *size);
	return ReturnValue(env, args, Value(new Object_wx_Bitmap(new wxBitmap(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareClassMethod(wx_ArtProvider, GetIcon)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "id", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "client", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_ArtProvider, GetIcon)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxArtID id = static_cast<wxArtID>(wxString::FromUTF8(args.GetString(0)));
	wxArtClient client = wxART_OTHER;
	if (args.IsValid(1)) client = static_cast<wxArtClient>(wxString::FromUTF8(args.GetString(1)));
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(2)) size = Object_wx_Size::GetObject(args, 2)->GetEntity();
	wxIcon rtn = wxArtProvider::GetIcon(id, client, *size);
	return ReturnValue(env, args, Value(new Object_wx_Icon(new wxIcon(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareClassMethod(wx_ArtProvider, GetSizeHint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "client", VTYPE_wx_ArtClient, OCCUR_Once);
	DeclareArg(env, "platform_default", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_ArtProvider, GetSizeHint)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxArtClient *client = Object_wx_ArtClient::GetObject(args, 0)->GetEntity();
	bool platform_default = false;
	if (args.IsValid(1)) platform_default = args.GetBoolean(1);
	wxSize rtn = wxArtProvider::GetSizeHint(*client, platform_default);
	return ReturnValue(env, args, Value(new Object_wx_Size(new wxSize(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareClassMethod(wx_ArtProvider, Insert)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "provider", VTYPE_wx_ArtProvider, OCCUR_Once);
}

Gura_ImplementClassMethod(wx_ArtProvider, Insert)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxArtProvider *provider = Object_wx_ArtProvider::GetObject(args, 0)->GetEntity();
	wxArtProvider::Insert(provider);
	return Value::Null;
}

Gura_DeclareClassMethod(wx_ArtProvider, Pop)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_ArtProvider, Pop)
{
	if (!CheckWxReady(sig)) return Value::Null;
	bool rtn = wxArtProvider::Pop();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareClassMethod(wx_ArtProvider, Push)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "provider", VTYPE_wx_ArtProvider, OCCUR_Once);
}

Gura_ImplementClassMethod(wx_ArtProvider, Push)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxArtProvider *provider = Object_wx_ArtProvider::GetObject(args, 0)->GetEntity();
	wxArtProvider::Push(provider);
	return Value::Null;
}

Gura_DeclareClassMethod(wx_ArtProvider, Remove)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "provider", VTYPE_wx_ArtProvider, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_ArtProvider, Remove)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxArtProvider *provider = Object_wx_ArtProvider::GetObject(args, 0)->GetEntity();
	bool rtn = wxArtProvider::Remove(provider);
	return ReturnValue(env, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxArtProvider
//----------------------------------------------------------------------------
Object_wx_ArtProvider::~Object_wx_ArtProvider()
{
}

Object *Object_wx_ArtProvider::Clone() const
{
	return nullptr;
}

String Object_wx_ArtProvider::ToString(bool exprFlag)
{
	String rtn("<wx.ArtProvider:");
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
// Class implementation for wxArtProvider
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ArtProvider)
{
	Gura_AssignFunction(ArtProvider);
	Gura_AssignMethod(wx_ArtProvider, Delete);
	Gura_AssignMethod(wx_ArtProvider, GetBitmap);
	Gura_AssignMethod(wx_ArtProvider, GetIcon);
	Gura_AssignMethod(wx_ArtProvider, GetSizeHint);
	Gura_AssignMethod(wx_ArtProvider, Insert);
	Gura_AssignMethod(wx_ArtProvider, Pop);
	Gura_AssignMethod(wx_ArtProvider, Push);
	Gura_AssignMethod(wx_ArtProvider, Remove);
}

Gura_ImplementDescendantCreator(wx_ArtProvider)
{
	return new Object_wx_ArtProvider((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
