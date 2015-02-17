//=============================================================================
// Gura class: undefined
//=============================================================================
#ifndef __GURA_CLASS_UNDEFINED_H__
#define __GURA_CLASS_UNDEFINED_H__

#include "Class.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Class_undefined
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_undefined : public Class {
public:
	Class_undefined(Environment *pEnvOuter);
	virtual void Prepare(Environment &env);
	virtual bool CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl);
	virtual bool Serialize(Environment &env, Signal sig, Stream &stream, const Value &value) const;
	virtual bool Deserialize(Environment &env, Signal sig, Stream &stream, Value &value) const;
	virtual bool Format_d(Signal sig, Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const;
	virtual bool Format_u(Signal sig, Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const;
	virtual bool Format_b(Signal sig, Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const;
	virtual bool Format_o(Signal sig, Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const;
	virtual bool Format_x(Signal sig, Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const;
	virtual bool Format_e(Signal sig, Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const;
	virtual bool Format_f(Signal sig, Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const;
	virtual bool Format_g(Signal sig, Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const;
	virtual bool Format_s(Signal sig, Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const;
	virtual bool Format_c(Signal sig, Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const;
};

}

#endif
