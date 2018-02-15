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
}

bool Trainer::CreateFromExpr(Environment &env, const Expr *pExprModel, const SymbolSet &symbolsInput)
{
	_pExprModel.reset(pExprModel->Reference());
	return CreateNode(env, pExprModel, _pNodeBottom->GetConnectorSrc(), symbolsInput) != nullptr;
}

void Trainer::Reset(Environment &env)
{
	_nodeOwner.Reset(env);
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
	AutoPtr<NodeGear> pNode(pCreator->Create(value, pConnector, this));
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

void Trainer::Optimizer::Instance::Reset(Environment &env)
{
}

//-------------------------------------------------------------------------
// Trainer::Optimizer_AdaGrad
//-------------------------------------------------------------------------
Trainer::Optimizer::Instance *Trainer::Optimizer_AdaGrad::CreateInstance() const
{
	return new InstanceEx(_learningRate, _epsilon);
}

void Trainer::Optimizer_AdaGrad::InstanceEx::Reset(Environment &env)
{
	_pArrayH.reset(nullptr);
	_pArrayWork.reset(nullptr);
}

bool Trainer::Optimizer_AdaGrad::InstanceEx::Update(Signal &sig, AutoPtr<Array> &pArray, const Array *pArrayGrad)
{
	// _pArrayWork <- pArrayGrad * pArrayGrad
	if (!Array::Mul(sig, _pArrayWork, pArrayGrad, pArrayGrad)) return false;
	// _pArrayH <- _pArrayH + _pArrayWork
	if (_pArrayH.IsNull()) {
		_pArrayH.reset(_pArrayWork->CreateLike());
		_pArrayH->FillZero();
	}
	if (!Array::Add(sig, _pArrayH, _pArrayH.get(), _pArrayWork.get())) return false;
	// _pArrayWork <- sqrt(_pArrayH)
	if (!Array::Math_sqrt(sig, _pArrayWork, _pArrayH.get())) return false;
	// _pArrayWork <- _pArrayWork + _epsilon
	if (!Array::Add(sig, _pArrayWork, _pArrayWork.get(), _epsilon)) return false;
	// _pArrayWork <- _pArrayGrad / _pArrayWork
	if (!Array::Div(sig, _pArrayWork, pArrayGrad, _pArrayWork.get())) return false;
	// _pArrayWork <- _pArrayWork * _learningRate
	if (!Array::Mul(sig, _pArrayWork, _pArrayWork.get(), _learningRate)) return false;
	// pArray <- pArray - _pArrayWork
	if (!Array::Sub(sig, pArray, pArray.get(), _pArrayWork.get())) return false;
	return true;
}

//-------------------------------------------------------------------------
// Trainer::Optimizer_Adam
//-------------------------------------------------------------------------
Trainer::Optimizer::Instance *Trainer::Optimizer_Adam::CreateInstance() const
{
	return new InstanceEx();
}

void Trainer::Optimizer_Adam::InstanceEx::Reset(Environment &env)
{
}

bool Trainer::Optimizer_Adam::InstanceEx::Update(Signal &sig, AutoPtr<Array> &pArray, const Array *pArrayGrad)
{
	return true;
}

//-------------------------------------------------------------------------
// Trainer::Optimizer_GradientDescent
//-------------------------------------------------------------------------
Trainer::Optimizer::Instance *Trainer::Optimizer_GradientDescent::CreateInstance() const
{
	return new InstanceEx(_learningRate);
}

void Trainer::Optimizer_GradientDescent::InstanceEx::Reset(Environment &env)
{
}

bool Trainer::Optimizer_GradientDescent::InstanceEx::Update(Signal &sig, AutoPtr<Array> &pArray, const Array *pArrayGrad)
{
	// _pArrayWork <- pArrayGrad * _learningRate
	if (!Array::Mul(sig, _pArrayWork, pArrayGrad, _learningRate)) return false;
	// pArray <- pArray - _pArrayWork
	if (!Array::Sub(sig, pArray, pArray.get(), _pArrayWork.get())) return false;
	return true;
}

//-------------------------------------------------------------------------
// Trainer::Optimizer_Momentum
//-------------------------------------------------------------------------
Trainer::Optimizer::Instance *Trainer::Optimizer_Momentum::CreateInstance() const
{
	return new InstanceEx(_learningRate, _momentum);
}

void Trainer::Optimizer_Momentum::InstanceEx::Reset(Environment &env)
{
	_pArrayVel.reset(nullptr);
	_pArrayWork.reset(nullptr);
}

bool Trainer::Optimizer_Momentum::InstanceEx::Update(Signal &sig, AutoPtr<Array> &pArray, const Array *pArrayGrad)
{
	// _pArrayWork <- pArrayGrad * _learningRate
	if (!Array::Mul(sig, _pArrayWork, pArrayGrad, _learningRate)) return false;
	// _pArrayVel <- _pArrayVel * _momentum
	if (_pArrayVel.IsNull()) {
		_pArrayVel.reset(_pArrayWork->CreateLike());
		_pArrayVel->FillZero();
	}
	if (!Array::Mul(sig, _pArrayVel, _pArrayVel.get(), _momentum)) return false;
	// _pArrayVel <- _pArrayVel - _pArrayWork
	if (!Array::Sub(sig, _pArrayVel, _pArrayVel.get(), _pArrayWork.get())) return false;
	// pArray <- pArray + _pArrayVel
	if (!Array::Add(sig, pArray, pArray.get(), _pArrayVel.get())) return false;
	return true;
}

//-------------------------------------------------------------------------
// Trainer::Optimizer_Nesterov
//-------------------------------------------------------------------------
Trainer::Optimizer::Instance *Trainer::Optimizer_Nesterov::CreateInstance() const
{
	return new InstanceEx();
}

void Trainer::Optimizer_Nesterov::InstanceEx::Reset(Environment &env)
{
}

bool Trainer::Optimizer_Nesterov::InstanceEx::Update(Signal &sig, AutoPtr<Array> &pArray, const Array *pArrayGrad)
{
	return true;
}

//-------------------------------------------------------------------------
// Trainer::Optimizer_None
//-------------------------------------------------------------------------
Trainer::Optimizer::Instance *Trainer::Optimizer_None::CreateInstance() const
{
	return new InstanceEx();
}

bool Trainer::Optimizer_None::InstanceEx::Update(Signal &sig, AutoPtr<Array> &pArray, const Array *pArrayGrad)
{
	return true;
}

//-------------------------------------------------------------------------
// Trainer::Optimizer_RMSprop
//-------------------------------------------------------------------------
Trainer::Optimizer::Instance *Trainer::Optimizer_RMSprop::CreateInstance() const
{
	return new InstanceEx();
}

void Trainer::Optimizer_RMSprop::InstanceEx::Reset(Environment &env)
{
}

bool Trainer::Optimizer_RMSprop::InstanceEx::Update(Signal &sig, AutoPtr<Array> &pArray, const Array *pArrayGrad)
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

bool Trainer::Node::IsHead() { return false; }
bool Trainer::Node::IsBottom() { return false; }
bool Trainer::Node::IsUnary() { return false; }
bool Trainer::Node::IsBinary() { return false; }
bool Trainer::Node::IsGear() { return false; }

void Trainer::Node::Reset(Environment &env)
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
bool Trainer::NodeHead::IsHead() { return true; }

bool Trainer::NodeHead::IsVulnerable() const
{
	return IsVariable();
}

void Trainer::NodeHead::Reset(Environment &env)
{
	_pOptimizerInst->Reset(env);
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
		if (!_pOptimizerInst->Update(env, _pArrayFwd, (*ppConnectorDst)->GetArrayGrad())) return false;
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
bool Trainer::NodeBottom::IsBottom() { return true; }

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
		if (!Array::Sub(env, _connectorSrc.GetArrayGradAutoPtr(),
						_connectorSrc.GetArrayFwd(), pArrayCorrect)) return false;
	}
	return true;
}

