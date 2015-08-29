//----------------------------------------------------------------------------
// wxDirTraverser
// extracted from dirtrav.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

Gura_DeclarePrivUserSymbol(OnDir);
Gura_DeclarePrivUserSymbol(OnFile);
Gura_DeclarePrivUserSymbol(OnOpenError);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_DirTraverser: public wxDirTraverser, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_DirTraverser *_pObj;
public:
	//virtual wxDirTraverseResult OnDir(const wxString& dirname);
	//virtual wxDirTraverseResult OnFile(const wxString& filename);
	//virtual wxDirTraverseResult OnOpenError(const wxString& openerrorname);
	~wx_DirTraverser();
	inline void AssocWithGura(Object_wx_DirTraverser *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_DirTraverser::~wx_DirTraverser()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_DirTraverser::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxDirTraverser
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_DirTraverser, OnDir)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "dirname", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DirTraverser, OnDir)
{
	Signal &sig = env.GetSignal();
	Object_wx_DirTraverser *pThis = Object_wx_DirTraverser::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString dirname = wxString::FromUTF8(arg.GetString(0));
	wxDirTraverseResult rtn = pThis->GetEntity()->OnDir(dirname);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_DirTraverser, OnFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "filename", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DirTraverser, OnFile)
{
	Signal &sig = env.GetSignal();
	Object_wx_DirTraverser *pThis = Object_wx_DirTraverser::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString filename = wxString::FromUTF8(arg.GetString(0));
	wxDirTraverseResult rtn = pThis->GetEntity()->OnFile(filename);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_DirTraverser, OnOpenError)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "openerrorname", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DirTraverser, OnOpenError)
{
	Signal &sig = env.GetSignal();
	Object_wx_DirTraverser *pThis = Object_wx_DirTraverser::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString openerrorname = wxString::FromUTF8(arg.GetString(0));
	wxDirTraverseResult rtn = pThis->GetEntity()->OnOpenError(openerrorname);
	return ReturnValue(env, arg, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxDirTraverser
//----------------------------------------------------------------------------
Object_wx_DirTraverser::~Object_wx_DirTraverser()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_DirTraverser::Clone() const
{
	return nullptr;
}

String Object_wx_DirTraverser::ToString(bool exprFlag)
{
	String rtn("<wx.DirTraverser:");
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
// Class implementation for wxDirTraverser
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DirTraverser)
{
	Gura_RealizeUserSymbol(OnDir);
	Gura_RealizeUserSymbol(OnFile);
	Gura_RealizeUserSymbol(OnOpenError);
	Gura_AssignMethod(wx_DirTraverser, OnDir);
	Gura_AssignMethod(wx_DirTraverser, OnFile);
	Gura_AssignMethod(wx_DirTraverser, OnOpenError);
}

Gura_ImplementDescendantCreator(wx_DirTraverser)
{
	return new Object_wx_DirTraverser((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
