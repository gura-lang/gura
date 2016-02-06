//=============================================================================
// Gura module: model.obj
//=============================================================================
#ifndef __GURA_MODULE_MODEL_OBJ_H__
#define __GURA_MODULE_MODEL_OBJ_H__
#include <gura.h>

Gura_BeginModuleHeader(model_obj)

//-----------------------------------------------------------------------------
// TokenId
//-----------------------------------------------------------------------------
enum TokenId {
	TOKEN_None, TOKEN_EOL, TOKEN_EOF, TOKEN_Field,
};

//-----------------------------------------------------------------------------
// Tokenizer
//-----------------------------------------------------------------------------
class Tokenizer {
public:
	enum Stat {
		STAT_LineTop, STAT_SkipToNextLine, STAT_Field, STAT_SkipWhite, STAT_FileEnd,
	};
private:
	Stat _stat;
	size_t _iChar;
	char _field[128];
	TokenId _tokenIdPending;
public:
	inline Tokenizer() : _stat(STAT_LineTop), _iChar(0), _tokenIdPending(TOKEN_None) {}
	TokenId Tokenize(Environment &env, Stream &stream);
	inline const char *GetField() const { return _field; }
};

//-----------------------------------------------------------------------------
// Content
//-----------------------------------------------------------------------------
class Content {
public:
	bool Read(Environment &env, Stream &stream);
private:
	static bool ExtractInteger(const char *field, int *pNum);
	static bool ExtractFloat(const char *field, double *pNum);
	static bool ExtractTriplet(const char *field, int *piV, int *piVt, int *piVn);
};

//-----------------------------------------------------------------------------
// utilities
//-----------------------------------------------------------------------------
void SetError_FormatError(Environment &env);

Gura_EndModuleHeader(model_obj)

#endif
