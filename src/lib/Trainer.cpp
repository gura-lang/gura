//=============================================================================
// Trainer
//=============================================================================
#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Trainer
//-----------------------------------------------------------------------------
Trainer::Trainer() : _cntRef(1), _pNodeBottom(new NodeBottom())
{
}

Trainer::~Trainer()
{
}

bool Trainer::CreateFromExpr(Environment &env, const Expr *pExprSrc, const SymbolSet &symbolsInput)
{
	_pExprSrc.reset(pExprSrc->Reference());
	return _nodeOwner.CreateFromExpr(env, pExprSrc, _pNodeBottom->GetConnectorSrc(), symbolsInput);
}

bool Trainer::Eval(Environment &env)
{
	if (!_nodeOwner.EvalForward(env)) return false;
	if (!_pNodeBottom->EvalForward(env)) return false;
	return true;
}

bool Trainer::Train(Environment &env, const Array *pArrayCorrect)
{
	if (!_nodeOwner.EvalForward(env)) return false;
	if (!_pNodeBottom->EvalForward(env)) return false;
	if (!_pNodeBottom->EvalBackwardTop(env, pArrayCorrect)) return false;
	if (!_nodeOwner.EvalBackward(env)) return false;
	return true;
}

const Array *Trainer::GetResult() const
{
	return _pNodeBottom->GetArrayFwd();
}

const Array *Trainer::GetResultSoftmax() const
{
	return _pNodeBottom->GetArraySoftmax();
}

void Trainer::Print() const
{
	_pNodeBottom->Print(0);
}

//-----------------------------------------------------------------------------
// Trainer::Node
//-----------------------------------------------------------------------------
Trainer::Node::Node(Connector *pConnectorDst) : _cntRef(1)
{
	pConnectorDst->SetNodeSrc(this);
	_connectorsDst.push_back(pConnectorDst);
}

Trainer::Node::~Node()
{
}

//-----------------------------------------------------------------------------
// Trainer::Node::Connector
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Trainer::Node::ConnectorList
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Trainer::NodeHead
//-----------------------------------------------------------------------------
bool Trainer::NodeHead::IsVulnerable() const
{
	return IsVariable();
}

