//----------------------------------------------------------------------------
// wxZlibInputStream
// hand-coded
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_ZlibInputStream: public wxZlibInputStream, public GuraObjectObserver {
private:
	Gura::Signal *_pSig;
	Object_wx_ZlibInputStream *_pObj;
public:
	inline wx_ZlibInputStream(wxInputStream* stream, int flags) : wxZlibInputStream(stream, flags), _pSig(nullptr), _pObj(nullptr) {}
	~wx_ZlibInputStream();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_ZlibInputStream *pObj) {
		_pSig = &sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_ZlibInputStream::~wx_ZlibInputStream()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_ZlibInputStream::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxZlibInputStream
//----------------------------------------------------------------------------
Gura_DeclareFunction(ZlibInputStream)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_ZlibInputStream));
	DeclareArg(env, "stream", VTYPE_wx_InputStream, OCCUR_Once);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ZlibInputStream)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxInputStream *stream = Object_wx_InputStream::GetObject(args, 0)->GetEntity();
	int flags = wxZLIB_AUTO;
	if (args.IsValid(1)) flags = args.GetInt(1);
	wx_ZlibInputStream *pEntity = new wx_ZlibInputStream(stream, flags);
	Object_wx_ZlibInputStream *pObj = Object_wx_ZlibInputStream::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_ZlibInputStream(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareClassMethod(wx_ZlibInputStream, CanHandleGZip)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_ZlibInputStream, CanHandleGZip)
{
	if (!CheckWxReady(sig)) return Value::Null;
	bool rtn = wxZlibInputStream::CanHandleGZip();
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxZlibInputStream
//----------------------------------------------------------------------------
Object_wx_ZlibInputStream::~Object_wx_ZlibInputStream()
{
}

Object *Object_wx_ZlibInputStream::Clone() const
{
	return nullptr;
}

String Object_wx_ZlibInputStream::ToString(bool exprFlag)
{
	String rtn("<wx.ZlibInputStream:");
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
// Class implementation for wxZlibInputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ZlibInputStream)
{
	Gura_AssignFunction(ZlibInputStream);
	Gura_AssignMethod(wx_ZlibInputStream, CanHandleGZip);
}

Gura_ImplementDescendantCreator(wx_ZlibInputStream)
{
	return new Object_wx_ZlibInputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
