//----------------------------------------------------------------------------
// wxDataViewColumn
// extracted from dataviewcolumn.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_DataViewColumn: public wxDataViewColumn, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_DataViewColumn *_pObj;
public:
	inline wx_DataViewColumn(const wxString& title, wxDataViewRenderer* renderer, unsigned int model_column, int width, int flags) : wxDataViewColumn(title, renderer, model_column, width, flags), _pObj(nullptr) {}
	inline wx_DataViewColumn(const wxBitmap& bitmap, wxDataViewRenderer* renderer, unsigned int model_column, int width, int flags) : wxDataViewColumn(bitmap, renderer, model_column, width, flags), _pObj(nullptr) {}
	~wx_DataViewColumn();
	inline void AssocWithGura(Object_wx_DataViewColumn *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_DataViewColumn::~wx_DataViewColumn()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_DataViewColumn::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxDataViewColumn
//----------------------------------------------------------------------------
Gura_DeclareFunction(DataViewColumn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_DataViewColumn));
	DeclareArg(env, "title", VTYPE_any, OCCUR_Once);
	DeclareArg(env, "renderer", VTYPE_wx_DataViewRenderer, OCCUR_Once);
	DeclareArg(env, "model_column", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "width", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(DataViewColumn)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxDataViewRenderer *renderer = Object_wx_DataViewRenderer::GetObject(args, 1)->GetEntity();
	unsigned model_column = args.GetInt(2);
	int width = 80;
	if (args.IsValid(3)) width = args.GetInt(3);
	int flags = wxDATAVIEW_COL_RESIZABLE;
	if (args.IsValid(4)) flags = args.GetInt(4);
	wx_DataViewColumn *pEntity = nullptr;
	if (args.Is_string(0)) {
		wxString title = wxString::FromUTF8(args.GetString(0));
		pEntity = new wx_DataViewColumn(title, renderer, model_column, width, flags);
	} else if (args.IsInstanceOf(0, VTYPE_wx_Bitmap)) {
		wxBitmap *bitmap = Object_wx_Bitmap::GetObject(args, 0)->GetEntity();
		pEntity = new wx_DataViewColumn(*bitmap, renderer, model_column, width, flags);
	} else {
		SetError_ArgumentTypeByIndex(sig, args, 0);
		return Value::Null;
	}
	Object_wx_DataViewColumn *pObj = Object_wx_DataViewColumn::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_DataViewColumn(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareMethod(wx_DataViewColumn, GetBitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataViewColumn, GetBitmap)
{
	Object_wx_DataViewColumn *pThis = Object_wx_DataViewColumn::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	const wxBitmap &rtn = pThis->GetEntity()->GetBitmap();
	return ReturnValue(env, args, Value(new Object_wx_Bitmap(new wxBitmap(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_DataViewColumn, GetModelColumn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataViewColumn, GetModelColumn)
{
	Object_wx_DataViewColumn *pThis = Object_wx_DataViewColumn::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	unsigned rtn = pThis->GetEntity()->GetModelColumn();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_DataViewColumn, GetOwner)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataViewColumn, GetOwner)
{
	Object_wx_DataViewColumn *pThis = Object_wx_DataViewColumn::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDataViewCtrl *rtn = (wxDataViewCtrl *)pThis->GetEntity()->GetOwner();
	return ReturnValue(env, args, Value(new Object_wx_DataViewCtrl(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_DataViewColumn, GetRenderer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataViewColumn, GetRenderer)
{
	Object_wx_DataViewColumn *pThis = Object_wx_DataViewColumn::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDataViewRenderer *rtn = (wxDataViewRenderer *)pThis->GetEntity()->GetRenderer();
	return ReturnValue(env, args, Value(new Object_wx_DataViewRenderer(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_DataViewColumn, GetSortable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataViewColumn, GetSortable)
{
	Object_wx_DataViewColumn *pThis = Object_wx_DataViewColumn::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->GetSortable();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_DataViewColumn, GetWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataViewColumn, GetWidth)
{
	Object_wx_DataViewColumn *pThis = Object_wx_DataViewColumn::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetWidth();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_DataViewColumn, IsSortOrderAscending)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataViewColumn, IsSortOrderAscending)
{
	Object_wx_DataViewColumn *pThis = Object_wx_DataViewColumn::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsSortOrderAscending();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_DataViewColumn, SetAlignment)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "align", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewColumn, SetAlignment)
{
	Object_wx_DataViewColumn *pThis = Object_wx_DataViewColumn::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxAlignment align = static_cast<wxAlignment>(args.GetInt(0));
	pThis->GetEntity()->SetAlignment(align);
	return Value::Null;
}

Gura_DeclareMethod(wx_DataViewColumn, SetBitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "bitmap", VTYPE_wx_Bitmap, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewColumn, SetBitmap)
{
	Object_wx_DataViewColumn *pThis = Object_wx_DataViewColumn::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxBitmap *bitmap = Object_wx_Bitmap::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetBitmap(*bitmap);
	return Value::Null;
}

Gura_DeclareMethod(wx_DataViewColumn, SetSortOrder)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "ascending", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewColumn, SetSortOrder)
{
	Object_wx_DataViewColumn *pThis = Object_wx_DataViewColumn::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool ascending = args.GetBoolean(0);
	pThis->GetEntity()->SetSortOrder(ascending);
	return Value::Null;
}

Gura_DeclareMethod(wx_DataViewColumn, SetSortable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "sortable", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewColumn, SetSortable)
{
	Object_wx_DataViewColumn *pThis = Object_wx_DataViewColumn::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool sortable = args.GetBoolean(0);
	pThis->GetEntity()->SetSortable(sortable);
	return Value::Null;
}

Gura_DeclareMethod(wx_DataViewColumn, SetTitle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "title", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewColumn, SetTitle)
{
	Object_wx_DataViewColumn *pThis = Object_wx_DataViewColumn::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString title = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetTitle(title);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxDataViewColumn
//----------------------------------------------------------------------------
Object_wx_DataViewColumn::~Object_wx_DataViewColumn()
{
}

Object *Object_wx_DataViewColumn::Clone() const
{
	return nullptr;
}

String Object_wx_DataViewColumn::ToString(bool exprFlag)
{
	String rtn("<wx.DataViewColumn:");
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
// Class implementation for wxDataViewColumn
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DataViewColumn)
{
	Gura_AssignFunction(DataViewColumn);
	Gura_AssignMethod(wx_DataViewColumn, GetBitmap);
	Gura_AssignMethod(wx_DataViewColumn, GetModelColumn);
	Gura_AssignMethod(wx_DataViewColumn, GetOwner);
	Gura_AssignMethod(wx_DataViewColumn, GetRenderer);
	Gura_AssignMethod(wx_DataViewColumn, GetSortable);
	Gura_AssignMethod(wx_DataViewColumn, GetWidth);
	Gura_AssignMethod(wx_DataViewColumn, IsSortOrderAscending);
	Gura_AssignMethod(wx_DataViewColumn, SetAlignment);
	Gura_AssignMethod(wx_DataViewColumn, SetBitmap);
	Gura_AssignMethod(wx_DataViewColumn, SetSortOrder);
	Gura_AssignMethod(wx_DataViewColumn, SetSortable);
	Gura_AssignMethod(wx_DataViewColumn, SetTitle);
}

Gura_ImplementDescendantCreator(wx_DataViewColumn)
{
	return new Object_wx_DataViewColumn((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