bool Trainer::NodeHead::EvalForward(Environment &env)
{
	//::printf("NodeHead::EvalForward()\n");
	if (_pArrayFwd.IsNull() || IsInput()) {
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

bool Trainer::NodeHead::EvalBackward(Environment &env)
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

void Trainer::NodeHead::Print(int indentLevel)
{
	::printf("%-*sHead\n", indentLevel * 2, "");
}

//-----------------------------------------------------------------------------
// Trainer::NodeBottom
//-----------------------------------------------------------------------------
bool Trainer::NodeBottom::IsVulnerable() const
{
	return _connectorSrc.GetNodeSrc()->IsVulnerable();
}

bool Trainer::NodeBottom::EvalForward(Environment &env)
{
	//::printf("NodeBottom::EvalForward()\n");
	_pArrayFwd.reset(_connectorSrc.GetArrayFwd()->Reference());
	return true;
}

bool Trainer::NodeBottom::EvalBackward(Environment &env)
{
	// nothing to do
	return true;
}

bool Trainer::NodeBottom::EvalBackwardTop(Environment &env, const Array *pArrayCorrect)
{
	_pArrayCorrect.reset(pArrayCorrect->Reference());
	if (_connectorSrc.GetNodeSrc()->IsVulnerable()) {
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

void Trainer::NodeBottom::Print(int indentLevel)
{
	::printf("%*sTail [fwd:%p,bwd:%p]\n", indentLevel * 2, "",
			 _connectorSrc.GetArrayFwd(), _connectorSrc.GetArrayBwd());
	_connectorSrc.GetNodeSrc()->Print(indentLevel + 1);
}

//-----------------------------------------------------------------------------
// Trainer::NodeUnary
//-----------------------------------------------------------------------------
bool Trainer::NodeUnary::IsVulnerable() const
{
	return _connectorSrc.GetNodeSrc()->IsVulnerable();
}

bool Trainer::NodeUnary::EvalForward(Environment &env)
{
	//::printf("NodeUnary::EvalForward()\n");
	_pArrayFwd.reset(
		Array::ApplyUnaryFunc(
			env, _unaryFuncPack, _pArrayFwd.get(),
			GetConnectorSrc()->GetArrayFwd()));
	return env.IsNoSignalled();
}

void Trainer::NodeUnary::Print(int indentLevel)
{
	::printf("%-*sUnary:%s [fwd:%p,bwd:%p]\n", indentLevel * 2, "",
			 _unaryFuncPack.name,
			 _connectorSrc.GetArrayFwd(), _connectorSrc.GetArrayBwd());
	_connectorSrc.GetNodeSrc()->Print(indentLevel + 1);
}

//-----------------------------------------------------------------------------
// Trainer::NodeUnary_Pos
//-----------------------------------------------------------------------------
bool Trainer::NodeUnary_Pos::EvalBackward(Environment &env)
{
	if (_connectorSrc.GetNodeSrc()->IsVulnerable()) {
		ConnectorList::iterator ppConnectorDst = _connectorsDst.begin();
		_connectorSrc.SetArrayBwd((*ppConnectorDst)->GetArrayBwd()->Reference());
	}
	return true;
}

//-----------------------------------------------------------------------------
// Trainer::NodeUnary_Neg
//-----------------------------------------------------------------------------
bool Trainer::NodeUnary_Neg::EvalBackward(Environment &env)
{
	ConnectorList::iterator ppConnectorDst = _connectorsDst.begin();
	if (_connectorSrc.GetNodeSrc()->IsVulnerable()) {
		_connectorSrc.SetArrayBwd(
			Array::ApplyUnaryFunc(
				env, Array::unaryFuncPack_Neg, _connectorSrc.GetArrayBwd(),
				(*ppConnectorDst)->GetArrayBwd()));
		if (env.IsSignalled()) return false;
	}
	return true;
}

//-----------------------------------------------------------------------------
// Trainer::NodeUnary_Math_relu
//-----------------------------------------------------------------------------
bool Trainer::NodeUnary_Math_relu::EvalBackward(Environment &env)
{
	return false;
}

//-----------------------------------------------------------------------------
// Trainer::NodeUnary_Math_sigmoid
//-----------------------------------------------------------------------------
bool Trainer::NodeUnary_Math_sigmoid::EvalBackward(Environment &env)
{
	return false;
}

//-----------------------------------------------------------------------------
// Trainer::NodeBinary
//-----------------------------------------------------------------------------
bool Trainer::NodeBinary::IsVulnerable() const
{
	return
		_connectorSrcLeft.GetNodeSrc()->IsVulnerable() ||
		_connectorSrcRight.GetNodeSrc()->IsVulnerable();
}

bool Trainer::NodeBinary::EvalForward(Environment &env)
{
	//::printf("NodeBinary::EvalForward()\n");
	_pArrayFwd.reset(
		Array::ApplyBinaryFunc(
			env, _binaryFuncPack, _pArrayFwd.get(),
			GetConnectorSrcLeft()->GetArrayFwd(),
			GetConnectorSrcRight()->GetArrayFwd()));
	return env.IsNoSignalled();
}

void Trainer::NodeBinary::Print(int indentLevel)
{
	::printf("%-*sBinary:%s [fwd:%p,bwd:%p][fwd:%p,bwd:%p]\n", indentLevel * 2, "",
			 _binaryFuncPack.name,
			 _connectorSrcLeft.GetArrayFwd(), _connectorSrcLeft.GetArrayBwd(),
			 _connectorSrcRight.GetArrayFwd(), _connectorSrcRight.GetArrayBwd());
	_connectorSrcLeft.GetNodeSrc()->Print(indentLevel + 1);
	_connectorSrcRight.GetNodeSrc()->Print(indentLevel + 1);
}

//-----------------------------------------------------------------------------
// Trainer::NodeBinary_Add
//-----------------------------------------------------------------------------
bool Trainer::NodeBinary_Add::EvalBackward(Environment &env)
{
	ConnectorList::iterator ppConnectorDst = _connectorsDst.begin();
	const Array *pArrayBwd = (*ppConnectorDst)->GetArrayBwd();
	_connectorSrcLeft.SetArrayBwd(pArrayBwd->Reference());
	_connectorSrcRight.SetArrayBwd(pArrayBwd->Reference());
	return true;
}

//-----------------------------------------------------------------------------
// Trainer::NodeBinary_Sub
//-----------------------------------------------------------------------------
bool Trainer::NodeBinary_Sub::EvalBackward(Environment &env)
{
	ConnectorList::iterator ppConnectorDst = _connectorsDst.begin();
	if (_connectorSrcLeft.GetNodeSrc()->IsVulnerable()) {
		_connectorSrcLeft.SetArrayBwd((*ppConnectorDst)->GetArrayBwd()->Reference());
	}
	if (_connectorSrcRight.GetNodeSrc()->IsVulnerable()) {
		_connectorSrcRight.SetArrayBwd(
			Array::ApplyUnaryFunc(
				env, Array::unaryFuncPack_Neg, _connectorSrcRight.GetArrayBwd(),
				(*ppConnectorDst)->GetArrayBwd()));
		if (env.IsSignalled()) return false;
	}
	return true;
}

//-----------------------------------------------------------------------------
// Trainer::NodeBinary_Mul
//-----------------------------------------------------------------------------
bool Trainer::NodeBinary_Mul::EvalBackward(Environment &env)
{
	ConnectorList::iterator ppConnectorDst = _connectorsDst.begin();
	if (_connectorSrcLeft.GetNodeSrc()->IsVulnerable()) {
		_connectorSrcLeft.SetArrayBwd(
			Array::ApplyBinaryFunc(
				env, Array::binaryFuncPack_Mul, _connectorSrcLeft.GetArrayBwd(),
				_connectorSrcRight.GetArrayFwd(),
				(*ppConnectorDst)->GetArrayBwd()));
		if (env.IsSignalled()) return false;
	}
	if (_connectorSrcRight.GetNodeSrc()->IsVulnerable()) {
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
// Trainer::NodeBinary_Div
//-----------------------------------------------------------------------------
bool Trainer::NodeBinary_Div::EvalBackward(Environment &env)
{
	return false;
}

//-----------------------------------------------------------------------------
// Trainer::NodeBinary_Pow
//-----------------------------------------------------------------------------
bool Trainer::NodeBinary_Pow::EvalBackward(Environment &env)
{
	return false;
}

//-----------------------------------------------------------------------------
// Trainer::NodeBinary_Dot
//-----------------------------------------------------------------------------
bool Trainer::NodeBinary_Dot::EvalBackward(Environment &env)
{
	ConnectorList::iterator ppConnectorDst = _connectorsDst.begin();
	if (_connectorSrcLeft.GetNodeSrc()->IsVulnerable()) {
		_pArrayFwdRightTrans.reset(_connectorSrcRight.GetArrayFwd()->Transpose2d());
		_connectorSrcLeft.SetArrayBwd(
			Array::ApplyBinaryFunc(
				env, Array::binaryFuncPack_Dot, _connectorSrcLeft.GetArrayBwd(),
				(*ppConnectorDst)->GetArrayBwd(),
				_pArrayFwdRightTrans.get()));
		if (env.IsSignalled()) return false;
	}
	if (_connectorSrcRight.GetNodeSrc()->IsVulnerable()) {
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

//-----------------------------------------------------------------------------
// Trainer::NodeFilter
//-----------------------------------------------------------------------------
bool Trainer::NodeFilter::IsVulnerable() const
{
	return false;
}

bool Trainer::NodeFilter::EvalForward(Environment &env)
{
	_pArrayFwd.reset(
		_pFilter->Apply(env, _pArrayFwd.get(), GetConnectorSrc()->GetArrayFwd()));
	return env.IsNoSignalled();
}

bool Trainer::NodeFilter::EvalBackward(Environment &env)
{
	return false;
}

void Trainer::NodeFilter::Print(int indentLevel)
{
	::printf("%-*sFilter:%s [fwd:%p,bwd:%p]\n", indentLevel * 2, "",
			 _pFilter->ToString().c_str(),
			 _connectorSrc.GetArrayFwd(), _connectorSrc.GetArrayBwd());
	_connectorSrc.GetNodeSrc()->Print(indentLevel + 1);
}

//-----------------------------------------------------------------------------
// Trainer::NodeList
//-----------------------------------------------------------------------------
bool Trainer::NodeList::EvalForward(Environment &env)
{
	foreach_reverse (NodeList, ppNode, *this) {
		if (!(*ppNode)->EvalForward(env)) return false;
	}
	return true;
}

bool Trainer::NodeList::EvalBackward(Environment &env)
{
	foreach (NodeList, ppNode, *this) {
		if (!(*ppNode)->EvalBackward(env)) return false;
	}
	return true;
}

//-----------------------------------------------------------------------------
// NodeOwner
//-----------------------------------------------------------------------------
Trainer::NodeOwner::~NodeOwner()
{
	Clear();
}

void Trainer::NodeOwner::Clear()
{
	foreach (NodeOwner, ppNode, *this) {
		Trainer::Node::Delete(*ppNode);
	}
	clear();
}

bool Trainer::NodeOwner::CreateFromExpr(Environment &env, const Expr *pExpr,
										Node::Connector *pConnector, const SymbolSet &symbolsInput)
{
	if (pExpr->IsType(EXPRTYPE_UnaryOp)) {
		const Expr_UnaryOp *pExprEx = dynamic_cast<const Expr_UnaryOp *>(pExpr);
		const Operator *pOperator = pExprEx->GetOperator();
		AutoPtr<NodeUnary> pNode;
		if (pOperator->IsOpType(OPTYPE_Pos)) {
			pNode.reset(new NodeUnary_Pos(pConnector));
		} else if (pOperator->IsOpType(OPTYPE_Neg)) {
			pNode.reset(new NodeUnary_Neg(pConnector));
		} else {
			env.SetError(ERR_ValueError, "unsupported operator: %s", pOperator->GetName());
			return false;
		}
		Node::Connector *pConnectorSrc = pNode->GetConnectorSrc();
		push_back(pNode.release());
		if (!CreateFromExpr(env, pExprEx->GetChild(), pConnectorSrc, symbolsInput)) {
			return false;
		}
		return true;
	} else if (pExpr->IsType(EXPRTYPE_BinaryOp)) {
		const Expr_BinaryOp *pExprEx = dynamic_cast<const Expr_BinaryOp *>(pExpr);
		const Operator *pOperator = pExprEx->GetOperator();
		if (pOperator->IsOpType(OPTYPE_Filter)) {
			return CreateNodeFilter(env, pExprEx, pConnector, symbolsInput);
		}
		AutoPtr<NodeBinary> pNode;
		if (pOperator->IsOpType(OPTYPE_Add)) {
			pNode.reset(new NodeBinary_Add(pConnector));
		} else if (pOperator->IsOpType(OPTYPE_Sub)) {
			pNode.reset(new NodeBinary_Sub(pConnector));
		} else if (pOperator->IsOpType(OPTYPE_Mul)) {
			pNode.reset(new NodeBinary_Mul(pConnector));
		} else if (pOperator->IsOpType(OPTYPE_Div)) {
			pNode.reset(new NodeBinary_Div(pConnector));
		} else if (pOperator->IsOpType(OPTYPE_Pow)) {
			pNode.reset(new NodeBinary_Pow(pConnector));
		} else if (pOperator->IsOpType(OPTYPE_Dot)) {
			pNode.reset(new NodeBinary_Dot(pConnector));
		} else {
			env.SetError(ERR_ValueError, "unsupported operator: %s", pOperator->GetName());
			return false;
		}
		Node::Connector *pConnectorSrcLeft = pNode->GetConnectorSrcLeft();
		Node::Connector *pConnectorSrcRight = pNode->GetConnectorSrcRight();
		push_back(pNode.release());
		if (!CreateFromExpr(env, pExprEx->GetLeft(), pConnectorSrcLeft, symbolsInput) ||
			!CreateFromExpr(env, pExprEx->GetRight(), pConnectorSrcRight, symbolsInput)) {
			return false;
		}
		return true;
	}
	Node::Trait trait = Node::TRAIT_Variable;
	if (pExpr->IsIdentifier() &&
		symbolsInput.IsSet(dynamic_cast<const Expr_Identifier *>(pExpr)->GetSymbol())) {
		trait = Node::TRAIT_Input;
	} else if (pExpr->IsValue()) {
		trait = Node::TRAIT_Constant;
	}
	AutoPtr<NodeHead> pNode(new NodeHead(pConnector, Expr::Reference(pExpr), trait));
	push_back(pNode.release());
	return true;
}

bool Trainer::NodeOwner::CreateNodeUnary(Environment &env, const Expr_UnaryOp *pExprEx,
										 Node::Connector *pConnector, const SymbolSet &symbolsInput)
{
	return false;
}

bool Trainer::NodeOwner::CreateNodeBinary(Environment &env, const Expr_BinaryOp *pExprEx,
										  Node::Connector *pConnector, const SymbolSet &symbolsInput)
{
	return false;
}

bool Trainer::NodeOwner::CreateNodeFilter(Environment &env, const Expr_BinaryOp *pExprEx,
										  Node::Connector *pConnector, const SymbolSet &symbolsInput)
{
	Value value = pExprEx->GetRight()->Exec(env);
	if (env.IsSignalled()) return false;
	if (!value.Is_filter()) {
		env.SetError(ERR_ValueError, "filter instance is expected as a left-side operand of a filter operator");
		return false;
	}
	AutoPtr<NodeFilter> pNode(
		new NodeFilter(Object_filter::GetObject(value)->GetFilter()->Reference(), pConnector));
	Node::Connector *pConnectorSrc = pNode->GetConnectorSrc();
	push_back(pNode.release());
	if (!CreateFromExpr(env, pExprEx->GetLeft(), pConnectorSrc, symbolsInput)) {
		return false;
	}
	return true;
}

}
