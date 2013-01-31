//----------------------------------------------------------------------------
// wxDllLoader
// extracted from dllload.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_DllLoader: public wxDllLoader, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_DllLoader *_pObj;
public:
	~wx_DllLoader();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_DllLoader *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_DllLoader::~wx_DllLoader()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_DllLoader::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxDllLoader
//----------------------------------------------------------------------------
Gura_DeclareClassMethod(wx_DllLoader, GetDllExt)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_DllLoader, GetDllExt)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxString rtn = wxDllLoader::GetDllExt();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_DllLoader, GetProgramHandle)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DllLoader, GetProgramHandle)
{
	Object_wx_DllLoader *pThis = Object_wx_DllLoader::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDllType rtn = pThis->GetEntity()->GetProgramHandle();
	return ReturnValue(env, sig, args, Value(new Object_wx_DllType(new wxDllType(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_DllLoader, GetSymbol)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "dllHandle", VTYPE_wx_DllType, OCCUR_Once);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_DllLoader, GetSymbol)
{
	Object_wx_DllLoader *pThis = Object_wx_DllLoader::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDllType *dllHandle = Object_wx_DllType::GetObject(args, 0)->GetEntity();
	wxString name = wxString::FromUTF8(args.GetString(1));
	pThis->GetEntity()->GetSymbol(*dllHandle, name);
	return Value::Null;
}

Gura_DeclareMethod(wx_DllLoader, LoadLibrary)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "libname", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "success", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DllLoader, LoadLibrary)
{
	Object_wx_DllLoader *pThis = Object_wx_DllLoader::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString libname = wxString::FromUTF8(args.GetString(0));
	bool success = NULL;
	if (args.IsValid(1)) success = args.GetBoolean(1);
	wxDllType rtn = pThis->GetEntity()->LoadLibrary(libname, success);
	return ReturnValue(env, sig, args, Value(new Object_wx_DllType(new wxDllType(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_DllLoader, UnloadLibrary)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "dllhandle", VTYPE_wx_DllType, OCCUR_Once);
}

Gura_ImplementMethod(wx_DllLoader, UnloadLibrary)
{
	Object_wx_DllLoader *pThis = Object_wx_DllLoader::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDllType *dllhandle = Object_wx_DllType::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->UnloadLibrary(*dllhandle);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxDllLoader
//----------------------------------------------------------------------------
Object_wx_DllLoader::~Object_wx_DllLoader()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_DllLoader::Clone() const
{
	return NULL;
}

String Object_wx_DllLoader::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.DllLoader:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_DllLoader::OnModuleEntry(Environment &env, Signal sig)
{
}

//----------------------------------------------------------------------------
// Class implementation for wxDllLoader
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DllLoader)
{
	Gura_AssignMethod(wx_DllLoader, GetDllExt);
	Gura_AssignMethod(wx_DllLoader, GetProgramHandle);
	Gura_AssignMethod(wx_DllLoader, GetSymbol);
	Gura_AssignMethod(wx_DllLoader, LoadLibrary);
	Gura_AssignMethod(wx_DllLoader, UnloadLibrary);
}

Gura_ImplementDescendantCreator(wx_DllLoader)
{
	return new Object_wx_DllLoader((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
