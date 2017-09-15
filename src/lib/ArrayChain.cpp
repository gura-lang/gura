//=============================================================================
// ArrayChain
//=============================================================================
#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// ArrayNode
//-----------------------------------------------------------------------------
ArrayNode::ArrayNode(Connector *pConnectorDst)
{
	pConnectorDst->SetArrayNodeSrc(this);
	_connectorsDst.push_back(pConnectorDst);
}

ArrayNode::~ArrayNode()
{
}

//-----------------------------------------------------------------------------
// ArrayNode::Connector
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// ArrayNode::ConnectorList
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// ArrayNodeHead
//-----------------------------------------------------------------------------
bool ArrayNodeHead::InitForward(Environment &env)
{
	//::printf("ArrayNodeHead::InitForward()\n");
	Value value = _pExpr->Exec(env);
	if (env.IsSignalled()) return false;
	if (value.Is_number()) {
		_pArrayFwd.reset(ArrayT<Double>::CreateScalar(value.GetDouble()));
	} else if (value.Is_complex()) {
		_pArrayFwd.reset(ArrayT<Complex>::CreateScalar(value.GetComplex()));
	} else if (value.Is_array()) {
		_pArrayFwd.reset(Object_array::GetObject(value)->GetArray()->Reference());
	} else if (value.Is_filter()) {
		
	} else {
		env.SetError(ERR_ValueError, "variable must be an array");
		return false;
	}
	return true;
}

bool ArrayNodeHead::EvalForward(Environment &env)
{
	//::printf("ArrayNodeHead::EvalForward()\n");
	return true;
}

bool ArrayNodeHead::InitBackward(Environment &env)
{
	// nothing to do
	return true;
}

bool ArrayNodeHead::EvalBackward(Environment &env)
{
	//::printf("ArrayNodeHead::EvalBackward()\n");
	//ConnectorList::iterator ppConnectorDst = _connectorsDst.begin();
	//::printf("%s\n", (*ppConnectorDst)->GetArrayBwd()->ToString(false).c_str());
	return true;
}

void ArrayNodeHead::Print(int indentLevel)
{
	::printf("%-*sHead\n", indentLevel * 2, "");
}

//-----------------------------------------------------------------------------
// ArrayNodeTail
//-----------------------------------------------------------------------------
bool ArrayNodeTail::InitForward(Environment &env)
{
	//::printf("ArrayNodeTail::InitForward()\n");
	_pArrayFwd.reset(_connectorSrc.GetArrayFwd()->Reference());
	return true;
}

bool ArrayNodeTail::EvalForward(Environment &env)
{
	//::printf("ArrayNodeTail::EvalForward()\n");
	//::printf("%s\n", _connectorSrc.GetArrayFwd()->ToString(false).c_str());
	return true;
}

bool ArrayNodeTail::InitBackward(Environment &env)
{
	Array *pArrayFwd = _connectorSrc.GetArrayFwd();
	AutoPtr<Array> pArrayBwd(Array::Create(pArrayFwd->GetElemType(), false, pArrayFwd->GetDimensions()));
	pArrayBwd->Fill(1);
	_connectorSrc.SetArrayBwd(pArrayBwd.release());
	return true;
}

bool ArrayNodeTail::EvalBackward(Environment &env)
{
	// nothing to do
	return true;
}

void ArrayNodeTail::Print(int indentLevel)
{
	::printf("%*sTail [fwd:%p,bwd:%p]\n", indentLevel * 2, "",
			 _connectorSrc.GetArrayFwd(), _connectorSrc.GetArrayBwd());
	_connectorSrc.GetArrayNodeSrc()->Print(indentLevel + 1);
}

//-----------------------------------------------------------------------------
// ArrayNodeUnary
//-----------------------------------------------------------------------------
bool ArrayNodeUnary::InitForward(Environment &env)
{
	//::printf("ArrayNodeUnary::InitForward()\n");
	_pArrayFwd.reset(
		Array::ApplyUnaryFunc(
			env, _unaryFuncPack, nullptr,
			GetConnectorSrc()->GetArrayFwd()));
	return env.IsNoSignalled();
}

