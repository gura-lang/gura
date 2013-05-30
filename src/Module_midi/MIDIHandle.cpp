#include <gura.h>
#include "MIDIHandle.h"

//-----------------------------------------------------------------------------
// MIDIHandle
//-----------------------------------------------------------------------------
MIDIHandle::MIDIHandle() : _hMIDI(NULL)
{
	for (char channel = 0; channel < NUM_CHANNELS; channel++) {
		_pChannels[channel] = new Channel(this, channel);
	}
}

MIDIHandle::~MIDIHandle()
{
	for (char channel = 0; channel < NUM_CHANNELS; channel++) {
		delete _pChannels[channel];
	}
	Reset();
	Close();
}

void MIDIHandle::MmlPlay(char channel, const char *mml)
{
	_pChannels[channel]->Parse(mml);
}

//-----------------------------------------------------------------------------
// MIDIHandle::Channel
//-----------------------------------------------------------------------------
void MIDIHandle::Channel::OnMmlNote(unsigned char note, int length)
{
	_pHandle->RawWrite(0x90 + GetChannel(), note, 0x7f);
	Gura::OAL::Sleep(.01 * length);
	_pHandle->RawWrite(0x90 + GetChannel(), note, 0x00);
}

void MIDIHandle::Channel::OnMmlRest(int length)
{
	::Sleep(.01 * length);
}

void MIDIHandle::Channel::OnMmlVolume(int volume)
{
}

void MIDIHandle::Channel::OnMmlTone(int tone)
{
	_pHandle->RawWrite(0xc0 + GetChannel(), static_cast<unsigned char>(tone));
}

void MIDIHandle::Channel::OnMmlTempo(int tempo)
{
}
