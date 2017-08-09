#include "ArrayChain.h"

namespace Gura {

class ArrayChain;

//-----------------------------------------------------------------------------
// ArrayChainList
//-----------------------------------------------------------------------------
class ArrayChainList : public std::vector<ArrayChain *> {
public:
	inline ArrayChainList() {}
};

//-----------------------------------------------------------------------------
// ArrayChain
//-----------------------------------------------------------------------------
class ArrayChain {
public:
	class Connector {
	private:
		ArrayChain *_pArrayChainSrc;
		ArrayChain *_pArrayChainDst;
		AutoPtr<Array> _pArrayFwd;
		AutoPtr<Array> _pArrayBwd;
	public:
		inline Connector(ArrayChain *pArrayChainDst) :
			_pArrayChainSrc(nullptr), _pArrayChainDst(pArrayChainDst) {}
		inline ArrayChain *GetArrayChainSrc() { return _pArrayChainSrc; }
		inline ArrayChain *GetArrayChainDst() { return _pArrayChainDst; }
		inline void SetArrayChainSrc(ArrayChain *pArrayChainSrc) {
			_pArrayChainSrc = pArrayChainSrc;
		}
		inline void SetArrayFwd(Array *pArrayFwd) { _pArrayFwd.reset(pArrayFwd); }
		inline void SetArrayBwd(Array *pArrayBwd) { _pArrayBwd.reset(pArrayBwd); }
		inline Array *GetArrayFwd() { return _pArrayFwd.get(); }
		inline Array *GetArrayBwd() { return _pArrayBwd.get(); }
	};
	class ConnectorList : public std::vector<Connector *> {
	public:
		inline ConnectorList() {}
		inline void SetArrayFwd(Array *pArrayFwd);
		inline void SetArrayBwd(Array *pArrayBwd);
	};
protected:
	ConnectorList _connectorsDst;
public:
	inline ArrayChain() {}
	inline ArrayChain(Connector *pConnectorDst) {
		pConnectorDst->SetArrayChainSrc(this);
		_connectorsDst.push_back(pConnectorDst);
	}
	inline void AddConnectorDst(Connector *pConnectorDst) { _connectorsDst.push_back(pConnectorDst); }
	virtual bool InitForward(Environment &env) = 0;
	virtual bool InitBackward(Environment &env) = 0;
	virtual bool EvalForward(Environment &env) = 0;
	virtual bool EvalBackward(Environment &env) = 0;
	static ArrayChain *CreateFromExpr(const Expr *pExpr);
};

//-----------------------------------------------------------------------------
// ArrayChainHead
//-----------------------------------------------------------------------------
class ArrayChainHead : public ArrayChain {
private:
	AutoPtr<Expr> _pExpr;
public:
	inline ArrayChainHead(Connector *pConnectorDst, Expr *pExpr) : ArrayChain(pConnectorDst), _pExpr(pExpr) {}
	virtual bool InitForward(Environment &env);
	virtual bool InitBackward(Environment &env);
	virtual bool EvalForward(Environment &env);
	virtual bool EvalBackward(Environment &env);
};

//-----------------------------------------------------------------------------
// ArrayChainTail
//-----------------------------------------------------------------------------
class ArrayChainTail : public ArrayChain {
private:
	Connector _connectorSrc;
public:
	inline ArrayChainTail() : ArrayChain(), _connectorSrc(this) {}
	virtual bool InitForward(Environment &env);
	virtual bool InitBackward(Environment &env);
	virtual bool EvalForward(Environment &env);
	virtual bool EvalBackward(Environment &env);
};

//-----------------------------------------------------------------------------
// ArrayChainUnary
//-----------------------------------------------------------------------------
class ArrayChainUnary : public ArrayChain {
private:
	const Array::UnaryFuncPack &_unaryFuncPack;
	Connector _connectorSrc;
public:
	inline ArrayChainUnary(const Array::UnaryFuncPack &unaryFuncPack, Connector *pConnectorDst) :
		_unaryFuncPack(unaryFuncPack), ArrayChain(pConnectorDst), _connectorSrc(this) {}
	virtual bool InitForward(Environment &env);
	virtual bool InitBackward(Environment &env);
	virtual bool EvalForward(Environment &env);
	virtual bool EvalBackward(Environment &env);
};

//-----------------------------------------------------------------------------
// ArrayChainBinary
//-----------------------------------------------------------------------------
class ArrayChainBinary : public ArrayChain {
private:
	const Array::BinaryFuncPack &_binaryFuncPack;
	Connector _connectorSrcLeft;
	Connector _connectorSrcRight;
public:
	inline ArrayChainBinary(const Array::BinaryFuncPack &binaryFuncPack, Connector *pConnectorDst) :
		_binaryFuncPack(binaryFuncPack), ArrayChain(pConnectorDst),
		_connectorSrcLeft(this), _connectorSrcRight(this) {}
	virtual bool InitForward(Environment &env);
	virtual bool InitBackward(Environment &env);
	virtual bool EvalForward(Environment &env);
	virtual bool EvalBackward(Environment &env);
};

//-----------------------------------------------------------------------------
// ArrayChainOwner
//-----------------------------------------------------------------------------
class ArrayChainOwner : public ArrayChainList {
public:
	~ArrayChainOwner();
	void Clear();
};

//-----------------------------------------------------------------------------
// ArrayChain
//-----------------------------------------------------------------------------
ArrayChain *ArrayChain::CreateFromExpr(const Expr *pExpr)
{
	
	return nullptr;
}

//-----------------------------------------------------------------------------
// ArrayChain::Connector
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// ArrayChain::ConnectorList
//-----------------------------------------------------------------------------
void ArrayChain::ConnectorList::SetArrayFwd(Array *pArrayFwd)
{
	foreach (ConnectorList, ppConnector, *this) {
		(*ppConnector)->SetArrayFwd(pArrayFwd->Reference());
	}
	Array::Delete(pArrayFwd);
}

void ArrayChain::ConnectorList::SetArrayBwd(Array *pArrayBwd)
{
	foreach (ConnectorList, ppConnector, *this) {
		(*ppConnector)->SetArrayBwd(pArrayBwd->Reference());
	}
	Array::Delete(pArrayBwd);
}

//-----------------------------------------------------------------------------
// ArrayChainHead
//-----------------------------------------------------------------------------
bool ArrayChainHead::InitForward(Environment &env)
{
	Value value = _pExpr->Exec(env);
	if (!value.Is_array()) {
		env.SetError(ERR_ValueError, "variable must be an array");
		return false;
	}
	_connectorsDst.SetArrayFwd(Object_array::GetObject(value)->GetArray()->Reference());
	return true;
}

bool ArrayChainHead::InitBackward(Environment &env)
{
	return false;
}

bool ArrayChainHead::EvalForward(Environment &env)
{
	return false;
}

bool ArrayChainHead::EvalBackward(Environment &env)
{
	return false;
}

//-----------------------------------------------------------------------------
// ArrayChainTail
//-----------------------------------------------------------------------------
bool ArrayChainTail::InitForward(Environment &env)
{
	// nothing to do
	return true;
}

bool ArrayChainTail::InitBackward(Environment &env)
{
	return false;
}

bool ArrayChainTail::EvalForward(Environment &env)
{
	return false;
}

bool ArrayChainTail::EvalBackward(Environment &env)
{
	return false;
}

//-----------------------------------------------------------------------------
// ArrayChainUnary
//-----------------------------------------------------------------------------
bool ArrayChainUnary::InitForward(Environment &env)
{
	return false;
}

bool ArrayChainUnary::InitBackward(Environment &env)
{
	return false;
}

bool ArrayChainUnary::EvalForward(Environment &env)
{
	return false;
}

bool ArrayChainUnary::EvalBackward(Environment &env)
{
	return false;
}

//-----------------------------------------------------------------------------
// ArrayChainBinary
//-----------------------------------------------------------------------------
bool ArrayChainBinary::InitForward(Environment &env)
{
	return false;
}

bool ArrayChainBinary::InitBackward(Environment &env)
{
	return false;
}

bool ArrayChainBinary::EvalForward(Environment &env)
{
	return false;
}

bool ArrayChainBinary::EvalBackward(Environment &env)
{
	return false;
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

}
