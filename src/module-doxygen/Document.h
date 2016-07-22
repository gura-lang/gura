//=============================================================================
// Document.h
//=============================================================================
#ifndef __GURA_DOXYGEN_DOCUMENT_H__
#define __GURA_DOXYGEN_DOCUMENT_H__

Gura_BeginModuleScope(doxygen)

//-----------------------------------------------------------------------------
// Document
//-----------------------------------------------------------------------------
class Document {
public:
	enum Stat {
		STAT_Indent,
		STAT_Source,
		STAT_LineCommentBgn,
		STAT_LineDoxygenFirstChar,
		STAT_LineDoxygen,
		STAT_LineComment,
		STAT_BlockCommentBgn,
		STAT_BlockCommentBgn_Asterisk,
		STAT_BlockDoxygenFirstChar,
		STAT_BlockDoxygen,
		STAT_BlockDoxygen_Asterisk,
		STAT_BlockDoxygen_Indent,
		STAT_BlockDoxygen_IndentAsterisk,
		STAT_BlockDoxygen_IndentAfterAsterisk,
		STAT_BlockComment,
		STAT_BlockComment_Asterisk,
		STAT_Slash,
		STAT_ExIndent,
		STAT_ExDoxygen,
	};
	enum Region {
		RGN_Other,
		RGN_LineDoxygen,
		RGN_LineDoxygenMixed,
		RGN_BlockDoxygen,
		RGN_BlockDoxygenMixed,
	};
private:
	int _cntRef;
	Stat _stat;
	bool _commentLineFlag;
	Region _regionPrev;
	String _sourceName;
	AutoPtr<StructureOwner> _pStructureOwner;
	std::unique_ptr<Parser> _pParser;
public:
	Gura_DeclareReferenceAccessor(Document);
public:
	Document();
protected:
	inline ~Document() {}
public:
	bool ReadStream(Environment &env, SimpleStream &stream,
					const Aliases *pAliases, bool extractedFlag);
	inline const char *GetSourceName() const { return _sourceName.c_str(); }
	inline const StructureOwner &GetStructureOwner() const { return *_pStructureOwner; }
protected:
	bool FeedChar(Environment &env, char ch);
	void AddStructure();
};

Gura_EndModuleScope(doxygen)

#endif
