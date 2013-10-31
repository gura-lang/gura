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
	Gura::Signal _sig;
	Object_wx_DropFilesEvent *_pObj;
public:
	//inline wx_DropFilesEvent(WXTYPE id, int noFiles, wxString* files) : wxDropFilesEvent(id, noFiles, files), _sig(NULL), _pObj(NULL) {}
	~wx_DropFilesEvent();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_DropFilesEvent *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_DropFilesEvent::~wx_DropFilesEvent()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_DropFilesEvent::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxDropFilesEvent
//----------------------------------------------------------------------------
Gura_DeclareFunction(DropFilesEvent)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_DropFilesEvent));
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "noFiles", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "files", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(DropFilesEvent)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	WXTYPE id = 0;
	if (args.IsValid(0)) id = static_cast<WXTYPE>(args.GetInt(0));
	int noFiles = 0;
	if (args.IsValid(1)) noFiles = args.GetInt(1);
	wxString files = NULL;
	if (args.IsValid(2)) files = wxString::FromUTF8(args.GetString(2));
	wx_DropFilesEvent *pEntity = new wx_DropFilesEvent(id, noFiles, files);
	Object_wx_DropFilesEvent *pObj = Object_wx_DropFilesEvent::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_DropFilesEvent(pEntity, pEntity, OwnerFalse);
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

Gura_DeclareMethod(wx_DropFilesEvent, GetFiles)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DropFilesEvent, GetFiles)
{
#if 0
	Object_wx_DropFilesEvent *pThis = Object_wx_DropFilesEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetFiles();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DropFilesEvent, GetNumberOfFiles)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DropFilesEvent, GetNumberOfFiles)
{
	Object_wx_DropFilesEvent *pThis = Object_wx_DropFilesEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetNumberOfFiles();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DropFilesEvent, GetPosition)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DropFilesEvent, GetPosition)
{
	Object_wx_DropFilesEvent *pThis = Object_wx_DropFilesEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPoint rtn = pThis->GetEntity()->GetPosition();
	return ReturnValue(env, sig, args, Value(new Object_wx_Point(new wxPoint(rtn), NULL, OwnerTrue)));
}

//----------------------------------------------------------------------------
// Object implementation for wxDropFilesEvent
//----------------------------------------------------------------------------
Object_wx_DropFilesEvent::~Object_wx_DropFilesEvent()
{
}

Object *Object_wx_DropFilesEvent::Clone() const
{
	return NULL;
}

String Object_wx_DropFilesEvent::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.DropFilesEvent:");
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
	return new Object_wx_DropFilesEvent((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