bool Trainer::NodeBottom::DoDirProp(Environment &env, SymbolSet &symbols)
{
	symbols.insert(Gura_Symbol(input));
	symbols.insert(Gura_Symbol(inputgrad));
	return Node::DoDirProp(env, symbols);
}

Value Trainer::NodeBottom::DoGetProp(Environment &env, const Symbol *pSymbol,
							   const SymbolSet &attrs, bool &evaluatedFlag)
{
	if (pSymbol->IsIdentical(Gura_Symbol(input))) {
		evaluatedFlag = true;
		return Array::ToValue(env, Array::Reference(_connectorSrc.GetArrayFwd()));
	} else if (pSymbol->IsIdentical(Gura_Symbol(inputgrad))) {
		evaluatedFlag = true;
		return Array::ToValue(env, Array::Reference(_connectorSrc.GetArrayGrad()));
	}
	return Node::DoGetProp(env, pSymbol, attrs, evaluatedFlag);
}

String Trainer::NodeBottom::ToString() const
{
	String str;
	char buff[128];
	str += GetNodeTypeName();
	::sprintf(buff, " [fwd:%p,grad:%p]", _connectorSrc.GetArrayFwd(), _connectorSrc.GetArrayGrad());
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
bool Trainer::NodeUnary::IsUnary() { return true; }

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
	symbols.insert(Gura_Symbol(inputgrad));
	return Node::DoDirProp(env, symbols);
}

