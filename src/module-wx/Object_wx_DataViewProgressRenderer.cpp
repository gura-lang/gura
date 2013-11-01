//----------------------------------------------------------------------------
// wxDataViewProgressRenderer
// extracted from dataviewrenderer.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_DataViewProgressRenderer: public wxDataViewProgressRenderer, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_DataViewProgressRenderer *_pObj;
public:
	inline wx_DataViewProgressRenderer(const wxString& label, const wxString& varianttype, wxDataViewCellMode mode) : wxDataViewProgressRenderer(label, varianttype, mode), _sig(NULL), _pObj(NULL) {}
	~wx_DataViewProgressRenderer();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_DataViewProgressRenderer *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_DataViewProgressRenderer::~wx_DataViewProgressRenderer()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_DataViewProgressRenderer::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxDataViewProgressRenderer
//----------------------------------------------------------------------------
Gura_DeclareFunction(DataViewProgressRenderer)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_DataViewProgressRenderer));
	DeclareArg(env, "label", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "varianttype", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "mode", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(DataViewProgressRenderer)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxString label = wxEmptyString;
	if (args.IsValid(0)) label = wxString::FromUTF8(args.GetString(0));
	wxString varianttype = wxT("long");
	if (args.IsValid(1)) varianttype = wxString::FromUTF8(args.GetString(1));
	wxDataViewCellMode mode = wxDATAVIEW_CELL_INERT;
	if (args.IsValid(2)) mode = static_cast<wxDataViewCellMode>(args.GetInt(2));
	wx_DataViewProgressRenderer *pEntity = new wx_DataViewProgressRenderer(label, varianttype, mode);
	Object_wx_DataViewProgressRenderer *pObj = Object_wx_DataViewProgressRenderer::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_DataViewProgressRenderer(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

//----------------------------------------------------------------------------
// Object implementation for wxDataViewProgressRenderer
//----------------------------------------------------------------------------
Object_wx_DataViewProgressRenderer::~Object_wx_DataViewProgressRenderer()
{
}

Object *Object_wx_DataViewProgressRenderer::Clone() const
{
	return NULL;
}

String Object_wx_DataViewProgressRenderer::ToString(bool exprFlag)
{
	String rtn("<wx.DataViewProgressRenderer:");
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
// Class implementation for wxDataViewProgressRenderer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DataViewProgressRenderer)
{
	Gura_AssignFunction(DataViewProgressRenderer);
}

Gura_ImplementDescendantCreator(wx_DataViewProgressRenderer)
{
	return new Object_wx_DataViewProgressRenderer((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
