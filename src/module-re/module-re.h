//-----------------------------------------------------------------------------
// Gura module: re
//-----------------------------------------------------------------------------
#ifndef __GURA_MODULE_RE_H__
#define __GURA_MODULE_RE_H__

#include <gura.h>
#include <oniguruma.h>

Gura_BeginModuleHeader(re)

Gura_DeclareUserSymbol(re);
Gura_DeclareUserSymbol(string);
Gura_DeclareUserSymbol(multiline);

//-----------------------------------------------------------------------------
// Utilities
//-----------------------------------------------------------------------------
regex_t *CreateRegEx(Signal &sig, const char *pattern, const SymbolSet &attrs);
Value DoMatch(Environment &env, Signal &sig, regex_t *pRegEx,
							const char *str, int pos, int posEnd);
String DoSubWithString(Environment &env, Signal &sig, regex_t *pRegEx,
							const char *replace, const char *str, int cnt);
String DoSubWithFunc(Environment &env, Signal &sig, regex_t *pRegEx,
							const Function *pFunc, const char *str, int cnt);
void SetError_OnigurumaError(Signal &sig, int rtn);
void SetError_FailInOniguruma(Signal &sig);

//-----------------------------------------------------------------------------
// Group
//-----------------------------------------------------------------------------
class Group {
private:
	AutoPtr<StringRef> _pStrRef;
	int _posBegin, _posEnd;
public:
	inline Group(StringRef *pStrRef, int posBegin, int posEnd) :
				_pStrRef(pStrRef), _posBegin(posBegin), _posEnd(posEnd) {}
	inline Group(const Group &group) : _pStrRef(group._pStrRef->Reference()),
				_posBegin(group._posBegin), _posEnd(group._posEnd) {}
	inline void operator=(const Group &group) {
		_pStrRef.reset(group._pStrRef->Reference()),
		_posBegin = group._posBegin, _posEnd = group._posEnd;
	}
	inline String GetString() const {
		return Middle(_pStrRef->GetString(), _posBegin, GetLength());
	}
	inline int GetPosBegin() const { return _posBegin; }
	inline int GetPosEnd() const { return _posEnd; }
	inline int GetLength() const { return _posEnd - _posBegin; }
};

typedef std::vector<Group> GroupList;

//-----------------------------------------------------------------------------
// Class declaration for re.group
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(group);

class Object_group : public Object {
public:
	Gura_DeclareObjectAccessor(group)
private:
	Group _group;
public:
	inline Object_group(const Group &group) : Object(Gura_UserClass(group)), _group(group) {}
	inline Object_group(const Object_group &obj) : Object(obj), _group(obj._group) {}
	virtual ~Object_group();
	virtual Object *Clone() const;
	virtual bool DoDirProp(Environment &env, Signal &__to_delete__, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal &__to_delete__, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(bool exprFlag);
};

//-----------------------------------------------------------------------------
// Class declaration for re.match
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(match);

class Object_match : public Object {
public:
	typedef std::map<String, size_t> GroupNameDict;
public:
	Gura_DeclareObjectAccessor(match)
private:
	AutoPtr<StringRef> _pStrRef;
	GroupList _groupList;
	GroupNameDict _groupNameDict;
public:
	inline Object_match() : Object(Gura_UserClass(match)) {}
	inline Object_match(const Object_match &obj) : Object(obj),
			_pStrRef(obj._pStrRef->Reference()), _groupList(obj._groupList) {}
	virtual ~Object_match();
	virtual Object *Clone() const;
	virtual Value IndexGet(Environment &env, Signal &__to_delete__, const Value &valueIdx);
	virtual bool DoDirProp(Environment &env, Signal &__to_delete__, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal &__to_delete__, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(bool exprFlag);
	bool SetMatchInfo(const char *str, regex_t *pRegEx,
								const OnigRegion *pRegion, int posOffset);
	inline const char *GetString() const { return _pStrRef->GetString(); }
	const Group *GetGroup(Signal &sig, const Value &index) const;
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
	inline Object_pattern() : Object(Gura_UserClass(pattern)), _pRegEx(nullptr) {}
	virtual ~Object_pattern();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline bool SetPattern(Signal &sig, const char *pattern, const SymbolSet &attrs) {
		_pattern = pattern;
		_pRegEx = CreateRegEx(sig, pattern, attrs);
		return _pRegEx != nullptr;
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
	virtual bool DoNext(Environment &env, Signal &sig, Value &value);
	virtual String ToString() const;
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
	virtual bool DoNext(Environment &env, Signal &sig, Value &value);
	virtual String ToString() const;
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
	virtual bool DoNext(Environment &env, Signal &sig, Value &value);
	virtual String ToString() const;
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
};

//-----------------------------------------------------------------------------
// IteratorGroup class declaration
//-----------------------------------------------------------------------------
class IteratorGroup : public Iterator {
private:
	AutoPtr<Object_match> _pObjMatch;
	size_t _iGroup;
public:
	IteratorGroup(Object_match *pObjMatch);
	virtual Iterator *GetSource();
	virtual bool DoNext(Environment &env, Signal &sig, Value &value);
	virtual String ToString() const;
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
};

Gura_EndModuleHeader(re)

#endif
