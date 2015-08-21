//=============================================================================
// Callable
//=============================================================================
#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// CallerInfo
//-----------------------------------------------------------------------------
const CallerInfo CallerInfo::Empty(ExprList::Empty, nullptr, nullptr, nullptr);

//-----------------------------------------------------------------------------
// Callable
//-----------------------------------------------------------------------------
bool Callable::IsLeader() const
{
	return false;
}

bool Callable::IsTrailer() const
{
	return false;
}

bool Callable::IsFinalizer() const
{
	return false;
}

bool Callable::IsEndMarker() const
{
	return false;
}

OccurPattern Callable::GetBlockOccurPattern() const
{
	return OCCUR_Zero;
}

}
