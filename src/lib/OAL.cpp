//=============================================================================
// OAL: OS Abstraction Layer
//=============================================================================
#include "stdafx.h"

#if defined(GURA_ON_MSWIN)
#include <shlobj.h>
#if defined(_MSC_VER)
typedef int mode_t;
#define S_IRUSR 0x0100
#define S_IWUSR 0x0080
#define S_IXUSR 0x0040
#else
#include <sys/stat.h>
#endif
#define S_IRGRP 0x0020
#define S_IWGRP 0x0010
#define S_IXGRP 0x0008
#define S_IROTH 0x0004
#define S_IWOTH 0x0002
#define S_IXOTH 0x0001
#else
#include <unistd.h>
#include <dlfcn.h>
#include <pthread.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/types.h>
#endif

#if defined(GURA_ON_DARWIN)
#include <mach-o/dyld.h>
#endif

namespace Gura {
namespace OAL {

const char FileSeparatorWin = '\\';
const char FileSeparatorUnix = '/';

bool IsAbsPathName(const char *pathName)
{
	return IsFileSeparator(*pathName) ||
						(IsAlpha(*pathName) && *(pathName + 1) == ':');
}

String MakeAbsPathName(char chSeparator, const char *fileName, const char *dirNameBase)
{
	bool cutLastSepFlag = false;
	String pathName;
	if (IsAbsPathName(fileName)) {
		// nothing to do
	} else if (dirNameBase == NULL) {
		pathName += GetCurDir();
	} else {
		pathName += dirNameBase;
		if (pathName.empty() || !IsFileSeparator(pathName[pathName.size() - 1])) {
			pathName += FileSeparator;
		}
	}
	pathName += fileName;
	return RegulatePathName(chSeparator, pathName.c_str(), cutLastSepFlag);
}

String RegulatePathName(char chSeparator, const char *pathName, bool cutLastSepFlag)
{
	enum {
		STAT_Field, STAT_FileSeparator,
	} stat = STAT_Field;
	String prefix;
	char driveLetter = '\0';
	const char *p = pathName;
	if (IsAlpha(*p) && *(p + 1) == ':') {
		driveLetter = *p;
		p += 2;
		if (IsFileSeparator(*p)) {
			prefix += chSeparator;
			p++;
		}
		while (IsFileSeparator(*p)) p++;
	} else {
		while (IsFileSeparator(*p)) {
			prefix += chSeparator;
			p++;
		}
	}
	StringList fields;
	String field;
	bool sepTailFlag = false;
	for ( ; ; p++) {
		char ch = *p;
		bool continueFlag = false;
		do {
			continueFlag = false;
			switch (stat) {
			case STAT_Field: {
				if (IsFileSeparator(ch) || ch == '\0') {
					if (field == ".") {
						// nothing to do
					} else if (field == "..") {
						if (fields.empty()) {
							if (prefix.empty()) {
								fields.push_back(field);
							}
						} else if (fields.back() == "..") {
							fields.push_back(field);
						} else {
							fields.pop_back();
						}
					} else if (!field.empty()) {
						fields.push_back(field);
					}
					field.clear();
					stat = STAT_FileSeparator;
				} else {
					field += ch;
				}
				break;
			}
			case STAT_FileSeparator: {
				if (ch == '\0') {
					sepTailFlag = true;
				} else if (IsFileSeparator(ch)) {
					// nothing to do
				} else {
					continueFlag = true;
					stat = STAT_Field;
				}
				break;
			}
			}
		} while (continueFlag);
		if (ch == '\0') break;
	}
	String rtn;
	if (driveLetter != '\0') {
		rtn += driveLetter;
		rtn += ':';
	}
	rtn += prefix;
	foreach (StringList, pField, fields) {
		if (pField != fields.begin()) rtn += chSeparator;
		rtn += *pField;
	}
	if (sepTailFlag && !rtn.empty() && !IsFileSeparator(rtn[rtn.size() - 1])) {
		rtn += chSeparator;
	}
	return rtn;
}

String JoinPathName(char chSeparator, const char *pathName, const char *name)
{
	String rtn;
	for (const char *p = pathName; *p != '\0'; p++) {
		rtn += IsFileSeparator(*p)? chSeparator : *p;
	}
	if (*name == '\0') return rtn;
	if (!rtn.empty() && !IsFileSeparator(rtn[rtn.size() - 1])) {
		rtn += chSeparator;
	}
	do {
		const char *p = name;
		if (!rtn.empty() && IsFileSeparator(*p)) p++;
		for ( ; *p != '\0'; p++) {
			rtn += IsFileSeparator(*p)? chSeparator : *p;
		}
	} while (0);
	return rtn;
}

String JoinPathName(char chSeparator, const char *pathName, const char *name, size_t len)
{
	String rtn;
	for (const char *p = pathName; *p != '\0'; p++) {
		rtn += IsFileSeparator(*p)? chSeparator : *p;
	}
	if (*name == '\0' || len == 0) return rtn;
	if (!rtn.empty() && !IsFileSeparator(rtn[rtn.size() - 1])) {
		rtn += chSeparator;
	}
	do {
		const char *p = name;
		if (!rtn.empty() && IsFileSeparator(*p)) {
			p++, len--;
		}
		for ( ; *p != '\0' && len > 0; p++, len--) {
			rtn += IsFileSeparator(*p)? chSeparator : *p;
		}
	} while (0);
	return rtn;
}

String EliminateBottomDirName(const char *pathName)
{
	size_t len = ::strlen(pathName);
	if (len == 0) return String("");
	const char *pEnd = pathName + len;
	if (pathName < pEnd && IsFileSeparator(*(pEnd - 1))) {
		pEnd--;
	}
	if (pathName < pEnd) pEnd--;
	const char *pBegin = pEnd;
	for ( ; pathName < pBegin; pBegin--) {
		if (IsFileSeparator(*pBegin)) break;
	}
	return String(pathName, pBegin);
}

bool ParseStatMode(const char *mode, mode_t &st_mode)
{
	mode_t st_mode_r = 0, st_mode_w = 0, st_mode_x = 0;
	mode_t st_mode_mask = 0;
	enum {
		STAT_Target, STAT_ModeOp, STAT_Mode_Plus, STAT_Mode_Minus,
	} stat = STAT_Target;
	// state machine to parse regular expression: [ugoa]*([-+=]([rwxXst]*|[ugo]))+
	char ch = '\0';
	bool eatNextChar = true;
	for (const char *p = mode; *p != '\0'; ) {
		if (eatNextChar) ch = *p++;
		eatNextChar = true;
		if (stat == STAT_Target) {
			if (ch == 'u') {
				st_mode_r |= S_IRUSR;
				st_mode_w |= S_IWUSR;
				st_mode_x |= S_IXUSR;
				st_mode_mask |= S_IRUSR | S_IWUSR | S_IXUSR;
			} else if (ch == 'g') {
				st_mode_r |= S_IRGRP;
				st_mode_w |= S_IWGRP;
				st_mode_x |= S_IXGRP;
				st_mode_mask |= S_IRGRP | S_IWGRP | S_IXGRP;
			} else if (ch == 'o') {
				st_mode_r |= S_IROTH;
				st_mode_w |= S_IWOTH;
				st_mode_x |= S_IXOTH;
				st_mode_mask |= S_IROTH | S_IWOTH | S_IXOTH;
			} else if (ch == 'a') {
				st_mode_r |= S_IRUSR | S_IRGRP | S_IROTH;
				st_mode_w |= S_IWUSR | S_IWGRP | S_IWOTH;
				st_mode_x |= S_IXUSR | S_IXGRP | S_IXOTH;
				st_mode_mask |=
					S_IRUSR | S_IWUSR | S_IXUSR |
					S_IRGRP | S_IWGRP | S_IXGRP |
					S_IROTH | S_IWOTH | S_IXOTH;
			} else {
				if (st_mode_mask == 0) {
					st_mode_r |= S_IRUSR | S_IRGRP | S_IROTH;
					st_mode_w |= S_IWUSR | S_IWGRP | S_IWOTH;
					st_mode_x |= S_IXUSR | S_IXGRP | S_IXOTH;
					st_mode_mask |=
						S_IRUSR | S_IWUSR | S_IXUSR |
						S_IRGRP | S_IWGRP | S_IXGRP |
						S_IROTH | S_IWOTH | S_IXOTH;
				}
				eatNextChar = false;
				stat = STAT_ModeOp;
			}
		} else if (stat == STAT_ModeOp) {
			if (ch == '+') {
				stat = STAT_Mode_Plus;
			} else if (ch == '-') {
				stat = STAT_Mode_Minus;
			} else if (ch == '=') {
				st_mode &= ~st_mode_mask;
				stat = STAT_Mode_Plus;
			} else {
				return false;
			}
		} else if (stat == STAT_Mode_Plus) {
			if (ch == 'r') {
				st_mode |= st_mode_r;
			} else if (ch == 'w') {
				st_mode |= st_mode_w;
			} else if (ch == 'x') {
				st_mode |= st_mode_x;
			} else {
				eatNextChar = false;
				stat = STAT_ModeOp;
			}
		} else if (stat == STAT_Mode_Minus) {
			if (ch == 'r') {
				st_mode &= ~st_mode_r;
			} else if (ch == 'w') {
				st_mode &= ~st_mode_w;
			} else if (ch == 'x') {
				st_mode &= ~st_mode_x;
			} else {
				eatNextChar = false;
				stat = STAT_ModeOp;
			}
		}
	}
	return true;
}

bool CopyDir(const char *dirNameSrc, const char *dirNameDst)
{
	if (!MakeDirTree(dirNameDst)) return false;
	DirLister dirLister(dirNameSrc, false);
	bool dirFlag = false;
	String fileName;
	while (dirLister.Next(NULL, fileName, &dirFlag)) {
		if (dirFlag) continue;
		String pathNameSrc = JoinPathName(dirNameSrc, fileName.c_str());
		String pathNameDst = JoinPathName(dirNameDst, fileName.c_str());
		if (!Copy(pathNameSrc.c_str(), pathNameDst.c_str(), false)) return false;
	}
	return true;
}

bool CopyDirTree(const char *dirNameSrc, const char *dirNameDst)
{
	typedef std::list<String> RelNames;
	bool rtn = true;
	RelNames relNames;
	relNames.push_back("");
	foreach (RelNames, pRelNameIter, relNames) {
		const char *relNameIter = pRelNameIter->c_str();
		String dirNameIterSrc = JoinPathName(dirNameSrc, relNameIter);
		String dirNameIterDst = JoinPathName(dirNameDst, relNameIter);
		if (!MakeDirTree(dirNameIterDst.c_str())) return false;
		DirLister dirLister(dirNameIterSrc.c_str(), false);
		bool dirFlag = false;
		String fileName;
		while (dirLister.Next(NULL, fileName, &dirFlag)) {
			if (dirFlag) {
				String relName = JoinPathName(relNameIter, fileName.c_str());
				relNames.push_back(relName);
				continue;
			}
			String pathNameSrc = JoinPathName(dirNameIterSrc.c_str(), fileName.c_str());
			String pathNameDst = JoinPathName(dirNameIterDst.c_str(), fileName.c_str());
			if (!Copy(pathNameSrc.c_str(), pathNameDst.c_str(), false)) return false;
		}
	}
	return true;
}

bool MakeDirTree(const char *dirName)
{
	bool existFlag = false;
	if (IsDir(dirName, &existFlag)) return true;
	if (existFlag) return false;
	StringList dirNames;
	dirNames.push_back(dirName);
	String dirNameParent = EliminateBottomDirName(dirName);
	while (!dirNameParent.empty()) {
		if (IsDir(dirNameParent.c_str(), &existFlag)) break;
		if (existFlag) return false;
		dirNames.push_back(dirNameParent);
		dirNameParent = EliminateBottomDirName(dirNameParent.c_str());
	}
	foreach_reverse (StringList, pDirName, dirNames) {
		const String &dirName = *pDirName;
		if (!MakeDir(dirName.c_str())) return false;
	}
	return true;
}

bool RemoveDirTree(const char *dirName)
{
	typedef std::list<String> DirNames;
	bool rtn = true;
	DirNames dirNames;
	dirNames.push_back(dirName);
	foreach (DirNames, pDirNameIter, dirNames) {
		const char *dirNameIter = pDirNameIter->c_str();
		DirLister dirLister(dirNameIter);
		bool dirFlag = false;
		String pathName;
		while (dirLister.Next(NULL, pathName, &dirFlag)) {
			if (dirFlag) dirNames.push_back(pathName);
		}
	}
	foreach_reverse (DirNames, pDirNameIter, dirNames) {
		const char *dirNameIter = pDirNameIter->c_str();
		DirLister dirLister(dirNameIter);
		bool dirFlag = false;
		String pathName;
		while (dirLister.Next(NULL, pathName, &dirFlag)) {
			if (dirFlag) {
				// nothing to do
			} else if (!Remove(pathName.c_str())) {
				ChangeMode("u+w", pathName.c_str());
				if (!Remove(pathName.c_str())) rtn = false;
			}
		}
		if (!RemoveDir(dirNameIter)) {
			ChangeMode("u+w", dirNameIter);
			if (!RemoveDir(dirNameIter)) rtn = false;
		}
	}
	return rtn;
}

#if defined(GURA_ON_MSWIN)

const char *GetEncodingForConsole()
{
	UINT codePage = ::GetConsoleOutputCP();
	if (codePage == 0) codePage = ::GetACP();
	return
		(codePage == 1252)?		"iso-8859-1" :
		(codePage == 28592)?	"iso-8859-2" :
		(codePage == 1255)?		"iso-8859-8" :
		(codePage == 932)?		"shift_jis" :
		(codePage == 936)?		"gbk" :
		(codePage == 949)?		"euc-kr" :
		(codePage == 950)?		"big5" :
		(codePage == 65001)?	"utf-8" :
		"iso-8859-1";
}

const Symbol *GetLangCode()
{
	// http://www.loc.gov/standards/iso639-2/php/code_list.php
	UINT codePage = ::GetConsoleOutputCP();
	if (codePage == 0) codePage = ::GetACP();
	return
		(codePage == 1252)?		Gura_Symbol(en) :
		(codePage == 28592)?	Gura_Symbol(en) :
		(codePage == 1255)?		Gura_Symbol(en) :
		(codePage == 932)?		Gura_Symbol(ja) :
		(codePage == 936)?		Gura_Symbol(zh) :
		(codePage == 949)?		Gura_Symbol(ko) :
		(codePage == 950)?		Gura_Symbol(zh) :
		Gura_Symbol(en);
}

#else

const char *GetEncodingForConsole()
{
	const char *encodingDefault = "utf-8";
	struct AssocInfo {
		const char *key;
		const char *value;
	};
	String str = GetEnv("LANG");
	if (str.empty()) return encodingDefault;
	const char *strp = str.c_str();
	const char *p = ::strchr(strp, '.');
	String langLeft, langRight;
	if (p == NULL) {
		langLeft = strp;
	} else {
		langLeft = String(strp, p - strp);
		langRight = p + 1;
	}
	if (langRight.empty()) {
		static const AssocInfo assocInfoTbl[] = {
			{ "C",		"us-ascii"	},
			{ "en_US",	"us-ascii"	},
			{ "ja",	 	"euc-jp"	},
			{ "ja_JP",	"euc-jp"	},
			{ "zh_CN",	"gbk"		},	// CP936
			{ "ko_KR",	"euc-kr"	},	// CP949
			{ "zh_TW",	"big5"		},	// CP950
		};
		for (int i = 0; i < ArraySizeOf(assocInfoTbl); i++) {
			if (::strcasecmp(langLeft.c_str(), assocInfoTbl[i].key) == 0) {
				return assocInfoTbl[i].value;
			}
		}
	} else {
		static const AssocInfo assocInfoTbl[] = {
			{ "eucJP",	"euc-jp"	},
			{ "ujis",	"euc-jp"	},
			{ "utf-8",	"utf-8"		},
			{ "utf8",	"utf-8"		},
			{ "utf-16",	"utf-16"	},
			{ "utf16",	"utf-16"	},
			{ "SJIS",	"shift_jis"	},	// CP932
			{ "gbk",	"gbk"		},	// CP936
			{ "eucKR",	"euc-kr"	},	// CP949
			{ "big5",	"big5"		},	// CP950
		};
		for (int i = 0; i < ArraySizeOf(assocInfoTbl); i++) {
			if (::strcasecmp(langRight.c_str(), assocInfoTbl[i].key) == 0) {
				return assocInfoTbl[i].value;
			}
		}
	}
	return encodingDefault;
}

#if 0

const Symbol *GetLangCode()
{
	struct AssocInfo {
		const char *key;
		const char *value;
	};
	static const AssocInfo assocInfoTbl[] = {
		{ "0",		"en"	},
		{ "3",		"de"	},
		{ "14",		"ja"	},
	};
	String dirName = GetEnv("HOME");
	String fileName = JoinPathName(dirName.c_str(), ".CFUserTextEncoding");
	FILE *fp = ::fopen(fileName.c_str(), "rt");
	if (fp != NULL) {
		char buff[256];
		::fgets(buff, sizeof(buff) - 1, fp);
		::fclose(fp);
		String strLine = Strip(buff);
		const char *code = ::strchr(strLine.c_str(), ':');
		if (code != NULL) {
			code++;
			for (int i = 0; i < ArraySizeOf(assocInfoTbl); i++) {
				if (::strcmp(code, assocInfoTbl[i].key) == 0) {
					return Symbol::Add(assocInfoTbl[i].value);
				}
			}
		}
	}
	return Gura_Symbol(en);
}

#else

const Symbol *GetLangCode()
{
	String str = GetEnv("LANG");
	const char *strp = str.c_str();
	const char *p = strp;
	while (*p != '\0' && *p != '_' && *p != '.') p++;
	String lang = String(strp, p - strp);
	if (lang.empty() || lang == "C") {
		lang = "en";
	}
	return Symbol::Add(lang.c_str());
}

#endif

#endif

static void AppendCmdLine(String &cmdLine, const char *arg)
{
	bool quoteFlag = (::strchr(arg, ' ') != NULL);
	if (quoteFlag) {
		cmdLine += '"';
		cmdLine += arg;
		cmdLine += '"';
	} else {
		cmdLine += arg;
	}
}

#if defined(GURA_ON_MSWIN)
//=============================================================================
// Windows API
//=============================================================================
const char FileSeparator = '\\';
const bool IgnoreCaseInPathNameFlag = true;

int ExecProgram(Environment &env, Signal sig, const char *pathName,
				const ValueList &valList, Stream *pStreamStdin,
				Stream *pStreamStdout, Stream *pStreamStderr, bool forkFlag)
{
	String cmdLine;
	AppendCmdLine(cmdLine, ToNativeString(pathName).c_str());
	foreach_const (ValueList, pValue, valList) {
		cmdLine += " ";
		AppendCmdLine(cmdLine, ToNativeString(pValue->GetString()).c_str());
	}
	if (forkFlag) {
		STARTUPINFO si;
		PROCESS_INFORMATION ps;
		::memset(&si, 0x00, sizeof(si));
		si.cb = sizeof(STARTUPINFO);
		si.dwFlags = STARTF_USESTDHANDLES;
		si.hStdInput = ::GetStdHandle(STD_INPUT_HANDLE);
		si.hStdOutput = ::GetStdHandle(STD_OUTPUT_HANDLE);
		si.hStdError = ::GetStdHandle(STD_ERROR_HANDLE);
		BOOL rtn = ::CreateProcess(NULL, const_cast<char *>(cmdLine.c_str()),
								   NULL, NULL, TRUE, 0, NULL, NULL, &si, &ps);
		if (!rtn) {
			sig.SetError(ERR_IOError, "failed to execute %s", pathName);
			return -1;
		}
		return 0;
	}
	HANDLE hStdout = INVALID_HANDLE_VALUE;
	HANDLE hStderr = INVALID_HANDLE_VALUE;
	HANDLE hStdoutWatch = INVALID_HANDLE_VALUE;
	HANDLE hStderrWatch = INVALID_HANDLE_VALUE;
	do {
		SECURITY_ATTRIBUTES sa;
		::memset(&sa, 0x00, sizeof(sa));
		sa.nLength = sizeof(sa);
		sa.lpSecurityDescriptor = NULL;
		sa.bInheritHandle = TRUE;
		if (pStreamStdout != NULL && !::CreatePipe(&hStdoutWatch, &hStdout, &sa, 0)) {
			sig.SetError(ERR_IOError, "failed to create a pipe");
			return -1;
		}
		if (pStreamStderr != NULL && !::CreatePipe(&hStderrWatch, &hStderr, &sa, 0)) {
			sig.SetError(ERR_IOError, "failed to create a pipe");
			return -1;
		}
	} while (0);
	STARTUPINFO si;
	PROCESS_INFORMATION ps;
	::memset(&si, 0x00, sizeof(si));
	si.cb = sizeof(STARTUPINFO);
	si.dwFlags = STARTF_USESTDHANDLES;
	si.hStdInput = ::GetStdHandle(STD_INPUT_HANDLE);
	si.hStdOutput = hStdout;
	si.hStdError = hStderr;
	BOOL rtn = ::CreateProcess(NULL, const_cast<char *>(cmdLine.c_str()),
							NULL, NULL, TRUE, 0, NULL, NULL, &si, &ps);
	if (!rtn) {
		sig.SetError(ERR_IOError, "failed to execute %s", pathName);
		return -1;
	}
	::WaitForInputIdle(ps.hProcess, INFINITE);
	AutoPtr<Memory> pMemory(new MemoryHeap(32768));
	DWORD exitCode = 0;
	for (;;) {
		bool dataAvailFlag = false;
		if (pStreamStdout != NULL) {
			DWORD bytesAvail;
			::PeekNamedPipe(hStdoutWatch, NULL, NULL, NULL, &bytesAvail, NULL);
			if (bytesAvail > 0) {
				dataAvailFlag = true;
				char *buff = reinterpret_cast<char *>(pMemory->GetPointer());
				DWORD bytesRead;
				::ReadFile(hStdoutWatch, buff,
							static_cast<DWORD>(pMemory->GetSize()), &bytesRead, NULL);
				pStreamStdout->Write(sig, buff, bytesRead);
			}
		}
		if (pStreamStderr != NULL) {
			DWORD bytesAvail;
			::PeekNamedPipe(hStderrWatch, NULL, NULL, NULL, &bytesAvail, NULL);
			if (bytesAvail > 0) {
				dataAvailFlag = true;
				char *buff = reinterpret_cast<char *>(pMemory->GetPointer());
				DWORD bytesRead;
				::ReadFile(hStderrWatch, buff,
							static_cast<DWORD>(pMemory->GetSize()), &bytesRead, NULL);
				pStreamStderr->Write(sig, buff, bytesRead);
			}
		}
		if (!dataAvailFlag) {
			::GetExitCodeProcess(ps.hProcess, &exitCode);
			if (exitCode != STILL_ACTIVE) break;
			::Sleep(100);
		}
	}
	::CloseHandle(ps.hProcess);
	::CloseHandle(ps.hThread);
	::CloseHandle(hStdout);
	::CloseHandle(hStderr);
	::CloseHandle(hStdoutWatch);
	::CloseHandle(hStderrWatch);
	return static_cast<int>(exitCode);
}

String GetEnv(const char *name, bool *pFoundFlag)
{
	String nameEnc = ToNativeString(name);
	DWORD len = ::GetEnvironmentVariable(nameEnc.c_str(), NULL, 0);
	if (len == 0) {
		if (pFoundFlag != NULL) *pFoundFlag = false;
		return String("");
	}
	char *buff = new char [len];
	::GetEnvironmentVariable(nameEnc.c_str(), buff, len);
	String rtn(FromNativeString(buff));
	delete[] buff;
	if (pFoundFlag != NULL) *pFoundFlag = true;
	return rtn;
}

void PutEnv(const char *name, const char *value)
{
	::SetEnvironmentVariable(ToNativeString(name).c_str(), ToNativeString(value).c_str());
}

void UnsetEnv(const char *name)
{
	::SetEnvironmentVariable(ToNativeString(name).c_str(), NULL);
}

bool Copy(const char *src, const char *dst, bool failIfExistsFlag)
{
	String srcNative = ToNativeString(src);
	String dstNative = ToNativeString(dst);
	return ::CopyFile(srcNative.c_str(), dstNative.c_str(), failIfExistsFlag)? true : false;
}

bool Rename(const char *src, const char *dst)
{
	return ::MoveFileEx(ToNativeString(src).c_str(), ToNativeString(dst).c_str(),
									MOVEFILE_REPLACE_EXISTING)? true : false;
}

bool Remove(const char *pathName)
{
	return ::DeleteFile(ToNativeString(pathName).c_str())? true : false;
}

bool DoesExist(const char *pathName)
{
	WIN32_FILE_ATTRIBUTE_DATA attrData;
	return ::GetFileAttributesEx(ToNativeString(pathName).c_str(),
									GetFileExInfoStandard, &attrData) != 0;
}

bool IsDir(const char *pathName, bool *pExistFlag)
{
	WIN32_FILE_ATTRIBUTE_DATA attrData;
	bool existFlag = (::GetFileAttributesEx(ToNativeString(pathName).c_str(),
										GetFileExInfoStandard, &attrData) != 0);
	if (pExistFlag != NULL) *pExistFlag = existFlag;
	if (!existFlag) return false;
	return (attrData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) != 0;
}

bool MakeDir(const char *pathName)
{
	return ::CreateDirectory(ToNativeString(pathName).c_str(), NULL)? true : false;
}

bool RemoveDir(const char *pathName)
{
	return ::RemoveDirectory(ToNativeString(pathName).c_str())? true : false;
}

bool ChangeCurDir(const char *pathName)
{
	return ::SetCurrentDirectory(ToNativeString(pathName).c_str())? true : false;
}

String GetCurDir()
{
	char pathName[MAX_PATH];
	::GetCurrentDirectory(MAX_PATH, pathName);
	String rtn = FromNativeString(pathName);
	if (rtn.empty() || !IsFileSeparator(rtn[rtn.size() - 1])) {
		rtn += FileSeparator;
	}
	return rtn;
}

bool ChangeMode(int modeOct, const char *pathName)
{
	String pathNameEnc = ToNativeString(pathName);
	DWORD dwFileAttrs = ::GetFileAttributes(pathNameEnc.c_str()) &
													~FILE_ATTRIBUTE_READONLY;
	if (!(modeOct & 0222)) dwFileAttrs |= FILE_ATTRIBUTE_READONLY;
	return ::SetFileAttributes(pathNameEnc.c_str(), dwFileAttrs)? true : false;
}

bool ChangeMode(const char *mode, const char *pathName)
{
	String pathNameEnc = ToNativeString(pathName);
	DWORD dwFileAttrs = ::GetFileAttributes(pathNameEnc.c_str());
	mode_t st_mode = (dwFileAttrs & FILE_ATTRIBUTE_READONLY)? 0 : 0222;
	if (!ParseStatMode(mode, st_mode)) return false;
	dwFileAttrs &= ~FILE_ATTRIBUTE_READONLY;
	if (!(st_mode & 0222)) dwFileAttrs |= FILE_ATTRIBUTE_READONLY;
	return ::SetFileAttributes(pathNameEnc.c_str(), dwFileAttrs)? true : false;
}

void Sleep(Number delay)	// unit: sec
{
	::Sleep(static_cast<long>(delay * 1000));	// unit: msec
}

Number GetTickTime()
{
	LARGE_INTEGER freq, counter;
	if (::QueryPerformanceFrequency(&freq) && ::QueryPerformanceCounter(&counter)) {
		return static_cast<Number>(counter.QuadPart) / freq.QuadPart;
	} else {
		return static_cast<Number>(::GetTickCount()) / 1000;
	}
}

DateTime GetCurDateTime(bool utcFlag)
{
	SYSTEMTIME st;
	DateTime dateTime;
	if (utcFlag) {
		::GetSystemTime(&st);
		dateTime = ToDateTime(st, 0);
	} else {
		::GetLocalTime(&st);
		dateTime = ToDateTime(st, GetSecsOffsetTZ());
	}
	return dateTime;
}

DateTime ToDateTime(const SYSTEMTIME &st, int secsOffset)
{
	return DateTime(
		static_cast<short>(st.wYear),
		static_cast<char>(st.wMonth),
		static_cast<char>(st.wDay),
		static_cast<long>(st.wHour) * 3600 +
					static_cast<long>(st.wMinute) * 60 + st.wSecond,
		static_cast<long>(st.wMilliseconds) * 1000, secsOffset);
}

DateTime ToDateTime(const FILETIME &ft, bool utcFlag)
{
	SYSTEMTIME stUTC;
	::FileTimeToSystemTime(&ft, &stUTC);
	if (!utcFlag) {
		SYSTEMTIME stLocal;
		::SystemTimeToTzSpecificLocalTime(NULL, &stUTC, &stLocal);
		return ToDateTime(stLocal, GetSecsOffsetTZ());
	}
	return ToDateTime(stUTC, 0);
}

SYSTEMTIME ToSYSTEMTIME(const DateTime &dt)
{
	SYSTEMTIME st;
	st.wYear			= dt.GetYear();
	st.wMonth			= dt.GetMonth();
	st.wDayOfWeek		= dt.GetDayOfWeek();
	st.wDay				= dt.GetDay();
	st.wHour			= dt.GetHour();
	st.wMinute			= dt.GetMin();
	st.wSecond			= dt.GetSec();
	st.wMilliseconds	= static_cast<WORD>(dt.GetUSec() / 1000);
	return st;
}

FILETIME ToFILETIME(const DateTime &dt)
{
	SYSTEMTIME st = ToSYSTEMTIME(dt);
	FILETIME ftLocal, ft;
	::SystemTimeToFileTime(&st, &ftLocal);
	::LocalFileTimeToFileTime(&ftLocal, &ft);
	return ft;
}

int GetSecsOffsetTZ()
{
	TIME_ZONE_INFORMATION tzInfo;
	if (::GetTimeZoneInformation(&tzInfo) == TIME_ZONE_ID_INVALID) return 0;
	return -tzInfo.Bias * 60;
}

static HMODULE g_hModule = NULL;

void SetModuleHandle(HMODULE hModule)
{
	g_hModule = hModule;
}

String GetExecutable()
{
	char pathName[512];
	::GetModuleFileName(NULL, pathName, ArraySizeOf(pathName)); // Win32 API
	return FromNativeString(pathName);
}

String GetBaseDir()
{
	do {
		String dirBase = GetEnv("GURADIR");
		if (!dirBase.empty()) return FromNativeString(dirBase.c_str());
	} while (0);
	char pathName[1024];
	::GetModuleFileName(g_hModule, pathName, ArraySizeOf(pathName)); // Win32 API
	char *p = pathName + ::strlen(pathName);
	for ( ; p >= pathName; p--) {
		if (*p == '\\') {
			*p = '\0';
			break;
		}
	}
	if (p > pathName) p--;
	for ( ; p >= pathName; p--) {
		if (*p == '\\') {
			*p = '\0';
			break;
		}
	}
	return FromNativeString(pathName);
}

String GetDataDir()
{
	return GetBaseDir();
}

String GetModuleDir()
{
	return JoinPathName(GetBaseDir().c_str(), "module");
}

String GetIncludeDir()
{
	return JoinPathName(GetBaseDir().c_str(), "include");
}

String GetLibraryDir()
{
	return JoinPathName(GetBaseDir().c_str(), "lib");
}

String GetLocalDir()
{
	char buff[MAX_PATH];
	::SHGetSpecialFolderPath(NULL, buff, CSIDL_LOCAL_APPDATA, FALSE);
	String dirName = FromNativeString(buff);
	dirName += "\\Gura\\";
	dirName += GURA_VERSION;
	return dirName;
}

String PrepareLocalDir()
{
	char buff[MAX_PATH];
	::SHGetSpecialFolderPath(NULL, buff, CSIDL_LOCAL_APPDATA, FALSE);
	String dirName = FromNativeString(buff);
	dirName += "\\Gura";
	MakeDir(dirName.c_str());
	dirName += "\\";
	dirName += GURA_VERSION;
	MakeDir(dirName.c_str());
	do {
		String dirNameSub(dirName);
		dirNameSub += "\\module";
		MakeDir(dirNameSub.c_str());
	} while (0);
	do {
		String dirNameSub(dirName);
		dirNameSub += "\\application";
		MakeDir(dirNameSub.c_str());
	} while (0);
	do {
		String dirNameSub(dirName);
		dirNameSub += "\\config";
		MakeDir(dirNameSub.c_str());
	} while (0);
	do {
		String dirNameSub(dirName);
		dirNameSub += "\\work";
		MakeDir(dirNameSub.c_str());
	} while (0);
	return dirName;
}

void SetupModulePath(StringList &strList)
{
	String dirBase = GetBaseDir();
	String str = GetEnv("GURAPATH");
	if (!str.empty()) {
		SplitPathList(str.c_str(), strList);
	}
	strList.push_back(JoinPathName(GetLocalDir().c_str(), "module"));
	strList.push_back(dirBase);
	strList.push_back(JoinPathName(dirBase.c_str(), "module"));
	strList.push_back(JoinPathName(dirBase.c_str(), "module/site"));
}

void SetupExecutablePath()
{
	String dirBase = GetBaseDir();
	String path;
	path += dirBase;
	path += "\\guests\\dylib";
	path += ";";
	path += dirBase;
	path += "\\guests\\tcl\\bin";
	path += ";";
	path += GetEnv("PATH");
	PutEnv("PATH", path.c_str());
}

String ConvCodePage(const char *str, int len, UINT codePageSrc, UINT codePageDst)
{
	int cchWideChar = ::MultiByteToWideChar(codePageSrc, 0, str, len, NULL, 0);
	WCHAR *wcharBuff = new WCHAR [cchWideChar + 1];
	::MultiByteToWideChar(codePageSrc, 0, str, len, wcharBuff, cchWideChar);
	int cchMultiByte = ::WideCharToMultiByte(codePageDst, 0,
				wcharBuff, cchWideChar, NULL, 0, NULL, NULL);
	char *charBuff = new char [cchMultiByte + 1];
	::WideCharToMultiByte(codePageDst, 0,
				wcharBuff, cchWideChar, charBuff, cchMultiByte, NULL, NULL);
	charBuff[cchMultiByte] = '\0';
	String rtn(charBuff); // don't use String(charBuff, cchMultiByte) here!
	delete[] wcharBuff;
	delete[] charBuff;
	return rtn;
}

String ToNativeString(const char *str, int len)
{
	return ConvCodePage(str, len, CP_UTF8, CP_THREAD_ACP);
}

String FromNativeString(const char *str, int len)
{
	return ConvCodePage(str, len, CP_THREAD_ACP, CP_UTF8);
}

//-----------------------------------------------------------------------------
// FileStat implementation
//-----------------------------------------------------------------------------
FileStat::FileStat(const char *pathName, const BY_HANDLE_FILE_INFORMATION &attrData) :
	_pathName(pathName), _attr(0), _bytes(attrData.nFileSizeLow),
	_uid(0), _gid(0)
{
	_atime = ToDateTime(attrData.ftLastAccessTime);
	_mtime = ToDateTime(attrData.ftLastWriteTime);
	_ctime = ToDateTime(attrData.ftCreationTime);
	if (attrData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
		_attr |= ATTR_Dir;
	} else {
		_attr |= ATTR_Reg;
	}
	if (attrData.dwFileAttributes & FILE_ATTRIBUTE_READONLY) {
		_attr |= 0666;
	} else {
		_attr |= 0777;
	}
}

FileStat::FileStat(const char *pathName, const WIN32_FILE_ATTRIBUTE_DATA &attrData) :
	_pathName(pathName), _attr(0), _bytes(attrData.nFileSizeLow), _uid(0), _gid(0)
{
	_atime = ToDateTime(attrData.ftLastAccessTime);
	_mtime = ToDateTime(attrData.ftLastWriteTime);
	_ctime = ToDateTime(attrData.ftCreationTime);
	if (attrData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
		_attr |= ATTR_Dir;
	} else {
		_attr |= ATTR_Reg;
	}
	if (attrData.dwFileAttributes & FILE_ATTRIBUTE_READONLY) {
		_attr |= 0666;
	} else {
		_attr |= 0777;
	}
}

FileStat::FileStat(const char *pathName, const WIN32_FIND_DATA &findData) :
	_pathName(pathName), _attr(0), _bytes(findData.nFileSizeLow), _uid(0), _gid(0)
{
	_atime = ToDateTime(findData.ftLastAccessTime);
	_mtime = ToDateTime(findData.ftLastWriteTime);
	_ctime = ToDateTime(findData.ftCreationTime);
	if (findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
		_attr |= ATTR_Dir;
	} else {
		_attr |= ATTR_Reg;
	}
	if (findData.dwFileAttributes & FILE_ATTRIBUTE_READONLY) {
		_attr |= 0666;
	} else {
		_attr |= 0777;
	}
}

FileStat *FileStat::Generate(Signal sig, const char *fileName)
{
	ULong attr = 0;
	WIN32_FILE_ATTRIBUTE_DATA attrData;
	String pathName = ToNativeString(MakeAbsPathName(
								FileSeparator, fileName).c_str());
	if (::GetFileAttributesEx(pathName.c_str(), GetFileExInfoStandard, &attrData) == 0) {
		sig.SetError(ERR_IOError, "failed to get file status of %s", pathName.c_str());
		return NULL;
	}
	return new FileStat(pathName.c_str(), attrData);
}

//-----------------------------------------------------------------------------
// DirLister
//-----------------------------------------------------------------------------
DirLister::DirLister(const char *dirName, bool joinPathNameFlag) :
	_dirName(dirName), _joinPathNameFlag(joinPathNameFlag), _hFind(INVALID_HANDLE_VALUE)
{
}

DirLister::~DirLister()
{
	::FindClose(_hFind);
}

bool DirLister::Next(const char *pattern, String &pathName, bool *pDirFlag)
{
	WIN32_FIND_DATA findData;
	pathName.clear();
	String fileName;
	for (;;) {
		if (_hFind == INVALID_HANDLE_VALUE) {
			String pattern = JoinPathName(_dirName.c_str(), "*.*");
			_hFind = ::FindFirstFile(ToNativeString(pattern.c_str()).c_str(), &findData);
			if (_hFind == INVALID_HANDLE_VALUE) return false;
		} else {
			if (!::FindNextFile(_hFind, &findData)) return false;
		}
		fileName = FromNativeString(findData.cFileName);
		if (fileName != "." && fileName != ".." &&
			(pattern == NULL || PathMgr::DoesMatchName(pattern, fileName.c_str(), true))) break;
	}
	if (_joinPathNameFlag) {
		pathName = JoinPathName(_dirName.c_str(), fileName.c_str());
	} else {
		pathName = fileName;
	}
	*pDirFlag = (findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)? true : false;
	return true;
}

//-----------------------------------------------------------------------------
// DynamicLibrary
//-----------------------------------------------------------------------------
DynamicLibrary::DynamicLibrary() : _hModule(NULL)
{
}

bool DynamicLibrary::Open(Signal sig, const char *pathName)
{
	_hModule = ::LoadLibrary(ToNativeString(pathName).c_str());
	if (_hModule == NULL) {
		sig.SetError(ERR_ImportError, "can't open module file '%s'", pathName);
		return false;
	}
	return true;
}

void *DynamicLibrary::GetEntry(Signal sig, const char *name)
{
	if (_hModule == NULL) {
		sig.SetError(ERR_ImportError, "library has not been opened");
		return NULL;
	}
	FARPROC pFunc = ::GetProcAddress(_hModule, name);
	if (pFunc == NULL) {
		String nameEx = "_";
		nameEx += name;
		pFunc = ::GetProcAddress(_hModule, nameEx.c_str());
	}
	if (pFunc == NULL) {
		sig.SetError(ERR_ImportError, "can't find entry function '%s'", name);
		return NULL;
	}
	return pFunc;
}

//-----------------------------------------------------------------------------
// Thread
//-----------------------------------------------------------------------------
static DWORD WINAPI ThreadProc(LPVOID lpParameter)
{
	Thread *pThread = reinterpret_cast<Thread *>(lpParameter);
	pThread->Run();
	delete pThread;
	return 0;
}

Thread::Thread() : _hThread(NULL), _threadId(0)
{
}

Thread::~Thread()
{
}

void Thread::Start()
{
	_hThread = ::CreateThread(NULL, 0, ThreadProc, this, 0, &_threadId);
}

void Thread::Wait()
{
	::WaitForSingleObject(_hThread, INFINITE);
}

//-----------------------------------------------------------------------------
// Semaphore
//-----------------------------------------------------------------------------
Semaphore::Semaphore()
{
	_hMutex = ::CreateMutex(NULL, FALSE, NULL);
}

Semaphore::~Semaphore()
{
	::CloseHandle(_hMutex);
}

void Semaphore::Wait()
{
	::WaitForSingleObject(_hMutex, INFINITE);
}

void Semaphore::Release()
{
	::ReleaseMutex(_hMutex);
}

//-----------------------------------------------------------------------------
// Event
//-----------------------------------------------------------------------------
Event::Event()
{
	_hEvent = ::CreateEvent(NULL, FALSE, FALSE, NULL);
}

Event::~Event()
{
	::DeleteObject(_hEvent);
}

void Event::Wait()
{
	::WaitForSingleObject(_hEvent, INFINITE);
}

void Event::Notify()
{
	::SetEvent(_hEvent);
}

#else

//=============================================================================
// POSIX
//=============================================================================
const char FileSeparator = '/';
const bool IgnoreCaseInPathNameFlag = false;

int ExecProgram(Environment &env, Signal sig, const char *pathName,
				const ValueList &valList, Stream *pStreamStdin,
				Stream *pStreamStdout, Stream *pStreamStderr, bool forkFlag)
{
	int exitCode = 0;
	pid_t pid = 0;
	AutoPtr<Memory> pMemory(new MemoryHeap(32768));
	char *argv[4];
	argv[0] = ::strdup("/bin/sh");
	argv[1] = ::strdup("-c");
	String cmdLine;
	cmdLine = ToNativeString(pathName);
	foreach_const (ValueList, pValue, valList) {
		cmdLine += " ";
		AppendCmdLine(cmdLine, ToNativeString(pValue->GetString()).c_str());
	}
	argv[2] = ::strdup(cmdLine.c_str());
	argv[3] = NULL;
	if (forkFlag) {
		pid_t pid = ::fork();
		if (pid == 0) {
			::execv("/bin/sh", argv);
			::exit(1);
		}
		goto done;
	}
	int fdsStdin[2];
	int fdsStdout[2];
	int fdsStderr[2];
	if (::pipe(fdsStdin) < 0 || ::pipe(fdsStdout) < 0 || ::pipe(fdsStderr) < 0) {
		sig.SetError(ERR_IOError, "failed to create pipes");
		goto done;
	}
	pid = ::fork();
	if (pid == 0) {
		::dup2(fdsStdin[0], 0);
		::dup2(fdsStdout[1], 1);
		::dup2(fdsStderr[1], 2);
		for (int i = 0; i < 2; i++) {
			::close(fdsStdin[i]);
			::close(fdsStdout[i]);
			::close(fdsStderr[i]);
		}
		::execv("/bin/sh", argv);
		::exit(1);
	}
	fd_set fdsRead;
	for (;;) {
		if (pStreamStdin != NULL && !pStreamStdin->GetBlocking()) {
			char *buff = reinterpret_cast<char *>(pMemory->GetPointer());
			size_t bytesRead = pStreamStdin->Read(sig, buff, pMemory->GetSize());
			if (sig.IsSignalled()) return -1;
			if (bytesRead == 0) {
				::close(fdsStdin[1]);
			} else {
				::write(fdsStdin[1], buff, bytesRead);
			}
		}
		timeval tv;
		::memset(&tv, 0x00, sizeof(tv));
		tv.tv_sec = 0;
		tv.tv_usec = 100 * 1000;
		FD_ZERO(&fdsRead);
		if (pStreamStdout != NULL) FD_SET(fdsStdout[0], &fdsRead);
		if (pStreamStderr != NULL) FD_SET(fdsStderr[0], &fdsRead);
		::select(ChooseMax(fdsStdout[0], fdsStderr[0]) + 1, &fdsRead, NULL, NULL, &tv);
		bool idleFlag = true;
		if (FD_ISSET(fdsStdout[0], &fdsRead)) {
			idleFlag = false;
			char *buff = reinterpret_cast<char *>(pMemory->GetPointer());
			size_t bytesRead = ::read(fdsStdout[0], buff, pMemory->GetSize());
			pStreamStdout->Write(sig, buff, bytesRead);
			if (sig.IsSignalled()) return -1;
		}
		if (FD_ISSET(fdsStderr[0], &fdsRead)) {
			idleFlag = false;
			char *buff = reinterpret_cast<char *>(pMemory->GetPointer());
			size_t bytesRead = ::read(fdsStderr[0], buff, pMemory->GetSize());
			pStreamStderr->Write(sig, buff, bytesRead);
			if (sig.IsSignalled()) return -1;
		}
		if (idleFlag) {
			int status;
			int rtn = waitpid(pid, &status, WNOHANG);
			if (rtn > 0 && WIFEXITED(status)) {
				exitCode = WEXITSTATUS(status);
				break;
			}
		}
	}
	for (int i = 0; i < 2; i++) {
		::close(fdsStdin[i]);	// fdsStdin[1] may already have been closed.
		::close(fdsStdout[i]);
		::close(fdsStderr[i]);
	}
done:
	for (int i = 0; i < ArraySizeOf(argv); i++) ::free(argv[i]);
	return exitCode;
}

String GetEnv(const char *name, bool *pFoundFlag)
{
	const char *str = ::getenv(ToNativeString(name).c_str());
	if (str == NULL) {
		if (pFoundFlag != NULL) *pFoundFlag = false;
		return String("");
	}
	if (pFoundFlag != NULL) *pFoundFlag = true;
	return FromNativeString(str);
}

void PutEnv(const char *name, const char *value)
{
	int overwrite = 1;
	::setenv(ToNativeString(name).c_str(), ToNativeString(value).c_str(), overwrite);
}

void UnsetEnv(const char *name)
{
	::unsetenv(name);
}

bool Copy(const char *src, const char *dst, bool failIfExistsFlag)
{
	bool copySymLinkFlag = true;
	int fdSrc = -1, fdDst = -1;
	struct stat statSrc, statDst;
	String srcNative = ToNativeString(src);
	String dstNative = ToNativeString(dst);
	if (copySymLinkFlag) {
		if (::lstat(srcNative.c_str(), &statSrc) < 0) return false;
	} else {
		if (::stat(srcNative.c_str(), &statSrc) < 0) return false;
	}
	if (S_ISREG(statSrc.st_mode)) {
		if (::stat(dstNative.c_str(), &statDst) < 0) {
			// nothing to do
		} else if (failIfExistsFlag) {
			return false;
		} else if (!Remove(dst)) {
			//ChangeMode("u+w", dst);
			//if (!Remove(dst)) return false;
			return false;
		}
		fdSrc = ::open(srcNative.c_str(), O_RDONLY);
		if (fdSrc < 0) return false;
		fdDst = ::open(dstNative.c_str(), O_WRONLY | O_CREAT | O_TRUNC, statSrc.st_mode);
		if (fdDst < 0) {
			::close(fdSrc);
			return false;
		}
		size_t bytesSrc = statSrc.st_size;
		void *addrSrc = ::mmap(NULL, bytesSrc, PROT_READ, MAP_PRIVATE, fdSrc, 0);
		if (addrSrc == MAP_FAILED) {
			const size_t bytesBuff = 65536;
			void *buff = ::malloc(bytesBuff);
			for (;;) {
				ssize_t bytesRead = ::read(fdSrc, buff, bytesBuff);
				if (bytesRead == 0) break;
				if (::write(fdDst, buff, bytesRead) < bytesRead) {
					::close(fdSrc);
					::close(fdDst);
					return false;
				}
			}
		} else {
			if (::write(fdDst, addrSrc, bytesSrc) < bytesSrc) {
				::munmap(addrSrc, bytesSrc);
				::close(fdSrc);
				::close(fdDst);
				return false;
			}
			::munmap(addrSrc, bytesSrc);
		}
		::close(fdSrc);
		::close(fdDst);
		return true;
	} else if (S_ISDIR(statSrc.st_mode)) {
		// nothing to do
	} else if (S_ISCHR(statSrc.st_mode)) {
		// nothing to do
	} else if (S_ISBLK(statSrc.st_mode)) {
		// nothing to do
	} else if (S_ISFIFO(statSrc.st_mode)) {
		// nothing to do
	} else if (S_ISLNK(statSrc.st_mode)) {
		// still buggy
		if (::stat(dstNative.c_str(), &statDst) < 0) {
			// nothing to do
		} else if (failIfExistsFlag) {
			return false;
		} else if (!Remove(dst)) {
			//ChangeMode("u+w", dst);
			//if (!Remove(dst)) return false;
			return false;
		}
		char *tgt = new char [statSrc.st_size];
		if (::readlink(srcNative.c_str(), tgt, statSrc.st_size) < 0) return false;
		if (::symlink(tgt, dstNative.c_str()) < 0) return false;
		delete[] tgt;
		return true;
	} else if (S_ISSOCK(statSrc.st_mode)) {
		// nothing to do
	}
	return false;
}

bool Rename(const char *src, const char *dst)
{
	return ::rename(ToNativeString(src).c_str(), ToNativeString(dst).c_str()) == 0;
}

bool Remove(const char *pathName)
{
	return ::unlink(ToNativeString(pathName).c_str()) == 0;
}

bool DoesExist(const char *pathName)
{
	struct stat stat;
	return ::stat(ToNativeString(pathName).c_str(), &stat) == 0;
}

bool IsDir(const char *pathName, bool *pExistFlag)
{
	struct stat stat;
	bool existFlag = (::stat(ToNativeString(pathName).c_str(), &stat) == 0);
	if (pExistFlag != NULL) *pExistFlag = existFlag;
	if (!existFlag) return false;
	return S_ISDIR(stat.st_mode);
}

bool MakeDir(const char *pathName)
{
	return ::mkdir(ToNativeString(pathName).c_str(),
							S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH) == 0;
}

bool RemoveDir(const char *pathName)
{
	return ::rmdir(ToNativeString(pathName).c_str()) == 0;
}

bool ChangeCurDir(const char *pathName)
{
	return ::chdir(ToNativeString(pathName).c_str()) == 0;
}

String GetCurDir()
{
	//char *pathName = ::get_current_dir_name();
	char *pathName = ::getcwd(NULL, 0);
	String rtn = FromNativeString(pathName);
	::free(pathName);
	if (rtn.empty() || !IsFileSeparator(rtn[rtn.size() - 1])) {
		rtn += FileSeparator;
	}
	return rtn;
}

bool ChangeMode(int modeOct, const char *pathName)
{
	return ::chmod(ToNativeString(pathName).c_str(), modeOct) == 0;
}

bool ChangeMode(const char *mode, const char *pathName)
{
	String pathNameEnc = ToNativeString(pathName);
	mode_t st_mode = 0;
	do {
		struct stat statFs;
		if (::stat(pathNameEnc.c_str(), &statFs) < 0) return false;
		st_mode = statFs.st_mode;
	} while (0);
	if (!ParseStatMode(mode, st_mode)) return false;
	return ::chmod(pathNameEnc.c_str(), st_mode) == 0;
}

void Sleep(Number delay)	// unit: sec
{
	struct timeval tv;
	tv.tv_sec = 0;
	tv.tv_usec = static_cast<int>(delay * 1000000);
	::select(0, NULL, NULL, NULL, &tv);
}

Number GetTickTime()
{
	timeval tv;
	struct timezone tz;
	::gettimeofday(&tv, &tz);
	Number num = tv.tv_sec;
	num += static_cast<Number>(tv.tv_usec) / 1000000;
	return num;
}

DateTime GetCurDateTime(bool utcFlag)
{
	time_t t;
	::time(&t);
	struct tm tm;
	DateTime dateTime;
	if (utcFlag) {
		gmtime_r(&t, &tm);
		dateTime = ToDateTime(tm, 0);
	} else {
		localtime_r(&t, &tm);
		dateTime = ToDateTime(tm, GetSecsOffsetTZ());
	}
	return dateTime;
}

DateTime ToDateTime(const struct tm &tm, int secsOffset)
{
	return DateTime(
		static_cast<short>(tm.tm_year) + 1900,
		static_cast<char>(tm.tm_mon) + 1,
		static_cast<char>(tm.tm_mday),
		static_cast<long>(tm.tm_hour) * 3600 +
			static_cast<long>(tm.tm_min) * 60 + tm.tm_sec,
		0, secsOffset);
}

DateTime ToDateTime(time_t t, bool utcFlag)
{
	struct tm tm;
	int secsOffset = 0;
	if (utcFlag) {
		gmtime_r(&t, &tm);
	} else {
		localtime_r(&t, &tm);
		secsOffset = GetSecsOffsetTZ();
	}
	return ToDateTime(tm, secsOffset);
}

int GetSecsOffsetTZ()
{
	struct timeval tv;
	struct timezone tz;
	if (::gettimeofday(&tv, &tz) < 0) return 0;
	return -tz.tz_minuteswest * 60;
}

#if defined(GURA_ON_DARWIN)

String _GetExecutablePath()
{
	uint32_t bufsize = 1024;
	for (int i = 0; i < 2; i++) {
		char *buf = new char [bufsize];
		if (::_NSGetExecutablePath(buf, &bufsize) == 0) {
			String rtn = FromNativeString(buf);
			delete[] buf;
			return rtn;
		}
		delete[] buf;
	}
	return String("");
}

#else
	
String _GetExecutablePath()
{
	// /proc/self/exe
	return "/usr/bin/gura";
}

#endif

String _ReadLink(const char *pathName)
{
	size_t bufsize = 128;
	for (int i = 0; i < 8; i++) {
		char *buf = new char [bufsize + 1];
		ssize_t size = ::readlink(pathName, buf, bufsize);
		if (size >= 0) {
			buf[size] = '\0';
			String rtn = FromNativeString(buf);
			delete[] buf;
			return rtn;
		}
		delete[] buf;
		if (errno != EFAULT) return String("");
		bufsize *= 2;
	}
	return String("");
}

String GetExecutable()
{
	String pathName = _GetExecutablePath();
	for (int i = 0; i < 100; i++) {
		struct stat sb;
		int rtn = ::lstat(pathName.c_str(), &sb);
		if (rtn < 0 || !S_ISLNK(sb.st_mode)) break;
		String linkName = _ReadLink(pathName.c_str());
		if (linkName.empty()) break; // this must not happen.
		String dirNameBase = EliminateBottomDirName(pathName.c_str());
		if (dirNameBase.empty()) dirNameBase = "/";
		pathName = MakeAbsPathName(FileSeparator, linkName.c_str(), dirNameBase.c_str());
	}
	return pathName;
}

String GetBaseDir()
{
	String pathName = EliminateBottomDirName(GetExecutable().c_str());
	pathName = EliminateBottomDirName(pathName.c_str());
	if (pathName.empty()) pathName = "/";
	return pathName;
}

String GetDataDir()
{
	char dirName[128];
	::sprintf(dirName, "share/gura/%s", GURA_VERSION);
	return JoinPathName(GetBaseDir().c_str(), dirName);
}

String GetModuleDir()
{
	char dirName[128];
	::sprintf(dirName, "lib/gura/%s/module", GURA_VERSION);
	return JoinPathName(GetBaseDir().c_str(), dirName);
}

String GetIncludeDir()
{
	char dirName[128];
	::sprintf(dirName, "include/gura/%s", GURA_VERSION);
	return JoinPathName(GetBaseDir().c_str(), dirName);
}

String GetLibraryDir()
{
	return JoinPathName(GetBaseDir().c_str(), "lib");
}

String GetLocalDir()
{
	String dirName = GetEnv("HOME");
	dirName += "/.gura/";
	dirName += GURA_VERSION;
	return dirName;
}

String PrepareLocalDir()
{
	String dirName = GetEnv("HOME");
	dirName += "/.gura";
	MakeDir(dirName.c_str());
	dirName += "/";
	dirName += GURA_VERSION;
	MakeDir(dirName.c_str());
	do {
		String dirNameSub(dirName);
		dirNameSub += "/module";
		MakeDir(dirNameSub.c_str());
	} while (0);
	do {
		String dirNameSub(dirName);
		dirNameSub += "/application";
		MakeDir(dirNameSub.c_str());
	} while (0);
	do {
		String dirNameSub(dirName);
		dirNameSub += "/config";
		MakeDir(dirNameSub.c_str());
	} while (0);
	do {
		String dirNameSub(dirName);
		dirNameSub += "/work";
		MakeDir(dirNameSub.c_str());
	} while (0);
	return dirName;
}

void SetupModulePath(StringList &strList)
{
	String str = GetEnv("GURAPATH");
	if (!str.empty()) {
		SplitPathList(str.c_str(), strList);
	}
	strList.push_back(JoinPathName(GetLocalDir().c_str(), "module"));
	strList.push_back(GetModuleDir());
	strList.push_back(JoinPathName(GetModuleDir().c_str(), "site"));
}

void SetupExecutablePath()
{
	// nothing to do
}

String ToNativeString(const char *str, int len)
{
	if (len < 0) return String(str);
	return String(str, len);
}

String FromNativeString(const char *str, int len)
{
	if (len < 0) return String(str);
	return String(str, len);
}

//-----------------------------------------------------------------------------
// FileStat implementation
//-----------------------------------------------------------------------------
FileStat::FileStat(const char *pathName, const struct stat &stat) :
	_pathName(pathName), _attr(0), _bytes(stat.st_size),
	_uid(stat.st_uid), _gid(stat.st_gid)
{
	_atime = ToDateTime(stat.st_atime);
	_mtime = ToDateTime(stat.st_mtime);
	_ctime = ToDateTime(stat.st_ctime);
	if (S_ISDIR(stat.st_mode)) _attr |= ATTR_Dir;
	if (S_ISCHR(stat.st_mode)) _attr |= ATTR_Chr;
	if (S_ISBLK(stat.st_mode)) _attr |= ATTR_Blk;
	if (S_ISREG(stat.st_mode)) _attr |= ATTR_Reg;
	if (S_ISFIFO(stat.st_mode)) _attr |= ATTR_Fifo;
	if (S_ISLNK(stat.st_mode)) _attr |= ATTR_Lnk;
	if (S_ISSOCK(stat.st_mode)) _attr |= ATTR_Sock;
	_attr |= (stat.st_mode & 0777);
}

FileStat *FileStat::Generate(Signal sig, const char *fileName)
{
	ULong attr = 0;
	struct stat stat;
	String pathName = ToNativeString(MakeAbsPathName(
								FileSeparator, fileName).c_str());
	if (::stat(pathName.c_str(), &stat) != 0) {
		sig.SetError(ERR_IOError, "failed to get file status of %s", pathName.c_str());
		return NULL;
	}
	return new FileStat(pathName.c_str(), stat);
}

//-----------------------------------------------------------------------------
// DirLister
//-----------------------------------------------------------------------------
DirLister::DirLister(const char *dirName, bool joinPathNameFlag) :
		_dirName(dirName), _joinPathNameFlag(joinPathNameFlag), _dirp(NULL)
{
}

DirLister::~DirLister()
{
	if (_dirp != NULL) ::closedir(_dirp);
}

bool DirLister::Next(const char *pattern, String &pathName, bool *pDirFlag)
{
	struct dirent *direntp = NULL;
	pathName.clear();
	String fileName;
	for (;;) {
		if (_dirp == NULL) {
			_dirp = ::opendir(_dirName.empty()? "." : _dirName.c_str());
			if (_dirp == NULL) return false;
		}
		direntp = ::readdir(_dirp);
		if (direntp == NULL) return false;
		fileName = FromNativeString(direntp->d_name);
		if (fileName != "." && fileName != ".." &&
			(pattern == NULL || PathMgr::DoesMatchName(pattern, fileName.c_str(), false))) break;
	}
	if (_joinPathNameFlag) {
		pathName = JoinPathName(_dirName.c_str(), fileName.c_str());
	} else {
		pathName = fileName;
	}
	*pDirFlag = (direntp->d_type == DT_DIR);
	return true;
}

//-----------------------------------------------------------------------------
// DynamicLibrary
//-----------------------------------------------------------------------------
DynamicLibrary::DynamicLibrary() : _hLibrary(NULL)
{
}

bool DynamicLibrary::Open(Signal sig, const char *pathName)
{
	_hLibrary = dlopen(ToNativeString(pathName).c_str(), RTLD_LAZY);
	if (_hLibrary == NULL) {
		sig.SetError(ERR_ImportError, "%s", dlerror());
		return false;
	}
	dlerror(); // clear any existing error
	return true;
}

void *DynamicLibrary::GetEntry(Signal sig, const char *name)
{
	void *pFunc = dlsym(_hLibrary, name);
	if (pFunc == NULL) {
		sig.SetError(ERR_ImportError, "can't find entry function '%s'", name);
		return NULL;
	}
	return pFunc;
}

//-----------------------------------------------------------------------------
// Thread
//-----------------------------------------------------------------------------
static void *start_routine(void *arg)
{
	Thread *pThread = reinterpret_cast<Thread *>(arg);
	::pthread_detach(::pthread_self());
	pThread->Run();
	delete pThread;
	return 0;
}

Thread::Thread()
{
}

Thread::~Thread()
{
}

void Thread::Start()
{
	::pthread_create(&_pt, NULL, &start_routine, this);
}

void Thread::Wait()
{
}

//-----------------------------------------------------------------------------
// Semaphore
//-----------------------------------------------------------------------------
Semaphore::Semaphore()
{
	::sem_init(&_sem, 0, 1);
}

Semaphore::~Semaphore()
{
	::sem_destroy(&_sem);
}

void Semaphore::Wait()
{
	::sem_wait(&_sem);
}

void Semaphore::Release()
{
	::sem_post(&_sem);
}

//-----------------------------------------------------------------------------
// Event
//-----------------------------------------------------------------------------
Event::Event()
{
	pthread_mutexattr_t mutexattr;
	::pthread_mutexattr_init(&mutexattr);
	::pthread_mutex_init(&_mutex, &mutexattr);
	::pthread_mutex_lock(&_mutex);
}

Event::~Event()
{
	::pthread_mutex_destroy(&_mutex);
}

void Event::Wait()
{
	::pthread_mutex_lock(&_mutex);
}

void Event::Notify()
{
	::pthread_mutex_unlock(&_mutex);
}

#endif

}
}
