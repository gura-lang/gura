#include "ArrayChain.h"

namespace Gura {

//-----------------------------------------------------------------------------
// ArrayItem
//-----------------------------------------------------------------------------
ArrayItem::ArrayItem(Connector *pConnectorDst)
{
	pConnectorDst->SetArrayItemSrc(this);
	_connectorsDst.push_back(pConnectorDst);
}

ArrayItem::~ArrayItem()
{
}

//-----------------------------------------------------------------------------
// ArrayItem::Connector
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// ArrayItem::ConnectorList
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// ArrayItemHead
//-----------------------------------------------------------------------------
bool ArrayItemHead::InitForward(Environment &env)
{
	//::printf("ArrayItemHead::InitForward()\n");
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

bool ArrayItemHead::EvalForward(Environment &env)
{
	//::printf("ArrayItemHead::EvalForward()\n");
	return true;
}

bool ArrayItemHead::InitBackward(Environment &env)
{
	// nothing to do
	return true;
}

bool ArrayItemHead::EvalBackward(Environment &env)
{
	//::printf("ArrayItemHead::EvalBackward()\n");
	ConnectorList::iterator ppConnectorDst = _connectorsDst.begin();
	::printf("%s\n", (*ppConnectorDst)->GetArrayBwd()->ToString(false).c_str());
	return true;
}

void ArrayItemHead::Print(int indentLevel)
{
	::printf("%-*sArrayItemHead\n", indentLevel * 2, "");
}

//-----------------------------------------------------------------------------
// ArrayItemTail
//-----------------------------------------------------------------------------
bool ArrayItemTail::InitForward(Environment &env)
{
	//::printf("ArrayItemTail::InitForward()\n");
	return true;
}

bool ArrayItemTail::EvalForward(Environment &env)
{
	//::printf("ArrayItemTail::EvalForward()\n");
	::printf("%s\n", _connectorSrc.GetArrayFwd()->ToString(false).c_str());
	return true;
}

bool ArrayItemTail::InitBackward(Environment &env)
{
	Array *pArrayFwd = _connectorSrc.GetArrayFwd();
	AutoPtr<Array> pArrayBwd(Array::Create(pArrayFwd->GetElemType(), false, pArrayFwd->GetDimensions()));
	pArrayBwd->Fill(1);
	_connectorSrc.SetArrayBwd(pArrayBwd.release());
	return true;
}

bool ArrayItemTail::EvalBackward(Environment &env)
{
	// nothing to do
	return true;
}

void ArrayItemTail::Print(int indentLevel)
{
	::printf("%*sArrayItemTail[fwd:%p,bwd:%p]\n", indentLevel * 2, "",
			 _connectorSrc.GetArrayFwd(), _connectorSrc.GetArrayBwd());
	_connectorSrc.GetArrayItemSrc()->Print(indentLevel + 1);
}

//-----------------------------------------------------------------------------
// ArrayItemUnary
//-----------------------------------------------------------------------------
bool ArrayItemUnary::InitForward(Environment &env)
{
	//::printf("ArrayItemUnary::InitForward()\n");
	_pArrayFwd.reset(
		Array::ApplyUnaryFunc(
			env, _unaryFuncPack, nullptr,
			GetConnectorSrc()->GetArrayFwd()));
	return env.IsNoSignalled();
}

bool ArrayItemUnary::EvalForward(Environment &env)
{
	//::printf("ArrayItemUnary::EvalForward()\n");
	Array::Delete(
		Array::ApplyUnaryFunc(
			env, _unaryFuncPack, _pArrayFwd.get(),
			GetConnectorSrc()->GetArrayFwd()));
	return env.IsNoSignalled();
}

void ArrayItemUnary::Print(int indentLevel)
{
	::printf("%-*sArrayItemUnary[fwd:%p,bwd:%p]\n", indentLevel * 2, "",
			 _connectorSrc.GetArrayFwd(), _connectorSrc.GetArrayBwd());
	_connectorSrc.GetArrayItemSrc()->Print(indentLevel + 1);
}

//-----------------------------------------------------------------------------
// ArrayItemUnary_Pos
//-----------------------------------------------------------------------------
bool ArrayItemUnary_Pos::InitBackward(Environment &env)
{
	ConnectorList::iterator ppConnectorDst = _connectorsDst.begin();
	Array *pArrayBwd = (*ppConnectorDst)->GetArrayBwd()->Reference();
	if (!_connectorSrc.IsSourceConstant()) {
		_connectorSrc.SetArrayBwd(pArrayBwd);
	}
	return true;
}

bool ArrayItemUnary_Pos::EvalBackward(Environment &env)
{
	// nothing to do
	return true;
}

//-----------------------------------------------------------------------------
// ArrayItemUnary_Neg
//-----------------------------------------------------------------------------
bool ArrayItemUnary_Neg::InitBackward(Environment &env)
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

bool ArrayItemUnary_Neg::EvalBackward(Environment &env)
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
// ArrayItemUnary_Math_relu
//-----------------------------------------------------------------------------
bool ArrayItemUnary_Math_relu::InitBackward(Environment &env)
{
	return false;
}

bool ArrayItemUnary_Math_relu::EvalBackward(Environment &env)
{
	return false;
}

//-----------------------------------------------------------------------------
// ArrayItemUnary_Math_sigmoid
//-----------------------------------------------------------------------------
bool ArrayItemUnary_Math_sigmoid::InitBackward(Environment &env)
{
	return false;
}

bool ArrayItemUnary_Math_sigmoid::EvalBackward(Environment &env)
{
	return false;
}

//-----------------------------------------------------------------------------
// ArrayItemBinary
//-----------------------------------------------------------------------------
bool ArrayItemBinary::InitForward(Environment &env)
{
	//::printf("ArrayItemBinary::InitForward()\n");
	_pArrayFwd.reset(
		Array::ApplyBinaryFunc(
			env, _binaryFuncPack, nullptr,
			GetConnectorSrcLeft()->GetArrayFwd(),
			GetConnectorSrcRight()->GetArrayFwd()));
	return env.IsNoSignalled();
}

bool ArrayItemBinary::EvalForward(Environment &env)
{
	//::printf("ArrayItemBinary::EvalForward()\n");
	Array::Delete(
		Array::ApplyBinaryFunc(
			env, _binaryFuncPack, _pArrayFwd.get(),
			GetConnectorSrcLeft()->GetArrayFwd(),
			GetConnectorSrcRight()->GetArrayFwd()));
	return env.IsNoSignalled();
}

void ArrayItemBinary::Print(int indentLevel)
{
	::printf("%-*sArrayItemBinary[fwd:%p,bwd:%p][fwd:%p,bwd:%p]\n", indentLevel * 2, "",
			 _connectorSrcLeft.GetArrayFwd(), _connectorSrcLeft.GetArrayBwd(),
			 _connectorSrcRight.GetArrayFwd(), _connectorSrcRight.GetArrayBwd());
	_connectorSrcLeft.GetArrayItemSrc()->Print(indentLevel + 1);
	_connectorSrcRight.GetArrayItemSrc()->Print(indentLevel + 1);
}

//-----------------------------------------------------------------------------
// ArrayItemBinary_Add
//-----------------------------------------------------------------------------
bool ArrayItemBinary_Add::InitBackward(Environment &env)
{
	ConnectorList::iterator ppConnectorDst = _connectorsDst.begin();
	const Array *pArrayBwd = (*ppConnectorDst)->GetArrayBwd();
	_connectorSrcLeft.SetArrayBwd(pArrayBwd->Reference());
	_connectorSrcRight.SetArrayBwd(pArrayBwd->Reference());
	return true;
}

bool ArrayItemBinary_Add::EvalBackward(Environment &env)
{
	// nothing to do
	return true;
}

//-----------------------------------------------------------------------------
// ArrayItemBinary_Sub
//-----------------------------------------------------------------------------
bool ArrayItemBinary_Sub::InitBackward(Environment &env)
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

bool ArrayItemBinary_Sub::EvalBackward(Environment &env)
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
// ArrayItemBinary_Mul
//-----------------------------------------------------------------------------
bool ArrayItemBinary_Mul::InitBackward(Environment &env)
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

bool ArrayItemBinary_Mul::EvalBackward(Environment &env)
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
// ArrayItemBinary_Div
//-----------------------------------------------------------------------------
bool ArrayItemBinary_Div::InitBackward(Environment &env)
{
	return false;
}

bool ArrayItemBinary_Div::EvalBackward(Environment &env)
{
	return false;
}

//-----------------------------------------------------------------------------
// ArrayItemBinary_Pow
//-----------------------------------------------------------------------------
bool ArrayItemBinary_Pow::InitBackward(Environment &env)
{
	return false;
}

bool ArrayItemBinary_Pow::EvalBackward(Environment &env)
{
	return false;
}

//-----------------------------------------------------------------------------
// ArrayItemBinary_Dot
//-----------------------------------------------------------------------------
bool ArrayItemBinary_Dot::InitBackward(Environment &env)
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

bool ArrayItemBinary_Dot::EvalBackward(Environment &env)
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
// ArrayItemBinary_Filter
//-----------------------------------------------------------------------------
bool ArrayItemBinary_Filter::InitBackward(Environment &env)
{
	return false;
}

bool ArrayItemBinary_Filter::EvalBackward(Environment &env)
{
	return false;
}
#endif

//-----------------------------------------------------------------------------
// ArrayItemList
//-----------------------------------------------------------------------------
bool ArrayItemList::InitForward(Environment &env)
{
	foreach_reverse (ArrayItemList, ppArrayItem, *this) {
		if (!(*ppArrayItem)->InitForward(env)) return false;
	}
	return true;
}

bool ArrayItemList::InitBackward(Environment &env)
{
	foreach (ArrayItemList, ppArrayItem, *this) {
		if (!(*ppArrayItem)->InitBackward(env)) return false;
	}
	return true;
}

bool ArrayItemList::EvalForward(Environment &env)
{
	foreach_reverse (ArrayItemList, ppArrayItem, *this) {
		if (!(*ppArrayItem)->EvalForward(env)) return false;
	}
	return true;
}

bool ArrayItemList::EvalBackward(Environment &env)
{
	foreach (ArrayItemList, ppArrayItem, *this) {
		if (!(*ppArrayItem)->EvalBackward(env)) return false;
	}
	return true;
}

//-----------------------------------------------------------------------------
// ArrayItemOwner
//-----------------------------------------------------------------------------
ArrayItemOwner::~ArrayItemOwner()
{
	Clear();
}

void ArrayItemOwner::Clear()
{
	foreach (ArrayItemOwner, ppArrayItem, *this) {
		delete *ppArrayItem;
	}
	clear();
}

//-----------------------------------------------------------------------------
// ArrayChain
//-----------------------------------------------------------------------------
ArrayChain::~ArrayChain()
{
}

bool ArrayChain::CreateFromExpr(Environment &env, const Expr *pExpr)
{
	std::unique_ptr<ArrayItemTail> pArrayItem(new ArrayItemTail());
	ArrayItem::Connector *pConnectorSrc = pArrayItem->GetConnectorSrc();
	_arrayItemOwner.push_back(pArrayItem.release());
	if (!CreateFromExprSub(env, pExpr, pConnectorSrc)) return false;
	return true;
}

bool ArrayChain::CreateFromExprSub(Environment &env, const Expr *pExpr, ArrayItem::Connector *pConnector)
{
	if (pExpr->IsType(EXPRTYPE_UnaryOp)) {
		const Expr_UnaryOp *pExprEx = dynamic_cast<const Expr_UnaryOp *>(pExpr);
		const Operator *pOperator = pExprEx->GetOperator();
		std::unique_ptr<ArrayItemUnary> pArrayItem;
		if (pOperator->IsOpType(OPTYPE_Pos)) {
			pArrayItem.reset(new ArrayItemUnary_Pos(pConnector));
		} else if (pOperator->IsOpType(OPTYPE_Neg)) {
			pArrayItem.reset(new ArrayItemUnary_Neg(pConnector));
		} else {
			env.SetError(ERR_ValueError, "unsupported operator: %s", pOperator->GetName());
			return false;
		}
		ArrayItem::Connector *pConnectorSrc = pArrayItem->GetConnectorSrc();
		_arrayItemOwner.push_back(pArrayItem.release());
		if (!CreateFromExprSub(env, pExprEx->GetChild(), pConnectorSrc)) {
			return false;
		}
		return true;
	} else if (pExpr->IsType(EXPRTYPE_BinaryOp)) {
		const Expr_BinaryOp *pExprEx = dynamic_cast<const Expr_BinaryOp *>(pExpr);
		const Operator *pOperator = pExprEx->GetOperator();
		std::unique_ptr<ArrayItemBinary> pArrayItem;
		if (pOperator->IsOpType(OPTYPE_Add)) {
			pArrayItem.reset(new ArrayItemBinary_Add(pConnector));
		} else if (pOperator->IsOpType(OPTYPE_Sub)) {
			pArrayItem.reset(new ArrayItemBinary_Sub(pConnector));
		} else if (pOperator->IsOpType(OPTYPE_Mul)) {
			pArrayItem.reset(new ArrayItemBinary_Mul(pConnector));
		} else if (pOperator->IsOpType(OPTYPE_Div)) {
			pArrayItem.reset(new ArrayItemBinary_Div(pConnector));
		} else if (pOperator->IsOpType(OPTYPE_Pow)) {
			pArrayItem.reset(new ArrayItemBinary_Pow(pConnector));
		} else if (pOperator->IsOpType(OPTYPE_Dot)) {
			pArrayItem.reset(new ArrayItemBinary_Dot(pConnector));
		} else if (pOperator->IsOpType(OPTYPE_Filter)) {
			//pArrayItem.reset(new ArrayItemBinary_Filter(pConnector));
		} else {
			env.SetError(ERR_ValueError, "unsupported operator: %s", pOperator->GetName());
			return false;
		}
		ArrayItem::Connector *pConnectorSrcLeft = pArrayItem->GetConnectorSrcLeft();
		ArrayItem::Connector *pConnectorSrcRight = pArrayItem->GetConnectorSrcRight();
		_arrayItemOwner.push_back(pArrayItem.release());
		if (!CreateFromExprSub(env, pExprEx->GetLeft(), pConnectorSrcLeft) ||
			!CreateFromExprSub(env, pExprEx->GetRight(), pConnectorSrcRight)) {
			return false;
		}
		return true;
	} else if (pExpr->IsType(EXPRTYPE_Caller)) {
		const Expr_Caller *pExprEx = dynamic_cast<const Expr_Caller *>(pExpr);
		const ExprOwner &exprsArg = pExprEx->GetExprOwner();
		std::unique_ptr<ArrayItemUnary> pArrayItem;
		if (pExprEx->GetCar()->IsMember()) {
			const Expr_Member *pExprCar = dynamic_cast<const Expr_Member *>(pExprEx->GetCar());
			if (pExprCar->GetTarget()->IsSymbol(Gura_Symbol(math)) && pExprCar->GetSelector()->IsIdentifier()) {
				const Symbol *pSymbol = dynamic_cast<const Expr_Identifier *>(pExprCar->GetSelector())->GetSymbol();
				if (pSymbol->IsIdentical(Gura_Symbol(relu))) {
					pArrayItem.reset(new ArrayItemUnary_Math_relu(pConnector));
				} else if (pSymbol->IsIdentical(Gura_Symbol(sigmoid))) {
					pArrayItem.reset(new ArrayItemUnary_Math_sigmoid(pConnector));
				}
			}
		}
		if (pArrayItem.get() != nullptr) {
			if (exprsArg.size() != 1) {
				env.SetError(ERR_ValueError, "invalid number of arguments");
				return false;
			}
			ArrayItem::Connector *pConnectorSrc = pArrayItem->GetConnectorSrc();
			_arrayItemOwner.push_back(pArrayItem.release());
			if (!CreateFromExprSub(env, exprsArg.front(), pConnectorSrc)) {
				return false;
			}
			return true;
		}
	}
	std::unique_ptr<ArrayItemHead> pArrayItem(
		new ArrayItemHead(pConnector, Expr::Reference(pExpr)));
	_arrayItemOwner.push_back(pArrayItem.release());
	return true;
}

}
