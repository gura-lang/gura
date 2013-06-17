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

unsigned long Track::GetCurTimeStamp() const
{
	unsigned long timeStamp = 0;
	if (_pEventOwner->empty()) {
		// nothing to do
	} else if (_ppEventAt == _pEventOwner->end()) {
		timeStamp = _pEventOwner->back()->GetTimeStamp();
	} else  {
		timeStamp = (*_ppEventAt)->GetTimeStamp();
	}
	return timeStamp;
}

void Track::AdjustFollowingTimeStamp(unsigned long deltaTime)
{
	if (deltaTime == 0) return;
	for (EventOwner::iterator ppEventEach = _ppEventAt;
							ppEventEach != _pEventOwner->end(); ppEventEach++) {
		Event *pEventEach = *ppEventEach;
		pEventEach->SetTimeStamp(pEventEach->GetTimeStamp() + deltaTime);
	}
}

void Track::AddEvent(Event *pEvent, unsigned long deltaTime)
{
	pEvent->SetTimeStamp(GetCurTimeStamp() + deltaTime);
	_ppEventAt = _pEventOwner->insert(_ppEventAt, pEvent);
	_ppEventAt++;
	AdjustFollowingTimeStamp(deltaTime);
}

bool Track::SeekSet(Signal sig, long offset)
{
	if (offset < 0 || offset > _pEventOwner->size()) {
		sig.SetError(ERR_OutOfRangeError, "offst is out of range");
		return false;
	}
	_ppEventAt = _pEventOwner->begin() + offset;
	return true;
}

bool Track::SeekCur(Signal sig, long offset)
{
	long idx = (_ppEventAt == _pEventOwner->end())?
				_pEventOwner->size() : _ppEventAt - _pEventOwner->begin();
	idx += offset;
	if (idx < 0 || idx > _pEventOwner->size()) {
		sig.SetError(ERR_OutOfRangeError, "offst is out of range");
		return false;
	}
	_ppEventAt = _pEventOwner->begin() + offset;
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
