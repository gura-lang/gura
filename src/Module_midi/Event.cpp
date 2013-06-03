#include "SMF.h"
#include "Port.h"

Gura_BeginModule(midi)

//-----------------------------------------------------------------------------
// Event
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// EventList
//-----------------------------------------------------------------------------
void EventList::Sort()
{
	std::stable_sort(begin(), end(), Comparator_TimeStamp());
}

bool EventList::Play(Signal sig, Port *pPort, double deltaTimeUnit) const
{
	Event *pEventPrev = NULL;
	foreach_const (EventList, ppEvent, *this) {
		Event *pEvent = *ppEvent;
		if (pEventPrev != NULL &&
					pEventPrev->GetTimeStamp() < pEvent->GetTimeStamp()) {
			unsigned long deltaTime =
					pEvent->GetTimeStamp() - pEventPrev->GetTimeStamp();
			OAL::Sleep(deltaTimeUnit * deltaTime);
		}
		if (!pEvent->Play(sig, pPort)) return false;
		pEventPrev = pEvent;
	}
	return true;
}

//-----------------------------------------------------------------------------
// EventOwner
//-----------------------------------------------------------------------------
EventOwner::~EventOwner()
{
	Clear();
}

void EventOwner::Clear()
{
	foreach (EventOwner, ppEvent, *this) {
		Event *pEvent = *ppEvent;
		delete pEvent;
	}
	clear();
}

//-----------------------------------------------------------------------------
// MIDIEvent
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// MIDIEvent_NoteOff
//-----------------------------------------------------------------------------
bool MIDIEvent_NoteOff::Play(Signal sig, Port *pPort)
{
	pPort->RawWrite(_status | _channel, _params[0], _params[1]);
	return true;
}

//-----------------------------------------------------------------------------
// MIDIEvent_NoteOn
//-----------------------------------------------------------------------------
bool MIDIEvent_NoteOn::Play(Signal sig, Port *pPort)
{
	pPort->RawWrite(_status | _channel, _params[0], _params[1]);
	return true;
}

//-----------------------------------------------------------------------------
// MIDIEvent_PolyphonicKeyPressure
//-----------------------------------------------------------------------------
bool MIDIEvent_PolyphonicKeyPressure::Play(Signal sig, Port *pPort)
{
	pPort->RawWrite(_status | _channel, _params[0], _params[1]);
	return true;
}

//-----------------------------------------------------------------------------
// MIDIEvent_ControlChange
//-----------------------------------------------------------------------------
bool MIDIEvent_ControlChange::Play(Signal sig, Port *pPort)
{
	pPort->RawWrite(_status | _channel, _params[0], _params[1]);
	return true;
}

//-----------------------------------------------------------------------------
// MIDIEvent_ProgramChange
//-----------------------------------------------------------------------------
bool MIDIEvent_ProgramChange::Play(Signal sig, Port *pPort)
{
	pPort->RawWrite(_status | _channel, _params[0]);
	return true;
}

//-----------------------------------------------------------------------------
// MIDIEvent_ChannelPressure
//-----------------------------------------------------------------------------
bool MIDIEvent_ChannelPressure::Play(Signal sig, Port *pPort)
{
	pPort->RawWrite(_status | _channel, _params[0]);
	return true;
}

//-----------------------------------------------------------------------------
// MIDIEvent_PitchBendChange
//-----------------------------------------------------------------------------
bool MIDIEvent_PitchBendChange::Play(Signal sig, Port *pPort)
{
	pPort->RawWrite(_status | _channel, _params[0], _params[1]);
	return true;
}

}}
