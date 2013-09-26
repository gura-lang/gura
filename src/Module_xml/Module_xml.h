//-----------------------------------------------------------------------------
// Gura xml module
//-----------------------------------------------------------------------------
#ifndef __MODULE_XML_H__
#define __MODULE_XML_H__
#include <gura.h>
#include <expat.h>

Gura_BeginModule(xml)

Gura_DeclareUserSymbol(name);
Gura_DeclareUserSymbol(value);
Gura_DeclareUserSymbol(tagname);
Gura_DeclareUserSymbol(text);
Gura_DeclareUserSymbol(comment);
Gura_DeclareUserSymbol(children);
Gura_DeclareUserSymbol(attrs);

Gura_DeclareUserSymbol(StartElement);
Gura_DeclareUserSymbol(EndElement);
Gura_DeclareUserSymbol(CharacterData);
Gura_DeclareUserSymbol(ProcessingInstruction);
Gura_DeclareUserSymbol(Comment);
Gura_DeclareUserSymbol(StartCdataSection);
Gura_DeclareUserSymbol(EndCdataSection);
Gura_DeclareUserSymbol(Default);
Gura_DeclareUserSymbol(DefaultExpand);
Gura_DeclareUserSymbol(ExternalEntityRef);
Gura_DeclareUserSymbol(SkippedEntity);
Gura_DeclareUserSymbol(StartNamespaceDecl);
Gura_DeclareUserSymbol(EndNamespaceDecl);
Gura_DeclareUserSymbol(XmlDecl);
Gura_DeclareUserSymbol(StartDoctypeDecl);
Gura_DeclareUserSymbol(EndDoctypeDecl);
Gura_DeclareUserSymbol(ElementDecl);
Gura_DeclareUserSymbol(AttlistDecl);
Gura_DeclareUserSymbol(EntityDecl);
Gura_DeclareUserSymbol(NotationDecl);
Gura_DeclareUserSymbol(NotStandalone);

