//-----------------------------------------------------------------------------
// Gura module: postgresql
//-----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleBody(postgresql)

//-----------------------------------------------------------------------------
// Object_postgresql
//-----------------------------------------------------------------------------
Object_postgresql::Object_postgresql() :
					Object(Gura_UserClass(postgresql)), _conn(nullptr)
{
}

Object_postgresql::~Object_postgresql()
{
	Close();
}

Object *Object_postgresql::Clone() const
{
	return nullptr;
}

String Object_postgresql::ToString(bool exprFlag)
{
	String str;
	str += "<postgresql";
	str += ">";
	return str;
}

bool Object_postgresql::Connect(Signal &sig, const char *pghost, const char *pgport,
	const char *pgoptions, const char *pgtty, const char *dbName, const char *login, const char *pwd)
{
	_conn = ::PQsetdbLogin(pghost, pgport, pgoptions, pgtty, dbName, login, pwd);
	if (::PQstatus(_conn) == CONNECTION_BAD) {
		sig.SetError(ERR_RuntimeError, "PostgreSQL %s", ::PQerrorMessage(_conn));
	    ::PQfinish(_conn);
	    _conn = nullptr;
	    return false;
    }
	return true;
}

void Object_postgresql::Close()
{
	if (_conn != nullptr) {
		::PQfinish(_conn);
		_conn = nullptr;
	}
}

Iterator *Object_postgresql::Exec(Signal &sig, const char *command)
{
	if (_conn == nullptr) return nullptr;
	PGresult *res = ::PQexec(_conn, command);
	if (res == nullptr || ::PQresultStatus(res) != PGRES_COMMAND_OK) {
		sig.SetError(ERR_RuntimeError, "PostgreSQL %s", ::PQerrorMessage(_conn));
		::PQclear(res);
		return nullptr;
	} else if (::PQresultStatus(res) == PGRES_TUPLES_OK) {
		Iterator *pIterator =
				new IteratorTuple(Object_postgresql::Reference(this), res);
		return pIterator;
	}
	::PQclear(res);
	return nullptr;
}

//-----------------------------------------------------------------------------
// Object_postgresql::IteratorTuple
//-----------------------------------------------------------------------------
Object_postgresql::IteratorTuple::~IteratorTuple()
{
	Object::Delete(_pObj);
	::PQclear(_res);
}

bool Object_postgresql::IteratorTuple::DoNext(Environment &env, Value &value)
{
	//Environment &env = *_pObj;
	if (_iTuple >= ::PQntuples(_res)) return false;
	int nFields = ::PQnfields(_res);
	Object_list *pObjList = value.InitAsList(env);
	pObjList->Reserve(nFields);
	for (int iField = 0; iField < nFields; iField++) {
		pObjList->Add(Value(::PQgetvalue(_res, _iTuple, iField)));
	}
	_iTuple++;
	return true;
}

String Object_postgresql::IteratorTuple::ToString() const
{
	return String("<iterator:postgresql#tuple>");
}

//-----------------------------------------------------------------------------
// Gura interfaces for Object_postgresql
//-----------------------------------------------------------------------------
// postgresql.postgresql#close()
Gura_DeclareMethod(postgresql, close)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en),
		"Shuts down the connection with an PostgreSQL server.");
}

Gura_ImplementMethod(postgresql, close)
{
	Object_postgresql *pObj = Object_postgresql::GetObjectThis(arg);
	pObj->Close();
	return Value::Nil;
}

// postgresql.postgresql#query(stmt:string)
Gura_DeclareMethod(postgresql, query)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "stmt", VTYPE_string);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementMethod(postgresql, query)
{
	Signal &sig = env.GetSignal();
	Object_postgresql *pObj = Object_postgresql::GetObjectThis(arg);
	Iterator *pIterator = pObj->Exec(sig, arg.GetString(0));
	// Object_postgresql::Exec() may return nullptr even if no error occurs.
	if (pIterator == nullptr) return Value::Nil;
	return ReturnIterator(env, arg, pIterator);
}

// assignment
Gura_ImplementUserClass(postgresql)
{
	Gura_AssignMethod(postgresql, query);
}

//-----------------------------------------------------------------------------
// Gura module functions: postgresql
//-----------------------------------------------------------------------------
// postgresql.connect(host?:string, user?:string, passwd?:string, db?:string) {block?}
Gura_DeclareFunction(connect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "host", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "user", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "passwd", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "db", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementFunction(connect)
{
	Signal &sig = env.GetSignal();
	const char *pghost = arg.Is_string(0)? arg.GetString(0) : nullptr;
	const char *login = arg.Is_string(1)? arg.GetString(1) : nullptr;
	const char *pwd = arg.Is_string(2)? arg.GetString(2) : nullptr;
	const char *dbName = arg.Is_string(3)? arg.GetString(3) : nullptr;
	const char *pgport = nullptr;
	const char *pgoptions = nullptr;
	const char *pgtty = nullptr;
	Object_postgresql *pObj = new Object_postgresql();
	if (!pObj->Connect(sig, pghost, pgport, pgoptions, pgtty, dbName, login, pwd)) {
		delete pObj;
		return Value::Nil;
	}
	Value result(pObj);
	if (arg.IsBlockSpecified()) {
		const Function *pFuncBlock =
						arg.GetBlockFunc(env, GetSymbolForBlock());
		if (pFuncBlock == nullptr) return Value::Nil;
		ValueList valListArg(result);
		Args argsSub(valListArg);
		pFuncBlock->Eval(env, argsSub);
		result = Value::Nil; // object is destroyed here
	}
	return result;
}

// postgresql.test()
Gura_DeclareFunction(test)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementFunction(test)
{
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
	// class realization
	Gura_RealizeAndPrepareUserClass(postgresql, env.LookupClass(VTYPE_object));
	// function assignment
	Gura_AssignFunction(connect);
	Gura_AssignFunction(test);
	return true;
}

Gura_ModuleTerminate()
{
}

Gura_EndModuleBody(postgresql, postgresql)

Gura_RegisterModule(postgresql)
