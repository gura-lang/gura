// Palette

#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Palette
//-----------------------------------------------------------------------------
Palette::Palette() : _cntRef(1), _nEntries(0), _buff(NULL)
{
}

Palette::Palette(const Palette &palette) : _cntRef(1), _nEntries(palette._nEntries)
{
	size_t bytes = palette._pMemory->GetSize();
	_pMemory.reset(new MemoryHeap(bytes));
	_buff = reinterpret_cast<UChar *>(_pMemory->GetPointer());
	::memcpy(_buff, palette._buff, bytes);
}

Palette::~Palette()
{
}

void Palette::AllocBuff(size_t nEntries)
{
	_buff = NULL;
	_nEntries = nEntries;
	if (_nEntries > 0) {
		_pMemory.reset(new MemoryHeap(GetBuffSize()));
		_buff = reinterpret_cast<UChar *>(_pMemory->GetPointer());
		::memset(_buff, 0x00, GetBuffSize());
		for (size_t idx = 0; idx < nEntries; idx++) {
			GetEntry(idx)[Image::OffsetAlpha] = 0xff;
		}
	}
}

void Palette::ResizeBuff(size_t nEntries, size_t nEntriesToCopy)
{
	_nEntries = nEntries;
	size_t bytesToCopy = CalcBuffSize(nEntriesToCopy);
	AutoPtr<Memory> pMemory(new MemoryHeap(GetBuffSize()));
	UChar *buff = reinterpret_cast<UChar *>(pMemory->GetPointer());
	::memcpy(buff, _buff, bytesToCopy);
	::memset(buff + bytesToCopy, 0x00, GetBuffSize() - bytesToCopy);
	_buff = buff;
	_pMemory.reset(pMemory.release());
	for (size_t idx = nEntriesToCopy; idx < nEntries; idx++) {
		GetEntry(idx)[Image::OffsetAlpha] = 0xff;
	}
}

bool Palette::Prepare(Signal sig, const Symbol *pSymbol)
{
	size_t nEntries = 0;
	const UChar *rgb = NULL;
	if (pSymbol->IsIdentical(Gura_Symbol(mono))) {
		nEntries = 2, rgb = _rgb_Mono;
	} else if (pSymbol->IsIdentical(Gura_Symbol(basic))) {
		nEntries = 16, rgb = _rgb_Basic;
	} else if (pSymbol->IsIdentical(Gura_Symbol(win256))) {
		nEntries = 256, rgb = _rgb_Win256;
	} else if (pSymbol->IsIdentical(Gura_Symbol(websafe))) {
		nEntries = 256, rgb = _rgb_WebSafe;
	} else {
		sig.SetError(ERR_ValueError, "invalid palette symbol `%s", pSymbol->GetName());
		return false;
	}
	AllocBuff(nEntries);
	for (size_t idx = 0; idx < nEntries; idx++, rgb += 3) {
		SetEntry(idx, rgb[0], rgb[1], rgb[2]);
	}
	return true;
}

Value Palette::GetColorValue(Environment &env, size_t idx)
{
	const UChar *entry = GetEntry(idx);
	return Value(new Object_color(env,
		entry[Image::OffsetRed], entry[Image::OffsetGreen], entry[Image::OffsetBlue], entry[Image::OffsetAlpha]));
}

void Palette::SetColor(size_t idx, const Color &color)
{
	SetEntry(idx, color.GetRed(), color.GetGreen(), color.GetBlue(), color.GetAlpha());
}

size_t Palette::LookupNearest(UChar red, UChar green, UChar blue) const
{
	size_t idxMin = 0;
	const UChar *entry = _buff;
	size_t distMin = Color::CalcDistSqu(red, green, blue,
						entry[Image::OffsetRed], entry[Image::OffsetGreen], entry[Image::OffsetBlue]);
	if (distMin == 0) return idxMin;
	entry += 4;
	for (size_t idx = 1; idx < _nEntries; idx++, entry += 4) {
		size_t dist = Color::CalcDistSqu(red, green, blue,
						entry[Image::OffsetRed], entry[Image::OffsetGreen], entry[Image::OffsetBlue]);
		if (distMin > dist) {
			if (dist == 0) return idx;
			idxMin = idx, distMin = dist;
		}
	}
	return idxMin;
}

