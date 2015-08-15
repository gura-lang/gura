//----------------------------------------------------------------------------
// wxPostScriptDC
// extracted from postscpt.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_PostScriptDC: public wxPostScriptDC, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_PostScriptDC *_pObj;
public:
	inline wx_PostScriptDC(const wxPrintData& printData) : wxPostScriptDC(printData), _pObj(nullptr) {}
	inline wx_PostScriptDC(const wxString& output, bool interactive, wxWindow * parent) : wxPostScriptDC(output, interactive, parent), _pObj(nullptr) {}
	~wx_PostScriptDC();
	inline void AssocWithGura(Object_wx_PostScriptDC *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_PostScriptDC::~wx_PostScriptDC()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_PostScriptDC::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxPostScriptDC
//----------------------------------------------------------------------------
Gura_DeclareFunction(PostScriptDC)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_PostScriptDC));
	DeclareArg(env, "printData", VTYPE_wx_PrintData, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(PostScriptDC)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxPrintData *printData = Object_wx_PrintData::GetObject(args, 0)->GetEntity();
	wx_PostScriptDC *pEntity = new wx_PostScriptDC(*printData);
	Object_wx_PostScriptDC *pObj = Object_wx_PostScriptDC::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_PostScriptDC(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareFunction(PostScriptDC_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_PostScriptDC));
	DeclareArg(env, "output", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "interactive", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(PostScriptDC_1)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxString output = wxString::FromUTF8(args.GetString(0));
	bool interactive = true;
	if (args.IsValid(1)) interactive = args.GetBoolean(1);
	wxWindow *parent = Object_wx_Window::GetObject(args, 2)->GetEntity();
	wx_PostScriptDC *pEntity = new wx_PostScriptDC(output, interactive, parent);
	Object_wx_PostScriptDC *pObj = Object_wx_PostScriptDC::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_PostScriptDC(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareClassMethod(wx_PostScriptDC, SetResolution)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "ppi", VTYPE_number, OCCUR_Once);
}

Gura_ImplementClassMethod(wx_PostScriptDC, SetResolution)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	int ppi = args.GetInt(0);
	wxPostScriptDC::SetResolution(ppi);
	return Value::Nil;
}

Gura_DeclareClassMethod(wx_PostScriptDC, GetResolution)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_PostScriptDC, GetResolution)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	int rtn = wxPostScriptDC::GetResolution();
	return ReturnValue(env, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxPostScriptDC
//----------------------------------------------------------------------------
Object_wx_PostScriptDC::~Object_wx_PostScriptDC()
{
}

Object *Object_wx_PostScriptDC::Clone() const
{
	return nullptr;
}

String Object_wx_PostScriptDC::ToString(bool exprFlag)
{
	String rtn("<wx.PostScriptDC:");
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
// Class implementation for wxPostScriptDC
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PostScriptDC)
{
	Gura_AssignFunction(PostScriptDC);
	Gura_AssignFunction(PostScriptDC_1);
	Gura_AssignMethod(wx_PostScriptDC, SetResolution);
	Gura_AssignMethod(wx_PostScriptDC, GetResolution);
}

Gura_ImplementDescendantCreator(wx_PostScriptDC)
{
	return new Object_wx_PostScriptDC((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
