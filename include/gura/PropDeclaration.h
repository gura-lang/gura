//=============================================================================
// PropDeclaration
//=============================================================================
#ifndef __GURA_PROPDECLARATION_H__
#define __GURA_PROPDECLARATION_H__

#include "Value.h"

#define Gura_DeclarePropertyAlias_R(className, propName, propNameAlias) \
class PropDeclaration_##className##__##propName : public PropDeclaration { \
public: \
	PropDeclaration_##className##__##propName(const String &classFullName); \
	virtual Value DoGetProp(Environment &env, const Value &valueThis, const SymbolSet &attrs) const; \
	virtual Value DoSetProp(Environment &env, const Value &valueThis, const SymbolSet &attrs, const Value &value) const; \
}; \
Value PropDeclaration_##className##__##propName::DoSetProp(Environment &env, const Value &valueThis, const SymbolSet &attrs, const Value &value) const { return Value::Nil; } \
PropDeclaration_##className##__##propName::PropDeclaration_##className##__##propName(const String &classFullName) : \
						PropDeclaration(classFullName, Symbol::Add(propNameAlias), FLAG_Read)

#define Gura_DeclarePropertyAlias_RW(className, propName, propNameAlias) \
class PropDeclaration_##className##__##propName : public PropDeclaration { \
public: \
	PropDeclaration_##className##__##propName(const String &classFullName); \
	virtual Value DoGetProp(Environment &env, const Value &valueThis, const SymbolSet &attrs) const; \
	virtual Value DoSetProp(Environment &env, const Value &valueThis, const SymbolSet &attrs, const Value &value) const; \
}; \
PropDeclaration_##className##__##propName::PropDeclaration_##className##__##propName(const String &classFullName) : \
						PropDeclaration(classFullName, Symbol::Add(propNameAlias), FLAG_Read | FLAG_Write)

#define Gura_DeclareProperty_R(className, propName) \
Gura_DeclarePropertyAlias_R(className, propName, #propName)

#define Gura_DeclareProperty_RW(className, propName) \
Gura_DeclarePropertyAlias_RW(className, propName, #propName)

#define Gura_ImplementPropertyGetter(className, propName) \
Value PropDeclaration_##className##__##propName::DoGetProp(Environment &env, const Value &valueThis, const SymbolSet &attrs) const

#define Gura_ImplementPropertySetter(className, propName) \
Value PropDeclaration_##className##__##propName::DoSetProp(Environment &env, const Value &valueThis, const SymbolSet &attrs, const Value &value) const

#define Gura_AssignProperty(className, propName) \
AssignPropDeclaration(new PropDeclaration_##className##__##propName(MakeValueTypeName()))

namespace Gura {

//-----------------------------------------------------------------------------
// PropDeclaration
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE PropDeclaration : public HelpProvider::Holder {
protected:
	int _cntRef;
	String _classFullName;
	const Symbol *_pSymbol;
	ValueType _valType;
	ULong _flags;
	AutoPtr<HelpProvider> _pHelpProvider;
public:
	Gura_DeclareReferenceAccessor(PropDeclaration);
public:
	PropDeclaration(const String &classFullName, const Symbol *pSymbol, ULong flags);
protected:
	virtual ~PropDeclaration();
public:
	virtual Value GetProp(Environment &env, const Value &valueThis, const SymbolSet &attrs) const;
	virtual Value SetProp(Environment &env, const Value &valueThis, const SymbolSet &attrs, Value &value) const;
protected:
	virtual Value DoGetProp(Environment &env, const Value &valueThis, const SymbolSet &attrs) const = 0;
	virtual Value DoSetProp(Environment &env, const Value &valueThis, const SymbolSet &attrs, const Value &value) const = 0;
public:
	inline void SetPropAttr(ValueType valType, ULong flags = FLAG_None) {
		_valType = valType, _flags |= flags;
	}
	inline const char *GetClassFullName() const { return _classFullName.c_str(); }
	inline const Symbol *GetSymbol() const { return _pSymbol; }
	inline const char *GetName() const { return _pSymbol->GetName(); }
	inline ValueType GetValueType() const { return _valType; }
	inline ULong GetFlags() const { return _flags; }
	inline bool IsReadable() const { return (_flags & FLAG_Read) != 0; }
	inline bool IsWritable() const { return (_flags & FLAG_Write) != 0; }
	inline HelpProvider &GetHelpProvider() { return *_pHelpProvider; }
	inline const HelpProvider &GetHelpProvider() const { return *_pHelpProvider; }
	inline void AddHelp(const Symbol *pSymbol, const String &doc) {
		_pHelpProvider->AddHelp(pSymbol, doc);
	}
	inline void AddHelpTemplate(Environment &env, const Symbol *pSymbol, const String &doc) {
		_pHelpProvider->AddHelpTemplate(env, pSymbol, doc);
	}
	inline String ToString() const {
		return Declaration::ToString(_pSymbol, _valType, OCCUR_Once, _flags, 0, nullptr);
	}
	String MakeFullName() const;
public:
	// inherited from HelpProvider
	virtual String MakeHelpTitle() const;
};

//-----------------------------------------------------------------------------
// PropDeclarationMap
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE PropDeclarationMap :
	public std::unordered_map<const Symbol *, PropDeclaration *, Symbol::Hasher, Symbol::EqualTo> {
public:
	inline PropDeclarationMap() {}
	PropDeclarationMap(const PropDeclarationMap &propDeclarationMap);
	~PropDeclarationMap();
	void operator=(const PropDeclarationMap &propDeclarationMap);
};

//-----------------------------------------------------------------------------
// PropDeclarationList
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE PropDeclarationList : public std::vector<PropDeclaration *> {
public:
	class Comparator {
	public:
		inline bool operator()(const PropDeclaration *pPropDeclaration1,
							   const PropDeclaration *pPropDeclaration2) const {
			return ::strcmp(pPropDeclaration1->GetName(), pPropDeclaration2->GetName()) < 0;
		}
	};
public:
	void SortByName();
};

//-----------------------------------------------------------------------------
// PropDeclarationOwner
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE PropDeclarationOwner : public PropDeclarationList {
public:
	~PropDeclarationOwner();
	void Clear();
};

}

#endif
