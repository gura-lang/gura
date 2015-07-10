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
	Gura::Signal *_pSig;
	Object_wx_GridCellChoiceEditor *_pObj;
public:
	inline wx_GridCellChoiceEditor(size_t count, const wxString choices[], bool allowOthers) : wxGridCellChoiceEditor(count, choices, allowOthers), _pSig(nullptr), _pObj(nullptr) {}
	inline wx_GridCellChoiceEditor(const wxArrayString& choices, bool allowOthers) : wxGridCellChoiceEditor(choices, allowOthers), _pSig(nullptr), _pObj(nullptr) {}
	~wx_GridCellChoiceEditor();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_GridCellChoiceEditor *pObj) {
		_pSig = &sig, _pObj = pObj;
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
	DeclareArg(env, "choices", VTYPE_string, OCCUR_Once, FLAG_List);
	DeclareArg(env, "allowOthers", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GridCellChoiceEditor)
{
	if (!CheckWxReady(sig)) return Value::Null;
	std::unique_ptr<wxArrayString> choices(CreateArrayString(args.GetList(0)));
	bool allowOthers = false;
	if (args.IsValid(1)) allowOthers = args.GetBoolean(1);
	wx_GridCellChoiceEditor *pEntity = new wx_GridCellChoiceEditor(*choices, allowOthers);
	Object_wx_GridCellChoiceEditor *pObj = Object_wx_GridCellChoiceEditor::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_GridCellChoiceEditor(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_GridCellChoiceEditor, SetParameters)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "params", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellChoiceEditor, SetParameters)
{
	Object_wx_GridCellChoiceEditor *pThis = Object_wx_GridCellChoiceEditor::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString params = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetParameters(params);
	return Value::Null;
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