bool ArrayNodeUnary::EvalForward(Environment &env)
{
	//::printf("ArrayNodeUnary::EvalForward()\n");
	Array::Delete(
		Array::ApplyUnaryFunc(
			env, _unaryFuncPack, _pArrayFwd.get(),
			GetConnectorSrc()->GetArrayFwd()));
	return env.IsNoSignalled();
}

void ArrayNodeUnary::Print(int indentLevel)
{
	::printf("%-*sUnary:%s [fwd:%p,bwd:%p]\n", indentLevel * 2, "",
			 _unaryFuncPack.name,
			 _connectorSrc.GetArrayFwd(), _connectorSrc.GetArrayBwd());
	_connectorSrc.GetArrayNodeSrc()->Print(indentLevel + 1);
}

//-----------------------------------------------------------------------------
// ArrayNodeUnary_Pos
//-----------------------------------------------------------------------------
bool ArrayNodeUnary_Pos::InitBackward(Environment &env)
{
	ConnectorList::iterator ppConnectorDst = _connectorsDst.begin();
	Array *pArrayBwd = (*ppConnectorDst)->GetArrayBwd()->Reference();
	if (!_connectorSrc.IsSourceConstant()) {
		_connectorSrc.SetArrayBwd(pArrayBwd);
	}
	return true;
}

bool ArrayNodeUnary_Pos::EvalBackward(Environment &env)
{
	// nothing to do
	return true;
}

//-----------------------------------------------------------------------------
// ArrayNodeUnary_Neg
//-----------------------------------------------------------------------------
bool ArrayNodeUnary_Neg::InitBackward(Environment &env)
{
	ConnectorList::iterator ppConnectorDst = _connectorsDst.begin();
	if (!_connectorSrc.IsSourceConstant()) {
		_connectorSrc.SetArrayBwd(
			Array::ApplyUnaryFunc(
				env, Array::unaryFuncPack_Neg, nullptr,
				(*ppConnectorDst)->GetArrayBwd()));
		if (env.IsSignalled()) return false;
	}
	return true;
}

bool ArrayNodeUnary_Neg::EvalBackward(Environment &env)
{
	ConnectorList::iterator ppConnectorDst = _connectorsDst.begin();
	if (!_connectorSrc.IsSourceConstant()) {
		Array::Delete(
			Array::ApplyUnaryFunc(
				env, Array::unaryFuncPack_Neg, _connectorSrc.GetArrayBwd(),
				(*ppConnectorDst)->GetArrayBwd()));
		if (env.IsSignalled()) return false;
	}
	return true;
}

//-----------------------------------------------------------------------------
// ArrayNodeUnary_Math_relu
//-----------------------------------------------------------------------------
bool ArrayNodeUnary_Math_relu::InitBackward(Environment &env)
{
	return false;
}

bool ArrayNodeUnary_Math_relu::EvalBackward(Environment &env)
{
	return false;
}

//-----------------------------------------------------------------------------
// ArrayNodeUnary_Math_sigmoid
//-----------------------------------------------------------------------------
bool ArrayNodeUnary_Math_sigmoid::InitBackward(Environment &env)
{
	return false;
}

bool ArrayNodeUnary_Math_sigmoid::EvalBackward(Environment &env)
{
	return false;
}

//-----------------------------------------------------------------------------
// ArrayNodeBinary
//-----------------------------------------------------------------------------
bool ArrayNodeBinary::InitForward(Environment &env)
{
	//::printf("ArrayNodeBinary::InitForward()\n");
	_pArrayFwd.reset(
		Array::ApplyBinaryFunc(
			env, _binaryFuncPack, nullptr,
			GetConnectorSrcLeft()->GetArrayFwd(),
			GetConnectorSrcRight()->GetArrayFwd()));
	return env.IsNoSignalled();
}

