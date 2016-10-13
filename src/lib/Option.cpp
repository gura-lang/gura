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

Option &Option::AddInfo(const Info *infoTbl, int cntInfo)
{
	const Info *pInfo = infoTbl;
	for (int i = 0; i < cntInfo; i++, pInfo++) {
		_infoMapByKeyLong[pInfo->keyLong] = *pInfo;
		_infoMapByKeyShort[pInfo->keyShort] = *pInfo;
	}
	return *this;
}

bool Option::Parse(int &argc, const char *argv[], String &strErr)
{
	enum { STAT_Key, STAT_Value } stat = STAT_Key;
	const Info *pInfo = nullptr;
	const char *arg = "";
	for (int iArg = 1; iArg < argc; ) {
		arg = argv[iArg];
		if (stat == STAT_Key) {
			if (arg[0] != '-') {
				break;
			} else if (arg[1] == '-') {
				const char *keyLong = &arg[2];
#if 0
				pInfo = nullptr;
				for (int i = 0; i < cntInfo; i++) {
					if (::strcmp(infoTbl[i].keyLong, keyLong) == 0) {
						pInfo = &infoTbl[i];
						break;
					}
				}
#endif
				InfoMapByKeyLong::iterator iter = _infoMapByKeyLong.find(keyLong);
				pInfo = (iter == _infoMapByKeyLong.end())? nullptr : &iter->second;
				if (pInfo == nullptr) {
					strErr = "unknown option ";
					strErr += arg;
					return false;
				}
				if (pInfo->type == TYPE_Value) {
					stat = STAT_Value;
				} else {
					_map[pInfo->keyLong] = nullptr;
				}
			} else {
				char keyShort = arg[1];
				if (keyShort == '\0') {
					strErr = "invalid argument";
					return false;
				}
#if 0
				pInfo = nullptr;
				for (int i = 0; i < cntInfo; i++) {
					if (infoTbl[i].keyShort == keyShort) {
						pInfo = &infoTbl[i];
						break;
					}
				}
#endif
				InfoMapByKeyShort::iterator iter = _infoMapByKeyShort.find(keyShort);
				pInfo = (iter == _infoMapByKeyShort.end())? nullptr : &iter->second;
				if (pInfo == nullptr) {
					strErr = "unknown option ";
					strErr += arg;
					return false;
				}
				const char *value = &arg[2];
				if (pInfo->type == TYPE_Value) {
					if (value[0] == '\0') {
						stat = STAT_Value;
					} else {
						Map::iterator iter = _map.find(pInfo->keyLong);
						StringList *pStrList = nullptr;
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
					_map[pInfo->keyLong] = nullptr;
				}
			}
			argc--;
			for (int iArgTmp = iArg; iArgTmp < argc; iArgTmp++) {
				argv[iArgTmp] = argv[iArgTmp + 1];
			}
		} else if (stat == STAT_Value) {
			const char *value = arg;
			Map::iterator iter = _map.find(pInfo->keyLong);
			StringList *pStrList = nullptr;
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
	if (stat == STAT_Value) {
		strErr = "option ";
		strErr += arg;
		strErr += " requires a value";
		return false;
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
	return (valStr == nullptr)? defValue : valStr;
}

const StringList &Option::GetStringList(const char *key) const
{
	Map::const_iterator iter = _map.find(key);
	if (iter == _map.end()) return StringList::Empty;
	return *iter->second;
}

long Option::GetLong(const char *key, long defValue) const
{
	const char *valStr = _GetString(key);
	return (valStr == nullptr)? defValue : ::strtol(valStr, nullptr, 0);
}

const char *Option::_GetString(const char *key) const
{
	Map::const_iterator iter = _map.find(key);
	return (iter == _map.end())? nullptr : iter->second->front().c_str();
}

}
