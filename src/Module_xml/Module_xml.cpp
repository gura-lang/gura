//-----------------------------------------------------------------------------
// Gura xml module
//-----------------------------------------------------------------------------
#include "Module_xml.h"

Gura_BeginModule(xml)

//-----------------------------------------------------------------------------
// Parser
//-----------------------------------------------------------------------------
Parser::Parser()
{
	_parser = ::XML_ParserCreate(NULL);
	::XML_SetUserData(_parser, this);
	::XML_SetStartElementHandler(_parser,			StartElementHandler);
	::XML_SetEndElementHandler(_parser,				EndElementHandler);
	::XML_SetCharacterDataHandler(_parser,			CharacterDataHandler);
	::XML_SetProcessingInstructionHandler(_parser,	ProcessingInstructionHandler);
	::XML_SetCommentHandler(_parser,				CommentHandler);
	::XML_SetStartCdataSectionHandler(_parser,		StartCdataSectionHandler);
	::XML_SetEndCdataSectionHandler(_parser,		EndCdataSectionHandler);
	::XML_SetDefaultHandler(_parser,				DefaultHandler);
	::XML_SetDefaultHandlerExpand(_parser,			DefaultHandlerExpand);
	::XML_SetExternalEntityRefHandler(_parser,		ExternalEntityRefHandler);
	::XML_SetSkippedEntityHandler(_parser,			SkippedEntityHandler);
	::XML_SetUnknownEncodingHandler(_parser,		UnknownEncodingHandler, this);
	::XML_SetStartNamespaceDeclHandler(_parser,		StartNamespaceDeclHandler);
	::XML_SetEndNamespaceDeclHandler(_parser,		EndNamespaceDeclHandler);
	::XML_SetXmlDeclHandler(_parser,				XmlDeclHandler);
	::XML_SetStartDoctypeDeclHandler(_parser,		StartDoctypeDeclHandler);
	::XML_SetEndDoctypeDeclHandler(_parser,			EndDoctypeDeclHandler);
	::XML_SetElementDeclHandler(_parser,			ElementDeclHandler);
	::XML_SetAttlistDeclHandler(_parser,			AttlistDeclHandler);
	::XML_SetEntityDeclHandler(_parser,				EntityDeclHandler);
	::XML_SetNotationDeclHandler(_parser,			NotationDeclHandler);
	::XML_SetNotStandaloneHandler(_parser,			NotStandaloneHandler);
}

Parser::~Parser()
{
	::XML_ParserFree(_parser);
}

void Parser::Parse(Signal sig, Stream &stream)
{
	const size_t bytesToRead = 1024 * 8;
	for (;;) {
		char *buff = reinterpret_cast<char *>(::XML_GetBuffer(_parser, bytesToRead));
		int bytes = static_cast<int>(stream.Read(sig, buff, bytesToRead));
		if (sig.IsSignalled()) break;
		int doneFlag = (bytes < bytesToRead);
		XML_Status status = ::XML_Parse(_parser, buff, bytes, doneFlag);
		if (sig.IsSignalled()) {
			break;
		} else if (status == XML_STATUS_ERROR) {
			sig.SetError(ERR_IOError, "expat: %s at line %lu\n",
					::XML_ErrorString(XML_GetErrorCode(_parser)),
					::XML_GetCurrentLineNumber(_parser));
			break;
		} else if (status != XML_STATUS_OK) {
			break;
		}
		if (doneFlag) break;
	}
}

void Parser::StartElementHandler(void *userData,
								const XML_Char *name, const XML_Char **atts)
{
	// <name attr0="value0" attr1="value1" attr2="value">
	Parser *pParser = reinterpret_cast<Parser *>(userData);
	pParser->OnStartElement(name, atts);
}

void Parser::EndElementHandler(void *userData, const XML_Char *name)
{
	// </name>
	Parser *pParser = reinterpret_cast<Parser *>(userData);
	pParser->OnEndElement(name);
}

void XMLCALL Parser::CharacterDataHandler(void *userData,
												const XML_Char *text, int len)
{
	// text
	Parser *pParser = reinterpret_cast<Parser *>(userData);
	pParser->OnCharacterData(text, len);
}

void XMLCALL Parser::ProcessingInstructionHandler(void *userData,
									const XML_Char *target, const XML_Char *data)
{
	// <?target data>
	Parser *pParser = reinterpret_cast<Parser *>(userData);
	pParser->OnProcessingInstruction(target, data);
}

void XMLCALL Parser::CommentHandler(void *userData, const XML_Char *data)
{
	// <--data-->
	Parser *pParser = reinterpret_cast<Parser *>(userData);
	pParser->OnComment(data);
}

void XMLCALL Parser::StartCdataSectionHandler(void *userData)
{
	// <![CDATA[
	Parser *pParser = reinterpret_cast<Parser *>(userData);
	pParser->OnStartCdataSection();
}

void XMLCALL Parser::EndCdataSectionHandler(void *userData)
{
	// ]]>
	Parser *pParser = reinterpret_cast<Parser *>(userData);
	pParser->OnEndCdataSection();
}

void XMLCALL Parser::DefaultHandler(void *userData,
											const XML_Char *text, int len)
{
	Parser *pParser = reinterpret_cast<Parser *>(userData);
	pParser->OnDefault(text, len);
}

