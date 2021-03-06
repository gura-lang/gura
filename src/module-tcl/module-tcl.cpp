//-----------------------------------------------------------------------------
// Gura module: tcl
// Tcl/Tk manual: http://www.tcl.tk/man/tcl8.5/
//-----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleBody(tcl)

TCL_DECLARE_MUTEX(g_mutex)

static jmp_buf g_jmpenv;

//-----------------------------------------------------------------------------
// Object_interp implementation
//-----------------------------------------------------------------------------
Object_interp::Object_interp(Tcl_Interp *interp) :
		Object(Gura_UserClass(interp)), _interp(interp),
		_cntCreatedCommand(0), _cntCreatedVariable(0)
{
	_thread_id = ::Tcl_GetCurrentThread();
	ObjType_boolean		= ::Tcl_GetObjType("boolean");
	ObjType_bytearray	= ::Tcl_GetObjType("bytearray");
	ObjType_double		= ::Tcl_GetObjType("double");
	ObjType_int			= ::Tcl_GetObjType("int");
	ObjType_list		= ::Tcl_GetObjType("list");
	ObjType_string		= ::Tcl_GetObjType("string");
}

Object_interp::~Object_interp()
{
	::Tcl_DeleteInterp(_interp);
}

Object *Object_interp::Clone() const
{
	return nullptr;
}

String Object_interp::ToString(bool exprFlag)
{
	return String("<tcl.interp>");
}

Tcl_Obj *Object_interp::ConvToTclObj(Environment &env, Signal &sig, const Value &value)
{
	if (value.IsInvalid()) {
		return ::Tcl_NewStringObj("", 0);
	} else if (value.Is_boolean()) {
		return ::Tcl_NewBooleanObj(value.GetBoolean());
	} else if (value.Is_binary()) {
		const Binary &binary = value.GetBinary();
		return ::Tcl_NewByteArrayObj(
			reinterpret_cast<const unsigned char *>(binary.data()), static_cast<int>(binary.size()));
	} else if (value.Is_number()) {
		Number num = value.GetNumber();
		if (static_cast<Number>(static_cast<long>(num)) == num) {
			return ::Tcl_NewLongObj(static_cast<long>(num));
		} else {
			return ::Tcl_NewDoubleObj(num);
		}
	} else if (value.Is_list()) {
		int objc;
		Tcl_Obj **objv = CreateTclObjArray(env, sig, value.GetList(), &objc);
		if (!sig.IsSignalled()) {
			return ::Tcl_NewListObj(objc, objv);
		}
	} else if (value.Is_string()) {
		const char *str = value.GetString();
		return ::Tcl_NewStringObj(str, static_cast<int>(::strlen(str)));
	} else if (value.Is_function()) {
		Handler *pHandler = new Handler(Object_interp::Reference(this),
				Object_function::Reference(Object_function::GetObject(value)));
		String cmdName = NewCommandName();
		::Tcl_CreateCommand(_interp, cmdName.c_str(), CommandProc,
											pHandler, CommandDeleteProc);
		return ::Tcl_NewStringObj(cmdName.c_str(), static_cast<int>(cmdName.size()));
	} else if (value.IsType(VTYPE_variable)) {
		const Object_variable *pObjVariable =
						dynamic_cast<const Object_variable *>(value.GetObject());
		const char *varName = pObjVariable->GetVarName();
		return ::Tcl_NewStringObj(varName, static_cast<int>(::strlen(varName)));
	} else if (value.IsObject()) {
		Object *pObj = value.GetObject();
		const Function *pFunc =
					pObj->LookupFunction(Gura_UserSymbol(__tclname__), ENVREF_Escalate);
		if (pFunc != nullptr) {
			Value valueThis(pObj, VFLAG_NoFundOwner); // reference to self
			AutoPtr<Argument> pArg(new Argument(pFunc));
			pArg->SetValueThis(valueThis);
			Value result = pFunc->Eval(*pObj, *pArg);
			if (!sig.IsSignalled()) {
				return ConvToTclObj(env, sig, result);
			}
		}
	}
	String str = value.ToString(false);
	return ::Tcl_NewStringObj(str.c_str(), static_cast<int>(str.size()));
}

