//=============================================================================
// Gura class: Sequence
//=============================================================================
#ifndef __GURA_CLASS_SEQUENCE_H__
#define __GURA_CLASS_SEQUENCE_H__

#include "Class.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Class_Sequence
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_Sequence : public Class {
public:
	Class_Sequence(Environment *pEnvOuter);
	virtual void Prepare(Environment &env);
	virtual bool CastFrom(Environment &env, Value &value, const Declaration *pDecl);
	virtual bool Serialize(Environment &env, Stream &stream, const Value &value) const;
	virtual bool Deserialize(Environment &env, Stream &stream, Value &value) const;
};

}

#endif
