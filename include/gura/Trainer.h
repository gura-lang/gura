#ifndef __GURA_TRAINER_H__
#define __GURA_TRAINER_H__
#include <gura.h>

namespace Gura {

class TrainerNode;

//-----------------------------------------------------------------------------
// TrainerNode
//-----------------------------------------------------------------------------
class TrainerNode {
public:
	class Connector {
	private:
		TrainerNode *_pTrainerNodeSrc;
		TrainerNode *_pTrainerNodeDst;
		AutoPtr<Array> _pArrayBwd;
	public:
		inline Connector(TrainerNode *pTrainerNodeDst) :
			_pTrainerNodeSrc(nullptr), _pTrainerNodeDst(pTrainerNodeDst) {}
		inline TrainerNode *GetTrainerNodeSrc() { return _pTrainerNodeSrc; }
		inline TrainerNode *GetTrainerNodeDst() { return _pTrainerNodeDst; }
		inline void SetTrainerNodeSrc(TrainerNode *pTrainerNodeSrc) {
			_pTrainerNodeSrc = pTrainerNodeSrc;
		}
		inline void SetArrayBwd(Array *pArrayBwd) { _pArrayBwd.reset(pArrayBwd); }
		inline Array *GetArrayFwd() { return _pTrainerNodeSrc->GetArrayFwd(); }
		inline Array *GetArrayBwd() { return _pArrayBwd.get(); }
		inline const Array *GetArrayFwd() const { return _pTrainerNodeSrc->GetArrayFwd(); }
		inline const Array *GetArrayBwd() const { return _pArrayBwd.get(); }
		inline bool IsSourceVulnerable() const { return _pTrainerNodeSrc->IsVulnerable(); }
	};
	class ConnectorList : public std::vector<Connector *> {
	public:
		inline ConnectorList() {}
	};
protected:
	int _cntRef;
	ConnectorList _connectorsDst;
	AutoPtr<Array> _pArrayFwd;
public:
	Gura_DeclareReferenceAccessor(TrainerNode);
public:
	inline TrainerNode() : _cntRef(1) {}
	TrainerNode(Connector *pConnectorDst);
protected:
	virtual ~TrainerNode();
public:
	inline void AddConnectorDst(Connector *pConnectorDst) { _connectorsDst.push_back(pConnectorDst); }
	inline Array *GetArrayFwd() { return _pArrayFwd.get(); }
	virtual bool IsVulnerable() const;
	virtual bool EvalForward(Environment &env) = 0;
	virtual bool EvalBackward(Environment &env) = 0;
	virtual void Print(int indentLevel) = 0;
};

//-----------------------------------------------------------------------------
// TrainerNodeHead
//-----------------------------------------------------------------------------
class TrainerNodeHead : public TrainerNode {
protected:
	AutoPtr<Expr> _pExpr;
	AutoPtr<Array> _pArrayBwdAdj;
	bool _sourceNodeFlag;
public:
	inline TrainerNodeHead(Connector *pConnectorDst, Expr *pExpr, bool sourceNodeFlag) :
			TrainerNode(pConnectorDst), _pExpr(pExpr), _sourceNodeFlag(sourceNodeFlag) {}
	inline bool IsSourceNode() const { return _sourceNodeFlag; }
	virtual bool IsVulnerable() const;
	virtual bool EvalForward(Environment &env);
	virtual bool EvalBackward(Environment &env);
	virtual void Print(int indentLevel);
};

//-----------------------------------------------------------------------------
// TrainerNodeBottom
//-----------------------------------------------------------------------------
class TrainerNodeBottom : public TrainerNode {
private:
	Connector _connectorSrc;
	AutoPtr<Array> _pArraySoftmax;
	AutoPtr<Array> _pArrayCorrect;
public:
	inline TrainerNodeBottom() : TrainerNode(), _connectorSrc(this) {}
	inline Connector *GetConnectorSrc() { return &_connectorSrc; }
	inline const Array *GetArraySoftmax() const { return _pArraySoftmax.get(); }
	virtual bool EvalForward(Environment &env);
	virtual bool EvalBackward(Environment &env);
	bool EvalBackwardTop(Environment &env, const Array *pArrayCorrect);
	virtual void Print(int indentLevel);
};

//-----------------------------------------------------------------------------
// TrainerNodeUnary
//-----------------------------------------------------------------------------
class TrainerNodeUnary : public TrainerNode {
protected:
	const Array::UnaryFuncPack &_unaryFuncPack;
	Connector _connectorSrc;
public:
	inline TrainerNodeUnary(const Array::UnaryFuncPack &unaryFuncPack, Connector *pConnectorDst) :
		TrainerNode(pConnectorDst), _unaryFuncPack(unaryFuncPack), _connectorSrc(this) {}
	inline Connector *GetConnectorSrc() { return &_connectorSrc; }
	virtual bool EvalForward(Environment &env);
	virtual void Print(int indentLevel);
};

//-----------------------------------------------------------------------------
// TrainerNodeUnary_Pos
//-----------------------------------------------------------------------------
class TrainerNodeUnary_Pos : public TrainerNodeUnary {
public:
	inline TrainerNodeUnary_Pos(Connector *pConnectorDst) :
		TrainerNodeUnary(Array::unaryFuncPack_Pos, pConnectorDst) {}
	virtual bool EvalBackward(Environment &env);
};

//-----------------------------------------------------------------------------
// TrainerNodeUnary_Neg
//-----------------------------------------------------------------------------
class TrainerNodeUnary_Neg : public TrainerNodeUnary {
public:
	inline TrainerNodeUnary_Neg(Connector *pConnectorDst) :
		TrainerNodeUnary(Array::unaryFuncPack_Pos, pConnectorDst) {}
	virtual bool EvalBackward(Environment &env);
};

//-----------------------------------------------------------------------------
// TrainerNodeUnary_Math_relu
//-----------------------------------------------------------------------------
class TrainerNodeUnary_Math_relu : public TrainerNodeUnary {
public:
	inline TrainerNodeUnary_Math_relu(Connector *pConnectorDst) :
		TrainerNodeUnary(Array::unaryFuncPack_Math_relu, pConnectorDst) {}
	virtual bool EvalBackward(Environment &env);
};

//-----------------------------------------------------------------------------
// TrainerNodeUnary_Math_sigmoid
//-----------------------------------------------------------------------------
class TrainerNodeUnary_Math_sigmoid : public TrainerNodeUnary {
public:
	inline TrainerNodeUnary_Math_sigmoid(Connector *pConnectorDst) :
		TrainerNodeUnary(Array::unaryFuncPack_Math_sigmoid, pConnectorDst) {}
	virtual bool EvalBackward(Environment &env);
};

//-----------------------------------------------------------------------------
// TrainerNodeBinary
//-----------------------------------------------------------------------------
class TrainerNodeBinary : public TrainerNode {
protected:
	const Array::BinaryFuncPack &_binaryFuncPack;
	Connector _connectorSrcLeft;
	Connector _connectorSrcRight;
public:
	inline TrainerNodeBinary(const Array::BinaryFuncPack &binaryFuncPack, Connector *pConnectorDst) :
		TrainerNode(pConnectorDst), _binaryFuncPack(binaryFuncPack),
		_connectorSrcLeft(this), _connectorSrcRight(this) {}
	inline Connector *GetConnectorSrcLeft() { return &_connectorSrcLeft; }
	inline Connector *GetConnectorSrcRight() { return &_connectorSrcRight; }
	virtual bool EvalForward(Environment &env);
	virtual void Print(int indentLevel);
};

//-----------------------------------------------------------------------------
// TrainerNodeBinary_Add
//-----------------------------------------------------------------------------
class TrainerNodeBinary_Add : public TrainerNodeBinary {
public:
	inline TrainerNodeBinary_Add(Connector *pConnectorDst) :
		TrainerNodeBinary(Array::binaryFuncPack_Add, pConnectorDst) {}
	virtual bool EvalBackward(Environment &env);
};

//-----------------------------------------------------------------------------
// TrainerNodeBinary_Sub
//-----------------------------------------------------------------------------
class TrainerNodeBinary_Sub : public TrainerNodeBinary {
public:
	inline TrainerNodeBinary_Sub(Connector *pConnectorDst) :
		TrainerNodeBinary(Array::binaryFuncPack_Sub, pConnectorDst) {}
	virtual bool EvalBackward(Environment &env);
};

//-----------------------------------------------------------------------------
// TrainerNodeBinary_Mul
//-----------------------------------------------------------------------------
class TrainerNodeBinary_Mul : public TrainerNodeBinary {
public:
	inline TrainerNodeBinary_Mul(Connector *pConnectorDst) :
		TrainerNodeBinary(Array::binaryFuncPack_Mul, pConnectorDst) {}
	virtual bool EvalBackward(Environment &env);
};

//-----------------------------------------------------------------------------
// TrainerNodeBinary_Div
//-----------------------------------------------------------------------------
class TrainerNodeBinary_Div : public TrainerNodeBinary {
public:
	inline TrainerNodeBinary_Div(Connector *pConnectorDst) :
		TrainerNodeBinary(Array::binaryFuncPack_Div, pConnectorDst) {}
	virtual bool EvalBackward(Environment &env);
};

//-----------------------------------------------------------------------------
// TrainerNodeBinary_Pow
//-----------------------------------------------------------------------------
class TrainerNodeBinary_Pow : public TrainerNodeBinary {
public:
	inline TrainerNodeBinary_Pow(Connector *pConnectorDst) :
		TrainerNodeBinary(Array::binaryFuncPack_Pow, pConnectorDst) {}
	virtual bool EvalBackward(Environment &env);
};

//-----------------------------------------------------------------------------
// TrainerNodeBinary_Dot
//-----------------------------------------------------------------------------
class TrainerNodeBinary_Dot : public TrainerNodeBinary {
private:
	AutoPtr<Array> _pArrayFwdLeftTrans;
	AutoPtr<Array> _pArrayFwdRightTrans;
public:
	inline TrainerNodeBinary_Dot(Connector *pConnectorDst) :
		TrainerNodeBinary(Array::binaryFuncPack_Dot, pConnectorDst) {}
	virtual bool EvalBackward(Environment &env);
};

#if 0
//-----------------------------------------------------------------------------
// TrainerNodeBinary_Filter
//-----------------------------------------------------------------------------
class TrainerNodeBinary_Filter : public TrainerNodeBinary {
public:
	inline TrainerNodeBinary_Filter(Connector *pConnectorDst) :
		TrainerNodeBinary(Array::binaryFuncPack_Filter, pConnectorDst) {}
	virtual bool EvalBackward(Environment &env);
};
#endif

//-----------------------------------------------------------------------------
// TrainerNodeList
//-----------------------------------------------------------------------------
class TrainerNodeList : public std::vector<TrainerNode *> {
public:
	inline TrainerNodeList() {}
	bool EvalForward(Environment &env);
	bool EvalBackward(Environment &env);
};

//-----------------------------------------------------------------------------
// TrainerNodeOwner
//-----------------------------------------------------------------------------
class TrainerNodeOwner : public TrainerNodeList {
public:
	~TrainerNodeOwner();
	void Clear();
	bool CreateFromExpr(Environment &env, const Expr *pExpr,
						TrainerNode::Connector *pConnector, const SymbolSet &symbolsSource);
};

//-----------------------------------------------------------------------------
// Trainer
//-----------------------------------------------------------------------------
class Trainer {
private:
	int _cntRef;
	AutoPtr<TrainerNodeBottom> _pTrainerNodeBottom;
	TrainerNodeOwner _trainerNodeOwner;
public:
	Gura_DeclareReferenceAccessor(Trainer);
public:
	Trainer();
protected:
	virtual ~Trainer();
public:
	bool CreateFromExpr(Environment &env, const Expr *pExpr, const SymbolSet &symbolsSource);
	bool Eval(Environment &env);
	bool Train(Environment &env, const Array *pArrayCorrect);
	const Array *GetResult() const;
	const Array *GetResultSoftmax() const;
	inline const TrainerNodeOwner &GetTrainerNodeOwner() const { return _trainerNodeOwner; }
	void Print() const;
};

}

#endif