Value Object_interp::ConvFromTclObj(Environment &env, Signal &sig, Tcl_Obj *objPtr)
{
	Tcl_ObjType *typePtr = objPtr->typePtr;
	if (typePtr == nullptr) {
		return Value(objPtr->bytes, objPtr->length);
	} else if (typePtr == ObjType_boolean) {
		int value;
		::Tcl_GetBooleanFromObj(_interp, objPtr, &value);
		return Value(value? true : false);
	} else if (typePtr == ObjType_bytearray) {
		int length;
		unsigned char *binary = ::Tcl_GetByteArrayFromObj(objPtr, &length);
		return Value(new Object_binary(env, Binary(reinterpret_cast<char *>(binary), length), true));
	} else if (typePtr == ObjType_double) {
		double value;
		::Tcl_GetDoubleFromObj(_interp, objPtr, &value);
		return Value(value);
	} else if (typePtr == ObjType_int) {
		int value;
		::Tcl_GetIntFromObj(_interp, objPtr, &value);
		return Value(value);
	} else if (typePtr == ObjType_list) {
		int length;
		::Tcl_ListObjLength(_interp, objPtr, &length);
		Value result;
		Object_list *pObjList = result.InitAsList(env);
		pObjList->Reserve(length);
		for (int i = 0; i < length; i++) {
			Tcl_Obj *objElemPtr;
			::Tcl_ListObjIndex(_interp, objPtr, i, &objElemPtr);
			pObjList->Add(ConvFromTclObj(env, sig, objElemPtr));
			if (sig.IsSignalled()) return Value::Nil;
		}
		return result;
	} else if (typePtr == ObjType_string) {
		int length;
		char *value = ::Tcl_GetStringFromObj(objPtr, &length);
		return Value(value);
	}
	return Value(objPtr->bytes, objPtr->length);
}

Tcl_Obj **Object_interp::CreateTclObjArray(Environment &env, Signal &sig,
										const ValueList &valList, int *pObjc)
{
	*pObjc = static_cast<int>(valList.size());
	Tcl_Obj **objv = new Tcl_Obj *[*pObjc];
	int i = 0;
	foreach_const (ValueList, pValue, valList) {
		objv[i++] = ConvToTclObj(env, sig, *pValue);
		if (sig.IsSignalled()) {
			DeleteTclObjArray(i - 1, objv);
			return nullptr;
		}
	}
	return objv;
}

void Object_interp::DeleteTclObjArray(int objc, Tcl_Obj **objv)
{
	for (int i = 0; i < objc; i++) {
		Tcl_DecrRefCount(objv[i]);
	}
	delete[] objv;
}

Value Object_interp::TclEval(Environment &env, const ValueList &valList)
{
	Signal &sig = env.GetSignal();
	int objc;
	Tcl_Obj **objv = CreateTclObjArray(env, sig, valList, &objc);
	if (sig.IsSignalled()) return Value::Nil;
	int rtn = ::Tcl_EvalObjv(_interp, objc, objv, TCL_EVAL_DIRECT | TCL_EVAL_GLOBAL);
	if (rtn != TCL_OK) {
		sig.SetError(ERR_LibraryError, "[tcl] %s\n", ::Tcl_GetStringResult(_interp));
		delete[] objv;
		return Value::Nil;
	}
	delete[] objv;
	Tcl_Obj *obj = ::Tcl_GetObjResult(_interp);
	if (obj == nullptr) return Value::Nil;
	Value result = ConvFromTclObj(env, sig, obj);
	return result;
}

String Object_interp::NewCommandName()
{
	char cmdName[32];
	::sprintf(cmdName, "::gura::cmd%d", _cntCreatedCommand);
	_cntCreatedCommand++;
	return String(cmdName);
}