bool ArrayNodeBinary::EvalForward(Environment &env)
{
	//::printf("ArrayNodeBinary::EvalForward()\n");
	Array::Delete(
		Array::ApplyBinaryFunc(
			env, _binaryFuncPack, _pArrayFwd.get(),
			GetConnectorSrcLeft()->GetArrayFwd(),
			GetConnectorSrcRight()->GetArrayFwd()));
	return env.IsNoSignalled();
}

void ArrayNodeBinary::Print(int indentLevel)
{
	::printf("%-*sBinary:%s [fwd:%p,bwd:%p][fwd:%p,bwd:%p]\n", indentLevel * 2, "",
			 _binaryFuncPack.name,
			 _connectorSrcLeft.GetArrayFwd(), _connectorSrcLeft.GetArrayBwd(),
			 _connectorSrcRight.GetArrayFwd(), _connectorSrcRight.GetArrayBwd());
	_connectorSrcLeft.GetArrayNodeSrc()->Print(indentLevel + 1);
	_connectorSrcRight.GetArrayNodeSrc()->Print(indentLevel + 1);
}

//-----------------------------------------------------------------------------
// ArrayNodeBinary_Add
//-----------------------------------------------------------------------------
bool ArrayNodeBinary_Add::InitBackward(Environment &env)
{
	ConnectorList::iterator ppConnectorDst = _connectorsDst.begin();
	const Array *pArrayBwd = (*ppConnectorDst)->GetArrayBwd();
	_connectorSrcLeft.SetArrayBwd(pArrayBwd->Reference());
	_connectorSrcRight.SetArrayBwd(pArrayBwd->Reference());
	return true;
}

bool ArrayNodeBinary_Add::EvalBackward(Environment &env)
{
	// nothing to do
	return true;
}

//-----------------------------------------------------------------------------
// ArrayNodeBinary_Sub
//-----------------------------------------------------------------------------
bool ArrayNodeBinary_Sub::InitBackward(Environment &env)
{
	ConnectorList::iterator ppConnectorDst = _connectorsDst.begin();
	const Array *pArrayBwd = (*ppConnectorDst)->GetArrayBwd();
	if (!_connectorSrcLeft.IsSourceConstant()) {
		_connectorSrcLeft.SetArrayBwd(pArrayBwd->Reference());
	}
	if (!_connectorSrcRight.IsSourceConstant()) {
		_connectorSrcRight.SetArrayBwd(
			Array::ApplyUnaryFunc(
				env, Array::unaryFuncPack_Neg, nullptr,
				(*ppConnectorDst)->GetArrayBwd()));
		if (env.IsSignalled()) return false;
	}
	return true;
}

bool ArrayNodeBinary_Sub::EvalBackward(Environment &env)
{
	ConnectorList::iterator ppConnectorDst = _connectorsDst.begin();
	if (!_connectorSrcRight.IsSourceConstant()) {
		Array::Delete(
			Array::ApplyUnaryFunc(
				env, Array::unaryFuncPack_Neg, _connectorSrcRight.GetArrayBwd(),
				(*ppConnectorDst)->GetArrayBwd()));
		if (env.IsSignalled()) return false;
	}
	return true;
}

//-----------------------------------------------------------------------------
// ArrayNodeBinary_Mul
//-----------------------------------------------------------------------------
bool ArrayNodeBinary_Mul::InitBackward(Environment &env)
{
	ConnectorList::iterator ppConnectorDst = _connectorsDst.begin();
	if (!_connectorSrcLeft.IsSourceConstant()) {
		_connectorSrcLeft.SetArrayBwd(
			Array::ApplyBinaryFunc(
				env, Array::binaryFuncPack_Mul, nullptr,
				_connectorSrcRight.GetArrayFwd(),
				(*ppConnectorDst)->GetArrayBwd()));
		if (env.IsSignalled()) return false;
	}
	if (!_connectorSrcRight.IsSourceConstant()) {
		_connectorSrcRight.SetArrayBwd(
			Array::ApplyBinaryFunc(
				env, Array::binaryFuncPack_Mul, nullptr,
				_connectorSrcLeft.GetArrayFwd(),
				(*ppConnectorDst)->GetArrayBwd()));
		if (env.IsSignalled()) return false;
	}
	return true;
}

