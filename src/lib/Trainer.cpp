//=============================================================================
// Trainer
//=============================================================================
#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// TrainerNode
//-----------------------------------------------------------------------------
TrainerNode::TrainerNode(Connector *pConnectorDst) : _cntRef(1)
{
	pConnectorDst->SetTrainerNodeSrc(this);
	_connectorsDst.push_back(pConnectorDst);
}

TrainerNode::~TrainerNode()
{
}

bool TrainerNode::IsVulnerable() const
{
	return true;
}

//-----------------------------------------------------------------------------
// TrainerNode::Connector
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// TrainerNode::ConnectorList
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// TrainerNodeHead
//-----------------------------------------------------------------------------
bool TrainerNodeHead::IsVulnerable() const
{
	return !_sourceNodeFlag;
}

bool TrainerNodeHead::EvalForward(Environment &env)
{
	//::printf("TrainerNodeHead::EvalForward()\n");
	if (_pArrayFwd.IsNull() || IsSourceNode()) {
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
	}
	return true;
}

bool TrainerNodeHead::EvalBackward(Environment &env)
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

void TrainerNodeHead::Print(int indentLevel)
{
	::printf("%-*sHead\n", indentLevel * 2, "");
}

//-----------------------------------------------------------------------------
// TrainerNodeBottom
//-----------------------------------------------------------------------------
bool TrainerNodeBottom::EvalForward(Environment &env)
{
	//::printf("TrainerNodeBottom::EvalForward()\n");
	_pArrayFwd.reset(_connectorSrc.GetArrayFwd()->Reference());
	return true;
}

bool TrainerNodeBottom::EvalBackward(Environment &env)
{
	// nothing to do
	return true;
}

bool TrainerNodeBottom::EvalBackwardTop(Environment &env, const Array *pArrayCorrect)
{
	_pArrayCorrect.reset(pArrayCorrect->Reference());
	if (_connectorSrc.IsSourceVulnerable()) {
		_pArraySoftmax.reset(
			Filter_Softmax().Apply(
				env, _pArraySoftmax.get(),
				_connectorSrc.GetArrayFwd()));
		_connectorSrc.SetArrayBwd(
			Array::ApplyBinaryFunc(
				env, Array::binaryFuncPack_Sub, _connectorSrc.GetArrayBwd(),
				_pArraySoftmax.get(),
				pArrayCorrect));
		if (env.IsSignalled()) return false;
	}
	return true;
}

void TrainerNodeBottom::Print(int indentLevel)
{
	::printf("%*sTail [fwd:%p,bwd:%p]\n", indentLevel * 2, "",
			 _connectorSrc.GetArrayFwd(), _connectorSrc.GetArrayBwd());
	_connectorSrc.GetTrainerNodeSrc()->Print(indentLevel + 1);
}

//-----------------------------------------------------------------------------
// TrainerNodeUnary
//-----------------------------------------------------------------------------
bool TrainerNodeUnary::EvalForward(Environment &env)
{
	//::printf("TrainerNodeUnary::EvalForward()\n");
	_pArrayFwd.reset(
		Array::ApplyUnaryFunc(
			env, _unaryFuncPack, _pArrayFwd.get(),
			GetConnectorSrc()->GetArrayFwd()));
	return env.IsNoSignalled();
}

void TrainerNodeUnary::Print(int indentLevel)
{
	::printf("%-*sUnary:%s [fwd:%p,bwd:%p]\n", indentLevel * 2, "",
			 _unaryFuncPack.name,
			 _connectorSrc.GetArrayFwd(), _connectorSrc.GetArrayBwd());
	_connectorSrc.GetTrainerNodeSrc()->Print(indentLevel + 1);
}

//-----------------------------------------------------------------------------
// TrainerNodeUnary_Pos
//-----------------------------------------------------------------------------
bool TrainerNodeUnary_Pos::EvalBackward(Environment &env)
{
	if (_connectorSrc.IsSourceVulnerable()) {
		ConnectorList::iterator ppConnectorDst = _connectorsDst.begin();
		_connectorSrc.SetArrayBwd((*ppConnectorDst)->GetArrayBwd()->Reference());
	}
	return true;
}

//-----------------------------------------------------------------------------
// TrainerNodeUnary_Neg
//-----------------------------------------------------------------------------
bool TrainerNodeUnary_Neg::EvalBackward(Environment &env)
{
	ConnectorList::iterator ppConnectorDst = _connectorsDst.begin();
	if (_connectorSrc.IsSourceVulnerable()) {
		_connectorSrc.SetArrayBwd(
			Array::ApplyUnaryFunc(
				env, Array::unaryFuncPack_Neg, _connectorSrc.GetArrayBwd(),
				(*ppConnectorDst)->GetArrayBwd()));
		if (env.IsSignalled()) return false;
	}
	return true;
}

