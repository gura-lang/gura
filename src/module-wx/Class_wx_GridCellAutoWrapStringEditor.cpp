//----------------------------------------------------------------------------
// wxGridCellAutoWrapStringEditor
// extracted from gridedit.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_GridCellAutoWrapStringEditor: public wxGridCellAutoWrapStringEditor, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_GridCellAutoWrapStringEditor *_pObj;
public:
	inline wx_GridCellAutoWrapStringEditor() : wxGridCellAutoWrapStringEditor(), _pObj(nullptr) {}
	~wx_GridCellAutoWrapStringEditor();
	inline void AssocWithGura(Object_wx_GridCellAutoWrapStringEditor *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_GridCellAutoWrapStringEditor::~wx_GridCellAutoWrapStringEditor()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_GridCellAutoWrapStringEditor::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxGridCellAutoWrapStringEditor
//----------------------------------------------------------------------------
Gura_DeclareFunction(GridCellAutoWrapStringEditor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_GridCellAutoWrapStringEditor));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GridCellAutoWrapStringEditor)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_GridCellAutoWrapStringEditor *pEntity = new wx_GridCellAutoWrapStringEditor();
	Object_wx_GridCellAutoWrapStringEditor *pObj = Object_wx_GridCellAutoWrapStringEditor::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_GridCellAutoWrapStringEditor(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
}

//----------------------------------------------------------------------------
// Object implementation for wxGridCellAutoWrapStringEditor
//----------------------------------------------------------------------------
Object_wx_GridCellAutoWrapStringEditor::~Object_wx_GridCellAutoWrapStringEditor()
{
}

Object *Object_wx_GridCellAutoWrapStringEditor::Clone() const
{
	return nullptr;
}

String Object_wx_GridCellAutoWrapStringEditor::ToString(bool exprFlag)
{
	String rtn("<wx.GridCellAutoWrapStringEditor:");
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
// Class implementation for wxGridCellAutoWrapStringEditor
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridCellAutoWrapStringEditor)
{
	Gura_AssignFunction(GridCellAutoWrapStringEditor);
}

Gura_ImplementDescendantCreator(wx_GridCellAutoWrapStringEditor)
{
	return new Object_wx_GridCellAutoWrapStringEditor((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
