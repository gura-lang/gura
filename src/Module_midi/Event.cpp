#include "SMF.h"
#include "Port.h"

Gura_BeginModule(midi)

//-----------------------------------------------------------------------------
// Event
//-----------------------------------------------------------------------------
Event::~Event()
{
	// virtual destructor
}

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
		::printf("%08x %s\n", pEvent->GetTimeStamp(), pEvent->ToString().c_str());
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
		Event::Delete(pEvent);
	}
	clear();
}

//-----------------------------------------------------------------------------
// MIDIEvent
//-----------------------------------------------------------------------------
bool MIDIEvent::Play(Signal sig, Port *pPort) const
{
	if (_nParams == 1) {
		pPort->RawWrite(_status | _channel, _params[0]);
	} else {
		pPort->RawWrite(_status | _channel, _params[0], _params[1]);
	}
	return true;
}

bool MIDIEvent::Serialize(Signal sig, Stream &stream) const
{
	return false;
}

//-----------------------------------------------------------------------------
// MIDIEvent_NoteOff
//-----------------------------------------------------------------------------
String MIDIEvent_NoteOff::ToString() const
{
	char str[128];
	::sprintf(str, "NoteOff channel:%d note:%d velocity:%d", GetChannel(), _params[0], _params[1]);
	return String(str);
}

Event *MIDIEvent_NoteOff::Clone() const
{
	return new MIDIEvent_NoteOff(*this);
}

//-----------------------------------------------------------------------------
// MIDIEvent_NoteOn
//-----------------------------------------------------------------------------
String MIDIEvent_NoteOn::ToString() const
{
	char str[128];
	::sprintf(str, "NoteOn channel:%d note:%d velocity:%d", GetChannel(), _params[0], _params[1]);
	return String(str);
}

Event *MIDIEvent_NoteOn::Clone() const
{
	return new MIDIEvent_NoteOn(*this);
}

//-----------------------------------------------------------------------------
// MIDIEvent_PolyphonicKeyPressure
//-----------------------------------------------------------------------------
String MIDIEvent_PolyphonicKeyPressure::ToString() const
{
	char str[128];
	::sprintf(str, "PolyphonicKeyPressure channel:%d", GetChannel());
	return String(str);
}

Event *MIDIEvent_PolyphonicKeyPressure::Clone() const
{
	return new MIDIEvent_PolyphonicKeyPressure(*this);
}

//-----------------------------------------------------------------------------
// MIDIEvent_ControlChange
//-----------------------------------------------------------------------------
String MIDIEvent_ControlChange::ToString() const
{
	char str[128];
	::sprintf(str, "ControlChange channel:%d", GetChannel());
	return String(str);
}

Event *MIDIEvent_ControlChange::Clone() const
{
	return new MIDIEvent_ControlChange(*this);
}

//-----------------------------------------------------------------------------
// MIDIEvent_ProgramChange
//-----------------------------------------------------------------------------
String MIDIEvent_ProgramChange::ToString() const
{
	char str[128];
	::sprintf(str, "ProgramChange channel:%d", GetChannel());
	return String(str);
}

Event *MIDIEvent_ProgramChange::Clone() const
{
	return new MIDIEvent_ProgramChange(*this);
}

//-----------------------------------------------------------------------------
// MIDIEvent_ChannelPressure
//-----------------------------------------------------------------------------
String MIDIEvent_ChannelPressure::ToString() const
{
	char str[128];
	::sprintf(str, "ChannelPressure channel:%d", GetChannel());
	return String(str);
}

Event *MIDIEvent_ChannelPressure::Clone() const
{
	return new MIDIEvent_ChannelPressure(*this);
}

//-----------------------------------------------------------------------------
// MIDIEvent_PitchBendChange
//-----------------------------------------------------------------------------
String MIDIEvent_PitchBendChange::ToString() const
{
	char str[128];
	::sprintf(str, "PitchBendChange channel:%d", GetChannel());
	return String(str);
}

Event *MIDIEvent_PitchBendChange::Clone() const
{
	return new MIDIEvent_PitchBendChange(*this);
}

}}
