#include <gura.h>
#include "Port.h"

Gura_BeginModule(midi)


//-----------------------------------------------------------------------------
// Port
//-----------------------------------------------------------------------------
Port::Port() : _hMIDI(NULL)
{
	for (char channel = 0; channel < NUM_CHANNELS; channel++) {
		_pChannels[channel] = new Channel(this, channel);
	}
}

Port::~Port()
{
	for (char channel = 0; channel < NUM_CHANNELS; channel++) {
		delete _pChannels[channel];
	}
	Reset();
	Close();
}

void Port::MmlPlay(char channel, const char *mml)
{
	_pChannels[channel]->Parse(mml);
}

bool Port::Play(Signal sig, Stream &stream)
{
	SMFReaderEx smfReader;
	if (!smfReader.Read(sig, stream)) return false;
	smfReader.GetEventOwner().Sort();
	return smfReader.GetEventOwner().Exec(sig, this);
}

//-----------------------------------------------------------------------------
// Port::Event
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// EventList
//-----------------------------------------------------------------------------
void Port::EventList::Sort()
{
	std::stable_sort(begin(), end(), Comparator_TimeStamp());
}

bool Port::EventList::Exec(Signal sig, Port *pPort)
{
	Event *pEventPrev = NULL;
	foreach (EventList, ppEvent, *this) {
		Event *pEvent = *ppEvent;
		if (pEventPrev != NULL &&
					pEventPrev->GetTimeStamp() < pEvent->GetTimeStamp()) {
			unsigned long deltaTime =
					pEvent->GetTimeStamp() - pEventPrev->GetTimeStamp();
			OAL::Sleep(.005 * deltaTime);
		}
		if (!pEvent->Exec(sig, pPort)) return false;
		pEventPrev = pEvent;
	}
	return true;
}

//-----------------------------------------------------------------------------
// Port::EventOwner
//-----------------------------------------------------------------------------
Port::EventOwner::~EventOwner()
{
	Clear();
}

void Port::EventOwner::Clear()
{
	foreach (EventOwner, ppEvent, *this) {
		Event *pEvent = *ppEvent;
		delete pEvent;
	}
	clear();
}

//-----------------------------------------------------------------------------
// Port::MIDIEvent
//-----------------------------------------------------------------------------
bool Port::MIDIEvent::Exec(Signal sig, Port *pPort)
{
	pPort->RawWrite(_msg1, _msg2, _msg3);
	return true;
}

//-----------------------------------------------------------------------------
// Port::Channel
//-----------------------------------------------------------------------------
void Port::Channel::OnMmlNote(unsigned char note, int length)
{
	_pPort->RawWrite(0x90 + GetChannel(), note, 0x7f);
	OAL::Sleep(.01 * length);
	_pPort->RawWrite(0x90 + GetChannel(), note, 0x00);
}

void Port::Channel::OnMmlRest(int length)
{
	OAL::Sleep(.01 * length);
}

void Port::Channel::OnMmlVolume(int volume)
{
}

void Port::Channel::OnMmlTone(int tone)
{
	_pPort->RawWrite(0xc0 + GetChannel(), static_cast<unsigned char>(tone));
}

void Port::Channel::OnMmlTempo(int tempo)
{
}

//-----------------------------------------------------------------------------
// Port::SMFReaderEx
//-----------------------------------------------------------------------------
void Port::SMFReaderEx::OnMIDIEvent(unsigned long timeStamp, unsigned char msg1, unsigned char msg2)
{
	//::printf("%08x MIDIEvent %02x\n", timeStamp, msg1);
	_eventOwner.push_back(new MIDIEvent(timeStamp, msg1, msg2, 0x00));
}

void Port::SMFReaderEx::OnMIDIEvent(unsigned long timeStamp, unsigned char msg1, unsigned char msg2, unsigned char msg3)
{
	//::printf("%08x MIDIEvent %02x\n", timeStamp, msg1);
	_eventOwner.push_back(new MIDIEvent(timeStamp, msg1, msg2, msg3));
}

void Port::SMFReaderEx::OnSysExEvent(unsigned long deltaTime)
{
	::printf("%08x SysExEvent\n", deltaTime);
}

void Port::SMFReaderEx::OnMetaEvent(unsigned long deltaTime, unsigned char eventType, unsigned char data[], size_t length)
{
	::printf("%08x MetaEvent %02x\n", deltaTime, eventType);
}


}}
