//----------------------------------------------------------------------------
// wxGridCellFloatEditor
// extracted from gridedit.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_GridCellFloatEditor: public wxGridCellFloatEditor, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_GridCellFloatEditor *_pObj;
public:
	inline wx_GridCellFloatEditor(int width, int precision) : wxGridCellFloatEditor(width, precision), _sig(NULL), _pObj(NULL) {}
	~wx_GridCellFloatEditor();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_GridCellFloatEditor *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_GridCellFloatEditor::~wx_GridCellFloatEditor()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_GridCellFloatEditor::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxGridCellFloatEditor
//----------------------------------------------------------------------------
Gura_DeclareFunction(GridCellFloatEditor)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_GridCellFloatEditor));
	DeclareArg(env, "width", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "precision", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GridCellFloatEditor)
{
	if (!CheckWxReady(sig)) return Value::Null;
	int width = -1;
	if (args.IsValid(0)) width = args.GetInt(0);
	int precision = -1;
	if (args.IsValid(1)) precision = args.GetInt(1);
	wx_GridCellFloatEditor *pEntity = new wx_GridCellFloatEditor(width, precision);
	Object_wx_GridCellFloatEditor *pObj = Object_wx_GridCellFloatEditor::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_GridCellFloatEditor(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_GridCellFloatEditor, SetParameters)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "params", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellFloatEditor, SetParameters)
{
	Object_wx_GridCellFloatEditor *pThis = Object_wx_GridCellFloatEditor::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString params = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetParameters(params);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxGridCellFloatEditor
//----------------------------------------------------------------------------
Object_wx_GridCellFloatEditor::~Object_wx_GridCellFloatEditor()
{
}

Object *Object_wx_GridCellFloatEditor::Clone() const
{
	return NULL;
}

String Object_wx_GridCellFloatEditor::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.GridCellFloatEditor:");
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
// Class implementation for wxGridCellFloatEditor
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridCellFloatEditor)
{
	Gura_AssignFunction(GridCellFloatEditor);
	Gura_AssignMethod(wx_GridCellFloatEditor, SetParameters);
}

Gura_ImplementDescendantCreator(wx_GridCellFloatEditor)
{
	return new Object_wx_GridCellFloatEditor((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
