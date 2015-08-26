//----------------------------------------------------------------------------
// wxDynamicLibrary
// extracted from dynlib.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_DynamicLibrary: public wxDynamicLibrary, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_DynamicLibrary *_pObj;
public:
	//inline wx_DynamicLibrary() : wxDynamicLibrary(), _pObj(nullptr) {}
	//inline wx_DynamicLibrary(const wxString& name, int flags) : wxDynamicLibrary(name, flags), _pObj(nullptr) {}
	~wx_DynamicLibrary();
	inline void AssocWithGura(Object_wx_DynamicLibrary *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_DynamicLibrary::~wx_DynamicLibrary()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_DynamicLibrary::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxDynamicLibrary
//----------------------------------------------------------------------------
Gura_DeclareFunction(DynamicLibraryEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_DynamicLibrary));
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(DynamicLibraryEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wx_DynamicLibrary *pEntity = new wx_DynamicLibrary();
	Object_wx_DynamicLibrary *pObj = Object_wx_DynamicLibrary::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_DynamicLibrary(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareFunction(DynamicLibrary)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_DynamicLibrary));
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(DynamicLibrary)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wxString name = wxString::FromUTF8(args.GetString(0));
	int flags = wxDL_DEFAULT;
	if (args.IsValid(1)) flags = args.GetInt(1);
	wx_DynamicLibrary *pEntity = new wx_DynamicLibrary(name, flags);
	Object_wx_DynamicLibrary *pObj = Object_wx_DynamicLibrary::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_DynamicLibrary(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareClassMethod(wx_DynamicLibrary, CanonicalizeName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "cat", VTYPE_wx_DynamicLibraryCategory, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_DynamicLibrary, CanonicalizeName)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wxString name = wxString::FromUTF8(args.GetString(0));
	wxDynamicLibraryCategory *cat = (wxDynamicLibraryCategory *)(&wxDL_LIBRARY);
	if (args.IsValid(1)) cat = Object_wx_DynamicLibraryCategory::GetObject(args, 1)->GetEntity();
	wxString rtn = wxDynamicLibrary::CanonicalizeName(name, *cat);
	return ReturnValue(env, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareClassMethod(wx_DynamicLibrary, CanonicalizePluginName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "cat", VTYPE_wx_PluginCategory, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_DynamicLibrary, CanonicalizePluginName)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wxString name = wxString::FromUTF8(args.GetString(0));
	wxPluginCategory *cat = (wxPluginCategory *)(&wxDL_PLUGIN_GUI);
	if (args.IsValid(1)) cat = Object_wx_PluginCategory::GetObject(args, 1)->GetEntity();
	wxString rtn = wxDynamicLibrary::CanonicalizePluginName(name, *cat);
	return ReturnValue(env, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DynamicLibrary, Detach)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DynamicLibrary, Detach)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_DynamicLibrary *pThis = Object_wx_DynamicLibrary::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxDllType rtn = pThis->GetEntity()->Detach();
	return ReturnValue(env, args, Value(new Object_wx_DllType(new wxDllType(rtn), nullptr, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DynamicLibrary, GetSymbol)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_DynamicLibrary, GetSymbol)
{
	Signal &sig = env.GetSignal();
	Object_wx_DynamicLibrary *pThis = Object_wx_DynamicLibrary::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString name = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->GetSymbol(name);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DynamicLibrary, GetSymbolAorW)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_DynamicLibrary, GetSymbolAorW)
{
	Signal &sig = env.GetSignal();
#if defined(__WXMSW__)
	Object_wx_DynamicLibrary *pThis = Object_wx_DynamicLibrary::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString name = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->GetSymbolAorW(name);
	return Value::Nil;
#else
	SetError_MSWOnly(sig);
	return Value::Nil;
#endif	
}

Gura_DeclareClassMethod(wx_DynamicLibrary, GetProgramHandle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_DynamicLibrary, GetProgramHandle)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wxDllType rtn = wxDynamicLibrary::GetProgramHandle();
	return ReturnValue(env, args, Value(new Object_wx_DllType(new wxDllType(rtn), nullptr, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DynamicLibrary, HasSymbol)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DynamicLibrary, HasSymbol)
{
	Signal &sig = env.GetSignal();
	Object_wx_DynamicLibrary *pThis = Object_wx_DynamicLibrary::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString name = wxString::FromUTF8(args.GetString(0));
	bool rtn = pThis->GetEntity()->HasSymbol(name);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_DynamicLibrary, IsLoaded)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DynamicLibrary, IsLoaded)
{
	Signal &sig = env.GetSignal();
	Object_wx_DynamicLibrary *pThis = Object_wx_DynamicLibrary::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsLoaded();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareClassMethod(wx_DynamicLibrary, ListLoaded)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_DynamicLibrary, ListLoaded)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wxDynamicLibraryDetailsArray rtn = wxDynamicLibrary::ListLoaded();
	return ReturnValue(env, args, Value(new Object_wx_DynamicLibraryDetailsArray(new wxDynamicLibraryDetailsArray(rtn), nullptr, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DynamicLibrary, Load)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DynamicLibrary, Load)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_DynamicLibrary *pThis = Object_wx_DynamicLibrary::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString name = wxString::FromUTF8(args.GetString(0));
	int flags = wxDL_DEFAULT;
	if (args.IsValid(1)) flags = args.GetInt(1);
	bool rtn = pThis->GetEntity()->Load(name, flags);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DynamicLibrary, Unload)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DynamicLibrary, Unload)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_DynamicLibrary *pThis = Object_wx_DynamicLibrary::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->Unload();
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareClassMethod(wx_DynamicLibrary, Unload_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "handle", VTYPE_wx_DllType, OCCUR_Once);
#endif
}

Gura_ImplementClassMethod(wx_DynamicLibrary, Unload_1)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wxDllType *handle = Object_wx_DllType::GetObject(args, 0)->GetEntity();
	wxDynamicLibrary::Unload(*handle);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxDynamicLibrary
//----------------------------------------------------------------------------
Object_wx_DynamicLibrary::~Object_wx_DynamicLibrary()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_DynamicLibrary::Clone() const
{
	return nullptr;
}

String Object_wx_DynamicLibrary::ToString(bool exprFlag)
{
	String rtn("<wx.DynamicLibrary:");
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
// Class implementation for wxDynamicLibrary
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DynamicLibrary)
{
	Gura_AssignFunction(DynamicLibraryEmpty);
	Gura_AssignFunction(DynamicLibrary);
	Gura_AssignMethod(wx_DynamicLibrary, CanonicalizeName);
	Gura_AssignMethod(wx_DynamicLibrary, CanonicalizePluginName);
	Gura_AssignMethod(wx_DynamicLibrary, Detach);
	Gura_AssignMethod(wx_DynamicLibrary, GetSymbol);
	Gura_AssignMethod(wx_DynamicLibrary, GetSymbolAorW);
	Gura_AssignMethod(wx_DynamicLibrary, GetProgramHandle);
	Gura_AssignMethod(wx_DynamicLibrary, HasSymbol);
	Gura_AssignMethod(wx_DynamicLibrary, IsLoaded);
	Gura_AssignMethod(wx_DynamicLibrary, ListLoaded);
	Gura_AssignMethod(wx_DynamicLibrary, Load);
	Gura_AssignMethod(wx_DynamicLibrary, Unload);
	Gura_AssignMethod(wx_DynamicLibrary, Unload_1);
}

Gura_ImplementDescendantCreator(wx_DynamicLibrary)
{
	return new Object_wx_DynamicLibrary((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
