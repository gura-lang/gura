//----------------------------------------------------------------------------
// wxDataViewModel
// extracted from dataviewmodel.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_DataViewModel: public wxDataViewModel, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_DataViewModel *_pObj;
public:
	//inline wx_DataViewModel() : wxDataViewModel(), _sig(NULL), _pObj(NULL) {}
	~wx_DataViewModel();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_DataViewModel *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_DataViewModel::~wx_DataViewModel()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_DataViewModel::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxDataViewModel
//----------------------------------------------------------------------------
Gura_DeclareFunction(DataViewModelEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_DataViewModel));
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(DataViewModelEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wx_DataViewModel *pEntity = new wx_DataViewModel();
	Object_wx_DataViewModel *pObj = Object_wx_DataViewModel::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_DataViewModel(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxDataViewModel
//----------------------------------------------------------------------------
Object_wx_DataViewModel::~Object_wx_DataViewModel()
{
}

Object *Object_wx_DataViewModel::Clone() const
{
	return NULL;
}

String Object_wx_DataViewModel::ToString(bool exprFlag)
{
	String rtn("<wx.DataViewModel:");
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
// Class implementation for wxDataViewModel
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DataViewModel)
{
	Gura_AssignFunction(DataViewModelEmpty);
}

Gura_ImplementDescendantCreator(wx_DataViewModel)
{
	return new Object_wx_DataViewModel((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
