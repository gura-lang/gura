#include "Track.h"
#include "Content.h"

Gura_BeginModule(midi)

//-----------------------------------------------------------------------------
// Track
//-----------------------------------------------------------------------------
Track::Track(Property *pProperty) : _cntRef(1),
				_pProperty(pProperty), _pEventOwner(new EventOwner())
{
	_ppEventAt = _pEventOwner->end();
}

bool Track::ParseMML(Signal sig, const char *str)
{
	if (_pMML.get() == NULL) {
		_pMML.reset(new MML(this, _pProperty->GetChannelNext()));
	}
	return _pMML->ParseString(sig, str);
}

void Track::AddEvent(Event *pEvent)
{
	_ppEventAt = _pEventOwner->insert(_ppEventAt, pEvent);
	_ppEventAt++;
}

bool Track::Seek(Signal sig, long offset)
{
	return true;
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