//-----------------------------------------------------------------------------
// Parser
//-----------------------------------------------------------------------------
class Parser {
private:
	XML_Parser _parser;
public:
	Parser();
	virtual ~Parser();
	void Parse(Signal sig, Stream &stream);
	inline void StopParser() { ::XML_StopParser(_parser, XML_FALSE); }
private:
	static void XMLCALL StartElementHandler(void *userData, const XML_Char *name, const XML_Char **atts);
	static void XMLCALL EndElementHandler(void *userData, const XML_Char *name);
	static void XMLCALL CharacterDataHandler(void *userData, const XML_Char *s, int len);
	static void XMLCALL ProcessingInstructionHandler(void *userData, const XML_Char *target, const XML_Char *data);
	static void XMLCALL CommentHandler(void *userData, const XML_Char *data);
	static void XMLCALL StartCdataSectionHandler(void *userData);
	static void XMLCALL EndCdataSectionHandler(void *userData);
	static void XMLCALL DefaultHandler(void *userData, const XML_Char *s, int len);
	static void XMLCALL DefaultHandlerExpand(void *userData, const XML_Char *s, int len);
	static int  XMLCALL ExternalEntityRefHandler(XML_Parser p, const XML_Char *args, const XML_Char *base, const XML_Char *systemId, const XML_Char *publicId);
	static void XMLCALL SkippedEntityHandler(void *userData, const XML_Char *entityName, int isParameterEntity);
	static int  XMLCALL UnknownEncodingHandler(void *encodingHandlerData, const XML_Char *name, XML_Encoding *info);
	static void XMLCALL StartNamespaceDeclHandler(void *userData, const XML_Char *prefix, const XML_Char *uri);
	static void XMLCALL EndNamespaceDeclHandler(void *userData, const XML_Char *prefix);
	static void XMLCALL XmlDeclHandler(void *userData, const XML_Char *version, const XML_Char *encoding, int standalone);
	static void XMLCALL StartDoctypeDeclHandler(void *userData, const XML_Char *doctypeName, const XML_Char *systemId, const XML_Char *publicId, int hasInternalSubset);
	static void XMLCALL EndDoctypeDeclHandler(void *userData);
	static void XMLCALL ElementDeclHandler(void *userData, const XML_Char *name, XML_Content *model);
	static void XMLCALL AttlistDeclHandler(void *userData, const XML_Char *elname, const XML_Char *attname, const XML_Char *attType, const XML_Char *dflt, int isRequired);
	static void XMLCALL EntityDeclHandler(void *userData, const XML_Char *entityName, int isParameterEntity, const XML_Char *value, int valueLength, const XML_Char *base, const XML_Char *systemId, const XML_Char *publicId, const XML_Char *notationName);
	static void XMLCALL NotationDeclHandler(void *userData, const XML_Char *notationName, const XML_Char *base, const XML_Char *systemId, const XML_Char *publicId);
	static int  XMLCALL NotStandaloneHandler(void *userData);
	static int Convert_shift_jis(void *data, const char *s);
	static int Convert_euc_jp(void *data, const char *s);
	virtual void OnStartElement(const XML_Char *name, const XML_Char **atts) = 0;
	virtual void OnEndElement(const XML_Char *name) = 0;
	virtual void OnCharacterData(const XML_Char *s, int len) = 0;
	virtual void OnProcessingInstruction(const XML_Char *target, const XML_Char *data) = 0;
	virtual void OnComment(const XML_Char *data) = 0;
	virtual void OnStartCdataSection() = 0;
	virtual void OnEndCdataSection() = 0;
	virtual void OnDefault(const XML_Char *s, int len) = 0;
	virtual void OnDefaultExpand(const XML_Char *s, int len) = 0;
	virtual int  OnExternalEntityRef(XML_Parser p, const XML_Char *args, const XML_Char *base, const XML_Char *systemId, const XML_Char *publicId) = 0;
	virtual void OnSkippedEntity(const XML_Char *entityName, int isParameterEntity) = 0;
	virtual void OnStartNamespaceDecl(const XML_Char *prefix, const XML_Char *uri) = 0;
	virtual void OnEndNamespaceDecl(const XML_Char *prefix) = 0;
	virtual void OnXmlDecl(const XML_Char *version, const XML_Char *encoding, int standalone) = 0;
	virtual void OnStartDoctypeDecl(const XML_Char *doctypeName, const XML_Char *systemId, const XML_Char *publicId, int hasInternalSubset) = 0;
	virtual void OnEndDoctypeDecl() = 0;
	virtual void OnElementDecl(const XML_Char *name, XML_Content *model) = 0;
	virtual void OnAttlistDecl(const XML_Char *elname, const XML_Char *attname, const XML_Char *attType, const XML_Char *dflt, int isRequired) = 0;
	virtual void OnEntityDecl(const XML_Char *entityName, int isParameterEntity, const XML_Char *value, int valueLength, const XML_Char *base, const XML_Char *systemId, const XML_Char *publicId, const XML_Char *notationName) = 0;
	virtual void OnNotationDecl(const XML_Char *notationName, const XML_Char *base, const XML_Char *systemId, const XML_Char *publicId) = 0;
	virtual int  OnNotStandalone() = 0;
};

class ElementOwner;

//-----------------------------------------------------------------------------
// Attribute
//-----------------------------------------------------------------------------
class Attribute {
private:
	String _name;
	String _value;
private:
	int _cntRef;
public:
	Gura_DeclareReferenceAccessor(Attribute);
public:
	Attribute(const String &name, const String &value);
private:
	inline ~Attribute() {}
public:
	inline const char *GetName() const { return _name.c_str(); }
	inline const char *GetValue() const { return _value.c_str(); }
};

//-----------------------------------------------------------------------------
// AttributeList
//-----------------------------------------------------------------------------
class AttributeList : public std::vector<Attribute *> {
public:
	const Attribute *FindByName(const char *name) const;
};

//-----------------------------------------------------------------------------
// AttributeOwner
//-----------------------------------------------------------------------------
class AttributeOwner : public AttributeList {
private:
	int _cntRef;
public:
	Gura_DeclareReferenceAccessor(AttributeOwner);
public:
	inline AttributeOwner() : _cntRef(1) {}
private:
	~AttributeOwner();
public:
	void Clear();
};

