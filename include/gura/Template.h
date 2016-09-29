//=============================================================================
// Template
//=============================================================================
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
		typedef std::vector<Expr_Caller *> ExprLeaderStack;
	private:
		bool _autoIndentFlag;
		bool _appendLastEOLFlag;
		ExprLeaderStack _exprLeaderStack;
	public:
		Parser(bool autoIndentFlag, bool appendLastEOLFlag);
		bool ParseStream(Environment &env,
							Template *pTemplate, SimpleStream &streamSrc);
	private:
		bool CreateTmplScript(Environment &env,
				const char *strIndent, const char *strTmplScript, const char *strPost,
				Template *pTemplate, Expr_Block *pExprBlock,
				StringShared *pSourceName, int cntLineTop, int cntLineBtm);
	};
private:
	int _cntRef;
	AutoPtr<Template> _pTemplateSuper;
	AutoPtr<ExprOwner> _pExprOwnerForInit;
	AutoPtr<FunctionCustom> _pFuncForBody;
	AutoPtr<ValueExMap> _pValueExMap;
	SimpleStream *_pStreamDst;
	char _chLast;
public:
	Gura_DeclareReferenceAccessor(Template);
public:
	Template();
private:
	inline ~Template() {}
public:
	bool Read(Environment &env,
			  SimpleStream &streamSrc, bool autoIndentFlag, bool appendLastEOLFlag);
	bool Parse(Environment &env,
			   String::const_iterator strSrc, String::const_iterator strSrcEnd,
			   bool autoIndentFlag, bool appendLastEOLFlag);
	bool Parse(Environment &env,
			   const char *strSrc, const char *strSrcEnd,
			   bool autoIndentFlag, bool appendLastEOLFlag);
	bool Render(Environment &env, SimpleStream *pStreamDst);
	bool Render(Environment &env, String &strDst);
	bool Prepare(Environment &env);
	const ValueEx *LookupValue(const Symbol *pSymbol) const;
	void PutChar(Signal &sig, char ch);
	void Print(Signal &sig, const char *str);
	inline void SetTemplateSuper(Template *pTemplateSuper) {
		_pTemplateSuper.reset(pTemplateSuper);
	}
	inline Template *GetTemplateSuper() { return _pTemplateSuper.get(); }
	inline const Template *GetTemplateSuper() const { return _pTemplateSuper.get(); }
	inline void SetFuncForBody(FunctionCustom *pFuncForBody) { _pFuncForBody.reset(pFuncForBody); }
	inline ExprOwner &GetExprOwnerForInit() { return *_pExprOwnerForInit; }
	inline FunctionCustom *GetFuncForBody() { return _pFuncForBody.get(); }
	inline const FunctionCustom *GetFuncForBody() const { return _pFuncForBody.get(); }
	inline ValueExMap &GetValueExMap() { return *_pValueExMap; }
	inline const ValueExMap &GetValueExMap() const { return *_pValueExMap; }
	inline void SetStreamDst(SimpleStream *pStreamDst) { _pStreamDst = pStreamDst; }
	inline SimpleStream *GetStreamDst() { return _pStreamDst; }
	inline void ClearLastChar()  { _chLast = '\0'; }
	inline char GetLastChar() const { return _chLast; }
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
	virtual Value DoExec(Environment &env) const;
	virtual void Accept(ExprVisitor &visitor);
	virtual bool GenerateCode(Environment &env, CodeGenerator &codeGenerator) const;
	virtual bool GenerateScript(Signal &sig, SimpleStream &stream,
							ScriptStyle scriptStyle, int nestLevel, const char *strIndent) const;
};

//-----------------------------------------------------------------------------
// Expr_TmplScript
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Expr_TmplScript : public Expr_Collector {
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
			Expr_Collector(EXPRTYPE_None), _pTemplate(pTemplate),
			_strIndent(strIndent), _strPost(strPost),
			_autoIndentFlag(autoIndentFlag), _appendLastEOLFlag(appendLastEOLFlag) {}
	inline Expr_TmplScript(const Expr_TmplScript &expr) :
			Expr_Collector(expr), _pTemplate(expr._pTemplate),
			_strIndent(expr._strIndent), _strPost(expr._strPost),
			_autoIndentFlag(expr._autoIndentFlag), _appendLastEOLFlag(expr._appendLastEOLFlag) {}
	inline void SetStringIndent(const String &strIndent) { _strIndent = strIndent; }
	inline void SetStringPost(const String &strPost) { _strPost = strPost; }
	inline static Expr_TmplScript *Reference(const Expr_TmplScript *pExpr) {
		return dynamic_cast<Expr_TmplScript *>(Expr::Reference(pExpr));
	}
	virtual Expr *Clone() const;
	virtual Value DoExec(Environment &env) const;
	virtual bool GenerateCode(Environment &env, CodeGenerator &codeGenerator) const;
	virtual bool GenerateScript(Signal &sig, SimpleStream &stream,
							ScriptStyle scriptStyle, int nestLevel, const char *strIndent) const;
};

}

#endif
