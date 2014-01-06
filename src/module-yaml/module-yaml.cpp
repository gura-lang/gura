//-----------------------------------------------------------------------------
// Gura module: yaml
//-----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleBody(yaml)

//-----------------------------------------------------------------------------
// Gura module functions: yaml
//-----------------------------------------------------------------------------
// yaml.read(stream:stream:r)
Gura_DeclareFunction(read)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Read);
}

Gura_ImplementFunction(read)
{
	Stream &stream = args.GetStream(0);
	Iterator_FromStream *pIterator = new Iterator_FromStream(sig, stream.Reference());
	if (args.IsRsltMulti()) {
		return ReturnIterator(env, sig, args, pIterator);
	}
	Value value;
	pIterator->Next(env, sig, value);
	Iterator::Delete(pIterator);
	return value;
}

// yaml.write(stream:stream:w, obj)
Gura_DeclareFunction(write)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Write);
	DeclareArg(env, "obj", VTYPE_any);
}

Gura_ImplementFunction(write)
{
	if (!WriterToStream::Write(env, sig, args.GetStream(0), args.GetValue(1))) {
		return Value::Null;
	}
	return args.GetThis();
}

// yaml.parse(str:string)
Gura_DeclareFunction(parse)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "str", VTYPE_string);
}

Gura_ImplementFunction(parse)
{
	Iterator_FromString *pIterator = new Iterator_FromString(args.GetString(0));
	if (args.IsRsltMulti()) {
		return ReturnIterator(env, sig, args, pIterator);
	}
	Value value;
	pIterator->Next(env, sig, value);
	Iterator::Delete(pIterator);
	return value;
}

// yaml.compose(obj)
Gura_DeclareFunction(compose)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "obj", VTYPE_any);
}

Gura_ImplementFunction(compose)
{
	String str;
	WriterToString::Write(env, sig, str, args.GetValue(0));
	return Value(str);
}

//-----------------------------------------------------------------------------
// Gura interfaces for Object_stream
//-----------------------------------------------------------------------------
// stream#yamlread()
Gura_DeclareMethod(stream, yamlread)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(stream, yamlread)
{
	Stream &stream = Object_stream::GetThisObj(args)->GetStream();
	Iterator_FromStream *pIterator = new Iterator_FromStream(sig, stream.Reference());
	if (args.IsRsltMulti()) {
		return ReturnIterator(env, sig, args, pIterator);
	}
	Value value;
	pIterator->Next(env, sig, value);
	Iterator::Delete(pIterator);
	return value;
}

// stream#yamlwrite(obj):reduce
Gura_DeclareMethod(stream, yamlwrite)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "obj", VTYPE_any);
}

Gura_ImplementMethod(stream, yamlwrite)
{
	Object_stream *pThis = Object_stream::GetThisObj(args);
	if (!WriterToStream::Write(env, sig, pThis->GetStream(), args.GetValue(0))) {
		return Value::Null;
	}
	return args.GetThis();
}

// Module entry
Gura_ModuleEntry()
{
	// function assignment
	Gura_AssignFunction(read);
	Gura_AssignFunction(write);
	Gura_AssignFunction(parse);
	Gura_AssignFunction(compose);
	// method assignment to stream type
	Gura_AssignMethodTo(VTYPE_stream, stream, yamlread);
	Gura_AssignMethodTo(VTYPE_stream, stream, yamlwrite);
}

Gura_ModuleTerminate()
{
}

//-----------------------------------------------------------------------------
// WriterToStream
//-----------------------------------------------------------------------------
int WriterToStream::WriteHandler(unsigned char *buffer, size_t size)
{
	_stream.Write(_sig, buffer, size);
	return _sig.IsSignalled()? 0 : 1;
}

int WriterToStream::WriteHandlerStub(void *ext, unsigned char *buffer, size_t size)
{
	return reinterpret_cast<WriterToStream *>(ext)->WriteHandler(buffer, size);
}