//-----------------------------------------------------------------------------
// Element
//-----------------------------------------------------------------------------
class Element {
public:
	enum Type {
		TYPE_None,
		TYPE_Tag,
		TYPE_Text,
		TYPE_Comment,
	};
private:
	int _cntRef;
	Type _type;
	String _str;
	AutoPtr<AttributeOwner> _pAttributes;
	AutoPtr<ElementOwner> _pChildren;
public:
	Gura_DeclareReferenceAccessor(Element);
public:
	Element(Type type, const String &str, const char **atts = NULL);
	bool Format(Signal sig, Stream &stream, int indentLevel) const;
	String GatherText() const;
	void AddChild(Element *pChild);
	bool AddChild(Environment &env, Signal sig, const Value &value);
	inline bool IsTag() const { return _type == TYPE_Tag; }
	inline bool IsText() const { return _type == TYPE_Text; }
	inline bool IsComment() const { return _type == TYPE_Comment; }
	inline const char *GetTagName() const { return _str.c_str(); }
	inline const char *GetText() const { return _str.c_str(); }
	inline const char *GetComment() const { return _str.c_str(); }
	inline AttributeOwner *GetAttributes() { return _pAttributes.get(); }
	inline const AttributeOwner *GetAttributes() const { return _pAttributes.get(); }
	inline void SetChildren(ElementOwner *pChildren) { _pChildren.reset(pChildren); }
	inline ElementOwner *GetChildren() { return _pChildren.get(); }
	inline const ElementOwner *GetChildren() const { return _pChildren.get(); }
private:
	inline ~Element() {}
};

//-----------------------------------------------------------------------------
// ElementList
//-----------------------------------------------------------------------------
class ElementList : public std::vector<Element *> {
};

//-----------------------------------------------------------------------------
// ElementOwner
//-----------------------------------------------------------------------------
class ElementOwner : public ElementList {
private:
	int _cntRef;
public:
	Gura_DeclareReferenceAccessor(ElementOwner);
public:
	inline ElementOwner() : _cntRef(1) {}
private:
	~ElementOwner();
public:
	void Clear();
};

#if 0
//-----------------------------------------------------------------------------
// Document
//-----------------------------------------------------------------------------
class Document {
private:
	int _cntRef;
	AutoPtr<Element> _pRoot;
public:
	Gura_DeclareReferencerAccessor(Document);
public:
	Document();
private:
	inline ~Document() {}
public:
	
};
#endif

//-----------------------------------------------------------------------------
// Document
//-----------------------------------------------------------------------------
class Document : public Parser {
private:
	typedef std::vector<Element *> Stack;
private:
	Stack _stack;
	AutoPtr<Element> _pElementRoot;
public:
	Document();
	Element *Parse(Signal &sig, Stream &stream);
private:
	virtual void OnStartElement(const XML_Char *name, const XML_Char **atts);
	virtual void OnEndElement(const XML_Char *name);
	virtual void OnCharacterData(const XML_Char *s, int len);
	virtual void OnProcessingInstruction(const XML_Char *target, const XML_Char *data);
	virtual void OnComment(const XML_Char *data);
	virtual void OnStartCdataSection();
	virtual void OnEndCdataSection();
	virtual void OnDefault(const XML_Char *s, int len);
	virtual void OnDefaultExpand(const XML_Char *s, int len);
	virtual int  OnExternalEntityRef(XML_Parser p, const XML_Char *args, const XML_Char *base, const XML_Char *systemId, const XML_Char *publicId);
	virtual void OnSkippedEntity(const XML_Char *entityName, int isParameterEntity);
	virtual void OnStartNamespaceDecl(const XML_Char *prefix, const XML_Char *uri);
	virtual void OnEndNamespaceDecl(const XML_Char *prefix);
	virtual void OnXmlDecl(const XML_Char *version, const XML_Char *encoding, int standalone);
	virtual void OnStartDoctypeDecl(const XML_Char *doctypeName, const XML_Char *systemId, const XML_Char *publicId, int hasInternalSubset);
	virtual void OnEndDoctypeDecl();
	virtual void OnElementDecl(const XML_Char *name, XML_Content *model);
	virtual void OnAttlistDecl(const XML_Char *elname, const XML_Char *attname, const XML_Char *attType, const XML_Char *dflt, int isRequired);
	virtual void OnEntityDecl(const XML_Char *entityName, int isParameterEntity, const XML_Char *value, int valueLength, const XML_Char *base, const XML_Char *systemId, const XML_Char *publicId, const XML_Char *notationName);
	virtual void OnNotationDecl(const XML_Char *notationName, const XML_Char *base, const XML_Char *systemId, const XML_Char *publicId);
	virtual int  OnNotStandalone();
};

//-----------------------------------------------------------------------------
// Object_parser
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(parser);

