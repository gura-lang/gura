//-----------------------------------------------------------------------------
// Gura module: csv
//-----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleBody(csv)

static const char *DEFAULT_FORMAT = "%g";

//-----------------------------------------------------------------------------
// Implementation of Object_writer
//-----------------------------------------------------------------------------
Object_writer::Object_writer(Stream *pStreamDst, const char *format) :
		Object(Gura_UserClass(writer)), _pStreamDst(pStreamDst), _format(format)
{
}

Object_writer::~Object_writer()
{
}

Object *Object_writer::Clone() const
{
	return nullptr;
}

bool Object_writer::DoDirProp(Environment &env, SymbolSet &symbols)
{
	Signal &sig = GetSignal();
	if (!Object::DoDirProp(env, symbols)) return false;
	symbols.insert(Gura_Symbol(format));
	return true;
}

Value Object_writer::DoGetProp(Environment &env, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_Symbol(format))) {
		return Value(_format);
	}
	evaluatedFlag = false;
	return Value::Nil;
}

Value Object_writer::DoSetProp(Environment &env, const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	Signal &sig = GetSignal();
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_Symbol(format))) {
		if (!value.Is_string()) {
			sig.SetError(ERR_TypeError, "string must be specified");
			return Value::Nil;
		}
		_format = value.GetString();
		return value;
	}
	return DoGetProp(env, pSymbol, attrs, evaluatedFlag);
}

String Object_writer::ToString(bool exprFlag)
{
	String str;
	str = "<csv.writer:";
	if (_pStreamDst.IsNull()) {
		str += "invalid";
	} else {
		str += _pStreamDst->GetName();
	}
	str += ">";
	return str;
}

bool Object_writer::PutValue(Environment &env, const Value &value)
{
	Signal &sig = env.GetSignal();
	String str;
	if (value.IsInvalid()) {
		return true;
	} else if (value.Is_number()) {
		str = Formatter::FormatValueList(sig, _format.c_str(), ValueList(value));
	} else if (value.Is_complex()) {
		str = Formatter::FormatValueList(sig, _format.c_str(), ValueList(value));
	} else if (value.Is_string()) {
		str += '"';
		for (const char *p = value.GetString(); *p != '\0'; p++) {
			char ch = *p;
			str += ch;
			if (ch == '"') str += ch;
		}
		str += '"';
	} else {
		sig.SetError(ERR_TypeError, "can't output in CSV format");
		return false;
	}
	_pStreamDst->Print(sig, str.c_str());
	return true;
}

bool Object_writer::PutLine(Environment &env, const ValueList &valList)
{
	Signal &sig = env.GetSignal();
	foreach_const (ValueList, pValue, valList) {
		if (pValue != valList.begin()) {
			_pStreamDst->PutChar(sig, ',');
			if (sig.IsSignalled()) return false;
		}
		if (!PutValue(env, *pValue)) return false;
	}
	_pStreamDst->PutChar(sig, '\n');
	return !sig.IsSignalled();
}

//-----------------------------------------------------------------------------
// Interfaces of csv.writer
//-----------------------------------------------------------------------------
// csv.writer#write(fields+):map:reduce
Gura_DeclareMethod(writer, write)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "fields", VTYPE_any, OCCUR_OnceOrMore);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementMethod(writer, write)
{
	Signal &sig = env.GetSignal();
	Object_writer *pThis = Object_writer::GetThisObj(args);
	if (!pThis->PutLine(env, args.GetList(0))) return Value::Nil;
	return args.GetThis();
}

// implementation of class writer
Gura_ImplementUserClass(writer)
{
	Gura_AssignMethod(writer, write);
}

//-----------------------------------------------------------------------------
// Gura module functions: csv
//-----------------------------------------------------------------------------
// csv.parse(str:string):map
Gura_DeclareFunction(parse)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "str", VTYPE_string);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(parse)
{
	Iterator *pIterator = new Iterator_reader(new ReaderString(args.GetStringSTL(0)));
	return ReturnIterator(env, args, pIterator);
}

// csv.read(stream:stream:r) {block?}
Gura_DeclareFunction(read)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Read);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(read)
{
	Object_stream *pObjStream = Object_stream::GetObject(args, 0);
	Iterator *pIterator = new Iterator_reader(new ReaderStream(
									pObjStream->GetStream().Reference()));
	return ReturnIterator(env, args, pIterator);
}

