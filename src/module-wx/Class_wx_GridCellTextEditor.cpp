//----------------------------------------------------------------------------
// wxGridCellTextEditor
// extracted from gridedit.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_GridCellTextEditor: public wxGridCellTextEditor, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_GridCellTextEditor *_pObj;
public:
	inline wx_GridCellTextEditor() : wxGridCellTextEditor(), _pObj(nullptr) {}
	~wx_GridCellTextEditor();
	inline void AssocWithGura(Object_wx_GridCellTextEditor *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_GridCellTextEditor::~wx_GridCellTextEditor()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_GridCellTextEditor::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxGridCellTextEditor
//----------------------------------------------------------------------------
Gura_DeclareFunction(GridCellTextEditor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_GridCellTextEditor));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GridCellTextEditor)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_GridCellTextEditor *pEntity = new wx_GridCellTextEditor();
	Object_wx_GridCellTextEditor *pObj = Object_wx_GridCellTextEditor::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_GridCellTextEditor(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
}

Gura_DeclareMethod(wx_GridCellTextEditor, SetParameters)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "params", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellTextEditor, SetParameters)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridCellTextEditor *pThis = Object_wx_GridCellTextEditor::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString params = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetParameters(params);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxGridCellTextEditor
//----------------------------------------------------------------------------
Object_wx_GridCellTextEditor::~Object_wx_GridCellTextEditor()
{
}

Object *Object_wx_GridCellTextEditor::Clone() const
{
	return nullptr;
}

String Object_wx_GridCellTextEditor::ToString(bool exprFlag)
{
	String rtn("<wx.GridCellTextEditor:");
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
// Class implementation for wxGridCellTextEditor
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridCellTextEditor)
{
	Gura_AssignFunction(GridCellTextEditor);
	Gura_AssignMethod(wx_GridCellTextEditor, SetParameters);
}

Gura_ImplementDescendantCreator(wx_GridCellTextEditor)
{
	return new Object_wx_GridCellTextEditor((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
