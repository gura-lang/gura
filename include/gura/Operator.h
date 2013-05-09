#ifndef __GURA_OPERATOR_H__
#define __GURA_OPERATOR_H__

#include "Common.h"

#define Gura_ImplementUnaryOperator(op, type) \
class Operator_##op##_##type : public Operator { \
public: \
	inline Operator_##op##_##type() : Operator(OPTYPE_##op, VTYPE_##type) {} \
	inline static Operator_##op##_##type *Create() { \
		return new Operator_##op##_##type(); \
	} \
	virtual Value DoEval(Environment &env, Signal sig, const Value &value) const; \
}; \
Value Operator_##op##_##type::DoEval(Environment &env, Signal sig, const Value &value) const

#define Gura_ImplementBinaryOperator(op, typeL, typeR) \
class Operator_##op##_##typeL##_##typeR : public Operator { \
public: \
	inline Operator_##op##_##typeL##_##typeR() : \
					Operator(OPTYPE_##op, VTYPE_##typeL, VTYPE_##typeR) {} \
	inline static Operator_##op##_##typeL##_##typeR *Create() { \
		return new Operator_##op##_##typeL##_##typeR(); \
	} \
	virtual Value DoEval(Environment &env, Signal sig, \
				const Value &valueLeft, const Value &valueRight) const; \
}; \
Value Operator_##op##_##typeL##_##typeR##::DoEval(Environment &env, Signal sig, \
					const Value &valueLeft, const Value &valueRight) const

#define Gura_AssignUnaryOperator(op, type) \
Operator::Assign(env, new Operator_##op##_##type())

#define Gura_AssignBinaryOperator(op, typeL, typeR) \
Operator::Assign(env, new Operator_##op##_##typeL##_##typeR())

namespace Gura {

enum OpType {
	OPTYPE_None,
	OPTYPE_Pos,
	OPTYPE_Neg,
	OPTYPE_Invert,
	OPTYPE_Not,
	OPTYPE_Plus,
	OPTYPE_Minus,
	OPTYPE_Multiply,
	OPTYPE_Divide,
	OPTYPE_Modulo,
	OPTYPE_Power,
	OPTYPE_Equal,
	OPTYPE_NotEqual,
	OPTYPE_Greater,
	OPTYPE_Less,
	OPTYPE_GreaterEq,
	OPTYPE_LessEq,
	OPTYPE_Compare,
	OPTYPE_ContainCheck,
	OPTYPE_Or,
	OPTYPE_And,
	OPTYPE_Xor,
	OPTYPE_ShiftL,
	OPTYPE_ShiftR,
	OPTYPE_OrOr,
	OPTYPE_AndAnd,
	OPTYPE_Sequence,
	OPTYPE_SequenceInf,
	OPTYPE_max,
};

void AssignBasicOperators(Environment &env);

//-----------------------------------------------------------------------------
// Operator
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator {
public:
	typedef unsigned long Key;
protected:
	OpType _opType;
	ValueType _valTypeLeft;
	ValueType _valTypeRight;
private:
	static const char *_mathSymbolTbl[];
public:
	inline Operator(OpType opType, ValueType valType) :
			_opType(opType), _valTypeLeft(valType), _valTypeRight(VTYPE_nil) {}
	inline Operator(OpType opType, ValueType valTypeLeft, ValueType valTypeRight) :
			_opType(opType), _valTypeLeft(valTypeLeft), _valTypeRight(valTypeRight) {}
	inline OpType GetOpType() const { return _opType; }
	inline ValueType GetValueType() const { return _valTypeLeft; }
	inline ValueType GetValueTypeLeft() const { return _valTypeLeft; }
	inline ValueType GetValueTypeRight() const { return _valTypeRight; }
	inline static Key CalcKey(ValueType valType) {
		return static_cast<Key>(valType);
	}
	inline static Key CalcKey(ValueType valTypeLeft, ValueType valTypeRight) {
		return static_cast<Key>((static_cast<unsigned long>(valTypeRight) << 16) +
							static_cast<unsigned long>(valTypeLeft));
	}
	inline Key CalcKey() const {
		return CalcKey(_valTypeLeft, _valTypeRight);
	}
	inline const char *GetMathSymbol() const { return GetMathSymbol(_opType); }
	inline static const char *GetMathSymbol(OpType opType) { return _mathSymbolTbl[opType]; }
	virtual Value DoEval(Environment &env, Signal sig, const Value &value) const;
	virtual Value DoEval(Environment &env, Signal sig,
					const Value &valueLeft, const Value &valueRight) const;
	void SetError_InvalidValueType(Signal &sig, const Value &value) const;
	void SetError_InvalidValueType(Signal &sig, const Value &valueLeft, const Value &valueRight) const;
	static void SetError_InvalidValueType(Signal &sig, OpType opType, const Value &value);
	static void SetError_InvalidValueType(Signal &sig, OpType opType,
					const Value &valueLeft, const Value &valueRight);
	static void Assign(Environment &env, Operator *pOperator);
	static const Operator *Lookup(Environment &env, OpType opType, ValueType valType);
	static const Operator *Lookup(Environment &env, OpType opType, ValueType valTypeLeft, ValueType valTypeRight);
};

//-----------------------------------------------------------------------------
// OperatorMap
//-----------------------------------------------------------------------------
typedef std::map<Operator::Key, Operator *> OperatorMap;

}

#endif
