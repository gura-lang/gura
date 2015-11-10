//=============================================================================
// Symbol
//=============================================================================
#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Symbol
//-----------------------------------------------------------------------------
const Symbol *Symbol::Empty = nullptr;
const Symbol *Symbol::Excl = nullptr;
const Symbol *Symbol::Dollar = nullptr;
const Symbol *Symbol::Percnt = nullptr;
const Symbol *Symbol::PercntPercnt = nullptr;
const Symbol *Symbol::Amp = nullptr;
const Symbol *Symbol::Ast = nullptr;
const Symbol *Symbol::Plus = nullptr;
const Symbol *Symbol::Quest = nullptr;
const Symbol *Symbol::Tilde = nullptr;
const Symbol *Symbol::Hyphen= nullptr;

Symbol::Set Symbol::_setOfFlowControlSymbol;
Symbol::MapFromFlag Symbol::_mapFromFlag;
Symbol::MapToFlag Symbol::_mapToFlag;
Symbol::MapFromOccurPattern Symbol::_mapFromOccurPattern;
Symbol::MapToOccurPattern Symbol::_mapToOccurPattern;
Symbol::MapFromResultMode Symbol::_mapFromResultMode;
Symbol::MapToResultMode Symbol::_mapToResultMode;

Symbol::Symbol(UniqNumber uniqNum, const char *name) : _uniqNum(uniqNum)
{
	_name = new char[::strlen(name) + 1];
	::strcpy(_name, name);
}

Symbol::~Symbol()
{
	delete[] _name;
}

const Symbol *Symbol::Add(const char *name)
{
	return SymbolPool::GetInstance()->Add(name);
}

bool Symbol::IsFlowControlSymbol() const
{
#if 1
	Set::const_iterator iter = _setOfFlowControlSymbol.find(this);
	return iter != _setOfFlowControlSymbol.end();
#else
	return 
		IsIdentical(Gura_Symbol(if_)) ||
		IsIdentical(Gura_Symbol(elsif)) ||
		IsIdentical(Gura_Symbol(repeat)) ||
		IsIdentical(Gura_Symbol(while_)) ||
		IsIdentical(Gura_Symbol(for_)) ||
		IsIdentical(Gura_Symbol(cross));
#endif
}

