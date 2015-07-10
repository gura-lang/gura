//----------------------------------------------------------------------------
// wxHTTP
// extracted from http.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_HTTP: public wxHTTP, public GuraObjectObserver {
private:
	Gura::Signal *_pSig;
	Object_wx_HTTP *_pObj;
public:
	~wx_HTTP();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_HTTP *pObj) {
		_pSig = &sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_HTTP::~wx_HTTP()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_HTTP::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxHTTP
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_HTTP, GetResponse)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HTTP, GetResponse)
{
	Object_wx_HTTP *pThis = Object_wx_HTTP::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetResponse();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_HTTP, GetInputStream)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "path", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HTTP, GetInputStream)
{
	Object_wx_HTTP *pThis = Object_wx_HTTP::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString path = wxString::FromUTF8(args.GetString(0));
	wxInputStream *rtn = (wxInputStream *)pThis->GetEntity()->GetInputStream(path);
	return ReturnValue(env, sig, args, Value(new Object_wx_InputStream(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_HTTP, SetHeader)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "header", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "h_data", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_HTTP, SetHeader)
{
	Object_wx_HTTP *pThis = Object_wx_HTTP::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString header = wxString::FromUTF8(args.GetString(0));
	wxString h_data = wxString::FromUTF8(args.GetString(1));
	pThis->GetEntity()->SetHeader(header, h_data);
	return Value::Null;
}

Gura_DeclareMethod(wx_HTTP, GetHeader)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "header", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HTTP, GetHeader)
{
	Object_wx_HTTP *pThis = Object_wx_HTTP::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString header = wxString::FromUTF8(args.GetString(0));
	wxString rtn = pThis->GetEntity()->GetHeader(header);
	return ReturnValue(env, sig, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

//----------------------------------------------------------------------------
// Object implementation for wxHTTP
//----------------------------------------------------------------------------
Object_wx_HTTP::~Object_wx_HTTP()
{
}

Object *Object_wx_HTTP::Clone() const
{
	return nullptr;
}

String Object_wx_HTTP::ToString(bool exprFlag)
{
	String rtn("<wx.HTTP:");
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
// Class implementation for wxHTTP
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HTTP)
{
	Gura_AssignMethod(wx_HTTP, GetResponse);
	Gura_AssignMethod(wx_HTTP, GetInputStream);
	Gura_AssignMethod(wx_HTTP, SetHeader);
	Gura_AssignMethod(wx_HTTP, GetHeader);
}

Gura_ImplementDescendantCreator(wx_HTTP)
{
	return new Object_wx_HTTP((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
