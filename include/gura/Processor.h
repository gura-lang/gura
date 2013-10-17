#ifndef __GURA_PROCESSOR_H__
#define __GURA_PROCESSOR_H__

#include "Common.h"

namespace Gura {

class Environment;

//-----------------------------------------------------------------------------
// Sequence
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Sequence {
public:
	class GURA_DLLDECLARE PostHandler {
	private:
		int _cntRef;
		AutoPtr<Environment> _pEnv;
	public:
		Gura_DeclareReferenceAccessor(PostHandler)
	public:
		inline PostHandler(Environment *pEnv) : _cntRef(1), _pEnv(pEnv) {}
	protected:
		inline ~PostHandler() {}
	public:
		virtual bool DoPost(Signal sig, const Value &value) = 0;
	};
protected:
	int _cntRef;
	AutoPtr<Environment> _pEnv;
	bool _doneFlag;
	AutoPtr<PostHandler> _pPostHandler;
public:
	Gura_DeclareReferenceAccessor(Sequence)
public:
	Sequence(Environment *pEnv);
protected:
	virtual ~Sequence();
public:
	inline void SetPostHandler(PostHandler *pPostHandler) {
		_pPostHandler.reset(pPostHandler);
	}
	bool Step(Signal sig, Value &result);
	virtual bool DoStep(Signal sig, Value &result) = 0;
	virtual String ToString() const = 0;
	inline bool CheckDone() const { return _doneFlag; }
	static Value Return(Signal sig, Sequence *pSequence);
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
