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
enum {
	SIGTYPE_None = 0,
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
	ULong _sigType;
	std::unique_ptr<Value> _pValue;
	Error _err;
public:
	Signal();
private:
	inline Signal(const Signal &sig) {}
	inline void operator=(const Signal &sig) {}
public:
	inline bool IsSignalled() const	{
		return _sigType != SIGTYPE_None &&
									_sigType != SIGTYPE_ErrorSuspended;
	}
	inline bool IsErrorSuspended() const	{ return _sigType == SIGTYPE_ErrorSuspended;	}
	inline bool IsError() const				{ return _sigType == SIGTYPE_Error;			}
	inline bool IsTerminate() const			{ return _sigType == SIGTYPE_Terminate;		}
	inline bool IsBreak() const				{ return _sigType == SIGTYPE_Break;			}
	inline bool IsContinue() const			{ return _sigType == SIGTYPE_Continue;			}
	inline bool IsReturn() const			{ return _sigType == SIGTYPE_Return;			}
	inline bool IsSwitchDone() const		{ return _sigType == SIGTYPE_SwitchDone;		}
	inline bool IsDetectEncoding() const	{ return _sigType == SIGTYPE_DetectEncoding;	}
	inline bool IsReqSaveHistory() const	{ return _sigType == SIGTYPE_ReqSaveHistory;	}
	inline bool IsReqClearHistory() const	{ return _sigType == SIGTYPE_ReqClearHistory;	}
	inline void SetType(ULong sigType) { _sigType = sigType; }
	inline ULong GetType() const { return _sigType; }
	inline const char *GetTypeName() const { return GetTypeName(_sigType); }
	inline Value &GetValue() const { return *_pValue; }
	void SetValue(const Value &value) const;
	inline void SuspendError() {
		if (_sigType == SIGTYPE_Error) _sigType = SIGTYPE_ErrorSuspended;
	}
	inline void ResumeError() {
		if (_sigType == SIGTYPE_ErrorSuspended) _sigType = SIGTYPE_Error;
	}
	inline Error &GetError() { return _err; }
	inline const Error &GetError() const { return _err; }
	void ClearSignal();
	void SetSignal(ULong sigType, const Value &value);
	void AddExprCause(const Expr *pExpr);
	void SetError(ErrorType errType, const char *format, ...);
	void SetErrorV(ErrorType errType,
			const char *format, va_list ap, const char *textPre = "");
	void PrintSignal(SimpleStream &stream);
	static const char *GetTypeName(ULong sigType);
};

}

#endif
