//----------------------------------------------------------------------------
// wxFilterInputStream
// extracted from fltinstr.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_FilterInputStream: public wxFilterInputStream, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_FilterInputStream *_pObj;
public:
	//inline wx_FilterInputStream(wxInputStream& stream) : wxFilterInputStream(stream), _pObj(nullptr) {}
	//inline wx_FilterInputStream(wxInputStream* stream) : wxFilterInputStream(stream), _pObj(nullptr) {}
	~wx_FilterInputStream();
	inline void AssocWithGura(Object_wx_FilterInputStream *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_FilterInputStream::~wx_FilterInputStream()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_FilterInputStream::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxFilterInputStream
//----------------------------------------------------------------------------
Gura_DeclareFunction(FilterInputStream)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_FilterInputStream));
	DeclareArg(env, "stream", VTYPE_wx_InputStream, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(FilterInputStream)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wxInputStream *stream = Object_wx_InputStream::GetObject(arg, 0)->GetEntity();
	wx_FilterInputStream *pEntity = new wx_FilterInputStream(*stream);
	Object_wx_FilterInputStream *pObj = Object_wx_FilterInputStream::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_FilterInputStream(pEntity, pEntity, OwnerFalse);
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

Gura_DeclareFunction(FilterInputStream_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_FilterInputStream));
	DeclareArg(env, "stream", VTYPE_wx_InputStream, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(FilterInputStream_1)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wxInputStream *stream = Object_wx_InputStream::GetObject(arg, 0)->GetEntity();
	wx_FilterInputStream *pEntity = new wx_FilterInputStream(stream);
	Object_wx_FilterInputStream *pObj = Object_wx_FilterInputStream::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_FilterInputStream(pEntity, pEntity, OwnerFalse);
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

//----------------------------------------------------------------------------
// Object implementation for wxFilterInputStream
//----------------------------------------------------------------------------
Object_wx_FilterInputStream::~Object_wx_FilterInputStream()
{
}

Object *Object_wx_FilterInputStream::Clone() const
{
	return nullptr;
}

String Object_wx_FilterInputStream::ToString(bool exprFlag)
{
	String rtn("<wx.FilterInputStream:");
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
// Class implementation for wxFilterInputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FilterInputStream)
{
	Gura_AssignFunction(FilterInputStream);
	Gura_AssignFunction(FilterInputStream_1);
}

Gura_ImplementDescendantCreator(wx_FilterInputStream)
{
	return new Object_wx_FilterInputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
