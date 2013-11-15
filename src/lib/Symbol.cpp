#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// static variables
//-----------------------------------------------------------------------------
SymbolPool *SymbolPool::_pInst = NULL;

const SymbolSet SymbolSet::Null;

//-----------------------------------------------------------------------------
// Symbol
//-----------------------------------------------------------------------------
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
	return 
		IsIdentical(Gura_Symbol(if_)) ||
		IsIdentical(Gura_Symbol(elsif)) ||
		IsIdentical(Gura_Symbol(repeat)) ||
		IsIdentical(Gura_Symbol(while_)) ||
		IsIdentical(Gura_Symbol(for_)) ||
		IsIdentical(Gura_Symbol(cross));
}

//-----------------------------------------------------------------------------
// SymbolList
//-----------------------------------------------------------------------------
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
	std::stable_sort(begin(), end(), Symbol::KeyCompare_Name());
}

//-----------------------------------------------------------------------------
// SymbolSet
//-----------------------------------------------------------------------------
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

//-----------------------------------------------------------------------------
// SymbolPool
//-----------------------------------------------------------------------------
SymbolPool::~SymbolPool()
{
	foreach (Content, ppSymbol, _content) {
		Symbol::Delete(*ppSymbol);
	}
}

void SymbolPool::Initialize()
{
	if (_pInst == NULL) {
		_pInst = new SymbolPool();
		_pInst->_Initialize();
	}
}

