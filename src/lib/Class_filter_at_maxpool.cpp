//=============================================================================
// Gura class: filter@maxpool
//=============================================================================
#include "stdafx.h"

namespace Gura {

static const char *helpDoc_en = R"**(
)**";

//-----------------------------------------------------------------------------
// Object_filter_at_maxpool
//-----------------------------------------------------------------------------
Object_filter_at_maxpool::Object_filter_at_maxpool(Environment &env) :
	Object(env.LookupClass(VTYPE_filter_at_maxpool))
{
}

Object *Object_filter_at_maxpool::Clone() const
{
	return nullptr;
}
	
String Object_filter_at_maxpool::ToString(bool exprFlag)
{
	String str;
	str += "<filter@maxpool:";
	str += ">";
	return str;
}

//-----------------------------------------------------------------------------
// Implementation of functions
//-----------------------------------------------------------------------------
// filter@maxpool():map {block?}
Gura_DeclareFunctionAlias(filter_at_maxpool, "filter@maxpool")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(env.LookupClass(VTYPE_filter_at_maxpool));
	AddHelp(
		Gura_Symbol(en),
		"Creates a `filter@maxpool` instance.\n");
}

Gura_ImplementFunction(filter_at_maxpool)
{
	Object_filter_at_maxpool *pObj = new Object_filter_at_maxpool(env);
	return ReturnValue(env, arg, Value(pObj));
}

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_filter_at_maxpool::Class_filter_at_maxpool(Environment *pEnvOuter) :
	ClassFundamental(pEnvOuter, VTYPE_filter_at_maxpool)
{
}

void Class_filter_at_maxpool::DoPrepare(Environment &env)
{
	// function assignment
	Gura_AssignFunction(filter_at_maxpool);
	// help document
	AddHelpTemplate(env, Gura_Symbol(en), helpDoc_en);
}

Object *Class_filter_at_maxpool::CreateDescendant(Environment &env, Class *pClass)
{
	return nullptr;
}

}
