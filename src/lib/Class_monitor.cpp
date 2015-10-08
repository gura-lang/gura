//=============================================================================
// Gura class: monitor
//=============================================================================
#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Object_monitor
//-----------------------------------------------------------------------------
Object_monitor::Object_monitor(const Object_monitor &obj) :
					Object(obj), _pMonitor(obj.GetMonitor()->Reference())
{
}

Object *Object_monitor::Clone() const
{
	return new Object_monitor(*this);
}

String Object_monitor::ToString(bool exprFlag)
{
	String str;
	str += "<monitor:";
	str += ">";
	return str;
}

//-----------------------------------------------------------------------------
// Implementation of functions
//-----------------------------------------------------------------------------
// monitor() {block?}
Gura_DeclareFunction(monitor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(env.LookupClass(VTYPE_monitor));
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Creates a `monitor` instance.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("monitor", "monitor"));
}

Gura_ImplementFunction(monitor)
{
	//AutoPtr<Monitor> pMonitor(new Monitor());
	//return ReturnValue(env, arg, Value(new Object_monitor(env, pMonitor.release())));
	return Value::Nil;
}

//-----------------------------------------------------------------------------
// Implementation of methods
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_monitor::Class_monitor(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_monitor)
{
}

void Class_monitor::Prepare(Environment &env)
{
	Gura_AssignFunction(monitor);
}

Object *Class_monitor::CreateDescendant(Environment &env, Class *pClass)
{
	GURA_ERROREND(env, "this function must not be called");
	return nullptr;
}

}
