#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Signal
//-----------------------------------------------------------------------------
Signal::Signal() : _pMsg(new Message()), _stackLevel(0)
{
}

Signal::Signal(Message *pMsg) : _pMsg(pMsg), _stackLevel(0)
{
}

Signal::Signal(const Signal &sig) :
						_pMsg(sig._pMsg), _stackLevel(sig._stackLevel + 1)
{
	if (_stackLevel > MAX_STACK_LEVEL) {
		SetError(ERR_SystemError, "stack level exceeds maximum (%d)", MAX_STACK_LEVEL);
	}
}

Signal &Signal::operator=(const Signal &sig)
{
	_pMsg = sig._pMsg, _stackLevel = sig._stackLevel;
	return *this;
}

void Signal::SetValue(const Value &value) const
{
	*_pMsg->pValue = value;
}

void Signal::ClearSignal()
{
	_pMsg->sigType = SIGTYPE_None;
	_pMsg->err.Clear();
}

void Signal::SetSignal(SignalType sigType, const Value &value)
{
	_pMsg->sigType = sigType, *_pMsg->pValue = value;
}

void Signal::AddExprCause(const Expr *pExpr)
{
	ExprOwner &exprOwner = _pMsg->err.GetExprCauseOwner();
	if (std::find(exprOwner.begin(), exprOwner.end(), pExpr) == exprOwner.end()) {
		exprOwner.push_back(Expr::Reference(pExpr));
	}
}

Signal::Message::Message() : sigType(SIGTYPE_None), pValue(new Value())
{
}

void Signal::SetError(ErrorType errType, const char *format, ...)
{
	va_list list;
	va_start(list, format);
	SetErrorV(errType, format, list);
	va_end(list);
}

void Signal::SetErrorV(ErrorType errType,
					const char *format, va_list list, const char *textPre)
{
	String str(textPre);
	do {
		char *buff = new char [2048];
		::vsprintf(buff, format, list);
		str += buff;
		delete [] buff;
	} while (0);
	_pMsg->sigType = SIGTYPE_Error;
	*_pMsg->pValue = Value::Null;
	_pMsg->err.Set(errType, str);
}

const char *Signal::GetTypeName(SignalType sigType)
{
	static const struct {
		SignalType sigType;
		const char *name;
	} tbl[] = {
		{ SIGTYPE_None,				"none",					},
		{ SIGTYPE_ErrorSuspended,	"error_suspended",		},
		{ SIGTYPE_Error,			"error",				},
		{ SIGTYPE_Terminate,		"terminate",			},
		{ SIGTYPE_Break,			"break",				},
		{ SIGTYPE_Continue,			"continue",				},
		{ SIGTYPE_Return,			"return",				},
		{ SIGTYPE_SwitchDone,		"switch_done",			},
		{ SIGTYPE_DetectEncoding,	"detect_encoding",		},
		{ SIGTYPE_ReqSaveHistory,	"req_save_history",		},
		{ SIGTYPE_ReqClearHistory,	"req_clear_history",	},
	};
	for (int i = 0; i < ArraySizeOf(tbl); i++) {
		if (tbl[i].sigType == sigType) return tbl[i].name;
	}
	return "unknown";
}

}
