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
	for (int i = 0; i < NUMBEROF(info->map); i++) info->map[i] = -1;
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
	unsigned short codeCP932 =
		(static_cast<unsigned short>(static_cast<unsigned char>(s[0])) << 8) +
		static_cast<unsigned char>(s[1]);
	unsigned short codeUTF16 = CP932ToUTF16(codeCP932);
	return (codeUTF16 == 0)? -1 : codeUTF16;
}

int Parser::Convert_euc_jp(void *data, const char *s)
{
	unsigned short codeEUCJP =
		(static_cast<unsigned short>(static_cast<unsigned char>(s[0])) << 8) +
		static_cast<unsigned char>(s[1]);
	unsigned short codeCP932 = EUCJPToCP932(codeEUCJP);
	unsigned short codeUTF16 = CP932ToUTF16(codeCP932);
	return (codeUTF16 == 0)? -1 : codeUTF16;
}

//-----------------------------------------------------------------------------
// Object_parser
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(parser);

Object_parser::Object_parser(Class *pClass) :
						Object(pClass), _parser(this), _pSig(NULL)
{
}

Object_parser::~Object_parser()
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
	Value rtn = EvalMethod(*_pSig, pSymbol, argList, evaluatedFlag);
	if (_pSig->IsSignalled()) {
		_parser.StopParser();
	}
}

void Object_parser::ParserEx::OnStartElement(const XML_Char *name, const XML_Char **atts)
{
	Environment &env = *_pObj;
	ValueList valListArg;
	valListArg.push_back(Value(new Object_element(env, name, atts)));
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
	Object_parser *pObj = Object_parser::GetSelfObj(args);
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
// Object_element
//-----------------------------------------------------------------------------
Object_element::Object_element(Environment &env, const char *name, const char **atts) :
					Object_dict(env.LookupClass(VTYPE_element), false)
{
	AssignValue(Gura_Symbol(name), Value(env, name), false);
	if (atts != NULL) {
		ValueDict &valDict = GetDict();
		for (const char **p = atts; *p != NULL && *(p + 1) != NULL; p += 2) {
			valDict[Value(env, *p)] = Value(env, *(p + 1));
		}
	}
	Value valueOfList;
	_pValList = &valueOfList.InitAsList(env);
	AssignValue(Gura_Symbol(children), valueOfList, false);
}

void Object_element::AddChild(const Value &value)
{
	_pValList->push_back(value);
}

String Object_element::Format(Signal sig, int indentLevel) const
{
	const char *indentUnit = "  ";
	String str;
	String name = "";
	String indent;
	for (int i = 0; i < indentLevel; i++) indent += indentUnit;
	do {
		const Value *pValue = LookupValue(Gura_Symbol(name), false);
		if (pValue != NULL) name = pValue->ToString(sig, false);
	} while (0);
	str += indent;
	str += "<";
	str += name;
	foreach_const (ValueDict, iter, GetDict()) {
		str += " ";
		str += iter->first.ToString(sig, false);
		str += "=\"";
		str += iter->second.ToString(sig, false);
		str += "\"";
	}
	const Value *pValChildren = LookupValue(Gura_Symbol(children), false);
	if (pValChildren == NULL || !pValChildren->IsList() ||
									pValChildren->GetList().empty()) {
		str += " />";
	} else {
		str += ">\n";
		foreach_const (ValueList, pValue, pValChildren->GetList()) {
			if (pValue->IsString()) {
				str += indent;
				str += indentUnit;
				str += pValue->GetString();
				str += "\n";
			} else if (pValue->IsType(VTYPE_element)) {
				const Object *pObj = pValue->GetObject();
				str += dynamic_cast<const Object_element *>(pObj)->
													Format(sig, indentLevel + 1);
				str += "\n";
			}
		}
		str += indent;
		str += "</";
		str += name;
		str += ">";
	}
	return str;
}

String Object_element::GetText(Signal sig) const
{
	String str;
	const Value *pValChildren = LookupValue(Gura_Symbol(children), false);
	if (pValChildren != NULL && pValChildren->IsList() &&
									!pValChildren->GetList().empty()) {
		foreach_const (ValueList, pValue, pValChildren->GetList()) {
			if (pValue->IsString()) {
				str += pValue->GetString();
			} else if (pValue->IsType(VTYPE_element)) {
				const Object *pObj = pValue->GetObject();
				str += dynamic_cast<const Object_element *>(pObj)->GetText(sig);
			}
		}
	}
	return str;
}

String Object_element::ToString(Signal sig, bool exprFlag)
{
	String str;
	const Value *pValue = LookupValue(Gura_Symbol(name), false);
	if (pValue == NULL) {
		str = "<xml.element>";
	} else {
		str = "<xml.element:";
		str += pValue->ToString(sig, false);
		str += ">";
	}
	return str;
}

//-----------------------------------------------------------------------------
// Gura interfaces for Object_element
//-----------------------------------------------------------------------------
// xml.element#format()
Gura_DeclareMethod(element, format)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(element, format)
{
	Object_element *pObj = Object_element::GetSelfObj(args);
	String str = pObj->Format(sig, 0);
	if (sig.IsSignalled()) return Value::Null;
	return Value(env, str.c_str());
}

// xml.element#text()
Gura_DeclareMethod(element, text)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(element, text)
{
	Object_element *pObj = Object_element::GetSelfObj(args);
	String str = pObj->GetText(sig);
	if (sig.IsSignalled()) return Value::Null;
	return Value(env, str.c_str());
}

// implementation of class Element
Gura_ImplementUserClass(element)
{
	Gura_AssignMethod(element, format);
	Gura_AssignMethod(element, text);
}

//-----------------------------------------------------------------------------
// Reader
//-----------------------------------------------------------------------------
Object_element *Reader::Parse(Environment &env, Signal &sig, Stream &stream)
{
	_pObjElemRoot = NULL, _pEnv = &env, _pSig = &sig;
	Parser::Parse(sig, stream);
	_pEnv = NULL, _pSig = NULL;
	return _pObjElemRoot;
}

void Reader::OnStartElement(const XML_Char *name, const XML_Char **atts)
{
	Object_element *pObjElem = new Object_element(*_pEnv, name, atts);
	if (_stack.empty()) {
		_pObjElemRoot = pObjElem;
	} else {
		_stack.back()->AddChild(Value(pObjElem));
	}
	_stack.push_back(pObjElem);
}

void Reader::OnEndElement(const XML_Char *name)
{
	_stack.pop_back();
}

void Reader::OnCharacterData(const XML_Char *text, int len)
{
	if (!_stack.empty()) {
		_stack.back()->AddChild(Value(*_pEnv,
							reinterpret_cast<const char *>(text), len));
	}
}

void Reader::OnProcessingInstruction(const XML_Char *target, const XML_Char *data)
{
}

void Reader::OnComment(const XML_Char *data)
{
}

void Reader::OnStartCdataSection()
{
}

void Reader::OnEndCdataSection()
{
}

void Reader::OnDefault(const XML_Char *text, int len)
{
}

void Reader::OnDefaultExpand(const XML_Char *text, int len)
{
}

int Reader::OnExternalEntityRef(XML_Parser parser,
							const XML_Char *args, const XML_Char *base,
							const XML_Char *systemId, const XML_Char *publicId)
{
	return 0;
}

void Reader::OnSkippedEntity(const XML_Char *entityName, int isParameterEntity)
{
}

void Reader::OnStartNamespaceDecl(const XML_Char *prefix, const XML_Char *uri)
{
}

void Reader::OnEndNamespaceDecl(const XML_Char *prefix)
{
}

void Reader::OnXmlDecl(const XML_Char *version, const XML_Char *encoding, int standalone)
{
}

void Reader::OnStartDoctypeDecl(
				const XML_Char *doctypeName, const XML_Char *systemId,
				const XML_Char *publicId, int hasInternalSubset)
{
}

void Reader::OnEndDoctypeDecl()
{
}

void Reader::OnElementDecl(const XML_Char *name, XML_Content *model)
{
}

void Reader::OnAttlistDecl(
			const XML_Char *elemName, const XML_Char *attName,
			const XML_Char *attType, const XML_Char *defaultValue, int isRequired)
{
}

void Reader::OnEntityDecl(
			const XML_Char *entityName, int isParameterEntity,
			const XML_Char *value, int valueLength, const XML_Char *base,
			const XML_Char *systemId, const XML_Char *publicId,
			const XML_Char *notationName)
{
}

void Reader::OnNotationDecl(
			const XML_Char *notationName, const XML_Char *base,
			const XML_Char *systemId, const XML_Char *publicId)
{
}

int Reader::OnNotStandalone()
{
	return 0;
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
	Object_parser *pObj = Object_parser::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_parser(Gura_UserClass(parser));
		return ReturnValue(env, sig, args, Value(pObj));
	}
	return ReturnValue(env, sig, args, args.GetSelf());
}

