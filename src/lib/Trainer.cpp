//=============================================================================
// Trainer
//=============================================================================
#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Trainer
//-----------------------------------------------------------------------------
Trainer::NodeGearCreatorMap Trainer::_nodeGearCreatorMap;

Trainer::Trainer(Optimizer *pOptimizer) : _cntRef(1), _pOptimizer(pOptimizer), _pNodeBottom(new NodeBottom())
{
}

Trainer::~Trainer()
{
}

void Trainer::Bootup()
{
	RegisterNodeGearCreator(VTYPE_gear_at_conv1d, new NodeGear_Conv1d::CreatorEx());
#if 0
	RegisterNodeGearCreator(VTYPE_gear_at_conv2d, new NodeGear_Conv2d::CreatorEx());
	RegisterNodeGearCreator(VTYPE_gear_at_conv3d, new NodeGear_Conv3d::CreatorEx());
	RegisterNodeGearCreator(VTYPE_gear_at_maxpool1d, new NodeGear_MaxPool1d::CreatorEx());
	RegisterNodeGearCreator(VTYPE_gear_at_maxpool2d, new NodeGear_MaxPool2d::CreatorEx());
	RegisterNodeGearCreator(VTYPE_gear_at_maxpool3d, new NodeGear_MaxPool3d::CreatorEx());
	RegisterNodeGearCreator(VTYPE_gear_at_relu, new NodeGear_Relu::CreatorEx());
	RegisterNodeGearCreator(VTYPE_gear_at_sigmoid, new NodeGear_Sigmoid::CreatorEx());
	RegisterNodeGearCreator(VTYPE_gear_at_softmax, new NodeGear_Softmax::CreatorEx());
	RegisterNodeGearCreator(VTYPE_gear_at_tanh, new NodeGear_Tanh::CreatorEx());
#endif
}

bool Trainer::CreateFromExpr(Environment &env, const Expr *pExprModel, const SymbolSet &symbolsInput)
{
	_pExprModel.reset(pExprModel->Reference());
	return CreateNode(env, pExprModel, _pNodeBottom->GetConnectorSrc(), symbolsInput) != nullptr;
}

bool Trainer::EvalForward(Environment &env)
{
	return _nodeOwner.EvalForward(env) && _pNodeBottom->EvalForward(env);
}

bool Trainer::EvalBackward(Environment &env, const Array *pArrayCorrect)
{
	return _pNodeBottom->EvalBackwardTop(env, pArrayCorrect) && _nodeOwner.EvalBackward(env);
}

const Array *Trainer::GetResult() const
{
	return _pNodeBottom->GetArrayFwd();
}

Trainer::Node *Trainer::FindNode(const Symbol *pSymbol) const
{
	NodeMap::const_iterator iter = _nodeMap.find(pSymbol);
	return (iter == _nodeMap.end())? nullptr : iter->second;
}

void Trainer::Print() const
{
	_pNodeBottom->Print(0);
}

Trainer::Node *Trainer::CreateNode(Environment &env, const Expr *pExpr,
								   Node::Connector *pConnector, const SymbolSet &symbolsInput)
{
	if (pExpr->IsType(EXPRTYPE_Block)) {
		Node *pNodeRtn = nullptr;
		const Expr_Block *pExprEx = dynamic_cast<const Expr_Block *>(pExpr);
		const ExprOwner &exprOwner = pExprEx->GetExprOwner();
		foreach_const (ExprOwner, ppExprEach, exprOwner) {
			const Expr *pExprEach = *ppExprEach;
			Node::Connector *pConnectorEach = (ppExprEach + 1 == exprOwner.end())? pConnector : nullptr;
			pNodeRtn = CreateNode(env, pExprEach, pConnectorEach, symbolsInput);
			if (pNodeRtn == nullptr) return nullptr;
		}
		return pNodeRtn;
	}
	if (pExpr->IsType(EXPRTYPE_Assign)) {
		const Expr_Assign *pExprEx = dynamic_cast<const Expr_Assign *>(pExpr);
		if (pExprEx->GetOperatorToApply() != nullptr) {
			env.SetError(ERR_SyntaxError, "invalid assignment");
			return nullptr;
		}
		if (!pExprEx->GetLeft()->IsIdentifier()) {
			env.SetError(ERR_SyntaxError, "assignment to an identifier is only supported");
			return nullptr;
		}
		const Symbol *pSymbol = dynamic_cast<const Expr_Identifier *>(pExprEx->GetLeft())->GetSymbol();
		Node *pNode = CreateNode(env, pExprEx->GetRight(), pConnector, symbolsInput);
		if (pNode == nullptr) return nullptr;
		if (_nodeMap.find(pSymbol) != _nodeMap.end()) {
			env.SetError(ERR_SyntaxError, "duplicated assignment to the identifier %s", pSymbol->GetName());
			return nullptr;
		}
		_nodeMap[pSymbol] = pNode;
		return pNode;
	} else if (pExpr->IsType(EXPRTYPE_UnaryOp)) {
		const Expr_UnaryOp *pExprEx = dynamic_cast<const Expr_UnaryOp *>(pExpr);
		return CreateNodeUnary(env, pExprEx, pConnector, symbolsInput);
	} else if (pExpr->IsType(EXPRTYPE_BinaryOp)) {
		const Expr_BinaryOp *pExprEx = dynamic_cast<const Expr_BinaryOp *>(pExpr);
		return pExprEx->GetOperator()->IsOpType(OPTYPE_Gear)?
			CreateNodeGear(env, pExprEx, pConnector, symbolsInput) :
			CreateNodeBinary(env, pExprEx, pConnector, symbolsInput);
	} else if (pExpr->IsIdentifier()) {
		const Expr_Identifier *pExprEx = dynamic_cast<const Expr_Identifier *>(pExpr);
		const Symbol *pSymbol = pExprEx->GetSymbol();
		Node *pNodeFound = FindNode(pSymbol);
		if (pNodeFound != nullptr) return pNodeFound;
		Node::Trait trait = Node::TRAIT_Input;
		Optimizer::Instance *pOptimizerInst = nullptr;
		if (!symbolsInput.IsSet(pSymbol)) {
			trait = Node::TRAIT_Variable;
			pOptimizerInst = _pOptimizer->CreateInstance();
		}
		AutoPtr<NodeHead> pNode(new NodeHead(pConnector, Expr::Reference(pExpr), trait, pOptimizerInst));
		_nodeOwner.push_back(pNode.get());
		return pNode.release();
	} else {
		Node::Trait trait = Node::TRAIT_Constant;
		Optimizer::Instance *pOptimizerInst = nullptr;
		if (!pExpr->IsValue()) {
			trait = Node::TRAIT_Variable;
			pOptimizerInst = _pOptimizer->CreateInstance();
		}
		AutoPtr<NodeHead> pNode(new NodeHead(pConnector, Expr::Reference(pExpr), trait, pOptimizerInst));
		_nodeOwner.push_back(pNode.get());
		return pNode.release();
	}
}

