//----------------------------------------------------------------------------
// wxNotebookSizer
// extracted from nbsizer.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_NotebookSizer: public wxNotebookSizer, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_NotebookSizer *_pObj;
public:
	inline wx_NotebookSizer(wxNotebook* notebook) : wxNotebookSizer(notebook), _pObj(nullptr) {}
	~wx_NotebookSizer();
	inline void AssocWithGura(Object_wx_NotebookSizer *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_NotebookSizer::~wx_NotebookSizer()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_NotebookSizer::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxNotebookSizer
//----------------------------------------------------------------------------
Gura_DeclareFunction(NotebookSizer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_NotebookSizer));
	DeclareArg(env, "notebook", VTYPE_wx_Notebook, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(NotebookSizer)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxNotebook *notebook = Object_wx_Notebook::GetObject(args, 0)->GetEntity();
	wx_NotebookSizer *pEntity = new wx_NotebookSizer(notebook);
	Object_wx_NotebookSizer *pObj = Object_wx_NotebookSizer::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_NotebookSizer(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
}

Gura_DeclareMethod(wx_NotebookSizer, GetNotebook)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_NotebookSizer, GetNotebook)
{
	Signal &sig = env.GetSignal();
	Object_wx_NotebookSizer *pThis = Object_wx_NotebookSizer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxNotebook *rtn = (wxNotebook *)pThis->GetEntity()->GetNotebook();
	return ReturnValue(env, args, Value(new Object_wx_Notebook(rtn, nullptr, OwnerFalse)));
}

//----------------------------------------------------------------------------
// Object implementation for wxNotebookSizer
//----------------------------------------------------------------------------
Object_wx_NotebookSizer::~Object_wx_NotebookSizer()
{
}

Object *Object_wx_NotebookSizer::Clone() const
{
	return nullptr;
}

String Object_wx_NotebookSizer::ToString(bool exprFlag)
{
	String rtn("<wx.NotebookSizer:");
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
// Class implementation for wxNotebookSizer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_NotebookSizer)
{
	Gura_AssignFunction(NotebookSizer);
	Gura_AssignMethod(wx_NotebookSizer, GetNotebook);
}

Gura_ImplementDescendantCreator(wx_NotebookSizer)
{
	return new Object_wx_NotebookSizer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
