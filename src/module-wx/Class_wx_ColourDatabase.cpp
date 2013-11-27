//----------------------------------------------------------------------------
// wxColourDatabase
// extracted from colour.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_ColourDatabase: public wxColourDatabase, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_ColourDatabase *_pObj;
public:
	inline wx_ColourDatabase() : wxColourDatabase(), _sig(NULL), _pObj(NULL) {}
	~wx_ColourDatabase();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_ColourDatabase *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_ColourDatabase::~wx_ColourDatabase()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_ColourDatabase::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxColourDatabase
//----------------------------------------------------------------------------
Gura_DeclareFunction(ColourDatabaseEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_ColourDatabase));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ColourDatabaseEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_ColourDatabase *pEntity = new wx_ColourDatabase();
	Object_wx_ColourDatabase *pObj = Object_wx_ColourDatabase::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_ColourDatabase(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_ColourDatabase, AddColour)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "colourName", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "colour", VTYPE_wx_Colour, OCCUR_Once);
}

Gura_ImplementMethod(wx_ColourDatabase, AddColour)
{
	Object_wx_ColourDatabase *pThis = Object_wx_ColourDatabase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString colourName = wxString::FromUTF8(args.GetString(0));
	wxColour *colour = Object_wx_Colour::GetObject(args, 1)->GetEntity();
	pThis->GetEntity()->AddColour(colourName, *colour);
	return Value::Null;
}

Gura_DeclareMethod(wx_ColourDatabase, AddColour_1)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "colourName", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "colour", VTYPE_wx_Colour, OCCUR_Once);
}

Gura_ImplementMethod(wx_ColourDatabase, AddColour_1)
{
	Object_wx_ColourDatabase *pThis = Object_wx_ColourDatabase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString colourName = wxString::FromUTF8(args.GetString(0));
	wxColour *colour = Object_wx_Colour::GetObject(args, 1)->GetEntity();
	pThis->GetEntity()->AddColour(colourName, *colour);
	return Value::Null;
}

Gura_DeclareMethod(wx_ColourDatabase, Find)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "colourName", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ColourDatabase, Find)
{
	Object_wx_ColourDatabase *pThis = Object_wx_ColourDatabase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString colourName = wxString::FromUTF8(args.GetString(0));
	wxColour rtn = pThis->GetEntity()->Find(colourName);
	return ReturnValue(env, sig, args, Value(new Object_wx_Colour(new wxColour(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_ColourDatabase, FindName)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "colour", VTYPE_wx_Colour, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ColourDatabase, FindName)
{
	Object_wx_ColourDatabase *pThis = Object_wx_ColourDatabase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxColour *colour = Object_wx_Colour::GetObject(args, 0)->GetEntity();
	wxString rtn = pThis->GetEntity()->FindName(*colour);
	return ReturnValue(env, sig, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

//----------------------------------------------------------------------------
// Object implementation for wxColourDatabase
//----------------------------------------------------------------------------
Object_wx_ColourDatabase::~Object_wx_ColourDatabase()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_ColourDatabase::Clone() const
{
	return NULL;
}

String Object_wx_ColourDatabase::ToString(bool exprFlag)
{
	String rtn("<wx.ColourDatabase:");
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
// Class implementation for wxColourDatabase
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ColourDatabase)
{
	Gura_AssignFunction(ColourDatabaseEmpty);
	Gura_AssignMethod(wx_ColourDatabase, AddColour);
	Gura_AssignMethod(wx_ColourDatabase, AddColour_1);
	Gura_AssignMethod(wx_ColourDatabase, Find);
	Gura_AssignMethod(wx_ColourDatabase, FindName);
}

Gura_ImplementDescendantCreator(wx_ColourDatabase)
{
	return new Object_wx_ColourDatabase((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
