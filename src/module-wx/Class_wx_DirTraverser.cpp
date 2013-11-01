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
	Gura::Signal _sig;
	Object_wx_DirTraverser *_pObj;
public:
	//virtual wxDirTraverseResult OnDir(const wxString& dirname);
	//virtual wxDirTraverseResult OnFile(const wxString& filename);
	//virtual wxDirTraverseResult OnOpenError(const wxString& openerrorname);
	~wx_DirTraverser();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_DirTraverser *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_DirTraverser::~wx_DirTraverser()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_DirTraverser::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxDirTraverser
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_DirTraverser, OnDir)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "dirname", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DirTraverser, OnDir)
{
	Object_wx_DirTraverser *pThis = Object_wx_DirTraverser::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString dirname = wxString::FromUTF8(args.GetString(0));
	wxDirTraverseResult rtn = pThis->GetEntity()->OnDir(dirname);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DirTraverser, OnFile)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "filename", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DirTraverser, OnFile)
{
	Object_wx_DirTraverser *pThis = Object_wx_DirTraverser::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString filename = wxString::FromUTF8(args.GetString(0));
	wxDirTraverseResult rtn = pThis->GetEntity()->OnFile(filename);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DirTraverser, OnOpenError)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "openerrorname", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DirTraverser, OnOpenError)
{
	Object_wx_DirTraverser *pThis = Object_wx_DirTraverser::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString openerrorname = wxString::FromUTF8(args.GetString(0));
	wxDirTraverseResult rtn = pThis->GetEntity()->OnOpenError(openerrorname);
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxDirTraverser
//----------------------------------------------------------------------------
Object_wx_DirTraverser::~Object_wx_DirTraverser()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_DirTraverser::Clone() const
{
	return NULL;
}

String Object_wx_DirTraverser::ToString(bool exprFlag)
{
	String rtn("<wx.DirTraverser:");
	if (GetEntity() == NULL) {
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
	return new Object_wx_DirTraverser((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