bool WriterToStream::Write(Environment &env, Signal sig, Stream &stream, const Value &value)
{
	WriterToStream writer(sig, stream);
	yaml_emitter_t emitter;
	::yaml_emitter_initialize(&emitter);
	::yaml_emitter_set_output(&emitter, WriteHandlerStub, &writer);
	ExecEmitter(env, sig, emitter, YAML_UTF8_ENCODING, value);
	::yaml_emitter_delete(&emitter);
	return !sig.IsSignalled();
}

//-----------------------------------------------------------------------------
// WriterToString
//-----------------------------------------------------------------------------
int WriterToString::WriteHandler(unsigned char *buffer, size_t size)
{
	for (char *p = reinterpret_cast<char *>(buffer); size > 0; size--, p++) {
		_str += *p;
	}
	return 1;
}

int WriterToString::WriteHandlerStub(void *ext, unsigned char *buffer, size_t size)
{
	return reinterpret_cast<WriterToString *>(ext)->WriteHandler(buffer, size);
}

bool WriterToString::Write(Environment &env, Signal sig, String &str, const Value &value)
{
	WriterToString writer(str);
	yaml_emitter_t emitter;
	::yaml_emitter_initialize(&emitter);
	::yaml_emitter_set_output(&emitter, WriteHandlerStub, &writer);
	ExecEmitter(env, sig, emitter, YAML_UTF8_ENCODING, value);
	::yaml_emitter_delete(&emitter);
	return !sig.IsSignalled();
}

//-----------------------------------------------------------------------------
// Stocker_Mapping
//-----------------------------------------------------------------------------
void Stocker_Mapping::Stock(const Value &value)
{
	if (_keyFlag) {
		_valueKey = value;
	} else {
		_pObjDict->GetDict()[_valueKey] = value;
	}
	_keyFlag = !_keyFlag;
}

Value Stocker_Mapping::GetValue()
{
	return Value(_pObjDict);
}

//-----------------------------------------------------------------------------
// Stocker_Sequence
//-----------------------------------------------------------------------------
void Stocker_Sequence::Stock(const Value &value)
{
	_pObjList->GetList().push_back(value);
}

Value Stocker_Sequence::GetValue()
{
	return Value(_pObjList);
}

//-----------------------------------------------------------------------------
// Iterator_FromStream
//-----------------------------------------------------------------------------
Iterator_FromStream::Iterator_FromStream(Signal sig, Stream *pStream) :
			Iterator(false), _sig(sig), _pStream(pStream), _doneFlag(false)
{
	::yaml_parser_initialize(&_parser);
	::yaml_parser_set_input(&_parser, ReadHandler, this);
}

Iterator_FromStream::~Iterator_FromStream()
{
	Stream::Delete(_pStream);
	::yaml_parser_delete(&_parser);
}

Iterator *Iterator_FromStream::GetSource()
{
	return NULL;
}

bool Iterator_FromStream::DoNext(Environment &env, Signal sig, Value &value)
{
	if (_doneFlag) return false;
	value = ExecParser(env, sig, _parser, _anchorMap);
	_doneFlag = value.IsInvalid();
	return !_doneFlag;
}

String Iterator_FromStream::ToString() const
{
	return String("<iterator:yaml.fromstream>");
}

void Iterator_FromStream::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

int Iterator_FromStream::DoRead(unsigned char *buffer, size_t size, size_t *length)
{
	*length = _pStream->Read(_sig, buffer, size);
	return _sig.IsSignalled()? 0 : 1;
}

int Iterator_FromStream::ReadHandler(void *ext,
		unsigned char *buffer, size_t size, size_t *length)
{
	return reinterpret_cast<Iterator_FromStream *>(ext)->DoRead(buffer, size, length);
}

