//=============================================================================
// Gura class: mtp.stat
//=============================================================================
#ifndef __GURA_MODULE_MTP_CLASS_STAT_H__
#define __GURA_MODULE_MTP_CLASS_STAT_H__
#include <gura.h>

Gura_BeginModuleScope(mtp)

//-----------------------------------------------------------------------------
// Stat
//-----------------------------------------------------------------------------
class Stat {
private:
	int _cntRef;
	String _fileName;
	size_t _fileSize;
	DateTime _dtModification;
	LIBMTP_filetype_t _fileType;
public:
	Gura_DeclareReferenceAccessor(Stat);
public:
	Stat(const LIBMTP_file_t *fileInfo);
	Stat(const char *fileName, size_t fileSize, const DateTime &dtModification, LIBMTP_filetype_t fileType);
protected:
	inline ~Stat() {}
public:
	inline const char *GetFileName() const { return _fileName.c_str(); }
	inline size_t GetFileSize() const { return _fileSize; }
	const DateTime &GetDtModification() const { return _dtModification; }
};

//-----------------------------------------------------------------------------
// Declaration of Object_stat
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(stat);

class Object_stat : public Object {
private:
	AutoPtr<Stat> _pStat;
public:
	Gura_DeclareObjectAccessor(stat)
public:
	Object_stat(Stat *pStat);
	virtual String ToString(bool exprFlag);
	inline Stat *GetStat() const { return _pStat.get(); }
};

Gura_EndModuleScope(mtp)

#endif
