//----------------------------------------------------------------------------
// wxSizeEvent
// extracted from sizeevt.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_SizeEvent: public wxSizeEvent, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_SizeEvent *_pObj;
public:
	inline wx_SizeEvent(const wxSize& sz, int id) : wxSizeEvent(sz, id), _pObj(nullptr) {}
	~wx_SizeEvent();
	inline void AssocWithGura(Object_wx_SizeEvent *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_SizeEvent::~wx_SizeEvent()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_SizeEvent::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxSizeEvent
//----------------------------------------------------------------------------
Gura_DeclareFunction(SizeEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_SizeEvent));
	DeclareArg(env, "sz", VTYPE_wx_Size, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(SizeEvent)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxSize *sz = Object_wx_Size::GetObject(args, 0)->GetEntity();
	int id = 0;
	if (args.IsValid(1)) id = args.GetInt(1);
	wx_SizeEvent *pEntity = new wx_SizeEvent(*sz, id);
	Object_wx_SizeEvent *pObj = Object_wx_SizeEvent::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_SizeEvent(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
}

Gura_DeclareMethod(wx_SizeEvent, GetSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SizeEvent, GetSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_SizeEvent *pThis = Object_wx_SizeEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxSize rtn = pThis->GetEntity()->GetSize();
	return ReturnValue(env, args, Value(new Object_wx_Size(new wxSize(rtn), nullptr, OwnerTrue)));
}

//----------------------------------------------------------------------------
// Object implementation for wxSizeEvent
//----------------------------------------------------------------------------
Object_wx_SizeEvent::~Object_wx_SizeEvent()
{
}

Object *Object_wx_SizeEvent::Clone() const
{
	return nullptr;
}

String Object_wx_SizeEvent::ToString(bool exprFlag)
{
	String rtn("<wx.SizeEvent:");
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
// Class implementation for wxSizeEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SizeEvent)
{
	Gura_AssignFunction(SizeEvent);
	Gura_AssignMethod(wx_SizeEvent, GetSize);
}

Gura_ImplementDescendantCreator(wx_SizeEvent)
{
	return new Object_wx_SizeEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
