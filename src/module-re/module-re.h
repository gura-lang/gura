#ifndef __MODULE_RE_H__
#define __MODULE_RE_H__

#include <gura.h>
#include <oniguruma.h>

Gura_BeginModule(re)

Gura_DeclareUserSymbol(re);
Gura_DeclareUserSymbol(string);
Gura_DeclareUserSymbol(multiline);

//-----------------------------------------------------------------------------
// Utilities
//-----------------------------------------------------------------------------
regex_t *CreateRegEx(Signal sig, const char *pattern, const SymbolSet &attrs);
Value DoMatch(Environment &env, Signal sig, regex_t *pRegEx,
							const char *str, int pos, int posEnd);
String DoSubWithString(Environment &env, Signal sig, regex_t *pRegEx,
							const char *replace, const char *str, int cnt);
String DoSubWithFunc(Environment &env, Signal sig, regex_t *pRegEx,
							const Function *pFunc, const char *str, int cnt);
void SetError_OnigurumaError(Signal sig, int rtn);
void SetError_FailInOniguruma(Signal sig);

//-----------------------------------------------------------------------------
// Class declaration for re.match
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(match);

class Object_match : public Object {
public:
	class Group {
	private:
		int _posBegin, _posEnd;
	public:
		inline Group(int posBegin, int posEnd) :
						_posBegin(posBegin), _posEnd(posEnd) {}
		inline Group(const Group &group) :
						_posBegin(group._posBegin), _posEnd(group._posEnd) {}
		inline void operator=(const Group &group) {
			_posBegin = group._posBegin, _posEnd = group._posEnd;
		}
		inline int GetPosBegin() const { return _posBegin; }
		inline int GetPosEnd() const { return _posEnd; }
		inline int GetLength() const { return _posEnd - _posBegin; }
	};
	typedef std::vector<Group> GroupList;
	typedef std::map<String, size_t> GroupNameDict;
public:
	Gura_DeclareObjectAccessor(match)
private:
	String _str;
	GroupList _groupList;
	GroupNameDict _groupNameDict;
public:
	inline Object_match(Environment &env) : Object(Gura_UserClass(match)) {}
	inline Object_match(const Object_match &obj) : Object(obj),
							_str(obj._str), _groupList(obj._groupList) {}
	virtual ~Object_match();
	virtual Object *Clone() const;
	virtual Value IndexGet(Environment &env, Signal sig, const Value &valueIdx);
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(Signal sig, bool exprFlag);
	bool SetMatchInfo(const char *str, regex_t *pRegEx,
								const OnigRegion *pRegion, int posOffset);
	inline String GetGroupString(const Group &group) const {
		return Middle(_str.c_str(), group.GetPosBegin(), group.GetLength());
	}
	const Group *GetGroup(Signal sig, const Value &index) const;
	const GroupList &GetGroupList() const { return _groupList; }
private:
	int ForeachNameCallback(const String &name, int nGroups,
											int *idxGroupTbl, regex_t *pRegEx);
	static int ForeachNameCallbackStub(
				const UChar *nameRaw, const UChar *nameRawEnd,
				int nGroups, int *idxGroupTbl, regex_t *pRegEx, void *pArg);
};

//-----------------------------------------------------------------------------
// Class declaration for re.pattern
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(pattern);

class Object_pattern : public Object {
private:
	String _pattern;
	regex_t *_pRegEx;
public:
	Gura_DeclareObjectAccessor(pattern)
public:
	inline Object_pattern(Environment &env) :
						Object(Gura_UserClass(pattern)), _pRegEx(NULL) {}
	virtual ~Object_pattern();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline bool SetPattern(Signal sig, const char *pattern, const SymbolSet &attrs) {
		_pattern = pattern;
		_pRegEx = CreateRegEx(sig, pattern, attrs);
		return _pRegEx != NULL;
	}
	inline regex_t *GetRegEx() { return _pRegEx; }
};

//-----------------------------------------------------------------------------
// IteratorSplit class declaration
//-----------------------------------------------------------------------------
class IteratorSplit : public Iterator {
private:
	AutoPtr<Object_pattern> _pObjPattern;
	String _str;
	int _cnt;
	int _idx;
	int _len;
	bool _doneFlag;
	OnigRegion *_pRegion;
public:
	IteratorSplit(Object_pattern *pObjPattern, const String &str, int cntMax);
	virtual ~IteratorSplit();
	virtual Iterator *GetSource();
	virtual bool DoNext(Environment &env, Signal sig, Value &value);
	virtual String ToString(Signal sig) const;
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
};

//-----------------------------------------------------------------------------
// IteratorScan class declaration
//-----------------------------------------------------------------------------
class IteratorScan : public Iterator {
private:
	AutoPtr<Object_pattern> _pObjPattern;
	String _str;
	int _idx, _idxEnd;
	int _len;
	OnigRegion *_pRegion;
public:
	IteratorScan(Object_pattern *pObjPattern, const String &str, int pos, int posEnd);
	virtual ~IteratorScan();
	virtual Iterator *GetSource();
	virtual bool DoNext(Environment &env, Signal sig, Value &value);
	virtual String ToString(Signal sig) const;
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
};

//-----------------------------------------------------------------------------
// IteratorGrep class declaration
//-----------------------------------------------------------------------------
class IteratorGrep : public Iterator {
private:
	AutoPtr<Iterator> _pIteratorSrc;
	AutoPtr<Object_pattern> _pObjPattern;
public:
	IteratorGrep(Iterator *pIteratorSrc, Object_pattern *pObjPattern);
	virtual Iterator *GetSource();
	virtual bool DoNext(Environment &env, Signal sig, Value &value);
	virtual String ToString(Signal sig) const;
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
};

}}

#endif
