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
	Gura::Signal _sig;
	Object_wx_MemoryDC *_pObj;
public:
	inline wx_MemoryDC() : wxMemoryDC(), _sig(NULL), _pObj(NULL) {}
	inline wx_MemoryDC(wxBitmap& bitmap) : wxMemoryDC(bitmap), _sig(NULL), _pObj(NULL) {}
	~wx_MemoryDC();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_MemoryDC *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_MemoryDC::~wx_MemoryDC()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_MemoryDC::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxMemoryDC
//----------------------------------------------------------------------------
Gura_DeclareFunction(MemoryDCEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_MemoryDC));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(MemoryDCEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_MemoryDC *pEntity = new wx_MemoryDC();
	Object_wx_MemoryDC *pObj = Object_wx_MemoryDC::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_MemoryDC(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareFunction(MemoryDC)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_MemoryDC));
	DeclareArg(env, "bitmap", VTYPE_wx_Bitmap, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(MemoryDC)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxBitmap *bitmap = Object_wx_Bitmap::GetObject(args, 0)->GetEntity();
	wx_MemoryDC *pEntity = new wx_MemoryDC(*bitmap);
	Object_wx_MemoryDC *pObj = Object_wx_MemoryDC::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_MemoryDC(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_MemoryDC, SelectObject)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "bitmap", VTYPE_wx_Bitmap, OCCUR_Once);
}

Gura_ImplementMethod(wx_MemoryDC, SelectObject)
{
	Object_wx_MemoryDC *pThis = Object_wx_MemoryDC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxBitmap *bitmap = Object_wx_Bitmap::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SelectObject(*bitmap);
	return Value::Null;
}

Gura_DeclareMethod(wx_MemoryDC, SelectObjectAsSource)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "bitmap", VTYPE_wx_Bitmap, OCCUR_Once);
}

Gura_ImplementMethod(wx_MemoryDC, SelectObjectAsSource)
{
	Object_wx_MemoryDC *pThis = Object_wx_MemoryDC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxBitmap *bitmap = Object_wx_Bitmap::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SelectObjectAsSource(*bitmap);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxMemoryDC
//----------------------------------------------------------------------------
Object_wx_MemoryDC::~Object_wx_MemoryDC()
{
}

Object *Object_wx_MemoryDC::Clone() const
{
	return NULL;
}

String Object_wx_MemoryDC::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.MemoryDC:");
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
	return new Object_wx_MemoryDC((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