void XMLCALL Parser::DefaultHandlerExpand(void *userData,
											const XML_Char *text, int len)
{
	Parser *pParser = reinterpret_cast<Parser *>(userData);
	pParser->OnDefaultExpand(text, len);
}

int XMLCALL Parser::ExternalEntityRefHandler(XML_Parser parser,
							const XML_Char *args, const XML_Char *base,
							const XML_Char *systemId, const XML_Char *publicId)
{
	// <!ENTITY>
	//Parser *pParser = reinterpret_cast<Parser *>(userData);
	//pParser->OnExternalEntityRef(args, base, systemId, publicId);
	return 0;
}

void XMLCALL Parser::SkippedEntityHandler(void *userData,
							const XML_Char *entityName, int isParameterEntity)
{
}

int XMLCALL Parser::UnknownEncodingHandler(void *encodingHandlerData,
							const XML_Char *name, XML_Encoding *info)
{
	for (int i = 0; i < ArraySizeOf(info->map); i++) info->map[i] = -1;
	if (::strcasecmp(name, "shift_jis") == 0) {
		for (int i = 0; i <= 0x7f; i++) info->map[i] = i;
		for (int i = 0x81; i <= 0x9f; i++) info->map[i] = -2;
		for (int i = 0xe0; i <= 0xee; i++) info->map[i] = -2;
		for (int i = 0xfa; i <= 0xfc; i++) info->map[i] = -2;
		info->data = NULL;
		info->convert = Convert_shift_jis;
		info->release = NULL;
		return XML_STATUS_OK;
	} else if (::strcasecmp(name, "euc-jp") == 0) {
		for (int i = 0; i <= 0x7f; i++) info->map[i] = i;
		for (int i = 0x81; i <= 0xff; i++) info->map[i] = -2;
		info->data = NULL;
		info->convert = Convert_euc_jp;
		info->release = NULL;
		return XML_STATUS_OK;
	}
	return XML_STATUS_ERROR;
}

void XMLCALL Parser::StartNamespaceDeclHandler(void *userData,
							const XML_Char *prefix, const XML_Char *uri)
{
	// <tag xmlns:prefix="uri">
	Parser *pParser = reinterpret_cast<Parser *>(userData);
	pParser->OnStartNamespaceDecl(prefix, uri);
}

void XMLCALL Parser::EndNamespaceDeclHandler(void *userData,
													const XML_Char *prefix)
{
	Parser *pParser = reinterpret_cast<Parser *>(userData);
	pParser->OnEndNamespaceDecl(prefix);
}

void XMLCALL Parser::XmlDeclHandler(void *userData,
				const XML_Char *version, const XML_Char *encoding, int standalone)
{
	// <?xml version="version" encoding="encoding" standalone="yes|no"?>
	Parser *pParser = reinterpret_cast<Parser *>(userData);
	pParser->OnXmlDecl(version, encoding, standalone);
}

void XMLCALL Parser::StartDoctypeDeclHandler(void *userData,
				const XML_Char *doctypeName, const XML_Char *systemId,
				const XML_Char *publicId, int hasInternalSubset)
{
	// <!DOCTYPE doctypeName systemId "publicId"[
	// declarations
	// ]>
	Parser *pParser = reinterpret_cast<Parser *>(userData);
	pParser->OnStartDoctypeDecl(doctypeName, systemId, publicId, hasInternalSubset);
}

void XMLCALL Parser::EndDoctypeDeclHandler(void *userData)
{
	Parser *pParser = reinterpret_cast<Parser *>(userData);
	pParser->OnEndDoctypeDecl();
}

void XMLCALL Parser::ElementDeclHandler(void *userData,
									const XML_Char *name, XML_Content *model)
{
	// DTD
	Parser *pParser = reinterpret_cast<Parser *>(userData);
	pParser->OnElementDecl(name, model);
}

void XMLCALL Parser::AttlistDeclHandler(void *userData,
			const XML_Char *elemName, const XML_Char *attName,
			const XML_Char *attType, const XML_Char *defaultValue, int isRequired)
{
	// DTD
	Parser *pParser = reinterpret_cast<Parser *>(userData);
	pParser->OnAttlistDecl(elemName, attName, attType, defaultValue, isRequired);
}

void XMLCALL Parser::EntityDeclHandler(void *userData,
			const XML_Char *entityName, int isParameterEntity,
			const XML_Char *value, int valueLength, const XML_Char *base,
			const XML_Char *systemId, const XML_Char *publicId,
			const XML_Char *notationName)
{
	// <!ENTITY>
	Parser *pParser = reinterpret_cast<Parser *>(userData);
	pParser->OnEntityDecl(entityName, isParameterEntity, value, valueLength, base,
										systemId, publicId, notationName);
}

void XMLCALL Parser::NotationDeclHandler(void *userData,
			const XML_Char *notationName, const XML_Char *base,
			const XML_Char *systemId, const XML_Char *publicId)
{
	Parser *pParser = reinterpret_cast<Parser *>(userData);
	pParser->OnNotationDecl(notationName, base, systemId, publicId);
}