Trainer::Node *Trainer::CreateNodeUnary(Environment &env, const Expr_UnaryOp *pExprEx,
										Node::Connector *pConnector, const SymbolSet &symbolsInput)
{
	const Operator *pOperator = pExprEx->GetOperator();
	AutoPtr<NodeUnary> pNode;
	if (pOperator->IsOpType(OPTYPE_Pos)) {
		pNode.reset(new NodeUnary_Pos(pConnector));
	} else if (pOperator->IsOpType(OPTYPE_Neg)) {
		pNode.reset(new NodeUnary_Neg(pConnector));
	} else {
		env.SetError(ERR_ValueError, "unsupported operator: %s", pOperator->GetName());
		return nullptr;
	}
	Node::Connector *pConnectorSrc = pNode->GetConnectorSrc();
	Node *pNodeRtn = pNode.get();
	_nodeOwner.push_back(pNode.release());
	return
		(CreateNode(env, pExprEx->GetChild(), pConnectorSrc, symbolsInput) == nullptr)?
		nullptr : pNodeRtn;
}

Trainer::Node *Trainer::CreateNodeBinary(Environment &env, const Expr_BinaryOp *pExprEx,
										 Node::Connector *pConnector, const SymbolSet &symbolsInput)
{
	const Operator *pOperator = pExprEx->GetOperator();
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
		return nullptr;
	}
	Node::Connector *pConnectorSrcLeft = pNode->GetConnectorSrcLeft();
	Node::Connector *pConnectorSrcRight = pNode->GetConnectorSrcRight();
	Node *pNodeRtn = pNode.get();
	_nodeOwner.push_back(pNode.release());
	return
		(CreateNode(env, pExprEx->GetLeft(), pConnectorSrcLeft, symbolsInput) == nullptr) ||
		(CreateNode(env, pExprEx->GetRight(), pConnectorSrcRight, symbolsInput) == nullptr)?
		nullptr : pNodeRtn;
}


Trainer::Node *Trainer::CreateNodeGear(Environment &env, const Expr_BinaryOp *pExprEx,
									   Node::Connector *pConnector, const SymbolSet &symbolsInput)
{
	Value value = pExprEx->GetRight()->Exec(env);
	if (env.IsSignalled()) return nullptr;
	if (!value.IsInstanceOf(VTYPE_gear)) {
		env.SetError(ERR_ValueError, "gear instance is expected as a right-side operand of a gear operator");
		return nullptr;
	}
	NodeGearCreatorMap::iterator iter = _nodeGearCreatorMap.find(value.GetValueType());
	if (iter == _nodeGearCreatorMap.end()) {
		env.SetError(ERR_ValueError, "unsupported gear type: %s", value.MakeValueTypeName().c_str());
		return nullptr;
	}
	const NodeGear::Creator *pCreator = iter->second;
	AutoPtr<NodeGear> pNode(pCreator->Create(value, pConnector));
	Node::Connector *pConnectorSrc = pNode->GetConnectorSrc();
	Node *pNodeRtn = pNode.get();
	_nodeOwner.push_back(pNode.release());
	return (CreateNode(env, pExprEx->GetLeft(), pConnectorSrc, symbolsInput) == nullptr)?
		nullptr : pNodeRtn;
}

//-------------------------------------------------------------------------
// Trainer::Optimizer
//-------------------------------------------------------------------------
Trainer::Optimizer::~Optimizer()
{
}

//-------------------------------------------------------------------------
// Trainer::Optimizer_Adam
//-------------------------------------------------------------------------
Trainer::Optimizer::Instance *Trainer::Optimizer_Adam::CreateInstance()
{
	return new InstanceEx();
}

bool Trainer::Optimizer_Adam::InstanceEx::Update(Signal &sig, AutoPtr<Array> &pArray, const Array *pArrayBwd)
{
	return true;
}

//-------------------------------------------------------------------------
// Trainer::Optimizer_GradientDescent
//-------------------------------------------------------------------------
Trainer::Optimizer::Instance *Trainer::Optimizer_GradientDescent::CreateInstance()
{
	return new InstanceEx(_learningRate);
}

bool Trainer::Optimizer_GradientDescent::InstanceEx::Update(Signal &sig, AutoPtr<Array> &pArray, const Array *pArrayBwd)
{
	if (!Array::ApplyBinaryFunc_array_number(
			sig, Array::binaryFuncPack_Mul, _pArrayAdj,
			pArrayBwd, _learningRate)) return false;
	if (!Array::ApplyBinaryFunc(
			sig, Array::binaryFuncPack_Sub, pArray,
			pArray.get(),
			_pArrayAdj.get())) return false;
	return true;
}

//-------------------------------------------------------------------------
// Trainer::Optimizer_Momentum
//-------------------------------------------------------------------------
Trainer::Optimizer::Instance *Trainer::Optimizer_Momentum::CreateInstance()
{
	return new InstanceEx();
}

bool Trainer::Optimizer_Momentum::InstanceEx::Update(Signal &sig, AutoPtr<Array> &pArray, const Array *pArrayBwd)
{
	return true;
}

