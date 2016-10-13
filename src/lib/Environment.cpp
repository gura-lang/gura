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
	for (size_t i = 0; i < ArraySizeOf(tbl); i++) {
		if (tbl[i].envType == envType) return tbl[i].name;
	}
	return "unknown";
}

//-----------------------------------------------------------------------------
// Environment
//-----------------------------------------------------------------------------
Environment::Environment(Signal &sig) : _sig(sig)
{
}

Environment::Environment(const Environment &env) : _sig(env.GetSignal())
{
	// _pFrameCache will be initialized when the program reads some variable at first
	_frameOwner.reserve(env.GetFrameOwner().size());
	foreach_const (FrameOwner, ppFrame, env.GetFrameOwner()) {
		Frame *pFrame = *ppFrame;
		_frameOwner.push_back(Frame::Reference(pFrame));
	}
}

Environment::Environment(const Environment &envOuter, EnvType envType) :
	_sig(envOuter.GetSignal())
{
	// _pFrameCache will be initialized when the program reads some variable at first
	_frameOwner.reserve(envOuter.GetFrameOwner().size() + 1);
	_frameOwner.push_back(new Frame(envType, envOuter.GetGlobal()));
	foreach_const (FrameOwner, ppFrame, envOuter.GetFrameOwner()) {
		Frame *pFrame = *ppFrame;
		_frameOwner.push_back(Frame::Reference(pFrame));
	}
}

