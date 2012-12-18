//-----------------------------------------------------------------------------
// Gura csv module
//-----------------------------------------------------------------------------
#include "Module_csv.h"

Gura_BeginModule(csv)

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
	return NULL;
}

bool Object_writer::DoPropDir(Signal sig, SymbolSet &symbols)
{
	if (!Object::DoPropDir(sig, symbols)) return false;
	symbols.insert(Gura_Symbol(format));
	return true;
}

Value Object_writer::DoPropGet(Signal sig, const Symbol *pSymbol, bool &evaluatedFlag)
{
	Environment &env = *this;
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_Symbol(format))) {
		return Value(env, _format.c_str());
	}
	evaluatedFlag = false;
	return Value::Null;
}

Value Object_writer::DoPropSet(Signal sig,
				const Symbol *pSymbol, const Value &value, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_Symbol(format))) {
		if (!value.IsString()) {
			sig.SetError(ERR_TypeError, "string must be specified");
			return Value::Null;
		}
		_format = value.GetString();
		return value;
	}
	return DoPropGet(sig, pSymbol, evaluatedFlag);
}

String Object_writer::ToString(Signal sig, bool exprFlag)
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

bool Object_writer::PutValue(Environment &env, Signal sig, const Value &value)
{
	String str;
	if (value.IsInvalid()) {
		return true;
	} else if (value.IsNumber()) {
		str = Formatter::Format(sig, _format.c_str(), ValueList(value));
	} else if (value.IsComplex()) {
		str = Formatter::Format(sig, _format.c_str(), ValueList(value));
	} else if (value.IsString()) {
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

bool Object_writer::PutLine(Environment &env, Signal sig, const ValueList &valList)
{
	foreach_const (ValueList, pValue, valList) {
		if (pValue != valList.begin()) {
			_pStreamDst->PutChar(sig, ',');
			if (sig.IsSignalled()) return false;
		}
		if (!PutValue(env, sig, *pValue)) return false;
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
	SetMode(RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "fields", VTYPE_any, OCCUR_OnceOrMore);
}

Gura_ImplementMethod(writer, write)
{
	Object_writer *pSelf = Object_writer::GetSelfObj(args);
	if (!pSelf->PutLine(env, sig, args.GetList(0))) return Value::Null;
	return args.GetSelf();
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
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "str", VTYPE_string);
}

Gura_ImplementFunction(parse)
{
	Iterator *pIterator = new Iterator_reader(new ReaderString(args.GetStringSTL(0)));
	return ReturnIterator(env, sig, args, pIterator);
}

// csv.reader(stream:stream:r) {block?}
Gura_DeclareFunction(reader)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Read);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(reader)
{
	Object_stream *pObjStream = args.GetStreamObj(0);
	Iterator *pIterator = new Iterator_reader(new ReaderStream(
							Stream::Reference(&pObjStream->GetStream())));
	return ReturnIterator(env, sig, args, pIterator);
}

// csv.writer(stream:stream:w, format?:string) {block?}
Gura_DeclareFunction(writer)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Write);
	DeclareArg(env, "format", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(Gura_UserClass(writer));
}

Gura_ImplementFunction(writer)
{
	Object_stream *pObjStream = args.GetStreamObj(0);
	const char *format = args.IsString(1)? args.GetString(1) : DEFAULT_FORMAT;
	Object_writer *pObj = new Object_writer(
						Stream::Reference(&pObjStream->GetStream()), format);
	return ReturnValue(env, sig, args, Value(pObj));
}

//-----------------------------------------------------------------------------
// Gura interfaces for Object_stream
//-----------------------------------------------------------------------------
// stream#csvreader() {block?}
Gura_DeclareMethod(stream, csvreader)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(stream, csvreader)
{
	Object_stream *pSelf = Object_stream::GetSelfObj(args);
	Iterator *pIterator = new Iterator_reader(new ReaderStream(
							Stream::Reference(&pSelf->GetStream())));
	return ReturnIterator(env, sig, args, pIterator);
}

// stream#csvwriter(format?:string) {block?}
Gura_DeclareMethod(stream, csvwriter)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "format", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(stream, csvwriter)
{
	Object_stream *pSelf = Object_stream::GetSelfObj(args);
	const char *format = args.IsString(1)? args.GetString(1) : DEFAULT_FORMAT;
	Object_writer *pObj = new Object_writer(
						Stream::Reference(&pSelf->GetStream()), format);
	return ReturnValue(env, sig, args, Value(pObj));
}

// Module entry
Gura_ModuleEntry()
{
	// symbol realization
	Gura_RealizeUserSymbol(format);
	// class realization
	Gura_RealizeUserClass(writer, env.LookupClass(VTYPE_object));
	// function assignment
	Gura_AssignFunction(parse);
	Gura_AssignFunction(reader);
	Gura_AssignFunction(writer);
	// method assignment to stream type
	Gura_AssignMethodTo(VTYPE_stream, stream, csvreader);
	Gura_AssignMethodTo(VTYPE_stream, stream, csvwriter);
	// value assignment
	Gura_AssignValue(format, Value(env, DEFAULT_FORMAT));
}

Gura_ModuleTerminate()
{
}

//-----------------------------------------------------------------------------
// Reader
//-----------------------------------------------------------------------------
bool Reader::ReadLine(Environment &env, Signal sig, ValueList &valList)
{
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
				valList.push_back(Value(env, field.c_str()));
				break;
			} else {
				eatNextChar = false;
				stat = STAT_Field;
			}
		} else if (stat == STAT_Field) {
			if (ch == ',') {
				valList.push_back(Value(env, field.c_str()));
				stat = STAT_FieldTop;
			} else if (ch == '\n' || ch == '\0') {
				valList.push_back(Value(env, field.c_str()));
				break;
			} else {
				field.push_back(ch);
			}
		} else if (stat == STAT_Quoted) {
			if (ch == '"') {
				stat = STAT_QuotedEnd;
			} else if (ch == '\0') {
				valList.push_back(Value(env, field.c_str()));
				break;
			} else {
				field.push_back(ch);
			}
		} else if (stat == STAT_QuotedEnd) {
			if (ch == '"') {
				field.push_back(ch);
				stat = STAT_Quoted;
			} else if (ch == '\0') {
				valList.push_back(Value(env, field.c_str()));
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
char ReaderStream::NextChar(Signal sig)
{
	int ch = _pStream->GetChar(sig);
	return (ch < 0)? '\0' : static_cast<char>(static_cast<unsigned char>(ch));
}

//-----------------------------------------------------------------------------
// ReaderString
//-----------------------------------------------------------------------------
char ReaderString::NextChar(Signal sig)
{
	return (_strp == _str.end())? '\0' : *_strp++;
}

//-----------------------------------------------------------------------------
// Iterator_reader
//-----------------------------------------------------------------------------
Iterator_reader::~Iterator_reader()
{
}

bool Iterator_reader::DoNext(Environment &env, Signal sig, Value &value)
{
	ValueList &valList = value.InitAsList(env);
	if (_pReader->ReadLine(env, sig, valList)) return true;
	value = Value::Null;
	return false;
}

String Iterator_reader::ToString(Signal sig) const
{
	return String("<iterator:csv.reader>");
}

void Iterator_reader::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

Gura_EndModule(csv, csv)

Gura_RegisterModule(csv)
