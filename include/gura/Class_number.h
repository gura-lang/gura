//=============================================================================
// Gura class: number
//=============================================================================
#ifndef __GURA_CLASS_NUMBER_H__
#define __GURA_CLASS_NUMBER_H__

#include "Class.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Class_number
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_number : public Class {
public:
	Class_number(Environment *pEnvOuter);
	virtual void Prepare(Environment &env);
	virtual Value GetPropPrimitive(const Value &valueThis,
			const Symbol *pSymbol, const SymbolSet &attrs, bool &evaluatedFlag) const;
	virtual bool CastFrom(Environment &env, Value &value, const Declaration *pDecl);
	virtual bool Serialize(Environment &env, Stream &stream, const Value &value) const;
	virtual bool Deserialize(Environment &env, Stream &stream, Value &value) const;
	virtual bool Format_d(Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const;
	virtual bool Format_u(Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const;
	virtual bool Format_b(Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const;
	virtual bool Format_o(Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const;
	virtual bool Format_x(Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const;
	virtual bool Format_e(Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const;
	virtual bool Format_f(Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const;
	virtual bool Format_g(Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const;
	virtual bool Format_c(Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const;
};

}

#endif
