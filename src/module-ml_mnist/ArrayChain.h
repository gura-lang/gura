#ifndef __GURA_ARRAYCHAIN_H__
#define __GURA_ARRAYCHAIN_H__
#include <gura.h>

namespace Gura {

class ArrayItem;

//-----------------------------------------------------------------------------
// ArrayItem
//-----------------------------------------------------------------------------
class ArrayItem {
public:
	class Connector {
	private:
		ArrayItem *_pArrayItemSrc;
		ArrayItem *_pArrayItemDst;
		AutoPtr<Array> _pArrayBwd;
		bool _constSrcFlag;
	public:
		inline Connector(ArrayItem *pArrayItemDst) :
			_pArrayItemSrc(nullptr), _pArrayItemDst(pArrayItemDst), _constSrcFlag(false) {}
		inline ArrayItem *GetArrayItemSrc() { return _pArrayItemSrc; }
		inline ArrayItem *GetArrayItemDst() { return _pArrayItemDst; }
		inline void SetArrayItemSrc(ArrayItem *pArrayItemSrc) {
			_pArrayItemSrc = pArrayItemSrc;
		}
		inline void SetArrayBwd(Array *pArrayBwd) { _pArrayBwd.reset(pArrayBwd); }
		inline Array *GetArrayFwd() { return _pArrayItemSrc->GetArrayFwd(); }
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
	inline ArrayItem() {}
	ArrayItem(Connector *pConnectorDst);
	virtual ~ArrayItem();
	inline void AddConnectorDst(Connector *pConnectorDst) { _connectorsDst.push_back(pConnectorDst); }
	inline Array *GetArrayFwd() { return _pArrayFwd.get(); }
	virtual bool InitForward(Environment &env) = 0;
	virtual bool EvalForward(Environment &env) = 0;
	virtual bool InitBackward(Environment &env) = 0;
	virtual bool EvalBackward(Environment &env) = 0;
	virtual void Print(int indentLevel) = 0;
};

//-----------------------------------------------------------------------------
// ArrayItemHead
//-----------------------------------------------------------------------------
class ArrayItemHead : public ArrayItem {
protected:
	AutoPtr<Expr> _pExpr;
public:
	inline ArrayItemHead(Connector *pConnectorDst, Expr *pExpr) : ArrayItem(pConnectorDst), _pExpr(pExpr) {}
	virtual bool InitForward(Environment &env);
	virtual bool EvalForward(Environment &env);
	virtual bool InitBackward(Environment &env);
	virtual bool EvalBackward(Environment &env);
	virtual void Print(int indentLevel);
};

//-----------------------------------------------------------------------------
// ArrayItemTail
//-----------------------------------------------------------------------------
class ArrayItemTail : public ArrayItem {
private:
	Connector _connectorSrc;
public:
	inline ArrayItemTail() : ArrayItem(), _connectorSrc(this) {}
	inline Connector *GetConnectorSrc() { return &_connectorSrc; }
	virtual bool InitForward(Environment &env);
	virtual bool EvalForward(Environment &env);
	virtual bool InitBackward(Environment &env);
	virtual bool EvalBackward(Environment &env);
	virtual void Print(int indentLevel);
};

//-----------------------------------------------------------------------------
// ArrayItemUnary
//-----------------------------------------------------------------------------
class ArrayItemUnary : public ArrayItem {
protected:
	const Array::UnaryFuncPack &_unaryFuncPack;
	Connector _connectorSrc;
public:
	inline ArrayItemUnary(const Array::UnaryFuncPack &unaryFuncPack, Connector *pConnectorDst) :
		_unaryFuncPack(unaryFuncPack), ArrayItem(pConnectorDst), _connectorSrc(this) {}
	inline Connector *GetConnectorSrc() { return &_connectorSrc; }
	virtual bool InitForward(Environment &env);
	virtual bool EvalForward(Environment &env);
	virtual void Print(int indentLevel);
};

//-----------------------------------------------------------------------------
// ArrayItemUnary_Pos
//-----------------------------------------------------------------------------
class ArrayItemUnary_Pos : public ArrayItemUnary {
public:
	inline ArrayItemUnary_Pos(Connector *pConnectorDst) :
		ArrayItemUnary(Array::unaryFuncPack_Pos, pConnectorDst) {}
	virtual bool InitBackward(Environment &env);
	virtual bool EvalBackward(Environment &env);
};

//-----------------------------------------------------------------------------
// ArrayItemUnary_Neg
//-----------------------------------------------------------------------------
class ArrayItemUnary_Neg : public ArrayItemUnary {
public:
	inline ArrayItemUnary_Neg(Connector *pConnectorDst) :
		ArrayItemUnary(Array::unaryFuncPack_Pos, pConnectorDst) {}
	virtual bool InitBackward(Environment &env);
	virtual bool EvalBackward(Environment &env);
};

//-----------------------------------------------------------------------------
// ArrayItemUnary_Math_relu
//-----------------------------------------------------------------------------
class ArrayItemUnary_Math_relu : public ArrayItemUnary {
public:
	inline ArrayItemUnary_Math_relu(Connector *pConnectorDst) :
		ArrayItemUnary(Array::unaryFuncPack_Math_relu, pConnectorDst) {}
	virtual bool InitBackward(Environment &env);
	virtual bool EvalBackward(Environment &env);
};

//-----------------------------------------------------------------------------
// ArrayItemUnary_Math_sigmoid
//-----------------------------------------------------------------------------
class ArrayItemUnary_Math_sigmoid : public ArrayItemUnary {
public:
	inline ArrayItemUnary_Math_sigmoid(Connector *pConnectorDst) :
		ArrayItemUnary(Array::unaryFuncPack_Math_sigmoid, pConnectorDst) {}
	virtual bool InitBackward(Environment &env);
	virtual bool EvalBackward(Environment &env);
};

//-----------------------------------------------------------------------------
// ArrayItemBinary
//-----------------------------------------------------------------------------
class ArrayItemBinary : public ArrayItem {
protected:
	const Array::BinaryFuncPack &_binaryFuncPack;
	Connector _connectorSrcLeft;
	Connector _connectorSrcRight;
public:
	inline ArrayItemBinary(const Array::BinaryFuncPack &binaryFuncPack, Connector *pConnectorDst) :
		_binaryFuncPack(binaryFuncPack), ArrayItem(pConnectorDst),
		_connectorSrcLeft(this), _connectorSrcRight(this) {}
	inline Connector *GetConnectorSrcLeft() { return &_connectorSrcLeft; }
	inline Connector *GetConnectorSrcRight() { return &_connectorSrcRight; }
	virtual bool InitForward(Environment &env);
	virtual bool EvalForward(Environment &env);
	virtual void Print(int indentLevel);
};

//-----------------------------------------------------------------------------
// ArrayItemBinary_Add
//-----------------------------------------------------------------------------
class ArrayItemBinary_Add : public ArrayItemBinary {
public:
	inline ArrayItemBinary_Add(Connector *pConnectorDst) :
		ArrayItemBinary(Array::binaryFuncPack_Add, pConnectorDst) {}
	virtual bool InitBackward(Environment &env);
	virtual bool EvalBackward(Environment &env);
};

//-----------------------------------------------------------------------------
// ArrayItemBinary_Sub
//-----------------------------------------------------------------------------
class ArrayItemBinary_Sub : public ArrayItemBinary {
public:
	inline ArrayItemBinary_Sub(Connector *pConnectorDst) :
		ArrayItemBinary(Array::binaryFuncPack_Sub, pConnectorDst) {}
	virtual bool InitBackward(Environment &env);
	virtual bool EvalBackward(Environment &env);
};

//-----------------------------------------------------------------------------
// ArrayItemBinary_Mul
//-----------------------------------------------------------------------------
class ArrayItemBinary_Mul : public ArrayItemBinary {
public:
	inline ArrayItemBinary_Mul(Connector *pConnectorDst) :
		ArrayItemBinary(Array::binaryFuncPack_Mul, pConnectorDst) {}
	virtual bool InitBackward(Environment &env);
	virtual bool EvalBackward(Environment &env);
};

//-----------------------------------------------------------------------------
// ArrayItemBinary_Div
//-----------------------------------------------------------------------------
class ArrayItemBinary_Div : public ArrayItemBinary {
public:
	inline ArrayItemBinary_Div(Connector *pConnectorDst) :
		ArrayItemBinary(Array::binaryFuncPack_Div, pConnectorDst) {}
	virtual bool InitBackward(Environment &env);
	virtual bool EvalBackward(Environment &env);
};

//-----------------------------------------------------------------------------
// ArrayItemBinary_Pow
//-----------------------------------------------------------------------------
class ArrayItemBinary_Pow : public ArrayItemBinary {
public:
	inline ArrayItemBinary_Pow(Connector *pConnectorDst) :
		ArrayItemBinary(Array::binaryFuncPack_Pow, pConnectorDst) {}
	virtual bool InitBackward(Environment &env);
	virtual bool EvalBackward(Environment &env);
};

//-----------------------------------------------------------------------------
// ArrayItemBinary_Dot
//-----------------------------------------------------------------------------
class ArrayItemBinary_Dot : public ArrayItemBinary {
private:
	AutoPtr<Array> _pArrayFwdLeftTrans;
	AutoPtr<Array> _pArrayFwdRightTrans;
public:
	inline ArrayItemBinary_Dot(Connector *pConnectorDst) :
		ArrayItemBinary(Array::binaryFuncPack_Dot, pConnectorDst) {}
	virtual bool InitBackward(Environment &env);
	virtual bool EvalBackward(Environment &env);
};

#if 0
//-----------------------------------------------------------------------------
// ArrayItemBinary_Filter
//-----------------------------------------------------------------------------
class ArrayItemBinary_Filter : public ArrayItemBinary {
public:
	inline ArrayItemBinary_Filter(Connector *pConnectorDst) :
		ArrayItemBinary(Array::binaryFuncPack_Filter, pConnectorDst) {}
	virtual bool InitBackward(Environment &env);
	virtual bool EvalBackward(Environment &env);
};
#endif

//-----------------------------------------------------------------------------
// ArrayItemList
//-----------------------------------------------------------------------------
class ArrayItemList : public std::vector<ArrayItem *> {
public:
	inline ArrayItemList() {}
	bool InitForward(Environment &env);
	bool InitBackward(Environment &env);
	bool EvalForward(Environment &env);
	bool EvalBackward(Environment &env);
};

//-----------------------------------------------------------------------------
// ArrayItemOwner
//-----------------------------------------------------------------------------
class ArrayItemOwner : public ArrayItemList {
public:
	~ArrayItemOwner();
	void Clear();
};

//-----------------------------------------------------------------------------
// ArrayChain
//-----------------------------------------------------------------------------
class ArrayChain {
private:
	int _cntRef;
	ArrayItemOwner _arrayItemOwner;
public:
	Gura_DeclareReferenceAccessor(ArrayChain);
public:
	inline ArrayChain() : _cntRef(1) {}
protected:
	virtual ~ArrayChain();
public:
	bool CreateFromExpr(Environment &env, const Expr *pExpr);
private:
	bool CreateFromExprSub(Environment &env, const Expr *pExpr, ArrayItem::Connector *pConnector);
};

}

#endif

