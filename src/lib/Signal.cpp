//=============================================================================
// Signal
//=============================================================================
#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Signal
//-----------------------------------------------------------------------------
Signal::Signal() : _sigType(SIGTYPE_None), _pValue(new Value())
{
}

void Signal::SetValue(const Value &value) const
{
	*_pValue = value;
}

void Signal::ClearSignal()
{
	_sigType = SIGTYPE_None;
	_err.Clear();
}

void Signal::SetSignal(ULong sigType, const Value &value)
{
	_sigType = sigType;
	*_pValue = value;
}

void Signal::AddExprCause(const Expr *pExpr)
{
	ExprOwner &exprOwner = _err.GetExprCauseOwner();
	if (std::find(exprOwner.begin(), exprOwner.end(), pExpr) == exprOwner.end()) {
		exprOwner.push_back(Expr::Reference(pExpr));
	}
}

void Signal::SetError(ErrorType errType, const char *format, ...)
{
	va_list ap;
	va_start(ap, format);
	SetErrorV(errType, format, ap);
	va_end(ap);
}

void Signal::SetErrorV(ErrorType errType,
					const char *format, va_list ap, const char *textPre)
{
	Signal sig;
	String text = Formatter::FormatV(sig, format, ap);
	_sigType = SIGTYPE_Error;
	*_pValue = Value::Null;
	_err.Set(errType, textPre, text);
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

const char *Signal::GetTypeName(ULong sigType)
{
	static const struct {
		ULong sigType;
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
