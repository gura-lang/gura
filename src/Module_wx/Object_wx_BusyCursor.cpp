//----------------------------------------------------------------------------
// wxBusyCursor
// extracted from busycurs.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_BusyCursor: public wxBusyCursor, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_BusyCursor *_pObj;
public:
	inline wx_BusyCursor(wxCursor* cursor) : wxBusyCursor(cursor), _sig(NULL), _pObj(NULL) {}
	~wx_BusyCursor();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_BusyCursor *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_BusyCursor::~wx_BusyCursor()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_BusyCursor::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxBusyCursor
//----------------------------------------------------------------------------
Gura_DeclareFunction(BusyCursor_)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_BusyCursor));
	DeclareArg(env, "cursor", VTYPE_wx_Cursor, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(BusyCursor_)
{
	wxCursor *cursor = (wxCursor *)(wxHOURGLASS_CURSOR);
	if (args.IsValid(0)) cursor = Object_wx_Cursor::GetObject(args, 0)->GetEntity();
	wx_BusyCursor *pEntity = new wx_BusyCursor(cursor);
	Object_wx_BusyCursor *pObj = Object_wx_BusyCursor::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_BusyCursor(pEntity, pEntity, OwnerTrue);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerTrue);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

//----------------------------------------------------------------------------
// Object implementation for wxBusyCursor
//----------------------------------------------------------------------------
Object_wx_BusyCursor::~Object_wx_BusyCursor()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_BusyCursor::Clone() const
{
	return NULL;
}

String Object_wx_BusyCursor::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.BusyCursor:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_BusyCursor::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(BusyCursor_);
}

//----------------------------------------------------------------------------
// Class implementation for wxBusyCursor
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_BusyCursor)
{
}

Gura_ImplementDescendantCreator(wx_BusyCursor)
{
	return new Object_wx_BusyCursor((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