//-------------------------------------------------------------------------
// Trainer::Optimizer_None
//-------------------------------------------------------------------------
Trainer::Optimizer::Instance *Trainer::Optimizer_None::CreateInstance()
{
	return new InstanceEx();
}

bool Trainer::Optimizer_None::InstanceEx::Update(Signal &sig, AutoPtr<Array> &pArray, const Array *pArrayBwd)
{
	return true;
}

//-----------------------------------------------------------------------------
// Trainer::Node
//-----------------------------------------------------------------------------
Trainer::Node::Node(const char *nodeTypeName, Connector *pConnectorDst) : _cntRef(1), _nodeTypeName(nodeTypeName)
{
	if (pConnectorDst != nullptr) {
		pConnectorDst->SetNodeSrc(this);
		_connectorsDst.push_back(pConnectorDst);
	}
}

Trainer::Node::~Node()
{
}

bool Trainer::Node::DoDirProp(Environment &env, SymbolSet &symbols)
{
	symbols.insert(Gura_Symbol(output));
	symbols.insert(Gura_Symbol(type));
	return true;
}

Value Trainer::Node::DoGetProp(Environment &env, const Symbol *pSymbol,
							   const SymbolSet &attrs, bool &evaluatedFlag)
{
	if (pSymbol->IsIdentical(Gura_Symbol(output))) {
		evaluatedFlag = true;
		return Array::ToValue(env, Array::Reference(GetArrayFwd()));
	} else if (pSymbol->IsIdentical(Gura_Symbol(type))) {
		evaluatedFlag = true;
		return Value(Symbol::Add(GetNodeTypeName()));
	}
	return Value::Nil;
}

void Trainer::Node::Print(int indentLevel) const
{
	::printf("%-*s%s\n", indentLevel * 2, "", ToString().c_str());
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
		} else if (value.Is_gear()) {
		
		} else {
			env.SetError(ERR_ValueError, "variable must be an array");
			return false;
		}
	}
	return true;
}

bool Trainer::NodeHead::EvalBackward(Environment &env)
{
	ConnectorList::iterator ppConnectorDst = _connectorsDst.begin();
	if (ppConnectorDst == _connectorsDst.end()) return true;
	if (_pOptimizerInst.get() != nullptr) {
		if (!_pOptimizerInst->Update(env, _pArrayFwd, (*ppConnectorDst)->GetArrayBwd())) return false;
	}
	return true;
}

bool Trainer::NodeHead::DoDirProp(Environment &env, SymbolSet &symbols)
{
	return Node::DoDirProp(env, symbols);
}

Value Trainer::NodeHead::DoGetProp(Environment &env, const Symbol *pSymbol,
							   const SymbolSet &attrs, bool &evaluatedFlag)
{
	return Node::DoGetProp(env, pSymbol, attrs, evaluatedFlag);
}

String Trainer::NodeHead::ToString() const
{
	String str;
	str += GetNodeTypeName();
	str += ":";
	str += _pExpr->ToString(Expr::SCRSTYLE_OneLine);
	return str;
}

void Trainer::NodeHead::Print(int indentLevel) const
{
	Node::Print(indentLevel);
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
		if (!Array::ApplyBinaryFunc(
				env, Array::binaryFuncPack_Sub, _connectorSrc.GetArrayBwdAutoPtr(),
				_connectorSrc.GetArrayFwd(),
				pArrayCorrect)) return false;
	}
	return true;
}

bool Trainer::NodeBottom::DoDirProp(Environment &env, SymbolSet &symbols)
{
	symbols.insert(Gura_Symbol(input));
	symbols.insert(Gura_Symbol(inputbwd));
	return Node::DoDirProp(env, symbols);
}

Value Trainer::NodeBottom::DoGetProp(Environment &env, const Symbol *pSymbol,
							   const SymbolSet &attrs, bool &evaluatedFlag)
{
	if (pSymbol->IsIdentical(Gura_Symbol(input))) {
		evaluatedFlag = true;
		return Array::ToValue(env, Array::Reference(_connectorSrc.GetArrayFwd()));
	} else if (pSymbol->IsIdentical(Gura_Symbol(inputbwd))) {
		evaluatedFlag = true;
		return Array::ToValue(env, Array::Reference(_connectorSrc.GetArrayBwd()));
	}
	return Node::DoGetProp(env, pSymbol, attrs, evaluatedFlag);
}

String Trainer::NodeBottom::ToString() const
{
	String str;
	char buff[128];
	str += GetNodeTypeName();
	::sprintf(buff, " [fwd:%p,bwd:%p]", _connectorSrc.GetArrayFwd(), _connectorSrc.GetArrayBwd());
	str += buff;
	return str;
}

void Trainer::NodeBottom::Print(int indentLevel) const
{
	Node::Print(indentLevel);
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
	return Array::ApplyUnaryFunc(
		env, _unaryFuncPack, _pArrayFwd, GetConnectorSrc()->GetArrayFwd());
}

bool Trainer::NodeUnary::DoDirProp(Environment &env, SymbolSet &symbols)
{
	symbols.insert(Gura_Symbol(input));
	symbols.insert(Gura_Symbol(inputbwd));
	return Node::DoDirProp(env, symbols);
}

Value Trainer::NodeUnary::DoGetProp(Environment &env, const Symbol *pSymbol,
							   const SymbolSet &attrs, bool &evaluatedFlag)
{
	if (pSymbol->IsIdentical(Gura_Symbol(input))) {
		evaluatedFlag = true;
		return Array::ToValue(env, Array::Reference(_connectorSrc.GetArrayFwd()));
	} else if (pSymbol->IsIdentical(Gura_Symbol(inputbwd))) {
		evaluatedFlag = true;
		return Array::ToValue(env, Array::Reference(_connectorSrc.GetArrayBwd()));
	}
	return Node::DoGetProp(env, pSymbol, attrs, evaluatedFlag);
}

String Trainer::NodeUnary::ToString() const
{
	String str;
	char buff[128];
	str += GetNodeTypeName();
	::sprintf(buff, " [fwd:%p,bwd:%p]", _connectorSrc.GetArrayFwd(), _connectorSrc.GetArrayBwd());
	str += buff;
	return str;
}

