#ifndef __GURA_PARSER_H__
#define __GURA_PARSER_H__

#include "Expr.h"

namespace Gura {

//-----------------------------------------------------------------------------
// MagicCommentParser
//-----------------------------------------------------------------------------
class DLLDECLARE MagicCommentParser {
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
class DLLDECLARE Parser {
public:
	enum Stat {
		STAT_Start,
		STAT_DoubleChars, STAT_TripleChars, STAT_Escape,
		STAT_Quote, STAT_Colon,
		STAT_Error, STAT_ErrorRecovery,
		STAT_AfterLBrace,
		STAT_NumberPre, STAT_NumberHex, STAT_NumberOct,
		STAT_NumberAfterDot, STAT_Number,
		STAT_NumberExpAfterE, STAT_NumberExpAfterSign, STAT_NumberExp,
		STAT_ImagNumber, STAT_Symbol, STAT_SymbolExclamation,
		STAT_CommentLineTop, STAT_CommentLine, STAT_MagicCommentLine,
		STAT_ShebangLine,
		STAT_CommentBlock, STAT_CommentBlockEnd, STAT_CommentBlockNest,
		STAT_StringFirst, STAT_StringSecond,
		STAT_String, STAT_MString, STAT_MStringFirst,
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
		ETYPE_Quote,
		ETYPE_Force,
		ETYPE_Question,
		ETYPE_Plus,
		ETYPE_Minus,
		ETYPE_Multiply,
		ETYPE_Divide,
		ETYPE_Modulo,
		ETYPE_ModuloModulo,
		ETYPE_Power,
		ETYPE_Or,
		ETYPE_And,
		ETYPE_Xor,
		ETYPE_ShiftL,
		ETYPE_ShiftR,
		ETYPE_Invert,
		ETYPE_Equal,
		ETYPE_NotEqual,
		ETYPE_Less,
		ETYPE_Greater,
		ETYPE_LessEq,
		ETYPE_GreaterEq,
		ETYPE_Compare,
		ETYPE_ContainCheck,
		ETYPE_Assign,
		ETYPE_AssignPlus,
		ETYPE_AssignMinus,
		ETYPE_AssignMultiply,
		ETYPE_AssignDivide,
		ETYPE_AssignModulo,
		ETYPE_AssignPower,
		ETYPE_AssignOr,
		ETYPE_AssignAnd,
		ETYPE_AssignXor,
		ETYPE_AssignShiftL,
		ETYPE_AssignShiftR,
		ETYPE_DictAssign,
		ETYPE_OrOr,
		ETYPE_AndAnd,
		ETYPE_Not,
		ETYPE_Colon,
		ETYPE_ColonColon,
		ETYPE_ColonAsterisk,
		ETYPE_ColonAnd,
		ETYPE_ColonAfterSuffix,
		ETYPE_Sequence,
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
	};
	typedef std::map<ElemType, int> ElemTypeToIndexMap;
	struct StringInfo {
		char chBorder;
		bool rawFlag;			// prefixed by 'r' or 'R'
		bool binaryFlag;		// prefixed by 'b' or 'B'
		bool skipFirstEOLFlag;	// prefixed by 'R'
		Stat statRtn;
		int cntRest;
		unsigned long accum;
	};
	class DLLDECLARE Element {
	private:
		ElemType _elemType;
		int _lineNo;
		String _str;
		int _num;	// _num is only available for 
		// _pExpr is only available for the following eleement types.
		// ETYPE_Expr          (Expr)
		// ETYPE_LParenthesis  (Expr_Lister)
		// ETYPE_LBrace        (Expr_Block)
		// ETYPE_LBracket      (Expr_Lister)
		// ETYPE_LBlockParam   (Expr_BlockParam)
		Expr *_pExpr;
	public:
		inline Element() : _elemType(ETYPE_Unknown), _lineNo(0), _pExpr(NULL), _num(0) {}
		inline Element(const Element &elem) :
					_elemType(elem._elemType), _lineNo(elem._lineNo), _pExpr(elem._pExpr),
					_str(elem._str), _num(elem._num) {}
		inline Element(ElemType elemType, int lineNo) :
					_elemType(elemType), _lineNo(lineNo), _pExpr(NULL), _num(0) {}
		inline Element(ElemType elemType, int lineNo, const String &str) :
					_elemType(elemType), _lineNo(lineNo), _pExpr(NULL), _str(str), _num(0) {}
		inline Element(ElemType elemType, int lineNo, int num) :
					_elemType(elemType), _lineNo(lineNo), _pExpr(NULL), _num(num) {}
		inline Element(ElemType elemType, Expr *pExpr) :
					_elemType(elemType), _lineNo(pExpr->GetLineNoTop()), _pExpr(pExpr), _num(0) {}
		inline Element &operator=(const Element &elem) {
			_elemType = elem._elemType, _lineNo = elem._lineNo, _pExpr = elem._pExpr;
			_str = elem._str, _num = elem._num;
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
			return IsType(ETYPE_Plus) ||
						IsType(ETYPE_Multiply) || IsType(ETYPE_Question);
		}
		inline Expr *GetExpr() const { return _pExpr; }
		inline void SetExpr(Expr *pExpr) { _pExpr = pExpr; }
		inline const char *GetString() const { return _str.c_str(); }
		inline size_t GetStringSize() const { return _str.size(); }
		inline int GetNum() const { return _num; }
		inline void AddString(const char *str) { _str.append(str); }
		Number GetNumber() const;
		const char *GetTypeSymbol() const;
	};
	class DLLDECLARE ElementStack : public std::vector<Element> {
	public:
		~ElementStack();
		reverse_iterator SeekTerminal(reverse_iterator p);
		Element &Peek(int offset) { return *(rbegin() + offset); }
		void Clear();
		String ToString() const;
	};
	typedef std::vector<Expr_Caller *> ExprCallerStack;
private:
	Stat _stat;
	MagicCommentParser _magicCommentParser;
	bool _appearShebangFlag;
	bool _blockParamFlag;
	bool _quoteFlag;
	int _cntLine;
	int _commentNestLevel;
	String _sourceName;
	String _token;
	ElementStack _elemStack;
	StringInfo _stringInfo;
	ElemTypeToIndexMap _elemTypeToIndexMap;
	CharConverter _charConverter;
	static const ElemTypeInfo _elemTypeInfoTbl[];
public:
	Parser();
	~Parser();
	void Reset();
	void InitStack();
	Expr *ParseChar(Environment &env, Signal sig, char ch);
	Expr *ParseStream(Environment &env, Signal sig, Stream &stream);
	Expr *ParseStream(Environment &env, Signal sig, const char *pathName, const char *encoding);
	bool ParseString(Environment &env, Signal sig, ExprOwner &exprOwner,
							const char *sourceName, const char *str, size_t len);
	inline bool ParseString(Environment &env, Signal sig, ExprOwner &exprOwner,
							const char *sourceName, const char *str) {
		return ParseString(env, sig, exprOwner, sourceName, str, ::strlen(str));
	}
	bool EvalTemplate(Environment &env, Signal sig, SimpleStream &streamSrc,
				SimpleStream &streamDst, bool autoIndentFlag, bool appendLastEOLFlag);
	bool MakeTemplateScript(Environment &env, Signal sig,
			const char *strIndent, const char *strScript,
			SimpleStream &streamDst, bool autoIndentFlag, bool appendLastEOLFlag,
			ExprOwner &exprOwnerRoot, ExprCallerStack &exprCallerStack);
	void EvalConsoleChar(Environment &env, Signal sig, ExprOwner &exprOwner,
												Stream *pConsole, char ch);
	inline void SetSourceName(const char *sourceName) { _sourceName = sourceName; }
	inline bool IsStackEmpty() const { return _elemStack.size() <= 1; }
	inline bool IsContinued() const { return !IsStackEmpty() || _stat != STAT_Start; }
	inline int GetLineNo() const { return _cntLine + 1; }
	inline int ElemTypeToIndex(ElemType elemType) {
		return _elemTypeToIndexMap[elemType];
	}
	static const ElemTypeInfo *LookupElemTypeInfo(ElemType elemType);
	static Precedence LookupPrec(ElemType elemTypeLeft, ElemType elemTypeRight);
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
	Expr *FeedElement(Environment &env, Signal sig, const Element &elem);
	bool ReduceOneElem(Environment &env, Signal sig);
	bool ReduceTwoElems(Environment &env, Signal sig);
	bool ReduceThreeElems(Environment &env, Signal sig);
	bool ReduceFourElems(Environment &env, Signal sig);
	bool ReduceFiveElems(Environment &env, Signal sig);
};

}

#endif
