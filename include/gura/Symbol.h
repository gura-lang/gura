//=============================================================================
// Symbol
//=============================================================================
#ifndef __GURA_SYMBOL_H__
#define __GURA_SYMBOL_H__

#include "Common.h"

#define Gura_Symbol(name) (SymbolPool::GetInstance()->_pSymbol_##name)

#define Gura_DeclareSymbol(name) \
const Symbol *_pSymbol_##name

#define Gura_RealizeSymbol(name) \
_pSymbol_##name = Symbol::Add(#name);

#define Gura_RealizeSymbolAlias(name, str) \
_pSymbol_##name = Symbol::Add(str);

#define Gura_UserSymbol(name) (_pUserSymbol_##name)

#if defined(GURA_MODULE_MAIN)
#define Gura_DeclareUserSymbol(name) \
const Symbol *_pUserSymbol_##name = nullptr;
#else
#define Gura_DeclareUserSymbol(name) \
extern const Symbol *_pUserSymbol_##name;
#endif

#define Gura_DeclarePrivUserSymbol(name) \
static const Symbol *_pUserSymbol_##name = nullptr;

#define Gura_RealizeUserSymbol(name) \
_pUserSymbol_##name = Symbol::Add(#name);

#define Gura_RealizeUserSymbolAlias(name, str) \
_pUserSymbol_##name = Symbol::Add(str);

