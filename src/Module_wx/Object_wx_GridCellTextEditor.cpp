//----------------------------------------------------------------------------
// wxGridCellTextEditor
// extracted from gridedit.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_GridCellTextEditor: public wxGridCellTextEditor, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_GridCellTextEditor *_pObj;
public:
	inline wx_GridCellTextEditor() : wxGridCellTextEditor(), _sig(NULL), _pObj(NULL) {}
	~wx_GridCellTextEditor();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_GridCellTextEditor *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_GridCellTextEditor::~wx_GridCellTextEditor()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_GridCellTextEditor::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxGridCellTextEditor
//----------------------------------------------------------------------------
Gura_DeclareFunction(GridCellTextEditor)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_GridCellTextEditor));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GridCellTextEditor)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_GridCellTextEditor *pEntity = new wx_GridCellTextEditor();
	Object_wx_GridCellTextEditor *pObj = Object_wx_GridCellTextEditor::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_GridCellTextEditor(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_GridCellTextEditor, SetParameters)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "params", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellTextEditor, SetParameters)
{
	Object_wx_GridCellTextEditor *pThis = Object_wx_GridCellTextEditor::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString params = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetParameters(params);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxGridCellTextEditor
//----------------------------------------------------------------------------
Object_wx_GridCellTextEditor::~Object_wx_GridCellTextEditor()
{
}

Object *Object_wx_GridCellTextEditor::Clone() const
{
	return NULL;
}

String Object_wx_GridCellTextEditor::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.GridCellTextEditor:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_GridCellTextEditor::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(GridCellTextEditor);
}

//----------------------------------------------------------------------------
// Class implementation for wxGridCellTextEditor
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridCellTextEditor)
{
	Gura_AssignMethod(wx_GridCellTextEditor, SetParameters);
}

Gura_ImplementDescendantCreator(wx_GridCellTextEditor)
{
	return new Object_wx_GridCellTextEditor((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