bool Environment::InitializeAsRoot(int &argc, const char *argv[],
								   const Option::Info *optInfoTbl, int cntOptInfo)
{
	static const Option::Info optInfoTblDef[] = {
		{ "import-dir",		'I', Option::TYPE_Value	},
		{ "no-local-dir",	'N', Option::TYPE_Flag	},
		{ "naked",			'K', Option::TYPE_Flag	},
	};
	Environment &env = *this;
	Signal &sig = GetSignal();
	OAL::Initialize();
	Symbol::Initialize();
	Codec::Initialize();
	Token::Initialize();
	Parser::Initialize();
	_frameOwner.push_back(new Frame(ENVTYPE_root, new Global()));
	Random::Initialize(1234);	// initialize random generator SFMT
	ValueTypePool::Initialize(env);
	GetGlobal()->Prepare(env);
	Operator::Initialize(env);
	Operator::AssignBasicOperators(env);
	ValueTypePool::DoPrepareClass(env);
	OAL::SetupExecutablePath();
	Module::ImportBuiltIns(env);
	Option &opt = env.GetOption();
	opt.AddInfo(optInfoTblDef, ArraySizeOf(optInfoTblDef));
	if (optInfoTbl != nullptr) opt.AddInfo(optInfoTbl, cntOptInfo);
	String strErr;
	if (!opt.Parse(argc, argv, strErr)) {
		sig.SetError(ERR_CommandError, "%s", strErr.c_str());
		return false;
	}
	if (!opt.IsSet("no-local-dir")) OAL::PrepareLocalDir();
	String fileNameScript;
	Module *pModule_sys = GetGlobal()->GetModule_sys();
	if (argc >= 2) {
		fileNameScript = OAL::FromNativeString(argv[1]);
	}
	do {
		// assignment of sys.argv
		Value value;
		Object_list *pObjList = value.InitAsList(env);
		if (argc >= 2 && argv != nullptr) {
			pObjList->Reserve(argc - 1);
			pObjList->Add(Value(OAL::MakeAbsPathName(
										OAL::FileSeparator, fileNameScript.c_str())));
			for (int i = 2; i < argc; i++) {
				const char *arg = argv[i];
				pObjList->Add(Value(OAL::FromNativeString(arg)));
			}
		}
		pModule_sys->AssignValue(Symbol::Add("argv"), value, EXTRA_Public);
	} while (0);
	do {
		// assignment of sys.path
		Value value;
		Object_list *pObjList = value.InitAsList(env);
		do {
			String dirName, fileName;
			PathMgr::SplitFileName(fileNameScript.c_str(), &dirName, &fileName);
			if (!dirName.empty()) {
				pObjList->Add(Value(OAL::MakeAbsPathName(
											OAL::FileSeparator, dirName.c_str())));
			}
		} while (0);
		pObjList->Add(Value("."));
		if (opt.IsSet("import-dir")) {
			foreach_const (StringList, pStr, opt.GetStringList("import-dir")) {
				const String &str = *pStr;
				if (str.size() >= 2 && str[0] == '.' && (str[1] == '/' || str[1] == '\\')) {
					pObjList->Add(Value(str.c_str() + 2));
				} else {
					pObjList->Add(Value(OAL::MakeAbsPathName(
											OAL::FileSeparator, str.c_str())));
				}
			}
		}
		StringList strList;
		OAL::SetupModulePath(strList);
		foreach (StringList, pStr, strList) {
			pObjList->Add(Value(*pStr));
		}
		if (argc >= 2 && OAL::IsCompositeFile(fileNameScript.c_str())) {
			pObjList->Add(Value(OAL::MakeAbsPathName(
										OAL::FileSeparator, fileNameScript.c_str())));
		}
		pModule_sys->AssignValue(Symbol::Add("path"), value, EXTRA_Public);
	} while (0);
	do {
		// assignment of sys.maindir
		String str;
		if (argc < 2) {
			str = OAL::GetCurDir();
		} else {
			str = OAL::MakeAbsPathName(OAL::FileSeparator, fileNameScript.c_str());
			if (!OAL::IsCompositeFile(fileNameScript.c_str())) {
				String dirName;
				PathMgr::SplitFileName(str.c_str(), &dirName, nullptr);
				str = dirName;
			}
		}
		pModule_sys->AssignValue(Symbol::Add("maindir"), Value(str), EXTRA_Public);
	} while (0);
	if (!opt.IsSet("naked") && !Module::ImportDefaultExternals(env)) return false;
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

bool Environment::IsSymbolPublic(const Symbol *pSymbol) const
{
	EnvType envType = GetEnvType();
	if (envType == ENVTYPE_class || envType == ENVTYPE_object) {
		foreach_const (FrameOwner, ppFrame, _frameOwner) {
			const Frame *pFrame = *ppFrame;
			if (pFrame->IsType(ENVTYPE_class) && pFrame->IsSymbolPublic(pSymbol)) {
				return true;
			}
		}
		return false;
	}
	return GetTopFrame()->IsSymbolPublic(pSymbol);
}

void Environment::AddRootFrame(const FrameList &frameListSrc)
{
	// reference to the root environment
	_frameOwner.reserve(_frameOwner.size() + frameListSrc.size());
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
	_frameOwner.reserve(_frameOwner.size() + frameListSrc.size() - 1);
	FrameList::const_iterator ppFrame = frameListSrc.begin();
	ppFrame++;
	for ( ; ppFrame != frameListSrc.end(); ppFrame++) {
		Frame *pFrame = *ppFrame;
		_frameOwner.push_back(Frame::Reference(pFrame));
	}
}

void Environment::AddLackingFrame(const FrameList &frameListSrc)
{
	_frameOwner.reserve(_frameOwner.size() + frameListSrc.size());
	foreach_const (FrameList, ppFrame, frameListSrc) {
		Frame *pFrame = *ppFrame;
		if (!_frameOwner.DoesExist(pFrame)) {
			_frameOwner.push_back(Frame::Reference(pFrame));
		}
	}
}

void Environment::CacheFrame(const Symbol *pSymbol, Frame *pFrame)
{
	if (_pFrameCache.get() == nullptr) _pFrameCache.reset(new FrameCache());
	(*_pFrameCache)[pSymbol] = pFrame;
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

Function *Environment::AssignFunction(Function *pFunc, ULong extra)
{
	const Symbol *pSymbol = pFunc->GetSymbol();
	Frame *pFrame = GetTopFrame();
	Class *pClass = pFunc->GetClassToConstruct();
	if (pClass == nullptr) {
		if (IsClass()) {
			pFunc->SetClassContainer(dynamic_cast<Class *>(this));
		}
		pFrame->AssignValue(pSymbol, Value(new Object_function(*this, pFunc)), extra);
	} else {
		pFrame->AssignValue(pSymbol, Value(pClass->Reference()), extra);
	}
	return pFunc;
}

void Environment::AssignValueFromBlock(const Symbol *pSymbol, const Value &value, ULong extra)
{
	if ((extra & EXTRA_Public) == 0 && IsSymbolPublic(pSymbol)) {
		extra |= EXTRA_Public;
	}
	if (_pFrameCache.get() != nullptr) {
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
		} else if (overwriteFlag || pFrame->LookupValue(*this, pSymbol) == nullptr) {
			pFrame->AssignValue(pSymbol, value, extra);
			break;
		} else {
			return false;
		}
	}
	return true;
}

ValueEx *Environment::LookupValue(const Symbol *pSymbol, EnvType envType,
								  EnvRefMode envRefMode, int cntSuperSkip)
{
	//EnvType envType = GetEnvType();
	if (envRefMode == ENVREF_NoEscalate || envRefMode == ENVREF_Module) {
		Frame *pFrame = GetTopFrame();
		ValueEx *pValue = pFrame->LookupValue(*this, pSymbol);
		if (pValue != nullptr) {
			CacheFrame(pSymbol, pFrame);
			return pValue;
		}
	} else if (envType == ENVTYPE_class || envType == ENVTYPE_object) {
		foreach (FrameOwner, ppFrame, _frameOwner) {
			Frame *pFrame = *ppFrame;
			if (pFrame->IsType(ENVTYPE_object)) {
				ValueEx *pValue = pFrame->LookupValue(*this, pSymbol);
				if (pValue != nullptr) {
					CacheFrame(pSymbol, pFrame);
					return pValue;
				}
			} else if (pFrame->IsType(ENVTYPE_class)) {
				if (cntSuperSkip > 0) {
					cntSuperSkip--;
				} else {
					ValueEx *pValue = pFrame->LookupValue(*this, pSymbol);
					if (pValue != nullptr) {
						CacheFrame(pSymbol, pFrame);
						return pValue;
					}
				}
			}
		}
	} else {
		foreach (FrameOwner, ppFrame, _frameOwner) {
			Frame *pFrame = *ppFrame;
			ValueEx *pValue = pFrame->LookupValue(*this, pSymbol);
			if (pValue != nullptr) {
				CacheFrame(pSymbol, pFrame);
				return pValue;
			}
		}
	}
	return nullptr;
}

Function *Environment::LookupFunction(const Symbol *pSymbol, EnvRefMode envRefMode, int cntSuperSkip) const
{
	const ValueEx *pValue = LookupValue(pSymbol, envRefMode, cntSuperSkip);
	return (pValue != nullptr && pValue->Is_function())? pValue->GetFunction() : nullptr;
}

void Environment::RemoveValue(const Symbol *pSymbol)
{
	GetTopFrame()->RemoveValue(pSymbol);
}

Value Environment::DoGetProp(Environment &env, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag)
{
	return Value::Nil;
}

Value Environment::DoSetProp(Environment &env, const Symbol *pSymbol, const Value &value,
								const SymbolSet &attrs, bool &evaluatedFlag)
{
	return Value::Nil;
}

Callable *Environment::GetCallable(const Symbol *pSymbol)
{
	return nullptr;
}

Value Environment::GetProp(Environment &env, const Symbol *pSymbol,
						const SymbolSet &attrs, const Value *pValueDefault,
						EnvRefMode envRefMode, int cntSuperSkip) const
{
	Signal &sig = env.GetSignal();
	const ValueEx *pValue = LookupValue(pSymbol, envRefMode, cntSuperSkip);
	if (pValue == nullptr) {
		bool evaluatedFlag = false;
		Value result = const_cast<Environment *>(this)->
							DoGetProp(env, pSymbol, attrs, evaluatedFlag);
		if (sig.IsSignalled()) return Value::Nil;
		if (evaluatedFlag) return result;
		if (pValueDefault != nullptr) return *pValueDefault;
		SetError_PropertyNotFound(pSymbol);
		return Value::Nil;
	} else if ((envRefMode == ENVREF_Restricted || envRefMode == ENVREF_Module) &&
									(pValue->GetExtra() & EXTRA_Public) == 0) {
		SetError_AccessViolation(pSymbol);
		return Value::Nil;
	}
	return *pValue;
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
		pEnvRoot.reset(new Environment(GetSignal()));
		pEnvRoot->AddRootFrame(GetFrameOwner());
		pEnv = pEnvRoot.get();
		ppSymbol++;
		if (ppSymbol == symbolList.end()) return nullptr;
	}
	EnvRefMode envRefMode = ENVREF_Escalate;
	int cntSuperSkip = 0;
	for ( ; ppSymbol + 1 != symbolList.end(); ppSymbol++) {
		EnvType envType = pEnv->GetEnvType();
		if (envType == ENVTYPE_class) envType = ENVTYPE_local;
		Value *pValue = pEnv->LookupValue(*ppSymbol, envType, envRefMode, cntSuperSkip);
		if (pValue == nullptr || !pValue->IsModule()) return nullptr;
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
		if (pValueTypeInfo != nullptr) return pValueTypeInfo;
	}
	return nullptr;
}

