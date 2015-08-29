//----------------------------------------------------------------------------
// wxDataViewTextRenderer
// extracted from dataviewrenderer.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_DataViewTextRenderer: public wxDataViewTextRenderer, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_DataViewTextRenderer *_pObj;
public:
	inline wx_DataViewTextRenderer(const wxString& varianttype, wxDataViewCellMode mode) : wxDataViewTextRenderer(varianttype, mode), _pObj(nullptr) {}
	~wx_DataViewTextRenderer();
	inline void AssocWithGura(Object_wx_DataViewTextRenderer *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_DataViewTextRenderer::~wx_DataViewTextRenderer()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_DataViewTextRenderer::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxDataViewTextRenderer
//----------------------------------------------------------------------------
Gura_DeclareFunction(DataViewTextRenderer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_DataViewTextRenderer));
	DeclareArg(env, "varianttype", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "mode", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(DataViewTextRenderer)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxString varianttype = wxT("string");
	if (arg.IsValid(0)) varianttype = wxString::FromUTF8(arg.GetString(0));
	wxDataViewCellMode mode = wxDATAVIEW_CELL_INERT;
	if (arg.IsValid(1)) mode = static_cast<wxDataViewCellMode>(arg.GetInt(1));
	wx_DataViewTextRenderer *pEntity = new wx_DataViewTextRenderer(varianttype, mode);
	Object_wx_DataViewTextRenderer *pObj = Object_wx_DataViewTextRenderer::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_DataViewTextRenderer(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

//----------------------------------------------------------------------------
// Object implementation for wxDataViewTextRenderer
//----------------------------------------------------------------------------
Object_wx_DataViewTextRenderer::~Object_wx_DataViewTextRenderer()
{
}

Object *Object_wx_DataViewTextRenderer::Clone() const
{
	return nullptr;
}

String Object_wx_DataViewTextRenderer::ToString(bool exprFlag)
{
	String rtn("<wx.DataViewTextRenderer:");
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
// Class implementation for wxDataViewTextRenderer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DataViewTextRenderer)
{
	Gura_AssignFunction(DataViewTextRenderer);
}

Gura_ImplementDescendantCreator(wx_DataViewTextRenderer)
{
	return new Object_wx_DataViewTextRenderer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
