//=============================================================================
// Environment
//=============================================================================
#include "stdafx.h"

#if defined(HAVE_LIBDL)
#include <dlfcn.h>
#endif

namespace Gura {

//-----------------------------------------------------------------------------
// EnvType
//-----------------------------------------------------------------------------
const char *GetEnvTypeName(EnvType envType)
{
	static const struct {
		EnvType envType;
		const char *name;
	} tbl[] = {
		{ ENVTYPE_invalid,			"invalid",			},
		{ ENVTYPE_root,				"root",				},
		{ ENVTYPE_local,			"local",			},
		{ ENVTYPE_block,			"block",			},
		{ ENVTYPE_class,			"class",			},
		{ ENVTYPE_object,			"object",			},
		{ ENVTYPE_lister,			"lister",			},
	};
	for (int i = 0; i < ArraySizeOf(tbl); i++) {
		if (tbl[i].envType == envType) return tbl[i].name;
	}
	return "unknown";
}

//-----------------------------------------------------------------------------
// PathMgrOwner
//-----------------------------------------------------------------------------
PathMgrOwner::~PathMgrOwner()
{
	Clear();
}

void PathMgrOwner::Clear()
{
	foreach (PathMgrOwner, ppPathMgr, *this) {
		delete *ppPathMgr;
	}
	clear();
}

//-----------------------------------------------------------------------------
// Environment
//-----------------------------------------------------------------------------
Environment::Environment() : _cntRef(1)
{
}

Environment::Environment(const Environment &env) : _cntRef(1)
{
	// _pFrameCache will be initialized when the program reads some variable at first
	foreach_const (FrameOwner, ppFrame, env.GetFrameOwner()) {
		Frame *pFrame = *ppFrame;
		_frameOwner.push_back(Frame::Reference(pFrame));
	}
}

Environment::Environment(const Environment *pEnvOuter, EnvType envType) : _cntRef(1)
{
	// _pFrameCache will be initialized when the program reads some variable at first
	//if (envType == ENVTYPE_block && pEnvOuter->GetFrameCache() != NULL) {
	//	_pFrameCache.reset(pEnvOuter->GetFrameCache()->Reference());
	//}
	_frameOwner.push_back(new Frame(envType, pEnvOuter->GetGlobal()));
	foreach_const (FrameOwner, ppFrame, pEnvOuter->GetFrameOwner()) {
		Frame *pFrame = *ppFrame;
		_frameOwner.push_back(Frame::Reference(pFrame));
	}
}

Environment::~Environment()
{
	// virtual destructor
}

bool Environment::InitializeAsRoot(Signal sig, int &argc, const char *argv[],
									const Option::Info *optInfoTbl, int cntOptInfo)
{
	Environment &env = *this;
#if defined(_MSC_VER)
	::_set_output_format(_TWO_DIGIT_EXPONENT);
#endif
	SymbolPool::Initialize();
	Codec::Initialize();
	_frameOwner.push_back(new Frame(ENVTYPE_root, new Global()));
	Random::Initialize(1234);	// initialize random generator SFMT
	ValueTypePool::Initialize(env);
	GetGlobal()->Prepare(env, sig);
	Operator::Initialize(env);
	Operator::AssignBasicOperators(env);
	ValueTypePool::DoPrepareClass(env);
	OAL::SetupExecutablePath();
	Module::ImportBuiltIns(env, sig);
	// set command line argument into sys module
	if (optInfoTbl != NULL) {
		String strErr;
		if (!GetOption().Parse(argc, argv, optInfoTbl, cntOptInfo, strErr)) {
			sig.SetError(ERR_CommandError, "%s", strErr.c_str());
			return false;
		}
	}
	if (!GetOption().IsSet("no-local-dir")) {
		OAL::PrepareLocalDir();
	}
	if (!Gura_Module(sys)::SetCmdLineArgs(GetGlobal()->GetModule_sys(), sig, argc, argv)) {
		return false;
	}
	return true;
}

const SymbolSet &Environment::GetSymbolsPublic() const
{
	foreach_const (FrameOwner, ppFrame, GetFrameOwner()) {
		Frame *pFrame = *ppFrame;
		if (pFrame->GetEnvType() != ENVTYPE_block) {
			return pFrame->GetSymbolsPublic();
		}
	}
	return GetTopFrame()->GetSymbolsPublic(); // this must not happen
}

SymbolSet &Environment::PrepareSymbolsPublic()
{
	foreach (FrameOwner, ppFrame, GetFrameOwner()) {
		Frame *pFrame = *ppFrame;
		if (pFrame->GetEnvType() != ENVTYPE_block) {
			return pFrame->PrepareSymbolsPublic();
		}
	}
	return GetTopFrame()->PrepareSymbolsPublic(); // this must not happen
}

void Environment::AddRootFrame(const FrameList &frameListSrc)
{
	// reference to the root environment
	foreach_const (FrameList, ppFrame, frameListSrc) {
		Frame *pFrame = *ppFrame;
		if (pFrame->GetEnvType() == ENVTYPE_root) {
			_frameOwner.push_back(Frame::Reference(pFrame));
			break;
		}
	}
}

void Environment::AddOuterFrame(const FrameList &frameListSrc)
{
	if (frameListSrc.size() <= 1) return;
	FrameList::const_iterator ppFrame = frameListSrc.begin();
	ppFrame++;
	for ( ; ppFrame != frameListSrc.end(); ppFrame++) {
		Frame *pFrame = *ppFrame;
		_frameOwner.push_back(Frame::Reference(pFrame));
	}
}

void Environment::AddLackingFrame(const FrameList &frameListSrc)
{
	foreach_const (FrameList, ppFrame, frameListSrc) {
		Frame *pFrame = *ppFrame;
		if (!_frameOwner.DoesExist(pFrame)) {
			_frameOwner.push_back(Frame::Reference(pFrame));
		}
	}
}

void Environment::CacheFrame(const Symbol *pSymbol, Frame *pFrame)
{
	if (_pFrameCache.get() == NULL) _pFrameCache.reset(new FrameCache());
	(*_pFrameCache)[pSymbol] = pFrame;
}

bool Environment::IsSymbolPublic(const Symbol *pSymbol) const
{
	EnvType envType = GetTopFrame()->GetEnvType();
	if (envType == ENVTYPE_class || envType == ENVTYPE_object) {
		foreach_const (FrameOwner, ppFrame, _frameOwner) {
			const Frame *pFrame = *ppFrame;
			if (pFrame->IsType(ENVTYPE_class) && pFrame->IsSymbolPublic(pSymbol)) {
				return true;
			}
		}
		return false;
	}
	const Frame *pFrame = GetTopFrame();
	return pFrame->IsSymbolPublic(pSymbol);
}

void Environment::AssignValue(const Symbol *pSymbol, const Value &value, ULong extra)
{
	if ((extra & EXTRA_Public) == 0 && IsSymbolPublic(pSymbol)) {
		extra |= EXTRA_Public;
	}
	Frame *pFrame = GetTopFrame();
	pFrame->AssignValue(pSymbol, value, extra);
	CacheFrame(pSymbol, pFrame);
}

void Environment::AssignValueFromBlock(const Symbol *pSymbol, const Value &value, ULong extra)
{
	if ((extra & EXTRA_Public) == 0 && IsSymbolPublic(pSymbol)) {
		extra |= EXTRA_Public;
	}
	if (_pFrameCache.get() != NULL) {
		FrameCache::iterator iter = _pFrameCache->find(pSymbol);
		if (iter != _pFrameCache->end()) {
			Frame *pFrame = iter->second;
			pFrame->AssignValue(pSymbol, value, extra);
			return;
		}
	}
	foreach (FrameOwner, ppFrame, _frameOwner) {
		Frame *pFrame = *ppFrame;
		if (!pFrame->IsType(ENVTYPE_block)) {
			pFrame->AssignValue(pSymbol, value, extra);
			break;
		}
	}
}

bool Environment::ImportValue(const Symbol *pSymbol, const Value &value,
										ULong extra, bool overwriteFlag)
{
	foreach (FrameOwner, ppFrame, _frameOwner) {
		Frame *pFrame = *ppFrame;
		if (pFrame->IsType(ENVTYPE_block)) {
			// nothing to do
		} else if (overwriteFlag || pFrame->LookupValue(pSymbol) == NULL) {
			pFrame->AssignValue(pSymbol, value, extra);
			break;
		} else {
			return false;
		}
	}
	return true;
}

void Environment::RemoveValue(const Symbol *pSymbol)
{
	GetTopFrame()->RemoveValue(pSymbol);
}

ValueEx *Environment::LookupValue(const Symbol *pSymbol, EnvRefMode envRefMode, int cntSuperSkip)
{
	EnvType envType = GetTopFrame()->GetEnvType();
	if (envRefMode == ENVREF_NoEscalate || envRefMode == ENVREF_Module) {
		Frame *pFrame = GetTopFrame();
		ValueEx *pValue = pFrame->LookupValue(pSymbol);
		if (pValue != NULL) {
			CacheFrame(pSymbol, pFrame);
			return pValue;
		}
	} else if (envType == ENVTYPE_class || envType == ENVTYPE_object) {
		foreach (FrameOwner, ppFrame, _frameOwner) {
			Frame *pFrame = *ppFrame;
			if (pFrame->IsType(ENVTYPE_object)) {
				ValueEx *pValue = pFrame->LookupValue(pSymbol);
				if (pValue != NULL) {
					CacheFrame(pSymbol, pFrame);
					return pValue;
				}
			} else if (pFrame->IsType(ENVTYPE_class)) {
				if (cntSuperSkip > 0) {
					cntSuperSkip--;
				} else {
					ValueEx *pValue = pFrame->LookupValue(pSymbol);
					if (pValue != NULL) {
						CacheFrame(pSymbol, pFrame);
						return pValue;
					}
				}
			}
		}
	} else {
		foreach (FrameOwner, ppFrame, _frameOwner) {
			Frame *pFrame = *ppFrame;
			ValueEx *pValue = pFrame->LookupValue(pSymbol);
			if (pValue != NULL) {
				CacheFrame(pSymbol, pFrame);
				return pValue;
			}
		}
	}
	return NULL;
}

Function *Environment::AssignFunction(Function *pFunc)
{
	ULong extra = EXTRA_Public;
	Value value(new Object_function(*this, pFunc));
	GetTopFrame()->AssignValue(pFunc->GetSymbol(), value, extra);
	return pFunc;
}

Function *Environment::LookupFunction(const Symbol *pSymbol, EnvRefMode envRefMode, int cntSuperSkip) const
{
	EnvType envType = GetTopFrame()->GetEnvType();
	if (envRefMode == ENVREF_NoEscalate || envRefMode == ENVREF_Module) {
		Frame *pFrame = const_cast<Frame *>(GetTopFrame());
		Value *pValue = pFrame->LookupValue(pSymbol);
		if (pValue != NULL && pValue->Is_function()) {
			return pValue->GetFunction();
		}
	} else if (envType == ENVTYPE_object || envType == ENVTYPE_class) {
		foreach_const (FrameOwner, ppFrame, _frameOwner) {
			Frame *pFrame = *ppFrame;
			if (pFrame->IsType(ENVTYPE_object)) {
				Value *pValue = pFrame->LookupValue(pSymbol);
				if (pValue != NULL && pValue->Is_function()) {
					return pValue->GetFunction();
				}
			} else if (pFrame->IsType(ENVTYPE_class)) {
				if (cntSuperSkip > 0) {
					cntSuperSkip--;
				} else {
					Value *pValue = pFrame->LookupValue(pSymbol);
					if (pValue != NULL && pValue->Is_function()) {
						return pValue->GetFunction();
					}
				}
			}
		}
	} else {
		foreach_const (FrameOwner, ppFrame, _frameOwner) {
			Frame *pFrame = *ppFrame;
			Value *pValue = pFrame->LookupValue(pSymbol);
			if (pValue != NULL && pValue->Is_function()) {
				return pValue->GetFunction();
			}
		}
	}
	return NULL;
}

FunctionCustom *Environment::LookupFunctionCustom(const Symbol *pSymbol, EnvRefMode envRefMode, int cntSuperSkip) const
{
	Function *pFunc = LookupFunction(pSymbol, envRefMode, cntSuperSkip);
	return (pFunc != NULL && pFunc->IsCustom())?
						dynamic_cast<FunctionCustom *>(pFunc) : NULL;
}

void Environment::AssignValueType(ValueTypeInfo *pValueTypeInfo)
{
	GetTopFrame()->AssignValueType(pValueTypeInfo);
}

ValueTypeInfo *Environment::LookupValueType(const SymbolList &symbolList)
{
	AutoPtr<Environment> pEnvRoot;
	SymbolList::const_iterator ppSymbol = symbolList.begin();
	Environment *pEnv = this;
	if ((*ppSymbol)->IsIdentical(Gura_Symbol(root))) {
		// make a reference to the root environment
		pEnvRoot.reset(new Environment());
		pEnvRoot->AddRootFrame(GetFrameOwner());
		pEnv = pEnvRoot.get();
		ppSymbol++;
		if (ppSymbol == symbolList.end()) return NULL;
	}
	EnvRefMode envRefMode = ENVREF_Escalate;
	int cntSuperSkip = 0;
	for ( ; ppSymbol + 1 != symbolList.end(); ppSymbol++) {
		Value *pValue = pEnv->LookupValue(*ppSymbol, envRefMode, cntSuperSkip);
		if (pValue == NULL || !pValue->IsModule()) return NULL;
		pEnv = pValue->GetModule();
		envRefMode = ENVREF_NoEscalate;
	}
	return pEnv->LookupValueType(*ppSymbol);
}

ValueTypeInfo *Environment::LookupValueType(const Symbol *pSymbol)
{
	foreach_const (FrameOwner, ppFrame, _frameOwner) {
		Frame *pFrame = *ppFrame;
		ValueTypeInfo *pValueTypeInfo = pFrame->LookupValueType(pSymbol);
		if (pValueTypeInfo != NULL) return pValueTypeInfo;
	}
	return NULL;
}

ValueTypeInfo *Environment::LookupValueType(Signal sig, const ValueList &valList)
{
	SymbolList symbolList;
	foreach_const_reverse (ValueList, pValue, valList) {
		if (!pValue->Is_expr()) {
			sig.SetError(ERR_TypeError, "expr must be specified");
			return NULL;
		}
		if (!Parser::ParseDottedIdentifier(pValue->GetExpr(), symbolList)) {
			sig.SetError(ERR_TypeError, "invalid element for type name: '%s'",
					pValue->GetExpr()->ToString(Expr::SCRSTYLE_OneLine).c_str());
			return NULL;
		}
	}
	ValueTypeInfo *pValueTypeInfo = LookupValueType(symbolList);
	if (pValueTypeInfo == NULL) {
		sig.SetError(ERR_ValueError, "can't find type name: '%s'",
								symbolList.Join(".").c_str());
		return NULL;
	}
	return pValueTypeInfo;
}

ValueTypeInfo *Environment::LookupValueType(Signal sig, const Expr *pExpr)
{
	SymbolList symbolList;
	if (!Parser::ParseDottedIdentifier(pExpr, symbolList)) {
		sig.SetError(ERR_TypeError, "invalid element for type name: '%s'",
						pExpr->ToString(Expr::SCRSTYLE_OneLine).c_str());
		return NULL;
	}
	ValueTypeInfo *pValueTypeInfo = LookupValueType(symbolList);
	if (pValueTypeInfo == NULL) {
		sig.SetError(ERR_ValueError, "can't find type name: '%s'",
								symbolList.Join(".").c_str());
		return NULL;
	}
	return pValueTypeInfo;
}

Value Environment::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag)
{
	return Value::Null;
}

