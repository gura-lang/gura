#ifndef __GURA_TRAINER_H__
#define __GURA_TRAINER_H__
#include "Class_filter.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Trainer
//-----------------------------------------------------------------------------
class Trainer {
public:
	//-------------------------------------------------------------------------
	// Node
	//-------------------------------------------------------------------------
	class Node {
	public:
		enum Trait {
			TRAIT_Variable,
			TRAIT_Constant,
			TRAIT_Input,
		};
		class Connector {
		private:
			Node *_pNodeSrc;
			Node *_pNodeDst;
			AutoPtr<Array> _pArrayBwd;
		public:
			inline Connector(Node *pNodeDst) :
			_pNodeSrc(nullptr), _pNodeDst(pNodeDst) {}
			inline Node *GetNodeSrc() { return _pNodeSrc; }
			inline Node *GetNodeDst() { return _pNodeDst; }
			inline const Node *GetNodeSrc() const { return _pNodeSrc; }
			inline const Node *GetNodeDst() const { return _pNodeDst; }
			inline void SetNodeSrc(Node *pNodeSrc) {
				_pNodeSrc = pNodeSrc;
			}
			inline void SetArrayBwd(Array *pArrayBwd) { _pArrayBwd.reset(pArrayBwd); }
			inline Array *GetArrayFwd() { return _pNodeSrc->GetArrayFwd(); }
			inline Array *GetArrayBwd() { return _pArrayBwd.get(); }
			inline const Array *GetArrayFwd() const { return _pNodeSrc->GetArrayFwd(); }
			inline const Array *GetArrayBwd() const { return _pArrayBwd.get(); }
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
		Gura_DeclareReferenceAccessor(Node);
	public:
		inline Node() : _cntRef(1) {}
		Node(Connector *pConnectorDst);
	protected:
		virtual ~Node();
	public:
		inline void AddConnectorDst(Connector *pConnectorDst) { _connectorsDst.push_back(pConnectorDst); }
		inline Array *GetArrayFwd() { return _pArrayFwd.get(); }
		virtual bool IsVulnerable() const = 0;
		virtual bool EvalForward(Environment &env) = 0;
		virtual bool EvalBackward(Environment &env) = 0;
		virtual void Print(int indentLevel) = 0;
	};
	//-------------------------------------------------------------------------
	// NodeHead
	//-------------------------------------------------------------------------
	class NodeHead : public Node {
	protected:
		AutoPtr<Expr> _pExpr;
		AutoPtr<Array> _pArrayBwdAdj;
		Trait _trait;
	public:
		inline NodeHead(Connector *pConnectorDst, Expr *pExpr, Trait trait) :
				Node(pConnectorDst), _pExpr(pExpr), _trait(trait) {}
		inline bool IsVariable() const { return _trait == TRAIT_Variable; }
		inline bool IsConstant() const { return _trait == TRAIT_Constant; }
		inline bool IsInput() const { return _trait == TRAIT_Input; }
		virtual bool IsVulnerable() const;
		virtual bool EvalForward(Environment &env);
		virtual bool EvalBackward(Environment &env);
		virtual void Print(int indentLevel);
	};
	//-------------------------------------------------------------------------
	// NodeBottom
	//-------------------------------------------------------------------------
	class NodeBottom : public Node {
	private:
		Connector _connectorSrc;
		AutoPtr<Array> _pArraySoftmax;
		AutoPtr<Array> _pArrayCorrect;
	public:
		inline NodeBottom() : Node(), _connectorSrc(this) {}
		inline Connector *GetConnectorSrc() { return &_connectorSrc; }
		inline const Array *GetArraySoftmax() const { return _pArraySoftmax.get(); }
		virtual bool IsVulnerable() const;
		virtual bool EvalForward(Environment &env);
		virtual bool EvalBackward(Environment &env);
		bool EvalBackwardTop(Environment &env, const Array *pArrayCorrect);
		virtual void Print(int indentLevel);
	};
	//-------------------------------------------------------------------------
	// NodeUnary
	//-------------------------------------------------------------------------
	class NodeUnary : public Node {
	protected:
		const Array::UnaryFuncPack &_unaryFuncPack;
		Connector _connectorSrc;
	public:
		inline NodeUnary(const Array::UnaryFuncPack &unaryFuncPack, Connector *pConnectorDst) :
				Node(pConnectorDst), _unaryFuncPack(unaryFuncPack), _connectorSrc(this) {}
		inline Connector *GetConnectorSrc() { return &_connectorSrc; }
		virtual bool IsVulnerable() const;
		virtual bool EvalForward(Environment &env);
		virtual void Print(int indentLevel);
	};
	//-------------------------------------------------------------------------
	// NodeUnary_Pos
	//-------------------------------------------------------------------------
	class NodeUnary_Pos : public NodeUnary {
	public:
		inline NodeUnary_Pos(Connector *pConnectorDst) :
				NodeUnary(Array::unaryFuncPack_Pos, pConnectorDst) {}
		virtual bool EvalBackward(Environment &env);
	};
	//-------------------------------------------------------------------------
	// NodeUnary_Neg
	//-------------------------------------------------------------------------
	class NodeUnary_Neg : public NodeUnary {
	public:
		inline NodeUnary_Neg(Connector *pConnectorDst) :
				NodeUnary(Array::unaryFuncPack_Pos, pConnectorDst) {}
		virtual bool EvalBackward(Environment &env);
	};
	//-------------------------------------------------------------------------
	// NodeUnary_Math_relu
	//-------------------------------------------------------------------------
	class NodeUnary_Math_relu : public NodeUnary {
	public:
		inline NodeUnary_Math_relu(Connector *pConnectorDst) :
				NodeUnary(Array::unaryFuncPack_Math_relu, pConnectorDst) {}
		virtual bool EvalBackward(Environment &env);
	};
	//-------------------------------------------------------------------------
	// NodeUnary_Math_sigmoid
	//-------------------------------------------------------------------------
	class NodeUnary_Math_sigmoid : public NodeUnary {
	public:
		inline NodeUnary_Math_sigmoid(Connector *pConnectorDst) :
				NodeUnary(Array::unaryFuncPack_Math_sigmoid, pConnectorDst) {}
		virtual bool EvalBackward(Environment &env);
	};
	//-------------------------------------------------------------------------
	// NodeBinary
	//-------------------------------------------------------------------------
	class NodeBinary : public Node {
	protected:
		const Array::BinaryFuncPack &_binaryFuncPack;
		Connector _connectorSrcLeft;
		Connector _connectorSrcRight;
	public:
		inline NodeBinary(const Array::BinaryFuncPack &binaryFuncPack, Connector *pConnectorDst) :
				Node(pConnectorDst), _binaryFuncPack(binaryFuncPack),
				_connectorSrcLeft(this), _connectorSrcRight(this) {}
		inline Connector *GetConnectorSrcLeft() { return &_connectorSrcLeft; }
		inline Connector *GetConnectorSrcRight() { return &_connectorSrcRight; }
		virtual bool IsVulnerable() const;
		virtual bool EvalForward(Environment &env);
		virtual void Print(int indentLevel);
	};
	//-------------------------------------------------------------------------
	// NodeBinary_Add
	//-------------------------------------------------------------------------
	class NodeBinary_Add : public NodeBinary {
	public:
		inline NodeBinary_Add(Connector *pConnectorDst) :
				NodeBinary(Array::binaryFuncPack_Add, pConnectorDst) {}
		virtual bool EvalBackward(Environment &env);
	};
	//-------------------------------------------------------------------------
	// NodeBinary_Sub
	//-------------------------------------------------------------------------
	class NodeBinary_Sub : public NodeBinary {
	public:
		inline NodeBinary_Sub(Connector *pConnectorDst) :
				NodeBinary(Array::binaryFuncPack_Sub, pConnectorDst) {}
		virtual bool EvalBackward(Environment &env);
	};
	//-------------------------------------------------------------------------
	// NodeBinary_Mul
	//-------------------------------------------------------------------------
	class NodeBinary_Mul : public NodeBinary {
	public:
		inline NodeBinary_Mul(Connector *pConnectorDst) :
				NodeBinary(Array::binaryFuncPack_Mul, pConnectorDst) {}
		virtual bool EvalBackward(Environment &env);
	};
	//-------------------------------------------------------------------------
	// NodeBinary_Div
	//-------------------------------------------------------------------------
	class NodeBinary_Div : public NodeBinary {
	public:
		inline NodeBinary_Div(Connector *pConnectorDst) :
				NodeBinary(Array::binaryFuncPack_Div, pConnectorDst) {}
		virtual bool EvalBackward(Environment &env);
	};
	//-------------------------------------------------------------------------
	// NodeBinary_Pow
	//-------------------------------------------------------------------------
	class NodeBinary_Pow : public NodeBinary {
	public:
		inline NodeBinary_Pow(Connector *pConnectorDst) :
				NodeBinary(Array::binaryFuncPack_Pow, pConnectorDst) {}
		virtual bool EvalBackward(Environment &env);
	};
	//-------------------------------------------------------------------------
	// NodeBinary_Dot
	//-------------------------------------------------------------------------
	class NodeBinary_Dot : public NodeBinary {
	private:
		AutoPtr<Array> _pArrayFwdLeftTrans;
		AutoPtr<Array> _pArrayFwdRightTrans;
	public:
		inline NodeBinary_Dot(Connector *pConnectorDst) :
				NodeBinary(Array::binaryFuncPack_Dot, pConnectorDst) {}
		virtual bool EvalBackward(Environment &env);
	};
	//-------------------------------------------------------------------------
	// NodeFilter
	//-------------------------------------------------------------------------
	class NodeFilter : public Node {
	protected:
		AutoPtr<Filter> _pFilter;
		Connector _connectorSrc;
	public:
		inline NodeFilter(Filter *pFilter, Connector *pConnectorDst) :
				Node(pConnectorDst), _pFilter(pFilter), _connectorSrc(this) {}
		inline Connector *GetConnectorSrc() { return &_connectorSrc; }
		virtual bool IsVulnerable() const;
		virtual bool EvalForward(Environment &env);
		virtual bool EvalBackward(Environment &env);
		virtual void Print(int indentLevel);
	};
	//-------------------------------------------------------------------------
	// NodeList
	//-------------------------------------------------------------------------
	class NodeList : public std::vector<Node *> {
	public:
		inline NodeList() {}
		bool EvalForward(Environment &env);
		bool EvalBackward(Environment &env);
	};
	//-------------------------------------------------------------------------
	// NodeOwner
	//-------------------------------------------------------------------------
	class NodeOwner : public NodeList {
	public:
		~NodeOwner();
		void Clear();
		bool CreateFromExpr(Environment &env, const Expr *pExpr,
							Node::Connector *pConnector, const SymbolSet &symbolsInput);
	private:
		bool CreateNodeFilter(Environment &env, const Expr_BinaryOp *pExprEx,
							  Node::Connector *pConnector, const SymbolSet &symbolsInput);
	};
private:
	int _cntRef;
	AutoPtr<NodeBottom> _pNodeBottom;
	NodeOwner _nodeOwner;
	AutoPtr<Expr> _pExprSrc;
public:
	Gura_DeclareReferenceAccessor(Trainer);
public:
	Trainer();
protected:
	virtual ~Trainer();
public:
	bool CreateFromExpr(Environment &env, const Expr *pExprSrc, const SymbolSet &symbolsInput);
	bool Eval(Environment &env);
	bool Train(Environment &env, const Array *pArrayCorrect);
	const Array *GetResult() const;
	const Array *GetResultSoftmax() const;
	inline const NodeOwner &GetNodeOwner() const { return _nodeOwner; }
	inline const Expr *GetExprSrc() const { return _pExprSrc.get(); }
	void Print() const;
};

}

#endif

