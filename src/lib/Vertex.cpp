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
// Vertex3
//-----------------------------------------------------------------------------
const Vertex3 Vertex3::Zero;

String Vertex3::ToString() const
{
	String str;
	str += NumberToString(x);
	str += ",";
	str += NumberToString(y);
	str += ",";
	str += NumberToString(z);
	return str;
}

//-----------------------------------------------------------------------------
// Vertex
//-----------------------------------------------------------------------------
const Vertex Vertex::Zero;

Vertex Vertex::Translate(double tx, double ty, double tz) const
{
	return Vertex(x + tx, y + ty, z + tz, w);
}

Vertex Vertex::RotateX(double rad) const
{
	double numCos = ::cos(rad), numSin = ::sin(rad);
	return Vertex(x, numCos * y - numSin * z, numSin * y + numCos * z, w);
}

Vertex Vertex::RotateY(double rad) const
{
	double numCos = ::cos(rad), numSin = ::sin(rad);
	return Vertex(numCos * x + numSin * z, y, -numSin * x + numCos * z, w);
}

Vertex Vertex::RotateZ(double rad) const
{
	double numCos = ::cos(rad), numSin = ::sin(rad);
	return Vertex(numCos * x - numSin * y, numSin * x + numCos * y, z, w);
}

String Vertex::ToString() const
{
	String str;
	str += NumberToString(x);
	str += ",";
	str += NumberToString(y);
	str += ",";
	str += NumberToString(z);
	str += ",";
	str += NumberToString(w);
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
