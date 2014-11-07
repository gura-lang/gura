//----------------------------------------------------------------------------
// wxGridCellAutoWrapStringRenderer
// extracted from gridrend.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_GridCellAutoWrapStringRenderer: public wxGridCellAutoWrapStringRenderer, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_GridCellAutoWrapStringRenderer *_pObj;
public:
	inline wx_GridCellAutoWrapStringRenderer() : wxGridCellAutoWrapStringRenderer(), _sig(NULL), _pObj(NULL) {}
	~wx_GridCellAutoWrapStringRenderer();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_GridCellAutoWrapStringRenderer *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_GridCellAutoWrapStringRenderer::~wx_GridCellAutoWrapStringRenderer()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_GridCellAutoWrapStringRenderer::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxGridCellAutoWrapStringRenderer
//----------------------------------------------------------------------------
Gura_DeclareFunction(GridCellAutoWrapStringRenderer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_GridCellAutoWrapStringRenderer));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GridCellAutoWrapStringRenderer)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_GridCellAutoWrapStringRenderer *pEntity = new wx_GridCellAutoWrapStringRenderer();
	Object_wx_GridCellAutoWrapStringRenderer *pObj = Object_wx_GridCellAutoWrapStringRenderer::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_GridCellAutoWrapStringRenderer(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

//----------------------------------------------------------------------------
// Object implementation for wxGridCellAutoWrapStringRenderer
//----------------------------------------------------------------------------
Object_wx_GridCellAutoWrapStringRenderer::~Object_wx_GridCellAutoWrapStringRenderer()
{
}

Object *Object_wx_GridCellAutoWrapStringRenderer::Clone() const
{
	return NULL;
}

String Object_wx_GridCellAutoWrapStringRenderer::ToString(bool exprFlag)
{
	String rtn("<wx.GridCellAutoWrapStringRenderer:");
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
// Class implementation for wxGridCellAutoWrapStringRenderer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridCellAutoWrapStringRenderer)
{
	Gura_AssignFunction(GridCellAutoWrapStringRenderer);
}

Gura_ImplementDescendantCreator(wx_GridCellAutoWrapStringRenderer)
{
	return new Object_wx_GridCellAutoWrapStringRenderer((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
