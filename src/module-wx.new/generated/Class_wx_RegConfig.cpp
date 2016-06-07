//----------------------------------------------------------------------------
// wxRegConfig
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRegConfig
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRegConfig
//----------------------------------------------------------------------------
Object_wx_RegConfig::~Object_wx_RegConfig()
{
}

Object *Object_wx_RegConfig::Clone() const
{
	return nullptr;
}

String Object_wx_RegConfig::ToString(bool exprFlag)
{
	String rtn("<wx.RegConfig:");
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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__RegConfig, "RegConfig")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "appName", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "vendorName", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "localFilename", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "globalFilename", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_RegConfig));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__RegConfig)
{
	//const wxString& appName = arg.GetNumber(0)
	//const wxString& vendorName = arg.GetNumber(1)
	//const wxString& localFilename = arg.GetNumber(2)
	//const wxString& globalFilename = arg.GetNumber(3)
	//long style = arg.GetNumber(4)
	//wxRegConfig(appName, vendorName, localFilename, globalFilename, style);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRegConfig
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RegConfig)
{
	// Constructor assignment
	Gura_AssignFunction(__RegConfig);
}

Gura_ImplementDescendantCreator(wx_RegConfig)
{
	return new Object_wx_RegConfig((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
