#ifndef __GURA_OBJECT_DIRECTORY_H__
#define __GURA_OBJECT_DIRECTORY_H__

#include "Object.h"
#include "Directory.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Class_directory
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_directory : public Class {
public:
	Class_directory(Environment *pEnvOuter);
	virtual bool CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl);
	virtual Object *CreateDescendant(Environment &env, Signal sig, Class *pClass);
	static void OnModuleEntry(Environment &env, Signal sig);
};

//-----------------------------------------------------------------------------
// Object_directory
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Object_directory : public Object {
public:
	Gura_DeclareObjectAccessor(directory)
protected:
	AutoPtr<Directory> _pDirectory;
public:
	inline Object_directory(Environment &env, Directory *pDirectory) :
						Object(env.LookupClass(VTYPE_directory)), _pDirectory(pDirectory) {}
	inline Object_directory(Class *pClass, Directory *pDirectory) :
						Object(pClass), _pDirectory(pDirectory) {}
	inline Directory &GetDirectory() { return *_pDirectory; }
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(Signal sig, bool exprFlag);
};

}

#endif
