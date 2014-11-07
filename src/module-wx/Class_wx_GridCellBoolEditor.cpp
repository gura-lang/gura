//----------------------------------------------------------------------------
// wxGridCellBoolEditor
// extracted from gridedit.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_GridCellBoolEditor: public wxGridCellBoolEditor, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_GridCellBoolEditor *_pObj;
public:
	inline wx_GridCellBoolEditor() : wxGridCellBoolEditor(), _sig(NULL), _pObj(NULL) {}
	~wx_GridCellBoolEditor();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_GridCellBoolEditor *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_GridCellBoolEditor::~wx_GridCellBoolEditor()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_GridCellBoolEditor::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxGridCellBoolEditor
//----------------------------------------------------------------------------
Gura_DeclareFunction(GridCellBoolEditor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_GridCellBoolEditor));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GridCellBoolEditor)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_GridCellBoolEditor *pEntity = new wx_GridCellBoolEditor();
	Object_wx_GridCellBoolEditor *pObj = Object_wx_GridCellBoolEditor::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_GridCellBoolEditor(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareClassMethod(wx_GridCellBoolEditor, IsTrueValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "value", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_GridCellBoolEditor, IsTrueValue)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxString value = wxString::FromUTF8(args.GetString(0));
	bool rtn = wxGridCellBoolEditor::IsTrueValue(value);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareClassMethod(wx_GridCellBoolEditor, UseStringValues)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "valueTrue", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "valueFalse", VTYPE_string, OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_GridCellBoolEditor, UseStringValues)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxString valueTrue = _T("1");
	if (args.IsValid(0)) valueTrue = wxString::FromUTF8(args.GetString(0));
	wxString valueFalse = _T("");
	if (args.IsValid(1)) valueFalse = wxString::FromUTF8(args.GetString(1));
	wxGridCellBoolEditor::UseStringValues(valueTrue, valueFalse);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxGridCellBoolEditor
//----------------------------------------------------------------------------
Object_wx_GridCellBoolEditor::~Object_wx_GridCellBoolEditor()
{
}

Object *Object_wx_GridCellBoolEditor::Clone() const
{
	return NULL;
}

String Object_wx_GridCellBoolEditor::ToString(bool exprFlag)
{
	String rtn("<wx.GridCellBoolEditor:");
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
// Class implementation for wxGridCellBoolEditor
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridCellBoolEditor)
{
	Gura_AssignFunction(GridCellBoolEditor);
	Gura_AssignMethod(wx_GridCellBoolEditor, IsTrueValue);
	Gura_AssignMethod(wx_GridCellBoolEditor, UseStringValues);
}

Gura_ImplementDescendantCreator(wx_GridCellBoolEditor)
{
	return new Object_wx_GridCellBoolEditor((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
