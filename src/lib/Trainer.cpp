//=============================================================================
// Trainer
//=============================================================================
#include "stdafx.h"

namespace Gura {


//------------------------------------------------------------------------------
// Unary2OutFuncTmpl
//------------------------------------------------------------------------------
template<typename T_ElemRtnA, typename T_ElemRtnB, typename T_Elem, typename T_Operator>
void Unary2OutFuncTmpl(Signal &sig, AutoPtr<Array> &pArrayRtnA, AutoPtr<Array> &pArrayRtnB, const Array *pArray)
{
	const Array::Dimensions &dims = pArray->GetDimensions();
	if (pArrayRtnA.IsNull()) pArrayRtnA.reset(ArrayT<T_ElemRtnA>::Create(dims));
	if (pArrayRtnB.IsNull()) pArrayRtnB.reset(ArrayT<T_ElemRtnB>::Create(dims));
	T_ElemRtnA *pElemRtnA = dynamic_cast<ArrayT<T_ElemRtnA> *>(pArrayRtnA.get())->GetPointer();
	T_ElemRtnB *pElemRtnB = dynamic_cast<ArrayT<T_ElemRtnB> *>(pArrayRtnB.get())->GetPointer();
	const T_Elem *pElem = dynamic_cast<const ArrayT<T_Elem> *>(pArray)->GetPointer();
	if (pArray->IsRowMajor() || dims.size() < 2) {
		size_t nElems = pArray->GetElemNum();
		for (size_t i = 0; i < nElems; i++, pElem++) {
			T_Operator::Calc(*pElemRtnA, *pElemRtnB, *pElem);
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
					T_Operator::Calc(*pElemRtnA, *pElemRtnB, *pElemCol);
					pElemRtnA++, pElemRtnB++;
				}
			}
		}
	}
}