// p = xml.element(name:string, %attrs) {block?}
Gura_DeclareFunction(element)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "name", VTYPE_string);
	DeclareDictArg("attrs");
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(element)
{
	Object_element *pObjElem = new Object_element(env, args.GetString(0), NULL);
	foreach_const (ValueDict, iter, args.GetDictArg()) {
		pObjElem->GetDict()[iter->first] = iter->second;
	}
	const Expr_Block *pExprBlock = args.GetBlock(env, sig);
	if (sig.IsSignalled()) return Value::Null;
	if (pExprBlock != NULL) {
		Environment envLister(&env, ENVTYPE_lister);
		Value valueRaw =
			pExprBlock->GetExprList().ExecForList(envLister, sig, false, false);
		if (sig.IsSignalled() || !valueRaw.IsList()) return Value::Null;
		Value result;
		ValueList &valList = result.InitAsList(env);
		foreach_const (ValueList, pValue, valueRaw.GetList()) {
			valList.push_back(*pValue);
		}
		pObjElem->AssignValue(Gura_Symbol(children), result, false);
	}
	return Value(pObjElem);
}

// obj = xml.read(stream:stream:r)
Gura_DeclareFunction(read)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Read);
}

Gura_ImplementFunction(read)
{
	Value result;
	Object_element *pObjElem = Reader().Parse(env, sig, args.GetStream(0));
	if (sig.IsError()) return Value::Null;
	return Value(pObjElem);
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
	Object_stream *pSelf = Object_stream::GetSelfObj(args);
	Value result;
	Object_element *pObjElem = Reader().Parse(env, sig, pSelf->GetStream());
	if (sig.IsError()) return Value::Null;
	return Value(pObjElem);
}

// Module entry
Gura_ModuleEntry()
{
	// symbol realization
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
	Gura_RealizeUserClass(element, env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(parser, env.LookupClass(VTYPE_object));
	// function assignment
	Gura_AssignFunction(parser);
	Gura_AssignFunction(element);
	Gura_AssignFunction(read);
	// method assignment to stream type
	Gura_AssignMethodTo(VTYPE_stream, stream, xmlread);
}

Gura_ModuleTerminate()
{
}

Gura_EndModule(xml, xml)

Gura_RegisterModule(xml)
