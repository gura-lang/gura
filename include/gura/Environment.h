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
	ENVTYPE_class,
	ENVTYPE_object,
	ENVTYPE_lister,
};

enum EnvRefMode {
	ENVREF_NoEscalate,
	ENVREF_Escalate,
	ENVREF_Restricted,
};

enum OpType {
	OPTYPE_None,
	OPTYPE_Pos,
	OPTYPE_Neg,
	OPTYPE_Invert,
	OPTYPE_Not,
	OPTYPE_Plus,
	OPTYPE_Minus,
	OPTYPE_Multiply,
	OPTYPE_Divide,
	OPTYPE_Modulo,
	OPTYPE_format,
	OPTYPE_Power,
	OPTYPE_Equal,
	OPTYPE_NotEqual,
	OPTYPE_Greater,
	OPTYPE_Less,
	OPTYPE_GreaterEq,
	OPTYPE_LessEq,
	OPTYPE_Compare,
	OPTYPE_ContainCheck,
	OPTYPE_Or,
	OPTYPE_And,
	OPTYPE_Xor,
	OPTYPE_ShiftL,
	OPTYPE_ShiftR,
	OPTYPE_OrOr,
	OPTYPE_AndAnd,
	OPTYPE_Sequence,
	OPTYPE_SequenceInf,
	OPTYPE_max,
};

