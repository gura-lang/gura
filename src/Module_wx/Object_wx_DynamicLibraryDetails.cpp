//----------------------------------------------------------------------------
// wxDynamicLibraryDetails
// extracted from dynlib.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_DynamicLibraryDetails: public wxDynamicLibraryDetails, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_DynamicLibraryDetails *_pObj;
public:
	~wx_DynamicLibraryDetails();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_DynamicLibraryDetails *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_DynamicLibraryDetails::~wx_DynamicLibraryDetails()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_DynamicLibraryDetails::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxDynamicLibraryDetails
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_DynamicLibraryDetails, GetName)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DynamicLibraryDetails, GetName)
{
	Object_wx_DynamicLibraryDetails *pThis = Object_wx_DynamicLibraryDetails::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetName();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_DynamicLibraryDetails, GetPath)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DynamicLibraryDetails, GetPath)
{
	Object_wx_DynamicLibraryDetails *pThis = Object_wx_DynamicLibraryDetails::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetPath();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_DynamicLibraryDetails, GetAddress)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "addr", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "*len", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DynamicLibraryDetails, GetAddress)
{
#if 0
	Object_wx_DynamicLibraryDetails *pThis = Object_wx_DynamicLibraryDetails::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int addr = args.GetInt(0);
	size_t *len = args.GetSizeT(1);
	bool rtn = pThis->GetEntity()->GetAddress(addr, *len);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DynamicLibraryDetails, GetVersion)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DynamicLibraryDetails, GetVersion)
{
	Object_wx_DynamicLibraryDetails *pThis = Object_wx_DynamicLibraryDetails::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetVersion();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

//----------------------------------------------------------------------------
// Object implementation for wxDynamicLibraryDetails
//----------------------------------------------------------------------------
Object_wx_DynamicLibraryDetails::~Object_wx_DynamicLibraryDetails()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_DynamicLibraryDetails::Clone() const
{
	return NULL;
}

String Object_wx_DynamicLibraryDetails::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.DynamicLibraryDetails:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_DynamicLibraryDetails::OnModuleEntry(Environment &env, Signal sig)
{
}

//----------------------------------------------------------------------------
// Class implementation for wxDynamicLibraryDetails
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DynamicLibraryDetails)
{
	Gura_AssignMethod(wx_DynamicLibraryDetails, GetName);
	Gura_AssignMethod(wx_DynamicLibraryDetails, GetPath);
	Gura_AssignMethod(wx_DynamicLibraryDetails, GetAddress);
	Gura_AssignMethod(wx_DynamicLibraryDetails, GetVersion);
}

Gura_ImplementDescendantCreator(wx_DynamicLibraryDetails)
{
	return new Object_wx_DynamicLibraryDetails((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
