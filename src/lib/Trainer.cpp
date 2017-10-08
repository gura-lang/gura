//=============================================================================
// Trainer
//=============================================================================
#include "stdafx.h"

namespace Gura {

//------------------------------------------------------------------------------
// PairFuncTmpl
//------------------------------------------------------------------------------
template<typename T_ElemRtnA, typename T_ElemRtnB, typename T_Elem,
		 void (*op)(T_ElemRtnA &, T_ElemRtnB &, const T_Elem &)>
void PairFuncTmpl(Signal &sig, AutoPtr<Array> &pArrayRtnA, AutoPtr<Array> &pArrayRtnB, const Array *pArray)
{
	bool colMajorFlag = false;
	const Array::Dimensions &dims = pArray->GetDimensions();
	if (pArrayRtnA.IsNull()) pArrayRtnA.reset(ArrayT<T_ElemRtnA>::Create(colMajorFlag, dims));
	if (pArrayRtnB.IsNull()) pArrayRtnB.reset(ArrayT<T_ElemRtnB>::Create(colMajorFlag, dims));
	T_ElemRtnA *pElemRtnA = dynamic_cast<ArrayT<T_ElemRtnA> *>(pArrayRtnA.get())->GetPointer();
	T_ElemRtnB *pElemRtnB = dynamic_cast<ArrayT<T_ElemRtnB> *>(pArrayRtnB.get())->GetPointer();
	const T_Elem *pElem = dynamic_cast<const ArrayT<T_Elem> *>(pArray)->GetPointer();
	if (pArray->IsRowMajor() || dims.size() < 2) {
		size_t nElems = pArray->GetElemNum();
		for (size_t i = 0; i < nElems; i++, pElem++) {
			op(*pElemRtnA, *pElemRtnB, *pElem);
			pElemRtnA++, pElemRtnB++;
		}
	} else { // pArray->IsColMajor() && dims.size() >= 2
		const Array::Dimension &dimRow = dims.GetRow();
		const Array::Dimension &dimCol = dims.GetCol();
		size_t nMats = pArray->GetElemNum() / dimRow.GetSizeProd();
		const T_Elem *pElemMat = pElem;
		for (size_t iMat = 0; iMat < nMats; iMat++, pElemMat += dimRow.GetSizeProd()) {
			const T_Elem *pElemRow = pElemMat;
			for (size_t iRow = 0; iRow < dimRow.GetSize(); iRow++,
					 pElemRow += dimRow.GetStrides()) {
				const T_Elem *pElemCol = pElemRow;
				for (size_t iCol = 0; iCol < dimCol.GetSize(); iCol++,
						 pElemCol += dimCol.GetStrides()) {
					op(*pElemRtnA, *pElemRtnB, *pElemCol);
					pElemRtnA++, pElemRtnB++;
				}
			}
		}
	}
}

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
		if (env.IsSignalled()) return false;
	}
	return true;
}

String Trainer::NodeHead::ToString() const
{
	String str;
	str += "Head:";
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
		_connectorSrc.SetArrayBwd(
			Array::ApplyBinaryFunc(
				env, Array::binaryFuncPack_Sub, _connectorSrc.GetArrayBwd(),
				_connectorSrc.GetArrayFwd(),
				pArrayCorrect));
		if (env.IsSignalled()) return false;
	}
	return true;
}

