//-----------------------------------------------------------------------------
// Gura module: mysql
//-----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleBody(mysql)

//-----------------------------------------------------------------------------
// Object_mysql
//-----------------------------------------------------------------------------
Object_mysql::Object_mysql() : Object(Gura_UserClass(mysql))
{
	::mysql_init(&_mysql);
}

Object_mysql::~Object_mysql()
{
	Close();
}

Object *Object_mysql::Clone() const
{
	return nullptr;
}

String Object_mysql::ToString(bool exprFlag)
{
	String str;
	str += "<mysql";
	str += ">";
	return str;
}

bool Object_mysql::Connect(Signal &sig, const char *host, const char *user, const char *passwd,
	const char *db, unsigned int port, const char *unix_socket, unsigned long client_flag)
{
	if (::mysql_real_connect(&_mysql, host, user, passwd,
								db, port, unix_socket, client_flag) == nullptr) {
		sig.SetError(ERR_RuntimeError, "MySQL %s\n", ::mysql_error(&_mysql));
		return false;
	}
	return true;
}

void Object_mysql::Close()
{
	::mysql_close(&_mysql);
}

Iterator *Object_mysql::Query(Signal &sig, const char *stmt_str)
{
	if (::mysql_query(&_mysql, stmt_str) != 0) {
		sig.SetError(ERR_RuntimeError, "MySQL %s\n", ::mysql_error(&_mysql));
		return nullptr;
	}
	MYSQL_RES *pRes = ::mysql_store_result(&_mysql);
	if (pRes != nullptr) {
		return new IteratorQuery(Object_mysql::Reference(this), pRes);
	} else if (::mysql_field_count(&_mysql) == 0) {
		return nullptr; // no error, but returns nullptr
	} else {
		sig.SetError(ERR_RuntimeError, "MySQL %s\n", ::mysql_error(&_mysql));
		return nullptr;
	}
}

//-----------------------------------------------------------------------------
// Object_mysql::IteratorQuery
//-----------------------------------------------------------------------------
Object_mysql::IteratorQuery::~IteratorQuery()
{
	Object::Delete(_pObj);
	::mysql_free_result(_pRes);
}

bool Object_mysql::IteratorQuery::DoNext(Environment &env, Signal &sig, Value &value)
{
	//Environment &env = *_pObj;
	unsigned int nFields = ::mysql_num_fields(_pRes);
	MYSQL_ROW row = ::mysql_fetch_row(_pRes);
	if (row == nullptr) return false;
	ValueList &valList = value.InitAsList(env);
	
	for (unsigned int i = 0; i < nFields; i++) {
		valList.push_back(Value(env, row[i]));
	}
	
	return true;
}

String Object_mysql::IteratorQuery::ToString() const
{
	return String("<iterator:MySQL#query>");
}

//-----------------------------------------------------------------------------
// Gura interfaces for Object_mysql
//-----------------------------------------------------------------------------
// mysql.mysql#close()
Gura_DeclareMethod(mysql, close)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Shuts down the connection with an MySQL server.");
}

Gura_ImplementMethod(mysql, close)
{
	Object_mysql *pObj = Object_mysql::GetThisObj(args);
	pObj->Close();
	return Value::Null;
}

// mysql.mysql#query(stmt:string)
Gura_DeclareMethod(mysql, query)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "stmt", VTYPE_string);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementMethod(mysql, query)
{
	Object_mysql *pObj = Object_mysql::GetThisObj(args);
	Iterator *pIterator = pObj->Query(sig, args.GetString(0));
	// Object_mysql::Query() may return nullptr even if no error occurs.
	if (pIterator == nullptr) return Value::Null;
	return ReturnIterator(env, sig, args, pIterator);
}

// assignment
Gura_ImplementUserClass(mysql)
{
	Gura_AssignMethod(mysql, query);
}

//-----------------------------------------------------------------------------
// Gura module functions: mysql
//-----------------------------------------------------------------------------
// mysql.connect(host?:string, user?:string, passwd?:string, db?:string) {block?}
Gura_DeclareFunction(connect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "host", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "user", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "passwd", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "db", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(connect)
{
	const char *host = args.Is_string(0)? args.GetString(0) : nullptr;
	const char *user = args.Is_string(1)? args.GetString(1) : nullptr;
	const char *passwd = args.Is_string(2)? args.GetString(2) : nullptr;
	const char *db = args.Is_string(3)? args.GetString(3) : nullptr;
	unsigned int port = 0;
	const char *unix_socket = nullptr;
	unsigned long client_flag = 0;
	Object_mysql *pObj = new Object_mysql();
	if (!pObj->Connect(sig, host, user, passwd, db, port, unix_socket, client_flag)) {
		delete pObj;
		return Value::Null;
	}
	Value result(pObj);
	if (args.IsBlockSpecified()) {
		const Function *pFuncBlock =
						args.GetBlockFunc(env, sig, GetSymbolForBlock());
		if (pFuncBlock == nullptr) return Value::Null;
		ValueList valListArg(result);
		Args argsSub(valListArg);
		pFuncBlock->Eval(env, sig, argsSub);
		result = Value::Null; // object is destroyed here
	}
	return result;
}

// mysql.test()
Gura_DeclareFunction(test)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(test)
{
	MYSQL mysql;
	::mysql_init(&mysql);
	::mysql_real_connect(&mysql, nullptr, "user", "password", "dbname", 0, nullptr, 0);
	if (::mysql_error(&mysql) != 0) {
		::printf("%s\n", ::mysql_error(&mysql));
		return Value::Null;
	}
	::mysql_query(&mysql, "select * from people");
	if (::mysql_error(&mysql) != 0) {
		::printf("%s\n", ::mysql_error(&mysql));
		return Value::Null;
	}
	MYSQL_RES *results = ::mysql_store_result(&mysql);
	MYSQL_ROW row;
	while ((row = ::mysql_fetch_row(results)) != nullptr) {
		::printf("%s\n", row[0]);
	}
	::mysql_free_result(results);
	::mysql_close(&mysql);
	::mysql_server_end();
	return Value::Null;
}

// Module entry
Gura_ModuleEntry()
{
	// class realization
	Gura_RealizeAndPrepareUserClass(mysql, env.LookupClass(VTYPE_object));
	// function assignment
	Gura_AssignFunction(connect);
	Gura_AssignFunction(test);
	return true;
}

Gura_ModuleTerminate()
{
	::mysql_server_end();
}

Gura_EndModuleBody(mysql, mysql)

Gura_RegisterModule(mysql)
