//----------------------------------------------------------------------------
// wxGridCellChoiceEditor
// extracted from gridedit.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_GridCellChoiceEditor: public wxGridCellChoiceEditor, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_GridCellChoiceEditor *_pObj;
public:
	inline wx_GridCellChoiceEditor(size_t count, const wxString choices[], bool allowOthers) : wxGridCellChoiceEditor(count, choices, allowOthers), _pObj(nullptr) {}
	inline wx_GridCellChoiceEditor(const wxArrayString& choices, bool allowOthers) : wxGridCellChoiceEditor(choices, allowOthers), _pObj(nullptr) {}
	~wx_GridCellChoiceEditor();
	inline void AssocWithGura(Object_wx_GridCellChoiceEditor *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_GridCellChoiceEditor::~wx_GridCellChoiceEditor()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_GridCellChoiceEditor::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxGridCellChoiceEditor
//----------------------------------------------------------------------------
Gura_DeclareFunction(GridCellChoiceEditor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_GridCellChoiceEditor));
	DeclareArg(env, "choices", VTYPE_string, OCCUR_Once, FLAG_ListVar);
	DeclareArg(env, "allowOthers", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GridCellChoiceEditor)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	std::unique_ptr<wxArrayString> choices(CreateArrayString(arg.GetList(0)));
	bool allowOthers = false;
	if (arg.IsValid(1)) allowOthers = arg.GetBoolean(1);
	wx_GridCellChoiceEditor *pEntity = new wx_GridCellChoiceEditor(*choices, allowOthers);
	Object_wx_GridCellChoiceEditor *pObj = Object_wx_GridCellChoiceEditor::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_GridCellChoiceEditor(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareMethod(wx_GridCellChoiceEditor, SetParameters)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "params", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellChoiceEditor, SetParameters)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridCellChoiceEditor *pThis = Object_wx_GridCellChoiceEditor::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString params = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->SetParameters(params);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxGridCellChoiceEditor
//----------------------------------------------------------------------------
Object_wx_GridCellChoiceEditor::~Object_wx_GridCellChoiceEditor()
{
}

Object *Object_wx_GridCellChoiceEditor::Clone() const
{
	return nullptr;
}

String Object_wx_GridCellChoiceEditor::ToString(bool exprFlag)
{
	String rtn("<wx.GridCellChoiceEditor:");
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
// Class implementation for wxGridCellChoiceEditor
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridCellChoiceEditor)
{
	Gura_AssignFunction(GridCellChoiceEditor);
	Gura_AssignMethod(wx_GridCellChoiceEditor, SetParameters);
}

Gura_ImplementDescendantCreator(wx_GridCellChoiceEditor)
{
	return new Object_wx_GridCellChoiceEditor((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