Value Environment::DoSetProp(Environment &env, Signal sig, const Symbol *pSymbol, const Value &value,
								const SymbolSet &attrs, bool &evaluatedFlag)
{
	return Value::Null;
}

Callable *Environment::GetCallable(Signal sig, const Symbol *pSymbol)
{
	return NULL;
}

Value Environment::GetProp(Environment &env, Signal sig, const Symbol *pSymbol,
						const SymbolSet &attrs, const Value *pValueDefault,
						EnvRefMode envRefMode, int cntSuperSkip) const
{
	const ValueEx *pValue = LookupValue(pSymbol, envRefMode, cntSuperSkip);
	if (pValue == NULL) {
		// nothing to do
	} else if (envRefMode != ENVREF_Restricted && envRefMode != ENVREF_Module) {
		return *pValue;
	} else if (pValue->GetExtra() & EXTRA_Public) {
		return *pValue;
	} else if (IsModule()) {
		sig.SetError(ERR_MemberAccessError,
				"can't access module member %s.%s",
				dynamic_cast<const Module *>(this)->GetName(), pSymbol->GetName());
		return Value::Null;
	} else if (IsClass()) {
		sig.SetError(ERR_MemberAccessError,
				"can't access class member %s.%s",
				dynamic_cast<const Class *>(this)->GetName(), pSymbol->GetName());
		return Value::Null;
	} else if (IsObject()) {
		sig.SetError(ERR_MemberAccessError,
				"can't access object member %s#%s",
				dynamic_cast<const Object *>(this)->GetClass()->GetName(),
				pSymbol->GetName());
		return Value::Null;
	} else {
		sig.SetError(ERR_ValueError,
				"can't access variable %s", pSymbol->GetName());
		return Value::Null;
	}
	bool evaluatedFlag = false;
	Value result = const_cast<Environment *>(this)->DoGetProp(env, sig, pSymbol, attrs, evaluatedFlag);
	if (sig.IsSignalled()) return Value::Null;
	if (evaluatedFlag) return result;
	if (pValueDefault != NULL) return *pValueDefault;
	if (IsModule()) {
		sig.SetError(ERR_ValueError,
				"%s module does not have a symbol '%s'",
				dynamic_cast<const Module *>(this)->GetName(), pSymbol->GetName());
	} else if (IsClass()) {
		sig.SetError(ERR_ValueError,
				"%s class does not have a property '%s'",
				dynamic_cast<const Class *>(this)->GetName(), pSymbol->GetName());
	} else if (IsObject()) {
		sig.SetError(ERR_ValueError,
				"the object of %s class does not have a property '%s'",
				dynamic_cast<const Object *>(this)->GetClass()->GetName(),
				pSymbol->GetName());
	} else {
		sig.SetError(ERR_ValueError,
				"undefined symbol '%s'", pSymbol->GetName());
	}
	return Value::Null;
}