ValueTypeInfo *Environment::LookupValueType(Signal &sig, const ValueList &valList)
{
	SymbolList symbolList;
	foreach_const_reverse (ValueList, pValue, valList) {
		if (!pValue->Is_expr()) {
			sig.SetError(ERR_TypeError, "expr must be specified");
			return nullptr;
		}
		//if (!Parser::ParseDottedIdentifier(pValue->GetExpr(), symbolList)) {
		if (!symbolList.AddFromExpr(pValue->GetExpr())) {
			sig.SetError(ERR_TypeError, "invalid element for type name: '%s'",
					pValue->GetExpr()->ToString(Expr::SCRSTYLE_OneLine).c_str());
			return nullptr;
		}
	}
	ValueTypeInfo *pValueTypeInfo = LookupValueType(symbolList);
	if (pValueTypeInfo == nullptr) {
		sig.SetError(ERR_ValueError, "can't find type name: '%s'",
								symbolList.Join(".").c_str());
		return nullptr;
	}
	return pValueTypeInfo;
}

ValueTypeInfo *Environment::LookupValueType(Signal &sig, const Expr *pExpr)
{
	SymbolList symbolList;
	//if (!Parser::ParseDottedIdentifier(pExpr, symbolList)) {
	if (!symbolList.AddFromExpr(pExpr)) {
		sig.SetError(ERR_TypeError, "invalid element for type name: '%s'",
						pExpr->ToString(Expr::SCRSTYLE_OneLine).c_str());
		return nullptr;
	}
	ValueTypeInfo *pValueTypeInfo = LookupValueType(symbolList);
	if (pValueTypeInfo == nullptr) {
		sig.SetError(ERR_ValueError, "can't find type name: '%s'",
								symbolList.Join(".").c_str());
		return nullptr;
	}
	return pValueTypeInfo;
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

bool Environment::ImportModules(Signal &sig, const char *moduleNames,
									bool binaryOnlyFlag, bool mixinTypeFlag)
{
	bool assignModuleNameFlag = true;
	const Symbol *pSymbolAlias = nullptr;
	const SymbolSet *pSymbolsToMixIn = nullptr;
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
		//if (!Parser::ParseDottedIdentifier(moduleName.c_str(), symbolList)) {
		if (!symbolList.AddFromString(moduleName.c_str())) {
			sig.SetError(ERR_ImportError, "wrong format of module name");
			return false;
		}
		if (ImportModule(sig, symbolList.begin(), symbolList.end(), assignModuleNameFlag,
					pSymbolAlias, pSymbolsToMixIn,
					overwriteFlag, binaryOnlyFlag, mixinTypeFlag) == nullptr) return false;
		moduleName.clear();
		if (ch == '\0') break;
	}
	return true;
}

