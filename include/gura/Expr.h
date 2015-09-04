//=============================================================================
// Expr
//=============================================================================
#ifndef __GURA_EXPR_H__
#define __GURA_EXPR_H__

#include "Common.h"
#include "Symbol.h"
#include "Signal.h"
#include "Environment.h"
#include "Iterator.h"
#include "Processor.h"

namespace Gura {

class Expr;
class ExprList;
class Expr_Value;
class Expr_Identifier;
class Expr_Suffixed;
class Expr_Root;
class Expr_Block;
class Expr_Lister;
class Expr_Iterer;
class Expr_Indexer;
class Expr_Caller;
class Expr_UnaryOp;
class Expr_BinaryOp;
class Expr_Quote;
class Expr_Assign;
class Expr_Member;
class Callable;
class CallerInfo;

typedef void (*BridgeFunctionT)(Environment &env, const Value &valueThis, Value &valueResult);

//-----------------------------------------------------------------------------
// ExprType
//-----------------------------------------------------------------------------
enum ExprType {
	EXPRTYPE_None,
	EXPRTYPE_UnaryOp,
	EXPRTYPE_Quote,
	EXPRTYPE_BinaryOp,
	EXPRTYPE_Assign,
	EXPRTYPE_Member,
	EXPRTYPE_Root,
	EXPRTYPE_Block,
	EXPRTYPE_Lister,
	EXPRTYPE_Iterer,
	EXPRTYPE_Indexer,
	EXPRTYPE_Caller,
	EXPRTYPE_Value,
	EXPRTYPE_Identifier,
	EXPRTYPE_Suffixed,
};

GURA_DLLDECLARE const char *GetExprTypeName(ExprType exprType);

//-----------------------------------------------------------------------------
// TrailCtrl
//-----------------------------------------------------------------------------
enum TrailCtrl {
	TRAILCTRL_Continue,
	TRAILCTRL_Quit,
	TRAILCTRL_Finalize,
};

//-----------------------------------------------------------------------------
// TrailCtrlHolder
//-----------------------------------------------------------------------------
class TrailCtrlHolder {
private:
	int _cntRef;
	TrailCtrl _trailCtrl;
public:
	Gura_DeclareReferenceAccessor(TrailCtrlHolder);
public:
	inline TrailCtrlHolder(TrailCtrl trailCtrl) :
									_cntRef(1), _trailCtrl(trailCtrl) {}
private:
	inline ~TrailCtrlHolder() {}
public:
	inline void Set(TrailCtrl trailCtrl) { _trailCtrl = trailCtrl; }
	inline TrailCtrl Get() const { return _trailCtrl; }
};

//-----------------------------------------------------------------------------
// CodeGenerator
//-----------------------------------------------------------------------------
class CodeGenerator {
public:
	virtual bool GenCode_Value(Environment &env, const Expr_Value *pExprValue) = 0;
	virtual bool GenCode_Identifier(Environment &env, const Expr_Identifier *pExpr) = 0;
	virtual bool GenCode_Suffixed(Environment &env, const Expr_Suffixed *pExpr) = 0;
	virtual bool GenCode_Root(Environment &env, const Expr_Root *pExpr) = 0;
	virtual bool GenCode_Block(Environment &env, const Expr_Block *pExpr) = 0;
	virtual bool GenCode_Lister(Environment &env, const Expr_Lister *pExpr) = 0;
	virtual bool GenCode_Iterer(Environment &env, const Expr_Iterer *pExpr) = 0;
	virtual bool GenCode_Indexer(Environment &env, const Expr_Indexer *pExpr) = 0;
	virtual bool GenCode_Caller(Environment &env, const Expr_Caller *pExpr) = 0;
	virtual bool GenCode_UnaryOp(Environment &env, const Expr_UnaryOp *pExpr) = 0;
	virtual bool GenCode_BinaryOp(Environment &env, const Expr_BinaryOp *pExpr) = 0;
	virtual bool GenCode_Quote(Environment &env, const Expr_Quote *pExpr) = 0;
	virtual bool GenCode_Assign(Environment &env, const Expr_Assign *pExpr) = 0;
	virtual bool GenCode_Member(Environment &env, const Expr_Member *pExpr) = 0;
};

//-----------------------------------------------------------------------------
// ExprVisitor
//-----------------------------------------------------------------------------
class ExprVisitor {
public:
	virtual bool Visit(Expr *pExpr) = 0;
};

//-----------------------------------------------------------------------------
// Expr
// [class hierarchy under Expr]
// Expr <-+- Expr_Value
//        +- Expr_Identifier
//        +- Expr_Suffixed
//        +- Expr_Unary <-----+- Expr_UnaryOp
//        |                   `- Expr_Quote
//        +- Expr_Binary <----+- Expr_BinaryOp
//        |                   +- Expr_Assign
//        |                   `- Expr_Member
//        +- Expr_Collector <-+- Expr_Root
//        |                   +- Expr_Block
//        |                   +- Expr_Lister
//        |                   `- Expr_Iterer
//        `- Expr_Compound <--+- Expr_Indexer
//                            `- Expr_Caller
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Expr {
public:
	enum ScriptStyle {
		SCRSTYLE_None,
		SCRSTYLE_Crammed,
		SCRSTYLE_OneLine,
		SCRSTYLE_Brief,
		SCRSTYLE_Fancy,
	};
	enum Separator {
		SEP_Comma,
		SEP_NewLine,
	};
public:
	static const char *IndentDefault;
public:
	class GURA_DLLDECLARE ExprVisitor_GatherSymbol : public ExprVisitor {
	private:
		SymbolSet &_symbolSet;
	public:
		inline ExprVisitor_GatherSymbol(SymbolSet &symbolSet) :
												_symbolSet(symbolSet) {}
		virtual bool Visit(Expr *pExpr);
	};
	class GURA_DLLDECLARE ExprVisitor_GatherSimpleLambdaArgs : public ExprVisitor {
	private:
		SymbolSet _symbolSet;
		ExprOwner &_exprOwnerArg;
	public:
		inline ExprVisitor_GatherSimpleLambdaArgs(ExprOwner &exprOwnerArg) : _exprOwnerArg(exprOwnerArg) {}
		virtual bool Visit(Expr *pExpr);
	};
	class GURA_DLLDECLARE ExprVisitor_SearchBar : public ExprVisitor {
	private:
		bool _foundFlag;
	public:
		inline ExprVisitor_SearchBar() : _foundFlag(false) {}
		virtual bool Visit(Expr *pExpr);
		inline bool GetFoundFlag() const { return _foundFlag; }
	};
	class GURA_DLLDECLARE SequenceRoot : public Sequence {
	private:
		AutoPtr<ExprOwner> _pExprOwner;
		size_t _idxExpr;
	public:
		SequenceRoot(Environment *pEnv, ExprOwner *pExprOwner);
		virtual bool DoStep(Signal &sig, Value &result);
		virtual String ToString() const;
	};
private:
	ExprType _exprType;
	int _cntRef;	// const_cast is used to update this value
	int _lineNoTop, _lineNoBtm;
	const Expr *_pExprParent;
	AutoPtr<StringShared> _pSourceName;
	BridgeFunctionT _bridgeFunction;
public:
	Gura_DeclareReferenceAccessor(Expr);
public:
	Expr(ExprType exprType);
	Expr(const Expr &expr);
protected:
	virtual ~Expr();
public:
	inline void SetSourceInfo(StringShared *pSourceName, int lineNoTop, int lineNoBtm) {
		_pSourceName.reset(pSourceName);
		_lineNoTop = lineNoTop, _lineNoBtm = lineNoBtm;
	}
	inline const char *GetSourceName() const {
		return _pSourceName.IsNull()? SRCNAME_unknown : _pSourceName->GetString();
	};
	inline int GetLineNoTop() const { return _lineNoTop; }
	inline int GetLineNoBtm() const { return _lineNoBtm; }
	inline void SetParent(const Expr *pExpr) { _pExprParent = pExpr; }
	inline const Expr *GetParent() const { return _pExprParent; }
	inline const char *GetTypeName() const { return GetExprTypeName(_exprType); }
	inline ExprType GetType() const { return _exprType; }
	inline bool IsType(ExprType exprType) const { return _exprType == exprType; }
	Value Exec(Environment &env, bool evalSymFuncFlag = false) const;
	Value Assign(Environment &env, Value &valueAssigned,
					const SymbolSet *pSymbolsAssignable, bool escalateFlag) const;
	inline Value Exec2(Environment &env,
			SeqPostHandler *pSeqPostHandler, bool evalSymFuncFlag = false) const {
		return Exec(env, evalSymFuncFlag);
	}
	inline void _SetBridgeFunction(BridgeFunctionT bridgeFunction) const {
		const_cast<Expr *>(this)->_bridgeFunction = bridgeFunction;
	}
	inline BridgeFunctionT _GetBridgeFunction() const { return _bridgeFunction; }
	Expr_Block *ToExprBlock() const;
	bool IsAtSameLine(const Expr *pExpr) const;
	void GatherSymbol(SymbolSet &symbolSet) const;
	void GatherSimpleLambdaArgs(ExprOwner &exprOwner) const;
	//bool GetChainedSymbolList(SymbolList &symbolList) const;
	void SetError(Signal &sig, ErrorType errType, const char *format, ...) const;
	void SetError_NotAssignableSymbol(Signal &sig, const Symbol *pSymbol) const;
	static bool NeedParenthesis(const Operator *pOperatorOuter,
										const Operator *pOperator, bool rightFlag);
	virtual Expr *Clone() const = 0;
	virtual Callable *LookupCallable(Environment &env) const;
private:
	virtual Value DoExec(Environment &env) const = 0;
	virtual Value DoAssign(Environment &env, Value &valueAssigned,
					const SymbolSet *pSymbolsAssignable, bool escalateFlag) const;
public:
	virtual void Accept(ExprVisitor &visitor) = 0;
	virtual bool IsParentOf(const Expr *pExpr) const;
	virtual Expr *MathDiff(Environment &env, const Symbol *pSymbol) const;
	virtual Expr *MathOptimize(Environment &env) const;
	virtual const Expr *Unquote() const;
	// type chekers - Unary and descendants
	virtual bool IsUnary() const;
	virtual bool IsUnaryOp() const;
	virtual bool IsUnaryOpSuffix() const;
	virtual bool IsQuote() const;
	// type chekers - Binary and descendants
	virtual bool IsBinary() const;
	virtual bool IsBinaryOp() const;
	virtual bool IsAssign() const;
	virtual bool IsMember() const;
	// type chekers - Collector and descendants
	virtual bool IsCollector() const;
	virtual bool IsRoot() const;
	virtual bool IsBlock() const;
	virtual bool IsLister() const;
	virtual bool IsIterer() const;
	// type chekers - Compound and descendants
	virtual bool IsCompound() const;
	virtual bool IsIndexer() const;
	virtual bool IsCaller() const;
	// type chekers - others
	virtual bool IsValue() const;
	virtual bool IsIdentifier() const;
	virtual bool IsSuffixed() const;
	bool IsSymbol(const Symbol *pSymbol) const;
	bool IsConstNumber(Number num) const;
	bool IsConstEvenNumber() const;
	bool IsConstNegNumber() const;
	bool IsUnaryOp(OpType opType) const;
	bool IsBinaryOp(OpType opType) const;
	virtual bool GenerateCode(Environment &env, CodeGenerator &codeGenerator) const;
	virtual bool GenerateScript(Signal &sig, SimpleStream &stream,
							ScriptStyle scriptStyle, int nestLevel, const char *strIndent) const;
	virtual String ToString(ScriptStyle scriptStyle) const;
	String MakePosText() const;
	static bool PutNestIndent(Signal &sig, SimpleStream &stream,
							  int nestLevel, const char *strIndent);
	static ScriptStyle SymbolToScriptStyle(const Symbol *pSymbol);
};

//-----------------------------------------------------------------------------
// ExprList
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE ExprList : public std::vector<Expr *> {
public:
	static const ExprList Empty;
public:
	inline ExprList() {};
	inline ExprList(Expr *pExpr) : std::vector<Expr *>(1) {
		(*this)[0] = pExpr;
	}
	inline ExprList(Expr *pExpr1, Expr *pExpr2) : std::vector<Expr *>(2) {
		(*this)[0] = pExpr1, (*this)[1] = pExpr2;
	}
	void ExtractTrace(ExprOwner &exprOwner) const;
	bool GenerateCode(Environment &env, CodeGenerator &codeGenerator) const;
	bool GenerateScript(Signal &sig, SimpleStream &stream,
		Expr::ScriptStyle scriptStyle, int nestLevel, const char *strIndent, Expr::Separator sep) const;
	void Accept(ExprVisitor &visitor);
	bool IsContained(const Expr *pExpr) const;
	void SetParent(const Expr *pExpr);
	bool IsAtSameLine() const;
private:
	inline ExprList(const ExprList &exprList) {}; // not supported
};

//-----------------------------------------------------------------------------
// ExprOwner
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE ExprOwner : public ExprList {
public:
	class GURA_DLLDECLARE Iterator : public Gura::Iterator {
	private:
		size_t _idx;
		AutoPtr<ExprOwner> _pExprOwner;
	public:
		Iterator(ExprOwner *pExprOwner);
		virtual Gura::Iterator *GetSource();
		virtual bool DoNext(Environment &env, Value &value);
		virtual String ToString() const;
		virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
	};
private:
	int _cntRef;
public:
	Gura_DeclareReferenceAccessor(ExprOwner);
public:
	ExprOwner();
	ExprOwner(const ExprList &exprList);
	ExprOwner(const ExprOwner &exprOwner);
private:
	~ExprOwner();
public:
	void Clear();
};

//-----------------------------------------------------------------------------
// Expr_Value
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Expr_Value : public Expr {
protected:
	Value _value;		// only contains number, string and binary
	std::unique_ptr<String> _pScript;
public:
	inline Expr_Value(const Value &value) : Expr(EXPRTYPE_Value), _value(value) {}
	inline Expr_Value(const Expr_Value &expr) : Expr(expr), _value(expr._value) {}
	inline const Value &GetValue() const { return _value; }
	inline void SetScript(const String &script) { _pScript.reset(new String(script)); }
	inline const String *GetScript() const { return _pScript.get(); }
	inline static Expr_Value *Reference(const Expr_Value *pExpr) {
		return dynamic_cast<Expr_Value *>(Expr::Reference(pExpr));
	}
	virtual bool IsValue() const;
	virtual Expr *Clone() const;
	virtual Value DoExec(Environment &env) const;
	virtual Expr *MathDiff(Environment &env, const Symbol *pSymbol) const;
	virtual Expr *MathOptimize(Environment &env) const;
	virtual void Accept(ExprVisitor &visitor);
	virtual bool GenerateCode(Environment &env, CodeGenerator &codeGenerator) const;
	virtual bool GenerateScript(Signal &sig, SimpleStream &stream,
							ScriptStyle scriptStyle, int nestLevel, const char *strIndent) const;
};

//-----------------------------------------------------------------------------
// Expr_Identifier
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Expr_Identifier : public Expr {
protected:
	const Symbol *_pSymbol;
	SymbolSet _attrs;
	SymbolSet _attrsOpt;
	SymbolList _attrFront;
public:
	inline Expr_Identifier(const Symbol *pSymbol) : Expr(EXPRTYPE_Identifier), _pSymbol(pSymbol) {}
	inline Expr_Identifier(const Expr_Identifier &expr) : Expr(expr),
							_pSymbol(expr._pSymbol), _attrs(expr._attrs) {}
	inline static Expr_Identifier *Reference(const Expr_Identifier *pExpr) {
		return dynamic_cast<Expr_Identifier *>(Expr::Reference(pExpr));
	}
	virtual bool IsIdentifier() const;
	virtual Expr *Clone() const;
	virtual Callable *LookupCallable(Environment &env) const;
	virtual Value DoExec(Environment &env) const;
	Value GetProp(Environment &env, const Value &valueThis) const;
	virtual Value DoAssign(Environment &env, Value &value,
					const SymbolSet *pSymbolsAssignable, bool escalateFlag) const;
	virtual void Accept(ExprVisitor &visitor);
	virtual Expr *MathDiff(Environment &env, const Symbol *pSymbol) const;
	virtual Expr *MathOptimize(Environment &env) const;
	inline bool AddAttr(const Symbol *pSymbol) {
		_attrs.Insert(pSymbol);
		return true;
	}
	inline void AddAttrs(const SymbolSet &symbolSet) { _attrs.Insert(symbolSet); }
	inline void AddAttrOpt(const Symbol *pSymbol) { _attrsOpt.Insert(pSymbol); }
	inline void AddAttrsOpt(const SymbolSet &symbolSet) { _attrsOpt.Insert(symbolSet); }
	inline SymbolSet &GetAttrs() { return _attrs; }
	inline SymbolSet &GetAttrsOpt() { return _attrsOpt; }
	inline const SymbolSet &GetAttrs() const { return _attrs; }
	inline const SymbolSet &GetAttrsOpt() const { return _attrsOpt; }
	inline const Symbol *GetSymbol() const { return _pSymbol; }
	inline SymbolList &GetAttrFront() { return _attrFront; }
	inline const SymbolList &GetAttrFront() const { return _attrFront; }
	virtual bool GenerateCode(Environment &env, CodeGenerator &codeGenerator) const;
	virtual bool GenerateScript(Signal &sig, SimpleStream &stream,
							ScriptStyle scriptStyle, int nestLevel, const char *strIndent) const;
	bool GenerateScriptHead(Signal &sig, SimpleStream &stream,
							ScriptStyle scriptStyle, int nestLevel, const char *strIndent) const;
	bool GenerateScriptTail(Signal &sig, SimpleStream &stream,
							ScriptStyle scriptStyle, int nestLevel, const char *strIndent) const;
};

//-----------------------------------------------------------------------------
// Expr_Suffixed
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Expr_Suffixed : public Expr {
protected:
	String _body;
	bool _numberFlag;
	const Symbol *_pSymbolSuffix;
public:
	inline Expr_Suffixed(const String &body, bool numberFlag, const Symbol *pSymbolSuffix) :
		Expr(EXPRTYPE_Suffixed), _body(body), _numberFlag(numberFlag), _pSymbolSuffix(pSymbolSuffix) {}
	inline Expr_Suffixed(const Expr_Suffixed &expr) :
		Expr(expr), _body(expr._body), _numberFlag(expr._numberFlag), _pSymbolSuffix(expr._pSymbolSuffix) {}
	inline bool IsNumber() const { return _numberFlag; }
	inline const char *GetBody() const { return _body.c_str(); }
	inline const Symbol *GetSymbolSuffix() const { return _pSymbolSuffix; }
	inline static Expr_Suffixed *Reference(const Expr_Suffixed *pExpr) {
		return dynamic_cast<Expr_Suffixed *>(Expr::Reference(pExpr));
	}
	virtual bool IsSuffixed() const;
	virtual Expr *Clone() const;
	virtual Value DoExec(Environment &env) const;
	virtual void Accept(ExprVisitor &visitor);
	virtual bool GenerateCode(Environment &env, CodeGenerator &codeGenerator) const;
	virtual bool GenerateScript(Signal &sig, SimpleStream &stream,
							ScriptStyle scriptStyle, int nestLevel, const char *strIndent) const;
};

//-----------------------------------------------------------------------------
// Expr_Unary
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Expr_Unary : public Expr {
private:
	AutoPtr<Expr> _pExprChild;
public:
	Expr_Unary(ExprType exprType, Expr *pExprChild);
	Expr_Unary(const Expr_Unary &expr);
	inline static Expr_Unary *Reference(const Expr_Unary *pExpr) {
		return dynamic_cast<Expr_Unary *>(Expr::Reference(pExpr));
	}
	virtual ~Expr_Unary();
	virtual bool IsUnary() const;
	virtual void Accept(ExprVisitor &visitor);
	virtual bool IsParentOf(const Expr *pExpr) const;
	inline void SetChild(Expr *pExprChild) {
		_pExprChild.reset(pExprChild);
		_pExprChild->SetParent(this);
	}
	inline Expr *GetChild() { return _pExprChild.get(); }
	inline const Expr *GetChild() const { return _pExprChild.get(); }
};

//-----------------------------------------------------------------------------
// Expr_Binary
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Expr_Binary : public Expr {
private:
	AutoPtr<Expr> _pExprLeft;
	AutoPtr<Expr> _pExprRight;
public:
	Expr_Binary(ExprType exprType, Expr *pExprLeft, Expr *pExprRight);
	Expr_Binary(const Expr_Binary &expr);
	inline static Expr_Binary *Reference(const Expr_Binary *pExpr) {
		return dynamic_cast<Expr_Binary *>(Expr::Reference(pExpr));
	}
	virtual ~Expr_Binary();
	virtual bool IsBinary() const;
	virtual void Accept(ExprVisitor &visitor);
	virtual bool IsParentOf(const Expr *pExpr) const;
	inline void SetLeft(Expr *pExprLeft) {
		_pExprLeft.reset(pExprLeft);
		_pExprLeft->SetParent(this);
	}
	inline void SetRight(Expr *pExprRight) {
		_pExprRight.reset(pExprRight);
		_pExprRight->SetParent(this);
	}
	inline Expr *GetLeft() { return _pExprLeft.get(); }
	inline Expr *GetRight() { return _pExprRight.get(); }
	inline const Expr *GetLeft() const { return _pExprLeft.get(); }
	inline const Expr *GetRight() const { return _pExprRight.get(); }
};

//-----------------------------------------------------------------------------
// Expr_Collector
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Expr_Collector : public Expr {
protected:
	AutoPtr<ExprOwner> _pExprOwner;
public:
	Expr_Collector(ExprType exprType);
	Expr_Collector(ExprType exprType, ExprOwner *pExprOwner);
	Expr_Collector(const Expr_Collector &expr);
	inline static Expr_Collector *Reference(const Expr_Collector *pExpr) {
		return dynamic_cast<Expr_Collector *>(Expr::Reference(pExpr));
	}
	virtual bool IsCollector() const;
	virtual ~Expr_Collector();
	virtual void Accept(ExprVisitor &visitor);
	virtual bool IsParentOf(const Expr *pExpr) const;
	inline void AddExpr(Expr *pExpr) {
		GetExprOwner().push_back(pExpr);
		pExpr->SetParent(this);
	}
	inline ExprOwner &GetExprOwner() { return *_pExprOwner; }
	inline const ExprOwner &GetExprOwner() const { return *_pExprOwner; }
};

//-----------------------------------------------------------------------------
// Expr_Root
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Expr_Root : public Expr_Collector {
public:
	Expr_Root();
	Expr_Root(const Expr_Root &expr);
	inline static Expr_Root *Reference(const Expr_Root *pExpr) {
		return dynamic_cast<Expr_Root *>(Expr::Reference(pExpr));
	}
	virtual bool IsRoot() const;
	virtual Expr *Clone() const;
	virtual Value DoExec(Environment &env) const;
	virtual bool GenerateCode(Environment &env, CodeGenerator &codeGenerator) const;
	virtual bool GenerateScript(Signal &sig, SimpleStream &stream,
							ScriptStyle scriptStyle, int nestLevel, const char *strIndent) const;
};

//-----------------------------------------------------------------------------
// Expr_Block
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Expr_Block : public Expr_Collector {
protected:
	AutoPtr<ExprOwner> _pExprOwnerParam;		// this may be nullptr
public:
	Expr_Block();
	Expr_Block(ExprOwner *pExprOwner, ExprOwner *pExprOwnerParam);
	Expr_Block(const Expr_Block &expr);
	inline static Expr_Block *Reference(const Expr_Block *pExpr) {
		return dynamic_cast<Expr_Block *>(Expr::Reference(pExpr));
	}
	virtual ~Expr_Block();
	virtual bool IsBlock() const;
	virtual Expr *Clone() const;
	virtual Value DoExec(Environment &env) const;
	virtual Expr *MathDiff(Environment &env, const Symbol *pSymbol) const;
	virtual void Accept(ExprVisitor &visitor);
	virtual bool GenerateCode(Environment &env, CodeGenerator &codeGenerator) const;
	virtual bool GenerateScript(Signal &sig, SimpleStream &stream,
							ScriptStyle scriptStyle, int nestLevel, const char *strIndent) const;
	inline void SetExprOwnerParam(ExprOwner *pExprOwnerParam) {
		_pExprOwnerParam.reset(pExprOwnerParam);
	}
	inline ExprOwner *GetExprOwnerParam() { return _pExprOwnerParam.get(); }
	inline const ExprOwner *GetExprOwnerParam() const { return _pExprOwnerParam.get(); }
};

//-----------------------------------------------------------------------------
// Expr_Lister
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Expr_Lister : public Expr_Collector {
public:
	inline Expr_Lister() : Expr_Collector(EXPRTYPE_Lister) {}
	inline Expr_Lister(const Expr_Lister &expr) : Expr_Collector(expr) {}
	inline static Expr_Lister *Reference(const Expr_Lister *pExpr) {
		return dynamic_cast<Expr_Lister *>(Expr::Reference(pExpr));
	}
	virtual bool IsLister() const;
	virtual Expr *Clone() const;
	virtual Value DoExec(Environment &env) const;
	virtual Value DoAssign(Environment &env, Value &value,
					const SymbolSet *pSymbolsAssignable, bool escalateFlag) const;
	virtual bool GenerateCode(Environment &env, CodeGenerator &codeGenerator) const;
	virtual bool GenerateScript(Signal &sig, SimpleStream &stream,
							ScriptStyle scriptStyle, int nestLevel, const char *strIndent) const;
};

//-----------------------------------------------------------------------------
// Expr_Iterer
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Expr_Iterer : public Expr_Collector {
public:
	inline Expr_Iterer() : Expr_Collector(EXPRTYPE_Iterer) {}
	inline Expr_Iterer(Expr *pExpr) : Expr_Collector(EXPRTYPE_Iterer) {
		AddExpr(pExpr);
	}
	inline Expr_Iterer(const Expr_Iterer &expr) : Expr_Collector(expr) {}
	inline static Expr_Iterer *Reference(const Expr_Iterer *pExpr) {
		return dynamic_cast<Expr_Iterer *>(Expr::Reference(pExpr));
	}
	virtual bool IsIterer() const;
	virtual Expr *Clone() const;
	virtual Value DoExec(Environment &env) const;
	virtual bool GenerateCode(Environment &env, CodeGenerator &codeGenerator) const;
	virtual bool GenerateScript(Signal &sig, SimpleStream &stream,
							ScriptStyle scriptStyle, int nestLevel, const char *strIndent) const;
};

//-----------------------------------------------------------------------------
// Expr_Compound
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Expr_Compound : public Expr {
protected:
	AutoPtr<Expr> _pExprCar;
	AutoPtr<Expr_Lister> _pExprLister;
public:
	Expr_Compound(ExprType exprType, Expr *pExprCar, Expr_Lister *pExprLister);
	Expr_Compound(const Expr_Compound &expr);
	inline static Expr_Compound *Reference(const Expr_Compound *pExpr) {
		return dynamic_cast<Expr_Compound *>(Expr::Reference(pExpr));
	}
	virtual ~Expr_Compound();
	virtual bool IsCompound() const;
	virtual bool IsParentOf(const Expr *pExpr) const;
	inline Expr *GetCar() { return _pExprCar.get(); }
	inline const Expr *GetCar() const { return _pExprCar.get(); }
	inline ExprOwner &GetExprOwner() { return _pExprLister->GetExprOwner(); }
	inline const ExprOwner &GetExprOwner() const { return _pExprLister->GetExprOwner(); }
};

//-----------------------------------------------------------------------------
// Expr_Indexer
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Expr_Indexer : public Expr_Compound {
public:
	inline Expr_Indexer(Expr *pExprCar, Expr_Lister *pExprLister) :
			Expr_Compound(EXPRTYPE_Indexer, pExprCar, pExprLister) {}
	inline Expr_Indexer(const Expr_Indexer &expr) : Expr_Compound(expr) {}
	inline static Expr_Indexer *Reference(const Expr_Indexer *pExpr) {
		return dynamic_cast<Expr_Indexer *>(Expr::Reference(pExpr));
	}
	virtual bool IsIndexer() const;
	virtual Expr *Clone() const;
	virtual Value DoExec(Environment &env) const;
	virtual Value DoAssign(Environment &env, Value &value,
					const SymbolSet *pSymbolsAssignable, bool escalateFlag) const;
	virtual void Accept(ExprVisitor &visitor);
	virtual bool GenerateCode(Environment &env, CodeGenerator &codeGenerator) const;
	virtual bool GenerateScript(Signal &sig, SimpleStream &stream,
							ScriptStyle scriptStyle, int nestLevel, const char *strIndent) const;
};

//-----------------------------------------------------------------------------
// Expr_Caller
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Expr_Caller : public Expr_Compound {
protected:
	AutoPtr<Expr_Block> _pExprBlock;		// this may be nullptr
	AutoPtr<Expr_Caller> _pExprTrailer;		// this may be nullptr
	AutoPtr<SymbolSetShared> _pAttrsShrd;
	AutoPtr<SymbolSetShared> _pAttrsOptShrd;
	SymbolList _attrFront;
	std::unique_ptr<CallerInfo> _pCallerInfo;
public:
	Expr_Caller(Expr *pExprCar, Expr_Lister *pExprLister, Expr_Block *pExprBlock);
	Expr_Caller(const Expr_Caller &expr);
	inline static Expr_Caller *Reference(const Expr_Caller *pExpr) {
		return dynamic_cast<Expr_Caller *>(Expr::Reference(pExpr));
	}
	virtual ~Expr_Caller();
	virtual bool IsCaller() const;
	virtual Expr *Clone() const;
	virtual Callable *LookupCallable(Environment &env) const;
	virtual Value DoExec(Environment &env) const;
	virtual Value DoAssign(Environment &env, Value &value,
					const SymbolSet *pSymbolsAssignable, bool escalateFlag) const;
	virtual void Accept(ExprVisitor &visitor);
	virtual bool IsParentOf(const Expr *pExpr) const;
	virtual Expr *MathDiff(Environment &env, const Symbol *pSymbol) const;
	virtual Expr *MathOptimize(Environment &env) const;
	virtual bool GenerateCode(Environment &env, CodeGenerator &codeGenerator) const;
	virtual bool GenerateScript(Signal &sig, SimpleStream &stream,
							ScriptStyle scriptStyle, int nestLevel, const char *strIndent) const;
	static Expr_Caller *Create(const Symbol *pContainerSymbol, const Symbol *pFuncSymbol,
							   Expr *pExprArg1 = nullptr, Expr *pExprArg2 = nullptr,
							   Expr *pExprArg3 = nullptr, Expr *pExprArg4 = nullptr);
	Value EvalEach(Environment &env, const Value &valueThis,
		Iterator *pIteratorThis, bool listThisFlag, TrailCtrlHolder *pTrailCtrlHolder) const;
	void UpdateCallerInfo();
	bool AddAttr(const Symbol *pSymbol);
	void AddAttrs(const SymbolSet &symbolSet);
	inline void AddAttrOpt(const Symbol *pSymbol) {
		_pAttrsOptShrd->GetSymbolSet().Insert(pSymbol);
	}
	inline void AddAttrsOpt(const SymbolSet &symbolSet) {
		_pAttrsOptShrd->GetSymbolSet().Insert(symbolSet);
	}
	inline const SymbolSetShared *GetAttrsShared() const { return _pAttrsShrd.get(); }
	inline const SymbolSetShared *GetAttrsOptShared() const { return _pAttrsOptShrd.get(); }
	inline const SymbolSet &GetAttrs() const { return _pAttrsShrd->GetSymbolSet(); }
	inline const SymbolSet &GetAttrsOpt() const { return _pAttrsOptShrd->GetSymbolSet(); }
	inline SymbolList &GetAttrFront() { return _attrFront; }
	inline const SymbolList &GetAttrFront() const { return _attrFront; }
	inline void SetBlock(Expr_Block *pExprBlock) {
		_pExprBlock.reset(pExprBlock);
		if (!_pExprBlock.IsNull()) _pExprBlock->SetParent(this);
		UpdateCallerInfo();
	}
	inline void SetTrailer(Expr_Caller *pExprCaller) {
		_pExprTrailer.reset(pExprCaller);
		if (!_pExprTrailer.IsNull()) _pExprTrailer->SetParent(this);
	}
	inline Expr_Block *GetBlock() { return _pExprBlock.get(); }
	inline const Expr_Block *GetBlock() const { return _pExprBlock.get(); }
	inline const Expr_Caller *GetTrailer() const { return _pExprTrailer.get(); }
	inline Expr_Caller *GetLastTrailer() {
		return (_pExprTrailer.IsNull())? this : _pExprTrailer->GetLastTrailer();
	}
	inline const CallerInfo &GetCallerInfo() const { return *_pCallerInfo; }
private:
	Value DoExec(Environment &env, TrailCtrlHolder *pTrailCtrlHolder) const;
};

//-----------------------------------------------------------------------------
// Expr_UnaryOp
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Expr_UnaryOp : public Expr_Unary {
protected:
	const Operator *_pOperator;
	bool _suffixFlag;
public:
	inline Expr_UnaryOp(const Operator *pOperator, Expr *pExprChild, bool suffixFlag) :
					Expr_Unary(EXPRTYPE_UnaryOp, pExprChild),
					_pOperator(pOperator), _suffixFlag(suffixFlag) {}
	inline Expr_UnaryOp(const Expr_UnaryOp &expr) :
					Expr_Unary(expr),
					_pOperator(expr._pOperator), _suffixFlag(expr._suffixFlag) {}
	inline const Operator *GetOperator() const { return _pOperator; }
	inline static Expr_UnaryOp *Reference(const Expr_UnaryOp *pExpr) {
		return dynamic_cast<Expr_UnaryOp *>(Expr::Reference(pExpr));
	}
	virtual Expr *Clone() const;
	virtual Value DoExec(Environment &env) const;
	virtual Expr *MathDiff(Environment &env, const Symbol *pSymbol) const;
	virtual Expr *MathOptimize(Environment &env) const;
	virtual bool IsUnaryOp() const;
	virtual bool IsUnaryOpSuffix() const;
	virtual bool GenerateCode(Environment &env, CodeGenerator &codeGenerator) const;
	virtual bool GenerateScript(Signal &sig, SimpleStream &stream,
							ScriptStyle scriptStyle, int nestLevel, const char *strIndent) const;
	inline static bool IsSuffixed(const Expr *pExpr, const Symbol *pSymbol) {
		return pExpr->IsUnaryOpSuffix() && dynamic_cast<const Expr_UnaryOp *>(pExpr)->
								GetOperator()->GetSymbol()->IsIdentical(pSymbol);
	}
};

//-----------------------------------------------------------------------------
// Expr_BinaryOp
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Expr_BinaryOp : public Expr_Binary {
protected:
	const Operator *_pOperator;
public:
	inline Expr_BinaryOp(const Operator *pOperator, Expr *pExprLeft, Expr *pExprRight) :
					Expr_Binary(EXPRTYPE_BinaryOp, pExprLeft, pExprRight), _pOperator(pOperator) {}
	inline Expr_BinaryOp(const Expr_BinaryOp &expr) :
					Expr_Binary(expr), _pOperator(expr._pOperator) {}
	inline const Operator *GetOperator() const { return _pOperator; }
	inline static Expr_BinaryOp *Reference(const Expr_BinaryOp *pExpr) {
		return dynamic_cast<Expr_BinaryOp *>(Expr::Reference(pExpr));
	}
	virtual Expr *Clone() const;
	virtual Value DoExec(Environment &env) const;
	virtual Expr *MathDiff(Environment &env, const Symbol *pSymbol) const;
	virtual Expr *MathOptimize(Environment &env) const;
	virtual bool IsBinaryOp() const;
	virtual bool GenerateCode(Environment &env, CodeGenerator &codeGenerator) const;
	virtual bool GenerateScript(Signal &sig, SimpleStream &stream,
							ScriptStyle scriptStyle, int nestLevel, const char *strIndent) const;
};

//-----------------------------------------------------------------------------
// Expr_Quote
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Expr_Quote : public Expr_Unary {
public:
	inline Expr_Quote(Expr *pExprChild) : Expr_Unary(EXPRTYPE_Quote, pExprChild) {}
	inline Expr_Quote(const Expr_Quote &expr) : Expr_Unary(expr) {}
	inline static Expr_Quote *Reference(const Expr_Quote *pExpr) {
		return dynamic_cast<Expr_Quote *>(Expr::Reference(pExpr));
	}
	virtual Expr *Clone() const;
	virtual Value DoExec(Environment &env) const;
	virtual const Expr *Unquote() const;
	virtual bool IsQuote() const;
	virtual bool GenerateCode(Environment &env, CodeGenerator &codeGenerator) const;
	virtual bool GenerateScript(Signal &sig, SimpleStream &stream,
							ScriptStyle scriptStyle, int nestLevel, const char *strIndent) const;
};

//-----------------------------------------------------------------------------
// Expr_Assign
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Expr_Assign : public Expr_Binary {
private:
	const Operator *_pOperatorToApply;	// this may be nullptr
public:
	inline Expr_Assign(Expr *pExprLeft, Expr *pExprRight, const Operator *pOperatorToApply) :
				Expr_Binary(EXPRTYPE_Assign, pExprLeft, pExprRight), _pOperatorToApply(pOperatorToApply) {}
	inline Expr_Assign(const Expr_Assign &expr) :
				Expr_Binary(expr), _pOperatorToApply(expr._pOperatorToApply) {}
	inline static Expr_Assign *Reference(const Expr_Assign *pExpr) {
		return dynamic_cast<Expr_Assign *>(Expr::Reference(pExpr));
	}
	inline const Operator *GetOperatorToApply() const { return _pOperatorToApply; }
	virtual Value DoExec(Environment &env) const;
	Value Exec(Environment &env, Environment &envDst, const SymbolSet *pSymbolsAssignable) const;
	virtual Expr *Clone() const;
	virtual bool IsAssign() const;
	virtual bool GenerateCode(Environment &env, CodeGenerator &codeGenerator) const;
	virtual bool GenerateScript(Signal &sig, SimpleStream &stream,
							ScriptStyle scriptStyle, int nestLevel, const char *strIndent) const;
};

//-----------------------------------------------------------------------------
// Expr_Member
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Expr_Member : public Expr_Binary {
public:
	enum Mode {
		MODE_Normal,		// foo.bar
		MODE_MapToList,		// foo::bar .. map-to-list
		MODE_MapToIter,		// foo:*bar .. map-to-iterator
		MODE_MapAlong,		// foo:&bar .. map-along
	};
private:
	Mode _mode;
public:
	inline Expr_Member(Expr *pExprLeft, Expr *pExprRight, Mode mode = MODE_Normal) :
				Expr_Binary(EXPRTYPE_Member, pExprLeft, pExprRight), _mode(mode) {}
	inline Expr_Member(const Expr_Member &expr) : Expr_Binary(expr), _mode(expr._mode) {}
	inline Mode GetMode() const { return _mode; }
	inline static Expr_Member *Reference(const Expr_Member *pExpr) {
		return dynamic_cast<Expr_Member *>(Expr::Reference(pExpr));
	}
	virtual Expr *Clone() const;
	virtual Value DoExec(Environment &env) const;
	virtual Value DoAssign(Environment &env, Value &value,
					const SymbolSet *pSymbolsAssignable, bool escalateFlag) const;
	virtual bool IsMember() const;
	virtual bool GenerateCode(Environment &env, CodeGenerator &codeGenerator) const;
	virtual bool GenerateScript(Signal &sig, SimpleStream &stream,
							ScriptStyle scriptStyle, int nestLevel, const char *strIndent) const;
};

}

#endif
