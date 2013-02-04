//-----------------------------------------------------------------------------
// Gura csv module
//-----------------------------------------------------------------------------
#ifndef __MODULE_CSV_H__
#define __MODULE_CSV_H__
#include <gura.h>

Gura_BeginModule(csv)

Gura_DeclareUserSymbol(format)

//-----------------------------------------------------------------------------
// Object_writer declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(writer);

class Object_writer : public Object {
private:
	AutoPtr<Stream> _pStreamDst;
	String _format;
public:
	Gura_DeclareObjectAccessor(writer)
public:
	Object_writer(Stream *pStreamDst, const char *format);
	virtual ~Object_writer();
	virtual Object *Clone() const;
	virtual bool DoDirProp(Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Signal sig, const Symbol *pSymbol, bool &evaluatedFlag);
	virtual Value DoSetProp(Signal sig,
				const Symbol *pSymbol, const Value &value, bool &evaluatedFlag);
	virtual String ToString(Signal sig, bool exprFlag);
	bool PutValue(Environment &env, Signal sig, const Value &value);
	bool PutLine(Environment &env, Signal sig, const ValueList &valList);
};

//-----------------------------------------------------------------------------
// Reader
//-----------------------------------------------------------------------------
class Reader {
public:
	bool ReadLine(Environment &env, Signal sig, ValueList &valList);
	virtual char NextChar(Signal sig) = 0;
};

//-----------------------------------------------------------------------------
// ReaderStream
//-----------------------------------------------------------------------------
class ReaderStream : public Reader {
private:
	AutoPtr<Stream> _pStream;
public:
	inline ReaderStream(Stream *pStream) : _pStream(pStream) {}
	virtual char NextChar(Signal sig);
};

//-----------------------------------------------------------------------------
// ReaderString
//-----------------------------------------------------------------------------
class ReaderString : public Reader {
private:
	String _str;
	String::iterator _strp;
public:
	inline ReaderString(const String &str) : _str(str) { _strp = _str.begin(); }
	virtual char NextChar(Signal sig);
};

//-----------------------------------------------------------------------------
// Iterator_reader
//-----------------------------------------------------------------------------
class Iterator_reader : public Iterator {
private:
	std::auto_ptr<Reader> _pReader;
public:
	inline Iterator_reader(Reader *pReader) :
								Iterator(false), _pReader(pReader) {}
	virtual ~Iterator_reader();
	virtual bool DoNext(Environment &env, Signal sig, Value &value);
	virtual String ToString(Signal sig) const;
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
};

}}

#endif