bool ArrayNodeBinary_Mul::EvalBackward(Environment &env)
{
	ConnectorList::iterator ppConnectorDst = _connectorsDst.begin();
	if (!_connectorSrcLeft.IsSourceConstant()) {
		Array::Delete(
			Array::ApplyBinaryFunc(
				env, Array::binaryFuncPack_Mul, _connectorSrcLeft.GetArrayBwd(),
				_connectorSrcRight.GetArrayFwd(),
				(*ppConnectorDst)->GetArrayBwd()));
		if (env.IsSignalled()) return false;
	}
	if (!_connectorSrcRight.IsSourceConstant()) {
		Array::Delete(
			Array::ApplyBinaryFunc(
				env, Array::binaryFuncPack_Mul, _connectorSrcRight.GetArrayBwd(),
				_connectorSrcLeft.GetArrayFwd(),
				(*ppConnectorDst)->GetArrayBwd()));
		if (env.IsSignalled()) return false;
	}
	return true;
}

//-----------------------------------------------------------------------------
// ArrayNodeBinary_Div
//-----------------------------------------------------------------------------
bool ArrayNodeBinary_Div::InitBackward(Environment &env)
{
	return false;
}

bool ArrayNodeBinary_Div::EvalBackward(Environment &env)
{
	return false;
}

//-----------------------------------------------------------------------------
// ArrayNodeBinary_Pow
//-----------------------------------------------------------------------------
bool ArrayNodeBinary_Pow::InitBackward(Environment &env)
{
	return false;
}

bool ArrayNodeBinary_Pow::EvalBackward(Environment &env)
{
	return false;
}

//-----------------------------------------------------------------------------
// ArrayNodeBinary_Dot
//-----------------------------------------------------------------------------
bool ArrayNodeBinary_Dot::InitBackward(Environment &env)
{
	ConnectorList::iterator ppConnectorDst = _connectorsDst.begin();
	if (!_connectorSrcLeft.IsSourceConstant()) {
		_pArrayFwdRightTrans.reset(_connectorSrcRight.GetArrayFwd()->Transpose2d());
		_connectorSrcLeft.SetArrayBwd(
			Array::ApplyBinaryFunc(
				env, Array::binaryFuncPack_Dot, nullptr,
				(*ppConnectorDst)->GetArrayBwd(),
				_pArrayFwdRightTrans.get()));
		if (env.IsSignalled()) return false;
	}
	if (!_connectorSrcRight.IsSourceConstant()) {
		_pArrayFwdLeftTrans.reset(_connectorSrcLeft.GetArrayFwd()->Transpose2d());
		_connectorSrcRight.SetArrayBwd(
			Array::ApplyBinaryFunc(
				env, Array::binaryFuncPack_Dot, nullptr,
				_pArrayFwdLeftTrans.get(),
				(*ppConnectorDst)->GetArrayBwd()));
		if (env.IsSignalled()) return false;
	}
	return true;
}

bool ArrayNodeBinary_Dot::EvalBackward(Environment &env)
{
	ConnectorList::iterator ppConnectorDst = _connectorsDst.begin();
	if (!_connectorSrcLeft.IsSourceConstant()) {
		Array::Delete(
			Array::ApplyBinaryFunc(
				env, Array::binaryFuncPack_Dot, _connectorSrcLeft.GetArrayBwd(),
				(*ppConnectorDst)->GetArrayBwd(),
				_pArrayFwdRightTrans.get()));
		if (env.IsSignalled()) return false;
	}
	if (!_connectorSrcRight.IsSourceConstant()) {
		Array::Delete(
			Array::ApplyBinaryFunc(
				env, Array::binaryFuncPack_Dot, _connectorSrcRight.GetArrayBwd(),
				_pArrayFwdLeftTrans.get(),
				(*ppConnectorDst)->GetArrayBwd()));
		if (env.IsSignalled()) return false;
	}
	return true;
}

