#ifndef __GURA_TRAINER_H__
#define __GURA_TRAINER_H__
#include "Class_gear.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Trainer
//-----------------------------------------------------------------------------
class Trainer {
public:
	//-------------------------------------------------------------------------
	// Optimizer
	//-------------------------------------------------------------------------
	class Optimizer {
	public:
		class Instance {
		public:
			virtual void Reset(Environment &env);
			virtual bool Update(Signal &sig, AutoPtr<Array> &pArray, const Array *pArrayGrad) = 0;
		};
	private:
		int _cntRef;
		const char *_name;
	public:
		Gura_DeclareReferenceAccessor(Optimizer);
	public:
		inline Optimizer(const char *name) : _cntRef(1), _name(name) {}
	protected:
		virtual ~Optimizer();
	public:
		virtual Instance *CreateInstance() const = 0;
		inline const char *GetName() const { return _name; }
	};
	//-------------------------------------------------------------------------
	// Optimizer_AdaGrad
	//-------------------------------------------------------------------------
	class Optimizer_AdaGrad : public Optimizer {
	public:
		class InstanceEx : public Instance {
		public:
			inline InstanceEx() {}
			virtual void Reset(Environment &env);
			virtual bool Update(Signal &sig, AutoPtr<Array> &pArray, const Array *pArrayGrad);
		};
	public:
		inline Optimizer_AdaGrad() : Optimizer("adagrad") {}
		virtual Instance *CreateInstance() const;
	};
	//-------------------------------------------------------------------------
	// Optimizer_Adam
	//-------------------------------------------------------------------------
	class Optimizer_Adam : public Optimizer {
	public:
		class InstanceEx : public Instance {
		public:
			inline InstanceEx() {}
			virtual void Reset(Environment &env);
			virtual bool Update(Signal &sig, AutoPtr<Array> &pArray, const Array *pArrayGrad);
		};
	public:
		inline Optimizer_Adam() : Optimizer("adam") {}
		virtual Instance *CreateInstance() const;
	};
	//-------------------------------------------------------------------------
	// Optimizer_GradientDescent
	//-------------------------------------------------------------------------
	class Optimizer_GradientDescent : public Optimizer {
	private:
		Double _learningRate;
	public:
		class InstanceEx : public Instance {
		private:
			Double _learningRate;
			AutoPtr<Array> _pArrayAdj;
		public:
			inline InstanceEx(Double learningRate) : _learningRate(learningRate) {}
			virtual void Reset(Environment &env);
			virtual bool Update(Signal &sig, AutoPtr<Array> &pArray, const Array *pArrayGrad);
		};
	public:
		inline Optimizer_GradientDescent(Double learningRate) :
					Optimizer("gradient_descent"), _learningRate(learningRate) {}
		virtual Instance *CreateInstance() const;
	};
	//-------------------------------------------------------------------------
	// Optimizer_Momentum
	//-------------------------------------------------------------------------
	class Optimizer_Momentum : public Optimizer {
	private:
		Double _learningRate;
		Double _momentum;
	public:
		class InstanceEx : public Instance {
		private:
			Double _learningRate;
			Double _momentum;
			AutoPtr<Array> _pArrayVel;
			AutoPtr<Array> _pArrayAdj;
		public:
			inline InstanceEx(Double learningRate, Double momentum) :
							_learningRate(learningRate), _momentum(momentum) {}
			virtual void Reset(Environment &env);
			virtual bool Update(Signal &sig, AutoPtr<Array> &pArray, const Array *pArrayGrad);
		};
	public:
		inline Optimizer_Momentum(Double learningRate, Double momentum) : Optimizer("momentum"),
							_learningRate(learningRate), _momentum(momentum) {}
		virtual Instance *CreateInstance() const;
	};
	//-------------------------------------------------------------------------
	// Optimizer_Nesterov
	//-------------------------------------------------------------------------
	class Optimizer_Nesterov : public Optimizer {
	public:
		class InstanceEx : public Instance {
		public:
			inline InstanceEx() {}
			virtual void Reset(Environment &env);
			virtual bool Update(Signal &sig, AutoPtr<Array> &pArray, const Array *pArrayGrad);
		};
	public:
		inline Optimizer_Nesterov() : Optimizer("nesterov") {}
		virtual Instance *CreateInstance() const;
	};
	//-------------------------------------------------------------------------
	// Optimizer_None
	//-------------------------------------------------------------------------
	class Optimizer_None : public Optimizer {
	public:
		class InstanceEx : public Instance {
		public:
			inline InstanceEx() {}
			virtual bool Update(Signal &sig, AutoPtr<Array> &pArray, const Array *pArrayGrad);
		};
	public:
		inline Optimizer_None() : Optimizer("none") {}
		virtual Instance *CreateInstance() const;
	};
	//-------------------------------------------------------------------------
	// Optimizer_RMSprop
	//-------------------------------------------------------------------------
	class Optimizer_RMSprop : public Optimizer {
	public:
		class InstanceEx : public Instance {
		public:
			inline InstanceEx() {}
			virtual void Reset(Environment &env);
			virtual bool Update(Signal &sig, AutoPtr<Array> &pArray, const Array *pArrayGrad);
		};
	public:
		inline Optimizer_RMSprop() : Optimizer("rmsprop") {}
		virtual Instance *CreateInstance() const;
	};
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
			AutoPtr<Array> _pArrayGrad;
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
			inline void SetArrayGrad(Array *pArrayGrad) { _pArrayGrad.reset(pArrayGrad); }
			inline Array *GetArrayFwd() { return _pNodeSrc->GetArrayFwd(); }
			inline Array *GetArrayGrad() { return _pArrayGrad.get(); }
			inline AutoPtr<Array> &GetArrayGradAutoPtr() { return _pArrayGrad; }
			inline const Array *GetArrayFwd() const { return _pNodeSrc->GetArrayFwd(); }
			inline const Array *GetArrayGrad() const { return _pArrayGrad.get(); }
		};
		class ConnectorList : public std::vector<Connector *> {
		public:
			inline ConnectorList() {}
		};
	protected:
		int _cntRef;
		const char *_nodeTypeName;
		ConnectorList _connectorsDst;
		AutoPtr<Array> _pArrayFwd;
	public:
		Gura_DeclareReferenceAccessor(Node);
	public:
		inline Node(const char *nodeTypeName) : _cntRef(1), _nodeTypeName(nodeTypeName) {}
		Node(const char *nodeTypeName, Connector *pConnectorDst);
	protected:
		virtual ~Node();
	public:
		inline const char *GetNodeTypeName() const { return _nodeTypeName; }
		inline void AddConnectorDst(Connector *pConnectorDst) { _connectorsDst.push_back(pConnectorDst); }
		inline Array *GetArrayFwd() { return _pArrayFwd.get(); }
		inline AutoPtr<Array> &GetArrayFwdAutoPtr() { return _pArrayFwd; }
		virtual bool IsHead();
		virtual bool IsBottom();
		virtual bool IsUnary();
		virtual bool IsBinary();
		virtual bool IsGear();
		virtual bool IsVulnerable() const = 0;
		virtual void Reset(Environment &env);
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
		AutoPtr<Array> _pArrayGradAdj;
		Trait _trait;
		std::unique_ptr<Optimizer::Instance> _pOptimizerInst;
	public:
		inline NodeHead(Connector *pConnectorDst, Expr *pExpr, Trait trait, Optimizer::Instance *pOptimizerInst) :
			Node("head", pConnectorDst), _pExpr(pExpr), _trait(trait), _pOptimizerInst(pOptimizerInst) {}
		inline bool IsVariable() const { return _trait == TRAIT_Variable; }
		inline bool IsConstant() const { return _trait == TRAIT_Constant; }
		inline bool IsInput() const { return _trait == TRAIT_Input; }
		virtual bool IsHead();
		virtual void Reset(Environment &env);
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
		inline NodeBottom() : Node("bottom"), _connectorSrc(this) {}
		inline Connector *GetConnectorSrc() { return &_connectorSrc; }
		inline const Connector *GetConnectorSrc() const { return &_connectorSrc; }
		virtual bool IsBottom();
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
		inline NodeUnary(const char *nodeTypeName, const Array::UnaryFuncPack &unaryFuncPack, Connector *pConnectorDst) :
			Node(nodeTypeName, pConnectorDst), _unaryFuncPack(unaryFuncPack), _connectorSrc(this) {}
		inline Connector *GetConnectorSrc() { return &_connectorSrc; }
		inline const Connector *GetConnectorSrc() const { return &_connectorSrc; }
		virtual bool IsUnary();
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
				NodeUnary("unary@pos", Array::unaryFuncPack_Pos, pConnectorDst) {}
		virtual bool EvalBackward(Environment &env);
	};
	//-------------------------------------------------------------------------
	// NodeUnary_Neg
	//-------------------------------------------------------------------------
	class NodeUnary_Neg : public NodeUnary {
	public:
		inline NodeUnary_Neg(Connector *pConnectorDst) :
				NodeUnary("unary@neg", Array::unaryFuncPack_Neg, pConnectorDst) {}
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
		inline NodeBinary(const char *nodeTypeName, const Array::BinaryFuncPack &binaryFuncPack, Connector *pConnectorDst) :
				Node(nodeTypeName, pConnectorDst), _binaryFuncPack(binaryFuncPack),
				_connectorSrcLeft(this), _connectorSrcRight(this) {}
		inline Connector *GetConnectorSrcLeft() { return &_connectorSrcLeft; }
		inline Connector *GetConnectorSrcRight() { return &_connectorSrcRight; }
		inline const Connector *GetConnectorSrcLeft() const { return &_connectorSrcLeft; }
		inline const Connector *GetConnectorSrcRight() const { return &_connectorSrcRight; }
		virtual bool IsBinary();
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
				NodeBinary("binary@add", Array::binaryFuncPack_Add, pConnectorDst) {}
		virtual bool EvalBackward(Environment &env);
	};
	//-------------------------------------------------------------------------
	// NodeBinary_Sub
	//-------------------------------------------------------------------------
	class NodeBinary_Sub : public NodeBinary {
	public:
		inline NodeBinary_Sub(Connector *pConnectorDst) :
				NodeBinary("binary@sub", Array::binaryFuncPack_Sub, pConnectorDst) {}
		virtual bool EvalBackward(Environment &env);
	};
	//-------------------------------------------------------------------------
	// NodeBinary_Mul
	//-------------------------------------------------------------------------
	class NodeBinary_Mul : public NodeBinary {
	public:
		inline NodeBinary_Mul(Connector *pConnectorDst) :
				NodeBinary("binary@mul", Array::binaryFuncPack_Mul, pConnectorDst) {}
		virtual bool EvalBackward(Environment &env);
	};
	//-------------------------------------------------------------------------
	// NodeBinary_Div
	//-------------------------------------------------------------------------
	class NodeBinary_Div : public NodeBinary {
	public:
		inline NodeBinary_Div(Connector *pConnectorDst) :
				NodeBinary("binary@div", Array::binaryFuncPack_Div, pConnectorDst) {}
		virtual bool EvalBackward(Environment &env);
	};
	//-------------------------------------------------------------------------
	// NodeBinary_Pow
	//-------------------------------------------------------------------------
	class NodeBinary_Pow : public NodeBinary {
	public:
		inline NodeBinary_Pow(Connector *pConnectorDst) :
				NodeBinary("binary@pow", Array::binaryFuncPack_Pow, pConnectorDst) {}
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
				NodeBinary("binary@dot", Array::binaryFuncPack_Dot, pConnectorDst) {}
		virtual bool EvalBackward(Environment &env);
	};
	//-------------------------------------------------------------------------
	// NodeGear
	//-------------------------------------------------------------------------
	class NodeGear : public Node {
	public:
		class Creator {
		public:
			virtual NodeGear *Create(const Value &value, Connector *pConnectorDst, const Trainer *pTrainer) const = 0;
		};
	protected:
		AutoPtr<Gear> _pGear;
		Connector _connectorSrc;
	public:
		inline NodeGear(Gear *pGear, Connector *pConnectorDst) :
				Node(pGear->GetName(), pConnectorDst), _pGear(pGear), _connectorSrc(this) {}
		inline Connector *GetConnectorSrc() { return &_connectorSrc; }
		inline const Connector *GetConnectorSrc() const { return &_connectorSrc; }
		virtual bool IsGear();
		virtual bool DoDirProp(Environment &env, SymbolSet &symbols);
		virtual Value DoGetProp(Environment &env, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
		virtual String ToString() const;
		virtual void Print(int indentLevel) const;
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
		void Reset(Environment &env);
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
	//-------------------------------------------------------------------------
	// NodeGearCreatorMap
	//-------------------------------------------------------------------------
	typedef std::map<ValueType, const NodeGear::Creator *> NodeGearCreatorMap;
private:
	int _cntRef;
	AutoPtr<Optimizer> _pOptimizer;
	AutoPtr<NodeBottom> _pNodeBottom;
	NodeOwner _nodeOwner;
	NodeMap _nodeMap;
	AutoPtr<Expr> _pExprModel;
	static NodeGearCreatorMap _nodeGearCreatorMap;
public:
	Gura_DeclareReferenceAccessor(Trainer);
public:
	Trainer(Optimizer *pOptimizer);
protected:
	virtual ~Trainer();
public:
	static void Bootup();
public:
	bool CreateFromExpr(Environment &env, const Expr *pExprModel, const SymbolSet &symbolsInput);
	void Reset(Environment &env);
	bool EvalForward(Environment &env);
	bool EvalBackward(Environment &env, const Array *pArrayCorrect);
	const Array *GetResult() const;
	inline NodeBottom *GetNodeBottom() { return _pNodeBottom.get(); }
	inline const NodeBottom *GetNodeBottom() const { return _pNodeBottom.get(); }
	inline const NodeOwner &GetNodeOwner() const { return _nodeOwner; }
	inline const Expr *GetExprModel() const { return _pExprModel.get(); }
	inline Optimizer::Instance *CreateOptimizerInstance() const { return _pOptimizer->CreateInstance(); }
	Node *FindNode(const Symbol *pSymbol) const;
	void Print() const;
	static inline void RegisterNodeGearCreator(ValueType valType, const NodeGear::Creator *pCreator) {
		_nodeGearCreatorMap[valType] = pCreator;
	}
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

