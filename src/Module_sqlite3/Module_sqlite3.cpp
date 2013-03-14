//-----------------------------------------------------------------------------
// Gura sqlite3 module
//-----------------------------------------------------------------------------
#include "Module_sqlite3.h"

Gura_BeginModule(sqlite3)

//-----------------------------------------------------------------------------
// Object_db
//-----------------------------------------------------------------------------
Object_db::~Object_db()
{
	Close();
}

Object *Object_db::Clone() const
{
	return NULL;
}

bool Object_db::Open(Signal sig, const char *fileName)
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
	if (_db != NULL) {
		::sqlite3_close(_db);
		_db = NULL;
		_fileName = "";
	}
}

Value Object_db::Exec(Signal sig, const char *sql, Args &args)
{
	if (_db == NULL) {
		SetError_NotOpened(sig);
		return Value::Null;
	}
	char *errMsg;
	Value result;
	Function::ResultComposer resultComposer(*this, args, result);
	int rc = ::sqlite3_exec(_db, sql, Callback, &resultComposer, &errMsg); 
	if (rc != SQLITE_OK) {
		sig.SetError(ERR_RuntimeError, "sqlite3 %s", errMsg);
		return Value::Null;
	}
	return result;
}

bool Object_db::ExecNoResult(Signal sig, const char *sql)
{
	if (_db == NULL) {
		SetError_NotOpened(sig);
		return false;
	}
	char *errMsg;
	int rc = ::sqlite3_exec(_db, sql, NULL, NULL, &errMsg); 
	if (rc != SQLITE_OK) {
		sig.SetError(ERR_RuntimeError, "sqlite3 %s", errMsg);
		return false;
	}
	return true;
}

Object_db::IteratorQuery *Object_db::Query(Signal sig, const char *sql)
{
	if (_db == NULL) {
		SetError_NotOpened(sig);
		return NULL;
	}
	sqlite3_stmt *pStmt;
	const char *pzTail;
	int rc = ::sqlite3_prepare(_db, sql, -1, &pStmt, &pzTail);
	if (rc != SQLITE_OK) {
		sig.SetError(ERR_RuntimeError, "sqlite3 %s", ::sqlite3_errmsg(_db));
		return NULL;
	}
	return new IteratorQuery(Object_db::Reference(this), pStmt);
}

Value Object_db::GetColumnNames(Signal sig, const char *sql)
{
	Environment &env = *this;
	if (_db == NULL) {
		SetError_NotOpened(sig);
		return Value::Null;
	}
	sqlite3_stmt *pStmt;
	const char *pzTail;
	int rc = ::sqlite3_prepare(_db, sql, -1, &pStmt, &pzTail);
	if (rc != SQLITE_OK) {
		sig.SetError(ERR_RuntimeError, "sqlite3 %s", ::sqlite3_errmsg(_db));
		return Value::Null;
	}
	Value result;
	ValueList &valList = result.InitAsList(env);
	int nCols = ::sqlite3_column_count(pStmt);
	for (int iCol = 0; iCol < nCols; iCol++) {
		valList.push_back(Value(env, ::sqlite3_column_name(pStmt, iCol)));
	}
	::sqlite3_finalize(pStmt);
	return result;
}

String Object_db::ToString(Signal sig, bool exprFlag)
{
	String str;
	str += "<sqlite3.db:";
	str += _fileName;
	str += ">";
	return str;
}

int Object_db::Callback(void *user, int argc, char **argv, char **azColName)
{
	Function::ResultComposer *pResultComposer =
						reinterpret_cast<Function::ResultComposer *>(user);
	Environment &env = pResultComposer->GetEnv();
	Value value;
	ValueList &valList = value.InitAsList(env);
	for (int i = 0; i < argc; i++) {
		valList.push_back(Value(env, argv[i]));
	}
	pResultComposer->Store(value);
	return SQLITE_OK;
}

void Object_db::SetError_NotOpened(Signal sig)
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
	return NULL;
}

bool Object_db::IteratorQuery::DoNext(Environment &env, Signal sig, Value &value)
{
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
			valList.push_back(Value(env,
				reinterpret_cast<const char *>(::sqlite3_column_text(_pStmt, iCol))));
		} else if (type == SQLITE_BLOB) {
			//::sqlite3_column_blob(_pStmt, iCol);
			valList.push_back(Value::Null);
		} else if (type == SQLITE_NULL) {
			valList.push_back(Value::Null);
		} else {
			sig.SetError(ERR_RuntimeError, "somthing's wrong in sqlite3");
			return false;
		}
	}
	return true;
}

