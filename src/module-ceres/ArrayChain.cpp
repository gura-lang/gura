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
		AutoPtr<Array> _pArrayFwd_In;
		AutoPtr<Array> _pArrayBwd_Out;
	public:
		inline Connector(ArrayChain *pArrayChainDst) :
			_pArrayChainSrc(nullptr), _pArrayChainDst(pArrayChainDst) {}
		inline ArrayChain *GetArrayChainSrc() { return _pArrayChainSrc; }
		inline ArrayChain *GetArrayChainDst() { return _pArrayChainDst; }
		inline void SetArrayChainSrc(ArrayChain *pArrayChainSrc) {
			_pArrayChainSrc = pArrayChainSrc;
		}
	};
	class ConnectorList : public std::vector<Connector *> {
	public:
		inline ConnectorList() {}
	};
private:
	ConnectorList _connectorsDst;
	AutoPtr<Array> _pArrayFwd_Out;
	AutoPtr<ArrayOwner> _pArraysBwd_In;
public:
	inline ArrayChain() : _pArraysBwd_In(new ArrayOwner()) {}
	inline ArrayChain(Connector *pConnectorDst) : _pArraysBwd_In(new ArrayOwner()) {
		pConnectorDst->SetArrayChainSrc(this);
		_connectorsDst.push_back(pConnectorDst);
	}
	inline void AddConnectorDst(Connector *pConnectorDst) { _connectorsDst.push_back(pConnectorDst); }
	virtual void ActivateConnection() = 0;
};

//-----------------------------------------------------------------------------
// ArrayChainHead
//-----------------------------------------------------------------------------
class ArrayChainHead : public ArrayChain {
public:
	inline ArrayChainHead(Connector *pConnectorDst) : ArrayChain(pConnectorDst) {}
	virtual void ActivateConnection();
};

//-----------------------------------------------------------------------------
// ArrayChainTail
//-----------------------------------------------------------------------------
class ArrayChainTail : public ArrayChain {
private:
	Connector _connectorSrc;
public:
	inline ArrayChainTail() : ArrayChain(), _connectorSrc(this) {}
	virtual void ActivateConnection();
};

//-----------------------------------------------------------------------------
// ArrayChainUnary
//-----------------------------------------------------------------------------
class ArrayChainUnary : public ArrayChain {
private:
	Connector _connectorSrc;
public:
	inline ArrayChainUnary(Connector *pConnectorDst) : ArrayChain(pConnectorDst), _connectorSrc(this) {}
	virtual void ActivateConnection();
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
	virtual void ActivateConnection();
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
// ArrayChainHead
//-----------------------------------------------------------------------------
void ArrayChainHead::ActivateConnection()
{
}

//-----------------------------------------------------------------------------
// ArrayChainTail
//-----------------------------------------------------------------------------
void ArrayChainTail::ActivateConnection()
{
}

//-----------------------------------------------------------------------------
// ArrayChainUnary
//-----------------------------------------------------------------------------
void ArrayChainUnary::ActivateConnection()
{
}

//-----------------------------------------------------------------------------
// ArrayChainBinary
//-----------------------------------------------------------------------------
void ArrayChainBinary::ActivateConnection()
{
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