int XMLCALL Parser::NotStandaloneHandler(void *userData)
{
	Parser *pParser = reinterpret_cast<Parser *>(userData);
	pParser->OnNotStandalone();
	return 0;
}

int Parser::Convert_shift_jis(void *data, const char *s)
{
	UShort codeCP932 =
		(static_cast<UShort>(static_cast<UChar>(s[0])) << 8) +
		static_cast<UChar>(s[1]);
	UShort codeUTF16 = Codec::CP932ToUTF16(codeCP932);
	return (codeUTF16 == 0)? -1 : codeUTF16;
}

int Parser::Convert_euc_jp(void *data, const char *s)
{
	UShort codeEUCJP =
		(static_cast<UShort>(static_cast<UChar>(s[0])) << 8) +
		static_cast<UChar>(s[1]);
	UShort codeCP932 = Codec::EUCJPToCP932(codeEUCJP);
	UShort codeUTF16 = Codec::CP932ToUTF16(codeCP932);
	return (codeUTF16 == 0)? -1 : codeUTF16;
}

//-----------------------------------------------------------------------------
// Attribute
//-----------------------------------------------------------------------------
Attribute::Attribute(const String &name, const String &value) :
									_cntRef(1), _name(name), _value(value)
{
}

//-----------------------------------------------------------------------------
// AttributeList
//-----------------------------------------------------------------------------
const Attribute *AttributeList::FindByName(const char *name) const
{
	foreach_const (AttributeList, ppAttribute, *this) {
		const Attribute *pAttribute = *ppAttribute;
		if (::strcmp(pAttribute->GetName(), name) == 0) return pAttribute;
	}
	return NULL;
}

//-----------------------------------------------------------------------------
// AttributeOwner
//-----------------------------------------------------------------------------
AttributeOwner::~AttributeOwner()
{
	Clear();
}

void AttributeOwner::Clear()
{
	foreach (AttributeOwner, ppAttribute, *this) {
		Attribute *pAttribute = *ppAttribute;
		Attribute::Delete(pAttribute);
	}
	clear();
}

//-----------------------------------------------------------------------------
// Element
//-----------------------------------------------------------------------------
Element::Element(Type type, const String &str, const char **atts) :
										_cntRef(1), _type(type), _str(str)
{
	if (type == TYPE_Tag) _pAttributes.reset(new AttributeOwner());
	if (atts != NULL) {
		for (const char **p = atts; *p != NULL && *(p + 1) != NULL; p += 2) {
			const char *name = *p, *value = *(p + 1);
			GetAttributes()->push_back(new Attribute(name, value));
		}
	}
}

bool Element::Format(Signal sig, Stream &stream, int indentLevel) const
{
	const char *indentUnit = "  ";
	String indent;
	for (int i = 0; i < indentLevel; i++) indent += indentUnit;
	stream.Print(sig, indent.c_str());
	if (sig.IsSignalled()) return false;
	if (IsTag()) {
		stream.PutChar(sig, '<');
		if (sig.IsSignalled()) return false;
		stream.Print(sig, GetTagName());
		if (sig.IsSignalled()) return false;
		foreach_const (AttributeOwner, ppAttribute, *GetAttributes()) {
			const Attribute *pAttribute = *ppAttribute;
			stream.PutChar(sig, ' ');
			if (sig.IsSignalled()) return false;
			stream.Print(sig, pAttribute->GetName());
			if (sig.IsSignalled()) return false;
			stream.Print(sig, "=\"");
			if (sig.IsSignalled()) return false;
			stream.Print(sig, pAttribute->GetValue());
			if (sig.IsSignalled()) return false;
			stream.PutChar(sig, '"');
			if (sig.IsSignalled()) return false;
		}
		if (GetChildren() == NULL || GetChildren()->empty()) {
			stream.Print(sig, " />\n");
			if (sig.IsSignalled()) return false;
		} else {
			stream.Print(sig, ">\n");
			if (sig.IsSignalled()) return false;
			foreach_const (ElementOwner, ppChild, *GetChildren()) {
				const Element *pChild = *ppChild;
				if (!pChild->Format(sig, stream, indentLevel + 1)) return false;
			}
			stream.Print(sig, indent.c_str());
			if (sig.IsSignalled()) return false;
			stream.Print(sig, "</");
			if (sig.IsSignalled()) return false;
			stream.Print(sig, GetTagName());
			if (sig.IsSignalled()) return false;
			stream.Print(sig, ">\n");
		}
	} else if (IsText()) {
		stream.Print(sig, GetText());
		if (sig.IsSignalled()) return false;
		stream.Print(sig, "\n");
		if (sig.IsSignalled()) return false;
	} else if (IsComment()) {
		stream.Print(sig, "<!--");
		if (sig.IsSignalled()) return false;
		stream.Print(sig, GetComment());
		if (sig.IsSignalled()) return false;
		stream.Print(sig, "-->\n");
		if (sig.IsSignalled()) return false;
	}
	return true;
}

String Element::GatherText() const
{
	if (IsText()) return GetText();
	String str;
	if (GetChildren() != NULL) {
		foreach_const (ElementOwner, ppChild, *GetChildren()) {
			const Element *pChild = *ppChild;
			str += pChild->GatherText();
		}
	}
	return str;
}

