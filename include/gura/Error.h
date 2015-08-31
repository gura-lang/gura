//=============================================================================
// Error
//=============================================================================
#ifndef __GURA_ERROR_H__
#define __GURA_ERROR_H__

#include "Common.h"

namespace Gura {

class Expr;
class ExprOwner;
class Environment;

//-----------------------------------------------------------------------------
// ErrorType
//-----------------------------------------------------------------------------
enum ErrorType {
	ERR_None,
	ERR_ArgumentError,
	ERR_ArithmeticError,
	ERR_AttributeError,
	ERR_CodecError,
	ERR_CommandError,
	ERR_DeclarationError,
	ERR_FormatError,
	ERR_ImportError,
	ERR_IndexError,
	ERR_IOError,
	ERR_IteratorError,
	ERR_KeyError,
	ERR_MemberAccessError,
	ERR_MemoryError,
	ERR_NameError,
	ERR_NotImplementedError,
	ERR_OutOfRangeError,
	ERR_ResourceError,
	ERR_RuntimeError,
	ERR_SyntaxError,
	ERR_SystemError,
	ERR_TypeError,
	ERR_ValueError,
	ERR_VersionError,
	ERR_ZeroDivisionError,
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
	String _textPre;
	String _text;
	AutoPtr<ExprOwner> _pExprCauseOwner;
	static const TypeInfo _typeInfoTbl[];
public:
	Error(ErrorType errType = ERR_None);
	Error(const Error &err);
	void Clear();
	void Set(ErrorType errType, const String &textPre, const String &text);
	const char *GetSourceName() const;
	int GetLineNoTop() const;
	int GetLineNoBtm() const;
	String MakePosText() const;
	String MakeText(bool lineInfoFlag = true) const;
	inline ErrorType GetType() const { return _errType; }
	inline const char *GetTypeName() const { return GetTypeName(_errType); }
	inline const char *GetTextPre() const { return _textPre.c_str(); }
	inline const char *GetText() const { return _text.c_str(); }
	inline ExprOwner &GetExprCauseOwner() { return *_pExprCauseOwner; }
	inline const ExprOwner &GetExprCauseOwner() const { return *_pExprCauseOwner; }
	static const char *GetTypeName(ErrorType errType);
	static void AssignErrorTypes(Environment &env);
};

}

#endif
