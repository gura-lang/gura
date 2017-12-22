//=============================================================================
// Vertex
//=============================================================================
#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Vertex2
//-----------------------------------------------------------------------------
const Vertex2 Vertex2::Zero;

String Vertex2::ToString() const
{
	String str;
	str += NumberToString(x);
	str += ",";
	str += NumberToString(y);
	return str;
}

//-----------------------------------------------------------------------------
// Vertex
//-----------------------------------------------------------------------------
const Vertex Vertex::Zero;

Vertex Vertex::Translate(double tx, double ty, double tz) const
{
	return Vertex(x + tx, y + ty, z + tz);
}

Vertex Vertex::RotateX(double rad) const
{
	double numCos = ::cos(rad), numSin = ::sin(rad);
	return Vertex(x, numCos * y - numSin * z, numSin * y + numCos * z);
}

Vertex Vertex::RotateY(double rad) const
{
	double numCos = ::cos(rad), numSin = ::sin(rad);
	return Vertex(numCos * x + numSin * z, y, -numSin * x + numCos * z);
}

Vertex Vertex::RotateZ(double rad) const
{
	double numCos = ::cos(rad), numSin = ::sin(rad);
	return Vertex(numCos * x - numSin * y, numSin * x + numCos * y, z);
}

void Vertex::Neg(Vertex &vRtn, const Vertex &v)
{
	vRtn = Vertex(-v.x, -v.y, -v.z);
}

void Vertex::Add(Vertex &vRtn, const Vertex &v1, const Vertex &v2)
{
	vRtn = Vertex(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

void Vertex::Sub(Vertex &vRtn, const Vertex &v1, const Vertex &v2)
{
	vRtn = Vertex(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}

void Vertex::Mul(Vertex &vRtn, const Vertex &v, const double &num)
{
	vRtn = Vertex(v.x * num, v.y * num, v.z * num);
}

bool Vertex::Div(Signal &sig, Vertex &vRtn, const Vertex &v, const double &num)
{
	if (num == 0) {
		Operator::SetError_DivideByZero(sig);
		return false;
	}
	vRtn = Vertex(v.x / num, v.y / num, v.z / num);
	return true;
}

void Vertex::Dot(double &rtn, const Vertex &v1, const Vertex &v2)
{
	rtn = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

void Vertex::Cross(Vertex &vRtn, const Vertex &v1, const Vertex &v2)
{
	double x = v1.y * v2.z - v1.z * v2.y;
	double y = v1.z * v2.x - v1.x * v2.z;
	double z = v1.x * v2.y - v1.y * v2.x;
	vRtn = Vertex(x, y, z);
}

void Vertex::Norm(double &rtn, const Vertex &v)
{
	rtn = ::sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

void Vertex::Normal(Vertex &vRtn, const Vertex &v1, const Vertex &v2, const Vertex &v3, bool unitFlag)
{
	double x1 = v2.x - v1.x, y1 = v2.y - v1.y, z1 = v2.z - v1.z;
	double x2 = v3.x - v1.x, y2 = v3.y - v1.y, z2 = v3.z - v1.z;
	double x = y1 * z2 - z1 * y2;
	double y = z1 * x2 - x1 * z2;
	double z = x1 * y2 - y1 * x2;
	if (!unitFlag) {
		vRtn = Vertex(x, y, z);
	} else {
		double len = ::sqrt(x * x + y * y + z * z);
		vRtn = (len == 0)? Vertex::Zero : Vertex(x / len, y / len, z / len);
	}
}

String Vertex::ToString() const
{
	String str;
	str += NumberToString(x);
	str += ",";
	str += NumberToString(y);
	str += ",";
	str += NumberToString(z);
	return str;
}

Vertex Vertex::CreateFromValues(Environment &env, const ValueList &valList)
{
	Signal &sig = env.GetSignal();
	if (valList.empty()) {
		Declaration::SetError_NotEnoughArguments(env);
		return Zero;
	}
	if (valList[0].Is_number()) {
		if (valList.size() < 2) {
			Declaration::SetError_NotEnoughArguments(env);
			return Zero;
		}
		if (!valList[0].MustBe_number(sig)) return Zero;
		if (!valList[1].MustBe_number(sig)) return Zero;
		if (valList.size() < 3) {
			return Vertex(valList[0].GetDouble(), valList[1].GetDouble());
		}
		if (!valList[2].MustBe_number(sig)) return Zero;
		if (valList.size() < 4) {
			return Vertex(valList[0].GetDouble(),
						  valList[1].GetDouble(), valList[2].GetDouble());
		}
		return Vertex(valList[0].GetDouble(), valList[1].GetDouble(),
					  valList[2].GetDouble(), valList[3].GetDouble());
	}
	Declaration::SetError_InvalidArgument(env);
	return Zero;
}

}
