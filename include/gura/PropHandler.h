//=============================================================================
// PropHandler
//=============================================================================
#ifndef __GURA_PROPHANDLER_H__
#define __GURA_PROPHANDLER_H__

#include "Value.h"

#define Gura_DeclarePropertyAlias_R(className, propName, propNameAlias) \
class PropHandler_##className##__##propName : public PropHandler { \
public: \
	PropHandler_##className##__##propName(); \
	virtual Value DoGetProp(const Value &valueThis, const SymbolSet &attrs) const; \
}; \
PropHandler_##className##__##propName::PropHandler_##className##__##propName() : \
							PropHandler(Symbol::Add(propNameAlias), FLAG_Read)

#define Gura_DeclareProperty_R(className, propName) \
Gura_DeclarePropertyAlias_R(className, propName, #propName)

#define Gura_ImplementPropertyGetter(className, propName) \
Value PropHandler_##className##__##propName::DoGetProp(const Value &valueThis, const SymbolSet &attrs) const

#define Gura_AssignProperty(className, propName) \
AssignPropHandler(new PropHandler_##className##__##propName())

namespace Gura {

//-----------------------------------------------------------------------------
// PropHandler
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE PropHandler : public HelpProvider::Holder {
protected:
	const Symbol *_pSymbol;
	ULong _flags;
	AutoPtr<HelpProvider> _pHelpProvider;
public:
	PropHandler(const Symbol *pSymbol, ULong flags);
	inline const Symbol *GetSymbol() { return _pSymbol; }
	inline const char *GetName() { return _pSymbol->GetName(); }
	virtual ~PropHandler();
	virtual Value DoGetProp(const Value &valueThis, const SymbolSet &attrs) const;
	virtual Value DoSetProp(const Value &valueThis, const Value &value, const SymbolSet &attrs) const;
public:
	inline HelpProvider &GetHelpProvider() { return *_pHelpProvider; }
	inline const HelpProvider &GetHelpProvider() const { return *_pHelpProvider; }
	inline void AddHelp(const Symbol *pSymbol, const String &doc) {
		_pHelpProvider->AddHelp(pSymbol, doc);
	}
	inline void AddHelpTemplate(Environment &env, const Symbol *pSymbol, const String &doc) {
		_pHelpProvider->AddHelpTemplate(env, pSymbol, doc);
	}
public:
	// inherited from HelpProvider
	virtual String MakeHelpTitle() const;
};

//-----------------------------------------------------------------------------
// PropHandlerMap
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE PropHandlerMap :
	public std::unordered_map <const Symbol *, PropHandler *, Symbol::Hasher, Symbol::EqualTo> {
public:
	inline PropHandlerMap() {}
	~PropHandlerMap();
};

}

#endif
