#ifndef __GURA_ENVIRONMENT_H__
#define __GURA_ENVIRONMENT_H__

#include "Value.h"
#include "String.h"

namespace Gura {

class Class;
class Class_function;
class Class_string;
class Class_binary;
class Class_BinaryPtr;
class Class_list;
class Class_matrix;
class Class_dict;
class Class_datetime;
class Class_iterator;
class Class_expr;
class Class_environment;
class Class_error;
class Class_semaphore;
class Class_Struct;

class Module;

class ICallable;
class FunctionCustom;

//-----------------------------------------------------------------------------
// EnvType
//-----------------------------------------------------------------------------
enum EnvType {
	ENVTYPE_invalid,
	ENVTYPE_root,
	ENVTYPE_local,
	ENVTYPE_block,
	ENVTYPE_module,
	ENVTYPE_member,
	ENVTYPE_class,
	ENVTYPE_instance,
	ENVTYPE_method,
	ENVTYPE_lister,
	ENVTYPE_outer,	// this type is not used as type of each actual frame
};

DLLDECLARE const char *GetEnvTypeName(EnvType envType);

//-----------------------------------------------------------------------------
// IntegratedModuleMap
//-----------------------------------------------------------------------------
typedef std::map<int, Module *> IntegratedModuleMap;

//-----------------------------------------------------------------------------
// SeparatedModuleMap
//-----------------------------------------------------------------------------
typedef std::map<String, Module *> SeparatedModuleMap;

//-----------------------------------------------------------------------------
// Module Entry Type
//-----------------------------------------------------------------------------
typedef void (*ModuleEntryType)(Environment &env, Signal sig);
typedef void (*ModuleTerminateType)(Module *pModule);

//-----------------------------------------------------------------------------
// IntegratedModule
//-----------------------------------------------------------------------------
class DLLDECLARE IntegratedModule {
private:
	String _name;
	ModuleEntryType _moduleEntry;
	ModuleTerminateType _moduleTerminate;
public:
	inline IntegratedModule(const char *name,
			ModuleEntryType moduleEntry, ModuleTerminateType moduleTerminate) :
		_name(name), _moduleEntry(moduleEntry), _moduleTerminate(moduleTerminate) {}
	inline void ModuleEntry(Environment &env, Signal sig) {
		(*_moduleEntry)(env, sig);
	}
	inline void ModuleTerminate(Module *pModule) {
		(*_moduleTerminate)(pModule);
	}
	bool IsMatch(const SymbolList &symbolOfModule) const;
};

//-----------------------------------------------------------------------------
// IntegratedModuleOwner
//-----------------------------------------------------------------------------
class DLLDECLARE IntegratedModuleOwner : public std::vector<IntegratedModule *> {
public:
	~IntegratedModuleOwner();
};

//-----------------------------------------------------------------------------
// ModuleIntegrator
//-----------------------------------------------------------------------------
class DLLDECLARE ModuleIntegrator {
public:
	ModuleIntegrator(const char *name,
			ModuleEntryType moduleEntry, ModuleTerminateType moduleTerminate);
};

//-----------------------------------------------------------------------------
// Environment
//-----------------------------------------------------------------------------
class DLLDECLARE Environment {
public:
	class DLLDECLARE Global {
	private:
		IntegratedModuleMap _integratedModuleMap;
		SeparatedModuleMap	_separatedModuleMap;
		StringList			_workingDirList;
	public:
		SymbolPool			*_pSymbolPool;
		ValueTypePool		*_pValueTypePool;
		bool				_echoFlag;
		Function			*_pFunc_Pos;
		Function			*_pFunc_Neg;
		Function			*_pFunc_Invert;
		Function			*_pFunc_Not;
		Function			*_pFunc_Plus;
		Function			*_pFunc_Minus;
		Function			*_pFunc_Multiply;
		Function			*_pFunc_Divide;
		Function			*_pFunc_Modulo;
		Function			*_pFunc_format;
		Function			*_pFunc_Power;
		Function			*_pFunc_Equal;
		Function			*_pFunc_NotEqual;
		Function			*_pFunc_Greater;
		Function			*_pFunc_Less;
		Function			*_pFunc_GreaterEq;
		Function			*_pFunc_LessEq;
		Function			*_pFunc_Compare;
		Function			*_pFunc_ContainCheck;
		Function			*_pFunc_Or;
		Function			*_pFunc_And;
		Function			*_pFunc_Xor;
		Function			*_pFunc_ShiftL;
		Function			*_pFunc_ShiftR;
		Function			*_pFunc_OrOr;
		Function			*_pFunc_AndAnd;
		Function			*_pFunc_Sequence;
		Function			*_pFunc_SequenceInf;
		Module				*_pModule_sys;
		Stream				*_pConsole;
		Stream				*_pConsoleError;
	public:
		Global();
		~Global();
		inline static void Delete(Global *pGlobal) {
			delete pGlobal;
		}
		void Prepare();
		Class *LookupClass(ValueType valType) const;
		Module *LookupIntegratedModule(int id) const;
		void RegisterIntegratedModule(int id, Module *pModule);
		Module *LookupSeparatedModule(const char *pathName) const;
		void RegisterSeparatedModule(const char *pathName, Module *pModule);
	};
	class DLLDECLARE Frame {
	private:
		int _cntRef;
		EnvType _envType;
		Global *_pGlobal;
		std::auto_ptr<ValueMap> _pValueMap;
		std::auto_ptr<ValueTypeMap> _pValueTypeMap;
	public:
		Frame(const Frame &frame);
		Frame(EnvType envType, Global *pGlobal);
		virtual ~Frame();
		inline Frame *IncRef() { _cntRef++; return this; }
		inline int DecRef() { if (_cntRef > 0) _cntRef--; return _cntRef; }
		inline int GetRefCnt() const { return _cntRef; }
		static void Delete(Frame *pFrame);
		inline Frame *Clone() const { return new Frame(*this); }
		inline EnvType GetEnvType() const { return _envType; }
		inline const char *GetTypeName() const { return GetEnvTypeName(_envType); }
		inline bool IsType(EnvType envType) const { return _envType == envType; }
		inline Global *GetGlobal() { return _pGlobal; }
		inline Global *GetGlobal() const { return _pGlobal; }
		inline const ValueMap &GetValueMap() const {
			return (_pValueMap.get() == NULL)? ValueMap::Null : *_pValueMap;
		}
		void AssignValue(const Symbol *pSymbol, const Value &value);
		void RemoveValue(const Symbol *pSymbol);
		Value *LookupValue(const Symbol *pSymbol);
		void AssignValueType(const ValueTypeInfo *pValueTypeInfo);
		const ValueTypeInfo *LookupValueType(const Symbol *pSymbol) const;
		void DbgPrint() const;
	};
	class DLLDECLARE FrameList : public std::list<Frame *> {
	public:
		~FrameList();
		inline bool IsExist(Frame *pFrame) const {
			return std::find(begin(), end(), pFrame) != end();
		}
	};
	typedef std::map<const Symbol *, Frame *, Symbol::KeyCompare_UniqNumber> FrameCache;
private:
	FrameList _frameList;
	FrameCache *_pFrameCache;
	int _cntSuperSkip;
	static IntegratedModuleOwner *_pIntegratedModuleOwner;
public:
	Environment(const Environment &env);
	Environment(const Environment *pEnvOuter, EnvType envType);
	virtual ~Environment();
	inline FrameList &GetFrameList()			{ return _frameList;						}
	inline const FrameList &GetFrameList() const{ return _frameList;						}
	inline Frame &GetTopFrame()					{ return *_frameList.front();				}
	inline const Frame &GetTopFrame() const		{ return *_frameList.front();				}
	inline Frame &GetBottomFrame()				{ return *_frameList.back();				}
	inline const Frame &GetBottomFrame() const	{ return *_frameList.back();				}
	inline EnvType GetEnvType() const			{ return GetTopFrame().GetEnvType(); }
	inline const char *GetTypeName() const		{ return GetTopFrame().GetTypeName(); }
	inline bool IsType(EnvType envType) const	{ return GetTopFrame().IsType(envType); }
	inline Global *GetGlobal()					{ return GetTopFrame().GetGlobal();			}
	inline Global *GetGlobal() const			{ return GetTopFrame().GetGlobal();			}
	inline void SetSuperSkipCount(int cntSuperSkip) { _cntSuperSkip = cntSuperSkip; }
	inline const Function *GetFunc_Pos()		{ return GetGlobal()->_pFunc_Pos;			}
	inline const Function *GetFunc_Neg()		{ return GetGlobal()->_pFunc_Neg;			}
	inline const Function *GetFunc_Invert()		{ return GetGlobal()->_pFunc_Invert;		}
	inline const Function *GetFunc_Not()		{ return GetGlobal()->_pFunc_Not;			}
	inline const Function *GetFunc_Plus()		{ return GetGlobal()->_pFunc_Plus;			}
	inline const Function *GetFunc_Minus()		{ return GetGlobal()->_pFunc_Minus;		}
	inline const Function *GetFunc_Multiply()	{ return GetGlobal()->_pFunc_Multiply;		}
	inline const Function *GetFunc_Divide()		{ return GetGlobal()->_pFunc_Divide;		}
	inline const Function *GetFunc_Modulo()		{ return GetGlobal()->_pFunc_Modulo;		}
	inline const Function *GetFunc_format()		{ return GetGlobal()->_pFunc_format;		}
	inline const Function *GetFunc_Power()		{ return GetGlobal()->_pFunc_Power;		}
	inline const Function *GetFunc_Equal()		{ return GetGlobal()->_pFunc_Equal;		}
	inline const Function *GetFunc_NotEqual()	{ return GetGlobal()->_pFunc_NotEqual;		}
	inline const Function *GetFunc_Greater()	{ return GetGlobal()->_pFunc_Greater;		}
	inline const Function *GetFunc_Less()		{ return GetGlobal()->_pFunc_Less;			}
	inline const Function *GetFunc_GreaterEq()	{ return GetGlobal()->_pFunc_GreaterEq;	}
	inline const Function *GetFunc_LessEq()		{ return GetGlobal()->_pFunc_LessEq;		}
	inline const Function *GetFunc_Compare()	{ return GetGlobal()->_pFunc_Compare;		}
	inline const Function *GetFunc_ContainCheck() { return GetGlobal()->_pFunc_ContainCheck;	}
	inline const Function *GetFunc_Or()			{ return GetGlobal()->_pFunc_Or;			}
	inline const Function *GetFunc_And()		{ return GetGlobal()->_pFunc_And;			}
	inline const Function *GetFunc_Xor()		{ return GetGlobal()->_pFunc_Xor;			}
	inline const Function *GetFunc_ShiftL()		{ return GetGlobal()->_pFunc_ShiftL;		}
	inline const Function *GetFunc_ShiftR()		{ return GetGlobal()->_pFunc_ShiftR;		}
	inline const Function *GetFunc_OrOr()		{ return GetGlobal()->_pFunc_OrOr;			}
	inline const Function *GetFunc_AndAnd()		{ return GetGlobal()->_pFunc_AndAnd;		}
	inline const Function *GetFunc_Sequence()	{ return GetGlobal()->_pFunc_Sequence;		}
	inline const Function *GetFunc_SequenceInf(){ return GetGlobal()->_pFunc_SequenceInf;	}
	inline Module *GetModule_sys()				{ return GetGlobal()->_pModule_sys;			}
	inline void SetEchoFlag(bool echoFlag)		{ GetGlobal()->_echoFlag = echoFlag;		}
	inline bool GetEchoFlag() const				{ return GetGlobal()->_echoFlag;			}
	void AddLackingFrame(Environment *pEnv);
	void CacheFrame(const Symbol *pSymbol, Frame *pFrame);
	void AssignValue(const Symbol *pSymbol, const Value &value, bool escalateFlag);
	void RemoveValue(const Symbol *pSymbol);
	Function *AssignFunction(Function *pFunc);
	Value *LookupValue(const Symbol *pSymbol, bool escalateFlag);
	inline const Value *LookupValue(const Symbol *pSymbol, bool escalateFlag) const {
		return const_cast<const Value *>(
				const_cast<Environment *>(this)->LookupValue(pSymbol, escalateFlag));
	}
	Function *LookupFunction(const Symbol *pSymbol, bool escalateFlag) const;
	FunctionCustom *LookupFunctionCustom(const Symbol *pSymbol, bool escalateFlag) const;
	void AssignValueType(const ValueTypeInfo *pValueTypeInfo);
	const ValueTypeInfo *LookupValueType(const SymbolList &symbolList) const;
	const ValueTypeInfo *LookupValueType(const Symbol *pSymbol) const;
	virtual Value DoPropGet(Signal sig, const Symbol *pSymbol, bool &evaluatedFlag);
	virtual Value DoPropSet(Signal sig, const Symbol *pSymbol,
										const Value &value, bool &evaluatedFlag);
	virtual ICallable *GetCallable(Signal sig, const Symbol *pSymbol);
	Value PropGet(Signal sig, const Symbol *pSymbol, const Value *pValueDefault = NULL);
	inline Class *LookupClass(ValueType valType) const {
		return GetGlobal()->LookupClass(valType);
	}
	void AssignModule(Module *pModule);
	bool ImportModules(Signal sig, const char *moduleNames);
	bool ImportModule(Signal sig, const Expr *pExpr, const Symbol *pSymbolAlias,
			const SymbolSet *pSymbolsToMixIn, bool overwriteFlag);
	bool ImportModule(Signal sig, const SymbolList &symbolOfModule,
			const Symbol *pSymbolAlias = NULL, const SymbolSet *pSymbolsToMixIn = NULL,
			bool overwriteFlag = true, bool assignModuleNameFlag = true);
	static bool IsBinaryModule(const char *pathName);
	bool AddModuleSearchPath(Signal sig, const StringList &strList);
	virtual bool IsModule() const;
	virtual bool IsClass() const;
	virtual bool IsObject() const;
	inline void Error(const char *fileName, int lineNo, const char *str) {
		::fprintf(stderr, "fatal error at line.%d in %s: %s\n", lineNo, fileName, str);
	}
	void DbgPrint() const;
	const char *GetPrompt(bool indentFlag);
	void SetConsole(bool errorOutputFlag, Stream *pConsole);
	Stream *GetConsole(bool errorOutputFlag);
	static void IntegrateModule(const char *name,
			ModuleEntryType moduleEntry, ModuleTerminateType moduleTerminate);
private:
	Module *ImportIntegratedModule(Signal sig, const SymbolList &symbolOfModule);
	Module *ImportSeparatedModule(Signal sig, const SymbolList &symbolOfModule);
	bool SearchSeparatedModuleFile(Signal sig, String &pathName,
						SymbolList::const_iterator ppSymbolOfModule,
						SymbolList::const_iterator ppSymbolOfModuleEnd);
	Module *ImportSeparatedModule_Script(Signal sig, Environment *pEnvOuter,
						const char *pathName, const SymbolList &symbolOfModule);
	Module *ImportSeparatedModule_Binary(Signal sig, Environment *pEnvOuter,
						const char *pathName, const SymbolList &symbolOfModule);
};

typedef std::set<Environment *> EnvironmentSet;

//-----------------------------------------------------------------------------
// EnvironmentRoot
//-----------------------------------------------------------------------------
class DLLDECLARE EnvironmentRoot : public Environment {
public:
	EnvironmentRoot(int argc, const char *argv[]);
	virtual ~EnvironmentRoot();
};

}
#endif
