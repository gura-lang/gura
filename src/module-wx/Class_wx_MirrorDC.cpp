//----------------------------------------------------------------------------
// wxMirrorDC
// extracted from mirrordc.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_MirrorDC: public wxMirrorDC, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_MirrorDC *_pObj;
public:
	inline wx_MirrorDC(wxDC& dc, bool mirror) : wxMirrorDC(dc, mirror), _pObj(nullptr) {}
	~wx_MirrorDC();
	inline void AssocWithGura(Object_wx_MirrorDC *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_MirrorDC::~wx_MirrorDC()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_MirrorDC::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxMirrorDC
//----------------------------------------------------------------------------
Gura_DeclareFunction(MirrorDC)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_MirrorDC));
	DeclareArg(env, "dc", VTYPE_wx_DC, OCCUR_Once);
	DeclareArg(env, "mirror", VTYPE_boolean, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(MirrorDC)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxDC *dc = Object_wx_DC::GetObject(args, 0)->GetEntity();
	bool mirror = args.GetBoolean(1);
	wx_MirrorDC *pEntity = new wx_MirrorDC(*dc, mirror);
	Object_wx_MirrorDC *pObj = Object_wx_MirrorDC::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_MirrorDC(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

//----------------------------------------------------------------------------
// Object implementation for wxMirrorDC
//----------------------------------------------------------------------------
Object_wx_MirrorDC::~Object_wx_MirrorDC()
{
}

Object *Object_wx_MirrorDC::Clone() const
{
	return nullptr;
}

String Object_wx_MirrorDC::ToString(bool exprFlag)
{
	String rtn("<wx.MirrorDC:");
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
// Class implementation for wxMirrorDC
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MirrorDC)
{
	Gura_AssignFunction(MirrorDC);
}

Gura_ImplementDescendantCreator(wx_MirrorDC)
{
	return new Object_wx_MirrorDC((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