bool Palette::UpdateByImage(const Image *pImage, ShrinkMode shrinkMode)
{
	ColorSet colorSet;
	size_t idxBlank = NextBlankIndex(colorSet);
	size_t bytesPerPixel = pImage->GetBytesPerPixel();
	size_t bytesPerLine = pImage->GetBytesPerLine();
	const UChar *pLine = pImage->GetPointer(0);
	for (size_t y = 0; y < pImage->GetHeight(); y++) {
		const UChar *pPixel = pLine;
		for (size_t x = 0; x < pImage->GetWidth(); x++) {
			Color color(pPixel[Image::OffsetRed], pPixel[Image::OffsetGreen], pPixel[Image::OffsetBlue]);
			std::pair<ColorSet::iterator, bool> rtn = colorSet.insert(color);
			if (!rtn.second) {
				// nothing to do
			} else if (idxBlank < _nEntries) {
				SetEntry(idxBlank, color);
				idxBlank++;
			} else {
				return false;
			}
			pPixel += bytesPerPixel;
		}
		pLine += bytesPerLine;
	}
	if (shrinkMode != ShrinkNone) Shrink(idxBlank, shrinkMode == ShrinkAlign);
	return true;
}

bool Palette::UpdateByImage(Signal sig, const Image *pImage, ShrinkMode shrinkMode)
{
	if (UpdateByImage(pImage, shrinkMode)) return true;
	sig.SetError(ERR_ValueError,
				"number of palette elements exceeds maximum %d", _nEntries);
	return false;
}

bool Palette::UpdateByPalette(const Palette *pPalette, ShrinkMode shrinkMode)
{
	ColorSet colorSet;
	size_t idxBlank = NextBlankIndex(colorSet);
	for (size_t idx = 0; idx < pPalette->CountEntries(); idx++) {
		const UChar *pEntry = pPalette->GetEntry(idx);
		Color color(pEntry[Image::OffsetRed], pEntry[Image::OffsetGreen], pEntry[Image::OffsetBlue]);
		std::pair<ColorSet::iterator, bool> rtn = colorSet.insert(color);
		if (!rtn.second) {
		} else if (idxBlank < _nEntries) {
			SetEntry(idxBlank, color);
			idxBlank++;
		} else {
			return false;
		}
	}
	if (shrinkMode != ShrinkNone) Shrink(idxBlank, shrinkMode == ShrinkAlign);
	return true;
}

bool Palette::UpdateByPalette(Signal sig, const Palette *pPalette, ShrinkMode shrinkMode)
{
	if (UpdateByPalette(pPalette, shrinkMode)) return true;
	sig.SetError(ERR_ValueError,
				"number of palette elements exceeds maximum %d", _nEntries);
	return false;
}

void Palette::Shrink(size_t nEntries, bool alignFlag)
{
	if (!alignFlag) {
		ResizeBuff(nEntries, nEntries);
		return;
	}
	size_t nEntriesAligned = 1;
	for ( ; nEntries > nEntriesAligned; nEntriesAligned <<= 1) ;
	if (nEntriesAligned < _nEntries) ResizeBuff(nEntriesAligned, nEntries);
}

size_t Palette::NextBlankIndex() const
{
	ColorSet colorSet;
	return NextBlankIndex(colorSet);
}

size_t Palette::NextBlankIndex(ColorSet &colorSet) const
{
	size_t idxMax = 0;
	for (size_t idx = 0; idx < _nEntries; idx++) {
		const UChar *pEntry = GetEntry(idx);
		Color color(pEntry[Image::OffsetRed], pEntry[Image::OffsetGreen], pEntry[Image::OffsetBlue]);
		std::pair<ColorSet::iterator, bool> rtn = colorSet.insert(color);
		if (rtn.second) idxMax = idx;
	}
	return idxMax + 1;
}

const UChar Palette::_rgb_Mono[] = {
	0x00, 0x00, 0x00,	// 0: black
	0xff, 0xff, 0xff,	// 1: white
};

const UChar Palette::_rgb_Basic[] = {
	0x00, 0x00, 0x00,	// 0: black
	0x80, 0x00, 0x00,	// 1: maroon
	0x00, 0x80, 0x00,	// 2: green
	0x80, 0x80, 0x00,	// 3: olive
	0x00, 0x00, 0x80,	// 4: navy
	0x80, 0x00, 0x80,	// 5: purple
	0x00, 0x80, 0x80,	// 6: teal
	0x80, 0x80, 0x80,	// 7: gray
	0xc0, 0xc0, 0xc0,	// 8: silver
	0xff, 0x00, 0x00,	// 9: red
	0x00, 0xff, 0x00,	// 10: lime
	0xff, 0xff, 0x00,	// 11: yellow
	0x00, 0x00, 0xff,	// 12: blue
	0xff, 0x00, 0xff,	// 13: fuchsia
	0x00, 0xff, 0xff,	// 14: aqua
	0xff, 0xff, 0xff,	// 15: white
};

