#ifndef __GURA_PROCESSOR_H__
#define __GURA_PROCESSOR_H__

#include "Common.h"

namespace Gura {

class Environment;

class SeqPostHandler;
class Object_list;

//-----------------------------------------------------------------------------
// Sequence
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Sequence {
public:
protected:
	int _cntRef;
	AutoPtr<Environment> _pEnv;
	bool _doneFlag;
	AutoPtr<SeqPostHandler> _pSeqPostHandler;
public:
	Gura_DeclareReferenceAccessor(Sequence)
public:
	Sequence(Environment *pEnv);
protected:
	virtual ~Sequence();
public:
	inline void SetSeqPostHandler(SeqPostHandler *pSeqPostHandler) {
		_pSeqPostHandler.reset(pSeqPostHandler);
	}
	bool Step(Signal sig, Value &result);
	virtual bool DoStep(Signal sig, Value &result) = 0;
	virtual String ToString() const = 0;
	inline bool CheckDone() const { return _doneFlag; }
	static Value Return(Signal sig, Sequence *pSequence);
};

//-----------------------------------------------------------------------------
// SeqPostHandler
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE SeqPostHandler {
private:
	int _cntRef;
	AutoPtr<Environment> _pEnv;
	bool _eachFlag;
public:
	Gura_DeclareReferenceAccessor(SeqPostHandler)
public:
	inline SeqPostHandler(Environment *pEnv, bool eachFlag = false) :
							_cntRef(1), _pEnv(pEnv), _eachFlag(eachFlag) {}
protected:
	virtual ~SeqPostHandler();
public:
	inline bool GetEachFlag() const { return _eachFlag; }
	virtual bool DoPost(Signal sig, const Value &value) = 0;
};

//-----------------------------------------------------------------------------
// SeqPostHandler_StoreList
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE SeqPostHandler_StoreList : public SeqPostHandler {
private:
	AutoPtr<Object_list> _pObjList;
public:
	inline SeqPostHandler_StoreList(Environment *pEnv, bool eachFlag, Object_list *pObjList) :
						SeqPostHandler(pEnv, eachFlag), _pObjList(pObjList) {}
	virtual bool DoPost(Signal sig, const Value &result);
};

//-----------------------------------------------------------------------------
// SequenceStack
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE SequenceStack : public std::list<Sequence *> {
public:
	~SequenceStack();
	void Clear();
};

//-----------------------------------------------------------------------------
// Processor
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Processor {
protected:
	int _cntRef;
	SequenceStack _sequenceStack;
public:
	Gura_DeclareReferenceAccessor(Processor)
public:
	Processor();
	bool Step(Signal sig, Value &value);
	inline void PushSequence(Sequence *pSequence) { _sequenceStack.push_back(pSequence); }
	inline bool CheckDone() const { return _sequenceStack.empty(); }
	Value Run(Signal sig);
};

}

#endif
