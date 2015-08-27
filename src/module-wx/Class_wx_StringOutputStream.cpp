//----------------------------------------------------------------------------
// wxStringOutputStream
// extracted from sostream.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_StringOutputStream: public wxStringOutputStream, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_StringOutputStream *_pObj;
public:
	inline wx_StringOutputStream(wxString *str) : wxStringOutputStream(str), _pObj(nullptr) {}
	~wx_StringOutputStream();
	inline void AssocWithGura(Object_wx_StringOutputStream *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_StringOutputStream::~wx_StringOutputStream()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_StringOutputStream::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxStringOutputStream
//----------------------------------------------------------------------------
Gura_DeclareFunction(StringOutputStream)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_StringOutputStream));
	DeclareArg(env, "str", VTYPE_wx_String, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(StringOutputStream)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxString *str = nullptr;
	if (args.IsValid(0)) str = Object_wx_String::GetObject(args, 0)->GetEntity();
	wx_StringOutputStream *pEntity = new wx_StringOutputStream(str);
	Object_wx_StringOutputStream *pObj = Object_wx_StringOutputStream::GetObjectThis(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_StringOutputStream(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
}

Gura_DeclareMethod(wx_StringOutputStream, GetString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StringOutputStream, GetString)
{
	Signal &sig = env.GetSignal();
	Object_wx_StringOutputStream *pThis = Object_wx_StringOutputStream::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetString();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

//----------------------------------------------------------------------------
// Object implementation for wxStringOutputStream
//----------------------------------------------------------------------------
Object_wx_StringOutputStream::~Object_wx_StringOutputStream()
{
}

Object *Object_wx_StringOutputStream::Clone() const
{
	return nullptr;
}

String Object_wx_StringOutputStream::ToString(bool exprFlag)
{
	String rtn("<wx.StringOutputStream:");
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
// Class implementation for wxStringOutputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_StringOutputStream)
{
	Gura_AssignFunction(StringOutputStream);
	Gura_AssignMethod(wx_StringOutputStream, GetString);
}

Gura_ImplementDescendantCreator(wx_StringOutputStream)
{
	return new Object_wx_StringOutputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
