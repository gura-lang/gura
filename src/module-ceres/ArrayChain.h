#ifndef __GURA_ARRAYCHAIN_H__
#define __GURA_ARRAYCHAIN_H__
#include <gura.h>

namespace Gura {

class ArrayChain;

//-----------------------------------------------------------------------------
// ArrayChainList
//-----------------------------------------------------------------------------
class ArrayChainList : public std::vector<ArrayChain *> {
public:
	inline ArrayChainList() {}
	bool InitForward(Environment &env);
	bool InitBackward(Environment &env);
	bool EvalForward(Environment &env);
	bool EvalBackward(Environment &env);
};

//-----------------------------------------------------------------------------
// ArrayChain
//-----------------------------------------------------------------------------
class ArrayChain {
public:
	class Connector {
	private:
		ArrayChain *_pArrayChainSrc;
		ArrayChain *_pArrayChainDst;
		AutoPtr<Array> _pArrayBwd;
	public:
		inline Connector(ArrayChain *pArrayChainDst) :
		_pArrayChainSrc(nullptr), _pArrayChainDst(pArrayChainDst) {}
		inline ArrayChain *GetArrayChainSrc() { return _pArrayChainSrc; }
		inline ArrayChain *GetArrayChainDst() { return _pArrayChainDst; }
		inline void SetArrayChainSrc(ArrayChain *pArrayChainSrc) {
			_pArrayChainSrc = pArrayChainSrc;
		}
		inline void SetArrayBwd(Array *pArrayBwd) { _pArrayBwd.reset(pArrayBwd); }
		inline Array *GetArrayFwd() { return _pArrayChainSrc->GetArrayFwd(); }
		inline Array *GetArrayBwd() { return _pArrayBwd.get(); }
	};
	class ConnectorList : public std::vector<Connector *> {
	public:
		inline ConnectorList() {}
	};
protected:
	ConnectorList _connectorsDst;
	AutoPtr<Array> _pArrayFwd;
public:
	inline ArrayChain() {}
	ArrayChain(Connector *pConnectorDst);
	virtual ~ArrayChain();
	inline void AddConnectorDst(Connector *pConnectorDst) { _connectorsDst.push_back(pConnectorDst); }
	inline Array *GetArrayFwd() { return _pArrayFwd.get(); }
	virtual bool InitForward(Environment &env) = 0;
	virtual bool EvalForward(Environment &env) = 0;
	virtual bool InitBackward(Environment &env) = 0;
	virtual bool EvalBackward(Environment &env) = 0;
	virtual void Print(int indentLevel) = 0;
};

//-----------------------------------------------------------------------------
// ArrayChainHead
//-----------------------------------------------------------------------------
class ArrayChainHead : public ArrayChain {
protected:
	AutoPtr<Expr> _pExpr;
public:
	inline ArrayChainHead(Connector *pConnectorDst, Expr *pExpr) : ArrayChain(pConnectorDst), _pExpr(pExpr) {}
	virtual bool InitForward(Environment &env);
	virtual bool EvalForward(Environment &env);
	virtual bool InitBackward(Environment &env);
	virtual bool EvalBackward(Environment &env);
	virtual void Print(int indentLevel);
};

//-----------------------------------------------------------------------------
// ArrayChainTail
//-----------------------------------------------------------------------------
class ArrayChainTail : public ArrayChain {
private:
	Connector _connectorSrc;
public:
	inline ArrayChainTail() : ArrayChain(), _connectorSrc(this) {}
	inline Connector *GetConnectorSrc() { return &_connectorSrc; }
	virtual bool InitForward(Environment &env);
	virtual bool EvalForward(Environment &env);
	virtual bool InitBackward(Environment &env);
	virtual bool EvalBackward(Environment &env);
	virtual void Print(int indentLevel);
};

//-----------------------------------------------------------------------------
// ArrayChainUnary
//-----------------------------------------------------------------------------
class ArrayChainUnary : public ArrayChain {
protected:
	const Array::UnaryFuncPack &_unaryFuncPack;
	Connector _connectorSrc;
public:
	inline ArrayChainUnary(const Array::UnaryFuncPack &unaryFuncPack, Connector *pConnectorDst) :
		_unaryFuncPack(unaryFuncPack), ArrayChain(pConnectorDst), _connectorSrc(this) {}
	inline Connector *GetConnectorSrc() { return &_connectorSrc; }
	virtual bool InitForward(Environment &env);
	virtual bool EvalForward(Environment &env);
	virtual void Print(int indentLevel);
};

//-----------------------------------------------------------------------------
// ArrayChainUnary_Pos
//-----------------------------------------------------------------------------
class ArrayChainUnary_Pos : public ArrayChainUnary {
public:
	inline ArrayChainUnary_Pos(Connector *pConnectorDst) :
		ArrayChainUnary(Array::unaryFuncPack_Pos, pConnectorDst) {}
	virtual bool InitBackward(Environment &env);
	virtual bool EvalBackward(Environment &env);
};

//-----------------------------------------------------------------------------
// ArrayChainUnary_Neg
//-----------------------------------------------------------------------------
class ArrayChainUnary_Neg : public ArrayChainUnary {
public:
	inline ArrayChainUnary_Neg(Connector *pConnectorDst) :
		ArrayChainUnary(Array::unaryFuncPack_Pos, pConnectorDst) {}
	virtual bool InitBackward(Environment &env);
	virtual bool EvalBackward(Environment &env);
};

//-----------------------------------------------------------------------------
// ArrayChainUnary_Math_relu
//-----------------------------------------------------------------------------
class ArrayChainUnary_Math_relu : public ArrayChainUnary {
public:
	inline ArrayChainUnary_Math_relu(Connector *pConnectorDst) :
		ArrayChainUnary(Array::unaryFuncPack_Math_relu, pConnectorDst) {}
	virtual bool InitBackward(Environment &env);
	virtual bool EvalBackward(Environment &env);
};

//-----------------------------------------------------------------------------
// ArrayChainUnary_Math_sigmoid
//-----------------------------------------------------------------------------
class ArrayChainUnary_Math_sigmoid : public ArrayChainUnary {
public:
	inline ArrayChainUnary_Math_sigmoid(Connector *pConnectorDst) :
		ArrayChainUnary(Array::unaryFuncPack_Math_sigmoid, pConnectorDst) {}
	virtual bool InitBackward(Environment &env);
	virtual bool EvalBackward(Environment &env);
};

//-----------------------------------------------------------------------------
// ArrayChainBinary
//-----------------------------------------------------------------------------
class ArrayChainBinary : public ArrayChain {
protected:
	const Array::BinaryFuncPack &_binaryFuncPack;
	Connector _connectorSrcLeft;
	Connector _connectorSrcRight;
public:
	inline ArrayChainBinary(const Array::BinaryFuncPack &binaryFuncPack, Connector *pConnectorDst) :
		_binaryFuncPack(binaryFuncPack), ArrayChain(pConnectorDst),
		_connectorSrcLeft(this), _connectorSrcRight(this) {}
	inline Connector *GetConnectorSrcLeft() { return &_connectorSrcLeft; }
	inline Connector *GetConnectorSrcRight() { return &_connectorSrcRight; }
	virtual bool InitForward(Environment &env);
	virtual bool EvalForward(Environment &env);
	virtual void Print(int indentLevel);
};

//-----------------------------------------------------------------------------
// ArrayChainBinary_Add
//-----------------------------------------------------------------------------
class ArrayChainBinary_Add : public ArrayChainBinary {
public:
	inline ArrayChainBinary_Add(Connector *pConnectorDst) :
		ArrayChainBinary(Array::binaryFuncPack_Add, pConnectorDst) {}
	virtual bool InitBackward(Environment &env);
	virtual bool EvalBackward(Environment &env);
};

//-----------------------------------------------------------------------------
// ArrayChainBinary_Sub
//-----------------------------------------------------------------------------
class ArrayChainBinary_Sub : public ArrayChainBinary {
public:
	inline ArrayChainBinary_Sub(Connector *pConnectorDst) :
		ArrayChainBinary(Array::binaryFuncPack_Sub, pConnectorDst) {}
	virtual bool InitBackward(Environment &env);
	virtual bool EvalBackward(Environment &env);
};

//-----------------------------------------------------------------------------
// ArrayChainBinary_Mul
//-----------------------------------------------------------------------------
class ArrayChainBinary_Mul : public ArrayChainBinary {
public:
	inline ArrayChainBinary_Mul(Connector *pConnectorDst) :
		ArrayChainBinary(Array::binaryFuncPack_Mul, pConnectorDst) {}
	virtual bool InitBackward(Environment &env);
	virtual bool EvalBackward(Environment &env);
};

//-----------------------------------------------------------------------------
// ArrayChainBinary_Div
//-----------------------------------------------------------------------------
class ArrayChainBinary_Div : public ArrayChainBinary {
public:
	inline ArrayChainBinary_Div(Connector *pConnectorDst) :
		ArrayChainBinary(Array::binaryFuncPack_Div, pConnectorDst) {}
	virtual bool InitBackward(Environment &env);
	virtual bool EvalBackward(Environment &env);
};

//-----------------------------------------------------------------------------
// ArrayChainBinary_Pow
//-----------------------------------------------------------------------------
class ArrayChainBinary_Pow : public ArrayChainBinary {
public:
	inline ArrayChainBinary_Pow(Connector *pConnectorDst) :
		ArrayChainBinary(Array::binaryFuncPack_Pow, pConnectorDst) {}
	virtual bool InitBackward(Environment &env);
	virtual bool EvalBackward(Environment &env);
};

//-----------------------------------------------------------------------------
// ArrayChainBinary_DotProd
//-----------------------------------------------------------------------------
class ArrayChainBinary_DotProd : public ArrayChainBinary {
public:
	inline ArrayChainBinary_DotProd(Connector *pConnectorDst) :
		ArrayChainBinary(Array::binaryFuncPack_DotProd, pConnectorDst) {}
	virtual bool InitBackward(Environment &env);
	virtual bool EvalBackward(Environment &env);
};

//-----------------------------------------------------------------------------
// ArrayChainOwner
//-----------------------------------------------------------------------------
class ArrayChainOwner : public ArrayChainList {
public:
	~ArrayChainOwner();
	void Clear();
	bool CreateFromExpr(Environment &env, const Expr *pExpr);
private:
	bool CreateFromExprSub(Environment &env, const Expr *pExpr, ArrayChain::Connector *pConnector);
};

}

#endif