void Element::AddChild(Element *pChild)
{
	if (_pChildren.get() == NULL) _pChildren.reset(new ElementOwner());
	_pChildren->push_back(pChild);
}

bool Element::AddChild(Environment &env, Signal sig, const Value &value)
{
	if (value.IsString()) {
		AutoPtr<Element> pChild(new Element(Element::TYPE_Text, value.GetStringSTL()));
		AddChild(pChild.release());
	} else if (value.IsInstanceOf(VTYPE_element)) {
		Object_element *pObj = Object_element::GetObject(value);
		AddChild(pObj->GetElement()->Reference());
	} else if (value.IsListOrIterator()) {
		AutoPtr<Iterator> pIterator(value.CreateIterator(sig));
		if (sig.IsSignalled()) return false;
		if (pIterator->IsInfinite()) {
			Iterator::SetError_InfiniteNotAllowed(sig);
			return false;
		}
		Value valueIter;
		while (pIterator->Next(env, sig, valueIter)) {
			if (!AddChild(env, sig, valueIter)) return false;
		}
		if (sig.IsSignalled()) return false;
	} else {
		sig.SetError(ERR_ValueError, "invalid value type");
		return false;
	}
	return true;
}

//-----------------------------------------------------------------------------
// ElementList
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// ElementOwner
//-----------------------------------------------------------------------------
ElementOwner::~ElementOwner()
{
	Clear();
}

void ElementOwner::Clear()
{
	foreach (ElementOwner, ppElement, *this) {
		Element *pElement = *ppElement;
		Element::Delete(pElement);
	}
	clear();
}

//-----------------------------------------------------------------------------
// Document
//-----------------------------------------------------------------------------
Document::Document() : _cntRef(1)
{
}

Element *Document::Parse(Signal &sig, Stream &stream)
{
	Parser::Parse(sig, stream);
	return _pElementRoot.release();
}

void Document::OnStartElement(const XML_Char *name, const XML_Char **atts)
{
	Element *pElement = new Element(Element::TYPE_Tag, name, atts);
	if (_stack.empty()) {
		_pElementRoot.reset(pElement);
	} else {
		_stack.back()->AddChild(pElement);
	}
	_stack.push_back(pElement);
}

void Document::OnEndElement(const XML_Char *name)
{
	_stack.pop_back();
}

void Document::OnCharacterData(const XML_Char *text, int len)
{
	if (!_stack.empty()) {
		Element *pElement = new Element(Element::TYPE_Text, String(text, len));
		_stack.back()->AddChild(pElement);
	}
}

void Document::OnProcessingInstruction(const XML_Char *target, const XML_Char *data)
{
}

void Document::OnComment(const XML_Char *data)
{
	if (!_stack.empty()) {
		Element *pElement = new Element(Element::TYPE_Comment, data);
		_stack.back()->AddChild(pElement);
	}
}

void Document::OnStartCdataSection()
{
}

void Document::OnEndCdataSection()
{
}

void Document::OnDefault(const XML_Char *text, int len)
{
}

void Document::OnDefaultExpand(const XML_Char *text, int len)
{
}

int Document::OnExternalEntityRef(XML_Parser parser,
							const XML_Char *args, const XML_Char *base,
							const XML_Char *systemId, const XML_Char *publicId)
{
	return 0;
}

void Document::OnSkippedEntity(const XML_Char *entityName, int isParameterEntity)
{
}

void Document::OnStartNamespaceDecl(const XML_Char *prefix, const XML_Char *uri)
{
}

void Document::OnEndNamespaceDecl(const XML_Char *prefix)
{
}

void Document::OnXmlDecl(const XML_Char *version, const XML_Char *encoding, int standalone)
{
}

void Document::OnStartDoctypeDecl(
				const XML_Char *doctypeName, const XML_Char *systemId,
				const XML_Char *publicId, int hasInternalSubset)
{
}

void Document::OnEndDoctypeDecl()
{
}

void Document::OnElementDecl(const XML_Char *name, XML_Content *model)
{
}

void Document::OnAttlistDecl(
			const XML_Char *elemName, const XML_Char *attName,
			const XML_Char *attType, const XML_Char *defaultValue, int isRequired)
{
}

void Document::OnEntityDecl(
			const XML_Char *entityName, int isParameterEntity,
			const XML_Char *value, int valueLength, const XML_Char *base,
			const XML_Char *systemId, const XML_Char *publicId,
			const XML_Char *notationName)
{
}

void Document::OnNotationDecl(
			const XML_Char *notationName, const XML_Char *base,
			const XML_Char *systemId, const XML_Char *publicId)
{
}

int Document::OnNotStandalone()
{
	return 0;
}

//-----------------------------------------------------------------------------
// Object_parser
//-----------------------------------------------------------------------------
Object_parser::Object_parser(Class *pClass) :
						Object(pClass), _parser(this), _pSig(NULL)
{
}

void Object_parser::Parse(Environment &env, Signal &sig, Stream &stream)
{
	_pSig = &sig;
	_parser.Parse(sig, stream);
	_pSig = NULL;
}

