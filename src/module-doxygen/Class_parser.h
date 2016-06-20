//=============================================================================
// Class_parser.h
//=============================================================================
#ifndef __GURA_DOXYGEN_CLASS_PARSER_H__
#define __GURA_DOXYGEN_CLASS_PARSER_H__

Gura_BeginModuleScope(doxygen)

//-----------------------------------------------------------------------------
// doxygen.parser class
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(parser);

class Object_parser : public Object {
public:
	Gura_DeclareObjectAccessor(parser)
private:
	Parser _parser;
public:
	inline Object_parser(Class *pClass) : Object(pClass), _parser(this) {}
	virtual ~Object_parser();
	virtual Object *Clone() const;
	virtual bool DoDirProp(Environment &env, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(bool exprFlag);
	inline Parser &GetParser() { return _parser; }
};

Gura_EndModuleScope(doxygen)

#endif
