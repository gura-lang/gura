//----------------------------------------------------------------------------
// wxListView
// extracted from listview.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_ListView: public wxListView, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_ListView *_pObj;
public:
	~wx_ListView();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_ListView *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_ListView::~wx_ListView()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_ListView::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxListView
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_ListView, ClearColumnImage)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListView, ClearColumnImage)
{
	Object_wx_ListView *pSelf = Object_wx_ListView::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int col = args.GetInt(0);
	pSelf->GetEntity()->ClearColumnImage(col);
	return Value::Null;
}

Gura_DeclareMethod(wx_ListView, Focus)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListView, Focus)
{
	Object_wx_ListView *pSelf = Object_wx_ListView::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	long index = args.GetLong(0);
	pSelf->GetEntity()->Focus(index);
	return Value::Null;
}

Gura_DeclareMethod(wx_ListView, GetFirstSelected)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListView, GetFirstSelected)
{
	Object_wx_ListView *pSelf = Object_wx_ListView::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	long rtn = pSelf->GetEntity()->GetFirstSelected();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ListView, GetFocusedItem)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListView, GetFocusedItem)
{
	Object_wx_ListView *pSelf = Object_wx_ListView::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	long rtn = pSelf->GetEntity()->GetFocusedItem();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ListView, GetNextSelected)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListView, GetNextSelected)
{
	Object_wx_ListView *pSelf = Object_wx_ListView::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	long item = args.GetLong(0);
	long rtn = pSelf->GetEntity()->GetNextSelected(item);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ListView, IsSelected)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListView, IsSelected)
{
	Object_wx_ListView *pSelf = Object_wx_ListView::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	long index = args.GetLong(0);
	bool rtn = pSelf->GetEntity()->IsSelected(index);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ListView, Select)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "on", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListView, Select)
{
	Object_wx_ListView *pSelf = Object_wx_ListView::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool on = true;
	if (args.IsValid(0)) on = args.GetBoolean(0);
	pSelf->GetEntity()->Select(on);
	return Value::Null;
}

Gura_DeclareMethod(wx_ListView, SetColumnImage)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "image", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListView, SetColumnImage)
{
	Object_wx_ListView *pSelf = Object_wx_ListView::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int col = args.GetInt(0);
	int image = args.GetInt(1);
	pSelf->GetEntity()->SetColumnImage(col, image);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxListView
//----------------------------------------------------------------------------
Object_wx_ListView::~Object_wx_ListView()
{
}

Object *Object_wx_ListView::Clone() const
{
	return NULL;
}

String Object_wx_ListView::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.ListView:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_ListView::OnModuleEntry(Environment &env, Signal sig)
{
}

//----------------------------------------------------------------------------
// Class implementation for wxListView
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ListView)
{
	Gura_AssignMethod(wx_ListView, ClearColumnImage);
	Gura_AssignMethod(wx_ListView, Focus);
	Gura_AssignMethod(wx_ListView, GetFirstSelected);
	Gura_AssignMethod(wx_ListView, GetFocusedItem);
	Gura_AssignMethod(wx_ListView, GetNextSelected);
	Gura_AssignMethod(wx_ListView, IsSelected);
	Gura_AssignMethod(wx_ListView, Select);
	Gura_AssignMethod(wx_ListView, SetColumnImage);
}

Gura_ImplementDescendantCreator(wx_ListView)
{
	return new Object_wx_ListView((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