void Trainer::NodeUnary::Print(int indentLevel) const
{
	Node::Print(indentLevel);
	_connectorSrc.GetNodeSrc()->Print(indentLevel + 1);
}

//-----------------------------------------------------------------------------
// Trainer::NodeUnary_Pos
//-----------------------------------------------------------------------------
bool Trainer::NodeUnary_Pos::EvalBackward(Environment &env)
{
	if (_connectorSrc.GetNodeSrc()->IsVulnerable()) {
		ConnectorList::iterator ppConnectorDst = _connectorsDst.begin();
		if (ppConnectorDst == _connectorsDst.end()) return true;
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
	if (ppConnectorDst == _connectorsDst.end()) return true;
	if (_connectorSrc.GetNodeSrc()->IsVulnerable()) {
		if (!Array::ApplyUnaryFunc(
				env, Array::unaryFuncPack_Neg, _connectorSrc.GetArrayBwdAutoPtr(),
				(*ppConnectorDst)->GetArrayBwd())) return false;
	}
	return true;
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
	return Array::ApplyBinaryFunc(
			env, _binaryFuncPack, _pArrayFwd,
			GetConnectorSrcLeft()->GetArrayFwd(),
			GetConnectorSrcRight()->GetArrayFwd());
}

bool Trainer::NodeBinary::DoDirProp(Environment &env, SymbolSet &symbols)
{
	symbols.insert(Gura_Symbol(input_at_left));
	symbols.insert(Gura_Symbol(input_at_right));
	symbols.insert(Gura_Symbol(inputbwd_at_left));
	symbols.insert(Gura_Symbol(inputbwd_at_right));
	return Node::DoDirProp(env, symbols);
}

Value Trainer::NodeBinary::DoGetProp(Environment &env, const Symbol *pSymbol,
							   const SymbolSet &attrs, bool &evaluatedFlag)
{
	if (pSymbol->IsIdentical(Gura_Symbol(input_at_left))) {
		evaluatedFlag = true;
		return Array::ToValue(env, Array::Reference(_connectorSrcLeft.GetArrayFwd()));
	} else if (pSymbol->IsIdentical(Gura_Symbol(input_at_right))) {
		evaluatedFlag = true;
		return Array::ToValue(env, Array::Reference(_connectorSrcRight.GetArrayFwd()));
	} else if (pSymbol->IsIdentical(Gura_Symbol(inputbwd_at_left))) {
		evaluatedFlag = true;
		return Array::ToValue(env, Array::Reference(_connectorSrcLeft.GetArrayBwd()));
	} else if (pSymbol->IsIdentical(Gura_Symbol(inputbwd_at_right))) {
		evaluatedFlag = true;
		return Array::ToValue(env, Array::Reference(_connectorSrcRight.GetArrayBwd()));
	}
	return Node::DoGetProp(env, pSymbol, attrs, evaluatedFlag);
}

String Trainer::NodeBinary::ToString() const
{
	String str;
	char buff[128];
	str += GetNodeTypeName();
	::sprintf(buff, " [fwd:%p,bwd:%p][fwd:%p,bwd:%p]",
			  _connectorSrcLeft.GetArrayFwd(), _connectorSrcLeft.GetArrayBwd(),
			  _connectorSrcRight.GetArrayFwd(), _connectorSrcRight.GetArrayBwd());
	str += buff;
	return str;
}

void Trainer::NodeBinary::Print(int indentLevel) const
{
	Node::Print(indentLevel);
	_connectorSrcLeft.GetNodeSrc()->Print(indentLevel + 1);
	_connectorSrcRight.GetNodeSrc()->Print(indentLevel + 1);
}

//-----------------------------------------------------------------------------
// Trainer::NodeBinary_Add
//-----------------------------------------------------------------------------
bool Trainer::NodeBinary_Add::EvalBackward(Environment &env)
{
	ConnectorList::iterator ppConnectorDst = _connectorsDst.begin();
	if (ppConnectorDst == _connectorsDst.end()) return true;
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
	if (ppConnectorDst == _connectorsDst.end()) return true;
	if (_connectorSrcLeft.GetNodeSrc()->IsVulnerable()) {
		_connectorSrcLeft.SetArrayBwd((*ppConnectorDst)->GetArrayBwd()->Reference());
	}
	if (_connectorSrcRight.GetNodeSrc()->IsVulnerable()) {
		if (!Array::ApplyUnaryFunc(
				env, Array::unaryFuncPack_Neg, _connectorSrcRight.GetArrayBwdAutoPtr(),
				(*ppConnectorDst)->GetArrayBwd())) return false;
	}
	return true;
}

//-----------------------------------------------------------------------------
// Trainer::NodeBinary_Mul
//-----------------------------------------------------------------------------
bool Trainer::NodeBinary_Mul::EvalBackward(Environment &env)
{
	ConnectorList::iterator ppConnectorDst = _connectorsDst.begin();
	if (ppConnectorDst == _connectorsDst.end()) return true;
	if (_connectorSrcLeft.GetNodeSrc()->IsVulnerable()) {
		if (!Array::ApplyBinaryFunc(
				env, Array::binaryFuncPack_Mul, _connectorSrcLeft.GetArrayBwdAutoPtr(),
				_connectorSrcRight.GetArrayFwd(),
				(*ppConnectorDst)->GetArrayBwd())) return false;
	}
	if (_connectorSrcRight.GetNodeSrc()->IsVulnerable()) {
		if (!Array::ApplyBinaryFunc(
				env, Array::binaryFuncPack_Mul, _connectorSrcRight.GetArrayBwdAutoPtr(),
				_connectorSrcLeft.GetArrayFwd(),
				(*ppConnectorDst)->GetArrayBwd())) return false;
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
	if (ppConnectorDst == _connectorsDst.end()) return true;
	if (_connectorSrcLeft.GetNodeSrc()->IsVulnerable()) {
		_connectorSrcRight.GetArrayFwd()->Transpose2d(_pArrayFwdRightTrans);
		if (!Array::ApplyBinaryFunc(
				env, Array::binaryFuncPack_Dot, _connectorSrcLeft.GetArrayBwdAutoPtr(),
				(*ppConnectorDst)->GetArrayBwd(),
				_pArrayFwdRightTrans.get())) return false;
	}
	if (_connectorSrcRight.GetNodeSrc()->IsVulnerable()) {
		_connectorSrcLeft.GetArrayFwd()->Transpose2d(_pArrayFwdLeftTrans);
		if (!Array::ApplyBinaryFunc(
				env, Array::binaryFuncPack_Dot, _connectorSrcRight.GetArrayBwdAutoPtr(),
				_pArrayFwdLeftTrans.get(),
				(*ppConnectorDst)->GetArrayBwd())) return false;
	}
	return true;
}

//-----------------------------------------------------------------------------
// Trainer::NodeGear
//-----------------------------------------------------------------------------
bool Trainer::NodeGear::DoDirProp(Environment &env, SymbolSet &symbols)
{
	symbols.insert(Gura_Symbol(input));
	symbols.insert(Gura_Symbol(inputbwd));
	return Node::DoDirProp(env, symbols);
}

Value Trainer::NodeGear::DoGetProp(Environment &env, const Symbol *pSymbol,
								   const SymbolSet &attrs, bool &evaluatedFlag)
{
	if (pSymbol->IsIdentical(Gura_Symbol(input))) {
		evaluatedFlag = true;
		return Array::ToValue(env, Array::Reference(_connectorSrc.GetArrayFwd()));
	} else if (pSymbol->IsIdentical(Gura_Symbol(inputbwd))) {
		evaluatedFlag = true;
		return Array::ToValue(env, Array::Reference(_connectorSrc.GetArrayBwd()));
	}
	return Node::DoGetProp(env, pSymbol, attrs, evaluatedFlag);
}

String Trainer::NodeGear::ToString() const
{
	String str;
	char buff[128];
	str += GetNodeTypeName();
	::sprintf(buff, " [fwd:%p,bwd:%p]", _connectorSrc.GetArrayFwd(), _connectorSrc.GetArrayBwd());
	str += buff;
	return str;
}

void Trainer::NodeGear::Print(int indentLevel) const
{
	Node::Print(indentLevel);
	_connectorSrc.GetNodeSrc()->Print(indentLevel + 1);
}

#if 0
//-----------------------------------------------------------------------------
// Trainer::NodeGear_Conv2d
//-----------------------------------------------------------------------------
bool Trainer::NodeGear_Conv2d::IsVulnerable() const
{
	return _connectorSrc.GetNodeSrc()->IsVulnerable();
}

bool Trainer::NodeGear_Conv2d::DoDirProp(Environment &env, SymbolSet &symbols)
{
	return NodeGear::DoDirProp(env, symbols);
}

Value Trainer::NodeGear_Conv2d::DoGetProp(Environment &env, const Symbol *pSymbol,
								   const SymbolSet &attrs, bool &evaluatedFlag)
{
	return NodeGear::DoGetProp(env, pSymbol, attrs, evaluatedFlag);
}

bool Trainer::NodeGear_Conv2d::EvalForward(Environment &env)
{
	Gear_Conv2d *pGear = GetGear();
	const Double padNum = 0;
	// pArraySrc .. [H, W], [H, W, C], [C, H, W], [N, C, H, W] or [N, H, W, C]
	const Array *pArrayFwdSrc = GetConnectorSrc()->GetArrayFwd();
	// _pArrayFwdSrcVec .. [H_out * W_out, C * FH * FW] or [N, H_out * W_out, C * FH * FW]
	if (_pArrayFwdSrcVec.IsNull()) {
		Gear::CalcPadding2d(pGear, pArrayFwdSrc->GetDimensions(),
							&_sizePadRow, &_sizePadCol, &_sizeOutRow, &_sizeOutCol);
	}
	if (!pArrayFwdSrc->ExpandKernelVec2d(
			env, _pArrayFwdSrcVec, pGear->GetSizeRow(), pGear->GetSizeCol(),
			pGear->GetStridesRow(), pGear->GetStridesCol(), _sizePadRow, _sizePadCol,
			pGear->GetChannelPos(), padNum)) return false;
	const Array *pArrayGear = pGear->GetArrayGear();
	const Array::Dimensions &dimsGear = pArrayGear->GetDimensions();
	if (_pArrayGearTrans.IsNull()) {
		Array::Dimensions dims;
		if (pGear->HasChannelDim()) {
			if (pGear->HasFilterDim()) {
				// pArrayGear .. [FN, C, FH, FW] or [FN, FH, FW, C]
				// _pArrayGearReshape .. [FN, C * FH * FW]
				// _pArrayGearTrans .. [C * FH * FW, FN]
				dims.reserve(2);
				dims.push_back(Array::Dimension(dimsGear[0].GetSize()));
				dims.push_back(Array::Dimension(dimsGear[1].GetSize() * dimsGear[2].GetSize() * dimsGear[3].GetSize()));
			} else {
				// pArrayGear .. [C, FH, FW], [FH, FW, C]
				// _pArrayGearReshape .. [1, C * FH * FW]
				// _pArrayGearTrans .. [C * FH * FW, 1]
				dims.reserve(2);
				dims.push_back(Array::Dimension(1));
				dims.push_back(Array::Dimension(dimsGear[0].GetSize() * dimsGear[1].GetSize() * dimsGear[2].GetSize()));
			}
		} else {
			if (pGear->HasFilterDim()) {
				// pArrayGear .. [FN, FH, FW] or [FN, FH, FW]
				// _pArrayGearReshape .. [FN, FH * FW]
				// _pArrayGearTrans .. [FH * FW, FN]
				dims.reserve(2);
				dims.push_back(Array::Dimension(dimsGear[0].GetSize()));
				dims.push_back(Array::Dimension(dimsGear[1].GetSize() * dimsGear[2].GetSize()));
			} else {
				// pArrayGear .. [FH, FW], [FH, FW]
				// _pArrayGearReshape .. [1, FH * FW]
				// _pArrayGearTrans .. [FH * FW, 1]
				dims.reserve(2);
				dims.push_back(Array::Dimension(1));
				dims.push_back(Array::Dimension(dimsGear[0].GetSize() * dimsGear[1].GetSize()));
			}
		}
		pArrayGear->Reshape(_pArrayGearReshape, dims);
		_pArrayGearReshape->Transpose2d(_pArrayGearTrans);
	}
	// _pArrayFwdPre = _pArrayFwdSrcVec |.| _pArrayGearTrans
	if (!Array::ApplyBinaryFunc(
			env, Array::binaryFuncPack_Dot, _pArrayFwdPre,
			_pArrayFwdSrcVec.get(), _pArrayGearTrans.get())) return false;
	//::printf("_pArrayFwdSrcVec: %s\n", _pArrayFwdSrcVec->GetDimensions().ToString().c_str());
	//::printf("_pArrayGearTrans: %s\n", _pArrayGearTrans->GetDimensions().ToString().c_str());
	//::printf("_pArrayFwdPre: %s\n", _pArrayFwdPre->GetDimensions().ToString().c_str());
	if (_pArrayFwd.IsNull()) {
		const Array::Dimensions &dimsPre = _pArrayFwdPre->GetDimensions();
		Array::Dimensions dims;
		if (dimsPre.size() == 2) {
			if (pGear->HasFilterDim()) {
				// _pArrayFwdPre .. [H_out * W_out, FN]
				// _pArrayFwd .. [H_out, W_out, FN]
				dims.reserve(3);
				dims.push_back(Array::Dimension(_sizeOutRow));
				dims.push_back(Array::Dimension(_sizeOutCol));
				dims.push_back(Array::Dimension(dimsPre[1].GetSize()));
			} else {
				// _pArrayFwdPre .. [H_out * W_out, 1]
				// _pArrayFwd .. [H_out, W_out]
				dims.reserve(3);
				dims.push_back(Array::Dimension(_sizeOutRow));
				dims.push_back(Array::Dimension(_sizeOutCol));
			}
		} else {
			if (pGear->HasFilterDim()) {
				// _pArrayFwdPre .. [N, H_out * W_out, FN]
				// _pArrayFwd .. [N, H_out, W_out, FN]
				dims.reserve(4);
				dims.push_back(Array::Dimension(dimsPre[0].GetSize()));
				dims.push_back(Array::Dimension(_sizeOutRow));
				dims.push_back(Array::Dimension(_sizeOutCol));
				dims.push_back(Array::Dimension(dimsPre[2].GetSize()));
			} else {
				// _pArrayFwdPre .. [N, H_out * W_out, 1]
				// _pArrayFwd .. [N, H_out, W_out]
				dims.reserve(3);
				dims.push_back(Array::Dimension(dimsPre[0].GetSize()));
				dims.push_back(Array::Dimension(_sizeOutRow));
				dims.push_back(Array::Dimension(_sizeOutCol));
			}
		}
		_pArrayFwdPre->Reshape(_pArrayFwd, dims);
	}
	return true;
}

bool Trainer::NodeGear_Conv2d::EvalBackward(Environment &env)
{
	ConnectorList::iterator ppConnectorDst = _connectorsDst.begin();
	if (ppConnectorDst == _connectorsDst.end()) return true;
	if (_connectorSrc.GetNodeSrc()->IsVulnerable()) {
		//const Array *pArrayBwdSrc = (*ppConnectorDst)->GetArrayBwd();
		//AutoPtr<Array> &pArrayBwd = _connectorSrc.GetArrayBwdAutoPtr();
		// pArrayBwdSrc .. [H_out, W_out], [H_out, W_out, FN], [FN, H_out, W_out], [N, H_out, W_out], [N, H_out, W_out, FN]
		// pArrayBwdSrcReshape .. [H_out * W_out], [H_out * W_out, FN], [FN, H_out * W_out], [N * h_out, W_out], [N * H_out * W_out, FN]
		// pArrayBwdSrcTrans .. [FN, N * H_out * W_out]
		// _pArrayFwdPre = _pArrayFwdSrcVec |.| _pArrayGearTrans
		// _pArrayFwdSrcVec .. [H_out * W_out, C * FH * FW] or [N, H_out * W_out, C * FH * FW]
		// _pArrayGearReshape .. [FN, C * FH * FW]
		// _pArrayGearTrans .. [C * FH * FW, FN]
		// pArrayBwdVec = pArrayBwdSrcReshape |.| _pArrayGearReshape
		// pArrayGearDiff = pArrayBwdSrcTrans |.| _pArrayFwdSrcVec
		// pArrayBwdVec .. [N * H_out * W_out, C * FH * FW]
		// pArrayGearDiff .. [FN, C * FH * FW]
	}
	return true;
}

Trainer::NodeGear *Trainer::NodeGear_Conv2d::CreatorEx::Create(const Value &value, Connector *pConnectorDst) const
{
	return new NodeGear_Conv2d(Object_gear_at_conv2d::GetObject(value)->GetGear()->Reference(), pConnectorDst);
}

//-----------------------------------------------------------------------------
// Trainer::NodeGear_Conv3d
//-----------------------------------------------------------------------------
bool Trainer::NodeGear_Conv3d::IsVulnerable() const
{
	return _connectorSrc.GetNodeSrc()->IsVulnerable();
}

bool Trainer::NodeGear_Conv3d::DoDirProp(Environment &env, SymbolSet &symbols)
{
	return NodeGear::DoDirProp(env, symbols);
}

Value Trainer::NodeGear_Conv3d::DoGetProp(Environment &env, const Symbol *pSymbol,
								   const SymbolSet &attrs, bool &evaluatedFlag)
{
	return NodeGear::DoGetProp(env, pSymbol, attrs, evaluatedFlag);
}

bool Trainer::NodeGear_Conv3d::EvalForward(Environment &env)
{
	return _pGear->Apply(env, _pArrayFwd, GetConnectorSrc()->GetArrayFwd());
}

bool Trainer::NodeGear_Conv3d::EvalBackward(Environment &env)
{
	return false;
}

Trainer::NodeGear *Trainer::NodeGear_Conv3d::CreatorEx::Create(const Value &value, Connector *pConnectorDst) const
{
	return new NodeGear_Conv3d(Object_gear_at_conv3d::GetObject(value)->GetGear()->Reference(), pConnectorDst);
}

//-----------------------------------------------------------------------------
// Trainer::NodeGear_MaxPool1d
//-----------------------------------------------------------------------------
bool Trainer::NodeGear_MaxPool1d::IsVulnerable() const
{
	return _connectorSrc.GetNodeSrc()->IsVulnerable();
}

bool Trainer::NodeGear_MaxPool1d::EvalForward(Environment &env)
{
	return _pGear->Apply(env, _pArrayFwd, GetConnectorSrc()->GetArrayFwd());
}

bool Trainer::NodeGear_MaxPool1d::EvalBackward(Environment &env)
{
	return false;
}

Trainer::NodeGear *Trainer::NodeGear_MaxPool1d::CreatorEx::Create(const Value &value, Connector *pConnectorDst) const
{
	return new NodeGear_MaxPool1d(Object_gear_at_maxpool1d::GetObject(value)->GetGear()->Reference(), pConnectorDst);
}

//-----------------------------------------------------------------------------
// Trainer::NodeGear_MaxPool2d
//-----------------------------------------------------------------------------
bool Trainer::NodeGear_MaxPool2d::IsVulnerable() const
{
	return _connectorSrc.GetNodeSrc()->IsVulnerable();
}

bool Trainer::NodeGear_MaxPool2d::EvalForward(Environment &env)
{
	return _pGear->Apply(env, _pArrayFwd, GetConnectorSrc()->GetArrayFwd());
}

bool Trainer::NodeGear_MaxPool2d::EvalBackward(Environment &env)
{
	return false;
}

Trainer::NodeGear *Trainer::NodeGear_MaxPool2d::CreatorEx::Create(const Value &value, Connector *pConnectorDst) const
{
	return new NodeGear_MaxPool2d(Object_gear_at_maxpool2d::GetObject(value)->GetGear()->Reference(), pConnectorDst);
}

//-----------------------------------------------------------------------------
// Trainer::NodeGear_MaxPool3d
//-----------------------------------------------------------------------------
bool Trainer::NodeGear_MaxPool3d::IsVulnerable() const
{
	return _connectorSrc.GetNodeSrc()->IsVulnerable();
}

bool Trainer::NodeGear_MaxPool3d::EvalForward(Environment &env)
{
	return _pGear->Apply(env, _pArrayFwd, GetConnectorSrc()->GetArrayFwd());
}

bool Trainer::NodeGear_MaxPool3d::EvalBackward(Environment &env)
{
	return false;
}

Trainer::NodeGear *Trainer::NodeGear_MaxPool3d::CreatorEx::Create(const Value &value, Connector *pConnectorDst) const
{
	return new NodeGear_MaxPool3d(Object_gear_at_maxpool3d::GetObject(value)->GetGear()->Reference(), pConnectorDst);
}

//-----------------------------------------------------------------------------
// Trainer::NodeGear_Relu
//-----------------------------------------------------------------------------
template<typename T_Elem>
class Operator_Relu2Out {
public:
	inline static void Calc(T_Elem &elemRtn, Boolean &elemBool, const T_Elem &elem) {
		elemBool = (elem > 0);
		elemRtn = elemBool? elem : 0;
	}
};

bool Trainer::NodeGear_Relu::IsVulnerable() const
{
	return _connectorSrc.GetNodeSrc()->IsVulnerable();
}

bool Trainer::NodeGear_Relu::EvalForward(Environment &env)
{
	static const Array::Unary2OutFuncT funcs[Array::ETYPE_Max] = {
		nullptr,
		&Array::Unary2OutFuncTmpl<Boolean,	Boolean,	Boolean,	Operator_Relu2Out<Boolean> >,
		&Array::Unary2OutFuncTmpl<Int8,		Boolean,	Int8,		Operator_Relu2Out<Int8> >,
		&Array::Unary2OutFuncTmpl<UInt8,	Boolean,	UInt8,		Operator_Relu2Out<UInt8> >,
		&Array::Unary2OutFuncTmpl<Int16,	Boolean,	Int16,		Operator_Relu2Out<Int16> >,
		&Array::Unary2OutFuncTmpl<UInt16,	Boolean,	UInt16,		Operator_Relu2Out<UInt16> >,
		&Array::Unary2OutFuncTmpl<Int32,	Boolean,	Int32,		Operator_Relu2Out<Int32> >,
		&Array::Unary2OutFuncTmpl<UInt32,	Boolean,	UInt32,		Operator_Relu2Out<UInt32> >,
		&Array::Unary2OutFuncTmpl<Int64,	Boolean,	Int64,		Operator_Relu2Out<Int64> >,
		&Array::Unary2OutFuncTmpl<UInt64,	Boolean,	UInt64,		Operator_Relu2Out<UInt64> >,
		&Array::Unary2OutFuncTmpl<Half,		Boolean,	Half,		Operator_Relu2Out<Half> >,
		&Array::Unary2OutFuncTmpl<Float,	Boolean,	Float,		Operator_Relu2Out<Float> >,
		&Array::Unary2OutFuncTmpl<Double,	Boolean,	Double,		Operator_Relu2Out<Double> >,
		nullptr,
		nullptr,
	};
	const Array *pArray = GetConnectorSrc()->GetArrayFwd();
	Array::Unary2OutFuncT func = funcs[pArray->GetElemType()];
	if (func == nullptr) {
		env.SetError(ERR_TypeError, "can't evaluate forward function");
		return nullptr;
	}
	(*func)(env, _pArrayFwd, _pArrayBool, pArray);
	return env.IsNoSignalled();
}

bool Trainer::NodeGear_Relu::EvalBackward(Environment &env)
{
	ConnectorList::iterator ppConnectorDst = _connectorsDst.begin();
	if (ppConnectorDst == _connectorsDst.end()) return true;
	if (_connectorSrc.GetNodeSrc()->IsVulnerable()) {
		if (!Array::ApplyBinaryFunc(
				env, Array::binaryFuncPack_Mul, _connectorSrc.GetArrayBwdAutoPtr(),
				_pArrayBool.get(),
				(*ppConnectorDst)->GetArrayBwd())) return false;
	}
	return true;
}

bool Trainer::NodeGear_Relu::DoDirProp(Environment &env, SymbolSet &symbols)
{
	return NodeGear::DoDirProp(env, symbols);
}

Value Trainer::NodeGear_Relu::DoGetProp(Environment &env, const Symbol *pSymbol,
								   const SymbolSet &attrs, bool &evaluatedFlag)
{
	return NodeGear::DoGetProp(env, pSymbol, attrs, evaluatedFlag);
}

Trainer::NodeGear *Trainer::NodeGear_Relu::CreatorEx::Create(const Value &value, Connector *pConnectorDst) const
{
	return new NodeGear_Relu(Object_gear_at_relu::GetObject(value)->GetGear()->Reference(), pConnectorDst);
}

//-----------------------------------------------------------------------------
// Trainer::NodeGear_Sigmoid
//-----------------------------------------------------------------------------
bool Trainer::NodeGear_Sigmoid::IsVulnerable() const
{
	return _connectorSrc.GetNodeSrc()->IsVulnerable();
}

bool Trainer::NodeGear_Sigmoid::EvalForward(Environment &env)
{
	return _pGear->Apply(env, _pArrayFwd, GetConnectorSrc()->GetArrayFwd());
}

bool Trainer::NodeGear_Sigmoid::EvalBackward(Environment &env)
{
	ConnectorList::iterator ppConnectorDst = _connectorsDst.begin();
	if (ppConnectorDst == _connectorsDst.end()) return true;
	if (_connectorSrc.GetNodeSrc()->IsVulnerable()) {
		// 1 - y
		if (!Array::ApplyBinaryFunc_number_array(
				env, Array::binaryFuncPack_Sub, _pArrayTmp,
				1, _pArrayFwd.get())) return false;
		// (1 - y) * y
		if (!Array::ApplyBinaryFunc(
				env, Array::binaryFuncPack_Mul, _pArrayTmp,
				_pArrayTmp.get(), _pArrayFwd.get())) return false;
		if (env.IsSignalled()) return false;
		// (1 - y) * y * bwd_in
		if (!Array::ApplyBinaryFunc(
				env, Array::binaryFuncPack_Mul, _connectorSrc.GetArrayBwdAutoPtr(),
				_pArrayTmp.get(),
				(*ppConnectorDst)->GetArrayBwd())) return false;
	}
	return true;
}

bool Trainer::NodeGear_Sigmoid::DoDirProp(Environment &env, SymbolSet &symbols)
{
	return NodeGear::DoDirProp(env, symbols);
}

Value Trainer::NodeGear_Sigmoid::DoGetProp(Environment &env, const Symbol *pSymbol,
										   const SymbolSet &attrs, bool &evaluatedFlag)
{
	return NodeGear::DoGetProp(env, pSymbol, attrs, evaluatedFlag);
}

Trainer::NodeGear *Trainer::NodeGear_Sigmoid::CreatorEx::Create(const Value &value, Connector *pConnectorDst) const
{
	return new NodeGear_Sigmoid(Object_gear_at_sigmoid::GetObject(value)->GetGear()->Reference(), pConnectorDst);
}

//-----------------------------------------------------------------------------
// Trainer::NodeGear_Softmax
//-----------------------------------------------------------------------------
bool Trainer::NodeGear_Softmax::IsVulnerable() const
{
	return _connectorSrc.GetNodeSrc()->IsVulnerable();
}

bool Trainer::NodeGear_Softmax::EvalForward(Environment &env)
{
	return _pGear->Apply(env, _pArrayFwd, GetConnectorSrc()->GetArrayFwd());
}

bool Trainer::NodeGear_Softmax::EvalBackward(Environment &env)
{
	ConnectorList::iterator ppConnectorDst = _connectorsDst.begin();
	if (ppConnectorDst == _connectorsDst.end()) return true;
	_connectorSrc.SetArrayBwd((*ppConnectorDst)->GetArrayBwd()->Reference());
	return true;
}

Trainer::NodeGear *Trainer::NodeGear_Softmax::CreatorEx::Create(const Value &value, Connector *pConnectorDst) const
{
	return new NodeGear_Softmax(Object_gear_at_softmax::GetObject(value)->GetGear()->Reference(), pConnectorDst);
}

//-----------------------------------------------------------------------------
// Trainer::NodeGear_Tanh
//-----------------------------------------------------------------------------
bool Trainer::NodeGear_Tanh::IsVulnerable() const
{
	return _connectorSrc.GetNodeSrc()->IsVulnerable();
}

bool Trainer::NodeGear_Tanh::EvalForward(Environment &env)
{
	return _pGear->Apply(env, _pArrayFwd, GetConnectorSrc()->GetArrayFwd());
}

bool Trainer::NodeGear_Tanh::EvalBackward(Environment &env)
{
	return false;
}

Trainer::NodeGear *Trainer::NodeGear_Tanh::CreatorEx::Create(const Value &value, Connector *pConnectorDst) const
{
	return new NodeGear_Tanh(Object_gear_at_tanh::GetObject(value)->GetGear()->Reference(), pConnectorDst);
}

#endif

//-----------------------------------------------------------------------------
// Trainer::NodeList
//-----------------------------------------------------------------------------
bool Trainer::NodeList::EvalForward(Environment &env)
{
	foreach_reverse (NodeList, ppNode, *this) {
		Node *pNode = *ppNode;
		if (!pNode->EvalForward(env)) return false;
	}
	return true;
}

bool Trainer::NodeList::EvalBackward(Environment &env)
{
	foreach (NodeList, ppNode, *this) {
		Node *pNode = *ppNode;
		if (!pNode->EvalBackward(env)) return false;
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

}
