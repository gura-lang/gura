#include "Track.h"
#include "Content.h"

Gura_BeginModule(midi)

//-----------------------------------------------------------------------------
// Track
//-----------------------------------------------------------------------------
Track::Track(Property *pProperty) : _cntRef(1),
				_pProperty(pProperty), _pEventOwner(new EventOwner())
{
}

bool Track::ParseMML(Signal sig, const char *str)
{
	if (_pMML.get() == NULL) {
		_pMML.reset(new MML(this, _pProperty->GetChannelNext()));
	}
	return _pMML->ParseString(sig, str);
}

//-----------------------------------------------------------------------------
// TrackList
//-----------------------------------------------------------------------------

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