void Environment::AssignIntegratedModule(Module *pModule)
{
	ULong extra = EXTRA_Public;
	GetGlobal()->RegisterIntegratedModule(pModule);
	Value value(pModule);
	foreach (FrameOwner, ppFrame, _frameOwner) {
		Frame *pFrame = *ppFrame;
		if (!pFrame->IsType(ENVTYPE_block)) {
			pFrame->AssignValue(pModule->GetSymbol(), value, extra);
			break;
		}
	}
}

bool Environment::ImportModules(Signal sig, const char *moduleNames,
									bool binaryOnlyFlag, bool mixinTypeFlag)
{
	bool assignModuleNameFlag = true;
	const Symbol *pSymbolAlias = NULL;
	const SymbolSet *pSymbolsToMixIn = NULL;
	bool overwriteFlag = true;
	String moduleName;
	for (const char *p = moduleNames; ; p++) {
		char ch = *p;
		if (ch != ',' && ch != '\0') {
			moduleName += ch;
			continue;
		}
		moduleName = Strip(moduleName.c_str());
		SymbolList symbolList;
		if (!Parser::ParseDottedIdentifier(moduleName.c_str(), symbolList)) {
			sig.SetError(ERR_ImportError, "wrong format of module name");
			return false;
		}
		if (ImportModule(sig, symbolList.begin(), symbolList.end(), assignModuleNameFlag,
					pSymbolAlias, pSymbolsToMixIn,
					overwriteFlag, binaryOnlyFlag, mixinTypeFlag) == NULL) return false;
		moduleName.clear();
		if (ch == '\0') break;
	}
	return true;
}

