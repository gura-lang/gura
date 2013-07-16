// Audio

#include "stdafx.h"

namespace Gura {
//-----------------------------------------------------------------------------
// Audio
//-----------------------------------------------------------------------------
Audio::~Audio()
{
	FreeBuffer();
}

bool Audio::AllocBuffer(Signal sig, size_t len)
{
	FreeBuffer();
	_pMemory.reset(new MemoryHeap(_nChannels * len * GetBytesPerData()));
	_buff = reinterpret_cast<UChar *>(_pMemory->GetPointer());
	_len = len;
	return true;
}

void Audio::FreeBuffer()
{
	_pMemory.reset(NULL);
	_buff = NULL;
	_len = 0;
}

bool Audio::SetSineWave(Signal sig, size_t iChannel,
			size_t pitch, int phase, int amplitude, size_t offset, size_t len)
{
	const double PI2 = Math_PI * 2;
	int amplitudeMax =
		(_format == FORMAT_U8 || _format == FORMAT_S8)? 0x7f :
		(_format == FORMAT_U16LE || _format == FORMAT_S16LE ||
		 _format == FORMAT_U16BE || _format == FORMAT_S16BE)? 0x7fff : 0;
	if (iChannel >= _nChannels) {
		sig.SetError(ERR_ValueError, "channel is out of range");
		return false;
	}
	if (amplitude < 0) {
		amplitude = amplitudeMax;
	} else if (amplitude > amplitudeMax) {
		sig.SetError(ERR_ValueError, "amplitude is out of range");
		return false;
	}
	if (len > _len) len = _len;
	if (offset >= _len) return true;
	if (offset + len > _len) len = _len - offset;
	UChar *buffp = _buff + (offset * _nChannels + iChannel) * GetBytesPerData();
	size_t bytesPerUnit = GetBytesPerData() * _nChannels;
	for (size_t i = 0; i < len; i++) {
		int data = static_cast<int>(::sin(PI2 * (i + phase) / pitch) * amplitude);
		StoreData(buffp, data);
		buffp += bytesPerUnit;
	}
	return true;
}

Audio::Format Audio::SymbolToFormat(Signal sig, const Symbol *pSymbol)
{
	if (pSymbol->IsIdentical(Gura_Symbol(u8))) {
		return FORMAT_U8;
	} else if (pSymbol->IsIdentical(Gura_Symbol(s8))) {
		return FORMAT_S8;
	} else if (pSymbol->IsIdentical(Gura_Symbol(u16le))) {
		return FORMAT_U16LE;
	} else if (pSymbol->IsIdentical(Gura_Symbol(s16le))) {
		return FORMAT_S16LE;
	} else if (pSymbol->IsIdentical(Gura_Symbol(u16be))) {
		return FORMAT_U16BE;
	} else if (pSymbol->IsIdentical(Gura_Symbol(s16be))) {
		return FORMAT_S16BE;
	} else {
		sig.SetError(ERR_ValueError, "unsupported audio format '%s'", pSymbol->GetName());
		return FORMAT_None;
	}
}

const Symbol *Audio::FormatToSymbol(Format format)
{
	if (format == FORMAT_U8) {
		return Gura_Symbol(u8);
	} else if (format == FORMAT_S8) {
		return Gura_Symbol(s8);
	} else if (format == FORMAT_U16LE) {
		return Gura_Symbol(u16le);
	} else if (format == FORMAT_S16LE) {
		return Gura_Symbol(s16le);
	} else if (format == FORMAT_U16BE) {
		return Gura_Symbol(u16be);
	} else if (format == FORMAT_S16BE) {
		return Gura_Symbol(s16be);
	} else {
		return Gura_Symbol(nil);
	}
}

}
