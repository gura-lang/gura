//----------------------------------------------------------------------------
// wxDropFilesEvent
// extracted from dropevt.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_DropFilesEvent: public wxDropFilesEvent, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_DropFilesEvent *_pObj;
public:
	//inline wx_DropFilesEvent(WXTYPE id, int noFiles, wxString* files) : wxDropFilesEvent(id, noFiles, files), _pObj(nullptr) {}
	~wx_DropFilesEvent();
	inline void AssocWithGura(Object_wx_DropFilesEvent *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_DropFilesEvent::~wx_DropFilesEvent()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_DropFilesEvent::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxDropFilesEvent
//----------------------------------------------------------------------------
Gura_DeclareFunction(DropFilesEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_DropFilesEvent));
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "files", VTYPE_string, OCCUR_ZeroOrOnce, FLAG_List);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(DropFilesEvent)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	WXTYPE id = 0;
	if (arg.IsValid(0)) id = static_cast<WXTYPE>(arg.GetInt(0));
	int noFiles = 0;
	wxString *files = nullptr;
	std::unique_ptr<wxArrayString> pFilesArray;
	if (arg.IsValid(1)) {
		pFilesArray.reset(CreateArrayString(arg,GetList(1)));
		files = pFilesArray->
	}
	wx_DropFilesEvent *pEntity = new wx_DropFilesEvent(id, noFiles, files);
	Object_wx_DropFilesEvent *pObj = Object_wx_DropFilesEvent::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_DropFilesEvent(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DropFilesEvent, GetFiles)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DropFilesEvent, GetFiles)
{
	Signal &sig = env.GetSignal();
	Object_wx_DropFilesEvent *pThis = Object_wx_DropFilesEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString *rtn = pThis->GetEntity()->GetFiles();
	int n = pThis->GetEntity()->GetNumberOfFiles();
	return ReturnValue(env, arg, ArrayStringToValue(env, rtn, n));
}

Gura_DeclareMethod(wx_DropFilesEvent, GetNumberOfFiles)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DropFilesEvent, GetNumberOfFiles)
{
	Signal &sig = env.GetSignal();
	Object_wx_DropFilesEvent *pThis = Object_wx_DropFilesEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetNumberOfFiles();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_DropFilesEvent, GetPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DropFilesEvent, GetPosition)
{
	Signal &sig = env.GetSignal();
	Object_wx_DropFilesEvent *pThis = Object_wx_DropFilesEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxPoint rtn = pThis->GetEntity()->GetPosition();
	return ReturnValue(env, arg, Value(new Object_wx_Point(new wxPoint(rtn), nullptr, OwnerTrue)));
}

//----------------------------------------------------------------------------
// Object implementation for wxDropFilesEvent
//----------------------------------------------------------------------------
Object_wx_DropFilesEvent::~Object_wx_DropFilesEvent()
{
}

Object *Object_wx_DropFilesEvent::Clone() const
{
	return nullptr;
}

String Object_wx_DropFilesEvent::ToString(bool exprFlag)
{
	String rtn("<wx.DropFilesEvent:");
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
// Class implementation for wxDropFilesEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DropFilesEvent)
{
	Gura_AssignFunction(DropFilesEvent);
	Gura_AssignMethod(wx_DropFilesEvent, GetFiles);
	Gura_AssignMethod(wx_DropFilesEvent, GetNumberOfFiles);
	Gura_AssignMethod(wx_DropFilesEvent, GetPosition);
}

Gura_ImplementDescendantCreator(wx_DropFilesEvent)
{
	return new Object_wx_DropFilesEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
