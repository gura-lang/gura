//----------------------------------------------------------------------------
// wxMetafileDC
// extracted from metafile.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_MetafileDC: public wxMetafileDC, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_MetafileDC *_pObj;
public:
	inline wx_MetafileDC(const wxString& filename) : wxMetafileDC(filename), _pObj(nullptr) {}
	~wx_MetafileDC();
	inline void AssocWithGura(Object_wx_MetafileDC *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_MetafileDC::~wx_MetafileDC()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_MetafileDC::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxMetafileDC
//----------------------------------------------------------------------------
Gura_DeclareFunction(MetafileDC)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_MetafileDC));
	DeclareArg(env, "filename", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(MetafileDC)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxString filename = wxT("");
	if (args.IsValid(0)) filename = wxString::FromUTF8(args.GetString(0));
	wx_MetafileDC *pEntity = new wx_MetafileDC(filename);
	Object_wx_MetafileDC *pObj = Object_wx_MetafileDC::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_MetafileDC(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
}

Gura_DeclareMethod(wx_MetafileDC, Close)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MetafileDC, Close)
{
	Signal &sig = env.GetSignal();
	Object_wx_MetafileDC *pThis = Object_wx_MetafileDC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxMetafile *rtn = (wxMetafile *)pThis->GetEntity()->Close();
	return ReturnValue(env, args, Value(new Object_wx_Metafile(rtn, nullptr, OwnerFalse)));
}

//----------------------------------------------------------------------------
// Object implementation for wxMetafileDC
//----------------------------------------------------------------------------
Object_wx_MetafileDC::~Object_wx_MetafileDC()
{
}

Object *Object_wx_MetafileDC::Clone() const
{
	return nullptr;
}

String Object_wx_MetafileDC::ToString(bool exprFlag)
{
	String rtn("<wx.MetafileDC:");
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
// Class implementation for wxMetafileDC
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MetafileDC)
{
	Gura_AssignFunction(MetafileDC);
	Gura_AssignMethod(wx_MetafileDC, Close);
}

Gura_ImplementDescendantCreator(wx_MetafileDC)
{
	return new Object_wx_MetafileDC((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
