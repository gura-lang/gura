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
	if (!CheckWxReady(sig)) return Value::Null;
	wxString varianttype = wxT("datetime");
	if (args.IsValid(0)) varianttype = wxString::FromUTF8(args.GetString(0));
	wxDataViewCellMode mode = wxDATAVIEW_CELL_ACTIVATABLE;
	if (args.IsValid(1)) mode = static_cast<wxDataViewCellMode>(args.GetInt(1));
	wx_DataViewDateRenderer *pEntity = new wx_DataViewDateRenderer(varianttype, mode);
	Object_wx_DataViewDateRenderer *pObj = Object_wx_DataViewDateRenderer::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_DataViewDateRenderer(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
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
