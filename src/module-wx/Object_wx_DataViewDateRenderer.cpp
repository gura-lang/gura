//----------------------------------------------------------------------------
// wxDataViewDateRenderer
// extracted from dataviewrenderer.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_DataViewDateRenderer: public wxDataViewDateRenderer, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_DataViewDateRenderer *_pObj;
public:
	inline wx_DataViewDateRenderer(const wxString& varianttype, wxDataViewCellMode mode) : wxDataViewDateRenderer(varianttype, mode), _sig(NULL), _pObj(NULL) {}
	~wx_DataViewDateRenderer();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_DataViewDateRenderer *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_DataViewDateRenderer::~wx_DataViewDateRenderer()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_DataViewDateRenderer::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxDataViewDateRenderer
//----------------------------------------------------------------------------
Gura_DeclareFunction(DataViewDateRenderer)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
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
	if (pObj == NULL) {
		pObj = new Object_wx_DataViewDateRenderer(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

//----------------------------------------------------------------------------
// Object implementation for wxDataViewDateRenderer
//----------------------------------------------------------------------------
Object_wx_DataViewDateRenderer::~Object_wx_DataViewDateRenderer()
{
}

Object *Object_wx_DataViewDateRenderer::Clone() const
{
	return NULL;
}

String Object_wx_DataViewDateRenderer::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.DataViewDateRenderer:");
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
// Class implementation for wxDataViewDateRenderer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DataViewDateRenderer)
{
	Gura_AssignFunction(DataViewDateRenderer);
}

Gura_ImplementDescendantCreator(wx_DataViewDateRenderer)
{
	return new Object_wx_DataViewDateRenderer((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
