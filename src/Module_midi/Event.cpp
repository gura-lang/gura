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
bool MIDIEvent::Play(Signal sig, Port *pPort)
{
	if (_nParams == 1) {
		pPort->RawWrite(_status | _channel, _params[0]);
	} else {
		pPort->RawWrite(_status | _channel, _params[0], _params[1]);
	}
	return true;
}

//-----------------------------------------------------------------------------
// MIDIEvent_NoteOff
//-----------------------------------------------------------------------------
Event *MIDIEvent_NoteOff::Clone() const
{
	return new MIDIEvent_NoteOff(*this);
}

//-----------------------------------------------------------------------------
// MIDIEvent_NoteOn
//-----------------------------------------------------------------------------
Event *MIDIEvent_NoteOn::Clone() const
{
	return new MIDIEvent_NoteOn(*this);
}

//-----------------------------------------------------------------------------
// MIDIEvent_PolyphonicKeyPressure
//-----------------------------------------------------------------------------
Event *MIDIEvent_PolyphonicKeyPressure::Clone() const
{
	return new MIDIEvent_PolyphonicKeyPressure(*this);
}

//-----------------------------------------------------------------------------
// MIDIEvent_ControlChange
//-----------------------------------------------------------------------------
Event *MIDIEvent_ControlChange::Clone() const
{
	return new MIDIEvent_ControlChange(*this);
}

//-----------------------------------------------------------------------------
// MIDIEvent_ProgramChange
//-----------------------------------------------------------------------------
Event *MIDIEvent_ProgramChange::Clone() const
{
	return new MIDIEvent_ProgramChange(*this);
}

//-----------------------------------------------------------------------------
// MIDIEvent_ChannelPressure
//-----------------------------------------------------------------------------
Event *MIDIEvent_ChannelPressure::Clone() const
{
	return new MIDIEvent_ChannelPressure(*this);
}

//-----------------------------------------------------------------------------
// MIDIEvent_PitchBendChange
//-----------------------------------------------------------------------------
Event *MIDIEvent_PitchBendChange::Clone() const
{
	return new MIDIEvent_PitchBendChange(*this);
}

}}
