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
	virtual void DoPrepare(Environment &env);
	virtual bool CastFrom(Environment &env, Value &value, ULong flags);
};

//-----------------------------------------------------------------------------
// Object_memory
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Object_memory : public Object {
public:
	class GURA_DLLDECLARE PointerEx : public Pointer {
	protected:
		AutoPtr<Object_memory> _pObjMemory;
	public:
		PointerEx(size_t offset, Object_memory *pObjMemory);
		PointerEx(const PointerEx &ptr);
		inline Object_memory *GetMemoryObj() { return _pObjMemory.get(); }
		inline const Object_memory *GetMemoryObj() const { return _pObjMemory.get(); }
		inline Memory &GetMemory() { return _pObjMemory->GetMemory(); }
		inline const Memory &GetMemory() const { return _pObjMemory->GetMemory(); }
	public:
		// virtual functions for Packer
		virtual bool StorePrepare(Signal &sig, size_t bytes);
		virtual void StoreBuffer(const void *buff, size_t bytes);
		virtual const UChar *ExtractPrepare(Signal &sig, size_t bytes, bool exceedErrorFlag);
	public:
		// virtual functions for Pointer
		virtual Pointer *Clone() const;
		virtual Object *GetTarget() const;
		virtual const UChar *GetPointerC() const;
		virtual UChar *GetWritablePointerC() const;
		virtual size_t GetEntireSize() const;
		virtual bool IsWritable() const;
	};
public:
	Gura_DeclareObjectAccessor(memory)
private:
	AutoPtr<Memory> _pMemory;
public:
	Object_memory(Environment &env, Memory *pMemory);
	Object_memory(Class *pClass, Memory *pMemory);
	inline Memory &GetMemory() { return *_pMemory; }
	inline const Memory &GetMemory() const { return *_pMemory; }
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