Value Trainer::NodeUnary::DoGetProp(Environment &env, const Symbol *pSymbol,
							   const SymbolSet &attrs, bool &evaluatedFlag)
{
	if (pSymbol->IsIdentical(Gura_Symbol(input))) {
		evaluatedFlag = true;
		return Array::ToValue(env, Array::Reference(_connectorSrc.GetArrayFwd()));
	} else if (pSymbol->IsIdentical(Gura_Symbol(inputgrad))) {
		evaluatedFlag = true;
		return Array::ToValue(env, Array::Reference(_connectorSrc.GetArrayGrad()));
	}
	return Node::DoGetProp(env, pSymbol, attrs, evaluatedFlag);
}

String Trainer::NodeUnary::ToString() const
{
	String str;
	char buff[128];
	str += GetNodeTypeName();
	::sprintf(buff, " [fwd:%p,grad:%p]", _connectorSrc.GetArrayFwd(), _connectorSrc.GetArrayGrad());
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
		_connectorSrc.SetArrayGrad((*ppConnectorDst)->GetArrayGrad()->Reference());
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
		if (!Array::Neg(env, _connectorSrc.GetArrayGradAutoPtr(), (*ppConnectorDst)->GetArrayGrad())) return false;
	}
	return true;
}

//-----------------------------------------------------------------------------
// Trainer::NodeBinary
//-----------------------------------------------------------------------------
bool Trainer::NodeBinary::IsBinary() { return true; }

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
	symbols.insert(Gura_Symbol(inputgrad_at_left));
	symbols.insert(Gura_Symbol(inputgrad_at_right));
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
	} else if (pSymbol->IsIdentical(Gura_Symbol(inputgrad_at_left))) {
		evaluatedFlag = true;
		return Array::ToValue(env, Array::Reference(_connectorSrcLeft.GetArrayGrad()));
	} else if (pSymbol->IsIdentical(Gura_Symbol(inputgrad_at_right))) {
		evaluatedFlag = true;
		return Array::ToValue(env, Array::Reference(_connectorSrcRight.GetArrayGrad()));
	}
	return Node::DoGetProp(env, pSymbol, attrs, evaluatedFlag);
}

String Trainer::NodeBinary::ToString() const
{
	String str;
	char buff[128];
	str += GetNodeTypeName();
	::sprintf(buff, " [fwd:%p,grad:%p][fwd:%p,grad:%p]",
			  _connectorSrcLeft.GetArrayFwd(), _connectorSrcLeft.GetArrayGrad(),
			  _connectorSrcRight.GetArrayFwd(), _connectorSrcRight.GetArrayGrad());
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
	const Array *pArrayGrad = (*ppConnectorDst)->GetArrayGrad();
	_connectorSrcLeft.SetArrayGrad(pArrayGrad->Reference());
	_connectorSrcRight.SetArrayGrad(pArrayGrad->Reference());
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
		_connectorSrcLeft.SetArrayGrad((*ppConnectorDst)->GetArrayGrad()->Reference());
	}
	if (_connectorSrcRight.GetNodeSrc()->IsVulnerable()) {
		if (!Array::Neg(env, _connectorSrcRight.GetArrayGradAutoPtr(), (*ppConnectorDst)->GetArrayGrad())) return false;
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
		// res = right * grad
		if (!Array::Mul(env, _connectorSrcLeft.GetArrayGradAutoPtr(),
						_connectorSrcRight.GetArrayFwd(), (*ppConnectorDst)->GetArrayGrad())) return false;
	}
	if (_connectorSrcRight.GetNodeSrc()->IsVulnerable()) {
		// res = left * grad
		if (!Array::Mul(env, _connectorSrcRight.GetArrayGradAutoPtr(),
						_connectorSrcLeft.GetArrayFwd(), (*ppConnectorDst)->GetArrayGrad())) return false;
	}
	return true;
}

