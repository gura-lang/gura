//----------------------------------------------------------------------------
// wxInitDialogEvent
// extracted from indlgevt.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_InitDialogEvent: public wxInitDialogEvent, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_InitDialogEvent *_pObj;
public:
	inline wx_InitDialogEvent(int id) : wxInitDialogEvent(id), _sig(NULL), _pObj(NULL) {}
	~wx_InitDialogEvent();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_InitDialogEvent *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_InitDialogEvent::~wx_InitDialogEvent()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_InitDialogEvent::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxInitDialogEvent
//----------------------------------------------------------------------------
Gura_DeclareFunction(InitDialogEvent)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_InitDialogEvent));
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(InitDialogEvent)
{
	if (!CheckWxReady(sig)) return Value::Null;
	int id = 0;
	if (args.IsValid(0)) id = args.GetInt(0);
	wx_InitDialogEvent *pEntity = new wx_InitDialogEvent(id);
	Object_wx_InitDialogEvent *pObj = Object_wx_InitDialogEvent::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_InitDialogEvent(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

//----------------------------------------------------------------------------
// Object implementation for wxInitDialogEvent
//----------------------------------------------------------------------------
Object_wx_InitDialogEvent::~Object_wx_InitDialogEvent()
{
}

Object *Object_wx_InitDialogEvent::Clone() const
{
	return NULL;
}

String Object_wx_InitDialogEvent::ToString(bool exprFlag)
{
	String rtn("<wx.InitDialogEvent:");
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
// Class implementation for wxInitDialogEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_InitDialogEvent)
{
	Gura_AssignFunction(InitDialogEvent);
}

Gura_ImplementDescendantCreator(wx_InitDialogEvent)
{
	return new Object_wx_InitDialogEvent((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
