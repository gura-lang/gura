//----------------------------------------------------------------------------
// wxMsgCatalog
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxMsgCatalog
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxMsgCatalog
//----------------------------------------------------------------------------
Object_wx_MsgCatalog::~Object_wx_MsgCatalog()
{
}

Object *Object_wx_MsgCatalog::Clone() const
{
	return nullptr;
}

String Object_wx_MsgCatalog::ToString(bool exprFlag)
{
	String rtn("<wx.MsgCatalog:");
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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_MsgCatalog, __CreateFromFile, "CreateFromFile")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "domain", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MsgCatalog, __CreateFromFile)
{
	Object_wx_MsgCatalog *pThis = Object_wx_MsgCatalog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& filename = arg.GetNumber(0)
	//const wxString& domain = arg.GetNumber(1)
	//wxMsgCatalog* _rtn = pThis->GetEntity()->CreateFromFile(filename, domain);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MsgCatalog, __CreateFromData, "CreateFromData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "domain", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MsgCatalog, __CreateFromData)
{
	Object_wx_MsgCatalog *pThis = Object_wx_MsgCatalog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxScopedCharBuffer& data = arg.GetNumber(0)
	//const wxString& domain = arg.GetNumber(1)
	//wxMsgCatalog* _rtn = pThis->GetEntity()->CreateFromData(data, domain);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxMsgCatalog
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MsgCatalog)
{
	// Class assignment
	Gura_AssignValueEx("MsgCatalog", Reference());
	// Method assignment
	Gura_AssignMethod(wx_MsgCatalog, __CreateFromFile);
	Gura_AssignMethod(wx_MsgCatalog, __CreateFromData);
}

Gura_ImplementDescendantCreator(wx_MsgCatalog)
{
	return new Object_wx_MsgCatalog((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
