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

bool Port::SMFPlay(Signal sig, Stream &stream)
{
	SMFReaderEx smfReader(this);
	return smfReader.Read(sig, stream);
}

//-----------------------------------------------------------------------------
// Port::Channel
//-----------------------------------------------------------------------------
void Port::Channel::OnMmlNote(unsigned char note, int length)
{
	_pPort->RawWrite(0x90 + GetChannel(), note, 0x7f);
	Gura::OAL::Sleep(.01 * length);
	_pPort->RawWrite(0x90 + GetChannel(), note, 0x00);
}

void Port::Channel::OnMmlRest(int length)
{
	::Sleep(.01 * length);
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
void Port::SMFReaderEx::OnMIDIEvent(unsigned long deltaTime, unsigned char data[], size_t length)
{
	::printf("%08x MIDIEvent %02x\n", deltaTime, data[0]);
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