namespace Gura {

class Expr;
class SymbolSet;
class ValueList;

//-----------------------------------------------------------------------------
// Symbol
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Symbol {
public:
	typedef UInt UniqNumber;
	struct LessThan {
		inline bool operator()(const Symbol *pSymbol1, const Symbol *pSymbol2) const {
			return pSymbol1->GetUniqNum() < pSymbol2->GetUniqNum();
		}
	};
	struct LessThan_Name {
		inline bool operator()(const Symbol *pSymbol1, const Symbol *pSymbol2) const {
			return ::strcmp(pSymbol1->GetName(), pSymbol2->GetName()) < 0;
		}
	};
	struct Hasher {
		inline size_t operator()(const Symbol *pSymbol) const {
			return static_cast<size_t>(pSymbol->GetUniqNum());
		}
	};
	struct EqualTo {
		inline bool operator()(const Symbol *pSymbol1, const Symbol *pSymbol2) const {
			return pSymbol1->GetUniqNum() == pSymbol2->GetUniqNum();
		}
	};
public:
	typedef std::set<const Symbol *, LessThan> Set;
	typedef std::map<ULong, const Symbol *> MapFromFlag;
	typedef std::map<const Symbol *, ULong, LessThan> MapToFlag;
	typedef std::map<OccurPattern, const Symbol *> MapFromOccurPattern;
	typedef std::map<const Symbol *, OccurPattern, LessThan> MapToOccurPattern;
	typedef std::map<ResultMode, const Symbol *> MapFromResultMode;
	typedef std::map<const Symbol *, ResultMode, LessThan> MapToResultMode;
private:
	UniqNumber _uniqNum;
	char *_name;
public:
	static const Symbol *Empty;
	static const Symbol *Excl;
	static const Symbol *Dollar;
	static const Symbol *Percnt;
	static const Symbol *PercntPercnt;
	static const Symbol *Amp;
	static const Symbol *Ast;
	static const Symbol *Plus;
	static const Symbol *Quest;
	static const Symbol *Tilde;
	static const Symbol *Hyphen;
private:
	static Set _setOfFlowControlSymbol;
	static MapFromFlag _mapFromFlag;
	static MapToFlag _mapToFlag;
	static MapFromOccurPattern _mapFromOccurPattern;
	static MapToOccurPattern _mapToOccurPattern;
	static MapFromResultMode _mapFromResultMode;
	static MapToResultMode _mapToResultMode;
public:
	Symbol(UniqNumber uniqNum, const char *name);
	~Symbol();
	bool IsFlowControlSymbol() const;
	inline static void Delete(Symbol *pSymbol) { delete pSymbol; }
	inline UniqNumber GetUniqNum() const { return _uniqNum; }
	inline const char *GetName() const { return _name; }
	inline bool IsIdentical(const Symbol *pSymbol) const {
		return GetUniqNum() == pSymbol->GetUniqNum();
	}
	inline bool IsNone() const { return _name[0] == '\0'; }
	inline bool IsPrivateName() const { return _name[0] == '_' && _name[1] == '_'; }
	static const Symbol *Add(const char *name);
public:
	static void Bootup();
	static const Symbol *FromFlag(ULong flag);
	static ULong ToFlag(const Symbol *pSymbol);
	static ULong ToFlags(const SymbolSet &symbolSet);
	static const Symbol *FromOccurPattern(OccurPattern occurPattern);
	static OccurPattern ToOccurPattern(const Symbol *pSymbol);
	static const Symbol *FromResultMode(ResultMode resultMode);
	static ResultMode ToResultMode(const Symbol *pSymbol);
	static String MakeAttrForFlags(ULong flagsToSet, ULong flagsToClear);
	static String MakeAttrForResultMode(ResultMode resultMode);
};

//-----------------------------------------------------------------------------
// SymbolList
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE SymbolList : public std::vector<const Symbol *> {
public:
	static const SymbolList Empty;
public:
	inline SymbolList() {}
	String Join(const char *sep) const;
	String Join(const char sepChar) const;
	static String Join(SymbolList::const_iterator ppSymbol,
				SymbolList::const_iterator ppSymbolEnd, const char *sep);
	static String Join(SymbolList::const_iterator ppSymbol,
				SymbolList::const_iterator ppSymbolEnd, const char sepChar);
	void SortByName();
	bool AddFromString(const char *str);
	bool AddFromExpr(const Expr *pExpr);
};

//-----------------------------------------------------------------------------
// SymbolSet
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE SymbolSet : public std::set<const Symbol *, Symbol::LessThan> {
public:
	static const SymbolSet Empty;
public:
	inline SymbolSet() {}
	SymbolSet(const SymbolSet &symbolSet);
	~SymbolSet();
	void operator=(const SymbolSet &symbolSet);
	inline bool IsSet(const Symbol *pSymbol) const {
		return find(pSymbol) != const_cast<SymbolSet *>(this)->end();
	}
	inline void Insert(const Symbol *pSymbol) {
		insert(pSymbol);
	}
	void Insert(const SymbolSet &symbolSet);
	void Insert(const ValueList &valList);
};

//-----------------------------------------------------------------------------
// SymbolSetShared
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE SymbolSetShared {
private:
	int _cntRef;
	SymbolSet _symbolSet;
public:
	Gura_DeclareReferenceAccessor(SymbolSetShared)
public:
	inline SymbolSetShared() : _cntRef(1) {}
	inline SymbolSetShared(const SymbolSet &symbolSet) :
		_cntRef(1), _symbolSet(symbolSet) {}
	inline SymbolSetShared(const SymbolSetShared &symbolSetShared) :
		_cntRef(1), _symbolSet(symbolSetShared._symbolSet) {}
private:
	inline ~SymbolSetShared() {}
public:
	inline SymbolSet &GetSymbolSet() { return _symbolSet; }
	inline const SymbolSet &GetSymbolSet() const { return _symbolSet; }
};

//-----------------------------------------------------------------------------
// SymbolPool
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE SymbolPool {
public:
	Gura_DeclareSymbol(__arg__);
	Gura_DeclareSymbol(__del__);
	Gura_DeclareSymbol(__doc__);
	Gura_DeclareSymbol(__getitem__);
	Gura_DeclareSymbol(__getitemx__);
	Gura_DeclareSymbol(__getprop__);
	Gura_DeclareSymbol(__init__);
	Gura_DeclareSymbol(__name__);
	Gura_DeclareSymbol(__setitem__);
	Gura_DeclareSymbol(__setitemx__);
	Gura_DeclareSymbol(__setprop__);
	Gura_DeclareSymbol(__source__);
	Gura_DeclareSymbol(__str__);
	Gura_DeclareSymbol(__symbol__);
	Gura_DeclareSymbol(__cast__);
	Gura_DeclareSymbol(__castto__);
	Gura_DeclareSymbol(__serialize__);
	Gura_DeclareSymbol(__deserialize__);
	Gura_DeclareSymbol(__format_d__);
	Gura_DeclareSymbol(__format_u__);
	Gura_DeclareSymbol(__format_b__);
	Gura_DeclareSymbol(__format_o__);
	Gura_DeclareSymbol(__format_x__);
	Gura_DeclareSymbol(__format_e__);
	Gura_DeclareSymbol(__format_f__);
	Gura_DeclareSymbol(__format_g__);
	Gura_DeclareSymbol(__format_s__);
	Gura_DeclareSymbol(__format_c__);
	Gura_DeclareSymbol(_anonymous_);
	Gura_DeclareSymbol(a);
	Gura_DeclareSymbol(A);
	Gura_DeclareSymbol(abs);
	Gura_DeclareSymbol(align);
	Gura_DeclareSymbol(alpha);
	Gura_DeclareSymbol(and);
	Gura_DeclareSymbol(aqua);
	Gura_DeclareSymbol(ar);
	Gura_DeclareSymbol(arg);
	Gura_DeclareSymbol(argument);
	Gura_DeclareSymbol(argsymbols);
	Gura_DeclareSymbol(array);
	Gura_DeclareSymbol(ascend);
	Gura_DeclareSymbol(ascii);
	Gura_DeclareSymbol(asctime);
	Gura_DeclareSymbol(attrfront);
	Gura_DeclareSymbol(attrs);
	Gura_DeclareSymbol(attrsopt);
	Gura_DeclareSymbol(audio);
	Gura_DeclareSymbol(audiotype);
	Gura_DeclareSymbol(autoindent);
	Gura_DeclareSymbol(b);
	Gura_DeclareSymbol(B);
	Gura_DeclareSymbol(backward);
	Gura_DeclareSymbol(basic);
	Gura_DeclareSymbol(bcc);
	Gura_DeclareSymbol(be);
	Gura_DeclareSymbol(begin);
	Gura_DeclareSymbol(bfs);
	Gura_DeclareSymbol(bg);
	Gura_DeclareSymbol(bgr);
	Gura_DeclareSymbol(bgra);
	Gura_DeclareSymbol(bias);
	Gura_DeclareSymbol(biased);
	Gura_DeclareSymbol(binary);
	Gura_DeclareSymbol(bitmap);
	Gura_DeclareSymbol(bitspersample);
	Gura_DeclareSymbol(black);
	Gura_DeclareSymbol(block);
	Gura_DeclareSymbol(blockparam);
	Gura_DeclareSymbol(blue);
	Gura_DeclareSymbol(body);
	Gura_DeclareSymbol(boolean);
	Gura_DeclareSymbol(both);
	Gura_DeclareSymbol(bottom);
	Gura_DeclareSymbol(box);
	Gura_DeclareSymbol(break_);
	Gura_DeclareSymbol(brief);
	Gura_DeclareSymbol(bright_aqua);
	Gura_DeclareSymbol(bright_blue);
	Gura_DeclareSymbol(bright_cyan);
	Gura_DeclareSymbol(bright_green);
	Gura_DeclareSymbol(bright_magenta);
	Gura_DeclareSymbol(bright_purple);
	Gura_DeclareSymbol(bright_red);
	Gura_DeclareSymbol(bright_white);
	Gura_DeclareSymbol(bright_yellow);
	Gura_DeclareSymbol(byte);
	Gura_DeclareSymbol(bytes);
	Gura_DeclareSymbol(bytespersample);
	Gura_DeclareSymbol(c);
	Gura_DeclareSymbol(C);
	Gura_DeclareSymbol(car);
	Gura_DeclareSymbol(carray);
	Gura_DeclareSymbol(case_);
	Gura_DeclareSymbol(cast);
	Gura_DeclareSymbol(catch_);
	Gura_DeclareSymbol(cdr);
	Gura_DeclareSymbol(center);
	Gura_DeclareSymbol(channels);
	Gura_DeclareSymbol(child);
	Gura_DeclareSymbol(children);
	Gura_DeclareSymbol(chop);
	Gura_DeclareSymbol(clang);
	Gura_DeclareSymbol(close);
	Gura_DeclareSymbol(closure);
	Gura_DeclareSymbol(codec);
	Gura_DeclareSymbol(codecs);
	Gura_DeclareSymbol(color);
	Gura_DeclareSymbol(column);
	Gura_DeclareSymbol(complex);
	Gura_DeclareSymbol(const_);
	Gura_DeclareSymbol(continue_);
	Gura_DeclareSymbol(cos);
	Gura_DeclareSymbol(crammed);
	Gura_DeclareSymbol(cross);
	Gura_DeclareSymbol(cs);
	Gura_DeclareSymbol(cstr);
	Gura_DeclareSymbol(cur);
	Gura_DeclareSymbol(cut_extra_args);
	Gura_DeclareSymbol(cyan);
	Gura_DeclareSymbol(d);
	Gura_DeclareSymbol(D);
	Gura_DeclareSymbol(darwin);
	Gura_DeclareSymbol(datetime);
	Gura_DeclareSymbol(day);
	Gura_DeclareSymbol(days);
	Gura_DeclareSymbol(de);
	Gura_DeclareSymbol(decl);
	Gura_DeclareSymbol(declaration);
	Gura_DeclareSymbol(decls);
	Gura_DeclareSymbol(default_);
	Gura_DeclareSymbol(deg);
	Gura_DeclareSymbol(delta);
	Gura_DeclareSymbol(denom);
	Gura_DeclareSymbol(depth);
	Gura_DeclareSymbol(descend);
	Gura_DeclareSymbol(dfs);
	Gura_DeclareSymbol(dict);
	Gura_DeclareSymbol(dir);
	Gura_DeclareSymbol(directory);
	Gura_DeclareSymbol(doc);
	Gura_DeclareSymbol(document);
	Gura_DeclareSymbol(double_);
	Gura_DeclareSymbol(down);
	Gura_DeclareSymbol(dynamic_scope);
	Gura_DeclareSymbol(e);
	Gura_DeclareSymbol(E);
	Gura_DeclareSymbol(elemtype);
	Gura_DeclareSymbol(else_);
	Gura_DeclareSymbol(elsif);
	Gura_DeclareSymbol(en);
	Gura_DeclareSymbol(end);
	Gura_DeclareSymbol(end_marker);
	Gura_DeclareSymbol(environment);
	Gura_DeclareSymbol(eof);
	Gura_DeclareSymbol(eol);
	Gura_DeclareSymbol(error);
	Gura_DeclareSymbol(esc);
	Gura_DeclareSymbol(exp);
	Gura_DeclareSymbol(expr);
	Gura_DeclareSymbol(extern_);
	Gura_DeclareSymbol(f);
	Gura_DeclareSymbol(F);
	Gura_DeclareSymbol(false_);
	Gura_DeclareSymbol(fancy);
	Gura_DeclareSymbol(file);
	Gura_DeclareSymbol(finalize);
	Gura_DeclareSymbol(finalizer);
	Gura_DeclareSymbol(finally);
	Gura_DeclareSymbol(first);
	Gura_DeclareSymbol(firsteol);
	Gura_DeclareSymbol(flat);
	Gura_DeclareSymbol(float_);
	Gura_DeclareSymbol(for_);
	Gura_DeclareSymbol(force);
	Gura_DeclareSymbol(fork);
	Gura_DeclareSymbol(format);
	Gura_DeclareSymbol(formatter);
	Gura_DeclareSymbol(forward);
	Gura_DeclareSymbol(fr);
	Gura_DeclareSymbol(friday);
	Gura_DeclareSymbol(ftp);
	Gura_DeclareSymbol(fullname);
	Gura_DeclareSymbol(function);
	Gura_DeclareSymbol(func_scope);
	Gura_DeclareSymbol(g);
	Gura_DeclareSymbol(G);
	Gura_DeclareSymbol(gear);
	Gura_DeclareSymbol(gnuc);
	Gura_DeclareSymbol(gray);
	Gura_DeclareSymbol(green);
	Gura_DeclareSymbol(h);
	Gura_DeclareSymbol(H);
	Gura_DeclareSymbol(half);
	Gura_DeclareSymbol(height);
	Gura_DeclareSymbol(help);
	Gura_DeclareSymbol(horz);
	Gura_DeclareSymbol(host);
	Gura_DeclareSymbol(hour);
	Gura_DeclareSymbol(http);
	Gura_DeclareSymbol(i);
	Gura_DeclareSymbol(I);
	Gura_DeclareSymbol(icase);
	Gura_DeclareSymbol(identifier);
	Gura_DeclareSymbol(if_);
	Gura_DeclareSymbol(imag);
	Gura_DeclareSymbol(image);
	Gura_DeclareSymbol(imagetype);
	Gura_DeclareSymbol(indent);
	Gura_DeclareSymbol(index);
	Gura_DeclareSymbol(indices);
	Gura_DeclareSymbol(input);
	Gura_DeclareSymbol(input_at_left);
	Gura_DeclareSymbol(input_at_right);
	Gura_DeclareSymbol(inputgrad);
	Gura_DeclareSymbol(inputgrad_at_left);
	Gura_DeclareSymbol(inputgrad_at_right);
	Gura_DeclareSymbol(inside_scope);
	Gura_DeclareSymbol(int_);
	Gura_DeclareSymbol(int8);
	Gura_DeclareSymbol(int16);
	Gura_DeclareSymbol(int32);
	Gura_DeclareSymbol(int64);
	Gura_DeclareSymbol(invalid);
	Gura_DeclareSymbol(iter);
	Gura_DeclareSymbol(iterator);
	Gura_DeclareSymbol(iteritem);
	Gura_DeclareSymbol(j);
	Gura_DeclareSymbol(J);
	Gura_DeclareSymbol(ja);
	Gura_DeclareSymbol(k);
	Gura_DeclareSymbol(K);
	Gura_DeclareSymbol(ka);
	Gura_DeclareSymbol(ko);
	Gura_DeclareSymbol(l);
	Gura_DeclareSymbol(L);
	Gura_DeclareSymbol(lang);
	Gura_DeclareSymbol(langcode);
	Gura_DeclareSymbol(last);
	Gura_DeclareSymbol(lasteol);
	Gura_DeclareSymbol(last_index);
	Gura_DeclareSymbol(le);
	Gura_DeclareSymbol(leader);
	Gura_DeclareSymbol(left);
	Gura_DeclareSymbol(left_bottom);
	Gura_DeclareSymbol(left_bottom_horz);
	Gura_DeclareSymbol(left_bottom_vert);
	Gura_DeclareSymbol(left_top);
	Gura_DeclareSymbol(left_top_horz);
	Gura_DeclareSymbol(left_top_vert);
	Gura_DeclareSymbol(len);
	Gura_DeclareSymbol(lexer);
	Gura_DeclareSymbol(line_);
	Gura_DeclareSymbol(lineno);
	Gura_DeclareSymbol(linenobtm);
	Gura_DeclareSymbol(linux);
	Gura_DeclareSymbol(list);
	Gura_DeclareSymbol(listitem);
	Gura_DeclareSymbol(listvar);
	Gura_DeclareSymbol(local);
	Gura_DeclareSymbol(log);
	Gura_DeclareSymbol(loose);
	Gura_DeclareSymbol(lower);
	Gura_DeclareSymbol(m);
	Gura_DeclareSymbol(M);
	Gura_DeclareSymbol(magenta);
	Gura_DeclareSymbol(map);
	Gura_DeclareSymbol(math);
	Gura_DeclareSymbol(matrix);
	Gura_DeclareSymbol(message);
	Gura_DeclareSymbol(min);
	Gura_DeclareSymbol(minus);
	Gura_DeclareSymbol(misc);
	Gura_DeclareSymbol(mixin_type);
	Gura_DeclareSymbol(mode);
	Gura_DeclareSymbol(monday);
	Gura_DeclareSymbol(monitor);
	Gura_DeclareSymbol(mono);
	Gura_DeclareSymbol(month);
	Gura_DeclareSymbol(msc);
	Gura_DeclareSymbol(msec);
	Gura_DeclareSymbol(msecs);
	Gura_DeclareSymbol(mswin);
	Gura_DeclareSymbol(multi);
	Gura_DeclareSymbol(n);
	Gura_DeclareSymbol(N);
	Gura_DeclareSymbol(name);
	Gura_DeclareSymbol(ndim);
	Gura_DeclareSymbol(neat);
	Gura_DeclareSymbol(next);
	Gura_DeclareSymbol(nil);
	Gura_DeclareSymbol(nocast);
	Gura_DeclareSymbol(noesc);
	Gura_DeclareSymbol(noflat);
	Gura_DeclareSymbol(noindent);
	Gura_DeclareSymbol(nomap);
	Gura_DeclareSymbol(nonamed);
	Gura_DeclareSymbol(none);
	Gura_DeclareSymbol(norm);
	Gura_DeclareSymbol(nosort);
	Gura_DeclareSymbol(nsec);
	Gura_DeclareSymbol(nsecs);
	Gura_DeclareSymbol(number);
	Gura_DeclareSymbol(numer);
	Gura_DeclareSymbol(o);
	Gura_DeclareSymbol(O);
	Gura_DeclareSymbol(object);
	Gura_DeclareSymbol(offset);
	Gura_DeclareSymbol(oneline);
	Gura_DeclareSymbol(open);
	Gura_DeclareSymbol(open_l);
	Gura_DeclareSymbol(open_r);
	Gura_DeclareSymbol(operator_);
	Gura_DeclareSymbol(or);
	Gura_DeclareSymbol(output);
	Gura_DeclareSymbol(outputgrad);
	Gura_DeclareSymbol(overwrite);
	Gura_DeclareSymbol(p);
	Gura_DeclareSymbol(P);
	Gura_DeclareSymbol(padding);
	Gura_DeclareSymbol(palette);
	Gura_DeclareSymbol(parent);
	Gura_DeclareSymbol(parents);
	Gura_DeclareSymbol(password);
	Gura_DeclareSymbol(path);
	Gura_DeclareSymbol(pathname);
	Gura_DeclareSymbol(percent);
	Gura_DeclareSymbol(pi);
	Gura_DeclareSymbol(pl);
	Gura_DeclareSymbol(plus);
	Gura_DeclareSymbol(pointer);
	Gura_DeclareSymbol(port);
	Gura_DeclareSymbol(post);
	Gura_DeclareSymbol(postext);
	Gura_DeclareSymbol(pre);
	Gura_DeclareSymbol(prec);
	Gura_DeclareSymbol(prefix);
	Gura_DeclareSymbol(prev);
	Gura_DeclareSymbol(private_);
	Gura_DeclareSymbol(privileged);
	Gura_DeclareSymbol(protected_);
	Gura_DeclareSymbol(ps1);
	Gura_DeclareSymbol(ps2);
	Gura_DeclareSymbol(public_);
	Gura_DeclareSymbol(purple);
	Gura_DeclareSymbol(q);
	Gura_DeclareSymbol(Q);
	Gura_DeclareSymbol(query);
	Gura_DeclareSymbol(quote);
	Gura_DeclareSymbol(r);
	Gura_DeclareSymbol(R);
	Gura_DeclareSymbol(raise);
	Gura_DeclareSymbol(ratio);
	Gura_DeclareSymbol(raw);
	Gura_DeclareSymbol(read);
	Gura_DeclareSymbol(readable);
	Gura_DeclareSymbol(real);
	Gura_DeclareSymbol(red);
	Gura_DeclareSymbol(reduce);
	Gura_DeclareSymbol(relu);
	Gura_DeclareSymbol(repeat);
	Gura_DeclareSymbol(rest);
	Gura_DeclareSymbol(rev);
	Gura_DeclareSymbol(rgb);
	Gura_DeclareSymbol(rgba);
	Gura_DeclareSymbol(rgbq);
	Gura_DeclareSymbol(right);
	Gura_DeclareSymbol(right_bottom);
	Gura_DeclareSymbol(right_bottom_horz);
	Gura_DeclareSymbol(right_bottom_vert);
	Gura_DeclareSymbol(right_top);
	Gura_DeclareSymbol(right_top_horz);
	Gura_DeclareSymbol(right_top_vert);
	Gura_DeclareSymbol(root);
	Gura_DeclareSymbol(row);
	Gura_DeclareSymbol(s);
	Gura_DeclareSymbol(S);
	Gura_DeclareSymbol(s16be);
	Gura_DeclareSymbol(s16le);
	Gura_DeclareSymbol(s32be);
	Gura_DeclareSymbol(s32le);
	Gura_DeclareSymbol(s64be);
	Gura_DeclareSymbol(s64le);
	Gura_DeclareSymbol(s8);
	Gura_DeclareSymbol(same);
	Gura_DeclareSymbol(sample);
	Gura_DeclareSymbol(samples);
	Gura_DeclareSymbol(samplespersec);
	Gura_DeclareSymbol(saturday);
	Gura_DeclareSymbol(scheme);
	Gura_DeclareSymbol(sec);
	Gura_DeclareSymbol(secs);
	Gura_DeclareSymbol(semaphore);
	Gura_DeclareSymbol(set);
	Gura_DeclareSymbol(shape);
	Gura_DeclareSymbol(shrink);
	Gura_DeclareSymbol(shrinkable);
	Gura_DeclareSymbol(sibling);
	Gura_DeclareSymbol(siblings);
	Gura_DeclareSymbol(sigmoid);
	Gura_DeclareSymbol(sin);
	Gura_DeclareSymbol(single);
	Gura_DeclareSymbol(size);
	Gura_DeclareSymbol(size_at_all);
	Gura_DeclareSymbol(sort);
	Gura_DeclareSymbol(source);
	Gura_DeclareSymbol(space);
	Gura_DeclareSymbol(sqrt);
	Gura_DeclareSymbol(stable);
	Gura_DeclareSymbol(stat);
	Gura_DeclareSymbol(static_);
	Gura_DeclareSymbol(stay);
	Gura_DeclareSymbol(stderr);
	Gura_DeclareSymbol(stdin);
	Gura_DeclareSymbol(stdout);
	Gura_DeclareSymbol(sticky);
	Gura_DeclareSymbol(sticky_at_top);
	Gura_DeclareSymbol(sticky_at_btm);
	Gura_DeclareSymbol(stream);
	Gura_DeclareSymbol(strict);
	Gura_DeclareSymbol(string);
	Gura_DeclareSymbol(suffix);
	Gura_DeclareSymbol(suffixmgr);
	Gura_DeclareSymbol(sunday);
	Gura_DeclareSymbol(super);
	Gura_DeclareSymbol(surround);
	Gura_DeclareSymbol(sv);
	Gura_DeclareSymbol(symbol);
	Gura_DeclareSymbol(symbol_func);
	Gura_DeclareSymbol(t);
	Gura_DeclareSymbol(T);
	Gura_DeclareSymbol(target);
	Gura_DeclareSymbol(template_);
	Gura_DeclareSymbol(text);
	Gura_DeclareSymbol(this_);
	Gura_DeclareSymbol(thursday);
	Gura_DeclareSymbol(timedelta);
	Gura_DeclareSymbol(timid);
	Gura_DeclareSymbol(title);
	Gura_DeclareSymbol(top);
	Gura_DeclareSymbol(trace);
	Gura_DeclareSymbol(trailer);
	Gura_DeclareSymbol(transpose);
	Gura_DeclareSymbol(true_);
	Gura_DeclareSymbol(try_);
	Gura_DeclareSymbol(tuesday);
	Gura_DeclareSymbol(type);
	Gura_DeclareSymbol(typename_);
	Gura_DeclareSymbol(typesym);
	Gura_DeclareSymbol(u);
	Gura_DeclareSymbol(U);
	Gura_DeclareSymbol(u16be);
	Gura_DeclareSymbol(u16le);
	Gura_DeclareSymbol(u32be);
	Gura_DeclareSymbol(u32le);
	Gura_DeclareSymbol(u64be);
	Gura_DeclareSymbol(u64le);
	Gura_DeclareSymbol(u8);
	Gura_DeclareSymbol(unary);
	Gura_DeclareSymbol(unbias);
	Gura_DeclareSymbol(unbiased);
	Gura_DeclareSymbol(unit);
	Gura_DeclareSymbol(unitstep);
	Gura_DeclareSymbol(unix);
	Gura_DeclareSymbol(unixtime);
	Gura_DeclareSymbol(unknown);
	Gura_DeclareSymbol(up);
	Gura_DeclareSymbol(upper);
	Gura_DeclareSymbol(uri);
	Gura_DeclareSymbol(url);
	Gura_DeclareSymbol(urlpath);
	Gura_DeclareSymbol(usec);
	Gura_DeclareSymbol(usecs);
	Gura_DeclareSymbol(user);
	Gura_DeclareSymbol(utc);
	Gura_DeclareSymbol(utf16);
	Gura_DeclareSymbol(utf32);
	Gura_DeclareSymbol(utf8);
	Gura_DeclareSymbol(v);
	Gura_DeclareSymbol(V);
	Gura_DeclareSymbol(valid);
	Gura_DeclareSymbol(value);
	Gura_DeclareSymbol(values);
	Gura_DeclareSymbol(vert);
	Gura_DeclareSymbol(vertex);
	Gura_DeclareSymbol(void_);
	Gura_DeclareSymbol(w);
	Gura_DeclareSymbol(W);
	Gura_DeclareSymbol(w3c);
	Gura_DeclareSymbol(wday);
	Gura_DeclareSymbol(web);
	Gura_DeclareSymbol(websafe);
	Gura_DeclareSymbol(wednesday);
	Gura_DeclareSymbol(week);
	Gura_DeclareSymbol(while_);
	Gura_DeclareSymbol(white);
	Gura_DeclareSymbol(width);
	Gura_DeclareSymbol(win);
	Gura_DeclareSymbol(win256);
	Gura_DeclareSymbol(window);
	Gura_DeclareSymbol(windows);
	Gura_DeclareSymbol(write);
	Gura_DeclareSymbol(writable);
	Gura_DeclareSymbol(x);
	Gura_DeclareSymbol(X);
	Gura_DeclareSymbol(xiter);
	Gura_DeclareSymbol(xiteritem);
	Gura_DeclareSymbol(xlist);
	Gura_DeclareSymbol(xlistitem);
	Gura_DeclareSymbol(xor);
	Gura_DeclareSymbol(xreduce);
	Gura_DeclareSymbol(xset);
	Gura_DeclareSymbol(y);
	Gura_DeclareSymbol(Y);
	Gura_DeclareSymbol(yday);
	Gura_DeclareSymbol(year);
	Gura_DeclareSymbol(yellow);
	Gura_DeclareSymbol(z);
	Gura_DeclareSymbol(Z);
	Gura_DeclareSymbol(zero);
	Gura_DeclareSymbol(zh);
private:
	typedef std::set<Symbol *, Symbol::LessThan_Name> Content;
private:
	static SymbolPool *_pInst;
	Symbol::UniqNumber _uniqNum;
	Content _content;
private:
	inline SymbolPool() {}
public:
	~SymbolPool();
	static void Bootup();
	static SymbolPool *GetInstance();
	const Symbol *Add(const char *name);
private:
	void _Bootup();
private:
	inline SymbolPool(const SymbolPool &symbolPool) {}
	inline void operator=(const SymbolPool &symbolPool) {}
};

}

#endif