Module *Environment::ImportModule(Signal sig, const Expr *pExpr,
			const Symbol *pSymbolAlias, const SymbolSet *pSymbolsToMixIn,
			bool overwriteFlag, bool binaryOnlyFlag, bool mixinTypeFlag)
{
	bool successFlag = false;
	bool assignModuleNameFlag = true;
	SymbolList symbolList;
	if (pExpr->IsUnaryOp()) {
		const Expr_UnaryOp *pExprEx = dynamic_cast<const Expr_UnaryOp *>(pExpr);
		const Symbol *pSymbol = pExprEx->GetOperator()->GetSymbol();
		if (pSymbol->IsIdentical(Gura_Symbol(Char_Sub))) {
			// import(-foo)
			successFlag = Parser::ParseDottedIdentifier(pExprEx->GetChild(), symbolList);
			assignModuleNameFlag = false;
		} else if (pSymbol->IsIdentical(Gura_Symbol(Char_And))) {
			// import(&foo)
			SeqPostHandler *pSeqPostHandler = NULL;
			Value rtn = pExprEx->GetChild()->Exec2(*this, sig, pSeqPostHandler);
			if (sig.IsSignalled()) return NULL;
			if (rtn.Is_string()) {
				const char *p = rtn.GetString();
				if (*p == '-') {
					assignModuleNameFlag = false;
					p++;
				}
				successFlag = Parser::ParseDottedIdentifier(p, symbolList);
			} else {
				sig.SetError(ERR_ImportError, "module name must be a string");
				return NULL;
			}
		} else {
			// nothing to do
		}
	} else {
		successFlag = Parser::ParseDottedIdentifier(pExpr, symbolList);
	}
	if (!successFlag) {
		sig.SetError(ERR_ImportError, "wrong format of module name");
		return NULL;
	}
	return ImportModule(sig, symbolList.begin(), symbolList.end(), assignModuleNameFlag,
						pSymbolAlias, pSymbolsToMixIn,
						overwriteFlag, binaryOnlyFlag, mixinTypeFlag);
}

