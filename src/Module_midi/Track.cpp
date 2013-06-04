#include "Track.h"

Gura_BeginModule(midi)

//-----------------------------------------------------------------------------
// Track
//-----------------------------------------------------------------------------
bool Track::Write(Signal sig, Stream &stream) const
{
	ChunkTop chunkTop;
	::memcpy(chunkTop.MTrk, "MTrk", sizeof(chunkTop.MTrk));
	Gura_PackULong(chunkTop.length, 0);
	if (stream.Write(sig, &chunkTop, ChunkTop::Size) != ChunkTop::Size) {
		sig.SetError(ERR_FormatError, "failed to write SMF");
		return false;
	}
	return GetEventOwner().Write(sig, stream);
}

//-----------------------------------------------------------------------------
// TrackList
//-----------------------------------------------------------------------------
bool TrackList::Write(Signal sig, Stream &stream) const
{
	foreach_const (TrackList, ppTrack, *this) {
		const Track *pTrack = *ppTrack;
		if (!pTrack->Write(sig, stream)) return false;
	}
	return true;
}

//-----------------------------------------------------------------------------
// TrackOwner
//-----------------------------------------------------------------------------
TrackOwner::~TrackOwner()
{
	Clear();
}

void TrackOwner::Clear()
{
	foreach (TrackOwner, ppTrack, *this) {
		Track *pTrack = *ppTrack;
		Track::Delete(pTrack);
	}
	clear();
}

}}