void Symbol::Initialize()
{
	SymbolPool::Initialize();
	Empty			= Add("");
	Excl			= Add("!");
	Dollar			= Add("$");
	Percnt			= Add("%");
	PercntPercnt	= Add("%%");
	Amp				= Add("&");
	Ast				= Add("*");
	Plus			= Add("+");
	Quest			= Add("?");
	Tilde			= Add("~");
	Hyphen			= Add("-");
	do {
		struct {
			const Symbol *pSymbol;
		} tbl[] = {
			{ Gura_Symbol(if_)		},
			{ Gura_Symbol(elsif)	},
			{ Gura_Symbol(repeat)	},
			{ Gura_Symbol(while_)	},
			{ Gura_Symbol(for_)		},
			{ Gura_Symbol(cross)	},
		};
		for (size_t i = 0; i < ArraySizeOf(tbl); i++) {
			_setOfFlowControlSymbol.insert(tbl[i].pSymbol);
		}
	} while (0);
	do {
		struct {
			const Symbol *pSymbol;
			ULong flag;
		} tbl[] = {
			{ Gura_Symbol(cut_extra_args),	FLAG_CutExtraArgs	},
			{ Gura_Symbol(dynamic_scope),	FLAG_DynamicScope	},
			{ Gura_Symbol(end_marker),		FLAG_EndMarker		},
			{ Gura_Symbol(finalizer),		FLAG_Finalizer		},
			{ Gura_Symbol(flat),			FLAG_Flat			},
			{ Gura_Symbol(fork),			FLAG_Fork			},
			{ Gura_Symbol(leader),			FLAG_Leader			},
			{ Gura_Symbol(listvar),			FLAG_ListVar		},
			{ Gura_Symbol(map),				FLAG_Map			},
			{ Gura_Symbol(nil),				FLAG_Nil			},
			{ Gura_Symbol(nocast),			FLAG_NoCast			},
			{ Gura_Symbol(nomap),			FLAG_NoMap			},
			{ Gura_Symbol(nonamed),			FLAG_NoNamed		},
			{ Gura_Symbol(private_),		FLAG_Private		},
			{ Gura_Symbol(privileged),		FLAG_Privileged		},
			{ Gura_Symbol(public_),			FLAG_Public			},
			{ Gura_Symbol(r),				FLAG_Read			},
			{ Gura_Symbol(symbol_func),		FLAG_SymbolFunc		},
			{ Gura_Symbol(trailer),			FLAG_Trailer		},
			{ Gura_Symbol(w),				FLAG_Write			},
		};
		for (size_t i = 0; i < ArraySizeOf(tbl); i++) {
			_mapFromFlag[tbl[i].flag] = tbl[i].pSymbol;
			_mapToFlag[tbl[i].pSymbol] = tbl[i].flag;
		}
	} while (0);
	do {
		struct {
			const Symbol *pSymbol;
			OccurPattern occurPattern;
		} tbl[] = {
			{ Symbol::Ast,		OCCUR_ZeroOrMore	},
			{ Symbol::Plus,		OCCUR_OnceOrMore	},
			{ Symbol::Quest,	OCCUR_ZeroOrOnce	},
		};
		for (size_t i = 0; i < ArraySizeOf(tbl); i++) {
			_mapFromOccurPattern[tbl[i].occurPattern] = tbl[i].pSymbol;
			_mapToOccurPattern[tbl[i].pSymbol] = tbl[i].occurPattern;
		}
	} while (0);
	do {
		struct {
			const Symbol *pSymbol;
			ResultMode resultMode;
		} tbl[] = {
			{ Gura_Symbol(iter),			RSLTMODE_Iterator	},
			{ Gura_Symbol(list),			RSLTMODE_List		},
			{ Gura_Symbol(reduce),			RSLTMODE_Reduce		},
			{ Gura_Symbol(set),				RSLTMODE_Set		},
			{ Gura_Symbol(void_),			RSLTMODE_Void		},
			{ Gura_Symbol(xiter),			RSLTMODE_XIterator	},
			{ Gura_Symbol(xlist),			RSLTMODE_XList		},
			{ Gura_Symbol(xreduce),			RSLTMODE_XReduce	},
			{ Gura_Symbol(xset),			RSLTMODE_XSet		},
		};
		for (size_t i = 0; i < ArraySizeOf(tbl); i++) {
			_mapFromResultMode[tbl[i].resultMode] = tbl[i].pSymbol;
			_mapToResultMode[tbl[i].pSymbol] = tbl[i].resultMode;
		}
	} while(0);
}

const Symbol *Symbol::FromFlag(ULong flag)
{
	MapFromFlag::const_iterator iter = _mapFromFlag.find(flag);
	return (iter == _mapFromFlag.end())? nullptr : iter->second;
}

ULong Symbol::ToFlag(const Symbol *pSymbol)
{
	MapToFlag::const_iterator iter = _mapToFlag.find(pSymbol);
	return (iter == _mapToFlag.end())? FLAG_None : iter->second;
}

ULong Symbol::ToFlags(const SymbolSet &symbolSet)
{
	ULong flags = 0;
	foreach_const (SymbolSet, ppSymbol, symbolSet) {
		MapToFlag::const_iterator iter = _mapToFlag.find(*ppSymbol);
		if (iter != _mapToFlag.end()) flags |= iter->second;
	}
	return flags;
}

const Symbol *Symbol::FromOccurPattern(OccurPattern occurPattern)
{
	MapFromOccurPattern::const_iterator iter = _mapFromOccurPattern.find(occurPattern);
	return (iter == _mapFromOccurPattern.end())? nullptr : iter->second;
}

OccurPattern Symbol::ToOccurPattern(const Symbol *pSymbol)
{
	MapToOccurPattern::const_iterator iter = _mapToOccurPattern.find(pSymbol);
	return (iter == _mapToOccurPattern.end())? OCCUR_Invalid : iter->second;
}

const Symbol *Symbol::FromResultMode(ResultMode resultMode)
{
	MapFromResultMode::const_iterator iter = _mapFromResultMode.find(resultMode);
	return (iter == _mapFromResultMode.end())? nullptr : iter->second;
}

