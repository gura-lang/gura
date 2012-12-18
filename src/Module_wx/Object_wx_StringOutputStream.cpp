//----------------------------------------------------------------------------
// wxStringOutputStream
// extracted from sostream.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_StringOutputStream: public wxStringOutputStream, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_StringOutputStream *_pObj;
public:
	inline wx_StringOutputStream(wxString *str) : wxStringOutputStream(str), _sig(NULL), _pObj(NULL) {}
	~wx_StringOutputStream();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_StringOutputStream *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_StringOutputStream::~wx_StringOutputStream()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_StringOutputStream::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxStringOutputStream
//----------------------------------------------------------------------------
Gura_DeclareFunction(StringOutputStream)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_StringOutputStream));
	DeclareArg(env, "str", VTYPE_wx_String, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(StringOutputStream)
{
	wxString *str = NULL;
	if (args.IsValid(0)) str = Object_wx_String::GetObject(args, 0)->GetEntity();
	wx_StringOutputStream *pEntity = new wx_StringOutputStream(str);
	Object_wx_StringOutputStream *pObj = Object_wx_StringOutputStream::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_StringOutputStream(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareMethod(wx_StringOutputStream, GetString)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StringOutputStream, GetString)
{
	Object_wx_StringOutputStream *pSelf = Object_wx_StringOutputStream::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString rtn = pSelf->GetEntity()->GetString();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

//----------------------------------------------------------------------------
// Object implementation for wxStringOutputStream
//----------------------------------------------------------------------------
Object_wx_StringOutputStream::~Object_wx_StringOutputStream()
{
}

Object *Object_wx_StringOutputStream::Clone() const
{
	return NULL;
}

String Object_wx_StringOutputStream::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.StringOutputStream:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_StringOutputStream::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(StringOutputStream);
}

//----------------------------------------------------------------------------
// Class implementation for wxStringOutputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_StringOutputStream)
{
	Gura_AssignMethod(wx_StringOutputStream, GetString);
}

Gura_ImplementDescendantCreator(wx_StringOutputStream)
{
	return new Object_wx_StringOutputStream((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