// csv.writer(stream:stream:w, format?:string) {block?}
Gura_DeclareFunction(writer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Write);
	DeclareArg(env, "format", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(Gura_UserClass(writer));
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(writer)
{
	Object_stream *pObjStream = Object_stream::GetObject(args, 0);
	const char *format = args.Is_string(1)? args.GetString(1) : DEFAULT_FORMAT;
	Object_writer *pObj = new Object_writer(
						pObjStream->GetStream().Reference(), format);
	return ReturnValue(env, args, Value(pObj));
}

//-----------------------------------------------------------------------------
// Gura interfaces for Object_stream
//-----------------------------------------------------------------------------
// stream#read@csv() {block?}
Gura_DeclareMethodAlias(stream, read_csv, "read@csv")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementMethod(stream, read_csv)
{
	Object_stream *pThis = Object_stream::GetThisObj(args);
	Iterator *pIterator = new Iterator_reader(new ReaderStream(
							pThis->GetStream().Reference()));
	return ReturnIterator(env, args, pIterator);
}

// stream#writer@csv(format?:string) {block?}
Gura_DeclareMethodAlias(stream, writer_csv, "writer@csv")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "format", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementMethod(stream, writer_csv)
{
	Object_stream *pThis = Object_stream::GetThisObj(args);
	const char *format = args.Is_string(1)? args.GetString(1) : DEFAULT_FORMAT;
	Object_writer *pObj = new Object_writer(pThis->GetStream().Reference(), format);
	return ReturnValue(env, args, Value(pObj));
}

// Module entry
Gura_ModuleEntry()
{
	// symbol realization
	Gura_RealizeUserSymbol(format);
	// class realization
	Gura_RealizeAndPrepareUserClass(writer, env.LookupClass(VTYPE_object));
	// function assignment
	Gura_AssignFunction(parse);
	Gura_AssignFunction(read);
	Gura_AssignFunction(writer);
	// method assignment to stream type
	Gura_AssignMethodTo(VTYPE_stream, stream, read_csv);
	Gura_AssignMethodTo(VTYPE_stream, stream, writer_csv);
	// value assignment
	Gura_AssignValue(format, Value(DEFAULT_FORMAT));
	return true;
}

Gura_ModuleTerminate()
{
}

//-----------------------------------------------------------------------------
// Reader
//-----------------------------------------------------------------------------
bool Reader::ReadLine(Environment &env, ValueList &valList)
{
	Signal &sig = env.GetSignal();
	enum {
		STAT_LineTop, STAT_FieldTop, STAT_Field, STAT_Quoted, STAT_QuotedEnd,
	} stat = STAT_LineTop;
	String field;
	char ch = '\0';
	bool rtn = true;
	bool eatNextChar = true;
	for (;;) {
		if (eatNextChar) {
			while ((ch = NextChar(sig)) == '\r') ;
			if (sig.IsSignalled()) return false;
		}
		eatNextChar = true;
		if (stat == STAT_LineTop) {
			if (ch == '\0') {
				rtn = false;
				break;
			}
			eatNextChar = false;
			stat = STAT_FieldTop;
		} else if (stat == STAT_FieldTop) {
			field.clear();
			if (ch == '"') {
				stat = STAT_Quoted;
			} else if (ch == '\n' || ch == '\0') {
				valList.push_back(Value(field));
				break;
			} else {
				eatNextChar = false;
				stat = STAT_Field;
			}
		} else if (stat == STAT_Field) {
			if (ch == ',') {
				valList.push_back(Value(field));
				stat = STAT_FieldTop;
			} else if (ch == '\n' || ch == '\0') {
				valList.push_back(Value(field));
				break;
			} else {
				field.push_back(ch);
			}
		} else if (stat == STAT_Quoted) {
			if (ch == '"') {
				stat = STAT_QuotedEnd;
			} else if (ch == '\0') {
				valList.push_back(Value(field));
				break;
			} else {
				field.push_back(ch);
			}
		} else if (stat == STAT_QuotedEnd) {
			if (ch == '"') {
				field.push_back(ch);
				stat = STAT_Quoted;
			} else if (ch == '\0') {
				valList.push_back(Value(field));
				break;
			} else {
				eatNextChar = false;
				stat = STAT_Field;
			}
		}
	}
	return rtn;
}

//-----------------------------------------------------------------------------
// ReaderStream
//-----------------------------------------------------------------------------
char ReaderStream::NextChar(Signal &sig)
{
	int ch = _pStream->GetChar(sig);
	return (ch < 0)? '\0' : static_cast<char>(static_cast<UChar>(ch));
}

//-----------------------------------------------------------------------------
// ReaderString
//-----------------------------------------------------------------------------
char ReaderString::NextChar(Signal &sig)
{
	return (_strp == _str.end())? '\0' : *_strp++;
}

//-----------------------------------------------------------------------------
// Iterator_reader
//-----------------------------------------------------------------------------
Iterator *Iterator_reader::GetSource()
{
	return nullptr;
}

bool Iterator_reader::DoNext(Environment &env, Value &value)
{
	Signal &sig = env.GetSignal();
	ValueList &valList = value.InitAsList(env);
	if (_pReader->ReadLine(env, valList)) return true;
	value = Value::Nil;
	return false;
}

String Iterator_reader::ToString() const
{
	return String("<iterator:csv.reader>");
}

void Iterator_reader::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

Gura_EndModuleBody(csv, csv)

Gura_RegisterModule(csv)