Module *Environment::ImportModule(Signal sig, SymbolList::const_iterator ppSymbolOfModule,
			SymbolList::const_iterator ppSymbolOfModuleEnd, bool assignModuleNameFlag,
			const Symbol *pSymbolAlias, const SymbolSet *pSymbolsToMixIn,
			bool overwriteFlag, bool binaryOnlyFlag, bool mixinTypeFlag)
{
	const Symbol *pSymbolOfModule = NULL;
	for (SymbolList::const_iterator ppSymbol = ppSymbolOfModule;
							ppSymbol != ppSymbolOfModuleEnd; ppSymbol++) {
		pSymbolOfModule = *ppSymbol;
	}
	Module *pModule = GetGlobal()->LookupIntegratedModule(pSymbolOfModule->GetName());
	if (pModule == NULL) {
		String pathName;
		if (!SearchSeparatedModuleFile(sig, pathName,
				ppSymbolOfModule, ppSymbolOfModuleEnd, binaryOnlyFlag)) return NULL;
		pModule = GetGlobal()->LookupSeparatedModule(pathName.c_str());
		if (pModule != NULL) {
			// nothing to do
		} else if (IsBinaryModule(pathName.c_str())) {
			pModule = ImportSeparatedModule_Binary(sig, this, pathName.c_str(), pSymbolOfModule);
		} else {
			pModule = ImportSeparatedModule_Script(sig, this, pathName.c_str(), pSymbolOfModule);
		}
		if (pModule == NULL) return NULL;
	}
	if (pSymbolsToMixIn == NULL) {
		if (!assignModuleNameFlag) {
			// import(-foo)
			// nothing to do
		} else if (pSymbolAlias == NULL) {
			// import(foo)
			Environment *pEnvDst = this;
			for (SymbolList::const_iterator ppSymbol = ppSymbolOfModule;
								ppSymbol + 1 != ppSymbolOfModuleEnd; ppSymbol++) {
				const Symbol *pSymbol = *ppSymbol;
				Value *pValue = pEnvDst->LookupValue(pSymbol, ENVREF_NoEscalate);
				if (pValue == NULL) {
					Module *pModuleParent = ImportModule(sig, ppSymbolOfModule,
								ppSymbol + 1, assignModuleNameFlag, NULL, NULL,
								overwriteFlag, false, false);
					if (pModuleParent == NULL) return NULL;
					pEnvDst = pModuleParent;
				} else if (pValue->IsModule()) {
					pEnvDst = pValue->GetModule();
				} else {
					sig.SetError(ERR_ImportError,
						"module symbol conflicts with an existing variable '%s'",
						SymbolList::Join(ppSymbolOfModule, ppSymbol + 1, '.').c_str());
					return NULL;
				}
			}
			Value *pValue = pEnvDst->LookupValue(pSymbolOfModule, ENVREF_Escalate);
			if (pValue != NULL && pValue->IsModule() && pValue->GetModule() == pModule) {
				// nothing to do
			} else {
				Value valueOfModule(Module::Reference(pModule));
				if (!pEnvDst->ImportValue(pSymbolOfModule, valueOfModule, EXTRA_Public, overwriteFlag)) {
					sig.SetError(ERR_ImportError,
							 "module symbol conflicts with an existing variable '%s'",
							 SymbolList::Join(ppSymbolOfModule, ppSymbolOfModuleEnd, '.').c_str());
					return NULL;
				}
			}
		} else {
			// import(foo, bar)
			Value valueOfModule(Module::Reference(pModule));
			if (!ImportValue(pSymbolAlias, valueOfModule, EXTRA_Public, overwriteFlag)) {
				sig.SetError(ERR_ImportError,
					"module symbol conflicts with an existing variable '%s'",
					pSymbolAlias->GetName());
				return NULL;
			}
		}
	} else if (pSymbolsToMixIn->IsSet(Gura_Symbol(Char_Mul))) {
		// import(hoge) {*}
		//GetFrameOwner().DbgPrint();
		foreach_const (ValueMap, iter, pModule->GetTopFrame()->GetValueMap()) {
			const Symbol *pSymbol = iter->first;
			const ValueEx &valueEx = iter->second;
			if (pSymbol->IsPrivateName()) {
				// nothing to do
			} else if (!ImportValue(pSymbol, valueEx, valueEx.GetExtra(), overwriteFlag)) {
				sig.SetError(ERR_ImportError,
					"imported variable name conflicts with an existing one '%s'",
					pSymbol->GetName());
				return NULL;
			}
		}
	} else {
		// import(hoge) {foo, bar}
		foreach_const (SymbolSet, ppSymbol, *pSymbolsToMixIn) {
			const Symbol *pSymbol = *ppSymbol;
			ValueEx *pValueEx = pModule->LookupValue(pSymbol, ENVREF_NoEscalate);
			if (pValueEx == NULL) {
				// nothing to do
			} else if (!ImportValue(pSymbol, *pValueEx, pValueEx->GetExtra(), overwriteFlag)) {
				sig.SetError(ERR_ImportError,
						"imported variable name conflicts with an existing one '%s'",
												pSymbol->GetName());
				return NULL;
			}
		}
	}
	if (mixinTypeFlag) {
		foreach_const (ValueTypeMap, iter, pModule->GetTopFrame()->GetValueTypeMap()) {
			ValueTypeInfo *pValueTypeInfo = iter->second;
			AssignValueType(pValueTypeInfo);
		}
	}
	return pModule;
}

