//----------------------------------------------------------------------------
// wxZlibOutputStream
// hand-coded
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_ZlibOutputStream: public wxZlibOutputStream, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_ZlibOutputStream *_pObj;
public:
	inline wx_ZlibOutputStream(wxOutputStream* stream, int level, int flags) : wxZlibOutputStream(stream, level, flags), _pObj(nullptr) {}
	~wx_ZlibOutputStream();
	inline void AssocWithGura(Object_wx_ZlibOutputStream *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_ZlibOutputStream::~wx_ZlibOutputStream()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_ZlibOutputStream::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxZlibOutputStream
//----------------------------------------------------------------------------
Gura_DeclareFunction(ZlibOutputStream)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_ZlibOutputStream));
	DeclareArg(env, "stream", VTYPE_wx_OutputStream, OCCUR_Once);
	DeclareArg(env, "level", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ZlibOutputStream)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxOutputStream *stream = Object_wx_OutputStream::GetObject(arg, 0)->GetEntity();
	int level = -1;
	if (arg.IsValid(1)) level = arg.GetInt(1);
	int flags = wxZLIB_ZLIB;
	if (arg.IsValid(2)) flags = arg.GetInt(2);
	wx_ZlibOutputStream *pEntity = new wx_ZlibOutputStream(stream, level, flags);
	Object_wx_ZlibOutputStream *pObj = Object_wx_ZlibOutputStream::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_ZlibOutputStream(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareClassMethod(wx_ZlibOutputStream, CanHandleGZip)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_ZlibOutputStream, CanHandleGZip)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	bool rtn = wxZlibOutputStream::CanHandleGZip();
	return ReturnValue(env, arg, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxZlibOutputStream
//----------------------------------------------------------------------------
Object_wx_ZlibOutputStream::~Object_wx_ZlibOutputStream()
{
}

Object *Object_wx_ZlibOutputStream::Clone() const
{
	return nullptr;
}

String Object_wx_ZlibOutputStream::ToString(bool exprFlag)
{
	String rtn("<wx.ZlibOutputStream:");
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
// Class implementation for wxZlibOutputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ZlibOutputStream)
{
	Gura_AssignFunction(ZlibOutputStream);
	Gura_AssignMethod(wx_ZlibOutputStream, CanHandleGZip);
}

Gura_ImplementDescendantCreator(wx_ZlibOutputStream)
{
	return new Object_wx_ZlibOutputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
