//-----------------------------------------------------------------------------
// Gura module: yaml
//-----------------------------------------------------------------------------
#ifndef __GURA_MODULE_YAML_H__
#define __GURA_MODULE_YAML_H__

#include <gura.h>
#define YAML_DECLARE_STATIC
#include <yaml.h>

Gura_BeginModuleHeader(yaml)

//-----------------------------------------------------------------------------
// AnchorMap
//-----------------------------------------------------------------------------
typedef std::map<String, Value> AnchorMap;

//-----------------------------------------------------------------------------
// WriterToStream
//-----------------------------------------------------------------------------
class WriterToStream {
private:
	Signal &_sig;
	Stream &_stream;
public:
	inline WriterToStream(Signal &sig, Stream &stream) : _sig(sig), _stream(stream) {}
	int WriteHandler(unsigned char *buffer, size_t size);
	static int WriteHandlerStub(void *ext, unsigned char *buffer, size_t size);
public:
	static bool Write(Environment &env, Signal &sig, Stream &stream, const Value &value);
};

//-----------------------------------------------------------------------------
// WriterToString
//-----------------------------------------------------------------------------
class WriterToString {
private:
	String &_str;
public:
	inline WriterToString(String &str) : _str(str) {}
	int WriteHandler(unsigned char *buffer, size_t size);
	static int WriteHandlerStub(void *ext, unsigned char *buffer, size_t size);
public:
	static bool Write(Environment &env, Signal &sig, String &str, const Value &value);
};

//-----------------------------------------------------------------------------
// Stocker
//-----------------------------------------------------------------------------
class Stocker {
public:
	virtual void Stock(const Value &value) = 0;
	virtual Value GetValue() = 0;
};

//-----------------------------------------------------------------------------
// StockerList
//-----------------------------------------------------------------------------
typedef std::vector<Stocker *> StockerList;

//-----------------------------------------------------------------------------
// Stocker_Mapping
//-----------------------------------------------------------------------------
class Stocker_Mapping : public Stocker {
private:
	Object_dict *_pObjDict;
	bool _keyFlag;
	Value _valueKey;
public:
	inline Stocker_Mapping(Environment &env) :
		_pObjDict(new Object_dict(env, new ValueDict())), _keyFlag(true) {}
	virtual void Stock(const Value &value);
	virtual Value GetValue();
};

//-----------------------------------------------------------------------------
// Stocker_Sequence
//-----------------------------------------------------------------------------
class Stocker_Sequence : public Stocker {
private:
	Object_list *_pObjList;
public:
	inline Stocker_Sequence(Environment &env) :
					_pObjList(new Object_list(env)) {}
	virtual void Stock(const Value &value);
	virtual Value GetValue();
	inline Object_list *GetListObj() { return _pObjList; }
};

//-----------------------------------------------------------------------------
// Iterator_FromStream
//-----------------------------------------------------------------------------
class Iterator_FromStream : public Iterator {
private:
	Signal &_sig;
	Stream *_pStream;
	yaml_parser_t _parser;
	AnchorMap _anchorMap;
	bool _doneFlag;
public:
	Iterator_FromStream(Signal &sig, Stream *pStream);
	virtual ~Iterator_FromStream();
	virtual Iterator *GetSource();
	virtual bool DoNext(Environment &env, Value &value);
	virtual String ToString() const;
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
	int DoRead(unsigned char *buffer, size_t size, size_t *length);
	static int ReadHandler(void *ext, unsigned char *buffer,
								size_t size, size_t *length);
};

//-----------------------------------------------------------------------------
// Iterator_FromString
//-----------------------------------------------------------------------------
class Iterator_FromString : public Iterator {
private:
	yaml_parser_t _parser;
	AnchorMap _anchorMap;
	bool _doneFlag;
public:
	Iterator_FromString(const char *str);
	virtual ~Iterator_FromString();
	virtual Iterator *GetSource();
	virtual bool DoNext(Environment &env, Value &value);
	virtual String ToString() const;
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
};

//-----------------------------------------------------------------------------
// utilities
//-----------------------------------------------------------------------------
bool WriteStream(Environment &env, Signal &sig, Stream &stream, const Value &value);
const char *GetErrorText(yaml_error_type_e error);

Value ExecParser(Environment &env, Signal &sig,
						yaml_parser_t &parser, AnchorMap &anchorMap);
bool ExecEmitter(Environment &env, Signal &sig, yaml_emitter_t &emitter,
						yaml_encoding_t encoding, const Value &value);

Gura_EndModuleHeader(yaml)

#endif
