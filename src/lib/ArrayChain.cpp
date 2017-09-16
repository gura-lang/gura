//=============================================================================
// ArrayChain
//=============================================================================
#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// ArrayNode
//-----------------------------------------------------------------------------
ArrayNode::ArrayNode(Connector *pConnectorDst) : _cntRef(1)
{
	pConnectorDst->SetArrayNodeSrc(this);
	_connectorsDst.push_back(pConnectorDst);
}

ArrayNode::~ArrayNode()
{
}

bool ArrayNode::IsVulnerable() const
{
	return true;
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
bool ArrayNodeHead::IsVulnerable() const
{
	return !_sourceNodeFlag;
}

bool ArrayNodeHead::InitForward(Environment &env)
{
	//::printf("ArrayNodeHead::InitForward()\n");
	//if (!IsSourceNode()) return EvalExpr(env);
	//return true;
	return EvalExpr(env);
}

bool ArrayNodeHead::EvalForward(Environment &env)
{
	//::printf("ArrayNodeHead::EvalForward()\n");
	//if (IsSourceNode()) return EvalExpr(env);
	return true;
}

bool ArrayNodeHead::EvalExpr(Environment &env)
{
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

bool ArrayNodeHead::InitBackward(Environment &env)
{
#if 0
	ConnectorList::iterator ppConnectorDst = _connectorsDst.begin();
	::printf("check-1\n");
	const Array *pArrayBwd = (*ppConnectorDst)->GetArrayBwd();
	::printf("check-2 %p\n", pArrayBwd);
	_pArrayBwdAdj.reset(Array::Create(pArrayBwd->GetElemType(), false, pArrayBwd->GetDimensions()));
	::printf("check-3\n");
	_pArrayBwdAdj->FillZero();
#endif
	return true;
}

bool ArrayNodeHead::EvalBackward(Environment &env)
{
	Double alpha = .01;
	ConnectorList::iterator ppConnectorDst = _connectorsDst.begin();
	if (IsVulnerable()) {
		_pArrayBwdAdj.reset(
			Array::ApplyBinaryFunc_array_number(
				env, Array::binaryFuncPack_Mul, _pArrayBwdAdj.get(),
				(*ppConnectorDst)->GetArrayBwd(), alpha));
		if (env.IsSignalled()) return false;
		Array::Delete(
			Array::ApplyBinaryFunc(
				env, Array::binaryFuncPack_Sub, _pArrayFwd.get(),
				_pArrayFwd.get(),
				_pArrayBwdAdj.get()));
		//::printf("%s: updated\n", _pExpr->ToString(Expr::SCRSTYLE_OneLine).c_str());
		if (env.IsSignalled()) return false;
	}
	return true;
}

void ArrayNodeHead::Print(int indentLevel)
{
	::printf("%-*sHead\n", indentLevel * 2, "");
}

//-----------------------------------------------------------------------------
// ArrayNodeBottom
//-----------------------------------------------------------------------------
bool ArrayNodeBottom::InitForward(Environment &env)
{
	::printf("ArrayNodeBottom::InitForward()\n");
	_pArrayFwd.reset(_connectorSrc.GetArrayFwd()->Reference());
	return true;
}

bool ArrayNodeBottom::EvalForward(Environment &env)
{
	//::printf("ArrayNodeBottom::EvalForward()\n");
	//::printf("%s\n", _connectorSrc.GetArrayFwd()->ToString(false).c_str());
	return true;
}

bool ArrayNodeBottom::InitBackward(Environment &env)
{
	Array *pArrayFwd = _connectorSrc.GetArrayFwd();
	AutoPtr<Array> pArrayBwd(Array::Create(pArrayFwd->GetElemType(), false, pArrayFwd->GetDimensions()));
	pArrayBwd->FillZero();
	_connectorSrc.SetArrayBwd(pArrayBwd.release());
	_pArraySoftmax.reset(Filter_Softmax().Apply(env, nullptr, pArrayFwd));
	return true;
}

bool ArrayNodeBottom::EvalBackward(Environment &env)
{
	// nothing to do
	return true;
}

bool ArrayNodeBottom::EvalBackwardTop(Environment &env, const Array *pArrayCorrect)
{
	if (_connectorSrc.IsSourceVulnerable()) {
		Array::Delete(
			Filter_Softmax().Apply(
				env, _pArraySoftmax.get(),
				_connectorSrc.GetArrayFwd()));
		Array::Delete(
			Array::ApplyBinaryFunc(
				env, Array::binaryFuncPack_Sub, _connectorSrc.GetArrayBwd(),
				_pArraySoftmax.get(),
				pArrayCorrect));
		if (env.IsSignalled()) return false;
	}
	return true;
}

void ArrayNodeBottom::Print(int indentLevel)
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
	::printf("ArrayNodeUnary::InitForward()\n");
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
	if (_connectorSrc.IsSourceVulnerable()) {
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
	if (_connectorSrc.IsSourceVulnerable()) {
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
	if (_connectorSrc.IsSourceVulnerable()) {
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
	::printf("ArrayNodeBinary::InitForward()\n");
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
	if (_connectorSrcLeft.IsSourceVulnerable()) {
		_connectorSrcLeft.SetArrayBwd(pArrayBwd->Reference());
	}
	if (_connectorSrcRight.IsSourceVulnerable()) {
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
	if (_connectorSrcRight.IsSourceVulnerable()) {
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
	if (_connectorSrcLeft.IsSourceVulnerable()) {
		_connectorSrcLeft.SetArrayBwd(
			Array::ApplyBinaryFunc(
				env, Array::binaryFuncPack_Mul, nullptr,
				_connectorSrcRight.GetArrayFwd(),
				(*ppConnectorDst)->GetArrayBwd()));
		if (env.IsSignalled()) return false;
	}
	if (_connectorSrcRight.IsSourceVulnerable()) {
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
	if (_connectorSrcLeft.IsSourceVulnerable()) {
		Array::Delete(
			Array::ApplyBinaryFunc(
				env, Array::binaryFuncPack_Mul, _connectorSrcLeft.GetArrayBwd(),
				_connectorSrcRight.GetArrayFwd(),
				(*ppConnectorDst)->GetArrayBwd()));
		if (env.IsSignalled()) return false;
	}
	if (_connectorSrcRight.IsSourceVulnerable()) {
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
	if (_connectorSrcLeft.IsSourceVulnerable()) {
		_pArrayFwdRightTrans.reset(_connectorSrcRight.GetArrayFwd()->Transpose2d());
		_connectorSrcLeft.SetArrayBwd(
			Array::ApplyBinaryFunc(
				env, Array::binaryFuncPack_Dot, nullptr,
				(*ppConnectorDst)->GetArrayBwd(),
				_pArrayFwdRightTrans.get()));
		if (env.IsSignalled()) return false;
	}
	if (_connectorSrcRight.IsSourceVulnerable()) {
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
	if (_connectorSrcLeft.IsSourceVulnerable()) {
		Array::Delete(
			Array::ApplyBinaryFunc(
				env, Array::binaryFuncPack_Dot, _connectorSrcLeft.GetArrayBwd(),
				(*ppConnectorDst)->GetArrayBwd(),
				_pArrayFwdRightTrans.get()));
		if (env.IsSignalled()) return false;
	}
	if (_connectorSrcRight.IsSourceVulnerable()) {
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
		ArrayNode::Delete(*ppArrayNode);
	}
	clear();
}

bool ArrayNodeOwner::CreateFromExpr(Environment &env, const Expr *pExpr, ArrayNode::Connector *pConnector)
{
	if (pExpr->IsType(EXPRTYPE_UnaryOp)) {
		const Expr_UnaryOp *pExprEx = dynamic_cast<const Expr_UnaryOp *>(pExpr);
		const Operator *pOperator = pExprEx->GetOperator();
		AutoPtr<ArrayNodeUnary> pArrayNode;
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
		if (!CreateFromExpr(env, pExprEx->GetChild(), pConnectorSrc)) {
			return false;
		}
		return true;
	} else if (pExpr->IsType(EXPRTYPE_BinaryOp)) {
		const Expr_BinaryOp *pExprEx = dynamic_cast<const Expr_BinaryOp *>(pExpr);
		const Operator *pOperator = pExprEx->GetOperator();
		AutoPtr<ArrayNodeBinary> pArrayNode;
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
			env.SetError(ERR_ValueError, "unsupported operator: %s", pOperator->GetName());
			return false;
		} else {
			env.SetError(ERR_ValueError, "unsupported operator: %s", pOperator->GetName());
			return false;
		}
		ArrayNode::Connector *pConnectorSrcLeft = pArrayNode->GetConnectorSrcLeft();
		ArrayNode::Connector *pConnectorSrcRight = pArrayNode->GetConnectorSrcRight();
		push_back(pArrayNode.release());
		if (!CreateFromExpr(env, pExprEx->GetLeft(), pConnectorSrcLeft) ||
			!CreateFromExpr(env, pExprEx->GetRight(), pConnectorSrcRight)) {
			return false;
		}
		return true;
	} else if (pExpr->IsType(EXPRTYPE_Caller)) {
		const Expr_Caller *pExprEx = dynamic_cast<const Expr_Caller *>(pExpr);
		const ExprOwner &exprsArg = pExprEx->GetExprOwner();
		AutoPtr<ArrayNodeUnary> pArrayNode;
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
			if (!CreateFromExpr(env, exprsArg.front(), pConnectorSrc)) {
				return false;
			}
			return true;
		}
	}
	AutoPtr<ArrayNodeHead> pArrayNode(new ArrayNodeHead(pConnector, Expr::Reference(pExpr)));
	bool sourceNodeFlag = pExpr->IsSymbol(Gura_Symbol(x));
	pArrayNode->SetSourceNodeFlag(sourceNodeFlag);
	push_back(pArrayNode.release());
	return true;
}

//-----------------------------------------------------------------------------
// ArrayChain
//-----------------------------------------------------------------------------
ArrayChain::ArrayChain() : _cntRef(1), _pArrayNodeBottom(new ArrayNodeBottom())
{
}

ArrayChain::~ArrayChain()
{
}

bool ArrayChain::CreateFromExpr(Environment &env, const Expr *pExpr)
{
	if (!_arrayNodeOwner.CreateFromExpr(env, pExpr, _pArrayNodeBottom->GetConnectorSrc())) return false;
	if (!_arrayNodeOwner.InitForward(env)) return false;
	if (!_pArrayNodeBottom->InitForward(env)) return false;
	if (!_pArrayNodeBottom->InitBackward(env)) return false;
	if (!_arrayNodeOwner.InitBackward(env)) return false;
	return true;
}

bool ArrayChain::Eval(Environment &env)
{
	if (!_arrayNodeOwner.EvalForward(env)) return false;
	if (!_pArrayNodeBottom->EvalForward(env)) return false;
	return true;
}

bool ArrayChain::Train(Environment &env, const Array *pArrayCorrect)
{
	if (!_arrayNodeOwner.EvalForward(env)) return false;
	if (!_pArrayNodeBottom->EvalForward(env)) return false;
	if (!_pArrayNodeBottom->EvalBackwardTop(env, pArrayCorrect)) return false;
	if (!_arrayNodeOwner.EvalBackward(env)) return false;
	return true;
}

const Array *ArrayChain::GetResult() const
{
	return _pArrayNodeBottom->GetArrayFwd();
}

const Array *ArrayChain::GetResultSoftmax() const
{
	return _pArrayNodeBottom->GetArraySoftmax();
}

void ArrayChain::Print() const
{
	_pArrayNodeBottom->Print(0);
}

}
