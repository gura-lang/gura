//-----------------------------------------------------------------------------
// Gura tcl module
//-----------------------------------------------------------------------------
#ifndef __GURA_MODULE_TCL_H__
#define __GURA_MODULE_TCL_H__

#include <gura.h>
#undef DLLEXPORT
#include <tcl.h>
#include <tk.h>
#include <setjmp.h>

Gura_BeginModuleHeader(tcl)

Gura_DeclareUserSymbol(__tclname__);

class Object_interp;

//-----------------------------------------------------------------------------
// Handler declaration
//-----------------------------------------------------------------------------
class Handler {
private:
	AutoPtr<Object_interp> _pObjInterp;
	AutoPtr<Object_function> _pObjFunc;
	Signal _sig;
public:
	inline Handler(Object_interp *pObjInterp, Object_function *pObjFunc, Signal sig) :
					_pObjInterp(pObjInterp), _pObjFunc(pObjFunc), _sig(sig) {}
	~Handler();
	Value Eval(ValueList &valListArg);
	Value Eval(int argc, const char *argv[]);
	inline Object_interp *GetInterpObj() { return _pObjInterp.get(); }
	inline Signal &GetSignal() { return _sig; }
};

//-----------------------------------------------------------------------------
// Object_interp declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(interp);

class Object_interp : public Object {
public:
	struct EventPack {
		Tcl_Event ev;
		Tcl_Interp *interp;
		// call information
		int objc;
		Tcl_Obj **objv;
		Tcl_Condition *pCond;
		// return information
		int rtn;
		Tcl_Obj *objRtn;
	};
public:
	Gura_DeclareObjectAccessor(interp)
private:
	Tcl_Interp *_interp;
	Tcl_ThreadId _thread_id;
	int _cntCreatedCommand;
	int _cntCreatedVariable;
	Tcl_ObjType *ObjType_boolean;
	Tcl_ObjType *ObjType_bytearray;
	Tcl_ObjType *ObjType_double;
	Tcl_ObjType *ObjType_int;
	Tcl_ObjType *ObjType_list;
	Tcl_ObjType *ObjType_string;
public:
	Object_interp(Tcl_Interp *interp);
	inline Tcl_Interp *GetInterp() { return _interp; }
	virtual ~Object_interp();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	Tcl_Obj *ConvToTclObj(Environment &env, Signal sig, const Value &value);
	Value ConvFromTclObj(Environment &env, Signal sig, Tcl_Obj *obj);
	Tcl_Obj **CreateTclObjArray(Environment &env, Signal sig,
										const ValueList &valList, int *pObjc);
	String NewCommandName();
	String NewVariableName();
	void ExitMainLoop();
	Value TclEval(Environment &env, Signal sig, const ValueList &valList);
	static void DeleteTclObjArray(int objc, Tcl_Obj **objv);
	static int CommandProc(ClientData clientData, Tcl_Interp *interp,
										int argc, const char *argv[]);
	static void CommandDeleteProc(ClientData clientData);
	static int TclThreadProc(Tcl_Event *ev, int flags);
	Value InvokeTclThread(Environment &env, Signal sig, const ValueList &valListArg);
};

//-----------------------------------------------------------------------------
// Object_variable declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(variable);

class Object_variable : public Object {
public:
	Gura_DeclareObjectAccessor(variable)
private:
	AutoPtr<Object_interp> _pObjInterp;
	String _varName;
public:
	Object_variable(Object_interp *pObjInterp, const char *varName);
	inline Object_interp *GetInterpObj() { return _pObjInterp.get(); }
	inline const char *GetVarName() const { return _varName.c_str(); }
	virtual ~Object_variable();
	virtual Object *Clone() const;
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value DoSetProp(Environment &env, Signal sig, const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(Signal sig, bool exprFlag);
	bool Set(Environment &env, Signal sig, const Value &value);
	Value Get(Environment &env, Signal sig);
};

//-----------------------------------------------------------------------------
// Object_timer declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(timer);

class Object_timer : public Object {
public:
	Gura_DeclareObjectAccessor(timer)
private:
	AutoPtr<Object_interp> _pObjInterp;
	bool _contFlag;
	int _cnt, _idx;
	int _msecCont;
	Tcl_TimerToken _token;
	std::auto_ptr<Handler> _pHandler;
public:
	Object_timer(Object_interp *pObjInterp);
	virtual ~Object_timer();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	void Start(Signal sig, const Function *pFunc, int msec, int msecCont, int cnt);
	void Cancel();
	bool TimerProc();
	static void TimerProcStub(ClientData clientData);
};

Gura_EndModuleHeader(tcl)

#endif
