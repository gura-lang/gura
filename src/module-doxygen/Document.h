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
		STAT_LineCommentBgn_Slash,
		STAT_LineDoxygenFirstChar,
		STAT_LineDoxygen,
		STAT_LineDoxygenPost,
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
		RGN_LineDoxygenTrail,
		RGN_LineDoxygenAndBlankLine,
		RGN_BlockDoxygen,
		RGN_BlockDoxygenTrail,
	};
	class Line {
	private:
		int _indent;
		String _str;
	public:
		inline Line(int indent, const String &str) : _indent(indent), _str(str) {}
		inline void SetIndent(int indent) { _indent = indent; }
		inline int GetIndent() const { return _indent; }
		inline const char *GetString() const { return _str.c_str(); }
	};
	class LineList : public std::vector<Line *> {
	public:
		void AdjustIndent();
	};
	class LineOwner : public LineList {
	public:
		~LineOwner();
		void Clear();
	};
private:
	int _cntRef;
	int _cntContLineDoxygen;
	Stat _stat;
	bool _commentLineFlag;
	Region _regionPrev;
	String _sourceName;
	String _strLine;
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
	void AddStructure(bool afterMemberFlag);
	void ConvertToBrief();
};

Gura_EndModuleScope(doxygen)

#endif