String Object_db::IteratorQuery::ToString(Signal sig) const
{
	return String("<iterator:sqlite3.db.query>");
}

void Object_db::IteratorQuery::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

//-----------------------------------------------------------------------------
// Gura interfaces for sqlite3.db
//-----------------------------------------------------------------------------
// sqlite3.db#exec(sql:string):map
Gura_DeclareMethod(db, exec)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "sql", VTYPE_string);
	AddHelp(Gura_Symbol(en), 
	"Executes an SQL statement and returns the result as a list.");
}

Gura_ImplementMethod(db, exec)
{
	Object_db *pObj = Object_db::GetThisObj(args);
	return pObj->Exec(sig, args.GetString(0), args);
}

// sqlite3.db#query(sql:string):map {block?}
Gura_DeclareMethod(db, query)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "sql", VTYPE_string);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), 
	"Executes an SQL statement and returns the result as an iterator.\n"
	"You should use query() instead of exec() when it's likely that you get a large\n"
	"size of data as the result\n");
}

Gura_ImplementMethod(db, query)
{
	Object_db *pObj = Object_db::GetThisObj(args);
	Iterator *pIterator = pObj->Query(sig, args.GetString(0));
	if (sig.IsSignalled()) return Value::Null;
	return ReturnIterator(env, sig, args, pIterator);
}

// sqlite3.db#getcolnames(sql:string):map
Gura_DeclareMethod(db, getcolnames)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "sql", VTYPE_string);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(db, getcolnames)
{
	Object_db *pObj = Object_db::GetThisObj(args);
	return pObj->GetColumnNames(sig, args.GetString(0));
}

// sqlite3.db#transaction() {block}
Gura_DeclareMethod(db, transaction)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_Once);
	AddHelp(Gura_Symbol(en), 
	"Executes the block within a transaction. The process is like follows:\n"
	"1.Executes a sqlit3 command 'BEGIN TRANSACTION'\n"
	"2.Executes code in the block\n"
	"3.Executes a sqlite3 command 'END TRANSACTION'");
}

Gura_ImplementMethod(db, transaction)
{
	Object_db *pObj = Object_db::GetThisObj(args);
	const Function *pFuncBlock =
						args.GetBlockFunc(env, sig, GetSymbolForBlock());
	if (sig.IsSignalled()) return Value::Null;
	if (!pObj->ExecNoResult(sig, "BEGIN TRANSACTION")) return Value::Null;
	Environment envBlock(&env, ENVTYPE_block);
	Args argsSub(ValueList::Null);
	Value result = pFuncBlock->Eval(envBlock, sig, argsSub);
	// "END TRANSACTION" has the same effect as "COMMIT"
	if (!pObj->ExecNoResult(sig, "END TRANSACTION")) return Value::Null;
	return result;
}

// sqlite3.db#close()
Gura_DeclareMethod(db, close)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), "Shuts down the connection with an sqlite3 server.");
}

Gura_ImplementMethod(db, close)
{
	Object_db *pObj = Object_db::GetThisObj(args);
	pObj->Close();
	return Value::Null;
}

// assignment
Gura_ImplementUserClass(db)
{
	Gura_AssignMethod(db, exec);
	Gura_AssignMethod(db, query);
	Gura_AssignMethod(db, getcolnames);
	Gura_AssignMethod(db, transaction);
	Gura_AssignMethod(db, close);
}

//-----------------------------------------------------------------------------
// Module functions: sqlite3
//-----------------------------------------------------------------------------
// db = sqlite3.db(filename:string) {block?}
Gura_DeclareFunction(db)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "filename", VTYPE_string);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(Gura_UserClass(db));
	AddHelp(Gura_Symbol(en), 
	"Opens an sqlite3 database file.\n"
	"If block is not specified, it returns a connection handle with an sqlite3 server.\n"
	"If block is specified, it executes the program in the block with a connection\n"
	"handle as a block parameter, and returns the result afterwards. The connection\n"
	"handle will automatically closed when the block finishes\n"
	"Block parameter format: |sql:sqlite3|");
}

Gura_ImplementFunction(db)
{
	AutoPtr<Object_db> pObj(new Object_db(env));
	if (!pObj->Open(sig, args.GetString(0))) return Value::Null;
	return ReturnValue(env, sig, args, Value(pObj.release()));
}

// Module entry
Gura_ModuleEntry()
{
	// class realization
	Gura_RealizeUserClass(db, env.LookupClass(VTYPE_object));
	// function assignment
	Gura_AssignFunction(db);
}

Gura_ModuleTerminate()
{
}

Gura_EndModule(sqlite3, sqlite3)

Gura_RegisterModule(sqlite3)
