//----------------------------------------------------------------------------
// wxMemoryDC
// extracted from memorydc.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_MemoryDC: public wxMemoryDC, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_MemoryDC *_pObj;
public:
	inline wx_MemoryDC() : wxMemoryDC(), _pObj(nullptr) {}
	inline wx_MemoryDC(wxBitmap& bitmap) : wxMemoryDC(bitmap), _pObj(nullptr) {}
	~wx_MemoryDC();
	inline void AssocWithGura(Object_wx_MemoryDC *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_MemoryDC::~wx_MemoryDC()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_MemoryDC::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxMemoryDC
//----------------------------------------------------------------------------
Gura_DeclareFunction(MemoryDCEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_MemoryDC));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(MemoryDCEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_MemoryDC *pEntity = new wx_MemoryDC();
	Object_wx_MemoryDC *pObj = Object_wx_MemoryDC::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_MemoryDC(pEntity, pEntity, OwnerTrue);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerTrue);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareFunction(MemoryDC)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_MemoryDC));
	DeclareArg(env, "bitmap", VTYPE_wx_Bitmap, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(MemoryDC)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxBitmap *bitmap = Object_wx_Bitmap::GetObject(arg, 0)->GetEntity();
	wx_MemoryDC *pEntity = new wx_MemoryDC(*bitmap);
	Object_wx_MemoryDC *pObj = Object_wx_MemoryDC::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_MemoryDC(pEntity, pEntity, OwnerTrue);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerTrue);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareMethod(wx_MemoryDC, SelectObject)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "bitmap", VTYPE_wx_Bitmap, OCCUR_Once);
}

Gura_ImplementMethod(wx_MemoryDC, SelectObject)
{
	Signal &sig = env.GetSignal();
	Object_wx_MemoryDC *pThis = Object_wx_MemoryDC::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxBitmap *bitmap = Object_wx_Bitmap::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SelectObject(*bitmap);
	return Value::Nil;
}

Gura_DeclareMethod(wx_MemoryDC, SelectObjectAsSource)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "bitmap", VTYPE_wx_Bitmap, OCCUR_Once);
}

Gura_ImplementMethod(wx_MemoryDC, SelectObjectAsSource)
{
	Signal &sig = env.GetSignal();
	Object_wx_MemoryDC *pThis = Object_wx_MemoryDC::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxBitmap *bitmap = Object_wx_Bitmap::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SelectObjectAsSource(*bitmap);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxMemoryDC
//----------------------------------------------------------------------------
Object_wx_MemoryDC::~Object_wx_MemoryDC()
{
}

Object *Object_wx_MemoryDC::Clone() const
{
	return nullptr;
}

String Object_wx_MemoryDC::ToString(bool exprFlag)
{
	String rtn("<wx.MemoryDC:");
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
// Class implementation for wxMemoryDC
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MemoryDC)
{
	Gura_AssignFunction(MemoryDCEmpty);
	Gura_AssignFunction(MemoryDC);
	Gura_AssignMethod(wx_MemoryDC, SelectObject);
	Gura_AssignMethod(wx_MemoryDC, SelectObjectAsSource);
}

Gura_ImplementDescendantCreator(wx_MemoryDC)
{
	return new Object_wx_MemoryDC((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerTrue);
}

Gura_EndModuleScope(wx)
