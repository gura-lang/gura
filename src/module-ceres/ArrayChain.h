#ifndef __GURA_ARRAYCHAIN_H__
#define __GURA_ARRAYCHAIN_H__
#include <gura.h>

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
		AutoPtr<Array> _pArrayBwd;
	public:
		inline Connector(ArrayChain *pArrayChainDst) :
			_pArrayChainSrc(nullptr), _pArrayChainDst(pArrayChainDst) {}
		inline ArrayChain *GetArrayChainSrc() { return _pArrayChainSrc; }
		inline ArrayChain *GetArrayChainDst() { return _pArrayChainDst; }
		inline void SetArrayChainSrc(ArrayChain *pArrayChainSrc) {
			_pArrayChainSrc = pArrayChainSrc;
		}
		inline Array *GetArrayFwd() { return _pArrayChainSrc->GetArrayFwd(); }
		inline Array *GetArrayBwd() { return _pArrayBwd.get(); }
	};
	class ConnectorList : public std::vector<Connector *> {
	public:
		inline ConnectorList() {}
	};
protected:
	ConnectorList _connectorsDst;
	AutoPtr<Array> _pArrayFwd;
public:
	inline ArrayChain() {}
	inline ArrayChain(Connector *pConnectorDst) {
		pConnectorDst->SetArrayChainSrc(this);
		_connectorsDst.push_back(pConnectorDst);
	}
	virtual ~ArrayChain();
	inline void AddConnectorDst(Connector *pConnectorDst) { _connectorsDst.push_back(pConnectorDst); }
	inline Array *GetArrayFwd() { return _pArrayFwd.get(); }
	virtual bool InitForward(Environment &env) = 0;
	virtual bool InitBackward(Environment &env) = 0;
	virtual bool EvalForward(Environment &env) = 0;
	virtual bool EvalBackward(Environment &env) = 0;
};

//-----------------------------------------------------------------------------
// ArrayChainOwner
//-----------------------------------------------------------------------------
class ArrayChainOwner : public ArrayChainList {
public:
	~ArrayChainOwner();
	void Clear();
	bool CreateFromExpr(Environment &env, const Expr *pExpr);
private:
	bool CreateFromExprSub(Environment &env, const Expr *pExpr, ArrayChain::Connector *pConnector);
};

}

#endif