String Object_interp::NewVariableName()
{
	char varName[32];
	::sprintf(varName, "gura_variable%d", _cntCreatedVariable);
	_cntCreatedVariable++;
	return String(varName);
}

void Object_interp::ExitMainLoop()
{
	//Tk_Window tkwin = ::Tk_MainWindow(_interp);
	//if (tkwin != nullptr) ::Tk_DestroyWindow(tkwin);
	::longjmp(g_jmpenv, 1);
}

int Object_interp::CommandProc(ClientData clientData,
							Tcl_Interp *interp, int argc, const char *argv[])
{
	Handler *pHandler = reinterpret_cast<Handler *>(clientData);
	Object_interp *pObjInterp = pHandler->GetInterpObj();
	Environment &env = *pObjInterp;
	Signal &sig = env.GetSignal();
	if (argc > 0) {
		// skip the first argument
		argc--, argv++;
	}
	Value result = pHandler->Eval(argc, argv);
	if (sig.IsSignalled()) {
		pObjInterp->ExitMainLoop();
		return TCL_OK;
	}
	Tcl_Obj *obj = pObjInterp->ConvToTclObj(env, sig, result);
	if (sig.IsSignalled()) {
		pObjInterp->ExitMainLoop();
		return TCL_OK;
	}
	::Tcl_SetObjResult(interp, obj);
	return TCL_OK;
}

void Object_interp::CommandDeleteProc(ClientData clientData)
{
	Handler *pHandler = reinterpret_cast<Handler *>(clientData);
	delete pHandler;
}

int Object_interp::TclThreadProc(Tcl_Event *ev, int flags)
{
	EventPack *pEventPack = reinterpret_cast<EventPack *>(ev);
	pEventPack->rtn = ::Tcl_EvalObjv(pEventPack->interp,
		pEventPack->objc, pEventPack->objv, TCL_EVAL_DIRECT | TCL_EVAL_GLOBAL);
	pEventPack->objRtn = ::Tcl_GetObjResult(pEventPack->interp);
	Tcl_IncrRefCount(pEventPack->objRtn);
	Object_interp::DeleteTclObjArray(pEventPack->objc, pEventPack->objv);
	pEventPack->objv = nullptr;
	// wake up calling thread
	Tcl_MutexLock(&g_mutex);
	Tcl_ConditionNotify(pEventPack->pCond);
	Tcl_MutexUnlock(&g_mutex);
	return 1;
}

Value Object_interp::InvokeTclThread(Environment &env, Signal &sig,
												const ValueList &valListArg)
{
	Tcl_Condition cond = nullptr;
	EventPack *pEventPack =
			reinterpret_cast<EventPack *>(::ckalloc(sizeof(EventPack)));
	pEventPack->ev.proc = TclThreadProc;
	pEventPack->interp = _interp;
	pEventPack->objv = CreateTclObjArray(env, sig, valListArg, &pEventPack->objc);
	if (sig.IsSignalled()) return Value::Nil;
	pEventPack->rtn = TCL_OK;
	pEventPack->objRtn = nullptr;
	pEventPack->pCond = &cond;
	do {
		Tcl_MutexLock(g_mutex);
		::Tcl_ThreadQueueEvent(_thread_id,
					reinterpret_cast<Tcl_Event *>(pEventPack), TCL_QUEUE_TAIL);
		::Tcl_ThreadAlert(_thread_id);
		Tcl_ConditionWait(&cond, g_mutex, nullptr);
		Tcl_MutexUnlock(g_mutex);
	} while (0);
	Tcl_ConditionFinalize(&cond);
	if (pEventPack->rtn != TCL_OK) {
		int length;
		const char *str = ::Tcl_GetStringFromObj(pEventPack->objRtn, &length);
		Tcl_DecrRefCount(pEventPack->objRtn);
		sig.SetError(ERR_LibraryError, "[tcl] %s\n", str);
		return Value::Nil;
	}
	Value result = ConvFromTclObj(env, sig, pEventPack->objRtn);
	Tcl_DecrRefCount(pEventPack->objRtn);
	return result;
}

