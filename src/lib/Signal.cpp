#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// SignalType
//-----------------------------------------------------------------------------
const char *GetSignalTypeName(SignalType sigType)
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

//-----------------------------------------------------------------------------
// ErrorType
//-----------------------------------------------------------------------------
struct ErrorTypeInfo {
	ErrorType errType;
	const char *name;
};

static const ErrorTypeInfo _errorTypeInfoTbl[] = {
	{ ERR_None,					"None"					},
	{ ERR_SyntaxError,			"SyntaxError"			},
	{ ERR_ArithmeticError,		"ArithmeticError"		},
	{ ERR_TypeError,			"TypeError"				},
	{ ERR_ZeroDivisionError,	"ZeroDivisionError"		},
	{ ERR_ValueError,			"ValueError"			},
	{ ERR_SystemError,			"SystemError"			},
	{ ERR_IOError,				"IOError"				},
	{ ERR_IndexError,			"IndexError"			},
	{ ERR_KeyError,				"KeyError"				},
	{ ERR_ImportError,			"ImportError"			},
	{ ERR_AttributeError,		"AttributeError"		},
	{ ERR_RuntimeError,			"RuntimeError"			},
	{ ERR_NameError,			"NameError"				},
	{ ERR_NotImplementedError,	"NotImplementedError"	},
	{ ERR_IteratorError,		"IteratorError"			},
	{ ERR_CodecError,			"CodecError"			},
	{ ERR_CommandError,			"CommandError"			},
	{ ERR_ArgumentError,		"ArgumentError"			},
	{ ERR_MemoryError,			"MemoryError"			},
	{ ERR_FormatError,			"FormatError"			},
	{ ERR_ResourceError,		"ResourceError"			},
	{ ERR_MemberAccessError,	"MemberAccessError"		},
	{ ERR_None,					NULL					},
};

const char *GetErrorTypeName(ErrorType errType)
{
	for (const ErrorTypeInfo *p = _errorTypeInfoTbl; p->name != NULL; p++) {
		if (p->errType == errType) return p->name;
	}
	return "unknown";
}

void AssignErrorTypes(Environment &env)
{
	for (const ErrorTypeInfo *p = _errorTypeInfoTbl; p->name != NULL; p++) {
		Object *pObj = new Object_error(env, p->errType);
		env.AssignValue(Symbol::Add(p->name), Value(pObj), false);
	}
}

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
	_pMsg->errType = ERR_None;
	_pMsg->pExprCauseOwner->Clear();
}

void Signal::SetSignal(SignalType sigType, const Value &value)
{
	_pMsg->sigType = sigType, *_pMsg->pValue = value;
}

void Signal::AddExprCause(const Expr *pExpr)
{
	_pMsg->pExprCauseOwner->push_back(Expr::Reference(pExpr));
}

Signal::Message::Message() : sigType(SIGTYPE_None),
	errType(ERR_None), pValue(new Value()), pExprCauseOwner(new ExprOwner())
{
}

String Signal::GetErrString(bool lineInfoFlag) const
{
	String str;
	const ExprOwner &exprCauseOwner = GetExprCauseOwner();
	str += GetErrorName();
	if (lineInfoFlag && !exprCauseOwner.empty()) {
		const Expr *pExprCause = exprCauseOwner.front();
		str += " at";
		const char *pathName = pExprCause->GetPathName();
		if (pathName != NULL) {
			str += " ";
			String fileName;
			Directory::SplitFileName(pathName, NULL, &fileName);
			str += fileName;
		}
		do {
			char buff[32];
			::sprintf(buff, ":%d", pExprCause->GetLineNoTop());
			str += buff;
		} while (0);
	}
	str += _pMsg->str.c_str();
	return str;
}

String Signal::GetErrTrace() const
{
	String str;
	const ExprOwner &exprCauseOwner = GetExprCauseOwner();
	if (exprCauseOwner.empty()) return str;
	const Expr *pExprInner = NULL;
	const Expr *pExprPrev = NULL;
	bool putTraceFlag = true;
	str += "Traceback:\n";
	foreach_const (ExprOwner, ppExpr, exprCauseOwner) {
		const Expr *pExpr = *ppExpr;
		if (pExprInner == NULL) {
			pExprPrev = pExpr;
		} else if (pExpr->IsAtSameLine(pExprInner)) {
			pExprPrev = pExpr;
		} else if (pExprPrev != NULL) {
			if (putTraceFlag) {
				PutTraceInfo(str, pExprPrev);
			}
			putTraceFlag = !pExpr->IsParentOf(pExprPrev);
			pExprPrev = pExpr;
		}
		pExprInner = pExpr;
	}
	if (pExprPrev != NULL) {
		PutTraceInfo(str, pExprPrev);
	}
	return str;
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
	_pMsg->errType = errType;
	_pMsg->str = str;
	*_pMsg->pValue = Value::Null;
}

void Signal::PutTraceInfo(String &str, const Expr *pExpr)
{
	bool multilineFlag = (pExpr->GetLineNoTop() != pExpr->GetLineNoBtm());
	if (multilineFlag) return;
	const char *pathName = pExpr->GetPathName();
	if (pathName != NULL) {
		String fileName;
		Directory::SplitFileName(pathName, NULL, &fileName);
		str += fileName;
	}
	char buff[64];
	if (multilineFlag) {
		::sprintf(buff, ":%d-%d", pExpr->GetLineNoTop(), pExpr->GetLineNoBtm());
	} else {
		::sprintf(buff, ":%d", pExpr->GetLineNoTop());
	}
	str += buff;
	str += ":\n  ";
	str += pExpr->ToString();
	str += "\n";
}

}