ResultMode Symbol::ToResultMode(const Symbol *pSymbol)
{
	MapToResultMode::const_iterator iter = _mapToResultMode.find(pSymbol);
	return (iter == _mapToResultMode.end())? RSLTMODE_Normal : iter->second;
}

String Symbol::MakeAttrForFlags(ULong flagsToSet, ULong flagsToClear)
{
	String str;
	ULong flag = 1;
	for (ULong flags = flagsToSet; flags != 0; flags >>= 1, flag <<= 1) {
		if (flags & 1) {
			const Symbol *pSymbol = FromFlag(flag);
			if (pSymbol != nullptr) {
				str += ":";
				str += pSymbol->GetName();
			}
		}
	}
	if (flagsToClear & FLAG_Flat) {
		str += ":noflat";
	}
	return str;
}

String Symbol::MakeAttrForResultMode(ResultMode resultMode)
{
#if 1
	const Symbol *pSymbol = FromResultMode(resultMode);
	if (pSymbol == nullptr) return String("");
	String str = ":";
	str += pSymbol->GetName();
	return str;
#else
	struct Item {
		ResultMode resultMode;
		const char *attrName;
	};
	static const Item items[] = {
		{ RSLTMODE_Iterator,	":iter"		},
		{ RSLTMODE_List,		":list"		},
		{ RSLTMODE_Reduce,		":reduce"	},
		{ RSLTMODE_Set,			":set"		},
		{ RSLTMODE_Void,		":void"		},
		{ RSLTMODE_XIterator,	":xiter"	},
		{ RSLTMODE_XList,		":xlist"	},
		{ RSLTMODE_XReduce,		":xreduce"	},
		{ RSLTMODE_XSet,		":xset"		},
	};
	for (size_t i = 0; i < ArraySizeOf(items); i++) {
		const Item &item = items[i];
		if (resultMode == item.resultMode) return String(item.attrName);
	}
	return String("");
#endif
}

//-----------------------------------------------------------------------------
// SymbolList
//-----------------------------------------------------------------------------
const SymbolList SymbolList::Empty;

String SymbolList::Join(const char *sep) const
{
	return Join(begin(), end(), sep);
}

String SymbolList::Join(const char sepChar) const
{
	char sep[2];
	sep[0] = sepChar;
	sep[1] = '\0';
	return Join(begin(), end(), sep);
}

String SymbolList::Join(SymbolList::const_iterator ppSymbol,
					SymbolList::const_iterator ppSymbolEnd, const char *sep)
{
	String rtn;
	if (ppSymbol == ppSymbolEnd) return rtn;
	rtn += (*ppSymbol)->GetName();
	ppSymbol++;
	for ( ; ppSymbol != ppSymbolEnd; ppSymbol++) {
		rtn += sep;
		rtn += (*ppSymbol)->GetName();
	}
	return rtn;
}

String SymbolList::Join(SymbolList::const_iterator ppSymbol,
					SymbolList::const_iterator ppSymbolEnd, const char sepChar)
{
	char sep[2];
	sep[0] = sepChar;
	sep[1] = '\0';
	return Join(ppSymbol, ppSymbolEnd, sep);
}

void SymbolList::SortByName()
{
	std::stable_sort(begin(), end(), Symbol::LessThan_Name());
}

//-----------------------------------------------------------------------------
// SymbolSet
//-----------------------------------------------------------------------------
const SymbolSet SymbolSet::Empty;

SymbolSet::SymbolSet(const SymbolSet &symbolSet)
{
	foreach_const (SymbolSet, ppSymbol, symbolSet) Insert(*ppSymbol);
}

SymbolSet::~SymbolSet()
{
}

void SymbolSet::operator=(const SymbolSet &symbolSet)
{
	foreach_const (SymbolSet, ppSymbol, symbolSet) Insert(*ppSymbol);
}

void SymbolSet::Insert(const SymbolSet &symbolSet)
{
	foreach_const (SymbolSet, ppSymbol, symbolSet) Insert(*ppSymbol);
}

//-----------------------------------------------------------------------------
// SymbolPool
//-----------------------------------------------------------------------------
SymbolPool *SymbolPool::_pInst = nullptr;

SymbolPool::~SymbolPool()
{
	foreach (Content, ppSymbol, _content) {
		Symbol::Delete(*ppSymbol);
	}
}