GURA_DLLDECLARE const char *GetEnvTypeName(EnvType envType);

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
class GURA_DLLDECLARE IntegratedModule {
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
class GURA_DLLDECLARE IntegratedModuleOwner : public std::vector<IntegratedModule *> {
public:
	~IntegratedModuleOwner();
};

//-----------------------------------------------------------------------------
// ModuleIntegrator
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE ModuleIntegrator {
public:
	ModuleIntegrator(const char *name,
			ModuleEntryType moduleEntry, ModuleTerminateType moduleTerminate);
};

//-----------------------------------------------------------------------------
// Environment
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Environment {
public:
	class GURA_DLLDECLARE Global {
	private:
		IntegratedModuleMap _integratedModuleMap;
		SeparatedModuleMap	_separatedModuleMap;
		StringList			_workingDirList;
	public:
		SymbolPool			*_pSymbolPool;
		ValueTypePool		*_pValueTypePool;
		bool				_echoFlag;
		Function			*_pOpFuncTbl[OPTYPE_max];
		Module				*_pModule_sys;
		AutoPtr<Stream>		_pConsoleDumb;
	public:
		Global();
		~Global();
		inline static void Delete(Global *pGlobal) {
			delete pGlobal;
		}
		void Prepare(Signal sig);
		Class *LookupClass(ValueType valType) const;
		Module *LookupIntegratedModule(int id) const;
		void RegisterIntegratedModule(int id, Module *pModule);
		Module *LookupSeparatedModule(const char *pathName) const;
		void RegisterSeparatedModule(const char *pathName, Module *pModule);
		void UnregisterSeparatedModule(const char *pathName);
		Stream *GetConsoleDumb() { return _pConsoleDumb.get(); }
	};
	class GURA_DLLDECLARE Frame {
	private:
		int _cntRef;
		EnvType _envType;
		Global *_pGlobal;
		std::auto_ptr<ValueMap> _pValueMap;
		std::auto_ptr<ValueTypeMap> _pValueTypeMap;
		std::auto_ptr<SymbolSet> _pSymbolsPublic;
	public:
		Frame(const Frame &frame);
		Frame(EnvType envType, Global *pGlobal);
		virtual ~Frame();
		inline static Frame *Reference(const Frame *pFrame) {
			if (pFrame == NULL) return NULL;
			Frame *pFrameCasted = const_cast<Frame *>(pFrame);
			pFrameCasted->_cntRef++;
			return pFrameCasted;
		}
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
		inline const ValueTypeMap &GetValueTypeMap() const {
			return (_pValueTypeMap.get() == NULL)? ValueTypeMap::Null : *_pValueTypeMap;
		}
		inline const SymbolSet &GetSymbolsPublic() const {
			return (_pSymbolsPublic.get() == NULL)? SymbolSet::Null : *_pSymbolsPublic;
		}
		void AssignValue(const Symbol *pSymbol, const Value &value, unsigned long extra);
		void RemoveValue(const Symbol *pSymbol);
		ValueEx *LookupValue(const Symbol *pSymbol);
		void AssignValueType(const ValueTypeInfo *pValueTypeInfo);
		const ValueTypeInfo *LookupValueType(const Symbol *pSymbol) const;
		SymbolSet &PrepareSymbolsPublic();
		void DbgPrint() const;
	};
	class GURA_DLLDECLARE FrameList : public std::list<Frame *> {
	public:
		inline bool IsExist(Frame *pFrame) const {
			return std::find(begin(), end(), pFrame) != end();
		}
		void DbgPrint() const;
	};
	class GURA_DLLDECLARE FrameOwner : public FrameList {
	public:
		~FrameOwner();
		void Clear();
	};
	typedef std::map<const Symbol *, Frame *, Symbol::KeyCompare_UniqNumber> FrameCache;
protected:
	FrameOwner _frameOwner;
	std::auto_ptr<FrameCache> _pFrameCache;
	static IntegratedModuleOwner *_pIntegratedModuleOwner;
public:
	Environment();
	Environment(const Environment &env);
	Environment(const Environment *pEnvOuter, EnvType envType);
	virtual ~Environment();
	inline FrameOwner &GetFrameOwner()			{ return _frameOwner;						}
	inline const FrameOwner &GetFrameOwner() const{ return _frameOwner;						}
	inline Frame *GetTopFrame()					{ return _frameOwner.front();				}
	inline const Frame *GetTopFrame() const		{ return _frameOwner.front();				}
	inline Frame *GetBottomFrame()				{ return _frameOwner.back();				}
	inline const Frame *GetBottomFrame() const	{ return _frameOwner.back();				}
	inline EnvType GetEnvType() const			{ return GetTopFrame()->GetEnvType(); }
	inline const char *GetTypeName() const		{ return GetTopFrame()->GetTypeName(); }
	inline bool IsType(EnvType envType) const	{ return GetTopFrame()->IsType(envType); }
	inline Global *GetGlobal()					{ return GetTopFrame()->GetGlobal();			}
	inline Global *GetGlobal() const			{ return GetTopFrame()->GetGlobal();			}
	inline const Function *GetOpFunc(OpType opType) { return GetGlobal()->_pOpFuncTbl[opType];	}
	inline const Function *GetOpFuncWithCheck(OpType opType) {
		return (opType < OPTYPE_max)? GetGlobal()->_pOpFuncTbl[opType] : NULL;
	}
	inline Module *GetModule_sys()				{ return GetGlobal()->_pModule_sys;			}
	inline void SetEchoFlag(bool echoFlag)		{ GetGlobal()->_echoFlag = echoFlag;		}
	inline bool GetEchoFlag() const				{ return GetGlobal()->_echoFlag;			}
	inline const SymbolSet &GetSymbolsPublic() const { return GetTopFrame()->GetSymbolsPublic(); }
	inline SymbolSet &PrepareSymbolsPublic()	{ return GetTopFrame()->PrepareSymbolsPublic(); }
	void AddRootFrame(const FrameList &frameListSrc);
	void AddOuterFrame(const FrameList &frameListSrc);
	void AddLackingFrame(const FrameList &frameListSrc);
	void CacheFrame(const Symbol *pSymbol, Frame *pFrame);
	void AssignValue(const Symbol *pSymbol, const Value &value);
	void AssignValueLocal(const Symbol *pSymbol, const Value &value);
	bool ImportValue(const Symbol *pSymbol, const Value &value,
										unsigned long extra, bool overwriteFlag);
	void RemoveValue(const Symbol *pSymbol);
	Function *AssignFunction(Function *pFunc);
	ValueEx *LookupValue(const Symbol *pSymbol,
						EnvRefMode envRefMode, int cntSuperSkip = 0);
	inline const ValueEx *LookupValue(const Symbol *pSymbol,
						EnvRefMode envRefMode, int cntSuperSkip = 0) const {
		return const_cast<const ValueEx *>(const_cast<Environment *>(this)->
						LookupValue(pSymbol, envRefMode, cntSuperSkip));
	}
	Function *LookupFunction(const Symbol *pSymbol, EnvRefMode envRefMode, int cntSuperSkip = 0) const;
	FunctionCustom *LookupFunctionCustom(const Symbol *pSymbol, EnvRefMode envRefMode, int cntSuperSkip = 0) const;
	void AssignValueType(const ValueTypeInfo *pValueTypeInfo);
	const ValueTypeInfo *LookupValueType(const SymbolList &symbolList) const;
	const ValueTypeInfo *LookupValueType(const Symbol *pSymbol) const;
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
						const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value DoSetProp(Environment &env, Signal sig, const Symbol *pSymbol, const Value &value,
						const SymbolSet &attrs, bool &evaluatedFlag);
	virtual ICallable *GetCallable(Signal sig, const Symbol *pSymbol);
	Value GetProp(Environment &env, Signal sig, const Symbol *pSymbol,
						const SymbolSet &attrs, const Value *pValueDefault = NULL,
						EnvRefMode envRefMode = ENVREF_Escalate, int cntSuperSkip = 0);
	inline Class *LookupClass(ValueType valType) const {
		return GetGlobal()->LookupClass(valType);
	}
	void AssignModule(Module *pModule);
	bool ImportModules(Signal sig, const char *moduleNames,
								bool binaryOnlyFlag, bool mixinTypeFlag);
	bool ImportModule(Signal sig, const Expr *pExpr, const Symbol *pSymbolAlias,
			const SymbolSet *pSymbolsToMixIn, bool overwriteFlag,
			bool binaryOnlyFlag, bool mixinTypeFlag);
	bool ImportModule(Signal sig, const SymbolList &symbolOfModule,
			const Symbol *pSymbolAlias, const SymbolSet *pSymbolsToMixIn,
			bool overwriteFlag, bool assignModuleNameFlag,
			bool binaryOnlyFlag, bool mixinTypeFlag);
	static bool IsBinaryModule(const char *pathName);
	bool AddModuleSearchPath(Signal sig, const StringList &strList);
	virtual bool IsModule() const;
	virtual bool IsClass() const;
	virtual bool IsObject() const;
	inline void Error(const char *fileName, int lineNo, const char *str) {
		::fprintf(stderr, "fatal error at line.%d in %s: %s\n", lineNo, fileName, str);
	}
	const char *GetPrompt(bool indentFlag);
	void SetConsole(Stream *pConsole);
	void SetConsoleErr(Stream *pConsole);
	Stream *GetConsole();
	Stream *GetConsoleErr();
	Stream *GetConsoleDumb();
	static void IntegrateModule(const char *name,
			ModuleEntryType moduleEntry, ModuleTerminateType moduleTerminate);
private:
	Module *ImportIntegratedModule(Signal sig, const SymbolList &symbolOfModule);
	Module *ImportSeparatedModule(Signal sig,
							const SymbolList &symbolOfModule, bool binaryOnlyFlag);
	bool SearchSeparatedModuleFile(Signal sig, String &pathName,
			SymbolList::const_iterator ppSymbolOfModule,
			SymbolList::const_iterator ppSymbolOfModuleEnd, bool binaryOnlyFlag);
	Module *ImportSeparatedModule_Script(Signal sig, Environment *pEnvOuter,
						const char *pathName, const SymbolList &symbolOfModule);
	Module *ImportSeparatedModule_Binary(Signal sig, Environment *pEnvOuter,
						const char *pathName, const SymbolList &symbolOfModule);
};

typedef std::set<Environment *> EnvironmentSet;

//-----------------------------------------------------------------------------
// EnvironmentRoot
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE EnvironmentRoot : public Environment {
public:
	EnvironmentRoot();
	virtual ~EnvironmentRoot();
	bool Initialize(Signal sig, int argc, const char *argv[]);
};

}
#endif