const UChar Palette::_rgb_Win256[] = {
	0x00, 0x00, 0x00,	// 0
	0x80, 0x00, 0x00,	// 1
	0x00, 0x80, 0x00,	// 2
	0x80, 0x80, 0x00,	// 3
	0x00, 0x00, 0x80,	// 4
	0x80, 0x00, 0x80,	// 5
	0x00, 0x80, 0x80,	// 6
	0xc0, 0xc0, 0xc0,	// 7
	0xc0, 0xdc, 0xc0,	// 8
	0xa6, 0xca, 0xf0,	// 9
	0x40, 0x20, 0x00,	// 10
	0x60, 0x20, 0x00,	// 11
	0x80, 0x20, 0x00,	// 12
	0xa0, 0x20, 0x00,	// 13
	0xc0, 0x20, 0x00,	// 14
	0xe0, 0x20, 0x00,	// 15
	0x00, 0x40, 0x00,	// 16
	0x20, 0x40, 0x00,	// 17
	0x40, 0x40, 0x00,	// 18
	0x60, 0x40, 0x00,	// 19
	0x80, 0x40, 0x00,	// 20
	0xa0, 0x40, 0x00,	// 21
	0xc0, 0x40, 0x00,	// 22
	0xe0, 0x40, 0x00,	// 23
	0x00, 0x60, 0x00,	// 24
	0x20, 0x60, 0x00,	// 25
	0x40, 0x60, 0x00,	// 26
	0x60, 0x60, 0x00,	// 27
	0x80, 0x60, 0x00,	// 28
	0xa0, 0x60, 0x00,	// 29
	0xc0, 0x60, 0x00,	// 30
	0xe0, 0x60, 0x00,	// 31
	0x00, 0x80, 0x00,	// 32
	0x20, 0x80, 0x00,	// 33
	0x40, 0x80, 0x00,	// 34
	0x60, 0x80, 0x00,	// 35
	0x80, 0x80, 0x00,	// 36
	0xa0, 0x80, 0x00,	// 37
	0xc0, 0x80, 0x00,	// 38
	0xe0, 0x80, 0x00,	// 39
	0x00, 0xa0, 0x00,	// 40
	0x20, 0xa0, 0x00,	// 41
	0x40, 0xa0, 0x00,	// 42
	0x60, 0xa0, 0x00,	// 43
	0x80, 0xa0, 0x00,	// 44
	0xa0, 0xa0, 0x00,	// 45
	0xc0, 0xa0, 0x00,	// 46
	0xe0, 0xa0, 0x00,	// 47
	0x00, 0xc0, 0x00,	// 48
	0x20, 0xc0, 0x00,	// 49
	0x40, 0xc0, 0x00,	// 50
	0x60, 0xc0, 0x00,	// 51
	0x80, 0xc0, 0x00,	// 52
	0xa0, 0xc0, 0x00,	// 53
	0xc0, 0xc0, 0x00,	// 54
	0xe0, 0xc0, 0x00,	// 55
	0x00, 0xe0, 0x00,	// 56
	0x20, 0xe0, 0x00,	// 57
	0x40, 0xe0, 0x00,	// 58
	0x60, 0xe0, 0x00,	// 59
	0x80, 0xe0, 0x00,	// 60
	0xa0, 0xe0, 0x00,	// 61
	0xc0, 0xe0, 0x00,	// 62
	0xe0, 0xe0, 0x00,	// 63
	0x00, 0x00, 0x40,	// 64
	0x20, 0x00, 0x40,	// 65
	0x40, 0x00, 0x40,	// 66
	0x60, 0x00, 0x40,	// 67
	0x80, 0x00, 0x40,	// 68
	0xa0, 0x00, 0x40,	// 69
	0xc0, 0x00, 0x40,	// 70
	0xe0, 0x00, 0x40,	// 71
	0x00, 0x20, 0x40,	// 72
	0x20, 0x20, 0x40,	// 73
	0x40, 0x20, 0x40,	// 74
	0x60, 0x20, 0x40,	// 75
	0x80, 0x20, 0x40,	// 76
	0xa0, 0x20, 0x40,	// 77
	0xc0, 0x20, 0x40,	// 78
	0xe0, 0x20, 0x40,	// 79
	0x00, 0x40, 0x40,	// 80
	0x20, 0x40, 0x40,	// 81
	0x40, 0x40, 0x40,	// 82
	0x60, 0x40, 0x40,	// 83
	0x80, 0x40, 0x40,	// 84
	0xa0, 0x40, 0x40,	// 85
	0xc0, 0x40, 0x40,	// 86
	0xe0, 0x40, 0x40,	// 87
	0x00, 0x60, 0x40,	// 88
	0x20, 0x60, 0x40,	// 89
	0x40, 0x60, 0x40,	// 90
	0x60, 0x60, 0x40,	// 91
	0x80, 0x60, 0x40,	// 92
	0xa0, 0x60, 0x40,	// 93
	0xc0, 0x60, 0x40,	// 94
	0xe0, 0x60, 0x40,	// 95
	0x00, 0x80, 0x40,	// 96
	0x20, 0x80, 0x40,	// 97
	0x40, 0x80, 0x40,	// 98
	0x60, 0x80, 0x40,	// 99
	0x80, 0x80, 0x40,	// 100
	0xa0, 0x80, 0x40,	// 101
	0xc0, 0x80, 0x40,	// 102
	0xe0, 0x80, 0x40,	// 103
	0x00, 0xa0, 0x40,	// 104
	0x20, 0xa0, 0x40,	// 105
	0x40, 0xa0, 0x40,	// 106
	0x60, 0xa0, 0x40,	// 107
	0x80, 0xa0, 0x40,	// 108
	0xa0, 0xa0, 0x40,	// 109
	0xc0, 0xa0, 0x40,	// 110
	0xe0, 0xa0, 0x40,	// 111
	0x00, 0xc0, 0x40,	// 112
	0x20, 0xc0, 0x40,	// 113
	0x40, 0xc0, 0x40,	// 114
	0x60, 0xc0, 0x40,	// 115
	0x80, 0xc0, 0x40,	// 116
	0xa0, 0xc0, 0x40,	// 117
	0xc0, 0xc0, 0x40,	// 118
	0xe0, 0xc0, 0x40,	// 119
	0x00, 0xe0, 0x40,	// 120
	0x20, 0xe0, 0x40,	// 121
	0x40, 0xe0, 0x40,	// 122
	0x60, 0xe0, 0x40,	// 123
	0x80, 0xe0, 0x40,	// 124
	0xa0, 0xe0, 0x40,	// 125
	0xc0, 0xe0, 0x40,	// 126
	0xe0, 0xe0, 0x40,	// 127
	0x00, 0x00, 0x80,	// 128
	0x20, 0x00, 0x80,	// 129
	0x40, 0x00, 0x80,	// 130
	0x60, 0x00, 0x80,	// 131
	0x80, 0x00, 0x80,	// 132
	0xa0, 0x00, 0x80,	// 133
	0xc0, 0x00, 0x80,	// 134
	0xe0, 0x00, 0x80,	// 135
	0x00, 0x20, 0x80,	// 136
	0x20, 0x20, 0x80,	// 137
	0x40, 0x20, 0x80,	// 138
	0x60, 0x20, 0x80,	// 139
	0x80, 0x20, 0x80,	// 140
	0xa0, 0x20, 0x80,	// 141
	0xc0, 0x20, 0x80,	// 142
	0xe0, 0x20, 0x80,	// 143
	0x00, 0x40, 0x80,	// 144
	0x20, 0x40, 0x80,	// 145
	0x40, 0x40, 0x80,	// 146
	0x60, 0x40, 0x80,	// 147
	0x80, 0x40, 0x80,	// 148
	0xa0, 0x40, 0x80,	// 149
	0xc0, 0x40, 0x80,	// 150
	0xe0, 0x40, 0x80,	// 151
	0x00, 0x60, 0x80,	// 152
	0x20, 0x60, 0x80,	// 153
	0x40, 0x60, 0x80,	// 154
	0x60, 0x60, 0x80,	// 155
	0x80, 0x60, 0x80,	// 156
	0xa0, 0x60, 0x80,	// 157
	0xc0, 0x60, 0x80,	// 158
	0xe0, 0x60, 0x80,	// 159
	0x00, 0x80, 0x80,	// 160
	0x20, 0x80, 0x80,	// 161
	0x40, 0x80, 0x80,	// 162
	0x60, 0x80, 0x80,	// 163
	0x80, 0x80, 0x80,	// 164
	0xa0, 0x80, 0x80,	// 165
	0xc0, 0x80, 0x80,	// 166
	0xe0, 0x80, 0x80,	// 167
	0x00, 0xa0, 0x80,	// 168
	0x20, 0xa0, 0x80,	// 169
	0x40, 0xa0, 0x80,	// 170
	0x60, 0xa0, 0x80,	// 171
	0x80, 0xa0, 0x80,	// 172
	0xa0, 0xa0, 0x80,	// 173
	0xc0, 0xa0, 0x80,	// 174
	0xe0, 0xa0, 0x80,	// 175
	0x00, 0xc0, 0x80,	// 176
	0x20, 0xc0, 0x80,	// 177
	0x40, 0xc0, 0x80,	// 178
	0x60, 0xc0, 0x80,	// 179
	0x80, 0xc0, 0x80,	// 180
	0xa0, 0xc0, 0x80,	// 181
	0xc0, 0xc0, 0x80,	// 182
	0xe0, 0xc0, 0x80,	// 183
	0x00, 0xe0, 0x80,	// 184
	0x20, 0xe0, 0x80,	// 185
	0x40, 0xe0, 0x80,	// 186
	0x60, 0xe0, 0x80,	// 187
	0x80, 0xe0, 0x80,	// 188
	0xa0, 0xe0, 0x80,	// 189
	0xc0, 0xe0, 0x80,	// 190
	0xe0, 0xe0, 0x80,	// 191
	0x00, 0x00, 0xc0,	// 192
	0x20, 0x00, 0xc0,	// 193
	0x40, 0x00, 0xc0,	// 194
	0x60, 0x00, 0xc0,	// 195
	0x80, 0x00, 0xc0,	// 196
	0xa0, 0x00, 0xc0,	// 197
	0xc0, 0x00, 0xc0,	// 198
	0xe0, 0x00, 0xc0,	// 199
	0x00, 0x20, 0xc0,	// 200
	0x20, 0x20, 0xc0,	// 201
	0x40, 0x20, 0xc0,	// 202
	0x60, 0x20, 0xc0,	// 203
	0x80, 0x20, 0xc0,	// 204
	0xa0, 0x20, 0xc0,	// 205
	0xc0, 0x20, 0xc0,	// 206
	0xe0, 0x20, 0xc0,	// 207
	0x00, 0x40, 0xc0,	// 208
	0x20, 0x40, 0xc0,	// 209
	0x40, 0x40, 0xc0,	// 210
	0x60, 0x40, 0xc0,	// 211
	0x80, 0x40, 0xc0,	// 212
	0xa0, 0x40, 0xc0,	// 213
	0xc0, 0x40, 0xc0,	// 214
	0xe0, 0x40, 0xc0,	// 215
	0x00, 0x60, 0xc0,	// 216
	0x20, 0x60, 0xc0,	// 217
	0x40, 0x60, 0xc0,	// 218
	0x60, 0x60, 0xc0,	// 219
	0x80, 0x60, 0xc0,	// 220
	0xa0, 0x60, 0xc0,	// 221
	0xc0, 0x60, 0xc0,	// 222
	0xe0, 0x60, 0xc0,	// 223
	0x00, 0x80, 0xc0,	// 224
	0x20, 0x80, 0xc0,	// 225
	0x40, 0x80, 0xc0,	// 226
	0x60, 0x80, 0xc0,	// 227
	0x80, 0x80, 0xc0,	// 228
	0xa0, 0x80, 0xc0,	// 229
	0xc0, 0x80, 0xc0,	// 230
	0xe0, 0x80, 0xc0,	// 231
	0x00, 0xa0, 0xc0,	// 232
	0x20, 0xa0, 0xc0,	// 233
	0x40, 0xa0, 0xc0,	// 234
	0x60, 0xa0, 0xc0,	// 235
	0x80, 0xa0, 0xc0,	// 236
	0xa0, 0xa0, 0xc0,	// 237
	0xc0, 0xa0, 0xc0,	// 238
	0xe0, 0xa0, 0xc0,	// 239
	0x00, 0xc0, 0xc0,	// 240
	0x20, 0xc0, 0xc0,	// 241
	0x40, 0xc0, 0xc0,	// 242
	0x60, 0xc0, 0xc0,	// 243
	0x80, 0xc0, 0xc0,	// 244
	0xa0, 0xc0, 0xc0,	// 245
	0xff, 0xfb, 0xf0,	// 246
	0xa0, 0xa0, 0xa4,	// 247
	0x80, 0x80, 0x80,	// 248
	0xff, 0x00, 0x00,	// 249
	0x00, 0xff, 0x00,	// 250
	0xff, 0xff, 0x00,	// 251
	0x00, 0x00, 0xff,	// 252
	0xff, 0x00, 0xff,	// 253
	0x00, 0xff, 0xff,	// 254
	0xff, 0xff, 0xff,	// 255
};

