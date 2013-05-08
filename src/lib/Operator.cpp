#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Operator
//-----------------------------------------------------------------------------
class Operator {
protected:
	OpType _opType;
	ValueType _valTypeLeft;
	ValueType _valTypeRight;
public:
	inline Operator(OpType opType, ValueType valType) :
			_opType(opType), _valTypeLeft(valType), _valTypeRight(VTYPE_nil) {}
	inline Operator(OpType opType, ValueType valTypeLeft, ValueType valTypeRight) :
			_opType(opType), _valTypeLeft(valTypeLeft), _valTypeRight(valTypeRight) {}
	inline OpType GetOpType() const { return _opType; }
	inline ValueType GetValueType() const { return _valTypeLeft; }
	inline ValueType GetValueTypeLeft() const { return _valTypeLeft; }
	inline ValueType GetValueTypeRight() const { return _valTypeRight; }
	inline static unsigned long CalcValueTypeKey(ValueType valType) {
		return static_cast<unsigned long>(valType);
	}
	inline static unsigned long CalcValueTypeKey(ValueType valTypeLeft, ValueType valTypeRight) {
		return (static_cast<unsigned long>(valTypeRight) << 16) +
							static_cast<unsigned long>(valTypeLeft);
	}
	inline unsigned long CalcValueTypeKey() const {
		return CalcValueTypeKey(_valTypeLeft, _valTypeRight);
	}
	virtual Value DoEval(Environment &env, Signal sig, const Value &value) const;
	virtual Value DoEval(Environment &env, Signal sig,
					const Value &valueLeft, const Value &valueRight) const;
};

//-----------------------------------------------------------------------------
// OperatorMap
//-----------------------------------------------------------------------------
class OperatorMap {
public:
	typedef std::map<unsigned long, Operator *> Map;
private:
	Map _maps[OPTYPE_max];
public:
	inline OperatorMap() {}
	void Register(Operator *pOperator);
	const Operator *Lookup(OpType opType, ValueType valType) const;
	const Operator *Lookup(OpType opType, ValueType valTypeLeft, ValueType valTypeRight) const;
};

//-----------------------------------------------------------------------------
// Operator
//-----------------------------------------------------------------------------
Value Operator::DoEval(Environment &env, Signal sig, const Value &value) const
{
	return Value::Null;
}

Value Operator::DoEval(Environment &env, Signal sig,
				const Value &valueLeft, const Value &valueRight) const
{
	return Value::Null;
}

//-----------------------------------------------------------------------------
// OperatorMap
//-----------------------------------------------------------------------------
void OperatorMap::Register(Operator *pOperator)
{
	Map &map = _maps[pOperator->GetOpType()];
	map[pOperator->CalcValueTypeKey()] = pOperator;
}

const Operator *OperatorMap::Lookup(OpType opType, ValueType valType) const
{
	const Map &map = _maps[opType];
	Map::const_iterator iter = map.find(Operator::CalcValueTypeKey(valType));
	return (iter == map.end())? NULL : iter->second;
}

const Operator *OperatorMap::Lookup(OpType opType, ValueType valTypeLeft, ValueType valTypeRight) const
{
	const Map &map = _maps[opType];
	Map::const_iterator iter = map.find(Operator::CalcValueTypeKey(valTypeLeft, valTypeRight));
	return (iter == map.end())? NULL : iter->second;
}

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

#define Gura_RegisterUnaryOperator(op, type) \
env.RegisterOperator(new Operator_##op##_##type())

#define Gura_RegisterBinaryOperator(op, typeL, typeR) \
env.RegisterOperator(new Operator_##op##_##typeL##_##typeR())

Gura_ImplementUnaryOperator(Pos, number)
{
	return value;
}

Gura_ImplementBinaryOperator(Plus, number, number)
{
	return Value(valueLeft.GetNumber() + valueRight.GetNumber());
}

Gura_ImplementBinaryOperator(Plus, complex, complex)
{
	return Value(valueLeft.GetComplex() + valueRight.GetComplex());
}

Gura_ImplementBinaryOperator(Plus, number, complex)
{
	return Value(valueLeft.GetNumber() + valueRight.GetComplex());
}

Gura_ImplementBinaryOperator(Plus, complex, number)
{
	return Value(valueLeft.GetComplex() + valueRight.GetNumber());
}

Gura_ImplementBinaryOperator(Plus, matrix, matrix)
{
	return Matrix::OperatorPlusMinus(env, sig, OPTYPE_Plus,
		Object_matrix::GetObject(valueLeft)->GetMatrix(), Object_matrix::GetObject(valueRight)->GetMatrix());
}

#if 0
	} else if (valueLeft.IsDateTime() && valueRight.IsTimeDelta()) {
		DateTime dateTime = valueLeft.GetDateTime();
		dateTime.Plus(valueRight.GetTimeDelta());
		return Value(env, dateTime);
	} else if (valueLeft.IsTimeDelta() && valueRight.IsDateTime()) {
		DateTime dateTime = valueRight.GetDateTime();
		dateTime.Plus(valueLeft.GetTimeDelta());
		return Value(env, dateTime);
	} else if (valueLeft.IsTimeDelta() && valueRight.IsTimeDelta()) {
		TimeDelta td1 = valueLeft.GetTimeDelta();
		TimeDelta td2 = valueRight.GetTimeDelta();
		return Value(env, TimeDelta(
				td1.GetDays() + td2.GetDays(),
				td1.GetSecsRaw() + td2.GetSecsRaw(),
				td1.GetUSecs() + td2.GetUSecs()));
	} else if (valueLeft.IsString() && valueRight.IsString()) {
		String str(valueLeft.GetString());
		str += valueRight.GetString();
		result = Value(env, str.c_str());
		return result;
	} else if (valueLeft.IsBinary() && valueRight.IsBinary()) {
		Binary buff(valueLeft.GetBinary());
		buff += valueRight.GetBinary();
		result = Value(new Object_binary(env, buff, true));
		return result;
	} else if (valueLeft.IsBinary() && valueRight.IsString()) {
		Binary buff(valueLeft.GetBinary());
		buff += valueRight.GetString();
		result = Value(new Object_binary(env, buff, true));
		return result;
	} else if (valueLeft.IsString() && valueRight.IsBinary()) {
		Binary buff;
		buff += valueLeft.GetString();
		buff += valueRight.GetBinary();
		result = Value(new Object_binary(env, buff, true));
		return result;
	} else if (valueLeft.IsBinaryPtr() && valueRight.IsNumber()) {
		Object_binaryptr *pObj =
			dynamic_cast<Object_binaryptr *>(Object_binaryptr::GetObject(valueLeft)->Clone());
		pObj->UnpackForward(sig,
							static_cast<int>(valueRight.GetNumber()), true);
		if (sig.IsSignalled()) return Value::Null;
		Value result;
		result.InitAsObject(pObj);
		return result;
#endif

void sub(Environment &env)
{
	//Gura_RegisterUnaryOperator(Pos, number);
	//Gura_RegisterBinaryOperator(Plus, number, number);
}

}
