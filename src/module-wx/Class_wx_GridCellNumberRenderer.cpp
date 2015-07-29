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
	//Gura::Signal *_pSig;
	Object_wx_GridCellNumberRenderer *_pObj;
public:
	inline wx_GridCellNumberRenderer() : wxGridCellNumberRenderer(), _pObj(nullptr) {}
	~wx_GridCellNumberRenderer();
	inline void AssocWithGura(Object_wx_GridCellNumberRenderer *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_GridCellNumberRenderer::~wx_GridCellNumberRenderer()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_GridCellNumberRenderer::GuraObjectDeleted()
{
	_pObj = nullptr;
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
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wx_GridCellNumberRenderer *pEntity = new wx_GridCellNumberRenderer();
	Object_wx_GridCellNumberRenderer *pObj = Object_wx_GridCellNumberRenderer::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_GridCellNumberRenderer(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

//----------------------------------------------------------------------------
// Object implementation for wxGridCellNumberRenderer
//----------------------------------------------------------------------------
Object_wx_GridCellNumberRenderer::~Object_wx_GridCellNumberRenderer()
{
}

Object *Object_wx_GridCellNumberRenderer::Clone() const
{
	return nullptr;
}

String Object_wx_GridCellNumberRenderer::ToString(bool exprFlag)
{
	String rtn("<wx.GridCellNumberRenderer:");
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
// Class implementation for wxGridCellNumberRenderer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridCellNumberRenderer)
{
	Gura_AssignFunction(GridCellNumberRenderer);
}

Gura_ImplementDescendantCreator(wx_GridCellNumberRenderer)
{
	return new Object_wx_GridCellNumberRenderer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
