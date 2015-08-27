//----------------------------------------------------------------------------
// wxDllLoader
// extracted from dllload.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_DllLoader: public wxDllLoader, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_DllLoader *_pObj;
public:
	~wx_DllLoader();
	inline void AssocWithGura(Object_wx_DllLoader *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_DllLoader::~wx_DllLoader()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_DllLoader::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxDllLoader
//----------------------------------------------------------------------------
Gura_DeclareClassMethod(wx_DllLoader, GetDllExt)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_DllLoader, GetDllExt)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxString rtn = wxDllLoader::GetDllExt();
	return ReturnValue(env, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_DllLoader, GetProgramHandle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DllLoader, GetProgramHandle)
{
	Signal &sig = env.GetSignal();
	Object_wx_DllLoader *pThis = Object_wx_DllLoader::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxDllType rtn = pThis->GetEntity()->GetProgramHandle();
	return ReturnValue(env, args, Value(new Object_wx_DllType(new wxDllType(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_DllLoader, GetSymbol)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "dllHandle", VTYPE_wx_DllType, OCCUR_Once);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_DllLoader, GetSymbol)
{
	Signal &sig = env.GetSignal();
	Object_wx_DllLoader *pThis = Object_wx_DllLoader::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxDllType *dllHandle = Object_wx_DllType::GetObject(args, 0)->GetEntity();
	wxString name = wxString::FromUTF8(args.GetString(1));
	pThis->GetEntity()->GetSymbol(*dllHandle, name);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DllLoader, LoadLibrary)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "libname", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "success", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DllLoader, LoadLibrary)
{
	Signal &sig = env.GetSignal();
	Object_wx_DllLoader *pThis = Object_wx_DllLoader::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString libname = wxString::FromUTF8(args.GetString(0));
	bool success = nullptr;
	if (args.IsValid(1)) success = args.GetBoolean(1);
	wxDllType rtn = pThis->GetEntity()->LoadLibrary(libname, success);
	return ReturnValue(env, args, Value(new Object_wx_DllType(new wxDllType(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_DllLoader, UnloadLibrary)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "dllhandle", VTYPE_wx_DllType, OCCUR_Once);
}

Gura_ImplementMethod(wx_DllLoader, UnloadLibrary)
{
	Signal &sig = env.GetSignal();
	Object_wx_DllLoader *pThis = Object_wx_DllLoader::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxDllType *dllhandle = Object_wx_DllType::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->UnloadLibrary(*dllhandle);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxDllLoader
//----------------------------------------------------------------------------
Object_wx_DllLoader::~Object_wx_DllLoader()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_DllLoader::Clone() const
{
	return nullptr;
}

String Object_wx_DllLoader::ToString(bool exprFlag)
{
	String rtn("<wx.DllLoader:");
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
	return new Object_wx_DllLoader((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
