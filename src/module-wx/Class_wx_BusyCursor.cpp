//----------------------------------------------------------------------------
// wxBusyCursor
// extracted from busycurs.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_BusyCursor: public wxBusyCursor, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_BusyCursor *_pObj;
public:
	inline wx_BusyCursor(wxCursor* cursor) : wxBusyCursor(cursor), _pObj(nullptr) {}
	~wx_BusyCursor();
	inline void AssocWithGura(Object_wx_BusyCursor *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_BusyCursor::~wx_BusyCursor()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_BusyCursor::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxBusyCursor
//----------------------------------------------------------------------------
Gura_DeclareFunction(BusyCursor_)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_BusyCursor));
	DeclareArg(env, "cursor", VTYPE_wx_Cursor, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(BusyCursor_)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxCursor *cursor = (wxCursor *)(wxHOURGLASS_CURSOR);
	if (args.IsValid(0)) cursor = Object_wx_Cursor::GetObject(args, 0)->GetEntity();
	wx_BusyCursor *pEntity = new wx_BusyCursor(cursor);
	Object_wx_BusyCursor *pObj = Object_wx_BusyCursor::GetObjectThis(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_BusyCursor(pEntity, pEntity, OwnerTrue);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerTrue);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
}

//----------------------------------------------------------------------------
// Object implementation for wxBusyCursor
//----------------------------------------------------------------------------
Object_wx_BusyCursor::~Object_wx_BusyCursor()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_BusyCursor::Clone() const
{
	return nullptr;
}

String Object_wx_BusyCursor::ToString(bool exprFlag)
{
	String rtn("<wx.BusyCursor:");
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
// Class implementation for wxBusyCursor
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_BusyCursor)
{
	Gura_AssignFunction(BusyCursor_);
}

Gura_ImplementDescendantCreator(wx_BusyCursor)
{
	return new Object_wx_BusyCursor((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
