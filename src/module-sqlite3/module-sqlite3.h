//-----------------------------------------------------------------------------
// Gura module: sqlite3
//-----------------------------------------------------------------------------
#ifndef __GURA_MODULE_SQLITE3_H__
#define __GURA_MODULE_SQLITE3_H__
#include <gura.h>
extern "C" {
#include <sqlite3.h>
}

Gura_BeginModuleHeader(sqlite3)

//-----------------------------------------------------------------------------
// Object_db
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(db);

class Object_db : public Object {
public:
	class IteratorQuery : public Iterator {
	private:
		AutoPtr<Object_db> _pObj;
		sqlite3_stmt *_pStmt;
	public:
		inline IteratorQuery(Object_db *pObj, sqlite3_stmt *pStmt) :
							Iterator(false), _pObj(pObj), _pStmt(pStmt) {}
		virtual ~IteratorQuery();
		virtual Iterator *GetSource();
		virtual bool DoNext(Environment &env, Signal sig, Value &value);
		virtual String ToString() const;
		virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
	};
private:
	sqlite3 *_db;
	String _fileName;
public:
	Gura_DeclareObjectAccessor(db)
public:
	inline Object_db(Environment &env) :
							Object(Gura_UserClass(db)), _db(nullptr) {}
	virtual ~Object_db();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	bool Open(Signal sig, const char *fileName);
	void Close();
	Value Exec(Signal sig, const char *sql, Args &args);
	bool ExecNoResult(Signal sig, const char *sql);
	IteratorQuery *Query(Signal sig, const char *sql);
	Value GetColumnNames(Signal sig, const char *sql);
public:
	void SetError_NotOpened(Signal sig);
private:
	static int Callback(void *user, int argc, char **argv, char **azColName);
};

//-----------------------------------------------------------------------------
// ResultComposerEx
//-----------------------------------------------------------------------------
class ResultComposerEx : public Function::ResultComposer {
private:
	Environment &_env;
	Signal &_sig;
public:
	inline ResultComposerEx(Environment &env, Signal &sig, Args &args, Value &result) :
					ResultComposer(env, args, result), _env(env), _sig(sig) {}
	inline Environment &GetEnv() { return _env; }
	inline Signal &GetSignal() { return _sig; }
};

Gura_EndModuleHeader(sqlite3)

#endif
