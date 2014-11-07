//----------------------------------------------------------------------------
// wxGridCellNumberRenderer
// extracted from gridrend.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_GridCellNumberRenderer: public wxGridCellNumberRenderer, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_GridCellNumberRenderer *_pObj;
public:
	inline wx_GridCellNumberRenderer() : wxGridCellNumberRenderer(), _sig(NULL), _pObj(NULL) {}
	~wx_GridCellNumberRenderer();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_GridCellNumberRenderer *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_GridCellNumberRenderer::~wx_GridCellNumberRenderer()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_GridCellNumberRenderer::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxGridCellNumberRenderer
//----------------------------------------------------------------------------
Gura_DeclareFunction(GridCellNumberRenderer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_GridCellNumberRenderer));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GridCellNumberRenderer)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_GridCellNumberRenderer *pEntity = new wx_GridCellNumberRenderer();
	Object_wx_GridCellNumberRenderer *pObj = Object_wx_GridCellNumberRenderer::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_GridCellNumberRenderer(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

//----------------------------------------------------------------------------
// Object implementation for wxGridCellNumberRenderer
//----------------------------------------------------------------------------
Object_wx_GridCellNumberRenderer::~Object_wx_GridCellNumberRenderer()
{
}

Object *Object_wx_GridCellNumberRenderer::Clone() const
{
	return NULL;
}

String Object_wx_GridCellNumberRenderer::ToString(bool exprFlag)
{
	String rtn("<wx.GridCellNumberRenderer:");
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
// Class implementation for wxGridCellNumberRenderer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridCellNumberRenderer)
{
	Gura_AssignFunction(GridCellNumberRenderer);
}

Gura_ImplementDescendantCreator(wx_GridCellNumberRenderer)
{
	return new Object_wx_GridCellNumberRenderer((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
