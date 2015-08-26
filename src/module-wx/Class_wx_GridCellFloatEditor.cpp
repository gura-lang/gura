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
	//Gura::Signal *_pSig;
	Object_wx_GridCellFloatEditor *_pObj;
public:
	inline wx_GridCellFloatEditor(int width, int precision) : wxGridCellFloatEditor(width, precision), _pObj(nullptr) {}
	~wx_GridCellFloatEditor();
	inline void AssocWithGura(Object_wx_GridCellFloatEditor *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_GridCellFloatEditor::~wx_GridCellFloatEditor()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_GridCellFloatEditor::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxGridCellFloatEditor
//----------------------------------------------------------------------------
Gura_DeclareFunction(GridCellFloatEditor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_GridCellFloatEditor));
	DeclareArg(env, "width", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "precision", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GridCellFloatEditor)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	int width = -1;
	if (args.IsValid(0)) width = args.GetInt(0);
	int precision = -1;
	if (args.IsValid(1)) precision = args.GetInt(1);
	wx_GridCellFloatEditor *pEntity = new wx_GridCellFloatEditor(width, precision);
	Object_wx_GridCellFloatEditor *pObj = Object_wx_GridCellFloatEditor::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_GridCellFloatEditor(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
}

Gura_DeclareMethod(wx_GridCellFloatEditor, SetParameters)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "params", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellFloatEditor, SetParameters)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridCellFloatEditor *pThis = Object_wx_GridCellFloatEditor::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString params = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetParameters(params);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxGridCellFloatEditor
//----------------------------------------------------------------------------
Object_wx_GridCellFloatEditor::~Object_wx_GridCellFloatEditor()
{
}

Object *Object_wx_GridCellFloatEditor::Clone() const
{
	return nullptr;
}

String Object_wx_GridCellFloatEditor::ToString(bool exprFlag)
{
	String rtn("<wx.GridCellFloatEditor:");
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
// Class implementation for wxGridCellFloatEditor
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridCellFloatEditor)
{
	Gura_AssignFunction(GridCellFloatEditor);
	Gura_AssignMethod(wx_GridCellFloatEditor, SetParameters);
}

Gura_ImplementDescendantCreator(wx_GridCellFloatEditor)
{
	return new Object_wx_GridCellFloatEditor((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