void Object_parser::CallHandler(const Symbol *pSymbol, const ValueList argList)
{
	bool evaluatedFlag;
	Value rtn = EvalMethod(*this, *_pSig, pSymbol, argList, evaluatedFlag);
	if (_pSig->IsSignalled()) {
		_parser.StopParser();
	}
}

void Object_parser::ParserEx::OnStartElement(const XML_Char *name, const XML_Char **atts)
{
	Environment &env = *_pObj;
	Element *pElement = new Element(Element::TYPE_Tag, name, atts);
	ValueList valListArg;
	valListArg.push_back(Value(new Object_element(pElement)));
	_pObj->CallHandler(Gura_UserSymbol(StartElement), valListArg);
}

void Object_parser::ParserEx::OnEndElement(const XML_Char *name)
{
	Environment &env = *_pObj;
	ValueList valListArg;
	valListArg.push_back(Value(env, name));
	_pObj->CallHandler(Gura_UserSymbol(EndElement), valListArg);
}

void Object_parser::ParserEx::OnCharacterData(const XML_Char *text, int len)
{
	Environment &env = *_pObj;
	ValueList valListArg;
	valListArg.push_back(Value(env, text, len));
	_pObj->CallHandler(Gura_UserSymbol(CharacterData), valListArg);
}

void Object_parser::ParserEx::OnProcessingInstruction(const XML_Char *target, const XML_Char *data)
{
	Environment &env = *_pObj;
	ValueList valListArg;
	valListArg.push_back(Value(env, target));
	valListArg.push_back(Value(env, data));
	_pObj->CallHandler(Gura_UserSymbol(ProcessingInstruction), valListArg);
}

void Object_parser::ParserEx::OnComment(const XML_Char *data)
{
	Environment &env = *_pObj;
	ValueList valListArg;
	valListArg.push_back(Value(env, data));
	_pObj->CallHandler(Gura_UserSymbol(Comment), valListArg);
}

void Object_parser::ParserEx::OnStartCdataSection()
{
	ValueList valListArg;
	_pObj->CallHandler(Gura_UserSymbol(StartCdataSection), valListArg);
}

void Object_parser::ParserEx::OnEndCdataSection()
{
	ValueList valListArg;
	_pObj->CallHandler(Gura_UserSymbol(EndCdataSection), valListArg);
}

void Object_parser::ParserEx::OnDefault(const XML_Char *text, int len)
{
	Environment &env = *_pObj;
	ValueList valListArg;
	valListArg.push_back(Value(env, text, len));
	_pObj->CallHandler(Gura_UserSymbol(Default), valListArg);
}

void Object_parser::ParserEx::OnDefaultExpand(const XML_Char *text, int len)
{
	Environment &env = *_pObj;
	ValueList valListArg;
	valListArg.push_back(Value(env, text, len));
	_pObj->CallHandler(Gura_UserSymbol(DefaultExpand), valListArg);
}

int Object_parser::ParserEx::OnExternalEntityRef(XML_Parser parser,
							const XML_Char *args, const XML_Char *base,
							const XML_Char *systemId, const XML_Char *publicId)
{
	//ValueList valListArg;
	//_pObj->CallHandler(Gura_UserSymbol(ExternalEntityRef), valListArg);
	return 0;
}

void Object_parser::ParserEx::OnSkippedEntity(const XML_Char *entityName, int isParameterEntity)
{
	Environment &env = *_pObj;
	ValueList valListArg;
	valListArg.push_back(Value(env, entityName));
	valListArg.push_back(Value(isParameterEntity != 0));
	_pObj->CallHandler(Gura_UserSymbol(SkippedEntity), valListArg);
}

void Object_parser::ParserEx::OnStartNamespaceDecl(const XML_Char *prefix, const XML_Char *uri)
{
	Environment &env = *_pObj;
	ValueList valListArg;
	valListArg.push_back(Value(env, prefix));
	valListArg.push_back(Value(env, uri));
	_pObj->CallHandler(Gura_UserSymbol(StartNamespaceDecl), valListArg);
}

void Object_parser::ParserEx::OnEndNamespaceDecl(const XML_Char *prefix)
{
	Environment &env = *_pObj;
	ValueList valListArg;
	valListArg.push_back(Value(env, prefix));
	_pObj->CallHandler(Gura_UserSymbol(EndNamespaceDecl), valListArg);
}

void Object_parser::ParserEx::OnXmlDecl(const XML_Char *version, const XML_Char *encoding, int standalone)
{
	Environment &env = *_pObj;
	ValueList valListArg;
	valListArg.push_back(Value(env, version));
	valListArg.push_back(Value(env, encoding));
	if (standalone >= 0) {
		valListArg.push_back(Value(standalone != 0));
	}
	_pObj->CallHandler(Gura_UserSymbol(XmlDecl), valListArg);
}

void Object_parser::ParserEx::OnStartDoctypeDecl(
				const XML_Char *doctypeName, const XML_Char *systemId,
				const XML_Char *publicId, int hasInternalSubset)
{
	Environment &env = *_pObj;
	ValueList valListArg;
	valListArg.push_back(Value(env, doctypeName));
	valListArg.push_back(Value(env, systemId));
	valListArg.push_back(Value(env, publicId));
	valListArg.push_back(Value(hasInternalSubset != 0));
	_pObj->CallHandler(Gura_UserSymbol(StartDoctypeDecl), valListArg);
}

