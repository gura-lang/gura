#ifndef __GURA_OBJECT_URI_H__
#define __GURA_OBJECT_URI_H__

#include "Object.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Class_uri / Object_uri
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_uri : public Class {
public:
	Class_uri(Environment *pEnvOuter);
	virtual bool CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl);
	virtual Object *CreateDescendant(Environment &env, Signal sig, Class *pClass);
	static void DoAssignConstructor(Environment &env, Signal sig);
};

class GURA_DLLDECLARE Object_uri : public Object {
public:
	Gura_DeclareObjectAccessor(uri)
private:
	bool _userValidFlag;
	String _scheme;
	String _user;
	String _password;
	String _host;
	String _port;
	String _urlpath;
	String _misc;
public:
	inline Object_uri(Class *pClass) :
					Object(pClass), _userValidFlag(false) {}
	inline Object_uri(Environment &env) :
					Object(env.LookupClass(VTYPE_uri)), _userValidFlag(false) {}
	Object_uri(const Object_uri &obj);
	virtual ~Object_uri();
	virtual Object *Clone() const;
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value DoSetProp(Environment &env, Signal sig, const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(Signal sig, bool exprFlag);
	bool Parse(Signal sig, const char *str);
	inline bool IsUserValid() const { return _userValidFlag; }
	inline const char *GetScheme() const { return _scheme.c_str(); }
	inline const char *GetUser() const { return _user.c_str(); }
	inline const char *GetPassword() const { return _password.c_str(); }
	inline const char *GetHost() const { return _host.c_str(); }
	inline const char *GetPort() const { return _port.c_str(); }
	inline const char *GetUrlPath() const { return _urlpath.c_str(); }
	inline void SetScheme(const char *str) { _scheme = str; }
	inline void SetUser(const char *str) { _user = str, _userValidFlag = true; }
	inline void SetPassword(const char *str) { _password = str; }
	inline void SetHost(const char *str) { _host = str; }
	inline void SetPort(const char *str) { _port = str; }
	inline void SetUrlPath(const char *str) { _urlpath = str; }
	void SetError_InvalidURIFormat(Signal sig);
};

}

#endif
