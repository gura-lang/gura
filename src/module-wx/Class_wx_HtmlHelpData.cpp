//----------------------------------------------------------------------------
// wxHtmlHelpData
// extracted from hthlpdat.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_HtmlHelpData: public wxHtmlHelpData, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_HtmlHelpData *_pObj;
public:
	inline wx_HtmlHelpData() : wxHtmlHelpData(), _pObj(nullptr) {}
	~wx_HtmlHelpData();
	inline void AssocWithGura(Object_wx_HtmlHelpData *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_HtmlHelpData::~wx_HtmlHelpData()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_HtmlHelpData::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlHelpData
//----------------------------------------------------------------------------
Gura_DeclareFunction(HtmlHelpDataEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_HtmlHelpData));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(HtmlHelpDataEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_HtmlHelpData *pEntity = new wx_HtmlHelpData();
	Object_wx_HtmlHelpData *pObj = Object_wx_HtmlHelpData::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_HtmlHelpData(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareMethod(wx_HtmlHelpData, AddBook)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "book_url", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlHelpData, AddBook)
{
	Object_wx_HtmlHelpData *pThis = Object_wx_HtmlHelpData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString book_url = wxString::FromUTF8(args.GetString(0));
	bool rtn = pThis->GetEntity()->AddBook(book_url);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_HtmlHelpData, FindPageById)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlHelpData, FindPageById)
{
	Object_wx_HtmlHelpData *pThis = Object_wx_HtmlHelpData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int id = args.GetInt(0);
	wxString rtn = pThis->GetEntity()->FindPageById(id);
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_HtmlHelpData, FindPageByName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "page", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlHelpData, FindPageByName)
{
	Object_wx_HtmlHelpData *pThis = Object_wx_HtmlHelpData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString page = wxString::FromUTF8(args.GetString(0));
	wxString rtn = pThis->GetEntity()->FindPageByName(page);
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_HtmlHelpData, GetBookRecArray)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlHelpData, GetBookRecArray)
{
#if 0
	Object_wx_HtmlHelpData *pThis = Object_wx_HtmlHelpData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	const wxHtmlBookRecArray &rtn = pThis->GetEntity()->GetBookRecArray();
	return ReturnValue(env, args, Value(new Object_wx_HtmlBookRecArray(new wxHtmlBookRecArray(rtn), nullptr, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlHelpData, GetContentsArray)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlHelpData, GetContentsArray)
{
#if 0
	Object_wx_HtmlHelpData *pThis = Object_wx_HtmlHelpData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	const wxHtmlHelpDataItems &rtn = pThis->GetEntity()->GetContentsArray();
	return ReturnValue(env, args, Value(new Object_wx_HtmlHelpDataItems(new wxHtmlHelpDataItems(rtn), nullptr, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlHelpData, GetIndexArray)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlHelpData, GetIndexArray)
{
#if 0
	Object_wx_HtmlHelpData *pThis = Object_wx_HtmlHelpData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	const wxHtmlHelpDataItems &rtn = pThis->GetEntity()->GetIndexArray();
	return ReturnValue(env, args, Value(new Object_wx_HtmlHelpDataItems(new wxHtmlHelpDataItems(rtn), nullptr, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlHelpData, SetTempDir)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "path", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlHelpData, SetTempDir)
{
	Object_wx_HtmlHelpData *pThis = Object_wx_HtmlHelpData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString path = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetTempDir(path);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxHtmlHelpData
//----------------------------------------------------------------------------
Object_wx_HtmlHelpData::~Object_wx_HtmlHelpData()
{
}

Object *Object_wx_HtmlHelpData::Clone() const
{
	return nullptr;
}

String Object_wx_HtmlHelpData::ToString(bool exprFlag)
{
	String rtn("<wx.HtmlHelpData:");
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
// Class implementation for wxHtmlHelpData
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlHelpData)
{
	Gura_AssignFunction(HtmlHelpDataEmpty);
	Gura_AssignMethod(wx_HtmlHelpData, AddBook);
	Gura_AssignMethod(wx_HtmlHelpData, FindPageById);
	Gura_AssignMethod(wx_HtmlHelpData, FindPageByName);
	Gura_AssignMethod(wx_HtmlHelpData, GetBookRecArray);
	Gura_AssignMethod(wx_HtmlHelpData, GetContentsArray);
	Gura_AssignMethod(wx_HtmlHelpData, GetIndexArray);
	Gura_AssignMethod(wx_HtmlHelpData, SetTempDir);
}

Gura_ImplementDescendantCreator(wx_HtmlHelpData)
{
	return new Object_wx_HtmlHelpData((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
