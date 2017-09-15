#ifndef __GURA_ARRAYCHAIN_H__
#define __GURA_ARRAYCHAIN_H__
#include <gura.h>

namespace Gura {

class ArrayNode;

//-----------------------------------------------------------------------------
// ArrayNode
//-----------------------------------------------------------------------------
class ArrayNode {
public:
	class Connector {
	private:
		ArrayNode *_pArrayNodeSrc;
		ArrayNode *_pArrayNodeDst;
		AutoPtr<Array> _pArrayBwd;
	public:
		inline Connector(ArrayNode *pArrayNodeDst) :
			_pArrayNodeSrc(nullptr), _pArrayNodeDst(pArrayNodeDst) {}
		inline ArrayNode *GetArrayNodeSrc() { return _pArrayNodeSrc; }
		inline ArrayNode *GetArrayNodeDst() { return _pArrayNodeDst; }
		inline void SetArrayNodeSrc(ArrayNode *pArrayNodeSrc) {
			_pArrayNodeSrc = pArrayNodeSrc;
		}
		inline void SetArrayBwd(Array *pArrayBwd) { _pArrayBwd.reset(pArrayBwd); }
		inline Array *GetArrayFwd() { return _pArrayNodeSrc->GetArrayFwd(); }
		inline Array *GetArrayBwd() { return _pArrayBwd.get(); }
		inline const Array *GetArrayFwd() const { return _pArrayNodeSrc->GetArrayFwd(); }
		inline const Array *GetArrayBwd() const { return _pArrayBwd.get(); }
		inline bool IsSourceConstant() const { return _pArrayNodeSrc->IsConstant(); }
	};
	class ConnectorList : public std::vector<Connector *> {
	public:
		inline ConnectorList() {}
	};
protected:
	int _cntRef;
	ConnectorList _connectorsDst;
	AutoPtr<Array> _pArrayFwd;
	bool _constantFlag;
public:
	Gura_DeclareReferenceAccessor(ArrayNode);
public:
	inline ArrayNode() : _cntRef(1), _constantFlag(false) {}
	ArrayNode(Connector *pConnectorDst);
protected:
	virtual ~ArrayNode();
public:
	inline void AddConnectorDst(Connector *pConnectorDst) { _connectorsDst.push_back(pConnectorDst); }
	inline Array *GetArrayFwd() { return _pArrayFwd.get(); }
	inline bool IsConstant() const { return _constantFlag; }
	inline void SetConstantFlag(bool constantFlag) { _constantFlag = constantFlag; }
	virtual bool InitForward(Environment &env) = 0;
	virtual bool EvalForward(Environment &env) = 0;
	virtual bool InitBackward(Environment &env) = 0;
	virtual bool EvalBackward(Environment &env) = 0;
	virtual void Print(int indentLevel) = 0;
};

//-----------------------------------------------------------------------------
// ArrayNodeHead
//-----------------------------------------------------------------------------
class ArrayNodeHead : public ArrayNode {
protected:
	AutoPtr<Expr> _pExpr;
public:
	inline ArrayNodeHead(Connector *pConnectorDst, Expr *pExpr) : ArrayNode(pConnectorDst), _pExpr(pExpr) {}
	virtual bool InitForward(Environment &env);
	virtual bool EvalForward(Environment &env);
	virtual bool InitBackward(Environment &env);
	virtual bool EvalBackward(Environment &env);
	virtual void Print(int indentLevel);
};

//-----------------------------------------------------------------------------
// ArrayNodeBottom
//-----------------------------------------------------------------------------
class ArrayNodeBottom : public ArrayNode {
private:
	Connector _connectorSrc;
public:
	inline ArrayNodeBottom() : ArrayNode(), _connectorSrc(this) {}
	inline Connector *GetConnectorSrc() { return &_connectorSrc; }
	virtual bool InitForward(Environment &env);
	virtual bool EvalForward(Environment &env);
	virtual bool InitBackward(Environment &env);
	virtual bool EvalBackward(Environment &env);
	bool EvalBackwardTop(Environment &env, const Array *pArrayCorrect);
	virtual void Print(int indentLevel);
};

//-----------------------------------------------------------------------------
// ArrayNodeUnary
//-----------------------------------------------------------------------------
class ArrayNodeUnary : public ArrayNode {
protected:
	const Array::UnaryFuncPack &_unaryFuncPack;
	Connector _connectorSrc;
public:
	inline ArrayNodeUnary(const Array::UnaryFuncPack &unaryFuncPack, Connector *pConnectorDst) :
		ArrayNode(pConnectorDst), _unaryFuncPack(unaryFuncPack), _connectorSrc(this) {}
	inline Connector *GetConnectorSrc() { return &_connectorSrc; }
	virtual bool InitForward(Environment &env);
	virtual bool EvalForward(Environment &env);
	virtual void Print(int indentLevel);
};

//-----------------------------------------------------------------------------
// ArrayNodeUnary_Pos
//-----------------------------------------------------------------------------
class ArrayNodeUnary_Pos : public ArrayNodeUnary {
public:
	inline ArrayNodeUnary_Pos(Connector *pConnectorDst) :
		ArrayNodeUnary(Array::unaryFuncPack_Pos, pConnectorDst) {}
	virtual bool InitBackward(Environment &env);
	virtual bool EvalBackward(Environment &env);
};

//-----------------------------------------------------------------------------
// ArrayNodeUnary_Neg
//-----------------------------------------------------------------------------
class ArrayNodeUnary_Neg : public ArrayNodeUnary {
public:
	inline ArrayNodeUnary_Neg(Connector *pConnectorDst) :
		ArrayNodeUnary(Array::unaryFuncPack_Pos, pConnectorDst) {}
	virtual bool InitBackward(Environment &env);
	virtual bool EvalBackward(Environment &env);
};

//-----------------------------------------------------------------------------
// ArrayNodeUnary_Math_relu
//-----------------------------------------------------------------------------
class ArrayNodeUnary_Math_relu : public ArrayNodeUnary {
public:
	inline ArrayNodeUnary_Math_relu(Connector *pConnectorDst) :
		ArrayNodeUnary(Array::unaryFuncPack_Math_relu, pConnectorDst) {}
	virtual bool InitBackward(Environment &env);
	virtual bool EvalBackward(Environment &env);
};

//-----------------------------------------------------------------------------
// ArrayNodeUnary_Math_sigmoid
//-----------------------------------------------------------------------------
class ArrayNodeUnary_Math_sigmoid : public ArrayNodeUnary {
public:
	inline ArrayNodeUnary_Math_sigmoid(Connector *pConnectorDst) :
		ArrayNodeUnary(Array::unaryFuncPack_Math_sigmoid, pConnectorDst) {}
	virtual bool InitBackward(Environment &env);
	virtual bool EvalBackward(Environment &env);
};

//-----------------------------------------------------------------------------
// ArrayNodeBinary
//-----------------------------------------------------------------------------
class ArrayNodeBinary : public ArrayNode {
protected:
	const Array::BinaryFuncPack &_binaryFuncPack;
	Connector _connectorSrcLeft;
	Connector _connectorSrcRight;
public:
	inline ArrayNodeBinary(const Array::BinaryFuncPack &binaryFuncPack, Connector *pConnectorDst) :
		ArrayNode(pConnectorDst), _binaryFuncPack(binaryFuncPack),
		_connectorSrcLeft(this), _connectorSrcRight(this) {}
	inline Connector *GetConnectorSrcLeft() { return &_connectorSrcLeft; }
	inline Connector *GetConnectorSrcRight() { return &_connectorSrcRight; }
	virtual bool InitForward(Environment &env);
	virtual bool EvalForward(Environment &env);
	virtual void Print(int indentLevel);
};

//-----------------------------------------------------------------------------
// ArrayNodeBinary_Add
//-----------------------------------------------------------------------------
class ArrayNodeBinary_Add : public ArrayNodeBinary {
public:
	inline ArrayNodeBinary_Add(Connector *pConnectorDst) :
		ArrayNodeBinary(Array::binaryFuncPack_Add, pConnectorDst) {}
	virtual bool InitBackward(Environment &env);
	virtual bool EvalBackward(Environment &env);
};

//-----------------------------------------------------------------------------
// ArrayNodeBinary_Sub
//-----------------------------------------------------------------------------
class ArrayNodeBinary_Sub : public ArrayNodeBinary {
public:
	inline ArrayNodeBinary_Sub(Connector *pConnectorDst) :
		ArrayNodeBinary(Array::binaryFuncPack_Sub, pConnectorDst) {}
	virtual bool InitBackward(Environment &env);
	virtual bool EvalBackward(Environment &env);
};

//-----------------------------------------------------------------------------
// ArrayNodeBinary_Mul
//-----------------------------------------------------------------------------
class ArrayNodeBinary_Mul : public ArrayNodeBinary {
public:
	inline ArrayNodeBinary_Mul(Connector *pConnectorDst) :
		ArrayNodeBinary(Array::binaryFuncPack_Mul, pConnectorDst) {}
	virtual bool InitBackward(Environment &env);
	virtual bool EvalBackward(Environment &env);
};

//-----------------------------------------------------------------------------
// ArrayNodeBinary_Div
//-----------------------------------------------------------------------------
class ArrayNodeBinary_Div : public ArrayNodeBinary {
public:
	inline ArrayNodeBinary_Div(Connector *pConnectorDst) :
		ArrayNodeBinary(Array::binaryFuncPack_Div, pConnectorDst) {}
	virtual bool InitBackward(Environment &env);
	virtual bool EvalBackward(Environment &env);
};

//-----------------------------------------------------------------------------
// ArrayNodeBinary_Pow
//-----------------------------------------------------------------------------
class ArrayNodeBinary_Pow : public ArrayNodeBinary {
public:
	inline ArrayNodeBinary_Pow(Connector *pConnectorDst) :
		ArrayNodeBinary(Array::binaryFuncPack_Pow, pConnectorDst) {}
	virtual bool InitBackward(Environment &env);
	virtual bool EvalBackward(Environment &env);
};

//-----------------------------------------------------------------------------
// ArrayNodeBinary_Dot
//-----------------------------------------------------------------------------
class ArrayNodeBinary_Dot : public ArrayNodeBinary {
private:
	AutoPtr<Array> _pArrayFwdLeftTrans;
	AutoPtr<Array> _pArrayFwdRightTrans;
public:
	inline ArrayNodeBinary_Dot(Connector *pConnectorDst) :
		ArrayNodeBinary(Array::binaryFuncPack_Dot, pConnectorDst) {}
	virtual bool InitBackward(Environment &env);
	virtual bool EvalBackward(Environment &env);
};

#if 0
//-----------------------------------------------------------------------------
// ArrayNodeBinary_Filter
//-----------------------------------------------------------------------------
class ArrayNodeBinary_Filter : public ArrayNodeBinary {
public:
	inline ArrayNodeBinary_Filter(Connector *pConnectorDst) :
		ArrayNodeBinary(Array::binaryFuncPack_Filter, pConnectorDst) {}
	virtual bool InitBackward(Environment &env);
	virtual bool EvalBackward(Environment &env);
};
#endif

//-----------------------------------------------------------------------------
// ArrayNodeList
//-----------------------------------------------------------------------------
class ArrayNodeList : public std::vector<ArrayNode *> {
public:
	inline ArrayNodeList() {}
	bool InitForward(Environment &env);
	bool InitBackward(Environment &env);
	bool EvalForward(Environment &env);
	bool EvalBackward(Environment &env);
};

//-----------------------------------------------------------------------------
// ArrayNodeOwner
//-----------------------------------------------------------------------------
class ArrayNodeOwner : public ArrayNodeList {
public:
	~ArrayNodeOwner();
	void Clear();
	bool CreateFromExpr(Environment &env, const Expr *pExpr, ArrayNode::Connector *pConnector);
};

//-----------------------------------------------------------------------------
// ArrayChain
//-----------------------------------------------------------------------------
class ArrayChain {
private:
	int _cntRef;
	AutoPtr<ArrayNodeBottom> _pArrayNodeBottom;
	ArrayNodeOwner _arrayNodeOwner;
public:
	Gura_DeclareReferenceAccessor(ArrayChain);
public:
	ArrayChain();
protected:
	virtual ~ArrayChain();
public:
	bool CreateFromExpr(Environment &env, const Expr *pExpr);
	bool Eval(Environment &env);
	bool Train(Environment &env, const Array *pArrayCorrect);
	const Array *GetResult() const;
	inline const ArrayNodeOwner &GetArrayNodeOwner() const { return _arrayNodeOwner; }
	void Print() const;
};

}

#endif