#if 0
//-----------------------------------------------------------------------------
// ArrayNodeBinary_Filter
//-----------------------------------------------------------------------------
bool ArrayNodeBinary_Filter::InitBackward(Environment &env)
{
	return false;
}

bool ArrayNodeBinary_Filter::EvalBackward(Environment &env)
{
	return false;
}
#endif

//-----------------------------------------------------------------------------
// ArrayNodeList
//-----------------------------------------------------------------------------
bool ArrayNodeList::InitForward(Environment &env)
{
	foreach_reverse (ArrayNodeList, ppArrayNode, *this) {
		if (!(*ppArrayNode)->InitForward(env)) return false;
	}
	return true;
}

bool ArrayNodeList::InitBackward(Environment &env)
{
	foreach (ArrayNodeList, ppArrayNode, *this) {
		if (!(*ppArrayNode)->InitBackward(env)) return false;
	}
	return true;
}

bool ArrayNodeList::EvalForward(Environment &env)
{
	foreach_reverse (ArrayNodeList, ppArrayNode, *this) {
		if (!(*ppArrayNode)->EvalForward(env)) return false;
	}
	return true;
}

bool ArrayNodeList::EvalBackward(Environment &env)
{
	foreach (ArrayNodeList, ppArrayNode, *this) {
		if (!(*ppArrayNode)->EvalBackward(env)) return false;
	}
	return true;
}

//-----------------------------------------------------------------------------
// ArrayNodeOwner
//-----------------------------------------------------------------------------
ArrayNodeOwner::~ArrayNodeOwner()
{
	Clear();
}

void ArrayNodeOwner::Clear()
{
	foreach (ArrayNodeOwner, ppArrayNode, *this) {
		delete *ppArrayNode;
	}
	clear();
}

bool ArrayNodeOwner::CreateFromExpr(Environment &env, const Expr *pExpr)
{
	std::unique_ptr<ArrayNodeTail> pArrayNode(new ArrayNodeTail());
	ArrayNode::Connector *pConnectorSrc = pArrayNode->GetConnectorSrc();
	push_back(pArrayNode.release());
	if (!CreateFromExprSub(env, pExpr, pConnectorSrc)) return false;
	return true;
}

