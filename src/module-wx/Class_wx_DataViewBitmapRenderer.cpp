//----------------------------------------------------------------------------
// wxDataViewBitmapRenderer
// extracted from dataviewrenderer.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_DataViewBitmapRenderer: public wxDataViewBitmapRenderer, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_DataViewBitmapRenderer *_pObj;
public:
	inline wx_DataViewBitmapRenderer(const wxString& varianttype, wxDataViewCellMode mode) : wxDataViewBitmapRenderer(varianttype, mode), _sig(nullptr), _pObj(nullptr) {}
	~wx_DataViewBitmapRenderer();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_DataViewBitmapRenderer *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_DataViewBitmapRenderer::~wx_DataViewBitmapRenderer()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_DataViewBitmapRenderer::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxDataViewBitmapRenderer
//----------------------------------------------------------------------------
Gura_DeclareFunction(DataViewBitmapRenderer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_DataViewBitmapRenderer));
	DeclareArg(env, "varianttype", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "mode", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(DataViewBitmapRenderer)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxString varianttype = wxT("wxBitmap");
	if (args.IsValid(0)) varianttype = wxString::FromUTF8(args.GetString(0));
	wxDataViewCellMode mode = wxDATAVIEW_CELL_INERT;
	if (args.IsValid(1)) mode = static_cast<wxDataViewCellMode>(args.GetInt(1));
	wx_DataViewBitmapRenderer *pEntity = new wx_DataViewBitmapRenderer(varianttype, mode);
	Object_wx_DataViewBitmapRenderer *pObj = Object_wx_DataViewBitmapRenderer::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_DataViewBitmapRenderer(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

//----------------------------------------------------------------------------
// Object implementation for wxDataViewBitmapRenderer
//----------------------------------------------------------------------------
Object_wx_DataViewBitmapRenderer::~Object_wx_DataViewBitmapRenderer()
{
}

Object *Object_wx_DataViewBitmapRenderer::Clone() const
{
	return nullptr;
}

String Object_wx_DataViewBitmapRenderer::ToString(bool exprFlag)
{
	String rtn("<wx.DataViewBitmapRenderer:");
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
// Class implementation for wxDataViewBitmapRenderer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DataViewBitmapRenderer)
{
	Gura_AssignFunction(DataViewBitmapRenderer);
}

Gura_ImplementDescendantCreator(wx_DataViewBitmapRenderer)
{
	return new Object_wx_DataViewBitmapRenderer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
