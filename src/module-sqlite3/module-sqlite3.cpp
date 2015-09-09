//-----------------------------------------------------------------------------
// Gura module: sqlite3
//-----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleBody(sqlite3)

//-----------------------------------------------------------------------------
// Object_db
//-----------------------------------------------------------------------------
Object_db::~Object_db()
{
	Close();
}

Object *Object_db::Clone() const
{
	return nullptr;
}

bool Object_db::Open(Signal &sig, const char *fileName)
{
	int rc = ::sqlite3_open(fileName, &_db);
	if (rc != SQLITE_OK) {
		sig.SetError(ERR_RuntimeError, "sqlite3 failed to create sqlite3 object");
		return false;
	}
	_fileName = fileName;
	return true;
}

void Object_db::Close()
{
	if (_db != nullptr) {
		::sqlite3_close(_db);
		_db = nullptr;
		_fileName = "";
	}
}

Value Object_db::Exec(Signal &sig, const char *sql, Argument &arg)
{
	if (_db == nullptr) {
		SetError_NotOpened(sig);
		return Value::Nil;
	}
	char *errMsg;
	Value result;
	ResultComposer resultComposer(*this, arg, result);
	CallbackInfo callbackInfo(*this, resultComposer);
	int rc = ::sqlite3_exec(_db, sql, Callback, &callbackInfo, &errMsg); 
	if (rc == SQLITE_OK) return result;
	if (sig.IsSignalled()) return Value::Nil;
	sig.SetError(ERR_RuntimeError, "sqlite3 %s", errMsg);
	return Value::Nil;
}

bool Object_db::ExecNoResult(Signal &sig, const char *sql)
{
	if (_db == nullptr) {
		SetError_NotOpened(sig);
		return false;
	}
	char *errMsg;
	int rc = ::sqlite3_exec(_db, sql, nullptr, nullptr, &errMsg); 
	if (rc != SQLITE_OK) {
		sig.SetError(ERR_RuntimeError, "sqlite3 %s", errMsg);
		return false;
	}
	return true;
}

Object_db::IteratorQuery *Object_db::Query(Signal &sig, const char *sql)
{
	if (_db == nullptr) {
		SetError_NotOpened(sig);
		return nullptr;
	}
	sqlite3_stmt *pStmt;
	const char *pzTail;
	int rc = ::sqlite3_prepare(_db, sql, -1, &pStmt, &pzTail);
	if (rc != SQLITE_OK) {
		sig.SetError(ERR_RuntimeError, "sqlite3 %s", ::sqlite3_errmsg(_db));
		return nullptr;
	}
	return new IteratorQuery(Object_db::Reference(this), pStmt);
}

Value Object_db::GetColumnNames(Signal &sig, const char *sql)
{
	Environment &env = *this;
	if (_db == nullptr) {
		SetError_NotOpened(sig);
		return Value::Nil;
	}
	sqlite3_stmt *pStmt;
	const char *pzTail;
	int rc = ::sqlite3_prepare(_db, sql, -1, &pStmt, &pzTail);
	if (rc != SQLITE_OK) {
		sig.SetError(ERR_RuntimeError, "sqlite3 %s", ::sqlite3_errmsg(_db));
		return Value::Nil;
	}
	Value result;
	ValueList &valList = result.InitAsList(env);
	int nCols = ::sqlite3_column_count(pStmt);
	for (int iCol = 0; iCol < nCols; iCol++) {
		valList.push_back(Value(::sqlite3_column_name(pStmt, iCol)));
	}
	::sqlite3_finalize(pStmt);
	return result;
}

String Object_db::ToString(bool exprFlag)
{
	String str;
	str += "<sqlite3.db:";
	str += _fileName;
	str += ">";
	return str;
}

int Object_db::Callback(void *user, int argc, char **argv, char **azColName)
{
	CallbackInfo *pCallbackInfo = reinterpret_cast<CallbackInfo *>(user);
	Environment &env = pCallbackInfo->GetEnv();
	ResultComposer &resultComposer = pCallbackInfo->GetResultComposer();
	Value value;
	ValueList &valList = value.InitAsList(env);
	for (int i = 0; i < argc; i++) {
		valList.push_back(Value(argv[i]));
	}
	return resultComposer.Store(env, value)? SQLITE_OK : SQLITE_ERROR;
}

void Object_db::SetError_NotOpened(Signal &sig)
{
	sig.SetError(ERR_RuntimeError, "database not opened");
}

//-----------------------------------------------------------------------------
// Object_db::IteratorQuery
//-----------------------------------------------------------------------------
Object_db::IteratorQuery::~IteratorQuery()
{
	::sqlite3_finalize(_pStmt);
}

Iterator *Object_db::IteratorQuery::GetSource()
{
	return nullptr;
}

bool Object_db::IteratorQuery::DoNext(Environment &env, Value &value)
{
	Signal &sig = env.GetSignal();
	if (::sqlite3_step(_pStmt) != SQLITE_ROW) {
		return false;
	}
	ValueList &valList = value.InitAsList(env);
	int nCols = ::sqlite3_column_count(_pStmt);
	for (int iCol = 0; iCol < nCols; iCol++) {
		int type = ::sqlite3_column_type(_pStmt, iCol);
		if (type == SQLITE_INTEGER) {
			valList.push_back(Value(static_cast<Number>(::sqlite3_column_int(_pStmt, iCol))));
		} else if (type == SQLITE_FLOAT) {
			valList.push_back(Value(static_cast<Number>(::sqlite3_column_double(_pStmt, iCol))));
		} else if (type == SQLITE_TEXT) {
			valList.push_back(Value(
				reinterpret_cast<const char *>(::sqlite3_column_text(_pStmt, iCol))));
		} else if (type == SQLITE_BLOB) {
			//::sqlite3_column_blob(_pStmt, iCol);
			valList.push_back(Value::Nil);
		} else if (type == SQLITE_NULL) {
			valList.push_back(Value::Nil);
		} else {
			sig.SetError(ERR_RuntimeError, "somthing's wrong in sqlite3");
			return false;
		}
	}
	return true;
}