//-----------------------------------------------------------------------------
// Gura interfaces for Object_interp
//-----------------------------------------------------------------------------
// tcl.interp#command(func:function)
Gura_DeclareMethod(interp, command)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "func", VTYPE_function);
	AddHelp(
		Gura_Symbol(en), 
		"");
}

Gura_ImplementMethod(interp, command)
{
	Object_interp *pThis = Object_interp::GetObjectThis(arg);
	Tcl_Interp *interp = pThis->GetInterp();
	Handler *pHandler = new Handler(Object_interp::Reference(pThis),
			Object_function::Reference(Object_function::GetObject(arg, 0)));
	String cmdName = pThis->NewCommandName();
	::Tcl_CreateCommand(interp, cmdName.c_str(), Object_interp::CommandProc,
									pHandler, Object_interp::CommandDeleteProc);
	return Value(cmdName);
}

// tcl.interp#eval(objs+)
Gura_DeclareMethod(interp, eval)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "objs", VTYPE_any, OCCUR_OnceOrMore);
	AddHelp(
		Gura_Symbol(en), 
		"");
}

Gura_ImplementMethod(interp, eval)
{
	Signal &sig = env.GetSignal();
	Object_interp *pThis = Object_interp::GetObjectThis(arg);
	return pThis->TclEval(env, arg.GetList(0));
}

#if 0
Gura_ImplementMethod(interp, eval)
{
	Signal &sig = env.GetSignal();
	Object_interp *pThis = Object_interp::GetObjectThis(arg);
	return pThis->InvokeTclThread(env, sig, arg.GetList(0));
}
#endif

// tcl.interp#evalscript(script:string)
Gura_DeclareMethod(interp, evalscript)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "script", VTYPE_string);
	AddHelp(
		Gura_Symbol(en), 
		"");
}

Gura_ImplementMethod(interp, evalscript)
{
	Signal &sig = env.GetSignal();
	Object_interp *pThis = Object_interp::GetObjectThis(arg);
	Tcl_Interp *interp = pThis->GetInterp();
	int rtn = ::Tcl_Eval(interp, arg.GetString(0));
	if (rtn != TCL_OK) {
		sig.SetError(ERR_LibraryError, "[tcl] %s\n", ::Tcl_GetStringResult(interp));
		return Value::Nil;
	}
	return pThis->ConvFromTclObj(env, sig, ::Tcl_GetObjResult(interp));
}

// tcl.interp#timer()
Gura_DeclareMethod(interp, timer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en), 
		"");
}

Gura_ImplementMethod(interp, timer)
{
	Object_interp *pThis = Object_interp::GetObjectThis(arg);
	Object_interp *pObjInterp = Object_interp::Reference(pThis);
	Object_timer *pObjTimer = new Object_timer(pObjInterp);
	return Value(pObjTimer);
}

// tcl.interp#variable(value?, varName?:string)
Gura_DeclareMethod(interp, variable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "value", VTYPE_any, OCCUR_ZeroOrOnce);
	DeclareArg(env, "varName", VTYPE_string, OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), 
		"");
}

Gura_ImplementMethod(interp, variable)
{
	Signal &sig = env.GetSignal();
	Object_interp *pThis = Object_interp::GetObjectThis(arg);
	Object_interp *pObjInterp = Object_interp::Reference(pThis);
	String varName;
	if (arg.Is_string(1)) {
		varName = arg.GetString(1);
	} else {
		varName = pObjInterp->NewVariableName();
	}
	Object_variable *pObjVariable = new Object_variable(pObjInterp, varName.c_str());
	if (arg.IsValid(0)) {
		if (!pObjVariable->Set(env, sig, arg.GetValue(0))) return Value::Nil;
	}
	return Value(pObjVariable);
}

// implementation of class Interp
Gura_ImplementUserClass(interp)
{
	Gura_AssignMethod(interp, command);
	Gura_AssignMethod(interp, eval);
	Gura_AssignMethod(interp, evalscript);
	Gura_AssignMethod(interp, timer);
	Gura_AssignMethod(interp, variable);
}