void Object_parser::ParserEx::OnEndDoctypeDecl()
{
	ValueList valListArg;
	_pObj->CallHandler(Gura_UserSymbol(EndDoctypeDecl), valListArg);
}

void Object_parser::ParserEx::OnElementDecl(const XML_Char *name, XML_Content *model)
{
	Environment &env = *_pObj;
	ValueList valListArg;
	valListArg.push_back(Value(env, name));
	//**************************
	// todo
	//**************************
	_pObj->CallHandler(Gura_UserSymbol(ElementDecl), valListArg);
}

void Object_parser::ParserEx::OnAttlistDecl(
			const XML_Char *elemName, const XML_Char *attName,
			const XML_Char *attType, const XML_Char *defaultValue, int isRequired)
{
	Environment &env = *_pObj;
	ValueList valListArg;
	valListArg.push_back(Value(env, elemName));
	valListArg.push_back(Value(env, attName));
	valListArg.push_back(Value(env, attType));
	valListArg.push_back(Value(env, defaultValue));
	valListArg.push_back(Value(isRequired != 0)); // #IMPLIED / #REQUIRED
	_pObj->CallHandler(Gura_UserSymbol(AttlistDecl), valListArg);
}

void Object_parser::ParserEx::OnEntityDecl(
			const XML_Char *entityName, int isParameterEntity,
			const XML_Char *value, int valueLength, const XML_Char *base,
			const XML_Char *systemId, const XML_Char *publicId,
			const XML_Char *notationName)
{
	Environment &env = *_pObj;
	ValueList valListArg;
	valListArg.push_back(Value(env, entityName));
	valListArg.push_back(Value(isParameterEntity != 0));
	valListArg.push_back(Value(env, value, valueLength));
	valListArg.push_back(Value(env, base));
	valListArg.push_back(Value(env, systemId));
	valListArg.push_back(Value(env, publicId));
	valListArg.push_back(Value(env, notationName));
	_pObj->CallHandler(Gura_UserSymbol(EntityDecl), valListArg);
}

void Object_parser::ParserEx::OnNotationDecl(
			const XML_Char *notationName, const XML_Char *base,
			const XML_Char *systemId, const XML_Char *publicId)
{
	Environment &env = *_pObj;
	ValueList valListArg;
	valListArg.push_back(Value(env, notationName));
	valListArg.push_back(Value(env, base));
	valListArg.push_back(Value(env, systemId));
	valListArg.push_back(Value(env, publicId));
	_pObj->CallHandler(Gura_UserSymbol(NotationDecl), valListArg);
}

int Object_parser::ParserEx::OnNotStandalone()
{
	ValueList valListArg;
	_pObj->CallHandler(Gura_UserSymbol(NotStandalone), valListArg);
	return 0;
}

//-----------------------------------------------------------------------------
// Gura interfaces for Object_parser
//-----------------------------------------------------------------------------
// str = xml.parser#parse(stream:stream:r)
Gura_DeclareMethod(parser, parse)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Read);
}

Gura_ImplementMethod(parser, parse)
{
	Object_parser *pObj = Object_parser::GetThisObj(args);
	pObj->Parse(env, sig, args.GetStream(0));
	return Value::Null;
}

// implementation of class Parser
Gura_ImplementUserInheritableClass(parser)
{
	Gura_AssignMethod(parser, parse);
}

Gura_ImplementDescendantCreator(parser)
{
	return new Object_parser((pClass == NULL)? this : pClass);
}

//-----------------------------------------------------------------------------
// Object_attribute
//-----------------------------------------------------------------------------
Object_attribute::Object_attribute(Attribute *pAttribute) :
					Object(Gura_UserClass(attribute)), _pAttribute(pAttribute)
{
}

bool Object_attribute::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	symbols.insert(Gura_UserSymbol(name));
	symbols.insert(Gura_UserSymbol(value));
	return true;
}

Value Object_attribute::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(name))) {
		return Value(env, _pAttribute->GetName());
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(value))) {
		return Value(env, _pAttribute->GetValue());
	}
	evaluatedFlag = false;
	return Value::Null;
}

String Object_attribute::ToString(Signal sig, bool exprFlag)
{
	String str;
	str = "<xml.attribute:";
	str += _pAttribute->GetName();
	str += "=";
	str += _pAttribute->GetValue();
	str += ">";
	return str;
}

//-----------------------------------------------------------------------------
// Gura interfaces for Object_attribute
//-----------------------------------------------------------------------------
// implementation of class attribute
Gura_ImplementUserClass(attribute)
{
}

//-----------------------------------------------------------------------------
// Object_element
//-----------------------------------------------------------------------------
Object_element::Object_element(Element *pElement) :
					Object(Gura_UserClass(element)), _pElement(pElement)
{
}

