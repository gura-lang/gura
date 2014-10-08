//=============================================================================
// Error
//=============================================================================
#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Error
//-----------------------------------------------------------------------------
const Error::TypeInfo Error::_typeInfoTbl[] = {
	{ ERR_None,					"None"					},
	{ ERR_SyntaxError,			"SyntaxError"			},
	{ ERR_ArithmeticError,		"ArithmeticError"		},
	{ ERR_TypeError,			"TypeError"				},
	{ ERR_ZeroDivisionError,	"ZeroDivisionError"		},
	{ ERR_ValueError,			"ValueError"			},
	{ ERR_DeclarationError,		"DeclarationError"		},
	{ ERR_SystemError,			"SystemError"			},
	{ ERR_IOError,				"IOError"				},
	{ ERR_OutOfRangeError,		"OutOfRange"			},
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

Error::Error(ErrorType errType) : _errType(errType), _pExprCauseOwner(new ExprOwner())
{
}

Error::Error(const Error &err) : _errType(err._errType), _text(err._text),
					_pExprCauseOwner(new ExprOwner(*err._pExprCauseOwner))
{
}

void Error::Clear()
{
	_errType = ERR_None;
	_text.clear();
	GetExprCauseOwner().Clear();
}

void Error::Set(ErrorType errType, const String &text)
{
	_errType = errType;
	_text = text;
}

const char *Error::GetSourceName() const
{
	const ExprOwner &exprCauseOwner = GetExprCauseOwner();
	return exprCauseOwner.empty()? NULL : exprCauseOwner.front()->GetSourceName();
}

int Error::GetLineNoTop() const
{
	const ExprOwner &exprCauseOwner = GetExprCauseOwner();
	return exprCauseOwner.empty()? 0 : exprCauseOwner.front()->GetLineNoTop();
}

int Error::GetLineNoBtm() const
{
	const ExprOwner &exprCauseOwner = GetExprCauseOwner();
	return exprCauseOwner.empty()? 0 : exprCauseOwner.front()->GetLineNoBtm();
}

String Error::MakePosText() const
{
	const ExprOwner &exprCauseOwner = GetExprCauseOwner();
	if (exprCauseOwner.empty()) return "";
	return exprCauseOwner.front()->MakePosText();
}

String Error::MakeText(bool lineInfoFlag) const
{
	String str;
	const ExprOwner &exprCauseOwner = GetExprCauseOwner();
	if (lineInfoFlag && !exprCauseOwner.empty()) {
		const Expr *pExprCause = exprCauseOwner.front();
		str += pExprCause->MakePosText();
		str += ": ";
	}
	str += GetTypeName();
	str += _text;
	return str;
}

const char *Error::GetTypeName(ErrorType errType)
{
	for (const TypeInfo *p = _typeInfoTbl; p->name != NULL; p++) {
		if (p->errType == errType) return p->name;
	}
	return "unknown";
}

void Error::AssignErrorTypes(Environment &env)
{
	for (const TypeInfo *p = _typeInfoTbl; p->name != NULL; p++) {
		Object *pObj = new Object_error(env, Error(p->errType));
		env.AssignValue(Symbol::Add(p->name), Value(pObj), EXTRA_Public);
	}
}

}