const UChar Palette::_rgb_WebSafe[] = {
	0x00, 0x00, 0x00,	// 0
	0x33, 0x00, 0x00,	// 1
	0x66, 0x00, 0x00,	// 2
	0x99, 0x00, 0x00,	// 3
	0xcc, 0x00, 0x00,	// 4
	0xff, 0x00, 0x00,	// 5
	0x00, 0x33, 0x00,	// 6
	0x33, 0x33, 0x00,	// 7
	0x66, 0x33, 0x00,	// 8
	0x99, 0x33, 0x00,	// 9
	0xcc, 0x33, 0x00,	// 10
	0xff, 0x33, 0x00,	// 11
	0x00, 0x66, 0x00,	// 12
	0x33, 0x66, 0x00,	// 13
	0x66, 0x66, 0x00,	// 14
	0x99, 0x66, 0x00,	// 15
	0xcc, 0x66, 0x00,	// 16
	0xff, 0x66, 0x00,	// 17
	0x00, 0x99, 0x00,	// 18
	0x33, 0x99, 0x00,	// 19
	0x66, 0x99, 0x00,	// 20
	0x99, 0x99, 0x00,	// 21
	0xcc, 0x99, 0x00,	// 22
	0xff, 0x99, 0x00,	// 23
	0x00, 0xcc, 0x00,	// 24
	0x33, 0xcc, 0x00,	// 25
	0x66, 0xcc, 0x00,	// 26
	0x99, 0xcc, 0x00,	// 27
	0xcc, 0xcc, 0x00,	// 28
	0xff, 0xcc, 0x00,	// 29
	0x00, 0xff, 0x00,	// 30
	0x33, 0xff, 0x00,	// 31
	0x66, 0xff, 0x00,	// 32
	0x99, 0xff, 0x00,	// 33
	0xcc, 0xff, 0x00,	// 34
	0xff, 0xff, 0x00,	// 35
	0x00, 0x00, 0x33,	// 36
	0x33, 0x00, 0x33,	// 37
	0x66, 0x00, 0x33,	// 38
	0x99, 0x00, 0x33,	// 39
	0xcc, 0x00, 0x33,	// 40
	0xff, 0x00, 0x33,	// 41
	0x00, 0x33, 0x33,	// 42
	0x33, 0x33, 0x33,	// 43
	0x66, 0x33, 0x33,	// 44
	0x99, 0x33, 0x33,	// 45
	0xcc, 0x33, 0x33,	// 46
	0xff, 0x33, 0x33,	// 47
	0x00, 0x66, 0x33,	// 48
	0x33, 0x66, 0x33,	// 49
	0x66, 0x66, 0x33,	// 50
	0x99, 0x66, 0x33,	// 51
	0xcc, 0x66, 0x33,	// 52
	0xff, 0x66, 0x33,	// 53
	0x00, 0x99, 0x33,	// 54
	0x33, 0x99, 0x33,	// 55
	0x66, 0x99, 0x33,	// 56
	0x99, 0x99, 0x33,	// 57
	0xcc, 0x99, 0x33,	// 58
	0xff, 0x99, 0x33,	// 59
	0x00, 0xcc, 0x33,	// 60
	0x33, 0xcc, 0x33,	// 61
	0x66, 0xcc, 0x33,	// 62
	0x99, 0xcc, 0x33,	// 63
	0xcc, 0xcc, 0x33,	// 64
	0xff, 0xcc, 0x33,	// 65
	0x00, 0xff, 0x33,	// 66
	0x33, 0xff, 0x33,	// 67
	0x66, 0xff, 0x33,	// 68
	0x99, 0xff, 0x33,	// 69
	0xcc, 0xff, 0x33,	// 70
	0xff, 0xff, 0x33,	// 71
	0x00, 0x00, 0x66,	// 72
	0x33, 0x00, 0x66,	// 73
	0x66, 0x00, 0x66,	// 74
	0x99, 0x00, 0x66,	// 75
	0xcc, 0x00, 0x66,	// 76
	0xff, 0x00, 0x66,	// 77
	0x00, 0x33, 0x66,	// 78
	0x33, 0x33, 0x66,	// 79
	0x66, 0x33, 0x66,	// 80
	0x99, 0x33, 0x66,	// 81
	0xcc, 0x33, 0x66,	// 82
	0xff, 0x33, 0x66,	// 83
	0x00, 0x66, 0x66,	// 84
	0x33, 0x66, 0x66,	// 85
	0x66, 0x66, 0x66,	// 86
	0x99, 0x66, 0x66,	// 87
	0xcc, 0x66, 0x66,	// 88
	0xff, 0x66, 0x66,	// 89
	0x00, 0x99, 0x66,	// 90
	0x33, 0x99, 0x66,	// 91
	0x66, 0x99, 0x66,	// 92
	0x99, 0x99, 0x66,	// 93
	0xcc, 0x99, 0x66,	// 94
	0xff, 0x99, 0x66,	// 95
	0x00, 0xcc, 0x66,	// 96
	0x33, 0xcc, 0x66,	// 97
	0x66, 0xcc, 0x66,	// 98
	0x99, 0xcc, 0x66,	// 99
	0xcc, 0xcc, 0x66,	// 100
	0xff, 0xcc, 0x66,	// 101
	0x00, 0xff, 0x66,	// 102
	0x33, 0xff, 0x66,	// 103
	0x66, 0xff, 0x66,	// 104
	0x99, 0xff, 0x66,	// 105
	0xcc, 0xff, 0x66,	// 106
	0xff, 0xff, 0x66,	// 107
	0x00, 0x00, 0x99,	// 108
	0x33, 0x00, 0x99,	// 109
	0x66, 0x00, 0x99,	// 110
	0x99, 0x00, 0x99,	// 111
	0xcc, 0x00, 0x99,	// 112
	0xff, 0x00, 0x99,	// 113
	0x00, 0x33, 0x99,	// 114
	0x33, 0x33, 0x99,	// 115
	0x66, 0x33, 0x99,	// 116
	0x99, 0x33, 0x99,	// 117
	0xcc, 0x33, 0x99,	// 118
	0xff, 0x33, 0x99,	// 119
	0x00, 0x66, 0x99,	// 120
	0x33, 0x66, 0x99,	// 121
	0x66, 0x66, 0x99,	// 122
	0x99, 0x66, 0x99,	// 123
	0xcc, 0x66, 0x99,	// 124
	0xff, 0x66, 0x99,	// 125
	0x00, 0x99, 0x99,	// 126
	0x33, 0x99, 0x99,	// 127
	0x66, 0x99, 0x99,	// 128
	0x99, 0x99, 0x99,	// 129
	0xcc, 0x99, 0x99,	// 130
	0xff, 0x99, 0x99,	// 131
	0x00, 0xcc, 0x99,	// 132
	0x33, 0xcc, 0x99,	// 133
	0x66, 0xcc, 0x99,	// 134
	0x99, 0xcc, 0x99,	// 135
	0xcc, 0xcc, 0x99,	// 136
	0xff, 0xcc, 0x99,	// 137
	0x00, 0xff, 0x99,	// 138
	0x33, 0xff, 0x99,	// 139
	0x66, 0xff, 0x99,	// 140
	0x99, 0xff, 0x99,	// 141
	0xcc, 0xff, 0x99,	// 142
	0xff, 0xff, 0x99,	// 143
	0x00, 0x00, 0xcc,	// 144
	0x33, 0x00, 0xcc,	// 145
	0x66, 0x00, 0xcc,	// 146
	0x99, 0x00, 0xcc,	// 147
	0xcc, 0x00, 0xcc,	// 148
	0xff, 0x00, 0xcc,	// 149
	0x00, 0x33, 0xcc,	// 150
	0x33, 0x33, 0xcc,	// 151
	0x66, 0x33, 0xcc,	// 152
	0x99, 0x33, 0xcc,	// 153
	0xcc, 0x33, 0xcc,	// 154
	0xff, 0x33, 0xcc,	// 155
	0x00, 0x66, 0xcc,	// 156
	0x33, 0x66, 0xcc,	// 157
	0x66, 0x66, 0xcc,	// 158
	0x99, 0x66, 0xcc,	// 159
	0xcc, 0x66, 0xcc,	// 160
	0xff, 0x66, 0xcc,	// 161
	0x00, 0x99, 0xcc,	// 162
	0x33, 0x99, 0xcc,	// 163
	0x66, 0x99, 0xcc,	// 164
	0x99, 0x99, 0xcc,	// 165
	0xcc, 0x99, 0xcc,	// 166
	0xff, 0x99, 0xcc,	// 167
	0x00, 0xcc, 0xcc,	// 168
	0x33, 0xcc, 0xcc,	// 169
	0x66, 0xcc, 0xcc,	// 170
	0x99, 0xcc, 0xcc,	// 171
	0xcc, 0xcc, 0xcc,	// 172
	0xff, 0xcc, 0xcc,	// 173
	0x00, 0xff, 0xcc,	// 174
	0x33, 0xff, 0xcc,	// 175
	0x66, 0xff, 0xcc,	// 176
	0x99, 0xff, 0xcc,	// 177
	0xcc, 0xff, 0xcc,	// 178
	0xff, 0xff, 0xcc,	// 179
	0x00, 0x00, 0xff,	// 180
	0x33, 0x00, 0xff,	// 181
	0x66, 0x00, 0xff,	// 182
	0x99, 0x00, 0xff,	// 183
	0xcc, 0x00, 0xff,	// 184
	0xff, 0x00, 0xff,	// 185
	0x00, 0x33, 0xff,	// 186
	0x33, 0x33, 0xff,	// 187
	0x66, 0x33, 0xff,	// 188
	0x99, 0x33, 0xff,	// 189
	0xcc, 0x33, 0xff,	// 190
	0xff, 0x33, 0xff,	// 191
	0x00, 0x66, 0xff,	// 192
	0x33, 0x66, 0xff,	// 193
	0x66, 0x66, 0xff,	// 194
	0x99, 0x66, 0xff,	// 195
	0xcc, 0x66, 0xff,	// 196
	0xff, 0x66, 0xff,	// 197
	0x00, 0x99, 0xff,	// 198
	0x33, 0x99, 0xff,	// 199
	0x66, 0x99, 0xff,	// 200
	0x99, 0x99, 0xff,	// 201
	0xcc, 0x99, 0xff,	// 202
	0xff, 0x99, 0xff,	// 203
	0x00, 0xcc, 0xff,	// 204
	0x33, 0xcc, 0xff,	// 205
	0x66, 0xcc, 0xff,	// 206
	0x99, 0xcc, 0xff,	// 207
	0xcc, 0xcc, 0xff,	// 208
	0xff, 0xcc, 0xff,	// 209
	0x00, 0xff, 0xff,	// 210
	0x33, 0xff, 0xff,	// 211
	0x66, 0xff, 0xff,	// 212
	0x99, 0xff, 0xff,	// 213
	0xcc, 0xff, 0xff,	// 214
	0xff, 0xff, 0xff,	// 215
	0x00, 0x00, 0x00,	// 216
	0x00, 0x00, 0x00,	// 217
	0x00, 0x00, 0x00,	// 218
	0x00, 0x00, 0x00,	// 219
	0x00, 0x00, 0x00,	// 220
	0x00, 0x00, 0x00,	// 221
	0x00, 0x00, 0x00,	// 222
	0x00, 0x00, 0x00,	// 223
	0x00, 0x00, 0x00,	// 224
	0x00, 0x00, 0x00,	// 225
	0x00, 0x00, 0x00,	// 226
	0x00, 0x00, 0x00,	// 227
	0x00, 0x00, 0x00,	// 228
	0x00, 0x00, 0x00,	// 229
	0x00, 0x00, 0x00,	// 230
	0x00, 0x00, 0x00,	// 231
	0x00, 0x00, 0x00,	// 232
	0x00, 0x00, 0x00,	// 233
	0x00, 0x00, 0x00,	// 234
	0x00, 0x00, 0x00,	// 235
	0x00, 0x00, 0x00,	// 236
	0x00, 0x00, 0x00,	// 237
	0x00, 0x00, 0x00,	// 238
	0x00, 0x00, 0x00,	// 239
	0x00, 0x00, 0x00,	// 240
	0x00, 0x00, 0x00,	// 241
	0x00, 0x00, 0x00,	// 242
	0x00, 0x00, 0x00,	// 243
	0x00, 0x00, 0x00,	// 244
	0x00, 0x00, 0x00,	// 245
	0x00, 0x00, 0x00,	// 246
	0x00, 0x00, 0x00,	// 247
	0x00, 0x00, 0x00,	// 248
	0x00, 0x00, 0x00,	// 249
	0x00, 0x00, 0x00,	// 250
	0x00, 0x00, 0x00,	// 251
	0x00, 0x00, 0x00,	// 252
	0x00, 0x00, 0x00,	// 253
	0x00, 0x00, 0x00,	// 254
	0x00, 0x00, 0x00,	// 255
};

//-----------------------------------------------------------------------------
// Palette::IteratorEach
//-----------------------------------------------------------------------------
Iterator *Palette::IteratorEach::GetSource()
{
	return NULL;
}

bool Palette::IteratorEach::DoNext(Environment &env, Signal sig, Value &value)
{
	if (_idx >= _pPalette->CountEntries()) return false;
	value = _pPalette->GetColorValue(env, _idx);
	_idx++;
	return true;
}

String Palette::IteratorEach::ToString(Signal sig) const
{
	return String("<iterator:palette#each>");
}

void Palette::IteratorEach::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

}
