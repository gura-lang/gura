#include <gura.h>
#include "MIDIHandle.h"

void MIDIHandle::MmlPlay(const char *mml)
{
	char ch = 0;
	MmlParser parser(this);
	parser.Parse(mml);
}

void MIDIHandle::MmlNote(MmlParser &parser, unsigned char note, int length)
{
	char ch = 0;
	RawWrite(0x90 + ch, note, 0x40);
	Gura::OAL::Sleep(.01 * length);
	RawWrite(0x90 + ch, note, 0x00);
}

void MIDIHandle::MmlRest(MmlParser &parser, int length)
{
	::Sleep(.01 * length);
}

void MIDIHandle::MmlVolume(MmlParser &parser, int volume)
{
}

void MIDIHandle::MmlTone(MmlParser &parser, int tone)
{
	char ch = 0;
	RawWrite(0xc0 + ch, static_cast<unsigned char>(tone));
}

void MIDIHandle::MmlTempo(MmlParser &parser, int tempo)
{
}
