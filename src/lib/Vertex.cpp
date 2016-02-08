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

Vertex Vertex::CalcNormal(const Vertex &v1, const Vertex &v2, const Vertex &v3, bool unitFlag)
{
	double x1 = v2.x - v1.x, y1 = v2.y - v1.y, z1 = v2.z - v1.z;
	double x2 = v3.x - v1.x, y2 = v3.y - v1.y, z2 = v3.z - v1.z;
	double x = y1 * z2 - z1 * y2;
	double y = z1 * x2 - x1 * z2;
	double z = x1 * y2 - y1 * x2;
	if (!unitFlag) return Vertex(x, y, z);
	double len = ::sqrt(x * x + y * y + z * z);
	if (len == 0) return Vertex::Zero;
	return Vertex(x / len, y / len, z / len);
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
