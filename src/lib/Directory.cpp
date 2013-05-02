#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Directory
//-----------------------------------------------------------------------------
Directory::Directory(Directory *pParent, const char *name, Type type, char chSeparator) :
	_cntRef(1), _pParent(pParent), _name(name), _type(type), _chSeparator(chSeparator)
{
}

Directory::Directory(const Directory &directory) : _cntRef(1),
	_pParent(Directory::Reference(directory._pParent)), _name(directory._name),
	_type(directory._type), _chSeparator(directory._chSeparator)
{
}

Directory::~Directory()
{
}

Directory *Directory::Next(Environment &env, Signal sig)
{
	if (!IsContainer()) {
		sig.SetError(ERR_ValueError, "not a container entry");
		return NULL;
	}
	return DoNext(env, sig);
}

String Directory::MakePathName(bool addSepFlag, const char *pathNameTrail) const
{
	String pathName(_name);
	for (Directory *pDirectory = GetParent(); pDirectory != NULL;
										pDirectory = pDirectory->GetParent()) {
		// a "boundary container" directory may have an empty name
		if (*pDirectory->GetName() != '\0' || pDirectory->IsRootContainer()) {
			String str(pDirectory->GetName());
			size_t len = str.size();
			if (len == 0 || !IsFileSeparator(str[len - 1])) {
				str += pDirectory->GetSeparator();
			}
			str += pathName;
			pathName = str;
		}
	}
	if (pathNameTrail != NULL) {
		size_t len = pathName.size();
		if (len == 0 || !IsFileSeparator(pathName[len - 1])) {
			pathName += GetSeparator();
		}
		for (const char *p = pathNameTrail; *p != '\0'; p++) {
			char ch = IsFileSeparator(*p)? GetSeparator() : *p;
			pathName += ch;
		}
	} else if (addSepFlag && IsContainer() && !_name.empty()) {
		pathName += GetSeparator();
	}
	return pathName;
}

int Directory::CountDepth() const
{
	int depth = 0;
	for (const Directory *pDirectory = GetParent(); pDirectory != NULL;
										pDirectory = pDirectory->GetParent()) {
		depth++;
	}
	return depth;
}

Object *Directory::DoGetStatObj(Signal sig)
{
	sig.SetError(ERR_IOError, "can't retrieve stat object");
	return NULL;
}


namespace DirBuilder {

//-----------------------------------------------------------------------------
// Record
//-----------------------------------------------------------------------------
Record::~Record()
{
	if (_pRecordChildren != NULL) {
		foreach (RecordList, ppRecordChild, *_pRecordChildren) {
			delete *ppRecordChild;
		}
	}
}

Record *Record::Find(const char *name)
{
	if (_pRecordChildren == NULL) return NULL;
	foreach (RecordList, ppRecordChild, *_pRecordChildren) {
		if (::strcmp((*ppRecordChild)->GetName(), name) == 0) {
			return *ppRecordChild;
		}
	}
	return NULL;
}

//-----------------------------------------------------------------------------
// Structure
//-----------------------------------------------------------------------------
Structure::Structure() : _cntRef(1), _pRecordRoot(NULL)
{
}

Structure::~Structure()
{
	delete _pRecordRoot;
}

Record *Structure::AddRecord(const char *pathName)
{
	const char *p = pathName;
	if (IsFileSeparator(*p)) p++;
	String field;
	Record *pRecord = NULL;
	Record *pRecordParent = GetRoot();
	for ( ; ; p++) {
		char ch = *p;
		if (!IsFileSeparator(ch) && ch != '\0') {
			field += ch;
			continue;
		}
		if (!field.empty()) {
			pRecord = pRecordParent->Find(field.c_str());
			if (pRecord == NULL) {
				bool containerFlag = IsFileSeparator(ch);
				pRecord = pRecordParent->GenerateChild(
										field.c_str(), containerFlag);
			}
			field.clear();
			pRecordParent = pRecord;
		}
		if (ch == '\0') break;
	}
	return pRecord;
}

Directory *Structure::GenerateDirectory(Signal sig, Directory *pParent,
				const char **pPathName, PathManager::NotFoundMode notFoundMode)
{
	Directory *pDirectory = NULL;
	const char *p = *pPathName;
	if (IsFileSeparator(*p)) p++;
	String field;
	Record *pRecordParent = GetRoot();
	if (*p == '\0') {
		*pPathName = p;
		return pRecordParent->GenerateDirectory(pParent, true);
	}
	bool boundaryFlag = true;
	for ( ; ; p++) {
		char ch = *p;
		if (!IsFileSeparator(ch) && ch != '\0') {
			field += ch;
			continue;
		}
		Record *pRecord = NULL;
		if (field.empty()) {
			break;
		} else {
			pRecord = pRecordParent->Find(field.c_str());
			if (pRecord != NULL) {
				// nothing to do
			} else if (notFoundMode == PathManager::NF_NoSignal) {
				pDirectory = NULL;
				break;
			} else {
				sig.SetError(ERR_IOError, "path not found");
				pDirectory = NULL;
				break;
			}
		}
		pDirectory = pRecord->GenerateDirectory(pParent, boundaryFlag);
		if (ch == '\0') break;
		boundaryFlag = false;
		pParent = pDirectory;
		pRecordParent = pRecord;
		field.clear();
	}
	*pPathName = p;
	return pDirectory;
}

}

}
