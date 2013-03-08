#ifndef __GURA_OPTION_H__
#define __GURA_OPTION_H__

#include "Signal.h"
#include "String.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Option
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Option {
public:
	struct Info {
		const char *keyLong;
		char keyShort;
		bool needValueFlag;
	};
	typedef std::map<String, StringList *> Map;
private:
	Map _map;
	const Info *_infoTbl;
	int _cntInfo;
public:
	inline Option(const Info *infoTbl, int cntInfo) :
									_infoTbl(infoTbl), _cntInfo(cntInfo) {}
	~Option();
	bool Parse(int &argc, const char *argv[], String &strErr);
	bool IsSet(const char *key);
	const char *GetString(const char *key, const char *defValue) const;
	const StringList &GetStringList(const char *key) const;
	long GetLong(const char *key, long defValue) const;
private:
	const char *_GetString(const char *key) const;
};

}

#endif
