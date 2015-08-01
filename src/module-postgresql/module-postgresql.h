//-----------------------------------------------------------------------------
// Gura module: postgresql
//-----------------------------------------------------------------------------
#ifndef __GURA_MODULE_POSTGRESQL_H__
#define __GURA_MODULE_POSTGRESQL_H__
#include <gura.h>
#include <libpq-fe.h>

Gura_BeginModuleHeader(postgresql)

//-----------------------------------------------------------------------------
// Object_postgresql
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(postgresql);

class Object_postgresql : public Object {
public:
	class IteratorTuple : public Iterator {
	private:
		Object_postgresql *_pObj;
		PGresult *_res;
		int _iTuple;
	public:
		inline IteratorTuple(Object_postgresql *pObj, PGresult *res) :
						Iterator(false), _pObj(pObj), _res(res), _iTuple(0) {}
		virtual ~IteratorTuple();
		virtual bool DoNext(Environment &env, Value &value);
		virtual String ToString() const;
	};
private:
    PGconn *_conn;
public:
	Gura_DeclareObjectAccessor(postgresql)
public:
	Object_postgresql();
	virtual ~Object_postgresql();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	bool Connect(Signal &sig, const char *pghost, const char *pgport,
		const char *pgoptions, const char *pgtty, const char *dbName, const char *login, const char *pwd);
	void Close();
	Iterator *Exec(Signal &sig, const char *command);
};

Gura_EndModuleHeader(postgresql)

#endif