bool Environment::SearchSeparatedModuleFile(Signal sig, String &pathName,
		SymbolList::const_iterator ppSymbolOfModule,
		SymbolList::const_iterator ppSymbolOfModuleEnd, bool binaryOnlyFlag)
{
	Environment &env = *this;
	const Value *pValDirNameList = GetGlobal()->GetModule_sys()->
							LookupValue(Gura_Symbol(path), ENVREF_NoEscalate);
	if (pValDirNameList == NULL) {
		sig.SetError(ERR_ImportError, "variable path is not specified");
		return false;
	} else if (!pValDirNameList->Is_list()) {
		sig.SetError(ERR_ImportError, "variable path must be a list");
		return false;
	}
	StringList extNameList;
	if (!binaryOnlyFlag) {
		extNameList.push_back("gura"); // script module shall be searched first
	}
	extNameList.push_back("gurd");
	String baseName = SymbolList::Join(ppSymbolOfModule, ppSymbolOfModuleEnd, '.'); //OAL::FileSeparator
	foreach_const (ValueList, pValue, pValDirNameList->GetList()) {
		if (!pValue->Is_string()) {
			sig.SetError(ERR_ImportError, "elements of variable path must be strings");
			return false;
		}
		do {
			String pathNameBase = pValue->GetString();
			pathNameBase += OAL::FileSeparator;
			pathNameBase += baseName;
			pathNameBase += '.';
			foreach_const (StringList, pExtName, extNameList) {
				pathName = pathNameBase + *pExtName;
				if (PathMgr::DoesExist(env, sig, pathName.c_str())) return true;
				if (sig.IsSignalled()) return false;
			}
		} while (0);
	}
	sig.SetError(ERR_ImportError, "can't find a module named '%s'",
		SymbolList::Join(ppSymbolOfModule, ppSymbolOfModuleEnd, '.').c_str());
	return false;
}

Module *Environment::ImportSeparatedModule_Script(Signal sig, Environment *pEnvOuter,
									const char *pathName, const Symbol *pSymbol)
{
	Environment &env = *this;
	AutoPtr<Stream> pStream(Stream::Open(env, sig, pathName, Stream::ATTR_Readable));
	if (sig.IsError()) return NULL;
	AutoPtr<Expr_Root> pExprRoot(Parser(pStream->GetName()).ParseStream(*pEnvOuter, sig, *pStream));
	if (sig.IsSignalled()) return NULL;
	Module *pModule = new Module(pEnvOuter, pSymbol,
							pathName, Expr::Reference(pExprRoot.get()), NULL);
	GetGlobal()->RegisterSeparatedModule(pathName, pModule);
	bool echoFlagSaved = pModule->GetGlobal()->GetEchoFlag();
	pModule->GetGlobal()->SetEchoFlag(false);
	do {
		AutoPtr<Processor> pProcessor(new Processor());
		pProcessor->PushSequence(new Expr::SequenceRoot(pModule->Reference(),
									pExprRoot->GetExprOwner().Reference()));
		pProcessor->Run(sig);
	} while (0);
	pModule->GetGlobal()->SetEchoFlag(echoFlagSaved);
	if (sig.IsSignalled()) {
		GetGlobal()->UnregisterSeparatedModule(pathName);
		delete pModule;
		return NULL;
	}
	return pModule;
}

