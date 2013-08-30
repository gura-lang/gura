#ifndef __GURA_HELP_H__
#define __GURA_HELP_H__

#include "Common.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Help
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Help {
private:
	int _cntRef;
	const Symbol *_pSymbol;
	String _formatName;
	String _text;
public:
	Gura_DeclareReferenceAccessor(Help);
public:
	Help(const Symbol *pSymbol, const String &formatName, const String &text);
	inline const Symbol *GetSymbol() const { return _pSymbol; }
	inline const char *GetFormatName() const { return _formatName.c_str(); }
	inline const char *GetText() const { return _text.c_str(); }
};

//-----------------------------------------------------------------------------
// HelpList
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE HelpList : public std::vector<Help *> {
};

//-----------------------------------------------------------------------------
// HelpOwner
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE HelpOwner : public HelpList {
public:
	~HelpOwner();
	void Clear();
};

//-----------------------------------------------------------------------------
// HelpFormatter
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE HelpFormatter {
private:
	String _formatName;
public:
	HelpFormatter(const String &formatName);
	const char *GetFormatName() const { return _formatName.c_str(); }
	virtual bool DoFormat(Environment &env, Signal sig,
				SimpleStream &streamSrc, Stream &streamDst) const = 0;
public:
	static void Register(Environment &env, HelpFormatter *pHelpFormatter);
	static bool Format(Environment &env, Signal sig, const char *formatName,
						SimpleStream &streamSrc, Stream &streamDst);
	static bool Format(Environment &env, Signal sig, const char *formatName,
						const char *text, Stream &streamDst);
};

//-----------------------------------------------------------------------------
// HelpFormatterList
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE HelpFormatterList : public std::vector<HelpFormatter *> {
public:
	const HelpFormatter *FindByFormatName(const char *formatName) const;
};

//-----------------------------------------------------------------------------
// HelpFormatterOwner
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE HelpFormatterOwner : public HelpFormatterList {
public:
	~HelpFormatterOwner();
	void Clear();
};

}

#endif
