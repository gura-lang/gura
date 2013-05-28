//-----------------------------------------------------------------------------
// Gura midi module
//-----------------------------------------------------------------------------
#ifndef __MODULE_MIDI_H__
#define __MODULE_MIDI_H__
#include <gura.h>
#include "MIDIHandle.h"

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
// Class declaration for midi.devinfo
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(devinfo);

class Object_devinfo : public Object {
public:
	Gura_DeclareObjectAccessor(devinfo)
public:
	inline Object_devinfo(Environment &env) : Object(Gura_UserClass(devinfo)) {}
	virtual Object *Clone() const;
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(Signal sig, bool exprFlag);
};

//-----------------------------------------------------------------------------
// Class declaration for midi.device
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(device);

class Object_device : public Object {
public:
	Gura_DeclareObjectAccessor(device)
private:
	MIDIHandle _handle;
public:
	inline Object_device(Environment &env) : Object(Gura_UserClass(device)) {}
	virtual Object *Clone() const;
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(Signal sig, bool exprFlag);
	inline MIDIHandle &GetHandle() { return _handle; }
};

}}

#endif
