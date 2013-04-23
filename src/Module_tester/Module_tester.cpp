//-----------------------------------------------------------------------------
// Gura tester module
//-----------------------------------------------------------------------------
#include "Module_tester.h"

Gura_BeginModule(tester)

//-----------------------------------------------------------------------------
// StreamFIFO
//-----------------------------------------------------------------------------
class StreamFIFO : public Stream {
private:
	AutoPtr<Memory> _pMemory;
	size_t _offsetWrite;
	size_t _offsetRead;
	size_t _bytesAvail;
	bool _writeWaitFlag;
	bool _readWaitFlag;
	bool _writeDoneFlag;
	std::auto_ptr<OAL::Semaphore> _pSemaphore;
	std::auto_ptr<OAL::Event> _pEventWrite;
	std::auto_ptr<OAL::Event> _pEventRequest;
public:
	StreamFIFO(Environment &env, Signal sig, size_t bytesBuff);
	virtual const char *GetName() const;
	virtual const char *GetIdentifier() const;
	virtual bool GetAttribute(Attribute &attr);
	virtual bool SetAttribute(const Attribute &attr);
	virtual size_t DoRead(Signal sig, void *buff, size_t len);
	virtual size_t DoWrite(Signal sig, const void *buff, size_t len);
	virtual bool DoSeek(Signal sig, long offset, size_t offsetPrev, SeekMode seekMode);
	virtual bool DoFlush(Signal sig);
	virtual bool DoClose(Signal sig);
	virtual size_t DoGetSize();
	void SetWriteDoneFlag();
	void Print();
};

void StreamFIFO::Print()
{
	::printf("offsetWrite:%d, offsetRead:%d, bytesAvail:%d\n", _offsetWrite, _offsetRead, _bytesAvail);
}

//-----------------------------------------------------------------------------
// StreamFIFO
//-----------------------------------------------------------------------------
StreamFIFO::StreamFIFO(Environment &env, Signal sig, size_t bytesBuff) :
		Stream(env, sig, ATTR_Readable | ATTR_Writable),
		_pMemory(new MemoryHeap(bytesBuff)),
		_offsetWrite(0), _offsetRead(0), _bytesAvail(0),
		_writeWaitFlag(false), _readWaitFlag(false), _writeDoneFlag(false),
		_pSemaphore(new OAL::Semaphore()),
		_pEventWrite(new OAL::Event()), _pEventRequest(new OAL::Event())
{
}

const char *StreamFIFO::GetName() const
{
	return "FIFO";
}

const char *StreamFIFO::GetIdentifier() const
{
	return NULL;
}

bool StreamFIFO::GetAttribute(Attribute &attr)
{
	return false;
}

bool StreamFIFO::SetAttribute(const Attribute &attr)
{
	return false;
}

size_t StreamFIFO::DoRead(Signal sig, void *buff, size_t len)
{
	char *buffp = reinterpret_cast<char *>(buff);
	_pSemaphore->Wait();
	size_t offset = 0;
	while (offset < len) {
		size_t bytesSpace = len - offset;
		if (_bytesAvail == 0) {
			if (offset > 0) break;
			_readWaitFlag = true;
			_pSemaphore->Release();
			_pEventWrite->Wait();
			_pSemaphore->Wait();
			_readWaitFlag = false;
		}
		if (_bytesAvail > 0) {
			size_t bytesCopy = ChooseMin(bytesSpace, _bytesAvail);
			if (_offsetRead + bytesCopy <= _pMemory->GetSize()) {
				::memcpy(buffp + offset, _pMemory->GetPointer(_offsetRead), bytesCopy);
				offset += bytesCopy;
				_offsetRead += bytesCopy;
				_bytesAvail -= bytesCopy;
				if (_offsetRead == _pMemory->GetSize()) _offsetRead = 0;
			} else {
				size_t bytesPart = _pMemory->GetSize() - _offsetRead;
				::memcpy(buffp + offset, _pMemory->GetPointer(_offsetRead), bytesPart);
				::memcpy(buffp + offset + bytesPart, _pMemory->GetPointer(), bytesCopy - bytesPart);
				offset += bytesCopy;
				_offsetRead = bytesCopy - bytesPart;
				_bytesAvail -= bytesCopy;
			}
		}
		if (_writeDoneFlag) {
			_pSemaphore->Release();
			return offset;
		}
	}
	_pSemaphore->Release();
	if (_writeWaitFlag) _pEventRequest->Notify();
	return offset;
}

