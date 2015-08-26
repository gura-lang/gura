//----------------------------------------------------------------------------
// wxHtmlFilter
// extracted from htfilter.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_HtmlFilter: public wxHtmlFilter, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_HtmlFilter *_pObj;
public:
	//inline wx_HtmlFilter() : wxHtmlFilter(), _pObj(nullptr) {}
	~wx_HtmlFilter();
	inline void AssocWithGura(Object_wx_HtmlFilter *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_HtmlFilter::~wx_HtmlFilter()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_HtmlFilter::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlFilter
//----------------------------------------------------------------------------
Gura_DeclareFunction(HtmlFilterEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_HtmlFilter));
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(HtmlFilterEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wx_HtmlFilter *pEntity = new wx_HtmlFilter();
	Object_wx_HtmlFilter *pObj = Object_wx_HtmlFilter::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_HtmlFilter(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlFilter, CanRead)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "file", VTYPE_wx_FSFile, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlFilter, CanRead)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlFilter *pThis = Object_wx_HtmlFilter::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxFSFile *file = Object_wx_FSFile::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->CanRead(*file);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_HtmlFilter, ReadFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "file", VTYPE_wx_FSFile, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlFilter, ReadFile)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlFilter *pThis = Object_wx_HtmlFilter::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxFSFile *file = Object_wx_FSFile::GetObject(args, 0)->GetEntity();
	wxString rtn = pThis->GetEntity()->ReadFile(*file);
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

//----------------------------------------------------------------------------
// Object implementation for wxHtmlFilter
//----------------------------------------------------------------------------
Object_wx_HtmlFilter::~Object_wx_HtmlFilter()
{
}

Object *Object_wx_HtmlFilter::Clone() const
{
	return nullptr;
}

String Object_wx_HtmlFilter::ToString(bool exprFlag)
{
	String rtn("<wx.HtmlFilter:");
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
// Class implementation for wxHtmlFilter
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlFilter)
{
	Gura_AssignFunction(HtmlFilterEmpty);
	Gura_AssignMethod(wx_HtmlFilter, CanRead);
	Gura_AssignMethod(wx_HtmlFilter, ReadFile);
}

Gura_ImplementDescendantCreator(wx_HtmlFilter)
{
	return new Object_wx_HtmlFilter((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
