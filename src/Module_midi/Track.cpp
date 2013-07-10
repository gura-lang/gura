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

#if 0
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
#endif

unsigned long Track::GetPrevTimeStamp() const
{
	unsigned long timeStamp = 0;
	if (_pEventOwner->empty()) {
		// nothing to do
	} else if (_ppEventAt == _pEventOwner->begin()) {
		// nothing to do
	} else if (_ppEventAt == _pEventOwner->end()) {
		timeStamp = _pEventOwner->back()->GetTimeStamp();
	} else  {
		timeStamp = (*(_ppEventAt - 1))->GetTimeStamp();
	}
	return timeStamp;
}

void Track::AdjustFollowingTimeStamp(long deltaTime)
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
	pEvent->SetTimeStamp(GetPrevTimeStamp() + deltaTime);
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
	long idx = Tell();
	idx += offset;
	if (idx < 0 || idx > _pEventOwner->size()) {
		sig.SetError(ERR_OutOfRangeError, "offst is out of range");
		return false;
	}
	_ppEventAt = _pEventOwner->begin() + offset;
	return true;
}

long Track::Tell() const
{
	size_t n = (_ppEventAt == _pEventOwner->end())?
				_pEventOwner->size() : _ppEventAt - _pEventOwner->begin();
	return static_cast<long>(n);
}

bool Track::Erase(Signal sig, size_t cnt)
{
	if (cnt == 0) return true;
	size_t offset = Tell();
	if (offset + cnt > _pEventOwner->size()) {
		sig.SetError(ERR_OutOfRangeError, "offst is out of range");
		return false;
	}
	EventOwner::iterator ppEvent = _pEventOwner->begin() + offset;
	unsigned long timeStampBegin = (*ppEvent)->GetTimeStamp();
	for (size_t i = 0; i < cnt; i++) {
		Event *pEvent = *ppEvent;
		Event::Delete(pEvent);
		ppEvent = _pEventOwner->erase(ppEvent);
	}
	_ppEventAt = ppEvent;
	if (ppEvent != _pEventOwner->end()) {
		unsigned long timeStampTail = (*ppEvent)->GetTimeStamp();
		long deltaTime = timeStampTail - timeStampBegin;
		AdjustFollowingTimeStamp(-deltaTime);
	}
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
