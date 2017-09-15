#include "ArrayChain.h"

namespace Gura {

//-----------------------------------------------------------------------------
// ArrayEx
//-----------------------------------------------------------------------------
ArrayEx::ArrayEx(Connector *pConnectorDst)
{
	pConnectorDst->SetArrayExSrc(this);
	_connectorsDst.push_back(pConnectorDst);
}

ArrayEx::~ArrayEx()
{
}

//-----------------------------------------------------------------------------
// ArrayEx::Connector
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// ArrayEx::ConnectorList
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// ArrayExHead
//-----------------------------------------------------------------------------
bool ArrayExHead::InitForward(Environment &env)
{
	//::printf("ArrayExHead::InitForward()\n");
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

bool ArrayExHead::EvalForward(Environment &env)
{
	//::printf("ArrayExHead::EvalForward()\n");
	return true;
}

bool ArrayExHead::InitBackward(Environment &env)
{
	// nothing to do
	return true;
}

bool ArrayExHead::EvalBackward(Environment &env)
{
	//::printf("ArrayExHead::EvalBackward()\n");
	ConnectorList::iterator ppConnectorDst = _connectorsDst.begin();
	//::printf("%s\n", (*ppConnectorDst)->GetArrayBwd()->ToString(false).c_str());
	return true;
}

void ArrayExHead::Print(int indentLevel)
{
	::printf("%-*sHead\n", indentLevel * 2, "");
}

//-----------------------------------------------------------------------------
// ArrayExTail
//-----------------------------------------------------------------------------
bool ArrayExTail::InitForward(Environment &env)
{
	//::printf("ArrayExTail::InitForward()\n");
	return true;
}

bool ArrayExTail::EvalForward(Environment &env)
{
	//::printf("ArrayExTail::EvalForward()\n");
	//::printf("%s\n", _connectorSrc.GetArrayFwd()->ToString(false).c_str());
	return true;
}

bool ArrayExTail::InitBackward(Environment &env)
{
	Array *pArrayFwd = _connectorSrc.GetArrayFwd();
	AutoPtr<Array> pArrayBwd(Array::Create(pArrayFwd->GetElemType(), false, pArrayFwd->GetDimensions()));
	pArrayBwd->Fill(1);
	_connectorSrc.SetArrayBwd(pArrayBwd.release());
	return true;
}

bool ArrayExTail::EvalBackward(Environment &env)
{
	// nothing to do
	return true;
}

void ArrayExTail::Print(int indentLevel)
{
	::printf("%*sTail [fwd:%p,bwd:%p]\n", indentLevel * 2, "",
			 _connectorSrc.GetArrayFwd(), _connectorSrc.GetArrayBwd());
	_connectorSrc.GetArrayExSrc()->Print(indentLevel + 1);
}

//-----------------------------------------------------------------------------
// ArrayExUnary
//-----------------------------------------------------------------------------
bool ArrayExUnary::InitForward(Environment &env)
{
	//::printf("ArrayExUnary::InitForward()\n");
	_pArrayFwd.reset(
		Array::ApplyUnaryFunc(
			env, _unaryFuncPack, nullptr,
			GetConnectorSrc()->GetArrayFwd()));
	return env.IsNoSignalled();
}

bool ArrayExUnary::EvalForward(Environment &env)
{
	//::printf("ArrayExUnary::EvalForward()\n");
	Array::Delete(
		Array::ApplyUnaryFunc(
			env, _unaryFuncPack, _pArrayFwd.get(),
			GetConnectorSrc()->GetArrayFwd()));
	return env.IsNoSignalled();
}

void ArrayExUnary::Print(int indentLevel)
{
	::printf("%-*sUnary:%s [fwd:%p,bwd:%p]\n", indentLevel * 2, "",
			 _unaryFuncPack.name,
			 _connectorSrc.GetArrayFwd(), _connectorSrc.GetArrayBwd());
	_connectorSrc.GetArrayExSrc()->Print(indentLevel + 1);
}

//-----------------------------------------------------------------------------
// ArrayExUnary_Pos
//-----------------------------------------------------------------------------
bool ArrayExUnary_Pos::InitBackward(Environment &env)
{
	ConnectorList::iterator ppConnectorDst = _connectorsDst.begin();
	Array *pArrayBwd = (*ppConnectorDst)->GetArrayBwd()->Reference();
	if (!_connectorSrc.IsSourceConstant()) {
		_connectorSrc.SetArrayBwd(pArrayBwd);
	}
	return true;
}

bool ArrayExUnary_Pos::EvalBackward(Environment &env)
{
	// nothing to do
	return true;
}

//-----------------------------------------------------------------------------
// ArrayExUnary_Neg
//-----------------------------------------------------------------------------
bool ArrayExUnary_Neg::InitBackward(Environment &env)
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

bool ArrayExUnary_Neg::EvalBackward(Environment &env)
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
// ArrayExUnary_Math_relu
//-----------------------------------------------------------------------------
bool ArrayExUnary_Math_relu::InitBackward(Environment &env)
{
	return false;
}

bool ArrayExUnary_Math_relu::EvalBackward(Environment &env)
{
	return false;
}

//-----------------------------------------------------------------------------
// ArrayExUnary_Math_sigmoid
//-----------------------------------------------------------------------------
bool ArrayExUnary_Math_sigmoid::InitBackward(Environment &env)
{
	return false;
}

bool ArrayExUnary_Math_sigmoid::EvalBackward(Environment &env)
{
	return false;
}

//-----------------------------------------------------------------------------
// ArrayExBinary
//-----------------------------------------------------------------------------
bool ArrayExBinary::InitForward(Environment &env)
{
	//::printf("ArrayExBinary::InitForward()\n");
	_pArrayFwd.reset(
		Array::ApplyBinaryFunc(
			env, _binaryFuncPack, nullptr,
			GetConnectorSrcLeft()->GetArrayFwd(),
			GetConnectorSrcRight()->GetArrayFwd()));
	return env.IsNoSignalled();
}

bool ArrayExBinary::EvalForward(Environment &env)
{
	//::printf("ArrayExBinary::EvalForward()\n");
	Array::Delete(
		Array::ApplyBinaryFunc(
			env, _binaryFuncPack, _pArrayFwd.get(),
			GetConnectorSrcLeft()->GetArrayFwd(),
			GetConnectorSrcRight()->GetArrayFwd()));
	return env.IsNoSignalled();
}

void ArrayExBinary::Print(int indentLevel)
{
	::printf("%-*sBinary:%s [fwd:%p,bwd:%p][fwd:%p,bwd:%p]\n", indentLevel * 2, "",
			 _binaryFuncPack.name,
			 _connectorSrcLeft.GetArrayFwd(), _connectorSrcLeft.GetArrayBwd(),
			 _connectorSrcRight.GetArrayFwd(), _connectorSrcRight.GetArrayBwd());
	_connectorSrcLeft.GetArrayExSrc()->Print(indentLevel + 1);
	_connectorSrcRight.GetArrayExSrc()->Print(indentLevel + 1);
}

//-----------------------------------------------------------------------------
// ArrayExBinary_Add
//-----------------------------------------------------------------------------
bool ArrayExBinary_Add::InitBackward(Environment &env)
{
	ConnectorList::iterator ppConnectorDst = _connectorsDst.begin();
	const Array *pArrayBwd = (*ppConnectorDst)->GetArrayBwd();
	_connectorSrcLeft.SetArrayBwd(pArrayBwd->Reference());
	_connectorSrcRight.SetArrayBwd(pArrayBwd->Reference());
	return true;
}

bool ArrayExBinary_Add::EvalBackward(Environment &env)
{
	// nothing to do
	return true;
}

//-----------------------------------------------------------------------------
// ArrayExBinary_Sub
//-----------------------------------------------------------------------------
bool ArrayExBinary_Sub::InitBackward(Environment &env)
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

bool ArrayExBinary_Sub::EvalBackward(Environment &env)
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
// ArrayExBinary_Mul
//-----------------------------------------------------------------------------
bool ArrayExBinary_Mul::InitBackward(Environment &env)
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

bool ArrayExBinary_Mul::EvalBackward(Environment &env)
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
// ArrayExBinary_Div
//-----------------------------------------------------------------------------
bool ArrayExBinary_Div::InitBackward(Environment &env)
{
	return false;
}

bool ArrayExBinary_Div::EvalBackward(Environment &env)
{
	return false;
}

//-----------------------------------------------------------------------------
// ArrayExBinary_Pow
//-----------------------------------------------------------------------------
bool ArrayExBinary_Pow::InitBackward(Environment &env)
{
	return false;
}

bool ArrayExBinary_Pow::EvalBackward(Environment &env)
{
	return false;
}

//-----------------------------------------------------------------------------
// ArrayExBinary_Dot
//-----------------------------------------------------------------------------
bool ArrayExBinary_Dot::InitBackward(Environment &env)
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

bool ArrayExBinary_Dot::EvalBackward(Environment &env)
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
// ArrayExBinary_Filter
//-----------------------------------------------------------------------------
bool ArrayExBinary_Filter::InitBackward(Environment &env)
{
	return false;
}

bool ArrayExBinary_Filter::EvalBackward(Environment &env)
{
	return false;
}
#endif

//-----------------------------------------------------------------------------
// ArrayExList
//-----------------------------------------------------------------------------
bool ArrayExList::InitForward(Environment &env)
{
	foreach_reverse (ArrayExList, ppArrayEx, *this) {
		if (!(*ppArrayEx)->InitForward(env)) return false;
	}
	return true;
}

bool ArrayExList::InitBackward(Environment &env)
{
	foreach (ArrayExList, ppArrayEx, *this) {
		if (!(*ppArrayEx)->InitBackward(env)) return false;
	}
	return true;
}

bool ArrayExList::EvalForward(Environment &env)
{
	foreach_reverse (ArrayExList, ppArrayEx, *this) {
		if (!(*ppArrayEx)->EvalForward(env)) return false;
	}
	return true;
}

bool ArrayExList::EvalBackward(Environment &env)
{
	foreach (ArrayExList, ppArrayEx, *this) {
		if (!(*ppArrayEx)->EvalBackward(env)) return false;
	}
	return true;
}

//-----------------------------------------------------------------------------
// ArrayExOwner
//-----------------------------------------------------------------------------
ArrayExOwner::~ArrayExOwner()
{
	Clear();
}

void ArrayExOwner::Clear()
{
	foreach (ArrayExOwner, ppArrayEx, *this) {
		delete *ppArrayEx;
	}
	clear();
}

bool ArrayExOwner::CreateFromExpr(Environment &env, const Expr *pExpr)
{
	std::unique_ptr<ArrayExTail> pArrayEx(new ArrayExTail());
	ArrayEx::Connector *pConnectorSrc = pArrayEx->GetConnectorSrc();
	push_back(pArrayEx.release());
	if (!CreateFromExprSub(env, pExpr, pConnectorSrc)) return false;
	return true;
}

bool ArrayExOwner::CreateFromExprSub(Environment &env, const Expr *pExpr, ArrayEx::Connector *pConnector)
{
	if (pExpr->IsType(EXPRTYPE_UnaryOp)) {
		const Expr_UnaryOp *pExprEx = dynamic_cast<const Expr_UnaryOp *>(pExpr);
		const Operator *pOperator = pExprEx->GetOperator();
		std::unique_ptr<ArrayExUnary> pArrayEx;
		if (pOperator->IsOpType(OPTYPE_Pos)) {
			pArrayEx.reset(new ArrayExUnary_Pos(pConnector));
		} else if (pOperator->IsOpType(OPTYPE_Neg)) {
			pArrayEx.reset(new ArrayExUnary_Neg(pConnector));
		} else {
			env.SetError(ERR_ValueError, "unsupported operator: %s", pOperator->GetName());
			return false;
		}
		ArrayEx::Connector *pConnectorSrc = pArrayEx->GetConnectorSrc();
		push_back(pArrayEx.release());
		if (!CreateFromExprSub(env, pExprEx->GetChild(), pConnectorSrc)) {
			return false;
		}
		return true;
	} else if (pExpr->IsType(EXPRTYPE_BinaryOp)) {
		const Expr_BinaryOp *pExprEx = dynamic_cast<const Expr_BinaryOp *>(pExpr);
		const Operator *pOperator = pExprEx->GetOperator();
		std::unique_ptr<ArrayExBinary> pArrayEx;
		if (pOperator->IsOpType(OPTYPE_Add)) {
			pArrayEx.reset(new ArrayExBinary_Add(pConnector));
		} else if (pOperator->IsOpType(OPTYPE_Sub)) {
			pArrayEx.reset(new ArrayExBinary_Sub(pConnector));
		} else if (pOperator->IsOpType(OPTYPE_Mul)) {
			pArrayEx.reset(new ArrayExBinary_Mul(pConnector));
		} else if (pOperator->IsOpType(OPTYPE_Div)) {
			pArrayEx.reset(new ArrayExBinary_Div(pConnector));
		} else if (pOperator->IsOpType(OPTYPE_Pow)) {
			pArrayEx.reset(new ArrayExBinary_Pow(pConnector));
		} else if (pOperator->IsOpType(OPTYPE_Dot)) {
			pArrayEx.reset(new ArrayExBinary_Dot(pConnector));
		} else if (pOperator->IsOpType(OPTYPE_Filter)) {
			//pArrayEx.reset(new ArrayExBinary_Filter(pConnector));
		} else {
			env.SetError(ERR_ValueError, "unsupported operator: %s", pOperator->GetName());
			return false;
		}
		ArrayEx::Connector *pConnectorSrcLeft = pArrayEx->GetConnectorSrcLeft();
		ArrayEx::Connector *pConnectorSrcRight = pArrayEx->GetConnectorSrcRight();
		push_back(pArrayEx.release());
		if (!CreateFromExprSub(env, pExprEx->GetLeft(), pConnectorSrcLeft) ||
			!CreateFromExprSub(env, pExprEx->GetRight(), pConnectorSrcRight)) {
			return false;
		}
		return true;
	} else if (pExpr->IsType(EXPRTYPE_Caller)) {
		const Expr_Caller *pExprEx = dynamic_cast<const Expr_Caller *>(pExpr);
		const ExprOwner &exprsArg = pExprEx->GetExprOwner();
		std::unique_ptr<ArrayExUnary> pArrayEx;
		if (pExprEx->GetCar()->IsMember()) {
			const Expr_Member *pExprCar = dynamic_cast<const Expr_Member *>(pExprEx->GetCar());
			if (pExprCar->GetTarget()->IsSymbol(Gura_Symbol(math)) && pExprCar->GetSelector()->IsIdentifier()) {
				const Symbol *pSymbol = dynamic_cast<const Expr_Identifier *>(pExprCar->GetSelector())->GetSymbol();
				if (pSymbol->IsIdentical(Gura_Symbol(relu))) {
					pArrayEx.reset(new ArrayExUnary_Math_relu(pConnector));
				} else if (pSymbol->IsIdentical(Gura_Symbol(sigmoid))) {
					pArrayEx.reset(new ArrayExUnary_Math_sigmoid(pConnector));
				}
			}
		}
		if (pArrayEx.get() != nullptr) {
			if (exprsArg.size() != 1) {
				env.SetError(ERR_ValueError, "invalid number of arguments");
				return false;
			}
			ArrayEx::Connector *pConnectorSrc = pArrayEx->GetConnectorSrc();
			push_back(pArrayEx.release());
			if (!CreateFromExprSub(env, exprsArg.front(), pConnectorSrc)) {
				return false;
			}
			return true;
		}
	}
	std::unique_ptr<ArrayExHead> pArrayEx(
		new ArrayExHead(pConnector, Expr::Reference(pExpr)));
	push_back(pArrayEx.release());
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
	if (!_arrayExOwner.CreateFromExpr(env, pExpr)) return false;
	if (!_arrayExOwner.InitForward(env)) return false;
	if (!_arrayExOwner.InitBackward(env)) return false;
	return true;
}

bool ArrayChain::Eval(Environment &env)
{
	if (!_arrayExOwner.EvalForward(env)) return false;
	if (!_arrayExOwner.EvalBackward(env)) return false;
	return true;
}

void ArrayChain::Print() const
{
	_arrayExOwner.front()->Print(0);
}

}
