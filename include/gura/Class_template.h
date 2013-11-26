#ifndef __GURA_CLASS_TEMPLATE_H__
#define __GURA_CLASS_TEMPLATE_H__

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
	public:
		Parser(bool autoIndentFlag, bool appendLastEOLFlag);
		bool EvalStream(Environment &env, Signal sig,
						SimpleStream &streamSrc, SimpleStream &streamDst);
	private:
		bool ParseScript(Environment &env, Signal sig,
				const char *strIndent, const char *strScript, const char *strPost,
				SimpleStream &streamDst, ExprOwner &exprOwnerRoot,
				ExprCallerStack &exprCallerStack,
				const char *sourceName, int cntLineStart);
	};
private:
	int _cntRef;
	AutoPtr<ExprOwner> _pExprOwnerRoot;
	Stream *_pStreamDst;
public:
	Gura_DeclareReferenceAccessor(Template);
public:
	Template(ExprOwner *pExprOwnerRoot);
private:
	inline ~Template() {}
public:
	bool Eval(Environment &env, Signal sig, Stream *pStreamDst);
	inline Stream *GetStreamDst() { return _pStreamDst; }
};

//-----------------------------------------------------------------------------
// Expr_TmplString
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Expr_TmplString : public Expr {
protected:
	SimpleStream &_streamDst;
	String _str;
public:
	inline Expr_TmplString(SimpleStream &streamDst, const String &str) :
				Expr(EXPRTYPE_None), _streamDst(streamDst), _str(str) {}
	inline Expr_TmplString(const Expr_TmplString &expr) :
				Expr(expr), _streamDst(expr._streamDst), _str(expr._str) {}
	inline SimpleStream &GetStreamDst() { return _streamDst;; }
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
	SimpleStream &_streamDst;
	String _strIndent;
	String _strPost;
	bool _autoIndentFlag;
	bool _appendLastEOLFlag;
public:
	inline Expr_TmplScript(SimpleStream &streamDst,
							const String &strIndent, const String &strPost,
							bool autoIndentFlag, bool appendLastEOLFlag) :
			Expr_Container(EXPRTYPE_None), _streamDst(streamDst),
			_strIndent(strIndent), _strPost(strPost),
			_autoIndentFlag(autoIndentFlag), _appendLastEOLFlag(appendLastEOLFlag) {}
	inline Expr_TmplScript(const Expr_TmplScript &expr) :
			Expr_Container(expr), _streamDst(expr._streamDst),
			_strIndent(expr._strIndent), _strPost(expr._strPost),
			_autoIndentFlag(expr._autoIndentFlag), _appendLastEOLFlag(expr._appendLastEOLFlag) {}
	inline SimpleStream &GetStreamDst() { return _streamDst;; }
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
