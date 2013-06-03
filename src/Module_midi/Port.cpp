#include <gura.h>
#include "Port.h"
#include "SMF.h"

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
	SMF smf;
	SMF::EventOwner eventOwner;
	if (!smf.Read(sig, stream, eventOwner)) return false;
	eventOwner.Sort();
	//::printf("format:%d num_track_chunks:%d division:%d\n",
	//				smf.GetFormat(), smf.GetNumTrackChunks(), smf.GetDivision());
	double deltaTimeUnit = .6 / smf.GetDivision();
	return eventOwner.Play(sig, this, deltaTimeUnit);
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

}}
