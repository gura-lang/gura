//----------------------------------------------------------------------------
// wxClipboardTextEvent
// extracted from clipevent.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_ClipboardTextEvent: public wxClipboardTextEvent, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_ClipboardTextEvent *_pObj;
public:
	inline wx_ClipboardTextEvent(wxEventType commandType, int id) : wxClipboardTextEvent(commandType, id), _pObj(nullptr) {}
	~wx_ClipboardTextEvent();
	inline void AssocWithGura(Object_wx_ClipboardTextEvent *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_ClipboardTextEvent::~wx_ClipboardTextEvent()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_ClipboardTextEvent::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxClipboardTextEvent
//----------------------------------------------------------------------------
Gura_DeclareFunction(ClipboardTextEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_ClipboardTextEvent));
	DeclareArg(env, "commandType", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ClipboardTextEvent)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxEventType commandType = wxEVT_NULL;
	if (args.IsValid(0)) commandType = static_cast<wxEventType>(args.GetInt(0));
	int id = 0;
	if (args.IsValid(1)) id = args.GetInt(1);
	wx_ClipboardTextEvent *pEntity = new wx_ClipboardTextEvent(commandType, id);
	Object_wx_ClipboardTextEvent *pObj = Object_wx_ClipboardTextEvent::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_ClipboardTextEvent(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

//----------------------------------------------------------------------------
// Object implementation for wxClipboardTextEvent
//----------------------------------------------------------------------------
Object_wx_ClipboardTextEvent::~Object_wx_ClipboardTextEvent()
{
}

Object *Object_wx_ClipboardTextEvent::Clone() const
{
	return nullptr;
}

String Object_wx_ClipboardTextEvent::ToString(bool exprFlag)
{
	String rtn("<wx.ClipboardTextEvent:");
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
// Class implementation for wxClipboardTextEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ClipboardTextEvent)
{
	Gura_AssignFunction(ClipboardTextEvent);
}

Gura_ImplementDescendantCreator(wx_ClipboardTextEvent)
{
	return new Object_wx_ClipboardTextEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
