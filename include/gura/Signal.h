#ifndef __GURA_SIGNAL_H__
#define __GURA_SIGNAL_H__

#include "Common.h"

namespace Gura {

class Expr;
class ExprOwner;
class Value;
class Environment;

//-----------------------------------------------------------------------------
// ErrorType
//-----------------------------------------------------------------------------
enum ErrorType {
	ERR_None,
	ERR_SyntaxError,
	ERR_ArithmeticError,
	ERR_TypeError,
	ERR_ZeroDivisionError,
	ERR_ValueError,
	ERR_DeclarationError,
	ERR_SystemError,
	ERR_IOError,
	ERR_OutOfRangeError,
	ERR_IndexError,
	ERR_KeyError,
	ERR_ImportError,
	ERR_AttributeError,
	ERR_RuntimeError,
	ERR_NameError,
	ERR_NotImplementedError,
	ERR_IteratorError,
	ERR_CodecError,
	ERR_CommandError,
	ERR_ArgumentError,
	ERR_MemoryError,
	ERR_FormatError,
	ERR_ResourceError,
	ERR_MemberAccessError,
};

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
// Error
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Error {
public:
	struct TypeInfo {
		ErrorType errType;
		const char *name;
	};
private:
	ErrorType _errType;
	String _str;
	std::auto_ptr<ExprOwner> _pExprCauseOwner;
	static const TypeInfo _typeInfoTbl[];
public:
	Error();
	Error(const Error &err);
	void Clear();
	void Set(ErrorType errType, const String &str);
	String MakeMessage(bool lineInfoFlag = true) const;
	String MakeTrace() const;
	inline ErrorType GetType() const { return _errType; }
	inline const char *GetTypeName() const { return GetTypeName(_errType); }
	inline const String &GetStringSTL() const { return _str; }
	inline ExprOwner &GetExprCauseOwner() { return *_pExprCauseOwner; }
	inline const ExprOwner &GetExprCauseOwner() const { return *_pExprCauseOwner; }
	static void PutTraceInfo(String &str, const Expr *pExpr);
	static const char *GetTypeName(ErrorType errType);
	static void AssignErrorTypes(Environment &env);
};

//-----------------------------------------------------------------------------
// Signal
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Signal {
private:
	struct Message {
		SignalType sigType;
		std::auto_ptr<Value> pValue;
		Error err;
		Message();
	};
private:
	Message *_pMsg;
	int _stackLevel;
public:
	Signal();
	Signal(Message *pMsg);
	Signal(const Signal &sig);
	Signal &operator=(const Signal &sig);
	inline bool IsSignalled() const	{
		return _pMsg->sigType != SIGTYPE_None &&
									_pMsg->sigType != SIGTYPE_ErrorSuspended;
	}
	inline bool IsErrorSuspended() const{ return _pMsg->sigType == SIGTYPE_ErrorSuspended; }
	inline bool IsError() const			{ return _pMsg->sigType == SIGTYPE_Error; }
	inline bool IsTerminate() const		{ return _pMsg->sigType == SIGTYPE_Terminate; }
	inline bool IsBreak() const			{ return _pMsg->sigType == SIGTYPE_Break; }
	inline bool IsContinue() const		{ return _pMsg->sigType == SIGTYPE_Continue; }
	inline bool IsReturn() const		{ return _pMsg->sigType == SIGTYPE_Return; }
	inline bool IsSwitchDone() const	{ return _pMsg->sigType == SIGTYPE_SwitchDone; }
	inline bool IsDetectEncoding() const{ return _pMsg->sigType == SIGTYPE_DetectEncoding; }
	inline bool IsReqSaveHistory() const	{ return _pMsg->sigType == SIGTYPE_ReqSaveHistory; }
	inline bool IsReqClearHistory() const	{ return _pMsg->sigType == SIGTYPE_ReqClearHistory; }
	inline SignalType GetType() const { return _pMsg->sigType; }
	inline const char *GetTypeName() const { return GetTypeName(_pMsg->sigType); }
	inline Value &GetValue() const { return *_pMsg->pValue; }
	void SetValue(const Value &value) const;
	inline void SuspendError() {
		if (_pMsg->sigType == SIGTYPE_Error) _pMsg->sigType = SIGTYPE_ErrorSuspended;
	}
	inline void ResumeError() {
		if (_pMsg->sigType == SIGTYPE_ErrorSuspended) _pMsg->sigType = SIGTYPE_Error;
	}
	inline Error &GetError() { return _pMsg->err; }
	inline const Error &GetError() const { return _pMsg->err; }
	void ClearSignal();
	void SetSignal(SignalType sigType, const Value &value);
	void AddExprCause(const Expr *pExpr);
	void SetError(ErrorType errType, const char *format, ...);
	void SetErrorV(ErrorType errType,
			const char *format, va_list list, const char *textPre = ": ");
	static const char *GetTypeName(SignalType sigType);
};

}

#endif
