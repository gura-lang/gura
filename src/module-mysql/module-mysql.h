//-----------------------------------------------------------------------------
// Gura module: mysql
//-----------------------------------------------------------------------------
#ifndef __GURA_MODULE_MYSQL_H__
#define __GURA_MODULE_MYSQL_H__
#include <gura.h>
#include <mysql.h>

Gura_BeginModuleHeader(mysql)

//-----------------------------------------------------------------------------
// Object_mysql
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(mysql);

class Object_mysql : public Object {
public:
	class IteratorQuery : public Iterator {
	private:
		Object_mysql *_pObj;
		MYSQL_RES *_pRes;
	public:
		inline IteratorQuery(Object_mysql *pObj, MYSQL_RES *pRes) :
								Iterator(false), _pObj(pObj), _pRes(pRes) {}
		virtual ~IteratorQuery();
		virtual bool DoNext(Environment &env, Value &value);
		virtual String ToString() const;
	};
private:
	MYSQL _mysql;
public:
	Gura_DeclareObjectAccessor(mysql)
public:
	Object_mysql();
	virtual ~Object_mysql();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	bool Connect(Signal &sig, const char *host, const char *user, const char *passwd,
		const char *db, unsigned int port, const char *unix_socket, unsigned long client_flag);
	void Close();
	Iterator *Query(Signal &sig, const char *stmt_str);
};

Gura_EndModuleHeader(mysql)

#endif
