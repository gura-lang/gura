//=============================================================================
// Gura class: memory
//=============================================================================
#ifndef __GURA_CLASS_MEMORY_H__
#define __GURA_CLASS_MEMORY_H__

#include "Class.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Class_memory
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_memory : public Class {
public:
	Class_memory(Environment *pEnvOuter);
	virtual void Prepare(Environment &env);
	virtual bool CastFrom(Environment &env, Value &value, const Declaration *pDecl);
};

//-----------------------------------------------------------------------------
// Object_memory
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Object_memory : public Object {
public:
	Gura_DeclareObjectAccessor(memory)
private:
	AutoPtr<Memory> _pMemory;
public:
	Object_memory(Environment &env, Memory *pMemory);
	Object_memory(Class *pClass, Memory *pMemory);
	inline Memory *GetMemory() { return _pMemory.get(); }
	inline const Memory *GetMemory() const { return _pMemory.get(); }
	virtual Object *Clone() const;
	virtual bool DoDirProp(Environment &env, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, const Symbol *pSymbol,
						const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value DoSetProp(Environment &env, const Symbol *pSymbol, const Value &value,
						const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(bool exprFlag);
};

}

#endif