Value Object_element::IndexGet(Environment &env, Signal sig, const Value &valueIdx)
{
	if (!valueIdx.IsString()) {
		sig.SetError(ERR_ValueError, "index must be a string");
		return Value::Null;
	}
	const AttributeOwner *pAttributes = _pElement->GetAttributes();
	const Attribute *pAttribute = (pAttributes == NULL)?
					NULL : pAttributes->FindByName(valueIdx.GetString());
	if (pAttribute == NULL) {
		sig.SetError(ERR_IndexError, "specified attribute doesn't exist");
		return Value::Null;
	}
	return Value(env, pAttribute->GetValue());
}

bool Object_element::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	symbols.insert(Gura_UserSymbol(tagname));
	symbols.insert(Gura_UserSymbol(text));
	symbols.insert(Gura_UserSymbol(comment));
	symbols.insert(Gura_UserSymbol(children));
	symbols.insert(Gura_UserSymbol(attrs));
	return true;
}

Value Object_element::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(tagname))) {
		if (!_pElement->IsTag()) return Value::Null;
		return Value(env, _pElement->GetTagName());
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(text))) {
		if (!_pElement->IsText()) return Value::Null;
		return Value(env, _pElement->GetText());
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(comment))) {
		if (!_pElement->IsComment()) return Value::Null;
		return Value(env, _pElement->GetComment());
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(children))) {
		const ElementOwner *pChildren = _pElement->GetChildren();
		if (pChildren == NULL) return Value::Null;
		Iterator *pIterator = new Iterator_element(pChildren->Reference());
		return Value(env, pIterator);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(attrs))) {
		const AttributeOwner *pAttrs = _pElement->GetAttributes();
		if (pAttrs == NULL) return Value::Null;
		Iterator *pIterator = new Iterator_attribute(pAttrs->Reference());
		return Value(env, pIterator);
	}
	evaluatedFlag = false;
	return Value::Null;
}

String Object_element::ToString(Signal sig, bool exprFlag)
{
	String str;
	str = "<xml.element:";
	if (_pElement->IsText()) {
		str += "*text*";
	} else if (_pElement->IsComment()) {
		str += "*comment*";
	} else {
		str += _pElement->GetTagName();
	}
	str += ">";
	return str;
}

//-----------------------------------------------------------------------------
// Gura interfaces for Object_element
//-----------------------------------------------------------------------------
// xml.element#format(stream?:stream:w):void
Gura_DeclareMethod(element, format)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_ZeroOrOnce, FLAG_Write);
}

Gura_ImplementMethod(element, format)
{
	Object_element *pObj = Object_element::GetThisObj(args);
	Stream *pStream = env.GetConsole();
	if (args.IsStream(0)) pStream = &args.GetStream(0);
	pObj->GetElement()->Format(sig, *pStream, 0);
	return Value::Null;
}

// xml.element#gettext()
Gura_DeclareMethod(element, gettext)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(element, gettext)
{
	Object_element *pObj = Object_element::GetThisObj(args);
	String str = pObj->GetElement()->GatherText();
	if (sig.IsSignalled()) return Value::Null;
	return Value(env, str.c_str());
}

// xml.element#addchild(value):void:map
Gura_DeclareMethod(element, addchild)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "value", VTYPE_any);
}

Gura_ImplementMethod(element, addchild)
{
	Object_element *pObj = Object_element::GetThisObj(args);
	pObj->GetElement()->AddChild(env, sig, args.GetValue(0));
	return Value::Null;
}

// implementation of class Element
Gura_ImplementUserClass(element)
{
	Gura_AssignMethod(element, format);
	Gura_AssignMethod(element, gettext);
	Gura_AssignMethod(element, addchild);
}

//-----------------------------------------------------------------------------
// Iterator_attribute
//-----------------------------------------------------------------------------
Iterator_attribute::Iterator_attribute(AttributeOwner *pAttributeOwner) :
						Iterator(false), _idxAttribute(0), _pAttributeOwner(pAttributeOwner)
{
}

Iterator *Iterator_attribute::GetSource()
{
	return NULL;
}

bool Iterator_attribute::DoNext(Environment &env, Signal sig, Value &value)
{
	if (_idxAttribute < _pAttributeOwner->size()) {
		Attribute *pAttribute = (*_pAttributeOwner)[_idxAttribute++];
		value = Value(new Object_attribute(pAttribute->Reference()));
		return true;
	}
	return false;
}

String Iterator_attribute::ToString(Signal sig) const
{
	String rtn;
	rtn += "<iterator:xml.attribute";
	rtn += ">";
	return rtn;
}

void Iterator_attribute::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

//-----------------------------------------------------------------------------
// Iterator_element
//-----------------------------------------------------------------------------
Iterator_element::Iterator_element(ElementOwner *pElementOwner) :
						Iterator(false), _idxElement(0), _pElementOwner(pElementOwner)
{
}

Iterator *Iterator_element::GetSource()
{
	return NULL;
}

bool Iterator_element::DoNext(Environment &env, Signal sig, Value &value)
{
	if (_idxElement < _pElementOwner->size()) {
		Element *pElement = (*_pElementOwner)[_idxElement++];
		value = Value(new Object_element(pElement->Reference()));
		return true;
	}
	return false;
}

String Iterator_element::ToString(Signal sig) const
{
	String rtn;
	rtn += "<iterator:xml.element";
	rtn += ">";
	return rtn;
}

void Iterator_element::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

