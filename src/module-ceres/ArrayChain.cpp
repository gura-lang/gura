#include "ArrayChain.h"

namespace Gura {

//-----------------------------------------------------------------------------
// ArrayChain
//-----------------------------------------------------------------------------
ArrayChain::ArrayChain(Connector *pConnectorDst)
{
	pConnectorDst->SetArrayChainSrc(this);
	_connectorsDst.push_back(pConnectorDst);
}

ArrayChain::~ArrayChain()
{
}

//-----------------------------------------------------------------------------
// ArrayChain::Connector
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// ArrayChain::ConnectorList
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// ArrayChainHead
//-----------------------------------------------------------------------------
bool ArrayChainHead::InitForward(Environment &env)
{
	::printf("ArrayChainHead::InitForward()\n");
	Value value = _pExpr->Exec(env);
	if (env.IsSignalled()) return false;
	if (value.Is_number()) {
		_pArrayFwd.reset(ArrayT<Double>::CreateScalar(value.GetDouble()));
	} else if (value.Is_complex()) {
		_pArrayFwd.reset(ArrayT<Complex>::CreateScalar(value.GetComplex()));
	} else if (value.Is_array()) {
		_pArrayFwd.reset(Object_array::GetObject(value)->GetArray()->Reference());
	} else {
		env.SetError(ERR_ValueError, "variable must be an array");
		return false;
	}
	return true;
}

bool ArrayChainHead::EvalForward(Environment &env)
{
	::printf("ArrayChainHead::EvalForward()\n");
	return true;
}

bool ArrayChainHead::InitBackward(Environment &env)
{
	// nothing to do
	return true;
}

bool ArrayChainHead::EvalBackward(Environment &env)
{
	// nothing to do
	return true;
}

void ArrayChainHead::Print(int indentLevel)
{
	::printf("%-*sArrayChainHead\n", indentLevel * 2, "");
}

//-----------------------------------------------------------------------------
// ArrayChainTail
//-----------------------------------------------------------------------------
bool ArrayChainTail::InitForward(Environment &env)
{
	::printf("ArrayChainTail::InitForward()\n");
	return true;
}

bool ArrayChainTail::EvalForward(Environment &env)
{
	::printf("ArrayChainTail::EvalForward()\n");
	::printf("%s\n", _connectorSrc.GetArrayFwd()->ToString(false).c_str());
	return true;
}

bool ArrayChainTail::InitBackward(Environment &env)
{
	Array *pArrayFwd = _connectorSrc.GetArrayFwd();
	AutoPtr<Array> pArrayBwd(Array::Create(pArrayFwd->GetElemType(), pArrayFwd->GetDimensions()));
	pArrayBwd->Fill(1);
	_connectorSrc.AddArrayBwd(pArrayBwd.release());
	return true;
}

bool ArrayChainTail::EvalBackward(Environment &env)
{
	// nothing to do
	return true;
}

void ArrayChainTail::Print(int indentLevel)
{
	::printf("%*-sArrayChainTail[fwd:%p,bwd:%p]\n", indentLevel * 2, "",
			 _connectorSrc.GetArrayFwd(), _connectorSrc.GetArrayBwd());
	_connectorSrc.GetArrayChainSrc()->Print(indentLevel + 1);
}

//-----------------------------------------------------------------------------
// ArrayChainUnary
//-----------------------------------------------------------------------------
bool ArrayChainUnary::InitForward(Environment &env)
{
	::printf("ArrayChainUnary::InitForward()\n");
	_pArrayFwd.reset(
		Array::ApplyUnaryFunc(
			env, _unaryFuncPack, nullptr,
			GetConnectorSrc()->GetArrayFwd()));
	return env.IsNoSignalled();
}

bool ArrayChainUnary::EvalForward(Environment &env)
{
	::printf("ArrayChainUnary::EvalForward()\n");
	Array::Delete(
		Array::ApplyUnaryFunc(
			env, _unaryFuncPack, _pArrayFwd.get(),
			GetConnectorSrc()->GetArrayFwd()));
	return env.IsNoSignalled();
}

void ArrayChainUnary::Print(int indentLevel)
{
	::printf("%-*sArrayChainUnary[fwd:%p,bwd:%p]\n", indentLevel * 2, "",
			 _connectorSrc.GetArrayFwd(), _connectorSrc.GetArrayBwd());
	_connectorSrc.GetArrayChainSrc()->Print(indentLevel + 1);
}

//-----------------------------------------------------------------------------
// ArrayChainUnary_Pos
//-----------------------------------------------------------------------------
bool ArrayChainUnary_Pos::InitBackward(Environment &env)
{
	ConnectorList::iterator ppConnectorDst = _connectorsDst.begin();
	Array *pArrayPrev = (*ppConnectorDst)->GetArrayBwd()->Reference();
	_connectorSrc.AddArrayBwd(pArrayPrev);
	ppConnectorDst++;
	for ( ; ppConnectorDst != _connectorsDst.end(); ppConnectorDst++) {
		pArrayPrev = Array::ApplyBinaryFunc(
			env, Array::binaryFuncPack_Add, nullptr,
			pArrayPrev, (*ppConnectorDst)->GetArrayBwd());
		_connectorSrc.AddArrayBwd(pArrayPrev);
	}
	return env.IsNoSignalled();
}

bool ArrayChainUnary_Pos::EvalBackward(Environment &env)
{
	// nothing to do
	return true;
}

//-----------------------------------------------------------------------------
// ArrayChainUnary_Neg
//-----------------------------------------------------------------------------
bool ArrayChainUnary_Neg::InitBackward(Environment &env)
{
	ConnectorList::iterator ppConnectorDst = _connectorsDst.begin();
	Array *pArrayPrev = Array::ApplyUnaryFunc(
		env, Array::unaryFuncPack_Neg, nullptr,
		(*ppConnectorDst)->GetArrayBwd());
	_connectorSrc.AddArrayBwd(pArrayPrev);
	ppConnectorDst++;
	for ( ; ppConnectorDst != _connectorsDst.end(); ppConnectorDst++) {
		
	}
	return env.IsNoSignalled();
}

bool ArrayChainUnary_Neg::EvalBackward(Environment &env)
{
	Connector *pConnectorDst = _connectorsDst.front();
	Array::Delete(
		Array::ApplyUnaryFunc(
			env, _unaryFuncPack, _connectorSrc.GetArrayBwd(),
			pConnectorDst->GetArrayBwd()));
	return env.IsNoSignalled();
}

//-----------------------------------------------------------------------------
// ArrayChainBinary
//-----------------------------------------------------------------------------
bool ArrayChainBinary::InitForward(Environment &env)
{
	::printf("ArrayChainBinary::InitForward()\n");
	_pArrayFwd.reset(
		Array::ApplyBinaryFunc(
			env, _binaryFuncPack, nullptr,
			GetConnectorSrcLeft()->GetArrayFwd(),
			GetConnectorSrcRight()->GetArrayFwd()));
	return env.IsNoSignalled();
}

bool ArrayChainBinary::EvalForward(Environment &env)
{
	::printf("ArrayChainBinary::EvalForward()\n");
	Array::Delete(
		Array::ApplyBinaryFunc(
			env, _binaryFuncPack, _pArrayFwd.get(),
			GetConnectorSrcLeft()->GetArrayFwd(),
			GetConnectorSrcRight()->GetArrayFwd()));
	return env.IsNoSignalled();
}

void ArrayChainBinary::Print(int indentLevel)
{
	::printf("%-*sArrayChainBinary[fwd:%p,bwd:%p][fwd:%p,bwd:%p]\n", indentLevel * 2, "",
			 _connectorSrcLeft.GetArrayFwd(), _connectorSrcLeft.GetArrayBwd(),
			 _connectorSrcRight.GetArrayFwd(), _connectorSrcRight.GetArrayBwd());
	_connectorSrcLeft.GetArrayChainSrc()->Print(indentLevel + 1);
	_connectorSrcRight.GetArrayChainSrc()->Print(indentLevel + 1);
}

//-----------------------------------------------------------------------------
// ArrayChainBinary_Add
//-----------------------------------------------------------------------------
bool ArrayChainBinary_Add::InitBackward(Environment &env)
{
	ConnectorList::iterator ppConnectorDst = _connectorsDst.begin();
	Array *pArrayPrev = (*ppConnectorDst)->GetArrayBwd()->Reference();
	_connectorSrcLeft.AddArrayBwd(pArrayPrev);
	_connectorSrcRight.AddArrayBwd(pArrayPrev->Reference());
	ppConnectorDst++;
	for ( ; ppConnectorDst != _connectorsDst.end(); ppConnectorDst++) {
		
	}
}

bool ArrayChainBinary_Add::EvalBackward(Environment &env)
{
	// nothing to do
	return true;
}

//-----------------------------------------------------------------------------
// ArrayChainBinary_Sub
//-----------------------------------------------------------------------------
bool ArrayChainBinary_Sub::InitBackward(Environment &env)
{
	ConnectorList::iterator ppConnectorDst = _connectorsDst.begin();
	Array *pArrayLeftPrev = (*ppConnectorDst)->GetArrayBwd()->Reference();
	Array *pArrayRightPrev = Array::ApplyUnaryFunc(
		env, Array::unaryFuncPack_Neg, nullptr,
		(*ppConnectorDst)->GetArrayBwd());
	_connectorSrcLeft.AddArrayBwd(pArrayLeftPrev);
	_connectorSrcRight.AddArrayBwd(pArrayRightPrev);
	ppConnectorDst++;
	for ( ; ppConnectorDst != _connectorsDst.end(); ppConnectorDst++) {
		
	}
}

bool ArrayChainBinary_Sub::EvalBackward(Environment &env)
{
	Connector *pConnectorDst = _connectorsDst.front();
	Array::Delete(
		Array::ApplyUnaryFunc(
			env, Array::unaryFuncPack_Neg, _connectorSrcRight.GetArrayBwd(),
			pConnectorDst->GetArrayBwd()));
	return env.IsNoSignalled();
}

//-----------------------------------------------------------------------------
// ArrayChainBinary_Mul
//-----------------------------------------------------------------------------
bool ArrayChainBinary_Mul::InitBackward(Environment &env)
{
	ConnectorList::iterator ppConnectorDst = _connectorsDst.begin();
	Array *pArrayLeftPrev = Array::ApplyBinaryFunc(
		env, Array::binaryFuncPack_Mul, nullptr,
		_connectorSrcRight.GetArrayFwd(),
		(*ppConnectorDst)->GetArrayBwd());
	Array *pArrayRightPrev = Array::ApplyBinaryFunc(
		env, Array::binaryFuncPack_Mul, nullptr,
		_connectorSrcLeft.GetArrayFwd(),
		(*ppConnectorDst)->GetArrayBwd());
	_connectorSrcLeft.AddArrayBwd(pArrayLeftPrev);
	_connectorSrcRight.AddArrayBwd(pArrayRightPrev);
	ppConnectorDst++;
	for ( ; ppConnectorDst != _connectorsDst.end(); ppConnectorDst++) {
		
	}
	return env.IsNoSignalled();
}

bool ArrayChainBinary_Mul::EvalBackward(Environment &env)
{
	Connector *pConnectorDst = _connectorsDst.front();
	Array::Delete(
		Array::ApplyBinaryFunc(
			env, Array::binaryFuncPack_Mul, _connectorSrcLeft.GetArrayBwd(),
			_connectorSrcRight.GetArrayFwd(),
			pConnectorDst->GetArrayBwd()));
	Array::Delete(
		Array::ApplyBinaryFunc(
			env, Array::binaryFuncPack_Mul, _connectorSrcRight.GetArrayBwd(),
			_connectorSrcLeft.GetArrayFwd(),
			pConnectorDst->GetArrayBwd()));
	return env.IsNoSignalled();
}

//-----------------------------------------------------------------------------
// ArrayChainBinary_Div
//-----------------------------------------------------------------------------
bool ArrayChainBinary_Div::InitBackward(Environment &env)
{
	return false;
}

bool ArrayChainBinary_Div::EvalBackward(Environment &env)
{
	return false;
}

//-----------------------------------------------------------------------------
// ArrayChainBinary_Pow
//-----------------------------------------------------------------------------
bool ArrayChainBinary_Pow::InitBackward(Environment &env)
{
	return false;
}

bool ArrayChainBinary_Pow::EvalBackward(Environment &env)
{
	return false;
}

//-----------------------------------------------------------------------------
// ArrayChainBinary_DotProd
//-----------------------------------------------------------------------------
bool ArrayChainBinary_DotProd::InitBackward(Environment &env)
{
	return false;
}

bool ArrayChainBinary_DotProd::EvalBackward(Environment &env)
{
	return false;
}

//-----------------------------------------------------------------------------
// ArrayChainList
//-----------------------------------------------------------------------------
bool ArrayChainList::InitForward(Environment &env)
{
	foreach_reverse (ArrayChainList, ppArrayChain, *this) {
		if (!(*ppArrayChain)->InitForward(env)) return false;
	}
	return true;
}

bool ArrayChainList::InitBackward(Environment &env)
{
	foreach (ArrayChainList, ppArrayChain, *this) {
		if (!(*ppArrayChain)->InitBackward(env)) return false;
	}
	return true;
}

bool ArrayChainList::EvalForward(Environment &env)
{
	foreach_reverse (ArrayChainList, ppArrayChain, *this) {
		if (!(*ppArrayChain)->EvalForward(env)) return false;
	}
	return true;
}

bool ArrayChainList::EvalBackward(Environment &env)
{
	foreach (ArrayChainList, ppArrayChain, *this) {
		if (!(*ppArrayChain)->EvalBackward(env)) return false;
	}
	return true;
}

//-----------------------------------------------------------------------------
// ArrayChainOwner
//-----------------------------------------------------------------------------
ArrayChainOwner::~ArrayChainOwner()
{
	Clear();
}

void ArrayChainOwner::Clear()
{
	foreach (ArrayChainOwner, ppArrayChain, *this) {
		delete *ppArrayChain;
	}
	clear();
}

bool ArrayChainOwner::CreateFromExpr(Environment &env, const Expr *pExpr)
{
	std::unique_ptr<ArrayChainTail> pArrayChain(new ArrayChainTail());
	ArrayChain::Connector *pConnectorSrc = pArrayChain->GetConnectorSrc();
	push_back(pArrayChain.release());
	if (!CreateFromExprSub(env, pExpr, pConnectorSrc)) return false;
	return true;
}

bool ArrayChainOwner::CreateFromExprSub(Environment &env, const Expr *pExpr, ArrayChain::Connector *pConnector)
{
	if (pExpr->IsType(EXPRTYPE_UnaryOp)) {
		const Expr_UnaryOp *pExprEx = dynamic_cast<const Expr_UnaryOp *>(pExpr);
		const Operator *pOperator = pExprEx->GetOperator();
		std::unique_ptr<ArrayChainUnary> pArrayChain;
		if (pOperator->IsOpType(OPTYPE_Pos)) {
			pArrayChain.reset(new ArrayChainUnary_Pos(pConnector));
		} else if (pOperator->IsOpType(OPTYPE_Neg)) {
			pArrayChain.reset(new ArrayChainUnary_Neg(pConnector));
		} else {
			env.SetError(ERR_ValueError, "unsupported operator: %s", pOperator->GetName());
			return false;
		}
		ArrayChain::Connector *pConnectorSrc = pArrayChain->GetConnectorSrc();
		push_back(pArrayChain.release());
		if (!CreateFromExprSub(env, pExprEx->GetChild(), pConnectorSrc)) {
			return false;
		}
	} else if (pExpr->IsType(EXPRTYPE_BinaryOp)) {
		const Expr_BinaryOp *pExprEx = dynamic_cast<const Expr_BinaryOp *>(pExpr);
		const Operator *pOperator = pExprEx->GetOperator();
		std::unique_ptr<ArrayChainBinary> pArrayChain;
		if (pOperator->IsOpType(OPTYPE_Add)) {
			pArrayChain.reset(new ArrayChainBinary_Add(pConnector));
		} else if (pOperator->IsOpType(OPTYPE_Sub)) {
			pArrayChain.reset(new ArrayChainBinary_Sub(pConnector));
		} else if (pOperator->IsOpType(OPTYPE_Mul)) {
			pArrayChain.reset(new ArrayChainBinary_Mul(pConnector));
		} else if (pOperator->IsOpType(OPTYPE_Div)) {
			pArrayChain.reset(new ArrayChainBinary_Div(pConnector));
		} else if (pOperator->IsOpType(OPTYPE_Pow)) {
			pArrayChain.reset(new ArrayChainBinary_Pow(pConnector));
		} else if (pOperator->IsOpType(OPTYPE_DotProd)) {
			pArrayChain.reset(new ArrayChainBinary_DotProd(pConnector));
		} else {
			env.SetError(ERR_ValueError, "unsupported operator: %s", pOperator->GetName());
			return false;
		}
		ArrayChain::Connector *pConnectorSrcLeft = pArrayChain->GetConnectorSrcLeft();
		ArrayChain::Connector *pConnectorSrcRight = pArrayChain->GetConnectorSrcRight();
		push_back(pArrayChain.release());
		if (!CreateFromExprSub(env, pExprEx->GetLeft(), pConnectorSrcLeft) ||
			!CreateFromExprSub(env, pExprEx->GetRight(), pConnectorSrcRight)) {
			return false;
		}
	} else if (pExpr->IsType(EXPRTYPE_Caller)) {
		const Expr_Caller *pExprEx = dynamic_cast<const Expr_Caller *>(pExpr);

	} else {
		std::unique_ptr<ArrayChainHead> pArrayChain(
			new ArrayChainHead(pConnector, Expr::Reference(pExpr)));
		push_back(pArrayChain.release());
	}
	return true;
}

}