//-----------------------------------------------------------------------------
// Trainer::NodeBinary_Div
//-----------------------------------------------------------------------------
bool Trainer::NodeBinary_Div::EvalBackward(Environment &env)
{
	ConnectorList::iterator ppConnectorDst = _connectorsDst.begin();
	if (ppConnectorDst == _connectorsDst.end()) return true;
	if (_connectorSrcLeft.GetNodeSrc()->IsVulnerable()) {
		// res = grad * right
		if (!Array::Div(env, _connectorSrcLeft.GetArrayGradAutoPtr(),
						(*ppConnectorDst)->GetArrayGrad(), _connectorSrcRight.GetArrayFwd())) return false;
	}
	if (_connectorSrcRight.GetNodeSrc()->IsVulnerable()) {
		// res = -grad * right / (left * left)
		if (!Array::Mul(env, _connectorSrcRight.GetArrayGradAutoPtr(),
						_connectorSrcLeft.GetArrayFwd(), (*ppConnectorDst)->GetArrayGrad())) return false;
		if (!Array::Mul(env, _pArrayWork,
						_connectorSrcRight.GetArrayFwd(), _connectorSrcRight.GetArrayFwd())) return false;
		if (!Array::Mul(env, _connectorSrcRight.GetArrayGradAutoPtr(),
						_connectorSrcRight.GetArrayGrad(), _pArrayWork.get())) return false;
		if (!Array::Neg(env, _connectorSrcRight.GetArrayGradAutoPtr(),
						_connectorSrcRight.GetArrayGrad())) return false;
	}
	return true;
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
		if (!Array::Dot(env, _connectorSrcLeft.GetArrayGradAutoPtr(),
						(*ppConnectorDst)->GetArrayGrad(), _pArrayFwdRightTrans.get())) return false;
	}
	if (_connectorSrcRight.GetNodeSrc()->IsVulnerable()) {
		_connectorSrcLeft.GetArrayFwd()->Transpose2d(_pArrayFwdLeftTrans);
		if (!Array::Dot(env, _connectorSrcRight.GetArrayGradAutoPtr(),
						_pArrayFwdLeftTrans.get(), (*ppConnectorDst)->GetArrayGrad())) return false;
	}
	return true;
}

//-----------------------------------------------------------------------------
// Trainer::NodeGear
//-----------------------------------------------------------------------------
bool Trainer::NodeGear::IsGear() { return true; }

bool Trainer::NodeGear::DoDirProp(Environment &env, SymbolSet &symbols)
{
	symbols.insert(Gura_Symbol(gear));
	symbols.insert(Gura_Symbol(input));
	symbols.insert(Gura_Symbol(inputgrad));
	return Node::DoDirProp(env, symbols);
}

Value Trainer::NodeGear::DoGetProp(Environment &env, const Symbol *pSymbol,
								   const SymbolSet &attrs, bool &evaluatedFlag)
{
	if (pSymbol->IsIdentical(Gura_Symbol(gear))) {
		evaluatedFlag = true;
		return Value(_pGear->ToObject(env));
	} else if (pSymbol->IsIdentical(Gura_Symbol(input))) {
		evaluatedFlag = true;
		return Array::ToValue(env, Array::Reference(_connectorSrc.GetArrayFwd()));
	} else if (pSymbol->IsIdentical(Gura_Symbol(inputgrad))) {
		evaluatedFlag = true;
		return Array::ToValue(env, Array::Reference(_connectorSrc.GetArrayGrad()));
	}
	return Node::DoGetProp(env, pSymbol, attrs, evaluatedFlag);
}

String Trainer::NodeGear::ToString() const
{
	String str;
	char buff[128];
	str += GetNodeTypeName();
	::sprintf(buff, " [fwd:%p,grad:%p]", _connectorSrc.GetArrayFwd(), _connectorSrc.GetArrayGrad());
	str += buff;
	return str;
}

void Trainer::NodeGear::Print(int indentLevel) const
{
	Node::Print(indentLevel);
	_connectorSrc.GetNodeSrc()->Print(indentLevel + 1);
}

//-----------------------------------------------------------------------------
// Trainer::NodeList
//-----------------------------------------------------------------------------
void Trainer::NodeList::Reset(Environment &env)
{
	foreach (NodeList, ppNode, *this) {
		Node *pNode = *ppNode;
		pNode->Reset(env);
	}
}

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
