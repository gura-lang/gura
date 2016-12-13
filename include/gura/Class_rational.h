//=============================================================================
// Gura class: rational
//=============================================================================
#ifndef __GURA_CLASS_RATIONAL_H__
#define __GURA_CLASS_RATIONAL_H__

#include "Class.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Class_rational
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_rational : public Class {
public:
	Class_rational(Environment *pEnvOuter);
	virtual void Prepare(Environment &env);
	//virtual Value GetPropPrimitive(const Value &valueThis,
	//		const Symbol *pSymbol, const SymbolSet &attrs, bool &evaluatedFlag) const;
	virtual bool CastFrom(Environment &env, Value &value, const Declaration *pDecl);
	virtual bool Serialize(Environment &env, Stream &stream, const Value &value) const;
	virtual bool Deserialize(Environment &env, Stream &stream, Value &value) const;
	virtual bool Format_d(Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const;
};

}

#endif
