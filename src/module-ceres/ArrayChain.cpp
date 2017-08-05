#include "ArrayChain.h"

namespace Gura {

class ArrayChain;

typedef std::vector<ArrayChain *> ArrayChainList;

class ArrayChain {
private:
	ArrayChainList _arrayChainsDst;
	AutoPtr<Array> _pArrayOut_Fwd;
	ArrayOwner _arraysIn_Bwd;
public:
	inline void AddArrayChainDst(ArrayChain *pArrayChain) { _arrayChainsDst.push_back(pArrayChain); }
};

class ArrayChainHead : public ArrayChain {
};

class ArrayChainTail : public ArrayChain {
private:
	ArrayChain *_pArrayChainSrc;
	AutoPtr<Array> _pArrayIn_Fwd;
	AutoPtr<Array> _pArrayOut_Bwd;
public:
	void Connect(ArrayChain *pArrayChain);
};

class ArrayChainUnary : public ArrayChain {
private:
	ArrayChain *_pArrayChainSrc;
	AutoPtr<Array> _pArrayIn_Fwd;
	AutoPtr<Array> _pArrayOut_Bwd;
public:
	void Connect(ArrayChain *pArrayChain);
};

class ArrayChainBinary : public ArrayChain {
private:
	ArrayChain *_pArrayChainLeftSrc;
	ArrayChain *_pArrayChainRightSrc;
	AutoPtr<Array> _pArrayLeftIn_Fwd;
	AutoPtr<Array> _pArrayLeftOut_Bwd;
	AutoPtr<Array> _pArrayRightIn_Fwd;
	AutoPtr<Array> _pArrayRightOut_Bwd;
public:
	void ConnectLeft(ArrayChain *pArrayChain);
	void ConnectRight(ArrayChain *pArrayChain);
};

//-----------------------------------------------------------------------------
// ArrayChain
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// ArrayChainHead
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// ArrayChainTail
//-----------------------------------------------------------------------------
void ArrayChainTail::Connect(ArrayChain *pArrayChain)
{
	_pArrayChainSrc = pArrayChain;
	pArrayChain->AddArrayChainDst(this);
}

//-----------------------------------------------------------------------------
// ArrayChainUnary
//-----------------------------------------------------------------------------
void ArrayChainUnary::Connect(ArrayChain *pArrayChain)
{
	_pArrayChainSrc = pArrayChain;
	pArrayChain->AddArrayChainDst(this);
}

//-----------------------------------------------------------------------------
// ArrayChainBinary
//-----------------------------------------------------------------------------
void ArrayChainBinary::ConnectLeft(ArrayChain *pArrayChain)
{
	_pArrayChainLeftSrc = pArrayChain;
	pArrayChain->AddArrayChainDst(this);
}

void ArrayChainBinary::ConnectRight(ArrayChain *pArrayChain)
{
	_pArrayChainRightSrc = pArrayChain;
	pArrayChain->AddArrayChainDst(this);
}

}