//-----------------------------------------------------------------------------
// Iterator_FromString
//-----------------------------------------------------------------------------
Iterator_FromString::Iterator_FromString(const char *str) :
									Iterator(false), _doneFlag(false)
{
	::yaml_parser_initialize(&_parser);
	::yaml_parser_set_input_string(&_parser,
			reinterpret_cast<const unsigned char *>(str), ::strlen(str));
}

Iterator_FromString::~Iterator_FromString()
{
	::yaml_parser_delete(&_parser);
}

Iterator *Iterator_FromString::GetSource()
{
	return NULL;
}

bool Iterator_FromString::DoNext(Environment &env, Signal sig, Value &value)
{
	if (_doneFlag) return false;
	value = ExecParser(env, sig, _parser, _anchorMap);
	_doneFlag = value.IsInvalid();
	return !_doneFlag;
}

String Iterator_FromString::ToString() const
{
	return String("<iterator:yaml.fromstring>");
}

void Iterator_FromString::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

//-----------------------------------------------------------------------------
// Parser body
//-----------------------------------------------------------------------------
Value ExecParser(Environment &env, Signal sig,
							yaml_parser_t &parser, AnchorMap &anchorMap)
{
	Value result;
	StockerList stockerList;
	yaml_event_t event;
	for (bool contFlag = true; contFlag; ) {
		if (!::yaml_parser_parse(&parser, &event)) {
			sig.SetError(ERR_FormatError, "%s", GetErrorText(parser.error));
			break;
		}
		if (event.type == YAML_STREAM_START_EVENT) {
			//::printf("STREAM_START\n");
			yaml_encoding_t encoding = event.data.stream_start.encoding;
			
		} else if (event.type == YAML_DOCUMENT_START_EVENT) {
			yaml_version_directive_t *version_directive =
							event.data.document_start.version_directive;
			yaml_tag_directive_t *tag_start =
							event.data.document_start.tag_directives.start;
			yaml_tag_directive_t *tag_end =
							event.data.document_start.tag_directives.end;
			int implicit = event.data.document_start.implicit;
			//::printf("DOCUMENT_START %p %p %p\n",
			//					version_directive, tag_start, tag_end);
			//tag_start->handle;
			//tag_start->prefix;
			//tag_end->handle;
			//tag_end->prefix;
		} else if (event.type == YAML_SCALAR_EVENT ||
					event.type == YAML_SEQUENCE_START_EVENT ||
					event.type == YAML_MAPPING_START_EVENT) {
			yaml_char_t *anchor = NULL;
			yaml_char_t *tag = NULL;
			Value value;
			Stocker *pStockerTop =
						stockerList.empty()? NULL : stockerList.back();
			if (event.type == YAML_SCALAR_EVENT) {
				anchor = event.data.scalar.anchor;
				tag = event.data.scalar.tag;
				yaml_char_t *valueRaw = event.data.scalar.value;
				size_t length = event.data.scalar.length;
				int plain_implicit = event.data.scalar.plain_implicit;
				int quoted_implicit = event.data.scalar.quoted_implicit;
				yaml_scalar_style_t style = event.data.scalar.style;
				String valueStr(reinterpret_cast<char *>(valueRaw), length);
				//::printf("SCALAR %s %s %s\n", anchor, tag, valueStr.c_str());
				value = Value(valueStr);
			} else if (event.type == YAML_SEQUENCE_START_EVENT) {
				anchor = event.data.sequence_start.anchor;
				tag = event.data.sequence_start.tag;
				int implicit = event.data.sequence_start.implicit;
				yaml_sequence_style_t style = event.data.sequence_start.style;
				//::printf("SEQUENCE_START %s %s\n", anchor, tag);
				Stocker *pStocker = new Stocker_Sequence(env);
				stockerList.push_back(pStocker);
				value = pStocker->GetValue();
			} else { // event.type == YAML_MAPPING_START_EVENT
				anchor = event.data.mapping_start.anchor;
				tag = event.data.mapping_start.tag;
				int implicit = event.data.mapping_start.implicit;
				yaml_mapping_style_t style = event.data.mapping_start.style;
				//::printf("MAPPING_START %s %s\n", anchor, tag);
				Stocker *pStocker = new Stocker_Mapping(env);
				stockerList.push_back(pStocker);
				value = pStocker->GetValue();
			}
			if (pStockerTop == NULL) {
				result = value;
			} else {
				pStockerTop->Stock(value);
			}
			if (anchor != NULL) {
				anchorMap[reinterpret_cast<char *>(anchor)] = value;
			}
		} else if (event.type == YAML_ALIAS_EVENT) {
			yaml_char_t *anchor = event.data.alias.anchor;
			//::printf("ALIAS\ %s\n", anchor);
			AnchorMap::iterator iter =
							anchorMap.find(reinterpret_cast<char *>(anchor));
			if (iter == anchorMap.end()) {
				sig.SetError(ERR_FormatError, "undefined anchor %s", anchor);
				contFlag = false;
			} else if (stockerList.empty()) {
				// something's wrong
			} else {
				stockerList.back()->Stock(iter->second);
			}
		} else if (event.type == YAML_STREAM_END_EVENT) {
			//::printf("STREAM_END\n");
			contFlag = false;
		} else if (event.type == YAML_DOCUMENT_END_EVENT) {
			int implicit = event.data.document_end.implicit;
			//::printf("DOCUMENT_END\n");
			contFlag = false;
		} else if (event.type == YAML_SEQUENCE_END_EVENT) {
			//::printf("SEQUENCE_END\n");
			stockerList.pop_back();
		} else if (event.type == YAML_MAPPING_END_EVENT) {
			//::printf("MAPPING_END\n");
			stockerList.pop_back();
		} else {
			sig.SetError(ERR_FormatError, "unknown event %d\n", event.type);
			contFlag = false;
		}
		::yaml_event_delete(&event);
	}
	if (sig.IsSignalled()) return Value::Null;
	return result;
}

