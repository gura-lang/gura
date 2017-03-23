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
// Properties of csv.writer
//-----------------------------------------------------------------------------
// csv.writer#format
Gura_DeclareProperty_RW(writer, format)
{
	SetPropAttr(VTYPE_string);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(writer, format)
{
	Object_writer *pThis = Object_writer::GetObject(valueThis);
	return Value(pThis->GetFormat());
}

Gura_ImplementPropertySetter(writer, format)
{
	Object_writer *pThis = Object_writer::GetObject(valueThis);
	pThis->SetFormat(value.GetString());
	return value;
}

//-----------------------------------------------------------------------------
// Methods of csv.writer
//-----------------------------------------------------------------------------
// csv.writer#write(fields+):map:reduce
Gura_DeclareMethod(writer, write)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "fields", VTYPE_any, OCCUR_OnceOrMore);
	AddHelp(
		Gura_Symbol(en),
		"Writes values in CSV format.\n"
		"\n"
		"The argument `fields` takes `string`, `number` or `complex` values\n"
		"that are to be put out in a row.\n");
}

Gura_ImplementMethod(writer, write)
{
	Signal &sig = env.GetSignal();
	Object_writer *pThis = Object_writer::GetObjectThis(arg);
	if (!pThis->PutLine(env, arg.GetList(0))) return Value::Nil;
	return arg.GetValueThis();
}

//-----------------------------------------------------------------------------
// Implementation of csv.writer
//-----------------------------------------------------------------------------
Gura_ImplementUserClassWithCast(writer)
{
	// Assignment of property
	Gura_AssignProperty(writer, format);
	// Assignment of method
	Gura_AssignMethod(writer, write);
}

Gura_ImplementCastFrom(writer)
{
	if (value.Is_stream()) {
		const char *format = DEFAULT_FORMAT;
		value = Value(new Object_writer(value.GetStream().Reference(), format));
		return true;
	}
	return false;
}

Gura_ImplementCastTo(writer)
{
	return false;
}

//-----------------------------------------------------------------------------
// Gura module functions: csv
//-----------------------------------------------------------------------------
// csv.parse(str:string):map {block?}
Gura_DeclareFunction(parse)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "str", VTYPE_string);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Creates an iterator that parses a text in CSV format that is contained in the specified string\n"
		"and returns a list of fields as its each element.\n"
		"\n"
		GURA_HELPTEXT_ITERATOR_en());
}

Gura_ImplementFunction(parse)
{
	Iterator *pIterator = new Iterator_reader(new ReaderString(arg.GetStringSTL(0)));
	return ReturnIterator(env, arg, pIterator);
}

// csv.read(stream:stream:r) {block?}
Gura_DeclareFunction(read)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Read);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Creates an iterator that parses a text in CSV format from the specified stream\n"
		"and returns a list of fields as its each element.\n"
		"\n"
		GURA_HELPTEXT_ITERATOR_en());
}

Gura_ImplementFunction(read)
{
	Object_stream *pObjStream = Object_stream::GetObject(arg, 0);
	Iterator *pIterator = new Iterator_reader(new ReaderStream(
									pObjStream->GetStream().Reference()));
	return ReturnIterator(env, arg, pIterator);
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
		Gura_Symbol(en),
		"Creates a `csv.writer` instance that provides methods\n"
		"to write CSV text to the specified stream.\n"
		"\n"
		"The argument `format` specifies a printf-style format string\n"
		"that is used to convert a `number` and `complex` value to a string.\n");
}

Gura_ImplementFunction(writer)
{
	Object_stream *pObjStream = Object_stream::GetObject(arg, 0);
	const char *format = arg.Is_string(1)? arg.GetString(1) : DEFAULT_FORMAT;
	Object_writer *pObj = new Object_writer(
						pObjStream->GetStream().Reference(), format);
	return ReturnValue(env, arg, Value(pObj));
}

//-----------------------------------------------------------------------------
// Gura interfaces for stream
//-----------------------------------------------------------------------------
// stream#read@csv() {block?}
Gura_DeclareMethodAlias(stream, read_csv, "read@csv")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Creates an iterator that parses a text in CSV format from the specified stream\n"
		"and returns a list of fields as its each element.\n"
		"\n"
		GURA_HELPTEXT_ITERATOR_en());
}

