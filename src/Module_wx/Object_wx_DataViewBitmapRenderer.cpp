//----------------------------------------------------------------------------
// wxDataViewBitmapRenderer
// extracted from dataviewrenderer.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_DataViewBitmapRenderer: public wxDataViewBitmapRenderer, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_DataViewBitmapRenderer *_pObj;
public:
	inline wx_DataViewBitmapRenderer(const wxString& varianttype, wxDataViewCellMode mode) : wxDataViewBitmapRenderer(varianttype, mode), _sig(NULL), _pObj(NULL) {}
	~wx_DataViewBitmapRenderer();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_DataViewBitmapRenderer *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_DataViewBitmapRenderer::~wx_DataViewBitmapRenderer()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_DataViewBitmapRenderer::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxDataViewBitmapRenderer
//----------------------------------------------------------------------------
Gura_DeclareFunction(DataViewBitmapRenderer)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_DataViewBitmapRenderer));
	DeclareArg(env, "varianttype", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "mode", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(DataViewBitmapRenderer)
{
	wxString varianttype = wxT("wxBitmap");
	if (args.IsValid(0)) varianttype = wxString::FromUTF8(args.GetString(0));
	wxDataViewCellMode mode = wxDATAVIEW_CELL_INERT;
	if (args.IsValid(1)) mode = static_cast<wxDataViewCellMode>(args.GetInt(1));
	wx_DataViewBitmapRenderer *pEntity = new wx_DataViewBitmapRenderer(varianttype, mode);
	Object_wx_DataViewBitmapRenderer *pObj = Object_wx_DataViewBitmapRenderer::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_DataViewBitmapRenderer(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

//----------------------------------------------------------------------------
// Object implementation for wxDataViewBitmapRenderer
//----------------------------------------------------------------------------
Object_wx_DataViewBitmapRenderer::~Object_wx_DataViewBitmapRenderer()
{
}

Object *Object_wx_DataViewBitmapRenderer::Clone() const
{
	return NULL;
}

String Object_wx_DataViewBitmapRenderer::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.DataViewBitmapRenderer:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_DataViewBitmapRenderer::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(DataViewBitmapRenderer);
}

//----------------------------------------------------------------------------
// Class implementation for wxDataViewBitmapRenderer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DataViewBitmapRenderer)
{
}

Gura_ImplementDescendantCreator(wx_DataViewBitmapRenderer)
{
	return new Object_wx_DataViewBitmapRenderer((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
