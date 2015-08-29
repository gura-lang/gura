//----------------------------------------------------------------------------
// wxDataViewDateRenderer
// extracted from dataviewrenderer.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_DataViewDateRenderer: public wxDataViewDateRenderer, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_DataViewDateRenderer *_pObj;
public:
	inline wx_DataViewDateRenderer(const wxString& varianttype, wxDataViewCellMode mode) : wxDataViewDateRenderer(varianttype, mode), _pObj(nullptr) {}
	~wx_DataViewDateRenderer();
	inline void AssocWithGura(Object_wx_DataViewDateRenderer *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_DataViewDateRenderer::~wx_DataViewDateRenderer()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_DataViewDateRenderer::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxDataViewDateRenderer
//----------------------------------------------------------------------------
Gura_DeclareFunction(DataViewDateRenderer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_DataViewDateRenderer));
	DeclareArg(env, "varianttype", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "mode", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(DataViewDateRenderer)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxString varianttype = wxT("datetime");
	if (arg.IsValid(0)) varianttype = wxString::FromUTF8(arg.GetString(0));
	wxDataViewCellMode mode = wxDATAVIEW_CELL_ACTIVATABLE;
	if (arg.IsValid(1)) mode = static_cast<wxDataViewCellMode>(arg.GetInt(1));
	wx_DataViewDateRenderer *pEntity = new wx_DataViewDateRenderer(varianttype, mode);
	Object_wx_DataViewDateRenderer *pObj = Object_wx_DataViewDateRenderer::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_DataViewDateRenderer(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

//----------------------------------------------------------------------------
// Object implementation for wxDataViewDateRenderer
//----------------------------------------------------------------------------
Object_wx_DataViewDateRenderer::~Object_wx_DataViewDateRenderer()
{
}

Object *Object_wx_DataViewDateRenderer::Clone() const
{
	return nullptr;
}

String Object_wx_DataViewDateRenderer::ToString(bool exprFlag)
{
	String rtn("<wx.DataViewDateRenderer:");
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
// Class implementation for wxDataViewDateRenderer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DataViewDateRenderer)
{
	Gura_AssignFunction(DataViewDateRenderer);
}

Gura_ImplementDescendantCreator(wx_DataViewDateRenderer)
{
	return new Object_wx_DataViewDateRenderer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