class Object_parser : public Object {
public:
	class ParserEx : public Parser {
	private:
		Object_parser *_pObj;
	public:
		inline ParserEx(Object_parser *pObj) : _pObj(pObj) {}
	private:
		virtual void OnStartElement(const XML_Char *name, const XML_Char **atts);
		virtual void OnEndElement(const XML_Char *name);
		virtual void OnCharacterData(const XML_Char *s, int len);
		virtual void OnProcessingInstruction(const XML_Char *target, const XML_Char *data);
		virtual void OnComment(const XML_Char *data);
		virtual void OnStartCdataSection();
		virtual void OnEndCdataSection();
		virtual void OnDefault(const XML_Char *s, int len);
		virtual void OnDefaultExpand(const XML_Char *s, int len);
		virtual int  OnExternalEntityRef(XML_Parser p, const XML_Char *args, const XML_Char *base, const XML_Char *systemId, const XML_Char *publicId);
		virtual void OnSkippedEntity(const XML_Char *entityName, int isParameterEntity);
		virtual void OnStartNamespaceDecl(const XML_Char *prefix, const XML_Char *uri);
		virtual void OnEndNamespaceDecl(const XML_Char *prefix);
		virtual void OnXmlDecl(const XML_Char *version, const XML_Char *encoding, int standalone);
		virtual void OnStartDoctypeDecl(const XML_Char *doctypeName, const XML_Char *systemId, const XML_Char *publicId, int hasInternalSubset);
		virtual void OnEndDoctypeDecl();
		virtual void OnElementDecl(const XML_Char *name, XML_Content *model);
		virtual void OnAttlistDecl(const XML_Char *elname, const XML_Char *attname, const XML_Char *attType, const XML_Char *dflt, int isRequired);
		virtual void OnEntityDecl(const XML_Char *entityName, int isParameterEntity, const XML_Char *value, int valueLength, const XML_Char *base, const XML_Char *systemId, const XML_Char *publicId, const XML_Char *notationName);
		virtual void OnNotationDecl(const XML_Char *notationName, const XML_Char *base, const XML_Char *systemId, const XML_Char *publicId);
		virtual int  OnNotStandalone();
	};
private:
	ParserEx _parser;
	Signal *_pSig;
public:
	Gura_DeclareObjectAccessor(parser)
public:
	Object_parser(Class *pClass);
	void Parse(Environment &env, Signal &sig, Stream &stream);
	void CallHandler(const Symbol *pSymbol, const ValueList argList);
};

//-----------------------------------------------------------------------------
// Object_attribute
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(attribute);

class Object_attribute : public Object {
private:
	AutoPtr<Attribute> _pAttribute;
public:
	Gura_DeclareObjectAccessor(attribute)
public:
	Object_attribute(Attribute *pAttribute);
	inline Attribute *GetAttribute() { return _pAttribute.get(); }
	inline const Attribute *GetAttribute() const { return _pAttribute.get(); }
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(Signal sig, bool exprFlag);
};

//-----------------------------------------------------------------------------
// Object_element
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(element);

class Object_element : public Object {
private:
	AutoPtr<Element> _pElement;
public:
	Gura_DeclareObjectAccessor(element)
public:
	Object_element(Element *pElement);
	inline Element *GetElement() { return _pElement.get(); }
	inline const Element *GetElement() const { return _pElement.get(); }
	virtual Value IndexGet(Environment &env, Signal sig, const Value &valueIdx);
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(Signal sig, bool exprFlag);
};

//-----------------------------------------------------------------------------
// Iterator_attribute
//-----------------------------------------------------------------------------
class Iterator_attribute : public Iterator {
private:
	size_t _idxAttribute;
	AutoPtr<AttributeOwner> _pAttributeOwner;
public:
	Iterator_attribute(AttributeOwner *pAttributeOwner);
	virtual Iterator *GetSource();
	virtual bool DoNext(Environment &env, Signal sig, Value &value);
	virtual String ToString(Signal sig) const;
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
};

//-----------------------------------------------------------------------------
// Iterator_element
//-----------------------------------------------------------------------------
class Iterator_element : public Iterator {
private:
	size_t _idxElement;
	AutoPtr<ElementOwner> _pElementOwner;
public:
	Iterator_element(ElementOwner *pElementOwner);
	virtual Iterator *GetSource();
	virtual bool DoNext(Environment &env, Signal sig, Value &value);
	virtual String ToString(Signal sig) const;
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
};

}}

#endif