String Object_db::IteratorQuery::ToString() const
{
	return String("<iterator:sqlite3.db.query>");
}

void Object_db::IteratorQuery::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

//-----------------------------------------------------------------------------
// Gura interfaces for sqlite3.db
//-----------------------------------------------------------------------------
// sqlite3.db#close()
Gura_DeclareMethod(db, close)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Shuts down the connection with an sqlite3 server.");
}

Gura_ImplementMethod(db, close)
{
	Object_db *pObj = Object_db::GetObjectThis(arg);
	pObj->Close();
	return Value::Nil;
}

// sqlite3.db#exec(sql:string):map
Gura_DeclareMethod(db, exec)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "sql", VTYPE_string);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown, 
		"Executes an SQL statement and returns the result as a list.");
}

Gura_ImplementMethod(db, exec)
{
	Signal &sig = env.GetSignal();
	Object_db *pObj = Object_db::GetObjectThis(arg);
	return pObj->Exec(sig, arg.GetString(0), arg);
}

// sqlite3.db#getcolnames(sql:string):map
Gura_DeclareMethod(db, getcolnames)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "sql", VTYPE_string);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown, 
		"");
}

Gura_ImplementMethod(db, getcolnames)
{
	Signal &sig = env.GetSignal();
	Object_db *pObj = Object_db::GetObjectThis(arg);
	return pObj->GetColumnNames(sig, arg.GetString(0));
}

// sqlite3.db#query(sql:string):map {block?}
Gura_DeclareMethod(db, query)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "sql", VTYPE_string);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown, 
		"Executes an SQL statement and returns the result as an iterator.\n"
		"You should use `sqlite3.db#query()` instead of `sqlite3.db#exec()`\n"
		"when it's likely that you get a large size of data as the result.\n");
}

Gura_ImplementMethod(db, query)
{
	Signal &sig = env.GetSignal();
	Object_db *pObj = Object_db::GetObjectThis(arg);
	Iterator *pIterator = pObj->Query(sig, arg.GetString(0));
	if (sig.IsSignalled()) return Value::Nil;
	return ReturnIterator(env, arg, pIterator);
}

// sqlite3.db#transaction() {block}
Gura_DeclareMethod(db, transaction)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_Once);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown, 
		"Executes the block within a transaction. The process is like following:\n"
		"\n"
		"1. Executes a sqlit3 command 'BEGIN TRANSACTION'\n"
		"2. Executes code in the block\n"
		"3. Executes a sqlite3 command 'END TRANSACTION'");
}

Gura_ImplementMethod(db, transaction)
{
	Signal &sig = env.GetSignal();
	Object_db *pObj = Object_db::GetObjectThis(arg);
	const Function *pFuncBlock =
						arg.GetBlockFunc(env, GetSymbolForBlock());
	if (sig.IsSignalled()) return Value::Nil;
	if (!pObj->ExecNoResult(sig, "BEGIN TRANSACTION")) return Value::Nil;
	AutoPtr<Environment> pEnvBlock(new Environment(&env, ENVTYPE_block));
	AutoPtr<Argument> pArgSub(new Argument(pFuncBlock));
	Value result = pFuncBlock->Eval(*pEnvBlock, *pArgSub);
	// "END TRANSACTION" has the same effect as "COMMIT"
	if (!pObj->ExecNoResult(sig, "END TRANSACTION")) return Value::Nil;
	return result;
}

// assignment
Gura_ImplementUserClass(db)
{
	Gura_AssignMethod(db, close);
	Gura_AssignMethod(db, exec);
	Gura_AssignMethod(db, getcolnames);
	Gura_AssignMethod(db, query);
	Gura_AssignMethod(db, transaction);
}

//-----------------------------------------------------------------------------
// Module functions: sqlite3
//-----------------------------------------------------------------------------
// db = sqlite3.db(filename:string) {block?}
Gura_DeclareFunction(db)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "filename", VTYPE_string);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(Gura_UserClass(db));
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown, 
		"Opens an sqlite3 database file.\n"
		"If block is not specified, it returns a connection handle with an sqlite3 server.\n"
		"If block is specified, it executes the program in the block with a connection\n"
		"handle as a block parameter, and returns the result afterwards. The connection\n"
		"handle will automatically closed when the block finishes.\n"
		"\n"
		"Block parameter format: `|db:sqlite3|`");
}

Gura_ImplementFunction(db)
{
	Signal &sig = env.GetSignal();
	AutoPtr<Object_db> pObj(new Object_db(env));
	if (!pObj->Open(sig, arg.GetString(0))) return Value::Nil;
	return ReturnValue(env, arg, Value(pObj.release()));
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
	Gura_RealizeAndPrepareUserClass(db, env.LookupClass(VTYPE_object));
	// function assignment
	Gura_AssignFunction(db);
	return true;
}

Gura_ModuleTerminate()
{
}

Gura_EndModuleBody(sqlite3, sqlite3)

Gura_RegisterModule(sqlite3)
