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
};

//-----------------------------------------------------------------------------
// ArrayChainHead
//-----------------------------------------------------------------------------
class ArrayChainHead : public ArrayChain {
private:
	AutoPtr<Expr> _pExpr;
public:
	inline ArrayChainHead(Connector *pConnectorDst, Expr *pExpr) : ArrayChain(pConnectorDst), _pExpr(pExpr) {}
	virtual bool ActivateForward(Environment &env);
};

//-----------------------------------------------------------------------------
// ArrayChainTail
//-----------------------------------------------------------------------------
class ArrayChainTail : public ArrayChain {
private:
	Connector _connectorSrc;
public:
	inline ArrayChainTail() : ArrayChain(), _connectorSrc(this) {}
};

//-----------------------------------------------------------------------------
// ArrayChainUnary
//-----------------------------------------------------------------------------
class ArrayChainUnary : public ArrayChain {
private:
	Connector _connectorSrc;
public:
	inline ArrayChainUnary(Connector *pConnectorDst) : ArrayChain(pConnectorDst), _connectorSrc(this) {}
};

//-----------------------------------------------------------------------------
// ArrayChainBinary
//-----------------------------------------------------------------------------
class ArrayChainBinary : public ArrayChain {
private:
	Connector _connectorSrcLeft;
	Connector _connectorSrcRight;
public:
	inline ArrayChainBinary(Connector *pConnectorDst) :
		ArrayChain(pConnectorDst), _connectorSrcLeft(this), _connectorSrcRight(this) {}
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
bool ArrayChainHead::ActivateForward(Environment &env)
{
	Value value = _pExpr->Exec(env);
	if (!value.Is_array()) {
		env.SetError(ERR_ValueError, "variable must be an array");
		return false;
	}
	_connectorsDst.SetArrayFwd(Object_array::GetObject(value)->GetArray()->Reference());
	return true;
}

//-----------------------------------------------------------------------------
// ArrayChainTail
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// ArrayChainUnary
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// ArrayChainBinary
//-----------------------------------------------------------------------------

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
