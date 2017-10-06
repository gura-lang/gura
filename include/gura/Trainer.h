#ifndef __GURA_TRAINER_H__
#define __GURA_TRAINER_H__
#include "Class_filter_at_conv1d.h"
#include "Class_filter_at_conv2d.h"
#include "Class_filter_at_conv3d.h"
#include "Class_filter_at_maxpool1d.h"
#include "Class_filter_at_maxpool2d.h"
#include "Class_filter_at_maxpool3d.h"
#include "Class_filter_at_relu.h"
#include "Class_filter_at_sigmoid.h"
#include "Class_filter_at_softmax.h"
#include "Class_filter_at_tanh.h"

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
		virtual String ToString() const = 0;
		virtual void Print(int indentLevel) const;
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
		virtual String ToString() const;
		virtual void Print(int indentLevel) const;
	};
	//-------------------------------------------------------------------------
	// NodeBottom
	//-------------------------------------------------------------------------
	class NodeBottom : public Node {
	private:
		Connector _connectorSrc;
		AutoPtr<Array> _pArrayCorrect;
	public:
		inline NodeBottom() : Node(), _connectorSrc(this) {}
		inline Connector *GetConnectorSrc() { return &_connectorSrc; }
		virtual bool IsVulnerable() const;
		virtual bool EvalForward(Environment &env);
		virtual bool EvalBackward(Environment &env);
		bool EvalBackwardTop(Environment &env, const Array *pArrayCorrect);
		virtual String ToString() const;
		virtual void Print(int indentLevel) const;
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
		virtual String ToString() const;
		virtual void Print(int indentLevel) const;
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
				NodeUnary(Array::unaryFuncPack_Neg, pConnectorDst) {}
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
		virtual String ToString() const;
		virtual void Print(int indentLevel) const;
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
		virtual String ToString() const;
		virtual void Print(int indentLevel) const;
	};
	//-------------------------------------------------------------------------
	// NodeFilter_Conv1d
	//-------------------------------------------------------------------------
	class NodeFilter_Conv1d : public NodeFilter {
	public:
		inline NodeFilter_Conv1d(Filter_Conv1d *pFilter, Connector *pConnectorDst) :
				NodeFilter(pFilter, pConnectorDst) {}
		inline Filter_Conv1d *GetFilter() { return dynamic_cast<Filter_Conv1d *>(_pFilter.get()); }
		virtual bool IsVulnerable() const;
		virtual bool EvalForward(Environment &env);
		virtual bool EvalBackward(Environment &env);
	};
	//-------------------------------------------------------------------------
	// NodeFilter_Conv2d
	//-------------------------------------------------------------------------
	class NodeFilter_Conv2d : public NodeFilter {
	public:
		inline NodeFilter_Conv2d(Filter_Conv2d *pFilter, Connector *pConnectorDst) :
				NodeFilter(pFilter, pConnectorDst) {}
		inline Filter_Conv2d *GetFilter() { return dynamic_cast<Filter_Conv2d *>(_pFilter.get()); }
		virtual bool IsVulnerable() const;
		virtual bool EvalForward(Environment &env);
		virtual bool EvalBackward(Environment &env);
	};
	//-------------------------------------------------------------------------
	// NodeFilter_Conv3d
	//-------------------------------------------------------------------------
	class NodeFilter_Conv3d : public NodeFilter {
	public:
		inline NodeFilter_Conv3d(Filter_Conv3d *pFilter, Connector *pConnectorDst) :
				NodeFilter(pFilter, pConnectorDst) {}
		inline Filter_Conv3d *GetFilter() { return dynamic_cast<Filter_Conv3d *>(_pFilter.get()); }
		virtual bool IsVulnerable() const;
		virtual bool EvalForward(Environment &env);
		virtual bool EvalBackward(Environment &env);
	};
	//-------------------------------------------------------------------------
	// NodeFilter_MaxPool1d
	//-------------------------------------------------------------------------
	class NodeFilter_MaxPool1d : public NodeFilter {
	public:
		inline NodeFilter_MaxPool1d(Filter_MaxPool1d *pFilter, Connector *pConnectorDst) :
				NodeFilter(pFilter, pConnectorDst) {}
		inline Filter_MaxPool1d *GetFilter() { return dynamic_cast<Filter_MaxPool1d *>(_pFilter.get()); }
		virtual bool IsVulnerable() const;
		virtual bool EvalForward(Environment &env);
		virtual bool EvalBackward(Environment &env);
	};
	//-------------------------------------------------------------------------
	// NodeFilter_MaxPool2d
	//-------------------------------------------------------------------------
	class NodeFilter_MaxPool2d : public NodeFilter {
	public:
		inline NodeFilter_MaxPool2d(Filter_MaxPool2d *pFilter, Connector *pConnectorDst) :
				NodeFilter(pFilter, pConnectorDst) {}
		inline Filter_MaxPool2d *GetFilter() { return dynamic_cast<Filter_MaxPool2d *>(_pFilter.get()); }
		virtual bool IsVulnerable() const;
		virtual bool EvalForward(Environment &env);
		virtual bool EvalBackward(Environment &env);
	};
	//-------------------------------------------------------------------------
	// NodeFilter_MaxPool3d
	//-------------------------------------------------------------------------
	class NodeFilter_MaxPool3d : public NodeFilter {
	public:
		inline NodeFilter_MaxPool3d(Filter_MaxPool3d *pFilter, Connector *pConnectorDst) :
				NodeFilter(pFilter, pConnectorDst) {}
		inline Filter_MaxPool3d *GetFilter() { return dynamic_cast<Filter_MaxPool3d *>(_pFilter.get()); }
		virtual bool IsVulnerable() const;
		virtual bool EvalForward(Environment &env);
		virtual bool EvalBackward(Environment &env);
	};
	//-------------------------------------------------------------------------
	// NodeFilter_Relu
	//-------------------------------------------------------------------------
	class NodeFilter_Relu : public NodeFilter {
	private:
		AutoPtr<Array> _pArrayBool;
	public:
		inline NodeFilter_Relu(Filter_Relu *pFilter, Connector *pConnectorDst) :
				NodeFilter(pFilter, pConnectorDst) {}
		inline Filter_Relu *GetFilter() { return dynamic_cast<Filter_Relu *>(_pFilter.get()); }
		virtual bool IsVulnerable() const;
		virtual bool EvalForward(Environment &env);
		virtual bool EvalBackward(Environment &env);
	};
	//-------------------------------------------------------------------------
	// NodeFilter_Sigmoid
	//-------------------------------------------------------------------------
	class NodeFilter_Sigmoid : public NodeFilter {
	private:
		AutoPtr<Array> _pArrayTmp;
	public:
		inline NodeFilter_Sigmoid(Filter_Sigmoid *pFilter, Connector *pConnectorDst) :
				NodeFilter(pFilter, pConnectorDst) {}
		inline Filter_Sigmoid *GetFilter() { return dynamic_cast<Filter_Sigmoid *>(_pFilter.get()); }
		virtual bool IsVulnerable() const;
		virtual bool EvalForward(Environment &env);
		virtual bool EvalBackward(Environment &env);
	};
	//-------------------------------------------------------------------------
	// NodeFilter_softmax
	//-------------------------------------------------------------------------
	class NodeFilter_Softmax : public NodeFilter {
	public:
		inline NodeFilter_Softmax(Filter_Softmax *pFilter, Connector *pConnectorDst) :
				NodeFilter(pFilter, pConnectorDst) {}
		inline Filter_Softmax *GetFilter() { return dynamic_cast<Filter_Softmax *>(_pFilter.get()); }
		virtual bool IsVulnerable() const;
		virtual bool EvalForward(Environment &env);
		virtual bool EvalBackward(Environment &env);
	};
	//-------------------------------------------------------------------------
	// NodeFilter_tanh
	//-------------------------------------------------------------------------
	class NodeFilter_Tanh : public NodeFilter {
	public:
		inline NodeFilter_Tanh(Filter_Tanh *pFilter, Connector *pConnectorDst) :
				NodeFilter(pFilter, pConnectorDst) {}
		inline Filter_Tanh *GetFilter() { return dynamic_cast<Filter_Tanh *>(_pFilter.get()); }
		virtual bool IsVulnerable() const;
		virtual bool EvalForward(Environment &env);
		virtual bool EvalBackward(Environment &env);
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
		bool CreateNodeUnary(Environment &env, const Expr_UnaryOp *pExprEx,
							 Node::Connector *pConnector, const SymbolSet &symbolsInput);
		bool CreateNodeBinary(Environment &env, const Expr_BinaryOp *pExprEx,
							  Node::Connector *pConnector, const SymbolSet &symbolsInput);
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
	bool EvalForward(Environment &env);
	bool EvalBackward(Environment &env, const Array *pArrayCorrect);
	const Array *GetResult() const;
	const Array *GetResultSoftmax() const;
	inline const NodeOwner &GetNodeOwner() const { return _nodeOwner; }
	inline const Expr *GetExprSrc() const { return _pExprSrc.get(); }
	void Print() const;
};

}

#endif