Gura_ImplementMethod(stream, read_csv)
{
	Object_stream *pThis = Object_stream::GetObjectThis(arg);
	Iterator *pIterator = new Iterator_reader(new ReaderStream(
							pThis->GetStream().Reference()));
	return ReturnIterator(env, arg, pIterator);
}

// stream#writer@csv(format?:string) {block?}
Gura_DeclareMethodAlias(stream, writer_csv, "writer@csv")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "format", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Creates a `csv.writer` instance that provides methods\n"
		"to write CSV text to the target stream.\n"
		"\n"
		"The argument `format` specifies a printf-style format string\n"
		"that is used to convert a `number` and `complex` value to a string.\n");
}

Gura_ImplementMethod(stream, writer_csv)
{
	Object_stream *pThis = Object_stream::GetObjectThis(arg);
	const char *format = arg.Is_string(1)? arg.GetString(1) : DEFAULT_FORMAT;
	Object_writer *pObj = new Object_writer(pThis->GetStream().Reference(), format);
	return ReturnValue(env, arg, Value(pObj));
}

//-----------------------------------------------------------------------------
// Gura interfaces for array
//-----------------------------------------------------------------------------
// array.read@csv(stream:stream) {block?}
Gura_DeclareClassMethodAlias(array, read_csv, "read@csv")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Reads CSV text from `stream` and creates an `array` instance.");
}

Gura_ImplementMethod(array, read_csv)
{
	typedef Double T_Elem;
	size_t sizeCol = 0;
	std::unique_ptr<Reader> pReader(new ReaderStream(arg.GetStream(0).Reference()));
	ValueList valList;
	for (;;) {
		Value value;
		Object_list *pObjList = value.InitAsList(env);
		if (!pReader->ReadLine(env, pObjList->GetListForModify())) {
			if (env.IsSignalled()) return Value::Nil;
			break;
		}
		size_t size = pObjList->GetList().size();
		if (sizeCol < size) sizeCol = size;
		valList.push_back(value);
	}
	size_t sizeRow = valList.size();
	AutoPtr<ArrayT<T_Elem> > pArrayT(new ArrayT<T_Elem>(sizeRow, sizeCol));
	pArrayT->FillZero();
	T_Elem *pRow = pArrayT->GetPointer();
	foreach_const (ValueList, pValueRow, valList) {
		T_Elem *p = pRow;
		foreach_const (ValueList, pValue, pValueRow->GetList()) {
			bool successFlag = false;
			Number num = pValue->ToNumber(false, successFlag);
			if (!successFlag) {
				env.SetError(ERR_ValueError, "failed to convert to a number value");
				return Value::Nil;
			}
			*p++ = static_cast<T_Elem>(num);
		}
		pRow += sizeCol;
	}
	return ReturnValue(env, arg, new Object_array(env, pArrayT.release()));
}

#if 0
// array#write@csv(stream:stream:w, format?:string):void
Gura_DeclareMethodAlias(array, write_csv, "write@csv")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Write);
	DeclareArg(env, "format", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Writes the content of `array` instance to the specified `stream` in CSV format.");
}

Gura_ImplementMethod(array, write_csv)
{
	Array *pArray = Object_array::GetObjectThis(arg)->GetArray();
	Signal &sig = env.GetSignal();
	Stream &stream = arg.GetStream(0);
	const char *format = arg.IsValid(1)? arg.GetString(1) : DEFAULT_FORMAT;
	//T_Elem *pRow = pArrayT->GetPointer();
	String str;
	str = Formatter::Format(sig, format, 0);
	return Value::Nil;
}
#endif

//-----------------------------------------------------------------------------
// Module Entries
//-----------------------------------------------------------------------------
Gura_ModuleValidate()
{
	return Version::CheckCoreVersion(GURA_VERSION, nullptr);
}

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
	// method assignment to array type
	Gura_AssignMethodTo(VTYPE_array, array, read_csv);
	//Gura_AssignMethodTo(VTYPE_array, array, write_csv);
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
	Object_list *pObjList = value.InitAsList(env);
	if (_pReader->ReadLine(env, pObjList->GetListForModify())) {
		pObjList->SetValueType(VTYPE_string);
		return true;
	}
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