size_t StreamFIFO::DoWrite(Signal sig, const void *buff, size_t len)
{
	const char *buffp = reinterpret_cast<const char *>(buff);
	_pSemaphore->Wait();
	for (size_t offset = 0; offset < len; ) {
		size_t bytesRest = len - offset;
		if (_bytesAvail == _pMemory->GetSize()) {
			_writeWaitFlag = true;
			_pSemaphore->Release();
			_pEventRequest->Wait();
			_pSemaphore->Wait();
			_writeWaitFlag = false;
		}
		size_t bytesSpace = _pMemory->GetSize() - _bytesAvail;
		size_t bytesCopy = ChooseMin(bytesRest, bytesSpace);
		if (_offsetWrite + bytesCopy <= _pMemory->GetSize()) {
			::memcpy(_pMemory->GetPointer(_offsetWrite), buffp + offset, bytesCopy);
			offset += bytesCopy;
			_offsetWrite += bytesCopy;
			_bytesAvail += bytesCopy;
			if (_offsetRead == _pMemory->GetSize()) _offsetRead = 0;
		} else {
			size_t bytesPart = _pMemory->GetSize() - _offsetWrite;
			::memcpy(_pMemory->GetPointer(_offsetWrite), buffp + offset, bytesPart);
			::memcpy(_pMemory->GetPointer(), buffp + offset + bytesPart, bytesCopy - bytesPart);
			offset += bytesCopy;
			_offsetWrite = bytesCopy - bytesPart;
			_bytesAvail += bytesCopy;
		}
	}
	_pSemaphore->Release();
	if (_readWaitFlag) _pEventWrite->Notify();
	return len;
}

bool StreamFIFO::DoSeek(Signal sig, long offset, size_t offsetPrev, SeekMode seekMode)
{
	return false;
}

bool StreamFIFO::DoFlush(Signal sig)
{
	return true;
}

bool StreamFIFO::DoClose(Signal sig)
{
	return true;
}

size_t StreamFIFO::DoGetSize()
{
	return 0;
}

void StreamFIFO::SetWriteDoneFlag()
{
	_writeDoneFlag = true;
	_pEventWrite->Notify();
}

//-----------------------------------------------------------------------------
// Thread1
//-----------------------------------------------------------------------------
class Thread1 : public OAL::Thread {
private:
	Signal _sig;
	AutoPtr<StreamFIFO> _pStreamFIFO;
public:
	inline Thread1(Signal sig, StreamFIFO *pStreamFIFO) :
								_sig(sig), _pStreamFIFO(pStreamFIFO) {}
	virtual void Run();
};

void Thread1::Run()
{
	unsigned char buff[1024];
	::printf("Thread1 starts\n");
	int num = 0;
	for (;;) {
		//size_t bytesToRead = static_cast<int>(RandomGenerator::Real2() * 1024) + 1;
		size_t bytesToRead = 32;
		size_t bytesRead = _pStreamFIFO->Read(_sig, buff, bytesToRead);
		for (size_t i = 0; i < bytesRead; i++, num++) {
			::printf(" %02x", buff[i]);
			if (buff[i] != (num & 0xff)) {
				::printf("error\n");
				_pStreamFIFO->Print();
			}
		}
		//::printf("\n");
	}
}

//-----------------------------------------------------------------------------
// Gura module functions: tester
//-----------------------------------------------------------------------------
// tester.run()
Gura_DeclareFunction(run)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), "run tester.");
}

Gura_ImplementFunction(run)
{
	RandomGenerator::Initialize(0);
	unsigned char buff[1024];
	AutoPtr<StreamFIFO> pStreamFIFO(new StreamFIFO(env, sig, 256));
	OAL::Thread *pThread1 = new Thread1(sig,
			dynamic_cast<StreamFIFO *>(Stream::Reference(pStreamFIFO.get())));
	pThread1->Start();
	int num = 0;
	for (;;) {
		size_t bytesToWrite = static_cast<int>(RandomGenerator::Real2() * 1024) + 1;
		for (size_t i = 0; i < bytesToWrite; i++, num++) {
			buff[i] = static_cast<unsigned char>(num);
		}
		::printf("Write %d\n", bytesToWrite);
		pStreamFIFO->Write(sig, buff, bytesToWrite);
		::printf("Written\n");
		pStreamFIFO->Print();
		//OAL::Sleep(1);
	}
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Module entry
//-----------------------------------------------------------------------------
Gura_ModuleEntry()
{
	// function assignment
	Gura_AssignFunction(run);
}

Gura_ModuleTerminate()
{
}

Gura_EndModule(tester, tester)

Gura_RegisterModule(tester)
