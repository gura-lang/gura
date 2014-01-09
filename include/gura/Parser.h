//=============================================================================
// Parser
//=============================================================================
#ifndef __GURA_PARSER_H__
#define __GURA_PARSER_H__

#include "Expr.h"

namespace Gura {

//-----------------------------------------------------------------------------
// MagicCommentParser
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE MagicCommentParser {
private:
	enum Stat {
		STAT_Idle, STAT_Start, STAT_SkipSpace, STAT_CodingName,
	};
private:
	Stat _stat;
	String _field;
public:
	MagicCommentParser();
	~MagicCommentParser();
	bool ParseChar(char ch);
	inline const char *GetEncoding() const { return _field.c_str(); }
};

//-----------------------------------------------------------------------------
// Parser
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Parser {
public:
	enum Stat {
		STAT_Start,
		STAT_DoubleChars, STAT_TripleChars, STAT_Escape,
		STAT_Colon,
		STAT_Error, STAT_ErrorRecovery,
		STAT_AfterLBrace,
		STAT_NumberPre, STAT_NumberHex, STAT_NumberOct,
		STAT_NumberAfterDot, STAT_Number,
		STAT_NumberExpAfterE, STAT_NumberExpAfterSign, STAT_NumberExp,
		STAT_ImagNumber, STAT_RatioNumber,
		STAT_SuffixedNumber,
		STAT_Symbol, STAT_SymbolExclamation,
		STAT_CommentLineTop, STAT_CommentLine, STAT_MagicCommentLine,
		STAT_ShebangLine,
		STAT_CommentBlock, STAT_CommentBlockEnd, STAT_CommentBlockNest,
		STAT_StringFirst, STAT_StringSecond,
		STAT_String, STAT_MString, STAT_MStringWise, STAT_MStringLineHead,
		STAT_StringEsc, STAT_StringEscHex, STAT_StringEscOct,
		STAT_StringInCommentBlock, STAT_StringEscInCommentBlock,
		STAT_MStringEndFirst, STAT_MStringEndSecond,
	};
	enum Precedence {
		PREC_LT,
		PREC_EQ,
		PREC_GT,
		PREC_Error,
	};
	enum ElemType {
		ETYPE_Begin,
		ETYPE_Number,
		ETYPE_ImagNumber,
		ETYPE_RatioNumber,
		ETYPE_Quote,
		ETYPE_Question,
		ETYPE_Add,
		ETYPE_Sub,
		ETYPE_Mul,
		ETYPE_Div,
		ETYPE_Mod,
		ETYPE_ModMod,
		ETYPE_Pow,
		ETYPE_Or,
		ETYPE_And,
		ETYPE_Xor,
		ETYPE_Shl,
		ETYPE_Shr,
		ETYPE_Inv,
		ETYPE_Eq,
		ETYPE_Ne,
		ETYPE_Lt,
		ETYPE_Gt,
		ETYPE_Le,
		ETYPE_Ge,
		ETYPE_Cmp,
		ETYPE_Contains,
		ETYPE_Assign,
		ETYPE_AssignAdd,
		ETYPE_AssignSub,
		ETYPE_AssignMul,
		ETYPE_AssignDiv,
		ETYPE_AssignMod,
		ETYPE_AssignPow,
		ETYPE_AssignOr,
		ETYPE_AssignAnd,
		ETYPE_AssignXor,
		ETYPE_AssignShl,
		ETYPE_AssignShr,
		ETYPE_Pair,
		ETYPE_OrOr,
		ETYPE_AndAnd,
		ETYPE_Not,
		ETYPE_Colon,
		ETYPE_ColonColon,
		ETYPE_ColonAsterisk,
		ETYPE_ColonAnd,
		ETYPE_ColonAfterSuffix,
		ETYPE_Seq,
		ETYPE_Comma,
		ETYPE_Semicolon,
		ETYPE_Dot,
		ETYPE_LParenthesis,		// open element
		ETYPE_RParenthesis,		// close element
		ETYPE_LBrace,			// open element
		ETYPE_RBrace,			// close element
		ETYPE_LBracket,			// open element
		ETYPE_RBracket,			// close element
		ETYPE_LBlockParam,		// open element
		ETYPE_RBlockParam,		// close element
		ETYPE_EOL,
		ETYPE_EOF,
		ETYPE_Symbol,
		ETYPE_String,
		ETYPE_SuffixedNumber,
		ETYPE_Binary,
		ETYPE_Expr,
		ETYPE_DoubleChars,		// only used in tokenizing process
		ETYPE_TripleChars,		// only used in tokenizing process
		ETYPE_Unknown,
	};
	struct ElemTypeInfo {
		ElemType elemType;
		int index;
		const char *name;
		const char *symbol;
		OpType opType;
	};
	typedef std::map<ElemType, int> ElemTypeToIndexMap;
	struct StringInfo {
		char chBorder;
		bool rawFlag;		// prefixed by 'r' or 'R'
		bool binaryFlag;	// prefixed by 'b' or 'B'
		bool wiseFlag;		// prefixed by 'R'
		Stat statRtn;
		int cntRest;
		ULong accum;
		String strIndentRef;
	};
	class GURA_DLLDECLARE Element {
	private:
		ElemType _elemType;
		int _lineNo;
		String _str;
		String _suffix;
		// _pExpr is only available for the following element types.
		// ETYPE_Expr          (Expr)
		// ETYPE_LParenthesis  (Expr_Lister)
		// ETYPE_LBrace        (Expr_Block)
		// ETYPE_LBracket      (Expr_Lister)
		// ETYPE_LBlockParam   (Expr_BlockParam)
		Expr *_pExpr;
	public:
		inline Element() : _elemType(ETYPE_Unknown), _lineNo(0), _pExpr(NULL) {}
		inline Element(const Element &elem) :
					_elemType(elem._elemType), _lineNo(elem._lineNo), _pExpr(elem._pExpr),
					_str(elem._str) {}
		inline Element(ElemType elemType, int lineNo) :
					_elemType(elemType), _lineNo(lineNo), _pExpr(NULL) {}
		inline Element(ElemType elemType, int lineNo, const String &str) :
					_elemType(elemType), _lineNo(lineNo), _pExpr(NULL), _str(str) {}
		inline Element(ElemType elemType, int lineNo, const String &str, const String &suffix) :
					_elemType(elemType), _lineNo(lineNo), _pExpr(NULL), _str(str), _suffix(suffix) {}
		inline Element(ElemType elemType, Expr *pExpr) :
					_elemType(elemType), _lineNo(pExpr->GetLineNoTop()), _pExpr(pExpr) {}
		inline Element &operator=(const Element &elem) {
			_elemType = elem._elemType, _lineNo = elem._lineNo, _pExpr = elem._pExpr;
			_str = elem._str;
			return *this;
		}
		~Element();
		inline ElemType GetType() const { return _elemType; }
		inline int GetLineNo() const { return _lineNo; }
		inline bool IsType(ElemType elemType) const { return _elemType == elemType; }
		inline bool IsOpenElement() const {
			return IsType(ETYPE_LParenthesis) || IsType(ETYPE_LBrace) ||
					IsType(ETYPE_LBracket) || IsType(ETYPE_LBlockParam);
		}
		inline bool IsCloseElement() const {
			return IsType(ETYPE_RParenthesis) || IsType(ETYPE_RBrace) ||
					IsType(ETYPE_RBracket) || IsType(ETYPE_RBlockParam);
		}
		inline bool IsSeparatorElement() const {
			return IsType(ETYPE_EOL) || IsType(ETYPE_EOF) ||
								IsType(ETYPE_Comma) || IsType(ETYPE_Semicolon);
		}
		inline bool IsSuffixElement() const {
			return IsType(ETYPE_Add) ||
						IsType(ETYPE_Mul) || IsType(ETYPE_Question);
		}
		inline Expr *GetExpr() const { return _pExpr; }
		inline void SetExpr(Expr *pExpr) { _pExpr = pExpr; }
		inline const String &GetStringSTL() const { return _str; }
		inline const String &GetSuffixSTL() const { return _suffix; }
		inline const char *GetString() const { return _str.c_str(); }
		inline const char *GetSuffix() const { return _suffix.c_str(); }
		inline size_t GetStringSize() const { return _str.size(); }
		inline void AddString(const String &str) { _str.append(str); }
		Number GetNumber() const;
		const char *GetTypeSymbol() const;
	};
	class GURA_DLLDECLARE ElementStack : public std::vector<Element> {
	public:
		~ElementStack();
		reverse_iterator SeekTerminal(reverse_iterator p);
		Element &Peek(int offset) { return *(rbegin() + offset); }
		void Clear();
		String ToString() const;
	};
private:
	Stat _stat;
	bool _lineHeadFlag;
	MagicCommentParser _magicCommentParser;
	bool _appearShebangFlag;
	bool _blockParamFlag;
	int _cntLine;
	int _cntCol;
	int _commentNestLevel;
	AutoPtr<StringRef> _pSourceName;
	String _token;
	String _suffix;
	ElementStack _elemStack;
	StringInfo _stringInfo;
	ElemTypeToIndexMap _elemTypeToIndexMap;
	CharConverter _charConverter;
	String _strIndent;
	static const ElemTypeInfo _elemTypeInfoTbl[];
public:
	Parser(const String &sourceName, int cntLineStart = 0);
	~Parser();
	void Reset();
	void InitStack();
	Expr *ParseChar(Environment &env, Signal sig, char ch);
	Expr_Root *ParseStream(Environment &env, Signal sig, Stream &stream);
	Expr_Root *ParseStream(Environment &env, Signal sig, const char *pathName, const char *encoding);
	bool ParseString(Environment &env, Signal sig, ExprOwner &exprOwner,
							const char *str, size_t len, bool parseNullFlag);
	inline bool ParseString(Environment &env, Signal sig, ExprOwner &exprOwner,
							const char *str, bool parseNullFlag) {
		return ParseString(env, sig, exprOwner, str, ::strlen(str), parseNullFlag);
	}
	void EvalConsoleChar(Environment &env, Signal sig, Expr_Root *pExprRoot, Stream *pConsole, char ch);
	inline bool IsStackEmpty() const { return _elemStack.size() <= 1; }
	inline bool IsContinued() const { return !IsStackEmpty() || _stat != STAT_Start; }
	inline int GetLineNo() const { return _cntLine + 1; }
	inline int GetColPos() const { return _cntCol; }
	inline int ElemTypeToIndex(ElemType elemType) {
		return _elemTypeToIndexMap[elemType];
	}
	static const ElemTypeInfo *LookupElemTypeInfo(ElemType elemType);
	static const ElemTypeInfo *LookupElemTypeInfoByOpType(OpType opType);
	static Precedence LookupPrec(ElemType elemTypeLeft, ElemType elemTypeRight);
	static int CompareOpTypePrec(OpType opType1, OpType opType2);
private:
	bool CheckBlockParamEnd() const;
	static ElemType ElemTypeForString(const StringInfo &stringInfo);
	static bool CheckStringPrefix(StringInfo &stringInfo, const String &token);
	void SetError(Signal sig, ErrorType errType, const char *format, ...);
	void SetError_InvalidElement(Signal sig);
	void SetError_InvalidElement(Signal sig, int lineno);
	static Precedence _LookupPrec(int indexLeft, int indexRight);
	inline  Precedence LookupPrecFast(ElemType elemTypeLeft, ElemType elemTypeRight) {
		return _LookupPrec(ElemTypeToIndex(elemTypeLeft), ElemTypeToIndex(elemTypeRight));
	}
	virtual Expr *FeedElement(Environment &env, Signal sig, const Element &elem);
	bool ReduceOneElem(Environment &env, Signal sig);
	bool ReduceTwoElems(Environment &env, Signal sig);
	bool ReduceThreeElems(Environment &env, Signal sig);
	bool ReduceFourElems(Environment &env, Signal sig);
	bool ReduceFiveElems(Environment &env, Signal sig);
};

}

#endif
