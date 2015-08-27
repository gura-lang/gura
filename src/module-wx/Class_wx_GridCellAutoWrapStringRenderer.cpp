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
	//Gura::Signal *_pSig;
	Object_wx_GridCellAutoWrapStringRenderer *_pObj;
public:
	inline wx_GridCellAutoWrapStringRenderer() : wxGridCellAutoWrapStringRenderer(), _pObj(nullptr) {}
	~wx_GridCellAutoWrapStringRenderer();
	inline void AssocWithGura(Object_wx_GridCellAutoWrapStringRenderer *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_GridCellAutoWrapStringRenderer::~wx_GridCellAutoWrapStringRenderer()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_GridCellAutoWrapStringRenderer::GuraObjectDeleted()
{
	_pObj = nullptr;
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
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_GridCellAutoWrapStringRenderer *pEntity = new wx_GridCellAutoWrapStringRenderer();
	Object_wx_GridCellAutoWrapStringRenderer *pObj = Object_wx_GridCellAutoWrapStringRenderer::GetObjectThis(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_GridCellAutoWrapStringRenderer(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
}

//----------------------------------------------------------------------------
// Object implementation for wxGridCellAutoWrapStringRenderer
//----------------------------------------------------------------------------
Object_wx_GridCellAutoWrapStringRenderer::~Object_wx_GridCellAutoWrapStringRenderer()
{
}

Object *Object_wx_GridCellAutoWrapStringRenderer::Clone() const
{
	return nullptr;
}

String Object_wx_GridCellAutoWrapStringRenderer::ToString(bool exprFlag)
{
	String rtn("<wx.GridCellAutoWrapStringRenderer:");
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
// Class implementation for wxGridCellAutoWrapStringRenderer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridCellAutoWrapStringRenderer)
{
	Gura_AssignFunction(GridCellAutoWrapStringRenderer);
}

Gura_ImplementDescendantCreator(wx_GridCellAutoWrapStringRenderer)
{
	return new Object_wx_GridCellAutoWrapStringRenderer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