//-----------------------------------------------------------------------------
// TrainerNodeUnary_Math_relu
//-----------------------------------------------------------------------------
bool TrainerNodeUnary_Math_relu::EvalBackward(Environment &env)
{
	return false;
}

//-----------------------------------------------------------------------------
// TrainerNodeUnary_Math_sigmoid
//-----------------------------------------------------------------------------
bool TrainerNodeUnary_Math_sigmoid::EvalBackward(Environment &env)
{
	return false;
}

//-----------------------------------------------------------------------------
// TrainerNodeBinary
//-----------------------------------------------------------------------------
bool TrainerNodeBinary::EvalForward(Environment &env)
{
	//::printf("TrainerNodeBinary::EvalForward()\n");
	_pArrayFwd.reset(
		Array::ApplyBinaryFunc(
			env, _binaryFuncPack, _pArrayFwd.get(),
			GetConnectorSrcLeft()->GetArrayFwd(),
			GetConnectorSrcRight()->GetArrayFwd()));
	return env.IsNoSignalled();
}

void TrainerNodeBinary::Print(int indentLevel)
{
	::printf("%-*sBinary:%s [fwd:%p,bwd:%p][fwd:%p,bwd:%p]\n", indentLevel * 2, "",
			 _binaryFuncPack.name,
			 _connectorSrcLeft.GetArrayFwd(), _connectorSrcLeft.GetArrayBwd(),
			 _connectorSrcRight.GetArrayFwd(), _connectorSrcRight.GetArrayBwd());
	_connectorSrcLeft.GetTrainerNodeSrc()->Print(indentLevel + 1);
	_connectorSrcRight.GetTrainerNodeSrc()->Print(indentLevel + 1);
}

//-----------------------------------------------------------------------------
// TrainerNodeBinary_Add
//-----------------------------------------------------------------------------
bool TrainerNodeBinary_Add::EvalBackward(Environment &env)
{
	ConnectorList::iterator ppConnectorDst = _connectorsDst.begin();
	const Array *pArrayBwd = (*ppConnectorDst)->GetArrayBwd();
	_connectorSrcLeft.SetArrayBwd(pArrayBwd->Reference());
	_connectorSrcRight.SetArrayBwd(pArrayBwd->Reference());
	return true;
}

//-----------------------------------------------------------------------------
// TrainerNodeBinary_Sub
//-----------------------------------------------------------------------------
bool TrainerNodeBinary_Sub::EvalBackward(Environment &env)
{
	ConnectorList::iterator ppConnectorDst = _connectorsDst.begin();
	if (_connectorSrcLeft.IsSourceVulnerable()) {
		_connectorSrcLeft.SetArrayBwd((*ppConnectorDst)->GetArrayBwd()->Reference());
	}
	if (_connectorSrcRight.IsSourceVulnerable()) {
		_connectorSrcRight.SetArrayBwd(
			Array::ApplyUnaryFunc(
				env, Array::unaryFuncPack_Neg, _connectorSrcRight.GetArrayBwd(),
				(*ppConnectorDst)->GetArrayBwd()));
		if (env.IsSignalled()) return false;
	}
	return true;
}

//-----------------------------------------------------------------------------
// TrainerNodeBinary_Mul
//-----------------------------------------------------------------------------
bool TrainerNodeBinary_Mul::EvalBackward(Environment &env)
{
	ConnectorList::iterator ppConnectorDst = _connectorsDst.begin();
	if (_connectorSrcLeft.IsSourceVulnerable()) {
		_connectorSrcLeft.SetArrayBwd(
			Array::ApplyBinaryFunc(
				env, Array::binaryFuncPack_Mul, _connectorSrcLeft.GetArrayBwd(),
				_connectorSrcRight.GetArrayFwd(),
				(*ppConnectorDst)->GetArrayBwd()));
		if (env.IsSignalled()) return false;
	}
	if (_connectorSrcRight.IsSourceVulnerable()) {
		_connectorSrcRight.SetArrayBwd(
			Array::ApplyBinaryFunc(
				env, Array::binaryFuncPack_Mul, _connectorSrcRight.GetArrayBwd(),
				_connectorSrcLeft.GetArrayFwd(),
				(*ppConnectorDst)->GetArrayBwd()));
		if (env.IsSignalled()) return false;
	}
	return true;
}

//-----------------------------------------------------------------------------
// TrainerNodeBinary_Div
//-----------------------------------------------------------------------------
bool TrainerNodeBinary_Div::EvalBackward(Environment &env)
{
	return false;
}

