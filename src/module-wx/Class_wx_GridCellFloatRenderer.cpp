//----------------------------------------------------------------------------
// wxGridCellFloatRenderer
// extracted from gridrend.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_GridCellFloatRenderer: public wxGridCellFloatRenderer, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_GridCellFloatRenderer *_pObj;
public:
	inline wx_GridCellFloatRenderer(int width, int precision) : wxGridCellFloatRenderer(width, precision), _pObj(nullptr) {}
	~wx_GridCellFloatRenderer();
	inline void AssocWithGura(Object_wx_GridCellFloatRenderer *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_GridCellFloatRenderer::~wx_GridCellFloatRenderer()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_GridCellFloatRenderer::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxGridCellFloatRenderer
//----------------------------------------------------------------------------
Gura_DeclareFunction(GridCellFloatRenderer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_GridCellFloatRenderer));
	DeclareArg(env, "width", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "precision", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GridCellFloatRenderer)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	int width = -1;
	if (args.IsValid(0)) width = args.GetInt(0);
	int precision = -1;
	if (args.IsValid(1)) precision = args.GetInt(1);
	wx_GridCellFloatRenderer *pEntity = new wx_GridCellFloatRenderer(width, precision);
	Object_wx_GridCellFloatRenderer *pObj = Object_wx_GridCellFloatRenderer::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_GridCellFloatRenderer(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareMethod(wx_GridCellFloatRenderer, GetPrecision)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridCellFloatRenderer, GetPrecision)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridCellFloatRenderer *pThis = Object_wx_GridCellFloatRenderer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetPrecision();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_GridCellFloatRenderer, GetWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridCellFloatRenderer, GetWidth)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridCellFloatRenderer *pThis = Object_wx_GridCellFloatRenderer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetWidth();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_GridCellFloatRenderer, SetParameters)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "params", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellFloatRenderer, SetParameters)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridCellFloatRenderer *pThis = Object_wx_GridCellFloatRenderer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString params = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetParameters(params);
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridCellFloatRenderer, SetPrecision)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "precision", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellFloatRenderer, SetPrecision)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridCellFloatRenderer *pThis = Object_wx_GridCellFloatRenderer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int precision = args.GetInt(0);
	pThis->GetEntity()->SetPrecision(precision);
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridCellFloatRenderer, SetWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellFloatRenderer, SetWidth)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridCellFloatRenderer *pThis = Object_wx_GridCellFloatRenderer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int width = args.GetInt(0);
	pThis->GetEntity()->SetWidth(width);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxGridCellFloatRenderer
//----------------------------------------------------------------------------
Object_wx_GridCellFloatRenderer::~Object_wx_GridCellFloatRenderer()
{
}

Object *Object_wx_GridCellFloatRenderer::Clone() const
{
	return nullptr;
}

String Object_wx_GridCellFloatRenderer::ToString(bool exprFlag)
{
	String rtn("<wx.GridCellFloatRenderer:");
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
// Class implementation for wxGridCellFloatRenderer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridCellFloatRenderer)
{
	Gura_AssignFunction(GridCellFloatRenderer);
	Gura_AssignMethod(wx_GridCellFloatRenderer, GetPrecision);
	Gura_AssignMethod(wx_GridCellFloatRenderer, GetWidth);
	Gura_AssignMethod(wx_GridCellFloatRenderer, SetParameters);
	Gura_AssignMethod(wx_GridCellFloatRenderer, SetPrecision);
	Gura_AssignMethod(wx_GridCellFloatRenderer, SetWidth);
}

Gura_ImplementDescendantCreator(wx_GridCellFloatRenderer)
{
	return new Object_wx_GridCellFloatRenderer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
