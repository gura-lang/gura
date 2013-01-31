//----------------------------------------------------------------------------
// wxZlibOutputStream
// hand-coded
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_ZlibOutputStream: public wxZlibOutputStream, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_ZlibOutputStream *_pObj;
public:
	inline wx_ZlibOutputStream(wxOutputStream* stream, int level, int flags) : wxZlibOutputStream(stream, level, flags), _sig(NULL), _pObj(NULL) {}
	~wx_ZlibOutputStream();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_ZlibOutputStream *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_ZlibOutputStream::~wx_ZlibOutputStream()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_ZlibOutputStream::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxZlibOutputStream
//----------------------------------------------------------------------------
Gura_DeclareFunction(ZlibOutputStream)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_ZlibOutputStream));
	DeclareArg(env, "stream", VTYPE_wx_OutputStream, OCCUR_Once);
	DeclareArg(env, "level", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ZlibOutputStream)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxOutputStream *stream = Object_wx_OutputStream::GetObject(args, 0)->GetEntity();
	int level = -1;
	if (args.IsValid(1)) level = args.GetInt(1);
	int flags = wxZLIB_ZLIB;
	if (args.IsValid(2)) flags = args.GetInt(2);
	wx_ZlibOutputStream *pEntity = new wx_ZlibOutputStream(stream, level, flags);
	Object_wx_ZlibOutputStream *pObj = Object_wx_ZlibOutputStream::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_ZlibOutputStream(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareClassMethod(wx_ZlibOutputStream, CanHandleGZip)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_ZlibOutputStream, CanHandleGZip)
{
	if (!CheckWxReady(sig)) return Value::Null;
	bool rtn = wxZlibOutputStream::CanHandleGZip();
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxZlibOutputStream
//----------------------------------------------------------------------------
Object_wx_ZlibOutputStream::~Object_wx_ZlibOutputStream()
{
}

Object *Object_wx_ZlibOutputStream::Clone() const
{
	return NULL;
}

String Object_wx_ZlibOutputStream::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.ZlibOutputStream:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_ZlibOutputStream::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(ZlibOutputStream);
}

//----------------------------------------------------------------------------
// Class implementation for wxZlibOutputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ZlibOutputStream)
{
	Gura_AssignMethod(wx_ZlibOutputStream, CanHandleGZip);
}

Gura_ImplementDescendantCreator(wx_ZlibOutputStream)
{
	return new Object_wx_ZlibOutputStream((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