//-----------------------------------------------------------------------------
// TrainerNodeBinary_Pow
//-----------------------------------------------------------------------------
bool TrainerNodeBinary_Pow::EvalBackward(Environment &env)
{
	return false;
}

//-----------------------------------------------------------------------------
// TrainerNodeBinary_Dot
//-----------------------------------------------------------------------------
bool TrainerNodeBinary_Dot::EvalBackward(Environment &env)
{
	ConnectorList::iterator ppConnectorDst = _connectorsDst.begin();
	if (_connectorSrcLeft.IsSourceVulnerable()) {
		_pArrayFwdRightTrans.reset(_connectorSrcRight.GetArrayFwd()->Transpose2d());
		_connectorSrcLeft.SetArrayBwd(
			Array::ApplyBinaryFunc(
				env, Array::binaryFuncPack_Dot, _connectorSrcLeft.GetArrayBwd(),
				(*ppConnectorDst)->GetArrayBwd(),
				_pArrayFwdRightTrans.get()));
		if (env.IsSignalled()) return false;
	}
	if (_connectorSrcRight.IsSourceVulnerable()) {
		_pArrayFwdLeftTrans.reset(_connectorSrcLeft.GetArrayFwd()->Transpose2d());
		_connectorSrcRight.SetArrayBwd(
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
// TrainerNodeBinary_Filter
//-----------------------------------------------------------------------------
bool TrainerNodeBinary_Filter::EvalBackward(Environment &env)
{
	return false;
}
#endif

//-----------------------------------------------------------------------------
// TrainerNodeList
//-----------------------------------------------------------------------------
bool TrainerNodeList::EvalForward(Environment &env)
{
	foreach_reverse (TrainerNodeList, ppTrainerNode, *this) {
		if (!(*ppTrainerNode)->EvalForward(env)) return false;
	}
	return true;
}

bool TrainerNodeList::EvalBackward(Environment &env)
{
	foreach (TrainerNodeList, ppTrainerNode, *this) {
		if (!(*ppTrainerNode)->EvalBackward(env)) return false;
	}
	return true;
}

//-----------------------------------------------------------------------------
// TrainerNodeOwner
//-----------------------------------------------------------------------------
TrainerNodeOwner::~TrainerNodeOwner()
{
	Clear();
}

void TrainerNodeOwner::Clear()
{
	foreach (TrainerNodeOwner, ppTrainerNode, *this) {
		TrainerNode::Delete(*ppTrainerNode);
	}
	clear();
}

bool TrainerNodeOwner::CreateFromExpr(Environment &env, const Expr *pExpr,
									TrainerNode::Connector *pConnector, const SymbolSet &symbolsSource)
{
	if (pExpr->IsType(EXPRTYPE_UnaryOp)) {
		const Expr_UnaryOp *pExprEx = dynamic_cast<const Expr_UnaryOp *>(pExpr);
		const Operator *pOperator = pExprEx->GetOperator();
		AutoPtr<TrainerNodeUnary> pTrainerNode;
		if (pOperator->IsOpType(OPTYPE_Pos)) {
			pTrainerNode.reset(new TrainerNodeUnary_Pos(pConnector));
		} else if (pOperator->IsOpType(OPTYPE_Neg)) {
			pTrainerNode.reset(new TrainerNodeUnary_Neg(pConnector));
		} else {
			env.SetError(ERR_ValueError, "unsupported operator: %s", pOperator->GetName());
			return false;
		}
		TrainerNode::Connector *pConnectorSrc = pTrainerNode->GetConnectorSrc();
		push_back(pTrainerNode.release());
		if (!CreateFromExpr(env, pExprEx->GetChild(), pConnectorSrc, symbolsSource)) {
			return false;
		}
		return true;
	} else if (pExpr->IsType(EXPRTYPE_BinaryOp)) {
		const Expr_BinaryOp *pExprEx = dynamic_cast<const Expr_BinaryOp *>(pExpr);
		const Operator *pOperator = pExprEx->GetOperator();
		AutoPtr<TrainerNodeBinary> pTrainerNode;
		if (pOperator->IsOpType(OPTYPE_Add)) {
			pTrainerNode.reset(new TrainerNodeBinary_Add(pConnector));
		} else if (pOperator->IsOpType(OPTYPE_Sub)) {
			pTrainerNode.reset(new TrainerNodeBinary_Sub(pConnector));
		} else if (pOperator->IsOpType(OPTYPE_Mul)) {
			pTrainerNode.reset(new TrainerNodeBinary_Mul(pConnector));
		} else if (pOperator->IsOpType(OPTYPE_Div)) {
			pTrainerNode.reset(new TrainerNodeBinary_Div(pConnector));
		} else if (pOperator->IsOpType(OPTYPE_Pow)) {
			pTrainerNode.reset(new TrainerNodeBinary_Pow(pConnector));
		} else if (pOperator->IsOpType(OPTYPE_Dot)) {
			pTrainerNode.reset(new TrainerNodeBinary_Dot(pConnector));
		} else if (pOperator->IsOpType(OPTYPE_Filter)) {
			//pTrainerNode.reset(new TrainerNodeBinary_Filter(pConnector));
			env.SetError(ERR_ValueError, "unsupported operator: %s", pOperator->GetName());
			return false;
		} else {
			env.SetError(ERR_ValueError, "unsupported operator: %s", pOperator->GetName());
			return false;
		}
		TrainerNode::Connector *pConnectorSrcLeft = pTrainerNode->GetConnectorSrcLeft();
		TrainerNode::Connector *pConnectorSrcRight = pTrainerNode->GetConnectorSrcRight();
		push_back(pTrainerNode.release());
		if (!CreateFromExpr(env, pExprEx->GetLeft(), pConnectorSrcLeft, symbolsSource) ||
			!CreateFromExpr(env, pExprEx->GetRight(), pConnectorSrcRight, symbolsSource)) {
			return false;
		}
		return true;
	} else if (pExpr->IsType(EXPRTYPE_Caller)) {
		const Expr_Caller *pExprEx = dynamic_cast<const Expr_Caller *>(pExpr);
		const ExprOwner &exprsArg = pExprEx->GetExprOwner();
		AutoPtr<TrainerNodeUnary> pTrainerNode;
		if (pExprEx->GetCar()->IsMember()) {
			const Expr_Member *pExprCar = dynamic_cast<const Expr_Member *>(pExprEx->GetCar());
			if (pExprCar->GetTarget()->IsSymbol(Gura_Symbol(math)) && pExprCar->GetSelector()->IsIdentifier()) {
				const Symbol *pSymbol = dynamic_cast<const Expr_Identifier *>(pExprCar->GetSelector())->GetSymbol();
				if (pSymbol->IsIdentical(Gura_Symbol(relu))) {
					pTrainerNode.reset(new TrainerNodeUnary_Math_relu(pConnector));
				} else if (pSymbol->IsIdentical(Gura_Symbol(sigmoid))) {
					pTrainerNode.reset(new TrainerNodeUnary_Math_sigmoid(pConnector));
				}
			}
		}
		if (pTrainerNode.get() != nullptr) {
			if (exprsArg.size() != 1) {
				env.SetError(ERR_ValueError, "invalid number of arguments");
				return false;
			}
			TrainerNode::Connector *pConnectorSrc = pTrainerNode->GetConnectorSrc();
			push_back(pTrainerNode.release());
			if (!CreateFromExpr(env, exprsArg.front(), pConnectorSrc, symbolsSource)) {
				return false;
			}
			return true;
		}
	}
	bool sourceNodeFlag = pExpr->IsIdentifier() &&
		symbolsSource.IsSet(dynamic_cast<const Expr_Identifier *>(pExpr)->GetSymbol());
	AutoPtr<TrainerNodeHead> pTrainerNode(new TrainerNodeHead(pConnector, Expr::Reference(pExpr), sourceNodeFlag));
	push_back(pTrainerNode.release());
	return true;
}

//-----------------------------------------------------------------------------
// Trainer
//-----------------------------------------------------------------------------
Trainer::Trainer() : _cntRef(1), _pTrainerNodeBottom(new TrainerNodeBottom())
{
}

Trainer::~Trainer()
{
}

bool Trainer::CreateFromExpr(Environment &env, const Expr *pExpr, const SymbolSet &symbolsSource)
{
	return _trainerNodeOwner.CreateFromExpr(env, pExpr, _pTrainerNodeBottom->GetConnectorSrc(), symbolsSource);
}

bool Trainer::Eval(Environment &env)
{
	if (!_trainerNodeOwner.EvalForward(env)) return false;
	if (!_pTrainerNodeBottom->EvalForward(env)) return false;
	return true;
}

bool Trainer::Train(Environment &env, const Array *pArrayCorrect)
{
	if (!_trainerNodeOwner.EvalForward(env)) return false;
	if (!_pTrainerNodeBottom->EvalForward(env)) return false;
	if (!_pTrainerNodeBottom->EvalBackwardTop(env, pArrayCorrect)) return false;
	if (!_trainerNodeOwner.EvalBackward(env)) return false;
	return true;
}

const Array *Trainer::GetResult() const
{
	return _pTrainerNodeBottom->GetArrayFwd();
}

const Array *Trainer::GetResultSoftmax() const
{
	return _pTrainerNodeBottom->GetArraySoftmax();
}

void Trainer::Print() const
{
	_pTrainerNodeBottom->Print(0);
}

}
