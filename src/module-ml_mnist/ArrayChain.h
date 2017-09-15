#ifndef __GURA_ARRAYCHAIN_H__
#define __GURA_ARRAYCHAIN_H__
#include <gura.h>


namespace Gura {

class ArrayEx;

//-----------------------------------------------------------------------------
// ArrayEx
//-----------------------------------------------------------------------------
class ArrayEx {
public:
	class Connector {
	private:
		ArrayEx *_pArrayExSrc;
		ArrayEx *_pArrayExDst;
		AutoPtr<Array> _pArrayBwd;
		bool _constSrcFlag;
	public:
		inline Connector(ArrayEx *pArrayExDst) :
			_pArrayExSrc(nullptr), _pArrayExDst(pArrayExDst), _constSrcFlag(false) {}
		inline ArrayEx *GetArrayExSrc() { return _pArrayExSrc; }
		inline ArrayEx *GetArrayExDst() { return _pArrayExDst; }
		inline void SetArrayExSrc(ArrayEx *pArrayExSrc) {
			_pArrayExSrc = pArrayExSrc;
		}
		inline void SetArrayBwd(Array *pArrayBwd) { _pArrayBwd.reset(pArrayBwd); }
		inline Array *GetArrayFwd() { return _pArrayExSrc->GetArrayFwd(); }
		inline Array *GetArrayBwd() { return _pArrayBwd.get(); }
		inline void SetConstSrcFlag(bool constSrcFlag) { _constSrcFlag = constSrcFlag; }
		inline bool IsSourceConstant() const { return _constSrcFlag; }
	};
	class ConnectorList : public std::vector<Connector *> {
	public:
		inline ConnectorList() {}
	};
protected:
	ConnectorList _connectorsDst;
	AutoPtr<Array> _pArrayFwd;
public:
	inline ArrayEx() {}
	ArrayEx(Connector *pConnectorDst);
	virtual ~ArrayEx();
	inline void AddConnectorDst(Connector *pConnectorDst) { _connectorsDst.push_back(pConnectorDst); }
	inline Array *GetArrayFwd() { return _pArrayFwd.get(); }
	virtual bool InitForward(Environment &env) = 0;
	virtual bool EvalForward(Environment &env) = 0;
	virtual bool InitBackward(Environment &env) = 0;
	virtual bool EvalBackward(Environment &env) = 0;
	virtual void Print(int indentLevel) = 0;
};

//-----------------------------------------------------------------------------
// ArrayExHead
//-----------------------------------------------------------------------------
class ArrayExHead : public ArrayEx {
protected:
	AutoPtr<Expr> _pExpr;
public:
	inline ArrayExHead(Connector *pConnectorDst, Expr *pExpr) : ArrayEx(pConnectorDst), _pExpr(pExpr) {}
	virtual bool InitForward(Environment &env);
	virtual bool EvalForward(Environment &env);
	virtual bool InitBackward(Environment &env);
	virtual bool EvalBackward(Environment &env);
	virtual void Print(int indentLevel);
};

//-----------------------------------------------------------------------------
// ArrayExTail
//-----------------------------------------------------------------------------
class ArrayExTail : public ArrayEx {
private:
	Connector _connectorSrc;
public:
	inline ArrayExTail() : ArrayEx(), _connectorSrc(this) {}
	inline Connector *GetConnectorSrc() { return &_connectorSrc; }
	virtual bool InitForward(Environment &env);
	virtual bool EvalForward(Environment &env);
	virtual bool InitBackward(Environment &env);
	virtual bool EvalBackward(Environment &env);
	virtual void Print(int indentLevel);
};

//-----------------------------------------------------------------------------
// ArrayExUnary
//-----------------------------------------------------------------------------
class ArrayExUnary : public ArrayEx {
protected:
	const Array::UnaryFuncPack &_unaryFuncPack;
	Connector _connectorSrc;
public:
	inline ArrayExUnary(const Array::UnaryFuncPack &unaryFuncPack, Connector *pConnectorDst) :
		_unaryFuncPack(unaryFuncPack), ArrayEx(pConnectorDst), _connectorSrc(this) {}
	inline Connector *GetConnectorSrc() { return &_connectorSrc; }
	virtual bool InitForward(Environment &env);
	virtual bool EvalForward(Environment &env);
	virtual void Print(int indentLevel);
};

//-----------------------------------------------------------------------------
// ArrayExUnary_Pos
//-----------------------------------------------------------------------------
class ArrayExUnary_Pos : public ArrayExUnary {
public:
	inline ArrayExUnary_Pos(Connector *pConnectorDst) :
		ArrayExUnary(Array::unaryFuncPack_Pos, pConnectorDst) {}
	virtual bool InitBackward(Environment &env);
	virtual bool EvalBackward(Environment &env);
};

//-----------------------------------------------------------------------------
// ArrayExUnary_Neg
//-----------------------------------------------------------------------------
class ArrayExUnary_Neg : public ArrayExUnary {
public:
	inline ArrayExUnary_Neg(Connector *pConnectorDst) :
		ArrayExUnary(Array::unaryFuncPack_Pos, pConnectorDst) {}
	virtual bool InitBackward(Environment &env);
	virtual bool EvalBackward(Environment &env);
};

//-----------------------------------------------------------------------------
// ArrayExUnary_Math_relu
//-----------------------------------------------------------------------------
class ArrayExUnary_Math_relu : public ArrayExUnary {
public:
	inline ArrayExUnary_Math_relu(Connector *pConnectorDst) :
		ArrayExUnary(Array::unaryFuncPack_Math_relu, pConnectorDst) {}
	virtual bool InitBackward(Environment &env);
	virtual bool EvalBackward(Environment &env);
};

//-----------------------------------------------------------------------------
// ArrayExUnary_Math_sigmoid
//-----------------------------------------------------------------------------
class ArrayExUnary_Math_sigmoid : public ArrayExUnary {
public:
	inline ArrayExUnary_Math_sigmoid(Connector *pConnectorDst) :
		ArrayExUnary(Array::unaryFuncPack_Math_sigmoid, pConnectorDst) {}
	virtual bool InitBackward(Environment &env);
	virtual bool EvalBackward(Environment &env);
};

//-----------------------------------------------------------------------------
// ArrayExBinary
//-----------------------------------------------------------------------------
class ArrayExBinary : public ArrayEx {
protected:
	const Array::BinaryFuncPack &_binaryFuncPack;
	Connector _connectorSrcLeft;
	Connector _connectorSrcRight;
public:
	inline ArrayExBinary(const Array::BinaryFuncPack &binaryFuncPack, Connector *pConnectorDst) :
		_binaryFuncPack(binaryFuncPack), ArrayEx(pConnectorDst),
		_connectorSrcLeft(this), _connectorSrcRight(this) {}
	inline Connector *GetConnectorSrcLeft() { return &_connectorSrcLeft; }
	inline Connector *GetConnectorSrcRight() { return &_connectorSrcRight; }
	virtual bool InitForward(Environment &env);
	virtual bool EvalForward(Environment &env);
	virtual void Print(int indentLevel);
};

//-----------------------------------------------------------------------------
// ArrayExBinary_Add
//-----------------------------------------------------------------------------
class ArrayExBinary_Add : public ArrayExBinary {
public:
	inline ArrayExBinary_Add(Connector *pConnectorDst) :
		ArrayExBinary(Array::binaryFuncPack_Add, pConnectorDst) {}
	virtual bool InitBackward(Environment &env);
	virtual bool EvalBackward(Environment &env);
};

//-----------------------------------------------------------------------------
// ArrayExBinary_Sub
//-----------------------------------------------------------------------------
class ArrayExBinary_Sub : public ArrayExBinary {
public:
	inline ArrayExBinary_Sub(Connector *pConnectorDst) :
		ArrayExBinary(Array::binaryFuncPack_Sub, pConnectorDst) {}
	virtual bool InitBackward(Environment &env);
	virtual bool EvalBackward(Environment &env);
};

//-----------------------------------------------------------------------------
// ArrayExBinary_Mul
//-----------------------------------------------------------------------------
class ArrayExBinary_Mul : public ArrayExBinary {
public:
	inline ArrayExBinary_Mul(Connector *pConnectorDst) :
		ArrayExBinary(Array::binaryFuncPack_Mul, pConnectorDst) {}
	virtual bool InitBackward(Environment &env);
	virtual bool EvalBackward(Environment &env);
};

//-----------------------------------------------------------------------------
// ArrayExBinary_Div
//-----------------------------------------------------------------------------
class ArrayExBinary_Div : public ArrayExBinary {
public:
	inline ArrayExBinary_Div(Connector *pConnectorDst) :
		ArrayExBinary(Array::binaryFuncPack_Div, pConnectorDst) {}
	virtual bool InitBackward(Environment &env);
	virtual bool EvalBackward(Environment &env);
};

//-----------------------------------------------------------------------------
// ArrayExBinary_Pow
//-----------------------------------------------------------------------------
class ArrayExBinary_Pow : public ArrayExBinary {
public:
	inline ArrayExBinary_Pow(Connector *pConnectorDst) :
		ArrayExBinary(Array::binaryFuncPack_Pow, pConnectorDst) {}
	virtual bool InitBackward(Environment &env);
	virtual bool EvalBackward(Environment &env);
};

//-----------------------------------------------------------------------------
// ArrayExBinary_Dot
//-----------------------------------------------------------------------------
class ArrayExBinary_Dot : public ArrayExBinary {
private:
	AutoPtr<Array> _pArrayFwdLeftTrans;
	AutoPtr<Array> _pArrayFwdRightTrans;
public:
	inline ArrayExBinary_Dot(Connector *pConnectorDst) :
		ArrayExBinary(Array::binaryFuncPack_Dot, pConnectorDst) {}
	virtual bool InitBackward(Environment &env);
	virtual bool EvalBackward(Environment &env);
};

#if 0
//-----------------------------------------------------------------------------
// ArrayExBinary_Filter
//-----------------------------------------------------------------------------
class ArrayExBinary_Filter : public ArrayExBinary {
public:
	inline ArrayExBinary_Filter(Connector *pConnectorDst) :
		ArrayExBinary(Array::binaryFuncPack_Filter, pConnectorDst) {}
	virtual bool InitBackward(Environment &env);
	virtual bool EvalBackward(Environment &env);
};
#endif

//-----------------------------------------------------------------------------
// ArrayExList
//-----------------------------------------------------------------------------
class ArrayExList : public std::vector<ArrayEx *> {
public:
	inline ArrayExList() {}
	bool InitForward(Environment &env);
	bool InitBackward(Environment &env);
	bool EvalForward(Environment &env);
	bool EvalBackward(Environment &env);
};

//-----------------------------------------------------------------------------
// ArrayExOwner
//-----------------------------------------------------------------------------
class ArrayExOwner : public ArrayExList {
public:
	~ArrayExOwner();
	void Clear();
};

//-----------------------------------------------------------------------------
// ArrayChain
//-----------------------------------------------------------------------------
class ArrayChain {
private:
	int _cntRef;
	ArrayExOwner _arrayItemOwner;
public:
	Gura_DeclareReferenceAccessor(ArrayChain);
public:
	inline ArrayChain() : _cntRef(1) {}
protected:
	virtual ~ArrayChain();
public:
	inline const ArrayExOwner &GetArrayExOwner() const { return _arrayItemOwner; }
	bool CreateFromExpr(Environment &env, const Expr *pExpr);
	void Print() const;
private:
	bool CreateFromExprSub(Environment &env, const Expr *pExpr, ArrayEx::Connector *pConnector);
};

}

#endif

