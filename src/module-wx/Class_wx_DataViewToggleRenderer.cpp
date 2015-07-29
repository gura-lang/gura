//----------------------------------------------------------------------------
// wxDataViewToggleRenderer
// extracted from dataviewrenderer.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_DataViewToggleRenderer: public wxDataViewToggleRenderer, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_DataViewToggleRenderer *_pObj;
public:
	inline wx_DataViewToggleRenderer(const wxString& varianttype, wxDataViewCellMode mode) : wxDataViewToggleRenderer(varianttype, mode), _pObj(nullptr) {}
	~wx_DataViewToggleRenderer();
	inline void AssocWithGura(Object_wx_DataViewToggleRenderer *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_DataViewToggleRenderer::~wx_DataViewToggleRenderer()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_DataViewToggleRenderer::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxDataViewToggleRenderer
//----------------------------------------------------------------------------
Gura_DeclareFunction(DataViewToggleRenderer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_DataViewToggleRenderer));
	DeclareArg(env, "varianttype", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "mode", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(DataViewToggleRenderer)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxString varianttype = wxT("bool");
	if (args.IsValid(0)) varianttype = wxString::FromUTF8(args.GetString(0));
	wxDataViewCellMode mode = wxDATAVIEW_CELL_INERT;
	if (args.IsValid(1)) mode = static_cast<wxDataViewCellMode>(args.GetInt(1));
	wx_DataViewToggleRenderer *pEntity = new wx_DataViewToggleRenderer(varianttype, mode);
	Object_wx_DataViewToggleRenderer *pObj = Object_wx_DataViewToggleRenderer::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_DataViewToggleRenderer(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

//----------------------------------------------------------------------------
// Object implementation for wxDataViewToggleRenderer
//----------------------------------------------------------------------------
Object_wx_DataViewToggleRenderer::~Object_wx_DataViewToggleRenderer()
{
}

Object *Object_wx_DataViewToggleRenderer::Clone() const
{
	return nullptr;
}

String Object_wx_DataViewToggleRenderer::ToString(bool exprFlag)
{
	String rtn("<wx.DataViewToggleRenderer:");
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
// Class implementation for wxDataViewToggleRenderer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DataViewToggleRenderer)
{
	Gura_AssignFunction(DataViewToggleRenderer);
}

Gura_ImplementDescendantCreator(wx_DataViewToggleRenderer)
{
	return new Object_wx_DataViewToggleRenderer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