//-----------------------------------------------------------------------------
// Emitter body
//-----------------------------------------------------------------------------
bool ExecEmitterSub(Environment &env, Signal sig,
								yaml_emitter_t &emitter, const Value &value);

bool ExecEmitter(Environment &env, Signal sig, yaml_emitter_t &emitter,
								yaml_encoding_t encoding, const Value &value)
{
	do {
		yaml_event_t event;
		::yaml_stream_start_event_initialize(&event, encoding);
		if (!::yaml_emitter_emit(&emitter, &event)) {
			sig.SetError(ERR_FormatError, "%s", GetErrorText(emitter.error));
			return false;
		}
	} while (0);
	do {
		yaml_version_directive_t *version_directive = NULL;
		yaml_tag_directive_t *tag_start = NULL;
		yaml_tag_directive_t *tag_end = NULL;
		int implicit = 1;
		yaml_event_t event;
		::yaml_document_start_event_initialize(&event,
								version_directive, tag_start, tag_end, implicit);
		if (!::yaml_emitter_emit(&emitter, &event)) {
			sig.SetError(ERR_FormatError, "%s", GetErrorText(emitter.error));
			return false;
		}
	} while (0);
	if (!ExecEmitterSub(env, sig, emitter, value)) return false;
	do {
		int implicit = 1;
		yaml_event_t event;
		::yaml_document_end_event_initialize(&event, implicit);
		if (!::yaml_emitter_emit(&emitter, &event)) {
			sig.SetError(ERR_FormatError, "%s", GetErrorText(emitter.error));
			return false;
		}
	} while (0);
	do {
		yaml_event_t event;
		::yaml_stream_end_event_initialize(&event);
		if (!::yaml_emitter_emit(&emitter, &event)) {
			sig.SetError(ERR_FormatError, "%s", GetErrorText(emitter.error));
			return false;
		}
	} while (0);
	return true;
}

