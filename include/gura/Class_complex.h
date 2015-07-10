//=============================================================================
// Gura class: complex
//=============================================================================
#ifndef __GURA_CLASS_COMPLEX_H__
#define __GURA_CLASS_COMPLEX_H__

#include "Class.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Class_complex
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_complex : public Class {
public:
	Class_complex(Environment *pEnvOuter);
	virtual void Prepare(Environment &env);
	virtual Value GetPropPrimitive(Environment &env, Signal &sig, const Value &valueThis,
			const Symbol *pSymbol, const SymbolSet &attrs, bool &evaluatedFlag) const;
	virtual bool CastFrom(Environment &env, Signal &sig, Value &value, const Declaration *pDecl);
	virtual bool Serialize(Environment &env, Signal &sig, Stream &stream, const Value &value) const;
	virtual bool Deserialize(Environment &env, Signal &sig, Stream &stream, Value &value) const;
	virtual bool Format_e(Signal &sig, Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const;
	virtual bool Format_f(Signal &sig, Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const;
	virtual bool Format_g(Signal &sig, Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const;
};

}

#endif
