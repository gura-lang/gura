//----------------------------------------------------------------------------
// wxGridCellNumberEditor
// extracted from gridedit.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_GridCellNumberEditor: public wxGridCellNumberEditor, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_GridCellNumberEditor *_pObj;
public:
	inline wx_GridCellNumberEditor(int min, int max) : wxGridCellNumberEditor(min, max), _sig(nullptr), _pObj(nullptr) {}
	~wx_GridCellNumberEditor();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_GridCellNumberEditor *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
public:
	// reveal private or protected member functions to public
	wxString _GetString() const {
		return wxGridCellNumberEditor::GetString();
	}
	bool _HasRange() const {
		return HasRange();
	}
};

wx_GridCellNumberEditor::~wx_GridCellNumberEditor()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_GridCellNumberEditor::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxGridCellNumberEditor
//----------------------------------------------------------------------------
Gura_DeclareFunction(GridCellNumberEditor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_GridCellNumberEditor));
	DeclareArg(env, "min", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "max", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GridCellNumberEditor)
{
	if (!CheckWxReady(sig)) return Value::Null;
	int min = -1;
	if (args.IsValid(0)) min = args.GetInt(0);
	int max = -1;
	if (args.IsValid(1)) max = args.GetInt(1);
	wx_GridCellNumberEditor *pEntity = new wx_GridCellNumberEditor(min, max);
	Object_wx_GridCellNumberEditor *pObj = Object_wx_GridCellNumberEditor::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_GridCellNumberEditor(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_GridCellNumberEditor, GetString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridCellNumberEditor, GetString)
{
	Object_wx_GridCellNumberEditor *pThis = Object_wx_GridCellNumberEditor::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = dynamic_cast<wx_GridCellNumberEditor *>(pThis->GetEntity())->_GetString();
	return ReturnValue(env, sig, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_GridCellNumberEditor, HasRange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridCellNumberEditor, HasRange)
{
	Object_wx_GridCellNumberEditor *pThis = Object_wx_GridCellNumberEditor::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = dynamic_cast<wx_GridCellNumberEditor *>(pThis->GetEntity())->_HasRange();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_GridCellNumberEditor, SetParameters)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "params", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellNumberEditor, SetParameters)
{
	Object_wx_GridCellNumberEditor *pThis = Object_wx_GridCellNumberEditor::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString params = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetParameters(params);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxGridCellNumberEditor
//----------------------------------------------------------------------------
Object_wx_GridCellNumberEditor::~Object_wx_GridCellNumberEditor()
{
}

Object *Object_wx_GridCellNumberEditor::Clone() const
{
	return nullptr;
}

String Object_wx_GridCellNumberEditor::ToString(bool exprFlag)
{
	String rtn("<wx.GridCellNumberEditor:");
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
// Class implementation for wxGridCellNumberEditor
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridCellNumberEditor)
{
	Gura_AssignFunction(GridCellNumberEditor);
	Gura_AssignMethod(wx_GridCellNumberEditor, GetString);
	Gura_AssignMethod(wx_GridCellNumberEditor, HasRange);
	Gura_AssignMethod(wx_GridCellNumberEditor, SetParameters);
}

Gura_ImplementDescendantCreator(wx_GridCellNumberEditor)
{
	return new Object_wx_GridCellNumberEditor((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