void SymbolPool::Initialize()
{
	if (_pInst == nullptr) {
		_pInst = new SymbolPool();
		_pInst->_Initialize();
	}
}

void SymbolPool::_Initialize()
{
	Gura_RealizeSymbol(__arg__);
	Gura_RealizeSymbol(__del__);
	Gura_RealizeSymbol(__doc__);
	Gura_RealizeSymbol(__getitem__);
	Gura_RealizeSymbol(__getitemx__);
	Gura_RealizeSymbol(__getprop__);
	Gura_RealizeSymbol(__init__);
	Gura_RealizeSymbol(__name__);
	Gura_RealizeSymbol(__setitem__);
	Gura_RealizeSymbol(__setitemx__);
	Gura_RealizeSymbol(__setprop__);
	Gura_RealizeSymbol(__source__);
	Gura_RealizeSymbol(__str__);
	Gura_RealizeSymbol(__symbol__);
	Gura_RealizeSymbol(__cast__);
	Gura_RealizeSymbol(__castto__);
	Gura_RealizeSymbol(__serialize__);
	Gura_RealizeSymbol(__deserialize__);
	Gura_RealizeSymbol(__format_d__);
	Gura_RealizeSymbol(__format_u__);
	Gura_RealizeSymbol(__format_b__);
	Gura_RealizeSymbol(__format_o__);
	Gura_RealizeSymbol(__format_x__);
	Gura_RealizeSymbol(__format_e__);
	Gura_RealizeSymbol(__format_f__);
	Gura_RealizeSymbol(__format_g__);
	Gura_RealizeSymbol(__format_s__);
	Gura_RealizeSymbol(__format_c__);
	Gura_RealizeSymbolAlias(_anonymous_,	"*anonymous*");
	Gura_RealizeSymbol(a);
	Gura_RealizeSymbol(abs);
	Gura_RealizeSymbol(align);
	Gura_RealizeSymbol(alpha);
	Gura_RealizeSymbol(and);
	Gura_RealizeSymbol(aqua);
	Gura_RealizeSymbol(ar);
	Gura_RealizeSymbol(arg);
	Gura_RealizeSymbol(argument);
	Gura_RealizeSymbol(argsymbols);
	Gura_RealizeSymbol(array);
	Gura_RealizeSymbol(ascend);
	Gura_RealizeSymbol(ascii);
	Gura_RealizeSymbol(asctime);
	Gura_RealizeSymbol(attrfront);
	Gura_RealizeSymbol(attrs);
	Gura_RealizeSymbol(attrsopt);
	Gura_RealizeSymbol(audio);
	Gura_RealizeSymbol(audiotype);
	Gura_RealizeSymbol(autoindent);
	Gura_RealizeSymbol(b);
	Gura_RealizeSymbol(backward);
	Gura_RealizeSymbol(basic);
	Gura_RealizeSymbol(bcc);
	Gura_RealizeSymbol(begin);
	Gura_RealizeSymbol(bfs);
	Gura_RealizeSymbol(bg);
	Gura_RealizeSymbol(bgr);
	Gura_RealizeSymbol(bgra);
	Gura_RealizeSymbol(binary);
	Gura_RealizeSymbol(bitmap);
	Gura_RealizeSymbol(bitspersample);
	Gura_RealizeSymbol(black);
	Gura_RealizeSymbol(block);
	Gura_RealizeSymbol(blockparam);
	Gura_RealizeSymbol(blue);
	Gura_RealizeSymbol(body);
	Gura_RealizeSymbol(boolean);
	Gura_RealizeSymbol(both);
	Gura_RealizeSymbol(bottom);
	Gura_RealizeSymbol(box);
	Gura_RealizeSymbolAlias(break_,			"break");
	Gura_RealizeSymbol(brief);
	Gura_RealizeSymbol(bright_aqua);
	Gura_RealizeSymbol(bright_blue);
	Gura_RealizeSymbol(bright_cyan);
	Gura_RealizeSymbol(bright_green);
	Gura_RealizeSymbol(bright_magenta);
	Gura_RealizeSymbol(bright_purple);
	Gura_RealizeSymbol(bright_red);
	Gura_RealizeSymbol(bright_white);
	Gura_RealizeSymbol(bright_yellow);
	Gura_RealizeSymbol(bytespersample);
	Gura_RealizeSymbol(c);
	Gura_RealizeSymbol(car);
	Gura_RealizeSymbol(carray);
	Gura_RealizeSymbol(cast);
	Gura_RealizeSymbolAlias(catch_,			"catch");
	Gura_RealizeSymbol(cdr);
	Gura_RealizeSymbol(center);
	Gura_RealizeSymbol(channels);
	Gura_RealizeSymbol(child);
	Gura_RealizeSymbol(children);
	Gura_RealizeSymbol(chop);
	Gura_RealizeSymbol(clang);
	Gura_RealizeSymbol(codec);
	Gura_RealizeSymbol(codecs);
	Gura_RealizeSymbol(color);
	Gura_RealizeSymbol(complex);
	Gura_RealizeSymbolAlias(const_,			"const");
	Gura_RealizeSymbolAlias(continue_,		"continue");
	Gura_RealizeSymbol(cos);
	Gura_RealizeSymbol(crammed);
	Gura_RealizeSymbol(cross);
	Gura_RealizeSymbol(cs);
	Gura_RealizeSymbol(cstr);
	Gura_RealizeSymbol(cur);
	Gura_RealizeSymbol(cut_extra_args);
	Gura_RealizeSymbol(cyan);
	Gura_RealizeSymbol(d);
	Gura_RealizeSymbol(datetime);
	Gura_RealizeSymbol(darwin);
	Gura_RealizeSymbol(day);
	Gura_RealizeSymbol(days);
	Gura_RealizeSymbol(de);
	Gura_RealizeSymbol(decl);
	Gura_RealizeSymbol(declaration);
	Gura_RealizeSymbol(decls);
	Gura_RealizeSymbolAlias(default_,		"default");
	Gura_RealizeSymbol(deg);
	Gura_RealizeSymbol(denom);
	Gura_RealizeSymbol(descend);
	Gura_RealizeSymbol(dfs);
	Gura_RealizeSymbol(dict);
	Gura_RealizeSymbol(dir);
	Gura_RealizeSymbol(directory);
	Gura_RealizeSymbol(down);
	Gura_RealizeSymbol(dynamic_scope);
	Gura_RealizeSymbol(e);
	Gura_RealizeSymbolAlias(else_,			"else");
	Gura_RealizeSymbol(elsif);
	Gura_RealizeSymbol(en);
	Gura_RealizeSymbol(end);
	Gura_RealizeSymbol(end_marker);
	Gura_RealizeSymbol(environment);
	Gura_RealizeSymbol(eof);
	Gura_RealizeSymbol(eol);
	Gura_RealizeSymbol(error);
	Gura_RealizeSymbol(esc);
	Gura_RealizeSymbol(exp);
	Gura_RealizeSymbol(expr);
	Gura_RealizeSymbolAlias(extern_,		"extern");
	Gura_RealizeSymbol(f);
	Gura_RealizeSymbolAlias(false_,			"false");
	Gura_RealizeSymbol(fancy);
	Gura_RealizeSymbol(file);
	Gura_RealizeSymbol(finalize);
	Gura_RealizeSymbol(finalizer);
	Gura_RealizeSymbol(firsteol);
	Gura_RealizeSymbol(flat);
	Gura_RealizeSymbolAlias(for_,			"for");
	Gura_RealizeSymbol(force);
	Gura_RealizeSymbol(fork);
	Gura_RealizeSymbol(format);
	Gura_RealizeSymbol(formatter);
	Gura_RealizeSymbol(forward);
	Gura_RealizeSymbol(fr);
	Gura_RealizeSymbol(friday);
	Gura_RealizeSymbol(ftp);
	Gura_RealizeSymbol(fullname);
	Gura_RealizeSymbol(function);
	Gura_RealizeSymbol(func_scope);
	Gura_RealizeSymbol(g);
	Gura_RealizeSymbol(gnuc);
	Gura_RealizeSymbol(gray);
	Gura_RealizeSymbol(green);
	Gura_RealizeSymbol(h);
	Gura_RealizeSymbol(height);
	Gura_RealizeSymbol(help);
	Gura_RealizeSymbol(horz);
	Gura_RealizeSymbol(host);
	Gura_RealizeSymbol(hour);
	Gura_RealizeSymbol(http);
	Gura_RealizeSymbol(i);
	Gura_RealizeSymbol(icase);
	Gura_RealizeSymbol(identifier);
	Gura_RealizeSymbolAlias(if_,			"if");
	Gura_RealizeSymbol(imag);
	Gura_RealizeSymbol(image);
	Gura_RealizeSymbol(imagetype);
	Gura_RealizeSymbol(indent);
	Gura_RealizeSymbol(index);
	Gura_RealizeSymbol(indices);
	Gura_RealizeSymbol(inside_scope);
	Gura_RealizeSymbol(iter);
	Gura_RealizeSymbol(iterator);
	Gura_RealizeSymbol(iteritem);
	Gura_RealizeSymbol(j);
	Gura_RealizeSymbol(ja);
	Gura_RealizeSymbol(k);
	Gura_RealizeSymbol(ka);
	Gura_RealizeSymbol(ko);
	Gura_RealizeSymbol(l);
	Gura_RealizeSymbol(lang);
	Gura_RealizeSymbol(last_index);
	Gura_RealizeSymbol(langcode);
	Gura_RealizeSymbol(lasteol);
	Gura_RealizeSymbol(leader);
	Gura_RealizeSymbol(left);
	Gura_RealizeSymbol(left_bottom);
	Gura_RealizeSymbol(left_bottom_horz);
	Gura_RealizeSymbol(left_bottom_vert);
	Gura_RealizeSymbol(left_top);
	Gura_RealizeSymbol(left_top_horz);
	Gura_RealizeSymbol(left_top_vert);
	Gura_RealizeSymbol(len);
	Gura_RealizeSymbolAlias(line_,			"line");
	Gura_RealizeSymbol(lineno);
	Gura_RealizeSymbol(linenobtm);
	Gura_RealizeSymbol(linux);
	Gura_RealizeSymbol(list);
	Gura_RealizeSymbol(listitem);
	Gura_RealizeSymbol(listvar);
	Gura_RealizeSymbol(local);
	Gura_RealizeSymbol(log);
	Gura_RealizeSymbol(loose);
	Gura_RealizeSymbol(lower);
	Gura_RealizeSymbol(m);
	Gura_RealizeSymbol(magenta);
	Gura_RealizeSymbol(map);
	Gura_RealizeSymbol(math);
	Gura_RealizeSymbol(matrix);
	Gura_RealizeSymbol(message);
	Gura_RealizeSymbol(min);
	Gura_RealizeSymbol(minus);
	Gura_RealizeSymbol(misc);
	Gura_RealizeSymbol(mixin_type);
	Gura_RealizeSymbol(mode);
	Gura_RealizeSymbol(monday);
	Gura_RealizeSymbol(monitor);
	Gura_RealizeSymbol(mono);
	Gura_RealizeSymbol(month);
	Gura_RealizeSymbol(msc);
	Gura_RealizeSymbol(msec);
	Gura_RealizeSymbol(msecs);
	Gura_RealizeSymbol(mswin);
	Gura_RealizeSymbol(multi);
	Gura_RealizeSymbol(n);
	Gura_RealizeSymbol(name);
	Gura_RealizeSymbol(neat);
	Gura_RealizeSymbol(next);
	Gura_RealizeSymbol(nil);
	Gura_RealizeSymbol(nocast);
	Gura_RealizeSymbol(noesc);
	Gura_RealizeSymbol(noflat);
	Gura_RealizeSymbol(noindent);
	Gura_RealizeSymbol(nomap);
	Gura_RealizeSymbol(nonamed);
	Gura_RealizeSymbol(none);
	Gura_RealizeSymbol(norm);
	Gura_RealizeSymbol(nosort);
	Gura_RealizeSymbol(nsec);
	Gura_RealizeSymbol(nsecs);
	Gura_RealizeSymbol(number);
	Gura_RealizeSymbol(numer);
	Gura_RealizeSymbol(o);
	Gura_RealizeSymbol(object);
	Gura_RealizeSymbol(oneline);
	Gura_RealizeSymbol(open);
	Gura_RealizeSymbol(open_l);
	Gura_RealizeSymbol(open_r);
	Gura_RealizeSymbolAlias(operator_,		"operator");
	Gura_RealizeSymbol(or);
	Gura_RealizeSymbol(overwrite);
	Gura_RealizeSymbol(p);
	Gura_RealizeSymbol(padding);
	Gura_RealizeSymbol(palette);
	Gura_RealizeSymbol(parent);
	Gura_RealizeSymbol(parents);
	Gura_RealizeSymbol(password);
	Gura_RealizeSymbol(path);
	Gura_RealizeSymbol(pathname);
	Gura_RealizeSymbol(percent);
	Gura_RealizeSymbol(pi);
	Gura_RealizeSymbol(pl);
	Gura_RealizeSymbol(plus);
	Gura_RealizeSymbol(pointer);
	Gura_RealizeSymbol(port);
	Gura_RealizeSymbol(postext);
	Gura_RealizeSymbol(prec);
	Gura_RealizeSymbol(prefix);
	Gura_RealizeSymbol(prev);
	Gura_RealizeSymbolAlias(private_,		"private");
	Gura_RealizeSymbol(privileged);
	Gura_RealizeSymbolAlias(protected_,		"protected");
	Gura_RealizeSymbol(ps1);
	Gura_RealizeSymbol(ps2);
	Gura_RealizeSymbolAlias(public_,		"public");
	Gura_RealizeSymbol(purple);
	Gura_RealizeSymbol(q);
	Gura_RealizeSymbol(query);
	Gura_RealizeSymbol(quote);
	Gura_RealizeSymbol(r);
	Gura_RealizeSymbol(raise);
	Gura_RealizeSymbol(ratio);
	Gura_RealizeSymbol(raw);
	Gura_RealizeSymbol(readable);
	Gura_RealizeSymbol(real);
	Gura_RealizeSymbol(red);
	Gura_RealizeSymbol(reduce);
	Gura_RealizeSymbol(repeat);
	Gura_RealizeSymbol(rest);
	Gura_RealizeSymbol(rev);
	Gura_RealizeSymbol(rgb);
	Gura_RealizeSymbol(rgba);
	Gura_RealizeSymbol(rgbq);
	Gura_RealizeSymbol(right);
	Gura_RealizeSymbol(right_bottom);
	Gura_RealizeSymbol(right_bottom_horz);
	Gura_RealizeSymbol(right_bottom_vert);
	Gura_RealizeSymbol(right_top);
	Gura_RealizeSymbol(right_top_horz);
	Gura_RealizeSymbol(right_top_vert);
	Gura_RealizeSymbol(root);
	Gura_RealizeSymbol(s);
	Gura_RealizeSymbol(s16be);
	Gura_RealizeSymbol(s16le);
	Gura_RealizeSymbol(s32be);
	Gura_RealizeSymbol(s32le);
	Gura_RealizeSymbol(s64be);
	Gura_RealizeSymbol(s64le);
	Gura_RealizeSymbol(s8);
	Gura_RealizeSymbol(samples);
	Gura_RealizeSymbol(samplespersec);
	Gura_RealizeSymbol(saturday);
	Gura_RealizeSymbol(scheme);
	Gura_RealizeSymbol(sec);
	Gura_RealizeSymbol(secs);
	Gura_RealizeSymbol(semaphore);
	Gura_RealizeSymbol(set);
	Gura_RealizeSymbol(shrink);
	Gura_RealizeSymbol(shrinkable);
	Gura_RealizeSymbol(sibling);
	Gura_RealizeSymbol(siblings);
	Gura_RealizeSymbol(sin);
	Gura_RealizeSymbol(single);
	Gura_RealizeSymbol(sort);
	Gura_RealizeSymbol(source);
	Gura_RealizeSymbol(space);
	Gura_RealizeSymbol(sqrt);
	Gura_RealizeSymbol(stable);
	Gura_RealizeSymbol(stat);
	Gura_RealizeSymbolAlias(static_,		"static");
	Gura_RealizeSymbol(stay);
	Gura_RealizeSymbol(stderr);
	Gura_RealizeSymbol(stdin);
	Gura_RealizeSymbol(stdout);
	Gura_RealizeSymbol(sticky);
	Gura_RealizeSymbolAlias(sticky_at_top,	"sticky@top");
	Gura_RealizeSymbolAlias(sticky_at_btm,	"sticky@btm");
	Gura_RealizeSymbol(stream);
	Gura_RealizeSymbol(strict);
	Gura_RealizeSymbol(string);
	Gura_RealizeSymbol(suffix);
	Gura_RealizeSymbol(suffixmgr);
	Gura_RealizeSymbol(sunday);
	Gura_RealizeSymbol(super);
	Gura_RealizeSymbol(sv);
	Gura_RealizeSymbol(symbol);
	Gura_RealizeSymbol(symbol_func);
	Gura_RealizeSymbol(t);
	Gura_RealizeSymbolAlias(template_,		"template");
	Gura_RealizeSymbol(text);
	Gura_RealizeSymbolAlias(this_,			"this");
	Gura_RealizeSymbol(thursday);
	Gura_RealizeSymbol(timid);
	Gura_RealizeSymbol(timedelta);
	Gura_RealizeSymbol(top);
	Gura_RealizeSymbol(trace);
	Gura_RealizeSymbol(trailer);
	Gura_RealizeSymbol(transpose);
	Gura_RealizeSymbolAlias(true_,			"true");
	Gura_RealizeSymbolAlias(try_,			"try");
	Gura_RealizeSymbol(tuesday);
	Gura_RealizeSymbolAlias(typename_,		"typename");
	Gura_RealizeSymbol(typesym);
	Gura_RealizeSymbol(u);
	Gura_RealizeSymbol(u16be);
	Gura_RealizeSymbol(u16le);
	Gura_RealizeSymbol(u32be);
	Gura_RealizeSymbol(u32le);
	Gura_RealizeSymbol(u64be);
	Gura_RealizeSymbol(u64le);
	Gura_RealizeSymbol(u8);
	Gura_RealizeSymbol(unary);
	Gura_RealizeSymbol(unixtime);
	Gura_RealizeSymbol(unknown);
	Gura_RealizeSymbol(up);
	Gura_RealizeSymbol(upper);
	Gura_RealizeSymbol(uri);
	Gura_RealizeSymbol(urlpath);
	Gura_RealizeSymbol(usec);
	Gura_RealizeSymbol(usecs);
	Gura_RealizeSymbol(user);
	Gura_RealizeSymbol(utc);
	Gura_RealizeSymbol(utf16);
	Gura_RealizeSymbol(utf32);
	Gura_RealizeSymbol(utf8);
	Gura_RealizeSymbol(v);
	Gura_RealizeSymbol(value);
	Gura_RealizeSymbol(values);
	Gura_RealizeSymbol(vert);
	Gura_RealizeSymbolAlias(void_,			"void");
	Gura_RealizeSymbol(w);
	Gura_RealizeSymbol(w3c);
	Gura_RealizeSymbol(wday);
	Gura_RealizeSymbol(websafe);
	Gura_RealizeSymbol(wednesday);
	Gura_RealizeSymbol(week);
	Gura_RealizeSymbolAlias(while_,			"while");
	Gura_RealizeSymbol(white);
	Gura_RealizeSymbol(width);
	Gura_RealizeSymbol(win256);
	Gura_RealizeSymbol(writable);
	Gura_RealizeSymbol(x);
	Gura_RealizeSymbol(xiter);
	Gura_RealizeSymbol(xiteritem);
	Gura_RealizeSymbol(xlist);
	Gura_RealizeSymbol(xlistitem);
	Gura_RealizeSymbol(xor);
	Gura_RealizeSymbol(xreduce);
	Gura_RealizeSymbol(xset);
	Gura_RealizeSymbol(y);
	Gura_RealizeSymbol(yday);
	Gura_RealizeSymbol(year);
	Gura_RealizeSymbol(yellow);
	Gura_RealizeSymbol(z);
	Gura_RealizeSymbol(zero);
	Gura_RealizeSymbol(zh);
}

const Symbol *SymbolPool::Add(const char *name)
{
	Symbol *pSymbol = new Symbol(_uniqNum, name);
	std::pair<Content::iterator, bool> rtn = _content.insert(pSymbol);
	if (rtn.second) {
		_uniqNum++;
	} else {
		Symbol::Delete(pSymbol);
	}
	pSymbol = *rtn.first;
	return pSymbol;
}

SymbolPool *SymbolPool::GetInstance()
{
	return _pInst;
}

}