bool ArrayNodeOwner::CreateFromExprSub(Environment &env, const Expr *pExpr, ArrayNode::Connector *pConnector)
{
	if (pExpr->IsType(EXPRTYPE_UnaryOp)) {
		const Expr_UnaryOp *pExprEx = dynamic_cast<const Expr_UnaryOp *>(pExpr);
		const Operator *pOperator = pExprEx->GetOperator();
		std::unique_ptr<ArrayNodeUnary> pArrayNode;
		if (pOperator->IsOpType(OPTYPE_Pos)) {
			pArrayNode.reset(new ArrayNodeUnary_Pos(pConnector));
		} else if (pOperator->IsOpType(OPTYPE_Neg)) {
			pArrayNode.reset(new ArrayNodeUnary_Neg(pConnector));
		} else {
			env.SetError(ERR_ValueError, "unsupported operator: %s", pOperator->GetName());
			return false;
		}
		ArrayNode::Connector *pConnectorSrc = pArrayNode->GetConnectorSrc();
		push_back(pArrayNode.release());
		if (!CreateFromExprSub(env, pExprEx->GetChild(), pConnectorSrc)) {
			return false;
		}
		return true;
	} else if (pExpr->IsType(EXPRTYPE_BinaryOp)) {
		const Expr_BinaryOp *pExprEx = dynamic_cast<const Expr_BinaryOp *>(pExpr);
		const Operator *pOperator = pExprEx->GetOperator();
		std::unique_ptr<ArrayNodeBinary> pArrayNode;
		if (pOperator->IsOpType(OPTYPE_Add)) {
			pArrayNode.reset(new ArrayNodeBinary_Add(pConnector));
		} else if (pOperator->IsOpType(OPTYPE_Sub)) {
			pArrayNode.reset(new ArrayNodeBinary_Sub(pConnector));
		} else if (pOperator->IsOpType(OPTYPE_Mul)) {
			pArrayNode.reset(new ArrayNodeBinary_Mul(pConnector));
		} else if (pOperator->IsOpType(OPTYPE_Div)) {
			pArrayNode.reset(new ArrayNodeBinary_Div(pConnector));
		} else if (pOperator->IsOpType(OPTYPE_Pow)) {
			pArrayNode.reset(new ArrayNodeBinary_Pow(pConnector));
		} else if (pOperator->IsOpType(OPTYPE_Dot)) {
			pArrayNode.reset(new ArrayNodeBinary_Dot(pConnector));
		} else if (pOperator->IsOpType(OPTYPE_Filter)) {
			//pArrayNode.reset(new ArrayNodeBinary_Filter(pConnector));
		} else {
			env.SetError(ERR_ValueError, "unsupported operator: %s", pOperator->GetName());
			return false;
		}
		ArrayNode::Connector *pConnectorSrcLeft = pArrayNode->GetConnectorSrcLeft();
		ArrayNode::Connector *pConnectorSrcRight = pArrayNode->GetConnectorSrcRight();
		push_back(pArrayNode.release());
		if (!CreateFromExprSub(env, pExprEx->GetLeft(), pConnectorSrcLeft) ||
			!CreateFromExprSub(env, pExprEx->GetRight(), pConnectorSrcRight)) {
			return false;
		}
		return true;
	} else if (pExpr->IsType(EXPRTYPE_Caller)) {
		const Expr_Caller *pExprEx = dynamic_cast<const Expr_Caller *>(pExpr);
		const ExprOwner &exprsArg = pExprEx->GetExprOwner();
		std::unique_ptr<ArrayNodeUnary> pArrayNode;
		if (pExprEx->GetCar()->IsMember()) {
			const Expr_Member *pExprCar = dynamic_cast<const Expr_Member *>(pExprEx->GetCar());
			if (pExprCar->GetTarget()->IsSymbol(Gura_Symbol(math)) && pExprCar->GetSelector()->IsIdentifier()) {
				const Symbol *pSymbol = dynamic_cast<const Expr_Identifier *>(pExprCar->GetSelector())->GetSymbol();
				if (pSymbol->IsIdentical(Gura_Symbol(relu))) {
					pArrayNode.reset(new ArrayNodeUnary_Math_relu(pConnector));
				} else if (pSymbol->IsIdentical(Gura_Symbol(sigmoid))) {
					pArrayNode.reset(new ArrayNodeUnary_Math_sigmoid(pConnector));
				}
			}
		}
		if (pArrayNode.get() != nullptr) {
			if (exprsArg.size() != 1) {
				env.SetError(ERR_ValueError, "invalid number of arguments");
				return false;
			}
			ArrayNode::Connector *pConnectorSrc = pArrayNode->GetConnectorSrc();
			push_back(pArrayNode.release());
			if (!CreateFromExprSub(env, exprsArg.front(), pConnectorSrc)) {
				return false;
			}
			return true;
		}
	}
	std::unique_ptr<ArrayNodeHead> pArrayNode(
		new ArrayNodeHead(pConnector, Expr::Reference(pExpr)));
	push_back(pArrayNode.release());
	return true;
}

//-----------------------------------------------------------------------------
// ArrayChain
//-----------------------------------------------------------------------------
ArrayChain::~ArrayChain()
{
}

bool ArrayChain::CreateFromExpr(Environment &env, const Expr *pExpr)
{
	if (!_arrayNodeOwner.CreateFromExpr(env, pExpr)) return false;
	if (!_arrayNodeOwner.InitForward(env)) return false;
	if (!_arrayNodeOwner.InitBackward(env)) return false;
	return true;
}

bool ArrayChain::Eval(Environment &env)
{
	if (!_arrayNodeOwner.EvalForward(env)) return false;
	if (!_arrayNodeOwner.EvalBackward(env)) return false;
	return true;
}

const Array *ArrayChain::GetResult() const
{
	return _arrayNodeOwner.front()->GetArrayFwd();
}

void ArrayChain::Print() const
{
	_arrayNodeOwner.front()->Print(0);
}

}
