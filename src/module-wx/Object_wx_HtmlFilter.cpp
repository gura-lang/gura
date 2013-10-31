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
	Gura::Signal _sig;
	Object_wx_HtmlFilter *_pObj;
public:
	//inline wx_HtmlFilter() : wxHtmlFilter(), _sig(NULL), _pObj(NULL) {}
	~wx_HtmlFilter();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_HtmlFilter *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_HtmlFilter::~wx_HtmlFilter()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_HtmlFilter::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlFilter
//----------------------------------------------------------------------------
Gura_DeclareFunction(HtmlFilterEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_HtmlFilter));
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(HtmlFilterEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wx_HtmlFilter *pEntity = new wx_HtmlFilter();
	Object_wx_HtmlFilter *pObj = Object_wx_HtmlFilter::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_HtmlFilter(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlFilter, CanRead)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "file", VTYPE_wx_FSFile, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlFilter, CanRead)
{
	Object_wx_HtmlFilter *pThis = Object_wx_HtmlFilter::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxFSFile *file = Object_wx_FSFile::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->CanRead(*file);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_HtmlFilter, ReadFile)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "file", VTYPE_wx_FSFile, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlFilter, ReadFile)
{
	Object_wx_HtmlFilter *pThis = Object_wx_HtmlFilter::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxFSFile *file = Object_wx_FSFile::GetObject(args, 0)->GetEntity();
	wxString rtn = pThis->GetEntity()->ReadFile(*file);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

//----------------------------------------------------------------------------
// Object implementation for wxHtmlFilter
//----------------------------------------------------------------------------
Object_wx_HtmlFilter::~Object_wx_HtmlFilter()
{
}

Object *Object_wx_HtmlFilter::Clone() const
{
	return NULL;
}

String Object_wx_HtmlFilter::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.HtmlFilter:");
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
	return new Object_wx_HtmlFilter((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