Module *Environment::ImportModule(Signal &sig, const Expr *pExpr,
			const Symbol *pSymbolAlias, const SymbolSet *pSymbolsToMixIn,
			bool overwriteFlag, bool binaryOnlyFlag, bool mixinTypeFlag)
{
	bool successFlag = false;
	bool assignModuleNameFlag = true;
	SymbolList symbolList;
	if (pExpr->IsUnaryOp()) {
		const Expr_UnaryOp *pExprEx = dynamic_cast<const Expr_UnaryOp *>(pExpr);
		const Symbol *pSymbol = pExprEx->GetOperator()->GetSymbol();
		if (pSymbol->IsIdentical(Symbol::Hyphen)) {
			// import(-foo)
			//successFlag = Parser::ParseDottedIdentifier(pExprEx->GetChild(), symbolList);
			successFlag = symbolList.AddFromExpr(pExprEx->GetChild());
			assignModuleNameFlag = false;
		} else if (pSymbol->IsIdentical(Symbol::Amp)) {
			// import(&foo)
			Value rtn = pExprEx->GetChild()->Exec(*this);
			if (sig.IsSignalled()) return nullptr;
			if (rtn.Is_string()) {
				const char *str = rtn.GetString();
				if (*str == '-') {
					assignModuleNameFlag = false;
					str++;
				}
				//successFlag = Parser::ParseDottedIdentifier(str, symbolList);
				successFlag = symbolList.AddFromString(str);
			} else {
				sig.SetError(ERR_ImportError, "module name must be a string");
				return nullptr;
			}
		} else {
			// nothing to do
		}
	} else {
		//successFlag = Parser::ParseDottedIdentifier(pExpr, symbolList);
		successFlag = symbolList.AddFromExpr(pExpr);
	}
	if (!successFlag) {
		sig.SetError(ERR_ImportError, "wrong format of module name");
		return nullptr;
	}
	return ImportModule(sig, symbolList.begin(), symbolList.end(), assignModuleNameFlag,
						pSymbolAlias, pSymbolsToMixIn,
						overwriteFlag, binaryOnlyFlag, mixinTypeFlag);
}