//-----------------------------------------------------------------------------
// Handler implementation
//-----------------------------------------------------------------------------
Handler::~Handler()
{
}

Value Handler::Eval(ValueList &valListArg)
{
	Function *pFunc = _pObjFunc->GetFunction();
	Environment &env = pFunc->GetEnvScope();
	Signal &sig = env.GetSignal();
	Value result = _pObjFunc->Eval(env, valListArg);
	if (sig.IsSignalled()) {
		_pObjInterp->ExitMainLoop();
		return Value::Nil;
	}
	return result;
}

Value Handler::Eval(int argc, const char *argv[])
{
	Function *pFunc = _pObjFunc->GetFunction();
	Environment &env = pFunc->GetEnvScope();
	Signal &sig = env.GetSignal();
	ValueList valListArg;
	//argc = ChooseMin(argc, static_cast<int>(pFunc->GetDeclList().size()));
	if (argc > 0) {
		valListArg.reserve(argc);
		for (int i = 0; i < argc; i++) {
			valListArg.push_back(Value(argv[i]));
		}
	}
	Value result = _pObjFunc->Eval(env, valListArg);
	if (sig.IsSignalled()) {
		_pObjInterp->ExitMainLoop();
		return Value::Nil;
	}
	return result;
}

//-----------------------------------------------------------------------------
// Object_variable implementation
//-----------------------------------------------------------------------------
Object_variable::Object_variable(Object_interp *pObjInterp, const char *varName) :
		Object(Gura_UserClass(variable)), _pObjInterp(pObjInterp), _varName(varName)
{
}

Object_variable::~Object_variable()
{
}

Object *Object_variable::Clone() const
{
	return new Object_variable(Object_interp::Reference(_pObjInterp.get()), GetVarName());
}

String Object_variable::ToString(bool exprFlag)
{
	String str;
	str += "<tcl.variable:";
	str += _varName;
	str += ">";
	return str;
}

bool Object_variable::DoDirProp(Environment &env, SymbolSet &symbols)
{
	Signal &sig = GetSignal();
	if (!Object::DoDirProp(env, symbols)) return false;
	symbols.insert(Gura_Symbol(boolean));
	symbols.insert(Gura_Symbol(string));
	symbols.insert(Gura_Symbol(number));
	return true;
}

Value Object_variable::DoGetProp(Environment &env, const Symbol *pSymbol,
						const SymbolSet &attrs, bool &evaluatedFlag)
{
	Signal &sig = GetSignal();
	if (pSymbol->IsIdentical(Gura_Symbol(boolean))) {
		Value value = Get(env, sig);
		if (sig.IsSignalled()) return Value::Nil;
		if (value.Is_string()) {
			if (*value.GetString() == '\0') {
				value = Value(false);
			} else {
				bool successFlag;
				Number num = value.ToNumber(true, successFlag);
				value = Value(successFlag? (num != 0) : true);
			}
		} else if (value.Is_number()) {
			value = Value(value.GetNumber() != 0);
		} else if (!value.Is_boolean()) {
			bool flag = value.GetBoolean();
			value = Value(flag);
		}
		evaluatedFlag = true;
		return value;
	} else if (pSymbol->IsIdentical(Gura_Symbol(string))) {
		Value value = Get(env, sig);
		if (sig.IsSignalled()) return Value::Nil;
		if (!value.Is_string()) {
			String str = value.ToString(false);
			if (sig.IsSignalled()) return Value::Nil;
			value = Value(str);
		}
		evaluatedFlag = true;
		return value;
	} else if (pSymbol->IsIdentical(Gura_Symbol(number))) {
		Value value = Get(env, sig);
		if (sig.IsSignalled()) return Value::Nil;
		if (!value.Is_number()) {
			bool successFlag;
			Number num = value.ToNumber(true, successFlag);
			value = Value(num);
		}
		evaluatedFlag = true;
		return value;
	}
	return Value::Nil;
}

