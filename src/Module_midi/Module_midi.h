//-----------------------------------------------------------------------------
// Gura midi module
//-----------------------------------------------------------------------------
#ifndef __MODULE_MIDI_H__
#define __MODULE_MIDI_H__
#include <gura.h>
#include "Port.h"

Gura_BeginModule(midi)

//-----------------------------------------------------------------------------
// Class declaration for midi.smf
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(smf);

class Object_smf : public Object {
public:
	Gura_DeclareObjectAccessor(smf)
public:
	inline Object_smf(Environment &env) : Object(Gura_UserClass(smf)) {}
	virtual Object *Clone() const;
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(Signal sig, bool exprFlag);
};

//-----------------------------------------------------------------------------
// Class declaration for midi.portinfo
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(portinfo);

class Object_portinfo : public Object {
public:
	Gura_DeclareObjectAccessor(portinfo)
public:
	inline Object_portinfo(Environment &env) : Object(Gura_UserClass(portinfo)) {}
	virtual Object *Clone() const;
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(Signal sig, bool exprFlag);
};

//-----------------------------------------------------------------------------
// Class declaration for midi.port
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(port);

class Object_port : public Object {
public:
	Gura_DeclareObjectAccessor(port)
private:
	Port _port;
public:
	inline Object_port(Environment &env) : Object(Gura_UserClass(port)) {}
	virtual Object *Clone() const;
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(Signal sig, bool exprFlag);
	inline Port &GetPort() { return _port; }
};

}}

#endif
