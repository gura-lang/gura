//----------------------------------------------------------------------------
// wxGridCellAutoWrapStringEditor
// extracted from gridedit.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_GridCellAutoWrapStringEditor: public wxGridCellAutoWrapStringEditor, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_GridCellAutoWrapStringEditor *_pObj;
public:
	inline wx_GridCellAutoWrapStringEditor() : wxGridCellAutoWrapStringEditor(), _sig(NULL), _pObj(NULL) {}
	~wx_GridCellAutoWrapStringEditor();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_GridCellAutoWrapStringEditor *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_GridCellAutoWrapStringEditor::~wx_GridCellAutoWrapStringEditor()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_GridCellAutoWrapStringEditor::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxGridCellAutoWrapStringEditor
//----------------------------------------------------------------------------
Gura_DeclareFunction(GridCellAutoWrapStringEditor)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_GridCellAutoWrapStringEditor));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GridCellAutoWrapStringEditor)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_GridCellAutoWrapStringEditor *pEntity = new wx_GridCellAutoWrapStringEditor();
	Object_wx_GridCellAutoWrapStringEditor *pObj = Object_wx_GridCellAutoWrapStringEditor::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_GridCellAutoWrapStringEditor(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

//----------------------------------------------------------------------------
// Object implementation for wxGridCellAutoWrapStringEditor
//----------------------------------------------------------------------------
Object_wx_GridCellAutoWrapStringEditor::~Object_wx_GridCellAutoWrapStringEditor()
{
}

Object *Object_wx_GridCellAutoWrapStringEditor::Clone() const
{
	return NULL;
}

String Object_wx_GridCellAutoWrapStringEditor::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.GridCellAutoWrapStringEditor:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_GridCellAutoWrapStringEditor::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(GridCellAutoWrapStringEditor);
}

//----------------------------------------------------------------------------
// Class implementation for wxGridCellAutoWrapStringEditor
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridCellAutoWrapStringEditor)
{
}

Gura_ImplementDescendantCreator(wx_GridCellAutoWrapStringEditor)
{
	return new Object_wx_GridCellAutoWrapStringEditor((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