//-----------------------------------------------------------------------------
// Gura module functions: xml
//-----------------------------------------------------------------------------
// xml.parser()
Gura_DeclareFunctionBegin(parser)
Gura_DeclareFunctionEnd(parser)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(parser));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(parser)
{
	Object_parser *pObj = Object_parser::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_parser(Gura_UserClass(parser));
		return ReturnValue(env, sig, args, Value(pObj));
	}
	return ReturnValue(env, sig, args, args.GetThis());
}

// xml.element(_tagname_:string, %attrs):map {block?}
Gura_DeclareFunction(element)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "_tagname_", VTYPE_string);
	DeclareDictArg("attrs");
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(element)
{
	Element *pElement = new Element(Element::TYPE_Tag, args.GetStringSTL(0));
	foreach_const (ValueDict, iter, args.GetDictArg()) {
		String key = iter->first.ToString(sig, false);
		if (sig.IsSignalled()) return Value::Null;
		String value = iter->second.ToString(sig, false);
		if (sig.IsSignalled()) return Value::Null;
		pElement->GetAttributes()->push_back(new Attribute(key, value));
	}
	const Expr_Block *pExprBlock = args.GetBlock(env, sig);
	if (sig.IsSignalled()) return Value::Null;
	if (pExprBlock != NULL) {
		Environment envLister(&env, ENVTYPE_lister);
		Value valueRaw =
			pExprBlock->GetExprOwner().ExecForList(envLister, sig, false, false);
		if (sig.IsSignalled() || !valueRaw.IsList()) return Value::Null;
		foreach_const (ValueList, pValue, valueRaw.GetList()) {
			if (!pElement->AddChild(env, sig, *pValue)) return Value::Null;
		}
	}
	return Value(new Object_element(pElement));
}

// xml.comment(comment:string)
Gura_DeclareFunction(comment)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "comment", VTYPE_string);
}

Gura_ImplementFunction(comment)
{
	Element *pElement = new Element(Element::TYPE_Comment, args.GetStringSTL(0));
	return Value(new Object_element(pElement));
}

// xml.read(stream:stream:r) {block?}
Gura_DeclareFunction(read)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Read);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(read)
{
	AutoPtr<Document> pDocument(new Document());
	AutoPtr<Element> pElement(pDocument->Parse(sig, args.GetStream(0)));
	if (sig.IsError()) return Value::Null;
	return ReturnValue(env, sig, args, Value(new Object_element(pElement.release())));
}

//-----------------------------------------------------------------------------
// Gura interfaces for Object_stream
//-----------------------------------------------------------------------------
// stream#xmlread()
Gura_DeclareMethod(stream, xmlread)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(stream, xmlread)
{
	Object_stream *pThis = Object_stream::GetThisObj(args);
	AutoPtr<Document> pDocument(new Document());
	AutoPtr<Element> pElement(pDocument->Parse(sig, pThis->GetStream()));
	if (sig.IsError()) return Value::Null;
	return Value(new Object_element(pElement.release()));
}

// Module entry
Gura_ModuleEntry()
{
	// symbol realization
	Gura_RealizeUserSymbol(name);
	Gura_RealizeUserSymbol(value);
	Gura_RealizeUserSymbol(tagname);
	Gura_RealizeUserSymbol(text);
	Gura_RealizeUserSymbol(comment);
	Gura_RealizeUserSymbol(children);
	Gura_RealizeUserSymbol(attrs);
	Gura_RealizeUserSymbol(StartElement);
	Gura_RealizeUserSymbol(EndElement);
	Gura_RealizeUserSymbol(CharacterData);
	Gura_RealizeUserSymbol(ProcessingInstruction);
	Gura_RealizeUserSymbol(Comment);
	Gura_RealizeUserSymbol(StartCdataSection);
	Gura_RealizeUserSymbol(EndCdataSection);
	Gura_RealizeUserSymbol(Default);
	Gura_RealizeUserSymbol(DefaultExpand);
	Gura_RealizeUserSymbol(ExternalEntityRef);
	Gura_RealizeUserSymbol(SkippedEntity);
	Gura_RealizeUserSymbol(StartNamespaceDecl);
	Gura_RealizeUserSymbol(EndNamespaceDecl);
	Gura_RealizeUserSymbol(XmlDecl);
	Gura_RealizeUserSymbol(StartDoctypeDecl);
	Gura_RealizeUserSymbol(EndDoctypeDecl);
	Gura_RealizeUserSymbol(ElementDecl);
	Gura_RealizeUserSymbol(AttlistDecl);
	Gura_RealizeUserSymbol(EntityDecl);
	Gura_RealizeUserSymbol(NotationDecl);
	Gura_RealizeUserSymbol(NotStandalone);
	// class realization
	Gura_RealizeUserClass(attribute, env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(element, env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(parser, env.LookupClass(VTYPE_object));
	// function assignment
	Gura_AssignFunction(parser);
	Gura_AssignFunction(element);
	Gura_AssignFunction(comment);
	Gura_AssignFunction(read);
	// method assignment to stream type
	Gura_AssignMethodTo(VTYPE_stream, stream, xmlread);
}

Gura_ModuleTerminate()
{
}

Gura_EndModule(xml, xml)

Gura_RegisterModule(xml)