Module *Environment::ImportSeparatedModule_Binary(Signal sig, Environment *pEnvOuter,
									const char *pathName, const Symbol *pSymbol)
{
	OAL::DynamicLibrary dynamicLibrary;
	if (!dynamicLibrary.Open(sig, pathName)) return NULL;
	void *pFunc = NULL;
	pFunc = dynamicLibrary.GetEntry(sig, "GuraModuleEntry");
	if (pFunc == NULL) return NULL;
	// gcc of a certain version such as 3.4.6 may cause an error when trying to
	// cast between pointer-to-function and pointer-to-using with reinterpret_cast.
	ModuleEntryType moduleEntry = (ModuleEntryType)(pFunc);
	pFunc = dynamicLibrary.GetEntry(sig, "GuraModuleTerminate");
	if (pFunc == NULL) return NULL;
	ModuleTerminateType moduleTerminate = (ModuleTerminateType)(pFunc);
	Module *pModule = new Module(pEnvOuter, pSymbol, pathName, NULL, moduleTerminate);
	GetGlobal()->RegisterSeparatedModule(pathName, pModule);
	if (!(*moduleEntry)(*pModule, sig)) {
		GetGlobal()->UnregisterSeparatedModule(pathName);
		delete pModule;
		return NULL;
	}
	return pModule;
}

bool Environment::IsBinaryModule(const char *pathName)
{
	return ::strcasecmp(PathMgr::SeekExtName(pathName), EXTNAME_BinModule) == 0;
}

const char *Environment::GetPrompt(bool indentFlag)
{
	Value *pValue = GetGlobal()->GetModule_sys()->LookupValue(
			indentFlag? Gura_Symbol(ps2) : Gura_Symbol(ps1), ENVREF_NoEscalate);
	return (pValue == NULL || !pValue->Is_string())? "" : pValue->GetString();
}

const Symbol *Environment::GetLangCode()
{
	Value *pValue = GetGlobal()->GetModule_sys()->
					LookupValue(Gura_Symbol(langcode), ENVREF_NoEscalate);
	if (pValue == NULL || !pValue->IsInstanceOf(VTYPE_symbol)) {
		return Gura_Symbol(en);
	}
	return pValue->GetSymbol();
}

Stream *Environment::GetConsole()
{
	Value *pValue = GetGlobal()->GetModule_sys()->
					LookupValue(Gura_Symbol(stdout), ENVREF_NoEscalate);
	if (pValue == NULL || !pValue->IsInstanceOf(VTYPE_stream)) {
		return GetConsoleDumb();
	}
	return &pValue->GetStream();
}

Stream *Environment::GetConsoleErr()
{
	Value *pValue = GetGlobal()->GetModule_sys()->
					LookupValue(Gura_Symbol(stderr), ENVREF_NoEscalate);
	if (pValue == NULL || !pValue->IsInstanceOf(VTYPE_stream)) {
		return GetConsoleDumb();
	}
	return &pValue->GetStream();
}

Stream *Environment::GetConsoleDumb()
{
	return GetGlobal()->GetConsoleDumb();
}

bool Environment::IsModule() const { return false; }
bool Environment::IsClass() const { return false; }
bool Environment::IsObject() const { return false; }

//-----------------------------------------------------------------------------
// Environment::Global
//-----------------------------------------------------------------------------
Environment::Global::Global() : _echoFlag(false)
{
	_pSymbolPool = SymbolPool::GetInstance();
}

Environment::Global::~Global()
{
	foreach_const (ModuleMap, iter, _moduleMapSeparated) {
		delete iter->second;
	}
}

void Environment::Global::Prepare(Environment &env, Signal sig)
{
	_workingDirList.push_back(OAL::GetCurDir());
	_pValueTypePool = ValueTypePool::GetInstance();
	_pConsoleDumb.reset(new StreamDumb(env, sig));
}

Class *Environment::Global::LookupClass(ValueType valType) const
{
	return ValueTypePool::GetInstance()->Lookup(valType)->GetClass();
}

Module *Environment::Global::LookupIntegratedModule(const char *name) const
{
	ModuleMap::const_iterator iter = _moduleMapIntegrated.find(name);
	return (iter == _moduleMapIntegrated.end())? NULL : iter->second;
}

void Environment::Global::RegisterIntegratedModule(Module *pModule)
{
	_moduleMapIntegrated[pModule->GetName()] = pModule;
}

Module *Environment::Global::LookupSeparatedModule(const char *pathName) const
{
	ModuleMap::const_iterator iter = _moduleMapSeparated.find(pathName);
	return (iter == _moduleMapSeparated.end())? NULL : iter->second;
}

void Environment::Global::RegisterSeparatedModule(const char *pathName, Module *pModule)
{
	_moduleMapSeparated[pathName] = pModule;
}

void Environment::Global::UnregisterSeparatedModule(const char *pathName)
{
	_moduleMapSeparated.erase(_moduleMapSeparated.find(pathName));
}

//-----------------------------------------------------------------------------
// Environment::Frame
//-----------------------------------------------------------------------------
Environment::Frame::Frame(const Frame &frame) :
			_cntRef(1), _envType(frame._envType), _pGlobal(frame._pGlobal)
{
	if (frame._pValueMap.get() != NULL) {
		_pValueMap.reset(new ValueMap(*frame._pValueMap));
	}
	if (frame._pValueTypeMap.get() != NULL) {
		_pValueTypeMap.reset(new ValueTypeMap(*frame._pValueTypeMap));
	}
}