String Trainer::NodeBottom::ToString() const
{
	String str;
	char buff[128];
	str += "Tail";
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

String Trainer::NodeUnary::ToString() const
{
	String str;
	char buff[128];
	str += "Unary:";
	str += _unaryFuncPack.name;
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
	_pArrayFwd.reset(
		Array::ApplyBinaryFunc(
			env, _binaryFuncPack, _pArrayFwd.get(),
			GetConnectorSrcLeft()->GetArrayFwd(),
			GetConnectorSrcRight()->GetArrayFwd()));
	return env.IsNoSignalled();
}

String Trainer::NodeBinary::ToString() const
{
	String str;
	char buff[128];
	str += "Binary:";
	str += _binaryFuncPack.name;
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
String Trainer::NodeFilter::ToString() const
{
	String str;
	char buff[128];
	str += "Filter:";
	str += _pFilter->ToString();
	::sprintf(buff, " [fwd:%p,bwd:%p]", _connectorSrc.GetArrayFwd(), _connectorSrc.GetArrayBwd());
	str += buff;
	return str;
}

void Trainer::NodeFilter::Print(int indentLevel) const
{
	Node::Print(indentLevel);
	_connectorSrc.GetNodeSrc()->Print(indentLevel + 1);
}

//-----------------------------------------------------------------------------
// Trainer::NodeFilter_Conv1d
//-----------------------------------------------------------------------------
bool Trainer::NodeFilter_Conv1d::IsVulnerable() const
{
	return _connectorSrc.GetNodeSrc()->IsVulnerable();
}

bool Trainer::NodeFilter_Conv1d::EvalForward(Environment &env)
{
	return _pFilter->Apply(env, _pArrayFwd, GetConnectorSrc()->GetArrayFwd());
}

bool Trainer::NodeFilter_Conv1d::EvalBackward(Environment &env)
{
	return false;
}

//-----------------------------------------------------------------------------
// Trainer::NodeFilter_Conv2d
//-----------------------------------------------------------------------------
bool Trainer::NodeFilter_Conv2d::IsVulnerable() const
{
	return _connectorSrc.GetNodeSrc()->IsVulnerable();
}

bool Trainer::NodeFilter_Conv2d::EvalForward(Environment &env)
{
	return _pFilter->Apply(env, _pArrayFwd, GetConnectorSrc()->GetArrayFwd());
}

bool Trainer::NodeFilter_Conv2d::EvalBackward(Environment &env)
{
	return false;
}

//-----------------------------------------------------------------------------
// Trainer::NodeFilter_Conv3d
//-----------------------------------------------------------------------------
bool Trainer::NodeFilter_Conv3d::IsVulnerable() const
{
	return _connectorSrc.GetNodeSrc()->IsVulnerable();
}

bool Trainer::NodeFilter_Conv3d::EvalForward(Environment &env)
{
	return _pFilter->Apply(env, _pArrayFwd, GetConnectorSrc()->GetArrayFwd());
}

bool Trainer::NodeFilter_Conv3d::EvalBackward(Environment &env)
{
	return false;
}

//-----------------------------------------------------------------------------
// Trainer::NodeFilter_MaxPool1d
//-----------------------------------------------------------------------------
bool Trainer::NodeFilter_MaxPool1d::IsVulnerable() const
{
	return _connectorSrc.GetNodeSrc()->IsVulnerable();
}

bool Trainer::NodeFilter_MaxPool1d::EvalForward(Environment &env)
{
	return _pFilter->Apply(env, _pArrayFwd, GetConnectorSrc()->GetArrayFwd());
}

bool Trainer::NodeFilter_MaxPool1d::EvalBackward(Environment &env)
{
	return false;
}

//-----------------------------------------------------------------------------
// Trainer::NodeFilter_MaxPool2d
//-----------------------------------------------------------------------------
bool Trainer::NodeFilter_MaxPool2d::IsVulnerable() const
{
	return _connectorSrc.GetNodeSrc()->IsVulnerable();
}

bool Trainer::NodeFilter_MaxPool2d::EvalForward(Environment &env)
{
	return _pFilter->Apply(env, _pArrayFwd, GetConnectorSrc()->GetArrayFwd());
}

bool Trainer::NodeFilter_MaxPool2d::EvalBackward(Environment &env)
{
	return false;
}

//-----------------------------------------------------------------------------
// Trainer::NodeFilter_MaxPool3d
//-----------------------------------------------------------------------------
bool Trainer::NodeFilter_MaxPool3d::IsVulnerable() const
{
	return _connectorSrc.GetNodeSrc()->IsVulnerable();
}

bool Trainer::NodeFilter_MaxPool3d::EvalForward(Environment &env)
{
	return _pFilter->Apply(env, _pArrayFwd, GetConnectorSrc()->GetArrayFwd());
}

bool Trainer::NodeFilter_MaxPool3d::EvalBackward(Environment &env)
{
	return false;
}

//-----------------------------------------------------------------------------
// Trainer::NodeFilter_Relu
//-----------------------------------------------------------------------------
typedef void (*PairFuncT)(Signal &sig, AutoPtr<Array> &pArrayRtnA, AutoPtr<Array> &pArrayRtnB, const Array *pArray);

template<typename T_ElemRtn, typename T_Elem>
void FuncRelu(T_ElemRtn &elemRtn, Boolean &elemBool, const T_Elem &elem)
{
	elemBool = (elem > 0);
	elemRtn = elemBool? elem : 0;
}

bool Trainer::NodeFilter_Relu::IsVulnerable() const
{
	return _connectorSrc.GetNodeSrc()->IsVulnerable();
}

bool Trainer::NodeFilter_Relu::EvalForward(Environment &env)
{
	static const PairFuncT funcs[Array::ETYPE_Max] = {
		nullptr,
		&PairFuncTmpl<Boolean,	Boolean,	Boolean,	FuncRelu>,
		&PairFuncTmpl<Int8,		Boolean,	Int8,		FuncRelu>,
		&PairFuncTmpl<UInt8,	Boolean,	UInt8,		FuncRelu>,
		&PairFuncTmpl<Int16,	Boolean,	Int16,		FuncRelu>,
		&PairFuncTmpl<UInt16,	Boolean,	UInt16,		FuncRelu>,
		&PairFuncTmpl<Int32,	Boolean,	Int32,		FuncRelu>,
		&PairFuncTmpl<UInt32,	Boolean,	UInt32,		FuncRelu>,
		&PairFuncTmpl<Int64,	Boolean,	Int64,		FuncRelu>,
		&PairFuncTmpl<UInt64,	Boolean,	UInt64,		FuncRelu>,
		&PairFuncTmpl<Half,		Boolean,	Half,		FuncRelu>,
		&PairFuncTmpl<Float,	Boolean,	Float,		FuncRelu>,
		&PairFuncTmpl<Double,	Boolean,	Double,		FuncRelu>,
		nullptr,
		nullptr,
	};
	const Array *pArray = GetConnectorSrc()->GetArrayFwd();
	PairFuncT pairFunc = funcs[pArray->GetElemType()];
	if (pairFunc == nullptr) {
		env.SetError(ERR_TypeError, "can't evaluate forward function");
		return nullptr;
	}
	(*pairFunc)(env, _pArrayFwd, _pArrayBool, pArray);
	return env.IsNoSignalled();
}

bool Trainer::NodeFilter_Relu::EvalBackward(Environment &env)
{
	ConnectorList::iterator ppConnectorDst = _connectorsDst.begin();
	if (_connectorSrc.GetNodeSrc()->IsVulnerable()) {
		_connectorSrc.SetArrayBwd(
			Array::ApplyBinaryFunc(
				env, Array::binaryFuncPack_Mul, _connectorSrc.GetArrayBwd(),
				_pArrayBool.get(),
				(*ppConnectorDst)->GetArrayBwd()));
	}
	return true;
}

//-----------------------------------------------------------------------------
// Trainer::NodeFilter_Sigmoid
//-----------------------------------------------------------------------------
bool Trainer::NodeFilter_Sigmoid::IsVulnerable() const
{
	return _connectorSrc.GetNodeSrc()->IsVulnerable();
}

bool Trainer::NodeFilter_Sigmoid::EvalForward(Environment &env)
{
	return _pFilter->Apply(env, _pArrayFwd, GetConnectorSrc()->GetArrayFwd());
}

bool Trainer::NodeFilter_Sigmoid::EvalBackward(Environment &env)
{
	ConnectorList::iterator ppConnectorDst = _connectorsDst.begin();
	if (_connectorSrc.GetNodeSrc()->IsVulnerable()) {
		// 1 - y
		_pArrayTmp.reset(
			Array::ApplyBinaryFunc_number_array(
				env, Array::binaryFuncPack_Sub, _pArrayTmp.get(),
				1, _pArrayFwd.get()));
		if (env.IsSignalled()) return false;
		// (1 - y) * y
		_pArrayTmp.reset(
			Array::ApplyBinaryFunc(
				env, Array::binaryFuncPack_Mul, _pArrayTmp.get(),
				_pArrayTmp.get(), _pArrayFwd.get()));
		if (env.IsSignalled()) return false;
		// (1 - y) * y * bwd_in
		_connectorSrc.SetArrayBwd(
			Array::ApplyBinaryFunc(
				env, Array::binaryFuncPack_Mul, _connectorSrc.GetArrayBwd(),
				_pArrayTmp.get(),
				(*ppConnectorDst)->GetArrayBwd()));
		if (env.IsSignalled()) return false;
	}
	return true;
}

//-----------------------------------------------------------------------------
// Trainer::NodeFilter_Softmax
//-----------------------------------------------------------------------------
bool Trainer::NodeFilter_Softmax::IsVulnerable() const
{
	return _connectorSrc.GetNodeSrc()->IsVulnerable();
}

bool Trainer::NodeFilter_Softmax::EvalForward(Environment &env)
{
	return _pFilter->Apply(env, _pArrayFwd, GetConnectorSrc()->GetArrayFwd());
}

bool Trainer::NodeFilter_Softmax::EvalBackward(Environment &env)
{
	ConnectorList::iterator ppConnectorDst = _connectorsDst.begin();
	_connectorSrc.SetArrayBwd((*ppConnectorDst)->GetArrayBwd()->Reference());
	return true;
}

//-----------------------------------------------------------------------------
// Trainer::NodeFilter_Tanh
//-----------------------------------------------------------------------------
bool Trainer::NodeFilter_Tanh::IsVulnerable() const
{
	return _connectorSrc.GetNodeSrc()->IsVulnerable();
}

bool Trainer::NodeFilter_Tanh::EvalForward(Environment &env)
{
	return _pFilter->Apply(env, _pArrayFwd, GetConnectorSrc()->GetArrayFwd());
}

bool Trainer::NodeFilter_Tanh::EvalBackward(Environment &env)
{
	return false;
}

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

bool Trainer::NodeOwner::CreateFromExpr(Environment &env, const Expr *pExpr,
										Node::Connector *pConnector, const SymbolSet &symbolsInput)
{
	if (pExpr->IsType(EXPRTYPE_UnaryOp)) {
		const Expr_UnaryOp *pExprEx = dynamic_cast<const Expr_UnaryOp *>(pExpr);
		return CreateNodeUnary(env, pExprEx, pConnector, symbolsInput);
	} else if (pExpr->IsType(EXPRTYPE_BinaryOp)) {
		const Expr_BinaryOp *pExprEx = dynamic_cast<const Expr_BinaryOp *>(pExpr);
		return pExprEx->GetOperator()->IsOpType(OPTYPE_Filter)?
			CreateNodeFilter(env, pExprEx, pConnector, symbolsInput) :
			CreateNodeBinary(env, pExprEx, pConnector, symbolsInput);
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
	return CreateFromExpr(env, pExprEx->GetChild(), pConnectorSrc, symbolsInput);
}

bool Trainer::NodeOwner::CreateNodeBinary(Environment &env, const Expr_BinaryOp *pExprEx,
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
		return false;
	}
	Node::Connector *pConnectorSrcLeft = pNode->GetConnectorSrcLeft();
	Node::Connector *pConnectorSrcRight = pNode->GetConnectorSrcRight();
	push_back(pNode.release());
	return CreateFromExpr(env, pExprEx->GetLeft(), pConnectorSrcLeft, symbolsInput) &&
		CreateFromExpr(env, pExprEx->GetRight(), pConnectorSrcRight, symbolsInput);
}

bool Trainer::NodeOwner::CreateNodeFilter(Environment &env, const Expr_BinaryOp *pExprEx,
										  Node::Connector *pConnector, const SymbolSet &symbolsInput)
{
	Value value = pExprEx->GetRight()->Exec(env);
	if (env.IsSignalled()) return false;
	AutoPtr<NodeFilter> pNode;
	if (!value.IsInstanceOf(VTYPE_filter)) {
		env.SetError(ERR_ValueError, "filter instance is expected as a right-side operand of a filter operator");
		return false;
	}
	const Filter *pFilter = Object_filter::GetObject(value)->GetFilter();
	if (value.Is_filter_at_conv1d()) {
		pNode.reset(new NodeFilter_Conv1d(dynamic_cast<Filter_Conv1d *>(pFilter->Reference()), pConnector));
	} else if (value.Is_filter_at_conv2d()) {
		pNode.reset(new NodeFilter_Conv2d(dynamic_cast<Filter_Conv2d *>(pFilter->Reference()), pConnector));
	} else if (value.Is_filter_at_conv3d()) {
		pNode.reset(new NodeFilter_Conv3d(dynamic_cast<Filter_Conv3d *>(pFilter->Reference()), pConnector));
	} else if (value.Is_filter_at_maxpool1d()) {
		pNode.reset(new NodeFilter_MaxPool1d(dynamic_cast<Filter_MaxPool1d *>(pFilter->Reference()), pConnector));
	} else if (value.Is_filter_at_maxpool2d()) {
		pNode.reset(new NodeFilter_MaxPool2d(dynamic_cast<Filter_MaxPool2d *>(pFilter->Reference()), pConnector));
	} else if (value.Is_filter_at_maxpool3d()) {
		pNode.reset(new NodeFilter_MaxPool3d(dynamic_cast<Filter_MaxPool3d *>(pFilter->Reference()), pConnector));
	} else if (value.Is_filter_at_relu()) {
		pNode.reset(new NodeFilter_Relu(dynamic_cast<Filter_Relu *>(pFilter->Reference()), pConnector));
	} else if (value.Is_filter_at_sigmoid()) {
		pNode.reset(new NodeFilter_Sigmoid(dynamic_cast<Filter_Sigmoid *>(pFilter->Reference()), pConnector));
	} else if (value.Is_filter_at_softmax()) {
		pNode.reset(new NodeFilter_Softmax(dynamic_cast<Filter_Softmax *>(pFilter->Reference()), pConnector));
	} else if (value.Is_filter_at_tanh()) {
		pNode.reset(new NodeFilter_Tanh(dynamic_cast<Filter_Tanh *>(pFilter->Reference()), pConnector));
	} else {
		env.SetError(ERR_ValueError, "unsupported filter type: %s", value.MakeValueTypeName().c_str());
		return false;
	}
	Node::Connector *pConnectorSrc = pNode->GetConnectorSrc();
	push_back(pNode.release());
	return CreateFromExpr(env, pExprEx->GetLeft(), pConnectorSrc, symbolsInput);
}

}
