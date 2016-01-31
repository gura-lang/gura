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
	return Zero;
}

}
