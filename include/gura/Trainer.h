#ifndef __GURA_TRAINER_H__
#define __GURA_TRAINER_H__
#include "Class_gear_at_conv1d.h"
#include "Class_gear_at_conv2d.h"
#include "Class_gear_at_conv3d.h"
#include "Class_gear_at_maxpool1d.h"
#include "Class_gear_at_maxpool2d.h"
#include "Class_gear_at_maxpool3d.h"
#include "Class_gear_at_relu.h"
#include "Class_gear_at_sigmoid.h"
#include "Class_gear_at_softmax.h"
#include "Class_gear_at_tanh.h"

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
			inline AutoPtr<Array> &GetArrayBwdAutoPtr() { return _pArrayBwd; }
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
		inline AutoPtr<Array> &GetArrayFwdAutoPtr() { return _pArrayFwd; }
		virtual bool IsVulnerable() const = 0;
		virtual bool EvalForward(Environment &env) = 0;
		virtual bool EvalBackward(Environment &env) = 0;
		virtual bool DoDirProp(Environment &env, SymbolSet &symbols);
		virtual Value DoGetProp(Environment &env, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
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
		virtual bool DoDirProp(Environment &env, SymbolSet &symbols);
		virtual Value DoGetProp(Environment &env, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
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
		virtual bool DoDirProp(Environment &env, SymbolSet &symbols);
		virtual Value DoGetProp(Environment &env, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
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
		virtual bool DoDirProp(Environment &env, SymbolSet &symbols);
		virtual Value DoGetProp(Environment &env, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
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
		virtual bool DoDirProp(Environment &env, SymbolSet &symbols);
		virtual Value DoGetProp(Environment &env, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
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
	// NodeGear
	//-------------------------------------------------------------------------
	class NodeGear : public Node {
	protected:
		AutoPtr<Gear> _pGear;
		Connector _connectorSrc;
	public:
		inline NodeGear(Gear *pGear, Connector *pConnectorDst) :
				Node(pConnectorDst), _pGear(pGear), _connectorSrc(this) {}
		inline Connector *GetConnectorSrc() { return &_connectorSrc; }
		virtual bool DoDirProp(Environment &env, SymbolSet &symbols);
		virtual Value DoGetProp(Environment &env, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
		virtual String ToString() const;
		virtual void Print(int indentLevel) const;
	};
	//-------------------------------------------------------------------------
	// NodeGear_Conv
	//-------------------------------------------------------------------------
	class NodeGear_Conv : public NodeGear {
	protected:
		AutoPtr<Array> _pArrayFwdSrcVec;
		AutoPtr<Array> _pArrayGearReshape;
		AutoPtr<Array> _pArrayGearTrans;
		AutoPtr<Array> _pArrayFwdPre;
	public:
		inline NodeGear_Conv(Gear *pGear, Connector *pConnectorDst) :
				NodeGear(pGear, pConnectorDst) {}
		virtual bool IsVulnerable() const;
		virtual bool DoDirProp(Environment &env, SymbolSet &symbols);
		virtual Value DoGetProp(Environment &env, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
	};
	//-------------------------------------------------------------------------
	// NodeGear_Conv1d
	//-------------------------------------------------------------------------
	class NodeGear_Conv1d : public NodeGear_Conv {
	public:
		inline NodeGear_Conv1d(Gear_Conv1d *pGear, Connector *pConnectorDst) :
				NodeGear_Conv(pGear, pConnectorDst) {}
		inline Gear_Conv1d *GetGear() { return dynamic_cast<Gear_Conv1d *>(_pGear.get()); }
		virtual bool EvalForward(Environment &env);
		virtual bool EvalBackward(Environment &env);
	};
	//-------------------------------------------------------------------------
	// NodeGear_Conv2d
	//-------------------------------------------------------------------------
	class NodeGear_Conv2d : public NodeGear_Conv {
	private:
		size_t _sizePadRow;
		size_t _sizePadCol;
		size_t _sizeOutRow;
		size_t _sizeOutCol;
	public:
		inline NodeGear_Conv2d(Gear_Conv2d *pGear, Connector *pConnectorDst) :
			NodeGear_Conv(pGear, pConnectorDst), _sizePadRow(0), _sizePadCol(0), _sizeOutRow(0), _sizeOutCol(0) {}
		inline Gear_Conv2d *GetGear() { return dynamic_cast<Gear_Conv2d *>(_pGear.get()); }
		virtual bool EvalForward(Environment &env);
		virtual bool EvalBackward(Environment &env);
	};
	//-------------------------------------------------------------------------
	// NodeGear_Conv3d
	//-------------------------------------------------------------------------
	class NodeGear_Conv3d : public NodeGear_Conv {
	public:
		inline NodeGear_Conv3d(Gear_Conv3d *pGear, Connector *pConnectorDst) :
				NodeGear_Conv(pGear, pConnectorDst) {}
		inline Gear_Conv3d *GetGear() { return dynamic_cast<Gear_Conv3d *>(_pGear.get()); }
		virtual bool EvalForward(Environment &env);
		virtual bool EvalBackward(Environment &env);
	};
	//-------------------------------------------------------------------------
	// NodeGear_MaxPool1d
	//-------------------------------------------------------------------------
	class NodeGear_MaxPool1d : public NodeGear {
	public:
		inline NodeGear_MaxPool1d(Gear_MaxPool1d *pGear, Connector *pConnectorDst) :
				NodeGear(pGear, pConnectorDst) {}
		inline Gear_MaxPool1d *GetGear() { return dynamic_cast<Gear_MaxPool1d *>(_pGear.get()); }
		virtual bool IsVulnerable() const;
		virtual bool EvalForward(Environment &env);
		virtual bool EvalBackward(Environment &env);
	};
	//-------------------------------------------------------------------------
	// NodeGear_MaxPool2d
	//-------------------------------------------------------------------------
	class NodeGear_MaxPool2d : public NodeGear {
	public:
		inline NodeGear_MaxPool2d(Gear_MaxPool2d *pGear, Connector *pConnectorDst) :
				NodeGear(pGear, pConnectorDst) {}
		inline Gear_MaxPool2d *GetGear() { return dynamic_cast<Gear_MaxPool2d *>(_pGear.get()); }
		virtual bool IsVulnerable() const;
		virtual bool EvalForward(Environment &env);
		virtual bool EvalBackward(Environment &env);
	};
	//-------------------------------------------------------------------------
	// NodeGear_MaxPool3d
	//-------------------------------------------------------------------------
	class NodeGear_MaxPool3d : public NodeGear {
	public:
		inline NodeGear_MaxPool3d(Gear_MaxPool3d *pGear, Connector *pConnectorDst) :
				NodeGear(pGear, pConnectorDst) {}
		inline Gear_MaxPool3d *GetGear() { return dynamic_cast<Gear_MaxPool3d *>(_pGear.get()); }
		virtual bool IsVulnerable() const;
		virtual bool EvalForward(Environment &env);
		virtual bool EvalBackward(Environment &env);
	};
	//-------------------------------------------------------------------------
	// NodeGear_Relu
	//-------------------------------------------------------------------------
	class NodeGear_Relu : public NodeGear {
	private:
		AutoPtr<Array> _pArrayBool;
	public:
		inline NodeGear_Relu(Gear_Relu *pGear, Connector *pConnectorDst) :
				NodeGear(pGear, pConnectorDst) {}
		inline Gear_Relu *GetGear() { return dynamic_cast<Gear_Relu *>(_pGear.get()); }
		virtual bool IsVulnerable() const;
		virtual bool EvalForward(Environment &env);
		virtual bool EvalBackward(Environment &env);
		virtual bool DoDirProp(Environment &env, SymbolSet &symbols);
		virtual Value DoGetProp(Environment &env, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
	};
	//-------------------------------------------------------------------------
	// NodeGear_Sigmoid
	//-------------------------------------------------------------------------
	class NodeGear_Sigmoid : public NodeGear {
	private:
		AutoPtr<Array> _pArrayTmp;
	public:
		inline NodeGear_Sigmoid(Gear_Sigmoid *pGear, Connector *pConnectorDst) :
				NodeGear(pGear, pConnectorDst) {}
		inline Gear_Sigmoid *GetGear() { return dynamic_cast<Gear_Sigmoid *>(_pGear.get()); }
		virtual bool IsVulnerable() const;
		virtual bool EvalForward(Environment &env);
		virtual bool EvalBackward(Environment &env);
		virtual bool DoDirProp(Environment &env, SymbolSet &symbols);
		virtual Value DoGetProp(Environment &env, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
	};
	//-------------------------------------------------------------------------
	// NodeGear_softmax
	//-------------------------------------------------------------------------
	class NodeGear_Softmax : public NodeGear {
	public:
		inline NodeGear_Softmax(Gear_Softmax *pGear, Connector *pConnectorDst) :
				NodeGear(pGear, pConnectorDst) {}
		inline Gear_Softmax *GetGear() { return dynamic_cast<Gear_Softmax *>(_pGear.get()); }
		virtual bool IsVulnerable() const;
		virtual bool EvalForward(Environment &env);
		virtual bool EvalBackward(Environment &env);
	};
	//-------------------------------------------------------------------------
	// NodeGear_tanh
	//-------------------------------------------------------------------------
	class NodeGear_Tanh : public NodeGear {
	public:
		inline NodeGear_Tanh(Gear_Tanh *pGear, Connector *pConnectorDst) :
				NodeGear(pGear, pConnectorDst) {}
		inline Gear_Tanh *GetGear() { return dynamic_cast<Gear_Tanh *>(_pGear.get()); }
		virtual bool IsVulnerable() const;
		virtual bool EvalForward(Environment &env);
		virtual bool EvalBackward(Environment &env);
	};
	//-------------------------------------------------------------------------
	// NodeMap
	//-------------------------------------------------------------------------
	typedef std::unordered_map<const Symbol *, Node *, Symbol::Hasher, Symbol::EqualTo> NodeMap;
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
	private:
	public:
		~NodeOwner();
		void Clear();
	};
private:
	int _cntRef;
	AutoPtr<NodeBottom> _pNodeBottom;
	NodeOwner _nodeOwner;
	NodeMap _nodeMap;
	AutoPtr<Expr> _pExprModel;
public:
	Gura_DeclareReferenceAccessor(Trainer);
public:
	Trainer();
protected:
	virtual ~Trainer();
public:
	bool CreateFromExpr(Environment &env, const Expr *pExprModel, const SymbolSet &symbolsInput);
	bool EvalForward(Environment &env);
	bool EvalBackward(Environment &env, const Array *pArrayCorrect);
	const Array *GetResult() const;
	inline const NodeOwner &GetNodeOwner() const { return _nodeOwner; }
	inline const Expr *GetExprModel() const { return _pExprModel.get(); }
	Node *FindNode(const Symbol *pSymbol) const;
	void Print() const;
private:
	Node *CreateNode(Environment &env, const Expr *pExpr,
					 Node::Connector *pConnector, const SymbolSet &symbolsInput);
	Node *CreateNodeUnary(Environment &env, const Expr_UnaryOp *pExprEx,
						  Node::Connector *pConnector, const SymbolSet &symbolsInput);
	Node *CreateNodeBinary(Environment &env, const Expr_BinaryOp *pExprEx,
						   Node::Connector *pConnector, const SymbolSet &symbolsInput);
	Node *CreateNodeGear(Environment &env, const Expr_BinaryOp *pExprEx,
						 Node::Connector *pConnector, const SymbolSet &symbolsInput);
};

}

#endif

