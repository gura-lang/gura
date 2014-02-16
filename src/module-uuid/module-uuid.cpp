//-----------------------------------------------------------------------------
// Gura module: uuid
//-----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleBody(uuid)

//-----------------------------------------------------------------------------
// Gura module functions: uuid
//-----------------------------------------------------------------------------
// uuid.generate():[upper]
Gura_DeclareFunction(generate)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, 
	"Generates a Universal Unique Identifier (UUID). In default, results are output in\n"
	"lower-case characters. Specifying :upper would generates it in upper-case characters.");
	DeclareAttr(Gura_Symbol(upper));
}

Gura_ImplementFunction(generate)
{
	bool upperFlag = args.IsSet(Gura_Symbol(upper));
	char str[64];
#ifdef GURA_ON_MSWIN
	const char *format = upperFlag?
		"%08X-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X" :
		"%08x-%04x-%04x-%02x%02x-%02x%02x%02x%02x%02x%02x";
	GUID guid;
	::CoCreateGuid(&guid);
	::sprintf(str, format,
		guid.Data1, guid.Data2, guid.Data3, guid.Data4[0], guid.Data4[1],
		guid.Data4[2], guid.Data4[3], guid.Data4[4], guid.Data4[5], guid.Data4[6], guid.Data4[7]);
#else
	const char *format = upperFlag?
		"%02X%02X%02X%02X-%02X%02X-%02X%02X-%02X%02X-%02X%02X%02X%02X%02X%02X" :
		"%02x%02x%02x%02x-%02x%02x-%02x%02x-%02x%02x-%02x%02x%02x%02x%02x%02x";
	uuid_t guid;
	::uuid_generate(guid);
	::sprintf(str, format,
		guid[0], guid[1], guid[2], guid[3], guid[4], guid[5], guid[6], guid[7],
		guid[8], guid[9], guid[10], guid[11], guid[12], guid[13], guid[14], guid[15]);
#endif
	return Value(str);
}

// Module entry
Gura_ModuleEntry()
{
	// function assignment
	Gura_AssignFunction(generate);
	return true;
}

Gura_ModuleTerminate()
{
}

Gura_EndModuleBody(uuid, uuid)

Gura_RegisterModule(uuid)
