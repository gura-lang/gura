#ifndef __GURA_TEMPLATE_H__
#define __GURA_TEMPLATE_H__

#include "Parser.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Template
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Template {
public:
	class GURA_DLLDECLARE Parser {
	public:
		typedef std::vector<Expr_Caller *> ExprCallerStack;
	private:
		bool _autoIndentFlag;
		bool _appendLastEOLFlag;
		ExprCallerStack _exprCallerStack;
	public:
		Parser(bool autoIndentFlag, bool appendLastEOLFlag);
		bool EvalStream(Environment &env, Signal sig,
						SimpleStream &streamSrc, SimpleStream &streamDst);
		Template *ParseStream(Environment &env, Signal sig, SimpleStream &streamSrc);
	private:
		bool CreateTmplScript(Environment &env, Signal sig,
				const char *strIndent, const char *strTmplScript, const char *strPost,
				Template *pTemplate, Expr_Block *pExprBlock,
				StringRef *pSourceName, int cntLineTop, int cntLineBtm);
	};
private:
	int _cntRef;
	AutoPtr<Template> _pTemplateSuper;
	AutoPtr<ExprOwner> _pExprOwnerForInit;
	AutoPtr<FunctionCustom> _pFuncForBody;
	AutoPtr<ValueMap> _pValueMap;
	SimpleStream *_pStreamDst;
public:
	Gura_DeclareReferenceAccessor(Template);
public:
	Template();
private:
	inline ~Template() {}
public:
	bool Eval(Environment &env, Signal sig, SimpleStream *pStreamDst);
	bool Prepare(Environment &env, Signal sig);
	const ValueEx *LookupValue(const Symbol *pSymbol) const;
	inline void SetTemplateSuper(Template *pTemplateSuper) {
		_pTemplateSuper.reset(pTemplateSuper);
	}
	inline const Template *GetTemplateSuper() const { return _pTemplateSuper.get(); }
	inline void SetFuncForBody(FunctionCustom *pFuncForBody) { _pFuncForBody.reset(pFuncForBody); }
	inline ExprOwner &GetExprOwnerForInit() { return *_pExprOwnerForInit; }
	inline const FunctionCustom *GetFuncForBody() { return _pFuncForBody.get(); }
	inline ValueMap &GetValueMap() { return *_pValueMap; }
	inline const ValueMap &GetValueMap() const { return *_pValueMap; }
	inline SimpleStream *GetStreamDst() { return _pStreamDst; }
};

//-----------------------------------------------------------------------------
// Expr_TmplString
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Expr_TmplString : public Expr {
protected:
	Template *_pTemplate;
	String _str;
public:
	inline Expr_TmplString(Template *pTemplate, const String &str) :
				Expr(EXPRTYPE_None), _pTemplate(pTemplate), _str(str) {}
	inline Expr_TmplString(const Expr_TmplString &expr) :
				Expr(expr), _pTemplate(expr._pTemplate), _str(expr._str) {}
	inline const char *GetString() const { return _str.c_str(); }
	inline static Expr_TmplString *Reference(const Expr_TmplString *pExpr) {
		return dynamic_cast<Expr_TmplString *>(Expr::Reference(pExpr));
	}
	virtual Expr *Clone() const;
	virtual Value DoExec(Environment &env, Signal sig, SeqPostHandler *pSeqPostHandler) const;
	virtual void Accept(ExprVisitor &visitor) const;
	virtual bool GenerateCode(Environment &env, Signal sig, Stream &stream);
	virtual bool GenerateScript(Signal sig, SimpleStream &stream,
							ScriptStyle scriptStyle, int nestLevel) const;
};

//-----------------------------------------------------------------------------
// Expr_TmplScript
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Expr_TmplScript : public Expr_Container {
public:
	class GURA_DLLDECLARE SequenceEx : public Sequence {
	public:
		SequenceEx(Environment *pEnv);
		virtual bool DoStep(Signal sig, Value &result);
		virtual String ToString() const;
	};
protected:
	Template *_pTemplate;
	String _strIndent;
	String _strPost;
	bool _autoIndentFlag;
	bool _appendLastEOLFlag;
public:
	inline Expr_TmplScript(Template *pTemplate,
							const String &strIndent, const String &strPost,
							bool autoIndentFlag, bool appendLastEOLFlag) :
			Expr_Container(EXPRTYPE_None), _pTemplate(pTemplate),
			_strIndent(strIndent), _strPost(strPost),
			_autoIndentFlag(autoIndentFlag), _appendLastEOLFlag(appendLastEOLFlag) {}
	inline Expr_TmplScript(const Expr_TmplScript &expr) :
			Expr_Container(expr), _pTemplate(expr._pTemplate),
			_strIndent(expr._strIndent), _strPost(expr._strPost),
			_autoIndentFlag(expr._autoIndentFlag), _appendLastEOLFlag(expr._appendLastEOLFlag) {}
	inline void SetStringIndent(const String &strIndent) { _strIndent = strIndent; }
	inline void SetStringPost(const String &strPost) { _strPost = strPost; }
	inline static Expr_TmplScript *Reference(const Expr_TmplScript *pExpr) {
		return dynamic_cast<Expr_TmplScript *>(Expr::Reference(pExpr));
	}
	virtual Expr *Clone() const;
	virtual Value DoExec(Environment &env, Signal sig, SeqPostHandler *pSeqPostHandler) const;
	virtual bool GenerateCode(Environment &env, Signal sig, Stream &stream);
	virtual bool GenerateScript(Signal sig, SimpleStream &stream,
							ScriptStyle scriptStyle, int nestLevel) const;
};

}

#endif