typedef void (*Unary2OutFuncT)(Signal &sig, AutoPtr<Array> &pArrayRtnA, AutoPtr<Array> &pArrayRtnB, const Array *pArray);

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
	Double alpha = .01;
	ConnectorList::iterator ppConnectorDst = _connectorsDst.begin();
	if (IsVulnerable()) {
		if (!Array::ApplyBinaryFunc_array_number(
				env, Array::binaryFuncPack_Mul, _pArrayBwdAdj,
				(*ppConnectorDst)->GetArrayBwd(), alpha)) return false;
		if (!Array::ApplyBinaryFunc(
				env, Array::binaryFuncPack_Sub, _pArrayFwd,
				_pArrayFwd.get(),
				_pArrayBwdAdj.get())) return false;
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
		if (!Array::ApplyBinaryFunc(
				env, Array::binaryFuncPack_Sub, _connectorSrc.GetArrayBwdAutoPtr(),
				_connectorSrc.GetArrayFwd(),
				pArrayCorrect)) return false;
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
	return Array::ApplyBinaryFunc(
			env, _binaryFuncPack, _pArrayFwd,
			GetConnectorSrcLeft()->GetArrayFwd(),
			GetConnectorSrcRight()->GetArrayFwd());
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
String Trainer::NodeGear::ToString() const
{
	String str;
	char buff[128];
	str += "Gear:";
	str += _pGear->ToString();
	::sprintf(buff, " [fwd:%p,bwd:%p]", _connectorSrc.GetArrayFwd(), _connectorSrc.GetArrayBwd());
	str += buff;
	return str;
}

void Trainer::NodeGear::Print(int indentLevel) const
{
	Node::Print(indentLevel);
	_connectorSrc.GetNodeSrc()->Print(indentLevel + 1);
}

//-----------------------------------------------------------------------------
// Trainer::NodeGear_Conv1d
//-----------------------------------------------------------------------------
bool Trainer::NodeGear_Conv1d::IsVulnerable() const
{
	return _connectorSrc.GetNodeSrc()->IsVulnerable();
}

bool Trainer::NodeGear_Conv1d::EvalForward(Environment &env)
{
	return _pGear->Apply(env, _pArrayFwd, GetConnectorSrc()->GetArrayFwd());
}

bool Trainer::NodeGear_Conv1d::EvalBackward(Environment &env)
{
	return false;
}

//-----------------------------------------------------------------------------
// Trainer::NodeGear_Conv2d
//-----------------------------------------------------------------------------
bool Trainer::NodeGear_Conv2d::IsVulnerable() const
{
	return _connectorSrc.GetNodeSrc()->IsVulnerable();
}

bool Trainer::NodeGear_Conv2d::EvalForward(Environment &env)
{
	Gear_Conv2d *pGear = GetGear();
	size_t _sizePadRow = 0;
	size_t _sizePadCol = 0;
	AutoPtr<Array> _pArraySrcVec;
	AutoPtr<Array> _pArrayGearTrans;
	const Double padNum = 0;
	const Array *pArraySrc = GetConnectorSrc()->GetArrayFwd();
	const Array *pArrayGear = pGear->GetArrayGear();
	if (_pArraySrcVec.IsNull()) {
		Gear::CalcPadding2d(pGear, pArraySrc->GetDimensions(), &_sizePadRow, &_sizePadCol);
	}
	// pArraySrc            .. [N, C, H, W] or [N, H, W, C]
	// pArrayGear         .. [FN, C, FH, FW] or [FN, FH, FW, C]
	// _pArrayGearReshape .. [FN, C * FH * FW]
	// _pArraySrcVec        .. [N, H_out, W_out, C * FH * FW]
	// _pArrayGearTrans   .. [C * FH * FW, FN]
	// _pArrayFwd           .. [N, H_out, W_out, FN]
	pArraySrc->ExpandKernelVec2d(
		_pArraySrcVec, pGear->GetSizeRow(), pGear->GetSizeCol(),
		pGear->GetStridesRow(), pGear->GetStridesCol(), _sizePadRow, _sizePadCol,
		pGear->GetChannelPos(), padNum);
	pArrayGear->Transpose2d(_pArrayGearTrans);
	if (!Array::ApplyBinaryFunc(
			env, Array::binaryFuncPack_Dot, _pArrayFwd,
			_pArraySrcVec.get(), _pArrayGearTrans.get())) return false;
	return true;
}

bool Trainer::NodeGear_Conv2d::EvalBackward(Environment &env)
{
	return false;
}

//-----------------------------------------------------------------------------
// Trainer::NodeGear_Conv3d
//-----------------------------------------------------------------------------
bool Trainer::NodeGear_Conv3d::IsVulnerable() const
{
	return _connectorSrc.GetNodeSrc()->IsVulnerable();
}

bool Trainer::NodeGear_Conv3d::EvalForward(Environment &env)
{
	return _pGear->Apply(env, _pArrayFwd, GetConnectorSrc()->GetArrayFwd());
}

bool Trainer::NodeGear_Conv3d::EvalBackward(Environment &env)
{
	return false;
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
	static const Unary2OutFuncT funcs[Array::ETYPE_Max] = {
		nullptr,
		&Unary2OutFuncTmpl<Boolean,	Boolean,	Boolean,	Operator_Relu2Out<Boolean> >,
		&Unary2OutFuncTmpl<Int8,	Boolean,	Int8,		Operator_Relu2Out<Int8> >,
		&Unary2OutFuncTmpl<UInt8,	Boolean,	UInt8,		Operator_Relu2Out<UInt8> >,
		&Unary2OutFuncTmpl<Int16,	Boolean,	Int16,		Operator_Relu2Out<Int16> >,
		&Unary2OutFuncTmpl<UInt16,	Boolean,	UInt16,		Operator_Relu2Out<UInt16> >,
		&Unary2OutFuncTmpl<Int32,	Boolean,	Int32,		Operator_Relu2Out<Int32> >,
		&Unary2OutFuncTmpl<UInt32,	Boolean,	UInt32,		Operator_Relu2Out<UInt32> >,
		&Unary2OutFuncTmpl<Int64,	Boolean,	Int64,		Operator_Relu2Out<Int64> >,
		&Unary2OutFuncTmpl<UInt64,	Boolean,	UInt64,		Operator_Relu2Out<UInt64> >,
		&Unary2OutFuncTmpl<Half,	Boolean,	Half,		Operator_Relu2Out<Half> >,
		&Unary2OutFuncTmpl<Float,	Boolean,	Float,		Operator_Relu2Out<Float> >,
		&Unary2OutFuncTmpl<Double,	Boolean,	Double,		Operator_Relu2Out<Double> >,
		nullptr,
		nullptr,
	};
	const Array *pArray = GetConnectorSrc()->GetArrayFwd();
	Unary2OutFuncT func = funcs[pArray->GetElemType()];
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
	if (_connectorSrc.GetNodeSrc()->IsVulnerable()) {
		if (!Array::ApplyBinaryFunc(
				env, Array::binaryFuncPack_Mul, _connectorSrc.GetArrayBwdAutoPtr(),
				_pArrayBool.get(),
				(*ppConnectorDst)->GetArrayBwd())) return false;
	}
	return true;
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
	_connectorSrc.SetArrayBwd((*ppConnectorDst)->GetArrayBwd()->Reference());
	return true;
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
		return pExprEx->GetOperator()->IsOpType(OPTYPE_Gear)?
			CreateNodeGear(env, pExprEx, pConnector, symbolsInput) :
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

bool Trainer::NodeOwner::CreateNodeGear(Environment &env, const Expr_BinaryOp *pExprEx,
										  Node::Connector *pConnector, const SymbolSet &symbolsInput)
{
	Value value = pExprEx->GetRight()->Exec(env);
	if (env.IsSignalled()) return false;
	AutoPtr<NodeGear> pNode;
	if (!value.IsInstanceOf(VTYPE_gear)) {
		env.SetError(ERR_ValueError, "gear instance is expected as a right-side operand of a gear operator");
		return false;
	}
	const Gear *pGear = Object_gear::GetObject(value)->GetGear();
	if (value.Is_gear_at_conv1d()) {
		pNode.reset(new NodeGear_Conv1d(dynamic_cast<Gear_Conv1d *>(pGear->Reference()), pConnector));
	} else if (value.Is_gear_at_conv2d()) {
		pNode.reset(new NodeGear_Conv2d(dynamic_cast<Gear_Conv2d *>(pGear->Reference()), pConnector));
	} else if (value.Is_gear_at_conv3d()) {
		pNode.reset(new NodeGear_Conv3d(dynamic_cast<Gear_Conv3d *>(pGear->Reference()), pConnector));
	} else if (value.Is_gear_at_maxpool1d()) {
		pNode.reset(new NodeGear_MaxPool1d(dynamic_cast<Gear_MaxPool1d *>(pGear->Reference()), pConnector));
	} else if (value.Is_gear_at_maxpool2d()) {
		pNode.reset(new NodeGear_MaxPool2d(dynamic_cast<Gear_MaxPool2d *>(pGear->Reference()), pConnector));
	} else if (value.Is_gear_at_maxpool3d()) {
		pNode.reset(new NodeGear_MaxPool3d(dynamic_cast<Gear_MaxPool3d *>(pGear->Reference()), pConnector));
	} else if (value.Is_gear_at_relu()) {
		pNode.reset(new NodeGear_Relu(dynamic_cast<Gear_Relu *>(pGear->Reference()), pConnector));
	} else if (value.Is_gear_at_sigmoid()) {
		pNode.reset(new NodeGear_Sigmoid(dynamic_cast<Gear_Sigmoid *>(pGear->Reference()), pConnector));
	} else if (value.Is_gear_at_softmax()) {
		pNode.reset(new NodeGear_Softmax(dynamic_cast<Gear_Softmax *>(pGear->Reference()), pConnector));
	} else if (value.Is_gear_at_tanh()) {
		pNode.reset(new NodeGear_Tanh(dynamic_cast<Gear_Tanh *>(pGear->Reference()), pConnector));
	} else {
		env.SetError(ERR_ValueError, "unsupported gear type: %s", value.MakeValueTypeName().c_str());
		return false;
	}
	Node::Connector *pConnectorSrc = pNode->GetConnectorSrc();
	push_back(pNode.release());
	return CreateFromExpr(env, pExprEx->GetLeft(), pConnectorSrc, symbolsInput);
}

}
