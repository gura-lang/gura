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
	// Optimizer
	//-------------------------------------------------------------------------
	class Optimizer {
	public:
		class Instance {
		public:
			virtual bool Update(Signal &sig, AutoPtr<Array> &array, const Array *pArrayBwd) = 0;
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
		virtual Instance *CreateInstance() = 0;
		inline const char *GetName() const { return _name; }
	};
	//-------------------------------------------------------------------------
	// Optimizer_Adam
	//-------------------------------------------------------------------------
	class Optimizer_Adam : public Optimizer {
	public:
		class InstanceEx : public Instance {
		public:
			inline InstanceEx() {}
			virtual bool Update(Signal &sig, AutoPtr<Array> &pArray, const Array *pArrayBwd);
		};
	public:
		inline Optimizer_Adam() : Optimizer("adam") {}
		virtual Instance *CreateInstance();
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
			virtual bool Update(Signal &sig, AutoPtr<Array> &pArray, const Array *pArrayBwd);
		};
	public:
		inline Optimizer_GradientDescent(Double learningRate) :
					Optimizer("gradient_descent"), _learningRate(learningRate) {}
		virtual Instance *CreateInstance();
	};
	//-------------------------------------------------------------------------
	// Optimizer_Momentum
	//-------------------------------------------------------------------------
	class Optimizer_Momentum : public Optimizer {
	public:
		class InstanceEx : public Instance {
		public:
			inline InstanceEx() {}
			virtual bool Update(Signal &sig, AutoPtr<Array> &pArray, const Array *pArrayBwd);
		};
	public:
		inline Optimizer_Momentum() : Optimizer("momentum") {}
		virtual Instance *CreateInstance();
	};
	//-------------------------------------------------------------------------
	// Optimizer_None
	//-------------------------------------------------------------------------
	class Optimizer_None : public Optimizer {
	public:
		class InstanceEx : public Instance {
		public:
			inline InstanceEx() {}
			virtual bool Update(Signal &sig, AutoPtr<Array> &pArray, const Array *pArrayBwd);
		};
	public:
		inline Optimizer_None() : Optimizer("none") {}
		virtual Instance *CreateInstance();
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
		std::unique_ptr<Optimizer::Instance> _pOptimizerInst;
	public:
		inline NodeHead(Connector *pConnectorDst, Expr *pExpr, Trait trait, Optimizer::Instance *pOptimizerInst) :
			Node("head", pConnectorDst), _pExpr(pExpr), _trait(trait), _pOptimizerInst(pOptimizerInst) {}
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
		inline NodeBottom() : Node("bottom"), _connectorSrc(this) {}
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
		inline NodeUnary(const char *nodeTypeName, const Array::UnaryFuncPack &unaryFuncPack, Connector *pConnectorDst) :
			Node(nodeTypeName, pConnectorDst), _unaryFuncPack(unaryFuncPack), _connectorSrc(this) {}
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
				NodeUnary("unary_pos", Array::unaryFuncPack_Pos, pConnectorDst) {}
		virtual bool EvalBackward(Environment &env);
	};
	//-------------------------------------------------------------------------
	// NodeUnary_Neg
	//-------------------------------------------------------------------------
	class NodeUnary_Neg : public NodeUnary {
	public:
		inline NodeUnary_Neg(Connector *pConnectorDst) :
				NodeUnary("unary_neg", Array::unaryFuncPack_Neg, pConnectorDst) {}
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
				NodeBinary("binary_add", Array::binaryFuncPack_Add, pConnectorDst) {}
		virtual bool EvalBackward(Environment &env);
	};
	//-------------------------------------------------------------------------
	// NodeBinary_Sub
	//-------------------------------------------------------------------------
	class NodeBinary_Sub : public NodeBinary {
	public:
		inline NodeBinary_Sub(Connector *pConnectorDst) :
				NodeBinary("binary_sub", Array::binaryFuncPack_Sub, pConnectorDst) {}
		virtual bool EvalBackward(Environment &env);
	};
	//-------------------------------------------------------------------------
	// NodeBinary_Mul
	//-------------------------------------------------------------------------
	class NodeBinary_Mul : public NodeBinary {
	public:
		inline NodeBinary_Mul(Connector *pConnectorDst) :
				NodeBinary("binary_mul", Array::binaryFuncPack_Mul, pConnectorDst) {}
		virtual bool EvalBackward(Environment &env);
	};
	//-------------------------------------------------------------------------
	// NodeBinary_Div
	//-------------------------------------------------------------------------
	class NodeBinary_Div : public NodeBinary {
	public:
		inline NodeBinary_Div(Connector *pConnectorDst) :
				NodeBinary("binary_div", Array::binaryFuncPack_Div, pConnectorDst) {}
		virtual bool EvalBackward(Environment &env);
	};
	//-------------------------------------------------------------------------
	// NodeBinary_Pow
	//-------------------------------------------------------------------------
	class NodeBinary_Pow : public NodeBinary {
	public:
		inline NodeBinary_Pow(Connector *pConnectorDst) :
				NodeBinary("binary_pow", Array::binaryFuncPack_Pow, pConnectorDst) {}
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
				NodeBinary("binary_dot", Array::binaryFuncPack_Dot, pConnectorDst) {}
		virtual bool EvalBackward(Environment &env);
	};
	//-------------------------------------------------------------------------
	// NodeGear
	//-------------------------------------------------------------------------
	class NodeGear : public Node {
	public:
		class Creator {
		public:
			virtual NodeGear *Create(const Value &value, Connector *pConnectorDst) const = 0;
		};
	protected:
		AutoPtr<Gear> _pGear;
		Connector _connectorSrc;
	public:
		inline NodeGear(const char *nodeTypeName, Gear *pGear, Connector *pConnectorDst) :
				Node(nodeTypeName, pConnectorDst), _pGear(pGear), _connectorSrc(this) {}
		inline Connector *GetConnectorSrc() { return &_connectorSrc; }
		virtual bool DoDirProp(Environment &env, SymbolSet &symbols);
		virtual Value DoGetProp(Environment &env, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
		virtual String ToString() const;
		virtual void Print(int indentLevel) const;
	};
	//-------------------------------------------------------------------------
	// NodeGear_Conv1d
	//-------------------------------------------------------------------------
	class NodeGear_Conv1d : public NodeGear {
	public:
		class CreatorEx : public Creator {
		public:
			virtual NodeGear *Create(const Value &value, Connector *pConnectorDst) const;
		};
	private:
		AutoPtr<Array> _pArrayFwdSrcVec;
		AutoPtr<Array> _pArrayGearReshape;
		AutoPtr<Array> _pArrayGearTrans;
		AutoPtr<Array> _pArrayFwdPre;
	public:
		inline NodeGear_Conv1d(Gear_Conv1d *pGear, Connector *pConnectorDst) :
				NodeGear("gear_conv1d", pGear, pConnectorDst) {}
		inline Gear_Conv1d *GetGear() { return dynamic_cast<Gear_Conv1d *>(_pGear.get()); }
		virtual bool IsVulnerable() const;
		virtual bool DoDirProp(Environment &env, SymbolSet &symbols);
		virtual Value DoGetProp(Environment &env, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
		virtual bool EvalForward(Environment &env);
		virtual bool EvalBackward(Environment &env);
	};
	//-------------------------------------------------------------------------
	// NodeGear_Conv2d
	//-------------------------------------------------------------------------
	class NodeGear_Conv2d : public NodeGear {
	public:
		class CreatorEx : public Creator {
		public:
			virtual NodeGear *Create(const Value &value, Connector *pConnectorDst) const;
		};
	private:
		AutoPtr<Array> _pArrayFwdSrcVec;
		AutoPtr<Array> _pArrayGearReshape;
		AutoPtr<Array> _pArrayGearTrans;
		AutoPtr<Array> _pArrayFwdPre;
		size_t _sizePadRow;
		size_t _sizePadCol;
		size_t _sizeOutRow;
		size_t _sizeOutCol;
	public:
		inline NodeGear_Conv2d(Gear_Conv2d *pGear, Connector *pConnectorDst) :
				NodeGear("gear_conv2d", pGear, pConnectorDst),
				_sizePadRow(0), _sizePadCol(0), _sizeOutRow(0), _sizeOutCol(0) {}
		inline Gear_Conv2d *GetGear() { return dynamic_cast<Gear_Conv2d *>(_pGear.get()); }
		virtual bool IsVulnerable() const;
		virtual bool DoDirProp(Environment &env, SymbolSet &symbols);
		virtual Value DoGetProp(Environment &env, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
		virtual bool EvalForward(Environment &env);
		virtual bool EvalBackward(Environment &env);
	};
	//-------------------------------------------------------------------------
	// NodeGear_Conv3d
	//-------------------------------------------------------------------------
	class NodeGear_Conv3d : public NodeGear {
	public:
		class CreatorEx : public Creator {
		public:
			virtual NodeGear *Create(const Value &value, Connector *pConnectorDst) const;
		};
	private:
		AutoPtr<Array> _pArrayFwdSrcVec;
		AutoPtr<Array> _pArrayGearReshape;
		AutoPtr<Array> _pArrayGearTrans;
		AutoPtr<Array> _pArrayFwdPre;
	public:
		inline NodeGear_Conv3d(Gear_Conv3d *pGear, Connector *pConnectorDst) :
				NodeGear("gear_conv3d", pGear, pConnectorDst) {}
		inline Gear_Conv3d *GetGear() { return dynamic_cast<Gear_Conv3d *>(_pGear.get()); }
		virtual bool IsVulnerable() const;
		virtual bool DoDirProp(Environment &env, SymbolSet &symbols);
		virtual Value DoGetProp(Environment &env, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
		virtual bool EvalForward(Environment &env);
		virtual bool EvalBackward(Environment &env);
	};
	//-------------------------------------------------------------------------
	// NodeGear_MaxPool1d
	//-------------------------------------------------------------------------
	class NodeGear_MaxPool1d : public NodeGear {
	public:
		class CreatorEx : public Creator {
		public:
			virtual NodeGear *Create(const Value &value, Connector *pConnectorDst) const;
		};
	public:
		inline NodeGear_MaxPool1d(Gear_MaxPool1d *pGear, Connector *pConnectorDst) :
				NodeGear("gear_maxpool1d", pGear, pConnectorDst) {}
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
		class CreatorEx : public Creator {
		public:
			virtual NodeGear *Create(const Value &value, Connector *pConnectorDst) const;
		};
	public:
		inline NodeGear_MaxPool2d(Gear_MaxPool2d *pGear, Connector *pConnectorDst) :
				NodeGear("gear_maxpool2d", pGear, pConnectorDst) {}
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
		class CreatorEx : public Creator {
		public:
			virtual NodeGear *Create(const Value &value, Connector *pConnectorDst) const;
		};
	public:
		inline NodeGear_MaxPool3d(Gear_MaxPool3d *pGear, Connector *pConnectorDst) :
				NodeGear("gear_maxpool3d", pGear, pConnectorDst) {}
		inline Gear_MaxPool3d *GetGear() { return dynamic_cast<Gear_MaxPool3d *>(_pGear.get()); }
		virtual bool IsVulnerable() const;
		virtual bool EvalForward(Environment &env);
		virtual bool EvalBackward(Environment &env);
	};
	//-------------------------------------------------------------------------
	// NodeGear_Relu
	//-------------------------------------------------------------------------
	class NodeGear_Relu : public NodeGear {
	public:
		class CreatorEx : public Creator {
		public:
			virtual NodeGear *Create(const Value &value, Connector *pConnectorDst) const;
		};
	private:
		AutoPtr<Array> _pArrayBool;
	public:
		inline NodeGear_Relu(Gear_Relu *pGear, Connector *pConnectorDst) :
				NodeGear("gear_relu", pGear, pConnectorDst) {}
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
	public:
		class CreatorEx : public Creator {
		public:
			virtual NodeGear *Create(const Value &value, Connector *pConnectorDst) const;
		};
	private:
		AutoPtr<Array> _pArrayTmp;
	public:
		inline NodeGear_Sigmoid(Gear_Sigmoid *pGear, Connector *pConnectorDst) :
				NodeGear("gera_sigmoid", pGear, pConnectorDst) {}
		inline Gear_Sigmoid *GetGear() { return dynamic_cast<Gear_Sigmoid *>(_pGear.get()); }
		virtual bool IsVulnerable() const;
		virtual bool EvalForward(Environment &env);
		virtual bool EvalBackward(Environment &env);
		virtual bool DoDirProp(Environment &env, SymbolSet &symbols);
		virtual Value DoGetProp(Environment &env, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
	};
	//-------------------------------------------------------------------------
	// NodeGear_Softmax
	//-------------------------------------------------------------------------
	class NodeGear_Softmax : public NodeGear {
	public:
		class CreatorEx : public Creator {
		public:
			virtual NodeGear *Create(const Value &value, Connector *pConnectorDst) const;
		};
	public:
		inline NodeGear_Softmax(Gear_Softmax *pGear, Connector *pConnectorDst) :
				NodeGear("gear_softmax", pGear, pConnectorDst) {}
		inline Gear_Softmax *GetGear() { return dynamic_cast<Gear_Softmax *>(_pGear.get()); }
		virtual bool IsVulnerable() const;
		virtual bool EvalForward(Environment &env);
		virtual bool EvalBackward(Environment &env);
	};
	//-------------------------------------------------------------------------
	// NodeGear_Tanh
	//-------------------------------------------------------------------------
	class NodeGear_Tanh : public NodeGear {
	public:
		class CreatorEx : public Creator {
		public:
			virtual NodeGear *Create(const Value &value, Connector *pConnectorDst) const;
		};
	public:
		inline NodeGear_Tanh(Gear_Tanh *pGear, Connector *pConnectorDst) :
				NodeGear("gear_tanh", pGear, pConnectorDst) {}
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
	bool EvalForward(Environment &env);
	bool EvalBackward(Environment &env, const Array *pArrayCorrect);
	const Array *GetResult() const;
	inline NodeBottom *GetNodeBottom() { return _pNodeBottom.get(); }
	inline const NodeBottom *GetNodeBottom() const { return _pNodeBottom.get(); }
	inline const NodeOwner &GetNodeOwner() const { return _nodeOwner; }
	inline const Expr *GetExprModel() const { return _pExprModel.get(); }
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

