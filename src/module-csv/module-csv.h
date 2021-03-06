//-----------------------------------------------------------------------------
// Gura module: csv
//-----------------------------------------------------------------------------
#ifndef __GURA_MODULE_CSV_H__
#define __GURA_MODULE_CSV_H__
#include <gura.h>

Gura_BeginModuleHeader(csv)

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
	virtual String ToString(bool exprFlag);
	bool PutValue(Environment &env, const Value &value);
	bool PutLine(Environment &env, const ValueList &valList);
	const String &GetFormat() const { return _format; }
	void SetFormat(const String &format) { _format = format; }
};

//-----------------------------------------------------------------------------
// Reader
//-----------------------------------------------------------------------------
class Reader {
public:
	bool ReadLine(Environment &env, ValueList &valList);
	virtual char NextChar(Signal &sig) = 0;
};

//-----------------------------------------------------------------------------
// ReaderStream
//-----------------------------------------------------------------------------
class ReaderStream : public Reader {
private:
	AutoPtr<Stream> _pStream;
public:
	inline ReaderStream(Stream *pStream) : _pStream(pStream) {}
	virtual char NextChar(Signal &sig);
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
	virtual char NextChar(Signal &sig);
};

//-----------------------------------------------------------------------------
// Iterator_reader
//-----------------------------------------------------------------------------
class Iterator_reader : public Iterator {
private:
	std::unique_ptr<Reader> _pReader;
public:
	inline Iterator_reader(Reader *pReader) :
								Iterator(Finite), _pReader(pReader) {}
	virtual Iterator *GetSource();
	virtual bool DoNext(Environment &env, Value &value);
	virtual String ToString() const;
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
};

Gura_EndModuleHeader(csv)

#endif