Value Object_variable::DoSetProp(Environment &env, const Symbol *pSymbol, const Value &value,
						const SymbolSet &attrs, bool &evaluatedFlag)
{
	Signal &sig = GetSignal();
	if (pSymbol->IsIdentical(Gura_Symbol(boolean))) {
		Set(env, sig, value);
		if (sig.IsSignalled()) return Value::Nil;
		evaluatedFlag = true;
		return value;
	} else if (pSymbol->IsIdentical(Gura_Symbol(string))) {
		Set(env, sig, value);
		if (sig.IsSignalled()) return Value::Nil;
		evaluatedFlag = true;
		return value;
	} else if (pSymbol->IsIdentical(Gura_Symbol(number))) {
		Set(env, sig, value);
		if (sig.IsSignalled()) return Value::Nil;
		evaluatedFlag = true;
		return value;
	}
	return Value::Nil;
}

bool Object_variable::Set(Environment &env, Signal &sig, const Value &value)
{
	ValueList valList(Value("set"), Value(GetVarName()), value);
	_pObjInterp->TclEval(env, valList);
	return !sig.IsSignalled();
}

Value Object_variable::Get(Environment &env, Signal &sig)
{
	ValueList valList(Value("set"), Value(GetVarName()));
	return _pObjInterp->TclEval(env, valList);
}

//-----------------------------------------------------------------------------
// Gura interfaces for Object_variable
//-----------------------------------------------------------------------------
// implementation of class Variable
Gura_ImplementUserClass(variable)
{
	Gura_AssignValue(variable, Value(Reference()));
}

//-----------------------------------------------------------------------------
// Object_timer implementation
//-----------------------------------------------------------------------------
Object_timer::Object_timer(Object_interp *pObjInterp) :
		Object(Gura_UserClass(timer)), _pObjInterp(pObjInterp),
		_contFlag(false), _cnt(0), _idx(0), _msecCont(0)
{
}

Object_timer::~Object_timer()
{
	::Tcl_DeleteTimerHandler(_token);
}

Object *Object_timer::Clone() const
{
	return nullptr;
}

String Object_timer::ToString(bool exprFlag)
{
	String str;
	str += "<tcl.timer:";
	str += ">";
	return str;
}

void Object_timer::Start(Signal &sig, const Function *pFunc,
									int msec, int msecCont, int cnt)
{
	Environment &env = *this;
	_contFlag = true;
	_cnt = cnt, _idx = 0;
	_msecCont = msecCont;
	if (_cnt == 0) return;
	Object::Reference(this);
	_token = ::Tcl_CreateTimerHandler(msec, TimerProcStub, this);
	Object_function *pObjFunc = new Object_function(env, Function::Reference(pFunc));
	_pHandler.reset(new Handler(Object_interp::Reference(_pObjInterp.get()), pObjFunc));
}

void Object_timer::Cancel()
{
	::Tcl_DeleteTimerHandler(_token);
	_contFlag = false;
}

bool Object_timer::TimerProc()
{
	ValueList valListArg;
	valListArg.reserve(1);
	valListArg.push_back(Value(this, VFLAG_NoFundOwner));
	_pHandler->Eval(valListArg);
	_idx++;
	if (_contFlag && _idx != _cnt) {
		_token = ::Tcl_CreateTimerHandler(_msecCont, TimerProcStub, this);
		return true;
	}
	_contFlag = false;
	return false;
}

void Object_timer::TimerProcStub(ClientData clientData)
{
	Object_timer *pObjTimer =
						reinterpret_cast<Object_timer *>(clientData);
	if (!pObjTimer->TimerProc()) {
		Object::Delete(pObjTimer);
	}
}

//-----------------------------------------------------------------------------
// Gura interfaces for Object_timer
//-----------------------------------------------------------------------------
// tcl.timer#cancel()
Gura_DeclareMethod(timer, cancel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en), 
		"");
}

