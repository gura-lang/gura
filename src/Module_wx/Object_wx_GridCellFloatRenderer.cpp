//----------------------------------------------------------------------------
// wxGridCellFloatRenderer
// extracted from gridrend.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_GridCellFloatRenderer: public wxGridCellFloatRenderer, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_GridCellFloatRenderer *_pObj;
public:
	inline wx_GridCellFloatRenderer(int width, int precision) : wxGridCellFloatRenderer(width, precision), _sig(NULL), _pObj(NULL) {}
	~wx_GridCellFloatRenderer();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_GridCellFloatRenderer *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_GridCellFloatRenderer::~wx_GridCellFloatRenderer()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_GridCellFloatRenderer::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxGridCellFloatRenderer
//----------------------------------------------------------------------------
Gura_DeclareFunction(GridCellFloatRenderer)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_GridCellFloatRenderer));
	DeclareArg(env, "width", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "precision", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GridCellFloatRenderer)
{
	if (!CheckWxReady(sig)) return Value::Null;
	int width = -1;
	if (args.IsValid(0)) width = args.GetInt(0);
	int precision = -1;
	if (args.IsValid(1)) precision = args.GetInt(1);
	wx_GridCellFloatRenderer *pEntity = new wx_GridCellFloatRenderer(width, precision);
	Object_wx_GridCellFloatRenderer *pObj = Object_wx_GridCellFloatRenderer::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_GridCellFloatRenderer(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_GridCellFloatRenderer, GetPrecision)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridCellFloatRenderer, GetPrecision)
{
	Object_wx_GridCellFloatRenderer *pThis = Object_wx_GridCellFloatRenderer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetPrecision();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_GridCellFloatRenderer, GetWidth)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridCellFloatRenderer, GetWidth)
{
	Object_wx_GridCellFloatRenderer *pThis = Object_wx_GridCellFloatRenderer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetWidth();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_GridCellFloatRenderer, SetParameters)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "params", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellFloatRenderer, SetParameters)
{
	Object_wx_GridCellFloatRenderer *pThis = Object_wx_GridCellFloatRenderer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString params = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetParameters(params);
	return Value::Null;
}

Gura_DeclareMethod(wx_GridCellFloatRenderer, SetPrecision)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "precision", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellFloatRenderer, SetPrecision)
{
	Object_wx_GridCellFloatRenderer *pThis = Object_wx_GridCellFloatRenderer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int precision = args.GetInt(0);
	pThis->GetEntity()->SetPrecision(precision);
	return Value::Null;
}

Gura_DeclareMethod(wx_GridCellFloatRenderer, SetWidth)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellFloatRenderer, SetWidth)
{
	Object_wx_GridCellFloatRenderer *pThis = Object_wx_GridCellFloatRenderer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int width = args.GetInt(0);
	pThis->GetEntity()->SetWidth(width);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxGridCellFloatRenderer
//----------------------------------------------------------------------------
Object_wx_GridCellFloatRenderer::~Object_wx_GridCellFloatRenderer()
{
}

Object *Object_wx_GridCellFloatRenderer::Clone() const
{
	return NULL;
}

String Object_wx_GridCellFloatRenderer::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.GridCellFloatRenderer:");
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
	return new Object_wx_GridCellFloatRenderer((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
