//=============================================================================
// Configuration.h
//=============================================================================
#ifndef __GURA_DOXYGEN_CONFIGURATION_H__
#define __GURA_DOXYGEN_CONFIGURATION_H__

Gura_BeginModuleScope(doxygen)

//-----------------------------------------------------------------------------
// Configuration
//-----------------------------------------------------------------------------
class Configuration {
public:
	class Entry {
	private:
		int _cntRef;
		String _name;
		StringList _values;
	public:
		Gura_DeclareReferenceAccessor(Entry);
	public:
		Entry(const String &name);
	protected:
		inline ~Entry() {}
	public:
		inline void AddValue(const String &value) { _values.push_back(value); }
		inline void ClearValues() { _values.clear(); }
		inline const char *GetName() const { return _name.c_str(); }
		inline const StringList &GetValues() const { return _values; }
	};
	class EntryDict : public std::map<String, Entry *> {
	public:
		~EntryDict();
		void Clear();
	};
private:
	enum Stat {
		STAT_Init,
		STAT_Name,
		STAT_Assign,
		STAT_PlusAssign,
		STAT_ValueBegin,
		STAT_Value,
		STAT_Value_Escape,
		STAT_QuotedValue,
		STAT_QuotedValueEnd,
		STAT_QuotedValue_Escape,
		STAT_SkipToLineEnd,
	};
private:
	Stat _stat;
	String _field;
	AutoPtr<Entry> _pEntry;
	EntryDict _entryDict;
public:
	Configuration();
	bool FeedChar(Environment &env, char ch);
	bool ReadStream(Environment &env, Stream &stream);
	void Print() const;
private:
	static bool IsNameCharBegin(char ch) {
		return IsAlpha(ch) || ch == '_';
	}
	static bool IsNameChar(char ch) {
		return IsNameCharBegin(ch) || IsDigit(ch);
	}
};

Gura_EndModuleScope(doxygen)

#endif