Environment::Frame::Frame(EnvType envType, Global *pGlobal) :
			_cntRef(1), _envType(envType), _pGlobal(pGlobal)
{
}

Environment::Frame::~Frame()
{
}

void Environment::Frame::Delete(Frame *pFrame)
{
	if (pFrame == NULL) return;
#if 0
	EnvType envType = pFrame->GetEnvType();
	if (envType != ENVTYPE_root && envType != ENVTYPE_class &&
										pFrame->_pValueMap.get() != NULL) {
		const ValueMap &valueMap = *pFrame->_pValueMap;
		EnvironmentSet envSet;
		foreach_const (ValueMap, iter, valueMap) {
			const Value &value = iter->second;
			if (value.IsObject()) {
				//value.GetObject()->GatherFollower(pFrame, envSet);
			}
		}
		int cntFollower = static_cast<int>(envSet.size());
		if (pFrame->GetRefCnt() <= cntFollower + 1) {
			foreach (EnvironmentSet, ppEnv, envSet) {
				(*ppEnv)->GetFrameOwner().remove(pFrame);
			}
			delete pFrame;
		} else {
			pFrame->DecRef();
		}
	} else if (pFrame->DecRef() <= 0) {
		delete pFrame;
	}
#endif
	if (pFrame->DecRef() <= 0) {
		delete pFrame;
	}
}

void Environment::Frame::AssignValue(const Symbol *pSymbol,
									const Value &value, ULong extra)
{
	if (_pValueMap.get() == NULL) _pValueMap.reset(new ValueMap());
	ValueMap::iterator iter = _pValueMap->find(pSymbol);
	if (iter != _pValueMap->end() && (iter->second.GetExtra() & EXTRA_Public) != 0) {
		extra |= EXTRA_Public;
	}
	(*_pValueMap)[pSymbol] = ValueEx(value, extra);
}

void Environment::Frame::RemoveValue(const Symbol *pSymbol)
{
	if (_pValueMap.get() == NULL) return;
	_pValueMap->erase(pSymbol);
}

ValueEx *Environment::Frame::LookupValue(const Symbol *pSymbol)
{
	if (_pValueMap.get() == NULL) return NULL;
	ValueMap::iterator iter = _pValueMap->find(pSymbol);
	return (iter == _pValueMap->end())? NULL : &iter->second;
}

void Environment::Frame::AssignValueType(ValueTypeInfo *pValueTypeInfo)
{
	if (_pValueTypeMap.get() == NULL) _pValueTypeMap.reset(new ValueTypeMap());
	(*_pValueTypeMap)[pValueTypeInfo->GetSymbol()] = pValueTypeInfo;
}

ValueTypeInfo *Environment::Frame::LookupValueType(const Symbol *pSymbol)
{
	if (_pValueTypeMap.get() == NULL) return NULL;
	ValueTypeMap::iterator iter = _pValueTypeMap->find(pSymbol);
	return (iter == _pValueTypeMap->end())? NULL : iter->second;
}

SymbolSet &Environment::Frame::PrepareSymbolsPublic()
{
	if (_pSymbolsPublic.get() == NULL) {
		_pSymbolsPublic.reset(new SymbolSet());
	}
	return *_pSymbolsPublic;
}

void Environment::Frame::DbgPrint() const
{
	::printf("%p %-10s\n", this, GetEnvTypeName(GetEnvType()));
	if (_pValueMap.get() == NULL) {
		::printf(" [Values] .. null\n");
	} else {
		::printf(" [Values] .. %p\n", _pValueMap.get());
		if (!_pValueMap->empty()) {
			foreach_const (ValueMap, iter, *_pValueMap) {
				::printf(" %s", iter->first->GetName());
			}
			::printf("\n");
		}
	}
	if (_pValueTypeMap.get() == NULL) {
		::printf(" [Value Types] .. null\n");
	} else {
		::printf(" [Value Types] .. %p\n", _pValueTypeMap.get());
		if (!_pValueTypeMap->empty()) {
			foreach_const (ValueTypeMap, iter, *_pValueTypeMap) {
				::printf(" %s", iter->first->GetName());
			}
			::printf("\n");
		}
	}
}

//-----------------------------------------------------------------------------
// Environment::FrameList
//-----------------------------------------------------------------------------
void Environment::FrameList::DbgPrint() const
{
	int idx = 0;
	foreach_const (FrameList, ppFrame, *this) {
		const Frame *pFrame = *ppFrame;
		idx++;
		::printf("frame#%d ", idx);
		pFrame->DbgPrint();
	}
}

//-----------------------------------------------------------------------------
// Environment::FrameOwner
//-----------------------------------------------------------------------------
Environment::FrameOwner::~FrameOwner()
{
	Clear();
}

void Environment::FrameOwner::Clear()
{
	foreach (FrameOwner, ppFrame, *this) {
		Frame *pFrame = *ppFrame;
		Frame::Delete(pFrame);
	}
	clear();
}

//-----------------------------------------------------------------------------
// Environment::FrameCache
//-----------------------------------------------------------------------------
Environment::FrameCache::FrameCache() : _cntRef(1)
{
}

Environment::FrameCache::~FrameCache()
{
}

}
