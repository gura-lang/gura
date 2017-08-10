#include "ArrayChain.h"

namespace Gura {

//-----------------------------------------------------------------------------
// ArrayChainHead
//-----------------------------------------------------------------------------
class ArrayChainHead : public ArrayChain {
private:
	AutoPtr<Expr> _pExpr;
public:
	inline ArrayChainHead(Connector *pConnectorDst, Expr *pExpr) : ArrayChain(pConnectorDst), _pExpr(pExpr) {}
	virtual bool InitForward(Environment &env);
	virtual bool InitBackward(Environment &env);
	virtual bool EvalForward(Environment &env);
	virtual bool EvalBackward(Environment &env);
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
	virtual bool InitBackward(Environment &env);
	virtual bool EvalForward(Environment &env);
	virtual bool EvalBackward(Environment &env);
};

//-----------------------------------------------------------------------------
// ArrayChainUnary
//-----------------------------------------------------------------------------
class ArrayChainUnary : public ArrayChain {
private:
	const Array::UnaryFuncPack &_unaryFuncPack;
	Connector _connectorSrc;
public:
	inline ArrayChainUnary(const Array::UnaryFuncPack &unaryFuncPack, Connector *pConnectorDst) :
		_unaryFuncPack(unaryFuncPack), ArrayChain(pConnectorDst), _connectorSrc(this) {}
	inline Connector *GetConnectorSrc() { return &_connectorSrc; }
	virtual bool InitForward(Environment &env);
	virtual bool InitBackward(Environment &env);
	virtual bool EvalForward(Environment &env);
	virtual bool EvalBackward(Environment &env);
};

class ArrayChainUnary_Pos : public ArrayChainUnary {
public:
	inline ArrayChainUnary_Pos(Connector *pConnectorDst) :
		ArrayChainUnary(Array::unaryFuncPack_Pos, pConnectorDst) {}
};

class ArrayChainUnary_Neg : public ArrayChainUnary {
public:
	inline ArrayChainUnary_Neg(Connector *pConnectorDst) :
		ArrayChainUnary(Array::unaryFuncPack_Pos, pConnectorDst) {}
};

//-----------------------------------------------------------------------------
// ArrayChainBinary
//-----------------------------------------------------------------------------
class ArrayChainBinary : public ArrayChain {
private:
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
	virtual bool InitBackward(Environment &env);
	virtual bool EvalForward(Environment &env);
	virtual bool EvalBackward(Environment &env);
};

class ArrayChainBinary_Add : public ArrayChainBinary {
public:
	inline ArrayChainBinary_Add(Connector *pConnectorDst) :
		ArrayChainBinary(Array::binaryFuncPack_Add, pConnectorDst) {}
};

class ArrayChainBinary_Sub : public ArrayChainBinary {
public:
	inline ArrayChainBinary_Sub(Connector *pConnectorDst) :
		ArrayChainBinary(Array::binaryFuncPack_Sub, pConnectorDst) {}
};

class ArrayChainBinary_Mul : public ArrayChainBinary {
public:
	inline ArrayChainBinary_Mul(Connector *pConnectorDst) :
		ArrayChainBinary(Array::binaryFuncPack_Mul, pConnectorDst) {}
};

class ArrayChainBinary_Div : public ArrayChainBinary {
public:
	inline ArrayChainBinary_Div(Connector *pConnectorDst) :
		ArrayChainBinary(Array::binaryFuncPack_Div, pConnectorDst) {}
};

class ArrayChainBinary_Pow : public ArrayChainBinary {
public:
	inline ArrayChainBinary_Pow(Connector *pConnectorDst) :
		ArrayChainBinary(Array::binaryFuncPack_Pow, pConnectorDst) {}
};

class ArrayChainBinary_DotProd : public ArrayChainBinary {
public:
	inline ArrayChainBinary_DotProd(Connector *pConnectorDst) :
		ArrayChainBinary(Array::binaryFuncPack_DotProd, pConnectorDst) {}
};

//-----------------------------------------------------------------------------
// ArrayChainOwner
//-----------------------------------------------------------------------------
bool ArrayChainOwner::CreateFromExpr(Environment &env, const Expr *pExpr)
{
	std::unique_ptr<ArrayChainTail> pArrayChain(new ArrayChainTail());
	if (!CreateFromExprSub(env, pExpr, pArrayChain->GetConnectorSrc())) return false;
	push_back(pArrayChain.release());
	return true;
}

bool ArrayChainOwner::CreateFromExprSub(Environment &env, const Expr *pExpr, ArrayChain::Connector *pConnector)
{
	if (pExpr->IsType(EXPRTYPE_UnaryOp)) {
		const Expr_UnaryOp *pExprEx = dynamic_cast<const Expr_UnaryOp *>(pExpr);
		const Operator *pOperator = pExprEx->GetOperator();
		std::unique_ptr<ArrayChainUnary> pArrayChain;
		if (pOperator->IsOpType(OPTYPE_Pos)) {
			pArrayChain.reset(new ArrayChainUnary_Pos(pConnector));
		} else if (pOperator->IsOpType(OPTYPE_Neg)) {
			pArrayChain.reset(new ArrayChainUnary_Neg(pConnector));
		} else {
			env.SetError(ERR_ValueError, "unsupported operator: %s", pOperator->GetName());
			return false;
		}
		if (!CreateFromExprSub(env, pExprEx->GetChild(), pArrayChain->GetConnectorSrc())) {
			return false;
		}
		push_back(pArrayChain.release());
	} else if (pExpr->IsType(EXPRTYPE_BinaryOp)) {
		const Expr_BinaryOp *pExprEx = dynamic_cast<const Expr_BinaryOp *>(pExpr);
		const Operator *pOperator = pExprEx->GetOperator();
		std::unique_ptr<ArrayChainBinary> pArrayChain;
		if (pOperator->IsOpType(OPTYPE_Add)) {
			pArrayChain.reset(new ArrayChainBinary_Add(pConnector));
		} else if (pOperator->IsOpType(OPTYPE_Sub)) {
			pArrayChain.reset(new ArrayChainBinary_Sub(pConnector));
		} else if (pOperator->IsOpType(OPTYPE_Mul)) {
			pArrayChain.reset(new ArrayChainBinary_Mul(pConnector));
		} else if (pOperator->IsOpType(OPTYPE_Div)) {
			pArrayChain.reset(new ArrayChainBinary_Div(pConnector));
		} else if (pOperator->IsOpType(OPTYPE_Pow)) {
			pArrayChain.reset(new ArrayChainBinary_Pow(pConnector));
		} else if (pOperator->IsOpType(OPTYPE_DotProd)) {
			pArrayChain.reset(new ArrayChainBinary_DotProd(pConnector));
		} else {
			env.SetError(ERR_ValueError, "unsupported operator: %s", pOperator->GetName());
			return false;
		}
		if (!CreateFromExprSub(env, pExprEx->GetLeft(), pArrayChain->GetConnectorSrcLeft()) ||
			!CreateFromExprSub(env, pExprEx->GetRight(), pArrayChain->GetConnectorSrcRight())) {
			return false;
		}
		push_back(pArrayChain.release());
	} else if (pExpr->IsType(EXPRTYPE_Caller)) {
		const Expr_Caller *pExprEx = dynamic_cast<const Expr_Caller *>(pExpr);

	} else {
		std::unique_ptr<ArrayChainHead> pArrayChain(
			new ArrayChainHead(pConnector, Expr::Reference(pExpr)));
		push_back(pArrayChain.release());
	}
	return true;
}

//-----------------------------------------------------------------------------
// ArrayChain
//-----------------------------------------------------------------------------
ArrayChain::~ArrayChain()
{
}

//-----------------------------------------------------------------------------
// ArrayChain::Connector
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// ArrayChain::ConnectorList
//-----------------------------------------------------------------------------
void ArrayChain::ConnectorList::SetArrayFwd(Array *pArrayFwd)
{
	foreach (ConnectorList, ppConnector, *this) {
		(*ppConnector)->SetArrayFwd(pArrayFwd->Reference());
	}
	Array::Delete(pArrayFwd);
}

void ArrayChain::ConnectorList::SetArrayBwd(Array *pArrayBwd)
{
	foreach (ConnectorList, ppConnector, *this) {
		(*ppConnector)->SetArrayBwd(pArrayBwd->Reference());
	}
	Array::Delete(pArrayBwd);
}

//-----------------------------------------------------------------------------
// ArrayChainHead
//-----------------------------------------------------------------------------
bool ArrayChainHead::InitForward(Environment &env)
{
	Value value = _pExpr->Exec(env);
	if (!value.Is_array()) {
		env.SetError(ERR_ValueError, "variable must be an array");
		return false;
	}
	_connectorsDst.SetArrayFwd(Object_array::GetObject(value)->GetArray()->Reference());
	return true;
}

bool ArrayChainHead::InitBackward(Environment &env)
{
	return false;
}

bool ArrayChainHead::EvalForward(Environment &env)
{
	return false;
}

bool ArrayChainHead::EvalBackward(Environment &env)
{
	return false;
}

//-----------------------------------------------------------------------------
// ArrayChainTail
//-----------------------------------------------------------------------------
bool ArrayChainTail::InitForward(Environment &env)
{
	// nothing to do
	return true;
}

bool ArrayChainTail::InitBackward(Environment &env)
{
	return false;
}

bool ArrayChainTail::EvalForward(Environment &env)
{
	return false;
}

bool ArrayChainTail::EvalBackward(Environment &env)
{
	return false;
}

//-----------------------------------------------------------------------------
// ArrayChainUnary
//-----------------------------------------------------------------------------
bool ArrayChainUnary::InitForward(Environment &env)
{
	return false;
}

bool ArrayChainUnary::InitBackward(Environment &env)
{
	return false;
}

bool ArrayChainUnary::EvalForward(Environment &env)
{
	return false;
}

bool ArrayChainUnary::EvalBackward(Environment &env)
{
	return false;
}

//-----------------------------------------------------------------------------
// ArrayChainBinary
//-----------------------------------------------------------------------------
bool ArrayChainBinary::InitForward(Environment &env)
{
	return false;
}

bool ArrayChainBinary::InitBackward(Environment &env)
{
	return false;
}

bool ArrayChainBinary::EvalForward(Environment &env)
{
	return false;
}

bool ArrayChainBinary::EvalBackward(Environment &env)
{
	return false;
}

//-----------------------------------------------------------------------------
// ArrayChainOwner
//-----------------------------------------------------------------------------
ArrayChainOwner::~ArrayChainOwner()
{
	Clear();
}

void ArrayChainOwner::Clear()
{
	foreach (ArrayChainOwner, ppArrayChain, *this) {
		delete *ppArrayChain;
	}
	clear();
}

}
