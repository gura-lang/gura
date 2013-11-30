#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Signal
//-----------------------------------------------------------------------------
Signal::Signal() : _pShared(new Shared()), _stackLevel(0)
{
}

Signal::Signal(Shared *pShared) : _pShared(pShared), _stackLevel(0)
{
}

Signal::Signal(const Signal &sig) : _pShared(sig._pShared), _stackLevel(sig._stackLevel + 1)
{
	if (_stackLevel > MAX_STACK_LEVEL) {
		SetError(ERR_SystemError, "stack level exceeds maximum (%d)", MAX_STACK_LEVEL);
	}
}

Signal &Signal::operator=(const Signal &sig)
{
	_pShared = sig._pShared, _stackLevel = sig._stackLevel;
	return *this;
}

void Signal::SetValue(const Value &value) const
{
	*_pShared->pValue = value;
}

void Signal::ClearSignal()
{
	_pShared->sigType = SIGTYPE_None;
	_pShared->err.Clear();
}

void Signal::SetSignal(SignalType sigType, const Value &value)
{
	_pShared->sigType = sigType;
	*_pShared->pValue = value;
}

void Signal::AddExprCause(const Expr *pExpr)
{
	ExprOwner &exprOwner = _pShared->err.GetExprCauseOwner();
	if (std::find(exprOwner.begin(), exprOwner.end(), pExpr) == exprOwner.end()) {
		exprOwner.push_back(Expr::Reference(pExpr));
	}
}

Signal::Shared::Shared() : sigType(SIGTYPE_None), pValue(new Value())
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
	String text(textPre);
	do {
		char *buff = new char [2048];
		::vsprintf(buff, format, list);
		text += buff;
		delete [] buff;
	} while (0);
	_pShared->sigType = SIGTYPE_Error;
	*_pShared->pValue = Value::Null;
	_pShared->err.Set(errType, text);
}

void Signal::PrintSignal(SimpleStream &stream)
{
	Signal sig;
	if (IsError()) {
		bool firstFlag = true;
		stream.Println(sig, GetError().MakeText().c_str());
		AutoPtr<ExprOwner> pExprOwner(new ExprOwner());
		GetError().GetExprCauseOwner().ExtractTrace(*pExprOwner);
		foreach_const (ExprOwner, ppExpr, *pExprOwner) {
			Expr *pExpr = *ppExpr;
			String strExpr = pExpr->ToString(Expr::SCRSTYLE_Brief);
			if (strExpr.empty()) continue;
			if (firstFlag) {
				stream.Println(sig, "Traceback:");
				firstFlag = false;
			}
			String str;
			str += pExpr->MakePosText();
			str += ":\n";
			str += "  ";
			str += strExpr;
			str += "\n";
			stream.Print(sig, str.c_str());
		}
	} else {
		Value value = GetValue();
		if (value.IsValid()) stream.Println(sig, value.ToString().c_str());
	}
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
