//=============================================================================
// Signal
//=============================================================================
#ifndef __GURA_SIGNAL_H__
#define __GURA_SIGNAL_H__

#include "Common.h"
#include "Error.h"

namespace Gura {

class Expr;
class ExprOwner;
class Value;
class SimpleStream;

//-----------------------------------------------------------------------------
// SignalType
//-----------------------------------------------------------------------------
enum SignalType {
	SIGTYPE_None,
	SIGTYPE_ErrorSuspended,
	SIGTYPE_Error,
	SIGTYPE_Terminate,
	SIGTYPE_Break,
	SIGTYPE_Continue,
	SIGTYPE_Return,
	SIGTYPE_SwitchDone,
	SIGTYPE_DetectEncoding,
	SIGTYPE_ReqSaveHistory,
	SIGTYPE_ReqClearHistory,
};

//-----------------------------------------------------------------------------
// Signal
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Signal {
private:
	class Shared {
	public:
		SignalType sigType;
		std::unique_ptr<Value> pValue;
		Error err;
	public:
		Shared();
	};
private:
	Shared *_pShared;
	int _stackLevel;
public:
	Signal();
	Signal(Shared *pShared);
	Signal(const Signal &sig);
	Signal &operator=(const Signal &sig);
	inline bool IsSignalled() const	{
		return _pShared->sigType != SIGTYPE_None &&
									_pShared->sigType != SIGTYPE_ErrorSuspended;
	}
	inline bool IsErrorSuspended() const	{ return _pShared->sigType == SIGTYPE_ErrorSuspended;	}
	inline bool IsError() const				{ return _pShared->sigType == SIGTYPE_Error;			}
	inline bool IsTerminate() const			{ return _pShared->sigType == SIGTYPE_Terminate;		}
	inline bool IsBreak() const				{ return _pShared->sigType == SIGTYPE_Break;			}
	inline bool IsContinue() const			{ return _pShared->sigType == SIGTYPE_Continue;			}
	inline bool IsReturn() const			{ return _pShared->sigType == SIGTYPE_Return;			}
	inline bool IsSwitchDone() const		{ return _pShared->sigType == SIGTYPE_SwitchDone;		}
	inline bool IsDetectEncoding() const	{ return _pShared->sigType == SIGTYPE_DetectEncoding;	}
	inline bool IsReqSaveHistory() const	{ return _pShared->sigType == SIGTYPE_ReqSaveHistory;	}
	inline bool IsReqClearHistory() const	{ return _pShared->sigType == SIGTYPE_ReqClearHistory;	}
	inline void SetType(SignalType sigType) { _pShared->sigType = sigType; }
	inline SignalType GetType() const { return _pShared->sigType; }
	inline const char *GetTypeName() const { return GetTypeName(_pShared->sigType); }
	inline Value &GetValue() const { return *_pShared->pValue; }
	void SetValue(const Value &value) const;
	inline void SuspendError() {
		if (_pShared->sigType == SIGTYPE_Error) _pShared->sigType = SIGTYPE_ErrorSuspended;
	}
	inline void ResumeError() {
		if (_pShared->sigType == SIGTYPE_ErrorSuspended) _pShared->sigType = SIGTYPE_Error;
	}
	inline Error &GetError() { return _pShared->err; }
	inline const Error &GetError() const { return _pShared->err; }
	void ClearSignal();
	void SetSignal(SignalType sigType, const Value &value);
	void AddExprCause(const Expr *pExpr);
	void SetError(ErrorType errType, const char *format, ...);
	void SetErrorV(ErrorType errType,
			const char *format, va_list ap, const char *textPre = "");
	void PrintSignal(SimpleStream &stream);
	static const char *GetTypeName(SignalType sigType);
};

}

#endif