Module *Environment::ImportModule(Signal &sig, SymbolList::const_iterator ppSymbolOfModule,
			SymbolList::const_iterator ppSymbolOfModuleEnd, bool assignModuleNameFlag,
			const Symbol *pSymbolAlias, const SymbolSet *pSymbolsToMixIn,
			bool overwriteFlag, bool binaryOnlyFlag, bool mixinTypeFlag)
{
	const Symbol *pSymbolOfModule = nullptr;
	for (SymbolList::const_iterator ppSymbol = ppSymbolOfModule;
							ppSymbol != ppSymbolOfModuleEnd; ppSymbol++) {
		pSymbolOfModule = *ppSymbol;
	}
	Module *pModule = GetGlobal()->LookupIntegratedModule(pSymbolOfModule->GetName());
	if (pModule == nullptr) {
		String pathName;
		if (!SearchSeparatedModuleFile(sig, pathName,
				ppSymbolOfModule, ppSymbolOfModuleEnd, binaryOnlyFlag)) return nullptr;
		pModule = GetGlobal()->LookupSeparatedModule(pathName.c_str());
		if (pModule != nullptr) {
			// nothing to do
		} else if (IsBinaryModule(pathName.c_str())) {
			pModule = ImportSeparatedModule_Binary(this, pathName.c_str(), pSymbolOfModule);
		} else {
			pModule = ImportSeparatedModule_Script(this, pathName.c_str(), pSymbolOfModule);
		}
		if (pModule == nullptr) return nullptr;
	}
	if (pSymbolsToMixIn == nullptr) {
		if (!assignModuleNameFlag) {
			// import(-foo)
			// nothing to do
		} else if (pSymbolAlias == nullptr) {
			// import(foo)
			Environment *pEnvDst = this;
			for (SymbolList::const_iterator ppSymbol = ppSymbolOfModule;
								ppSymbol + 1 != ppSymbolOfModuleEnd; ppSymbol++) {
				const Symbol *pSymbol = *ppSymbol;
				Value *pValue = pEnvDst->LookupValue(pSymbol, ENVREF_NoEscalate);
				if (pValue == nullptr) {
					Module *pModuleParent = ImportModule(sig, ppSymbolOfModule,
								ppSymbol + 1, assignModuleNameFlag, nullptr, nullptr,
								overwriteFlag, false, false);
					if (pModuleParent == nullptr) return nullptr;
					pEnvDst = pModuleParent;
				} else if (pValue->IsModule()) {
					pEnvDst = pValue->GetModule();
				} else {
					sig.SetError(ERR_ImportError,
						"module symbol conflicts with an existing variable '%s'",
						SymbolList::Join(ppSymbolOfModule, ppSymbol + 1, '.').c_str());
					return nullptr;
				}
			}
			Value *pValue = pEnvDst->LookupValue(pSymbolOfModule, ENVREF_Escalate);
			if (pValue != nullptr && pValue->IsModule() && pValue->GetModule() == pModule) {
				// nothing to do
			} else {
				Value valueOfModule(Module::Reference(pModule));
				if (!pEnvDst->ImportValue(pSymbolOfModule, valueOfModule, EXTRA_Public, overwriteFlag)) {
					sig.SetError(ERR_ImportError,
							 "module symbol conflicts with an existing variable '%s'",
							 SymbolList::Join(ppSymbolOfModule, ppSymbolOfModuleEnd, '.').c_str());
					return nullptr;
				}
			}
		} else {
			// import(foo, bar)
			Value valueOfModule(Module::Reference(pModule));
			if (!ImportValue(pSymbolAlias, valueOfModule, EXTRA_Public, overwriteFlag)) {
				sig.SetError(ERR_ImportError,
					"module symbol conflicts with an existing variable '%s'",
					pSymbolAlias->GetName());
				return nullptr;
			}
		}
	} else if (pSymbolsToMixIn->IsSet(Symbol::Ast)) {
		// import(hoge) {*}
		//GetFrameOwner().DbgPrint();
		foreach_const (ValueExMap, iter, pModule->GetTopFrame()->GetValueExMap()) {
			const Symbol *pSymbol = iter->first;
			const ValueEx &valueEx = iter->second;
			if (pSymbol->IsPrivateName()) {
				// nothing to do
			} else if (!ImportValue(pSymbol, valueEx, valueEx.GetExtra(), overwriteFlag)) {
				sig.SetError(ERR_ImportError,
					"imported variable name conflicts with an existing one '%s'",
					pSymbol->GetName());
				return nullptr;
			}
		}
	} else {
		// import(hoge) {foo, bar}
		foreach_const (SymbolSet, ppSymbol, *pSymbolsToMixIn) {
			const Symbol *pSymbol = *ppSymbol;
			ValueEx *pValueEx = pModule->LookupValue(pSymbol, ENVREF_NoEscalate);
			if (pValueEx == nullptr) {
				// nothing to do
			} else if (!ImportValue(pSymbol, *pValueEx, pValueEx->GetExtra(), overwriteFlag)) {
				sig.SetError(ERR_ImportError,
						"imported variable name conflicts with an existing one '%s'",
												pSymbol->GetName());
				return nullptr;
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

bool Environment::SearchSeparatedModuleFile(Signal &sig, String &pathName,
		SymbolList::const_iterator ppSymbolOfModule,
		SymbolList::const_iterator ppSymbolOfModuleEnd, bool binaryOnlyFlag)
{
	Environment &env = *this;
	const Value *pValDirNameList = GetGlobal()->GetModule_sys()->
							LookupValue(Gura_Symbol(path), ENVREF_NoEscalate);
	if (pValDirNameList == nullptr) {
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
				if (PathMgr::DoesExist(env, pathName.c_str())) return true;
				if (sig.IsSignalled()) return false;
			}
		} while (0);
	}
	sig.SetError(ERR_ImportError, "can't find a module named '%s'",
		SymbolList::Join(ppSymbolOfModule, ppSymbolOfModuleEnd, '.').c_str());
	return false;
}

Module *Environment::ImportSeparatedModule_Script(Environment *pEnvOuter,
									const char *pathName, const Symbol *pSymbol)
{
	Environment &env = *this;
	AutoPtr<Stream> pStream(Stream::Open(env, pathName, Stream::ATTR_Readable));
	if (_sig.IsError()) return nullptr;
	AutoPtr<Expr_Root> pExprRoot(Parser(_sig, pStream->GetName()).ParseStream(*pEnvOuter, *pStream));
	if (_sig.IsSignalled()) return nullptr;
	Module *pModule = new Module(pEnvOuter, pSymbol,
							pathName, Expr::Reference(pExprRoot.get()), nullptr);
	GetGlobal()->RegisterSeparatedModule(pathName, pModule);
	bool echoFlagSaved = pModule->GetGlobal()->GetEchoFlag();
	pModule->GetGlobal()->SetEchoFlag(false);
	pExprRoot->Exec(*pModule);
	pModule->GetGlobal()->SetEchoFlag(echoFlagSaved);
	if (_sig.IsSignalled()) {
		GetGlobal()->UnregisterSeparatedModule(pathName);
		delete pModule;
		return nullptr;
	}
	return pModule;
}

Module *Environment::ImportSeparatedModule_Binary(Environment *pEnvOuter,
									const char *pathName, const Symbol *pSymbol)
{
	OAL::DynamicLibrary dynamicLibrary;
	if (!dynamicLibrary.Open(_sig, pathName)) return nullptr;
	// gcc of a certain version such as 3.4.6 may cause an error when trying to
	// cast between pointer-to-function and pointer-to-using with reinterpret_cast.
	ModuleValidateType moduleValidate =
		(ModuleValidateType)dynamicLibrary.GetEntry(_sig, "GuraModuleValidate");
	ModuleEntryType moduleEntry =
		(ModuleEntryType)dynamicLibrary.GetEntry(_sig, "GuraModuleEntry");
	ModuleTerminateType moduleTerminate =
		(ModuleTerminateType)dynamicLibrary.GetEntry(_sig, "GuraModuleTerminate");
	if (moduleValidate == nullptr || moduleEntry == nullptr || moduleTerminate == nullptr) {
		_sig.SetError(ERR_ImportError, "can't find necessary entry functions");
		return nullptr;
	}
	if (!(*moduleValidate)()) {
		_sig.SetError(ERR_VersionError, "unacceptable version of module");
		return nullptr;
	}
	Module *pModule = new Module(pEnvOuter, pSymbol, pathName, nullptr, moduleTerminate);
	GetGlobal()->RegisterSeparatedModule(pathName, pModule);
	if (!(*moduleEntry)(*pModule)) {
		GetGlobal()->UnregisterSeparatedModule(pathName);
		delete pModule;
		return nullptr;
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
	return (pValue == nullptr || !pValue->Is_string())? "" : pValue->GetString();
}

const Symbol *Environment::GetLangCode()
{
	Value *pValue = GetGlobal()->GetModule_sys()->
					LookupValue(Gura_Symbol(langcode), ENVREF_NoEscalate);
	if (pValue == nullptr || !pValue->IsInstanceOf(VTYPE_symbol)) {
		return Gura_Symbol(en);
	}
	return pValue->GetSymbol();
}

Stream *Environment::GetConsole()
{
	Value *pValue = GetGlobal()->GetModule_sys()->
					LookupValue(Gura_Symbol(stdout), ENVREF_NoEscalate);
	if (pValue == nullptr || !pValue->IsInstanceOf(VTYPE_stream)) {
		return GetConsoleDumb();
	}
	return &pValue->GetStream();
}

Stream *Environment::GetConsoleErr()
{
	Value *pValue = GetGlobal()->GetModule_sys()->
					LookupValue(Gura_Symbol(stderr), ENVREF_NoEscalate);
	if (pValue == nullptr || !pValue->IsInstanceOf(VTYPE_stream)) {
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

void Environment::SetError(ErrorType errType, const char *format, ...) const
{
	va_list ap;
	va_start(ap, format);
	SetErrorV(errType, format, ap);
	va_end(ap);
}

void Environment::SetError_AccessViolation(const Symbol *pSymbol) const
{
	if (IsModule()) {
		SetError(ERR_MemberAccessError,
				 "can't access module member %s.%s",
				 dynamic_cast<const Module *>(this)->GetName(), pSymbol->GetName());
	} else if (IsClass()) {
		SetError(ERR_MemberAccessError,
				 "can't access class member %s.%s",
				 dynamic_cast<const Class *>(this)->GetName(), pSymbol->GetName());
	} else if (IsObject()) {
		SetError(ERR_MemberAccessError,
				 "can't access object member %s#%s",
				 dynamic_cast<const Object *>(this)->GetClass()->GetName(),
				 pSymbol->GetName());
	} else {
		SetError(ERR_ValueError,
				 "can't access variable %s", pSymbol->GetName());
	}
}

void Environment::SetError_PropertyNotFound(const Symbol *pSymbol) const
{
	if (IsModule()) {
		SetError(ERR_ValueError,
				 "%s module does not have a symbol '%s'",
				 dynamic_cast<const Module *>(this)->GetName(), pSymbol->GetName());
	} else if (IsClass()) {
		SetError(ERR_ValueError,
				 "%s class does not have a property '%s'",
				 dynamic_cast<const Class *>(this)->GetName(), pSymbol->GetName());
	} else if (IsObject()) {
		SetError(ERR_ValueError,
				 "the object of %s class does not have a property '%s'",
				 dynamic_cast<const Object *>(this)->GetClass()->GetName(),
				 pSymbol->GetName());
	} else {
		SetError(ERR_ValueError,
				 "undefined symbol '%s'", pSymbol->GetName());
	}
}

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

void Environment::Global::Prepare(Environment &env)
{
	_workingDirList.push_back(OAL::GetCurDir());
	_pValueTypePool = ValueTypePool::GetInstance();
	_pConsoleDumb.reset(new StreamDumb(env));
}

Class *Environment::Global::LookupClass(ValueType valType) const
{
	return ValueTypePool::GetInstance()->Lookup(valType)->GetClass();
}

Module *Environment::Global::LookupIntegratedModule(const char *name) const
{
	ModuleMap::const_iterator iter = _moduleMapIntegrated.find(name);
	return (iter == _moduleMapIntegrated.end())? nullptr : iter->second;
}

void Environment::Global::RegisterIntegratedModule(Module *pModule)
{
	_moduleMapIntegrated[pModule->GetName()] = pModule;
}

Module *Environment::Global::LookupSeparatedModule(const char *pathName) const
{
	ModuleMap::const_iterator iter = _moduleMapSeparated.find(pathName);
	return (iter == _moduleMapSeparated.end())? nullptr : iter->second;
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
	_cntRef(1), _envType(frame._envType), _pGlobal(frame._pGlobal), _pArgWeak(nullptr),
	_valueEx_arg(VTYPE_undefined, VFLAG_None, EXTRA_None),
	_valueEx_this(VTYPE_undefined, VFLAG_None, EXTRA_None)
{
	if (!frame._pValueExMap.IsNull()) {
		_pValueExMap.reset(new ValueExMap(*frame._pValueExMap));
	}
	if (frame._pValueTypeMap.get() != nullptr) {
		_pValueTypeMap.reset(new ValueTypeMap(*frame._pValueTypeMap));
	}
}

Environment::Frame::Frame(EnvType envType, Global *pGlobal) :
	_cntRef(1), _envType(envType), _pGlobal(pGlobal), _pArgWeak(nullptr),
	_valueEx_arg(VTYPE_undefined, VFLAG_None, EXTRA_None),
	_valueEx_this(VTYPE_undefined, VFLAG_None, EXTRA_None)
{
}

Environment::Frame::~Frame()
{
}

void Environment::Frame::Delete(Frame *pFrame)
{
	if (pFrame == nullptr) return;
#if 0
	EnvType envType = pFrame->GetEnvType();
	if (envType != ENVTYPE_root && envType != ENVTYPE_class &&
										!pFrame->_pValueExMap.IsNull()) {
		const ValueExMap &valueExMap = *pFrame->_pValueExMap;
		EnvironmentSet envSet;
		foreach_const (ValueExMap, iter, valueExMap) {
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

void Environment::Frame::AssignValue(const Symbol *pSymbol, const Value &value, ULong extra)
{
	if (pSymbol->IsIdentical(Gura_Symbol(__arg__))) {
		_valueEx_arg = ValueEx(value, extra);
	} else if (pSymbol->IsIdentical(Gura_Symbol(this_))) {
		_valueEx_this = ValueEx(value, extra);
	} else {
		if (_pValueExMap.IsNull()) _pValueExMap.reset(new ValueExMap());
		ValueExMap::iterator iter = _pValueExMap->find(pSymbol);
		if (iter == _pValueExMap->end()) {
			(*_pValueExMap)[pSymbol] = ValueEx(value, extra);
		} else {
			ULong extraDst = iter->second.GetExtra();
			iter->second = ValueEx(value, extra | extraDst);
			if ((extraDst & EXTRA_Argument) && _pArgWeak != nullptr) {
				Argument::Slot *pSlot = _pArgWeak->FindSlotBySymbol(pSymbol);
				if (pSlot != nullptr) {
					// Clear 'assigned' status so that its value is restored
					// when the next loop of implicit mapping begins.
					pSlot->SetSlotStat(Argument::SLOTSTAT_Valid);
				}
			}
		}
	}
}

ValueEx *Environment::Frame::LookupValue(Environment &env, const Symbol *pSymbol)
{
	if (pSymbol->IsIdentical(Gura_Symbol(__arg__))) {
		if (_valueEx_arg.IsInvalid() && _pArgWeak != nullptr) {
			_valueEx_arg = ValueEx(new Object_argument(env, _pArgWeak->Reference()),
								   VFLAG_FundOwner, EXTRA_Public);
		}
		return _valueEx_arg.IsValid()? &_valueEx_arg : nullptr;
	} else if (pSymbol->IsIdentical(Gura_Symbol(this_))) {
		if (_valueEx_this.IsInvalid() && _pArgWeak != nullptr &&
							_pArgWeak->GetFunction()->GetType() != FUNCTYPE_Block) {
			_valueEx_this = ValueEx(_pArgWeak->GetValueThis(), EXTRA_Public);
			_valueEx_this.AddFlags(VFLAG_Privileged);
		}
		return _valueEx_this.IsValid()? &_valueEx_this : nullptr;
	} else {
		if (_pValueExMap.IsNull()) return nullptr;
		ValueExMap::iterator iter = _pValueExMap->find(pSymbol);
		return (iter == _pValueExMap->end())? nullptr : &iter->second;
	}
}

void Environment::Frame::RemoveValue(const Symbol *pSymbol)
{
	if (_pValueExMap.IsNull()) return;
	_pValueExMap->erase(pSymbol);
}

void Environment::Frame::AssignValueType(ValueTypeInfo *pValueTypeInfo)
{
	if (_pValueTypeMap.get() == nullptr) _pValueTypeMap.reset(new ValueTypeMap());
	(*_pValueTypeMap)[pValueTypeInfo->GetSymbol()] = pValueTypeInfo;
}

ValueTypeInfo *Environment::Frame::LookupValueType(const Symbol *pSymbol)
{
	if (_pValueTypeMap.get() == nullptr) return nullptr;
	ValueTypeMap::iterator iter = _pValueTypeMap->find(pSymbol);
	return (iter == _pValueTypeMap->end())? nullptr : iter->second;
}

SymbolSet &Environment::Frame::PrepareSymbolsPublic()
{
	if (_pSymbolsPublic.get() == nullptr) {
		_pSymbolsPublic.reset(new SymbolSet());
	}
	return *_pSymbolsPublic;
}

void Environment::Frame::DbgPrint() const
{
	::printf("%p %-10s\n", this, GetEnvTypeName(GetEnvType()));
	if (_pValueExMap.IsNull()) {
		::printf(" [Values] .. null\n");
	} else {
		::printf(" [Values] .. %p\n", _pValueExMap.get());
		if (!_pValueExMap->empty()) {
			foreach_const (ValueExMap, iter, *_pValueExMap) {
				::printf(" %s", iter->first->GetName());
			}
			::printf("\n");
		}
	}
	if (_pValueTypeMap.get() == nullptr) {
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