Gura_ImplementMethod(timer, cancel)
{
	Object_timer *pThis = Object_timer::GetObjectThis(arg);
	pThis->Cancel();
	Object::Delete(pThis);
	return Value::Nil;
}

// tcl.timer#start(msec:number, msecCont?:number, count?:number):reduce {block}
Gura_DeclareMethod(timer, start)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "msec", VTYPE_number);
	DeclareArg(env, "msecCont", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "count", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_Once);
	AddHelp(
		Gura_Symbol(en), 
		"");
}

Gura_ImplementMethod(timer, start)
{
	Signal &sig = env.GetSignal();
	Object_timer *pThis = Object_timer::GetObjectThis(arg);
	const Function *pFuncBlock =
					arg.GetBlockFunc(env, GetSymbolForBlock());
	int msec = arg.GetInt(0);
	int msecCont = arg.Is_number(1)? arg.GetInt(1) : msec;
	int cnt = arg.Is_number(2)? arg.GetInt(2) : -1;
	pThis->Start(sig, pFuncBlock, msec, msecCont, cnt);
	return arg.GetValueThis();
}

// implementation of class timer
Gura_ImplementUserClass(timer)
{
	Gura_AssignValue(variable, Value(Reference()));
	Gura_AssignMethod(timer, cancel);
	Gura_AssignMethod(timer, start);
}

//-----------------------------------------------------------------------------
// Gura interfaces for Object_image
//-----------------------------------------------------------------------------
// image#read@tcl(interp:tcl.interp, imageName:string):reduce
Gura_DeclareMethodAlias(image, read_tcl, "read@tcl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "interp", VTYPE_interp);
	DeclareArg(env, "imageName", VTYPE_string);
	AddHelp(
		Gura_Symbol(en),
		"Reads an image data from TCL image object.");
}

Gura_ImplementMethod(image, read_tcl)
{
	Signal &sig = env.GetSignal();
	Object_image *pThis = Object_image::GetObjectThis(arg);
	Image *pImage = pThis->GetImage();
	if (!pImage->CheckEmpty(sig)) return Value::Nil;
	Object_interp *pObjInterp = reinterpret_cast<Object_interp *>(arg.GetObject(0));
	Tcl_Interp *interp = pObjInterp->GetInterp();
	const char *imageName = arg.GetString(1);
	Tk_PhotoHandle handle = ::Tk_FindPhoto(interp, imageName);
	if (handle == nullptr) {
		sig.SetError(ERR_ValueError, "invalid image name %s", imageName);
		return Value::Nil;
	}
	int width, height;
	::Tk_PhotoGetSize(handle, &width, &height);
	if (!pImage->AllocBuffer(sig, width, height, 0xff)) return Value::Nil;
	Tk_PhotoImageBlock photoImageBlock;
	photoImageBlock.pixelPtr = reinterpret_cast<unsigned char *>(pImage->GetBuffer());
	photoImageBlock.width = width;
	photoImageBlock.height = height;
	photoImageBlock.pitch = static_cast<int>(pImage->GetBytesPerLine());
	photoImageBlock.pixelSize = static_cast<int>(pImage->GetBytesPerPixel());
	photoImageBlock.offset[0] = Image::OffsetR;
	photoImageBlock.offset[1] = Image::OffsetG;
	photoImageBlock.offset[2] = Image::OffsetB;
	photoImageBlock.offset[3] = Image::OffsetA;
	::Tk_PhotoGetImage(handle, &photoImageBlock);
	return arg.GetValueThis();
}

// image#write@tcl(interp:tcl.interp, imageName:string):reduce
Gura_DeclareMethodAlias(image, write_tcl, "write@tcl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "interp", VTYPE_interp);
	DeclareArg(env, "imageName", VTYPE_string);
	AddHelp(
		Gura_Symbol(en),
		"Writes an image data to TCL image object.");
}