void SymbolPool::_Initialize()
{
	Gura_RealizeSymbolAlias(Char_Add,		"+");
	Gura_RealizeSymbolAlias(Char_And,		"&");
	Gura_RealizeSymbolAlias(Char_Mod,		"%");
	Gura_RealizeSymbolAlias(Char_ModMod,	"%%");
	Gura_RealizeSymbolAlias(Char_Mul,		"*");
	Gura_RealizeSymbolAlias(Char_Question,	"?");
	Gura_RealizeSymbolAlias(Str_Empty,		"");
	Gura_RealizeSymbol(__args__);
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
	Gura_RealizeSymbolAlias(_anonymous_,	"*anonymous*");
	Gura_RealizeSymbol(align);
	Gura_RealizeSymbol(alpha);
	Gura_RealizeSymbol(and);
	Gura_RealizeSymbol(aqua);
	Gura_RealizeSymbol(ar);
	Gura_RealizeSymbol(arg);
	Gura_RealizeSymbol(args);
	Gura_RealizeSymbol(argsymbols);
	Gura_RealizeSymbol(ascend);
	Gura_RealizeSymbol(ascii);
	Gura_RealizeSymbol(asctime);
	Gura_RealizeSymbol(audiotype);
	Gura_RealizeSymbol(autoindent);
	Gura_RealizeSymbol(backward);
	Gura_RealizeSymbol(basic);
	Gura_RealizeSymbol(bcc);
	Gura_RealizeSymbol(begin);
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
	Gura_RealizeSymbol(car);
	Gura_RealizeSymbol(carray);
	Gura_RealizeSymbol(cast);
	Gura_RealizeSymbol(cdr);
	Gura_RealizeSymbol(center);
	Gura_RealizeSymbol(channels);
	Gura_RealizeSymbol(child);
	Gura_RealizeSymbol(children);
	Gura_RealizeSymbol(chop);
	Gura_RealizeSymbol(codec);
	Gura_RealizeSymbol(codecs);
	Gura_RealizeSymbol(color);
	Gura_RealizeSymbolAlias(const_,			"const");
	Gura_RealizeSymbolAlias(continue_,		"continue");
	Gura_RealizeSymbol(cos);
	Gura_RealizeSymbol(crammed);
	Gura_RealizeSymbol(cross);
	Gura_RealizeSymbol(cs);
	Gura_RealizeSymbol(cstr);
	Gura_RealizeSymbol(cur);
	Gura_RealizeSymbol(cyan);
	Gura_RealizeSymbol(day);
	Gura_RealizeSymbol(days);
	Gura_RealizeSymbol(de);
	Gura_RealizeSymbol(decl);
	Gura_RealizeSymbol(decls);
	Gura_RealizeSymbolAlias(default_,		"default");
	Gura_RealizeSymbol(deg);
	Gura_RealizeSymbol(descend);
	Gura_RealizeSymbol(dir);
	Gura_RealizeSymbol(down);
	Gura_RealizeSymbol(dynamic_scope);
	Gura_RealizeSymbol(e);
	Gura_RealizeSymbolAlias(else_,			"else");
	Gura_RealizeSymbol(elsif);
	Gura_RealizeSymbol(en);
	Gura_RealizeSymbol(end);
	Gura_RealizeSymbol(end_marker);
	Gura_RealizeSymbol(eof);
	Gura_RealizeSymbol(eol);
	Gura_RealizeSymbol(esc);
	Gura_RealizeSymbol(exp);
	Gura_RealizeSymbol(expr);
	Gura_RealizeSymbolAlias(extern_,		"extern");
	Gura_RealizeSymbolAlias(false_,			"false");
	Gura_RealizeSymbol(fancy);
	Gura_RealizeSymbol(file);
	Gura_RealizeSymbol(finalizer);
	Gura_RealizeSymbol(firsteol);
	Gura_RealizeSymbol(flat);
	Gura_RealizeSymbolAlias(for_,			"for");
	Gura_RealizeSymbol(force);
	Gura_RealizeSymbol(fork);
	Gura_RealizeSymbol(format);
	Gura_RealizeSymbol(forward);
	Gura_RealizeSymbol(fr);
	Gura_RealizeSymbol(friday);
	Gura_RealizeSymbol(ftp);
	Gura_RealizeSymbol(fullname);
	Gura_RealizeSymbol(func_scope);
	Gura_RealizeSymbol(gnuc);
	Gura_RealizeSymbol(gray);
	Gura_RealizeSymbol(green);
	Gura_RealizeSymbol(height);
	Gura_RealizeSymbol(help);
	Gura_RealizeSymbol(horz);
	Gura_RealizeSymbol(host);
	Gura_RealizeSymbol(hour);
	Gura_RealizeSymbol(http);
	Gura_RealizeSymbol(icase);
	Gura_RealizeSymbol(identifier);
	Gura_RealizeSymbolAlias(if_,			"if");
	Gura_RealizeSymbol(imagetype);
	Gura_RealizeSymbol(indent);
	Gura_RealizeSymbol(index);
	Gura_RealizeSymbol(indices);
	Gura_RealizeSymbol(inside_scope);
	Gura_RealizeSymbol(iter);
	Gura_RealizeSymbol(iteritem);
	Gura_RealizeSymbol(j);
	Gura_RealizeSymbol(ja);
	Gura_RealizeSymbol(ka);
	Gura_RealizeSymbol(lang);
	Gura_RealizeSymbol(last_index);
	Gura_RealizeSymbol(lasteol);
	Gura_RealizeSymbol(leader);
	Gura_RealizeSymbol(left);
	Gura_RealizeSymbol(len);
	Gura_RealizeSymbolAlias(line_,			"line");
	Gura_RealizeSymbol(lineno);
	Gura_RealizeSymbol(linenobtm);
	Gura_RealizeSymbol(linux);
	Gura_RealizeSymbol(list);
	Gura_RealizeSymbol(listitem);
	Gura_RealizeSymbol(local);
	Gura_RealizeSymbol(log);
	Gura_RealizeSymbol(loose);
	Gura_RealizeSymbol(lower);
	Gura_RealizeSymbol(magenta);
	Gura_RealizeSymbol(map);
	Gura_RealizeSymbol(math);
	Gura_RealizeSymbol(message);
	Gura_RealizeSymbol(min);
	Gura_RealizeSymbol(misc);
	Gura_RealizeSymbol(mixin_type);
	Gura_RealizeSymbol(mode);
	Gura_RealizeSymbol(monday);
	Gura_RealizeSymbol(mono);
	Gura_RealizeSymbol(month);
	Gura_RealizeSymbol(msc);
	Gura_RealizeSymbol(msec);
	Gura_RealizeSymbol(msecs);
	Gura_RealizeSymbol(mswin);
	Gura_RealizeSymbol(multi);
	Gura_RealizeSymbol(name);
	Gura_RealizeSymbol(neat);
	Gura_RealizeSymbol(next);
	Gura_RealizeSymbol(nil);
	Gura_RealizeSymbol(nocast);
	Gura_RealizeSymbol(noesc);
	Gura_RealizeSymbol(noflat);
	Gura_RealizeSymbol(noindent);
	Gura_RealizeSymbol(nomap);
	Gura_RealizeSymbol(nosort);
	Gura_RealizeSymbol(nsec);
	Gura_RealizeSymbol(nsecs);
	Gura_RealizeSymbol(number);
	Gura_RealizeSymbol(oneline);
	Gura_RealizeSymbol(open);
	Gura_RealizeSymbol(open_l);
	Gura_RealizeSymbol(open_r);
	Gura_RealizeSymbolAlias(operator_,		"operator");
	Gura_RealizeSymbol(or);
	Gura_RealizeSymbol(overwrite);
	Gura_RealizeSymbol(palette);
	Gura_RealizeSymbol(parent);
	Gura_RealizeSymbol(parents);
	Gura_RealizeSymbol(password);
	Gura_RealizeSymbol(path);
	Gura_RealizeSymbol(pathname);
	Gura_RealizeSymbol(pi);
	Gura_RealizeSymbol(pl);
	Gura_RealizeSymbol(port);
	Gura_RealizeSymbol(postext);
	Gura_RealizeSymbol(prev);
	Gura_RealizeSymbolAlias(private_,		"private");
	Gura_RealizeSymbol(privileged);
	Gura_RealizeSymbolAlias(protected_,		"protected");
	Gura_RealizeSymbol(ps1);
	Gura_RealizeSymbol(ps2);
	Gura_RealizeSymbolAlias(public_,		"public");
	Gura_RealizeSymbol(purple);
	Gura_RealizeSymbol(quote);
	Gura_RealizeSymbol(r);
	Gura_RealizeSymbol(raise);
	Gura_RealizeSymbol(raw);
	Gura_RealizeSymbol(readable);
	Gura_RealizeSymbol(red);
	Gura_RealizeSymbol(reduce);
	Gura_RealizeSymbol(repeat);
	Gura_RealizeSymbol(rest);
	Gura_RealizeSymbol(rev);
	Gura_RealizeSymbol(rgb);
	Gura_RealizeSymbol(rgba);
	Gura_RealizeSymbol(rgbq);
	Gura_RealizeSymbol(right);
	Gura_RealizeSymbol(root);
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
	Gura_RealizeSymbol(set);
	Gura_RealizeSymbol(shrink);
	Gura_RealizeSymbol(shrinkable);
	Gura_RealizeSymbol(sibling);
	Gura_RealizeSymbol(siblings);
	Gura_RealizeSymbol(sin);
	Gura_RealizeSymbol(single);
	Gura_RealizeSymbol(sort);
	Gura_RealizeSymbol(sqrt);
	Gura_RealizeSymbol(stable);
	Gura_RealizeSymbol(stat);
	Gura_RealizeSymbolAlias(static_,		"static");
	Gura_RealizeSymbol(stay);
	Gura_RealizeSymbol(stderr);
	Gura_RealizeSymbol(stdin);
	Gura_RealizeSymbol(stdout);
	Gura_RealizeSymbol(sticky);
	Gura_RealizeSymbol(sticky_l);
	Gura_RealizeSymbol(sticky_r);
	Gura_RealizeSymbol(stream);
	Gura_RealizeSymbol(strict);
	Gura_RealizeSymbol(string);
	Gura_RealizeSymbol(sunday);
	Gura_RealizeSymbol(super);
	Gura_RealizeSymbol(sv);
	Gura_RealizeSymbol(symbol);
	Gura_RealizeSymbol(symbol_func);
	Gura_RealizeSymbol(text);
	Gura_RealizeSymbolAlias(this_,			"this");
	Gura_RealizeSymbol(thursday);
	Gura_RealizeSymbol(top);
	Gura_RealizeSymbol(trace);
	Gura_RealizeSymbol(trailer);
	Gura_RealizeSymbol(transpose);
	Gura_RealizeSymbolAlias(true_,			"true");
	Gura_RealizeSymbol(tuesday);
	Gura_RealizeSymbolAlias(typename_,		"typename");
	Gura_RealizeSymbol(typesym);
	Gura_RealizeSymbol(u16be);
	Gura_RealizeSymbol(u16le);
	Gura_RealizeSymbol(u32be);
	Gura_RealizeSymbol(u32le);
	Gura_RealizeSymbol(u64be);
	Gura_RealizeSymbol(u64le);
	Gura_RealizeSymbol(u8);
	Gura_RealizeSymbol(unary);
	Gura_RealizeSymbol(unixtime);
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

//-----------------------------------------------------------------------------
// OccurPattern
//-----------------------------------------------------------------------------
const Symbol *GetOccurPatternSymbol(OccurPattern occurPattern)
{
	return
		(occurPattern == OCCUR_ZeroOrOnce)? Gura_Symbol(Char_Question) :
		(occurPattern == OCCUR_ZeroOrMore)? Gura_Symbol(Char_Mul) :
		(occurPattern == OCCUR_OnceOrMore)? Gura_Symbol(Char_Add) :
		Gura_Symbol(Str_Empty);
}

}