bool ExecEmitterSub(Environment &env, Signal sig,
								yaml_emitter_t &emitter, const Value &value)
{
	if (value.Is_list()) {
		do {
			yaml_char_t *anchor = NULL;
			yaml_char_t *tag = NULL;
			int implicit = 0;
			yaml_sequence_style_t style = YAML_ANY_SEQUENCE_STYLE;
			yaml_event_t event;
			::yaml_sequence_start_event_initialize(&event, anchor, tag, implicit, style);
			if (!::yaml_emitter_emit(&emitter, &event)) {
				sig.SetError(ERR_FormatError, "%s", GetErrorText(emitter.error));
				return false;
			}
		} while (0);
		foreach_const (ValueList, pValue, value.GetList()) {
			if (!ExecEmitterSub(env, sig, emitter, *pValue)) return false;
		}
		do {
			yaml_event_t event;
			::yaml_sequence_end_event_initialize(&event);
			if (!::yaml_emitter_emit(&emitter, &event)) {
				sig.SetError(ERR_FormatError, "%s", GetErrorText(emitter.error));
				return false;
			}
		} while (0);
	} else if (value.Is_dict()) {
		do {
			yaml_char_t *anchor = NULL;
			yaml_char_t *tag = NULL;
			int implicit = 0;
			yaml_mapping_style_t style = YAML_ANY_MAPPING_STYLE;
			yaml_event_t event;
			::yaml_mapping_start_event_initialize(&event, anchor, tag, implicit, style);
			if (!::yaml_emitter_emit(&emitter, &event)) {
				return false;
			}
		} while (0);
		foreach_const (ValueDict, iter, value.GetDict()) {
			if (!ExecEmitterSub(env, sig, emitter, iter->first)) return false;
			if (!ExecEmitterSub(env, sig, emitter, iter->second)) return false;
		}
		do {
			yaml_event_t event;
			::yaml_mapping_end_event_initialize(&event);
			if (!::yaml_emitter_emit(&emitter, &event)) {
				sig.SetError(ERR_FormatError, "%s", GetErrorText(emitter.error));
				return false;
			}
		} while (0);
	} else {
		String str = value.ToString(false);
		if (sig.IsSignalled()) return false;
		yaml_char_t *anchor = NULL;
		yaml_char_t *tag = NULL;
		yaml_char_t *valueRaw =
			reinterpret_cast<unsigned char *>(const_cast<char *>(str.c_str()));
		size_t length = str.size();
		int plain_implicit = 1;
		int quoted_implicit = 1;
		yaml_scalar_style_t style = YAML_ANY_SCALAR_STYLE;
		yaml_event_t event;
		::yaml_scalar_event_initialize(&event,
			anchor, tag, valueRaw, length, plain_implicit, quoted_implicit, style);
		if (!::yaml_emitter_emit(&emitter, &event)) {
			sig.SetError(ERR_FormatError, "%s", GetErrorText(emitter.error));
			return false;
		}
	}
	return true;
}

//-----------------------------------------------------------------------------
// utilities
//-----------------------------------------------------------------------------
const char *GetErrorText(yaml_error_type_e error)
{
	static const struct {
		yaml_error_type_e error;
		const char *str;
	} tbl[] = {
		{ YAML_MEMORY_ERROR,	"Cannot allocate or reallocate a block of memory."	},
		{ YAML_READER_ERROR,	"Cannot read or decode the input stream."			},
		{ YAML_SCANNER_ERROR,	"Cannot scan the input stream."						},
		{ YAML_PARSER_ERROR,	"Cannot parse the input stream."					},
		{ YAML_COMPOSER_ERROR,	"Cannot compose a YAML document."					},
		{ YAML_WRITER_ERROR,	"Cannot write to the output stream."				},
		{ YAML_EMITTER_ERROR,	"Cannot emit a YAML stream."						},
	};
	for (int i = 0; i < ArraySizeOf(tbl); i++) {
		if (tbl[i].error == error) return tbl[i].str;
	}
	return "unknown error";
}

Gura_EndModuleBody(yaml, yaml)

Gura_RegisterModule(yaml)