Gura_ImplementMethod(image, write_tcl)
{
	Signal &sig = env.GetSignal();
	Object_image *pThis = Object_image::GetObjectThis(arg);
	Image *pImage = pThis->GetImage();
	if (!pImage->CheckValid(sig)) return Value::Nil;
	Object_interp *pObjInterp = reinterpret_cast<Object_interp *>(arg.GetObject(0));
	Tcl_Interp *interp = pObjInterp->GetInterp();
	const char *imageName = arg.GetString(1);
	Tk_PhotoHandle handle = ::Tk_FindPhoto(interp, imageName);
	if (handle == nullptr) {
		sig.SetError(ERR_ValueError, "invalid image name %s", imageName);
		return Value::Nil;
	}
	int width = static_cast<int>(pImage->GetWidth());
	int height = static_cast<int>(pImage->GetHeight());
	Tk_PhotoImageBlock photoImageBlock;
	photoImageBlock.pixelPtr = reinterpret_cast<unsigned char *>(pImage->GetBuffer());
	photoImageBlock.width = width;
	photoImageBlock.height = height;
	photoImageBlock.pitch = static_cast<int>(pImage->GetBytesPerLine());
	photoImageBlock.pixelSize = static_cast<int>(pImage->GetBytesPerPixel());
	photoImageBlock.offset[0] = Image::OffsetR;
	photoImageBlock.offset[1] = Image::OffsetG;
	photoImageBlock.offset[2] = Image::OffsetB;
	photoImageBlock.offset[3] = Image::OffsetA;
	::Tk_PhotoPutBlock(interp, handle, &photoImageBlock,
							0, 0, width, height, TK_PHOTO_COMPOSITE_SET);
	return arg.GetValueThis();
}

//-----------------------------------------------------------------------------
// Gura module functions: tcl
//-----------------------------------------------------------------------------
// tcl.interp()
Gura_DeclareFunction(interp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(interp));
	AddHelp(
		Gura_Symbol(en), 
		"");
}

Gura_ImplementFunction(interp)
{
	Signal &sig = env.GetSignal();
	Tcl_Interp *interp = ::Tcl_CreateInterp();
	if (::Tcl_Init(interp) != TCL_OK) {
		sig.SetError(ERR_LibraryError, "[tcl] %s\n", ::Tcl_GetStringResult(interp));
		::Tcl_DeleteInterp(interp);
		return Value::Nil;
	}
	if (::Tk_Init(interp) != TCL_OK) {
		sig.SetError(ERR_LibraryError, "[tcl] %s\n", ::Tcl_GetStringResult(interp));
		::Tcl_DeleteInterp(interp);
		return Value::Nil;
	}
	return Value(new Object_interp(interp));
}

// tcl.Tk_MainLoop()
Gura_DeclareFunction(Tk_MainLoop)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en), 
		"");
}

Gura_ImplementFunction(Tk_MainLoop)
{
	if (::setjmp(g_jmpenv)) return Value::Nil;
	::Tk_MainLoop();
	return Value::Nil;
}

//-----------------------------------------------------------------------------
// Module Entries
//-----------------------------------------------------------------------------
Gura_ModuleValidate()
{
	return Version::CheckCoreVersion(GURA_VERSION, nullptr);
}

Gura_ModuleEntry()
{
	// symbol realization
	Gura_RealizeUserSymbol(__tclname__);
	// class realization
	Gura_RealizeAndPrepareUserClass(interp,	env.LookupClass(VTYPE_object));
	Gura_RealizeAndPrepareUserClass(variable,	env.LookupClass(VTYPE_object));
	Gura_RealizeAndPrepareUserClass(timer,	env.LookupClass(VTYPE_object));
	// function assignment
	Gura_AssignFunction(interp);
	Gura_AssignFunction(Tk_MainLoop);
	// method assignment to image class
	Gura_AssignMethodTo(VTYPE_image, image, read_tcl);
	Gura_AssignMethodTo(VTYPE_image, image, write_tcl);
	return true;
}

Gura_ModuleTerminate()
{
}

Gura_EndModuleBody(tcl, tcl)

Gura_RegisterModule(tcl)
