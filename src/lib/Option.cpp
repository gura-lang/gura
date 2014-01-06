//=============================================================================
// Option
//=============================================================================
#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Option
//-----------------------------------------------------------------------------
Option::~Option()
{
	foreach (Map, iter, _map) {
		delete iter->second;
	}
}

bool Option::Parse(int &argc, const char *argv[],
						const Info *infoTbl, int cntInfo, String &strErr)
{
	enum { STAT_Key, STAT_Value } stat = STAT_Key;
	const Info *pInfo = NULL;
	for (int iArg = 1; iArg < argc; ) {
		const char *arg = argv[iArg];
		if (stat == STAT_Key) {
			if (arg[0] != '-') {
				break;
			} else if (arg[1] == '-') {
				const char *keyLong = &arg[2];
				pInfo = NULL;
				for (int i = 0; i < cntInfo; i++) {
					if (::strcmp(infoTbl[i].keyLong, keyLong) == 0) {
						pInfo = &infoTbl[i];
						break;
					}
				}
				if (pInfo == NULL) {
					strErr = "unknown option ";
					strErr += arg;
					return false;
				}
				if (pInfo->needValueFlag) {
					stat = STAT_Value;
				} else {
					_map[pInfo->keyLong] = NULL;
				}
			} else {
				char keyShort = arg[1];
				if (keyShort == '\0') {
					strErr = "invalid argument";
					return false;
				}
				pInfo = NULL;
				for (int i = 0; i < cntInfo; i++) {
					if (infoTbl[i].keyShort == keyShort) {
						pInfo = &infoTbl[i];
						break;
					}
				}
				if (pInfo == NULL) {
					strErr = "unknown option ";
					strErr += arg;
					return false;
				}
				const char *value = &arg[2];
				if (pInfo->needValueFlag) {
					if (value[0] == '\0') {
						stat = STAT_Value;
					} else {
						Map::iterator iter = _map.find(pInfo->keyLong);
						StringList *pStrList = NULL;
						if (iter == _map.end()) {
							pStrList = new StringList();
							_map[pInfo->keyLong] = pStrList;
						} else {
							pStrList = iter->second;
						}
						pStrList->push_back(value);
					}
				} else {
					if (value[0] != '\0') {
						strErr = "unknown option ";
						strErr += arg;
						return false;
					}
					_map[pInfo->keyLong] = NULL;
				}
			}
			argc--;
			for (int iArgTmp = iArg; iArgTmp < argc; iArgTmp++) {
				argv[iArgTmp] = argv[iArgTmp + 1];
			}
		} else if (stat == STAT_Value) {
			const char *value = arg;
			Map::iterator iter = _map.find(pInfo->keyLong);
			StringList *pStrList = NULL;
			if (iter == _map.end()) {
				pStrList = new StringList();
				_map[pInfo->keyLong] = pStrList;
			} else {
				pStrList = iter->second;
			}
			pStrList->push_back(value);
			argc--;
			for (int iArgTmp = iArg; iArgTmp < argc; iArgTmp++) {
				argv[iArgTmp] = argv[iArgTmp + 1];
			}
			stat = STAT_Key;
		}
	}
	return true;
}

bool Option::IsSet(const char *key)
{
	return _map.find(key) != _map.end();
}

const char *Option::GetString(const char *key, const char *defValue) const
{
	const char *valStr = _GetString(key);
	return (valStr == NULL)? defValue : valStr;
}

const StringList &Option::GetStringList(const char *key) const
{
	Map::const_iterator iter = _map.find(key);
	if (iter == _map.end()) return StringList::Null;
	return *iter->second;
}

long Option::GetLong(const char *key, long defValue) const
{
	const char *valStr = _GetString(key);
	return (valStr == NULL)? defValue : ::strtol(valStr, NULL, 0);
}

const char *Option::_GetString(const char *key) const
{
	Map::const_iterator iter = _map.find(key);
	return (iter == _map.end())? NULL : iter->second->front().c_str();
}

}
