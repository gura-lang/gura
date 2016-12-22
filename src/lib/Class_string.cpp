//=============================================================================
// Gura class: string
//=============================================================================
#include "stdafx.h"

namespace Gura {

static const char *helpDoc_en = R"**(
)**";

//-----------------------------------------------------------------------------
// Implementation of suffix manager
//-----------------------------------------------------------------------------
Gura_ImplementSuffixMgrForString($)
{
	return Value(body);
}

//-----------------------------------------------------------------------------
// Implementation of methods
//-----------------------------------------------------------------------------
// string#align(width:number, padding:string => ' '):map:[center,left,right] {block?}
Gura_DeclareMethod(string, align)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "width", VTYPE_number);
	DeclareArg(env, "padding", VTYPE_string, OCCUR_Once, FLAG_None, 0, new Expr_Value(Value(" ")));
	DeclareAttr(Gura_Symbol(center));
	DeclareAttr(Gura_Symbol(left));
	DeclareAttr(Gura_Symbol(right));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), 
		"Align the string to the left, right or center within the specified `width`\n"
		"and returns the result.\n"
		"\n"
		"The following attributes specify the alignment position:\n"
		"\n"
		"- `:center` .. Aligns to the center. This is the default.\n"
		"- `:left` .. Aligns to the left\n"
		"- `:right` .. Aligns to the right\n"
		"\n"
		"If the string width is narrower than the specified `width`, nothing would be done.\n"
		"\n"
		"It uses a string specified by the argument `padding` to fill lacking spaces.\n"
		"If omitted, a white space is used for padding.\n"
		"\n"
		"This method takes into account the character width based on the specification\n"
		"of East Asian Width. A kanji-character occupies two characters in width.\n");
}

Gura_ImplementMethod(string, align)
{
	Signal &sig = env.GetSignal();
	size_t width = arg.GetSizeT(0);
	const char *padding = arg.GetString(1);
	if (Length(padding) != 1) {
		sig.SetError(ERR_ValueError, "padding must consist of a single character");
		return Value::Nil;
	}
	String str;
	if (arg.IsSet(Gura_Symbol(right))) {
		str = RJust(arg.GetValueThis().GetString(), width, padding);
	} else if (arg.IsSet(Gura_Symbol(left))) {
		str = LJust(arg.GetValueThis().GetString(), width, padding);
	} else {
		str = Center(arg.GetValueThis().GetString(), width, padding);
	}
	return ReturnValue(env, arg, Value(str));
}

// string#binary() {block?}
Gura_DeclareMethodPrimitive(string, binary)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Converts the string into `binary` instance.");
}

Gura_ImplementMethod(string, binary)
{
	const char *str = arg.GetValueThis().GetString();
	return ReturnValue(env, arg, Value(new Object_binary(env, str, ::strlen(str), true)));
}

// string#capitalize() {block?}
Gura_DeclareMethod(string, capitalize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), 
		"Returns a string that capitalizes the first character.\n");
}

Gura_ImplementMethod(string, capitalize)
{
	return ReturnValue(env, arg, Value(Capitalize(arg.GetValueThis().GetString())));
}

// string#chop(suffix*:string):[eol,icase] {block?}
Gura_DeclareMethod(string, chop)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "suffix", VTYPE_string, OCCUR_ZeroOrMore);
	DeclareAttr(Gura_Symbol(eol));
	DeclareAttr(Gura_Symbol(icase));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), 
		"Returns a string that removes a last character.\n"
		"\n"
		"If an attribute `:eol` is specified, only the end-of-line character shall be\n"
		"removed. In this case, if the end-of-line has a sequence of CR-LF, CR code\n"
		"shall be removed as well.");
}

Gura_ImplementMethod(string, chop)
{
	bool eolOnlyFlag = arg.IsSet(Gura_Symbol(eol));
	const ValueList &valList = arg.GetList(0);
	if (valList.empty()) {
		return Value(Chop(arg.GetValueThis().GetString(), eolOnlyFlag));
	}
	String rtn = arg.GetValueThis().GetStringSTL();
	if (eolOnlyFlag) rtn = Chop(rtn.c_str(), true);
	foreach_const (ValueList, pValue, valList) {
		const char *p1 = rtn.c_str();
		const char *p2 = EndsWith(p1, pValue->GetString(), arg.IsSet(Gura_Symbol(icase)));
		if (p2 != nullptr) return ReturnValue(env, arg, Value(String(p1, p2)));
	}
	return ReturnValue(env, arg, Value(rtn));
}

// string#decodeuri() {block?}
Gura_DeclareMethod(string, decodeuri)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), 
		"Returns a string in which percent-encoded characters are decoded.");
}

Gura_ImplementMethod(string, decodeuri)
{
	return ReturnValue(env, arg, Value(DecodeURI(arg.GetValueThis().GetString())));
}

// string#each():[utf8,utf32] {block?}
Gura_DeclareMethod(string, each)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareAttr(Gura_Symbol(utf8));
	DeclareAttr(Gura_Symbol(utf32));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), 
		"Creates an iterator generating strings of each character in the original one.\n"
		"\n"
		GURA_HELPTEXT_ITERATOR_en());
}

Gura_ImplementMethod(string, each)
{
	Class_string::IteratorEach::Attr attr =
		arg.IsSet(Gura_Symbol(utf8))? Class_string::IteratorEach::ATTR_UTF8 :
		arg.IsSet(Gura_Symbol(utf32))? Class_string::IteratorEach::ATTR_UTF32 :
		Class_string::IteratorEach::ATTR_None;
	Iterator *pIterator = new Class_string::IteratorEach(
								arg.GetValueThis().GetStringSTL(), -1, attr);
	return ReturnIterator(env, arg, pIterator);
}

// string#eachline(nlines?:number):[chop] {block?}
// conrresponding to file#readlines()
Gura_DeclareMethod(string, eachline)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "nlines", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareAttr(Gura_Symbol(chop));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), 
		"Creates an iterator generating strings of each line in the original one.\n"
		"\n"
		"In default, end-of-line characters are involved in the result.\n"
		"You can eliminates them by specifying `:chop` attribute.\n"
		"\n"
		GURA_HELPTEXT_ITERATOR_en());
}

Gura_ImplementMethod(string, eachline)
{
	int maxSplit = arg.Is_number(0)? arg.GetInt(0) : -1;
	bool includeEOLFlag = !arg.IsSet(Gura_Symbol(chop));
	return ReturnIterator(env, arg, new Class_string::IteratorLine(
					arg.GetValueThis().GetStringSTL(), maxSplit, includeEOLFlag));
}

// string#embed(dst?:stream:w):[noindent,lasteol]
Gura_DeclareMethod(string, embed)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "dst", VTYPE_stream, OCCUR_ZeroOrOnce, FLAG_Write);
	DeclareAttr(Gura_Symbol(noindent));
	DeclareAttr(Gura_Symbol(lasteol));
	AddHelp(
		Gura_Symbol(en),
		"Evaluates a string that contains embedded scripts\n"
		"and renders the result to the specified stream.\n"
		"\n"
		"If the stream is omitted, the function returns the rendered result as a string.\n"
		"\n"
		"Calling this method is equivalent to calling a method `string#template()` to\n"
		"create a `template` instance on which a method `template#render()` is applied afterward.\n");
}

Gura_ImplementMethod(string, embed)
{
	bool autoIndentFlag = !arg.IsSet(Gura_Symbol(noindent));
	bool appendLastEOLFlag = arg.IsSet(Gura_Symbol(lasteol));
	AutoPtr<Template> pTemplate(new Template());
	if (!pTemplate->Parse(env, arg.GetValueThis().GetString(), nullptr,
						  autoIndentFlag, appendLastEOLFlag)) return Value::Nil;
	if (arg.Is_stream(0)) {
		Stream &streamDst = arg.GetStream(0);
		pTemplate->Render(env, &streamDst);
		return Value::Nil;
	} else {
		String strDst;
		SimpleStream_StringWriter streamDst(strDst);
		if (!pTemplate->Render(env, &streamDst)) return Value::Nil;
		return Value(strDst);
	}
}

// string#encode(codec:codec) {block?}
Gura_DeclareMethodPrimitive(string, encode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "codec", VTYPE_codec);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Encodes the string with the given `codec` and return the result as a `binary`.\n");
}

Gura_ImplementMethod(string, encode)
{
	Signal &sig = env.GetSignal();
	Codec *pCodec = Object_codec::GetObject(arg, 0)->GetCodec();
	Binary buff;
	if (!pCodec->GetEncoder()->Encode(sig, buff, arg.GetValueThis().GetString())) {
		return Value::Nil;
	}
	return ReturnValue(env, arg, Value(new Object_binary(env, buff, true)));
}

// string#encodeuri() {block?}
Gura_DeclareMethod(string, encodeuri)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), 
		"Returns a string in which non-URIC characters are percent-encoded.\n");
}

Gura_ImplementMethod(string, encodeuri)
{
	return ReturnValue(env, arg, Value(EncodeURI(arg.GetValueThis().GetString())));
}

// string#endswith(suffix:string, endpos?:number):map:[rest,icase]
Gura_DeclareMethod(string, endswith)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "suffix",	VTYPE_string);
	DeclareArg(env, "endpos",	VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareAttr(Gura_Symbol(rest));
	DeclareAttr(Gura_Symbol(icase));
	AddHelp(
		Gura_Symbol(en), 
		"Returns `true` if the string ends with suffix.\n"
		"\n"
		"\n"
		"If attribute `:rest` is specified,\n"
		"it returns the rest part if the string ends with suffix, or `nil` otherewise.\n"
		"You can specify a bottom position for the matching by an argument `endpos`.\n"
		"\n"
		"With an attribute `:icase`, character cases are ignored while matching.");
}

Gura_ImplementMethod(string, endswith)
{
	const char *str = arg.GetValueThis().GetString();
	bool ignoreCaseFlag = arg.IsSet(Gura_Symbol(icase));
	const char *rtn = arg.Is_number(1)?
		EndsWith(str, arg.GetString(0), arg.GetInt(1), ignoreCaseFlag) :
		EndsWith(str, arg.GetString(0), ignoreCaseFlag);
	if (arg.IsSet(Gura_Symbol(rest))) {
		if (rtn == nullptr) return Value::Nil;
		return Value(str, rtn - str);
	}
	return rtn != nullptr;
}

// string#escape():[surround] {block?}
Gura_DeclareMethod(string, escape)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareAttr(Gura_Symbol(surround));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), 
		"Applies backslash escaping on characters in the string.\n"
		"If attribute `:surround` is specified, the result contains a pair of single- or double-\n"
		"quotation characters surrounding the string.\n");
}

Gura_ImplementMethod(string, escape)
{
	bool surroundFlag = arg.IsSet(Gura_Symbol(surround));
	return ReturnValue(env, arg, Value(MakeQuotedString(arg.GetValueThis().GetString(), surroundFlag)));
}

// string#escapehtml():[quote] {block?}
Gura_DeclareMethod(string, escapehtml)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareAttr(Gura_Symbol(quote));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), 
		"Converts some characters into HTML entity symbols.\n"
		"If attribute `:quote` is specified, a double-quotation character would be converted to\n"
		"an entity symbol \"&quot;\".");
}

Gura_ImplementMethod(string, escapehtml)
{
	bool quoteFlag = arg.IsSet(Gura_Symbol(quote));
	return ReturnValue(env, arg, Value(EscapeHtml(arg.GetValueThis().GetString(), quoteFlag)));
}

// string#find(sub:string, pos?:number => 0):map:[icase,rev]
Gura_DeclareMethod(string, find)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "sub",	VTYPE_string);
	DeclareArg(env, "pos",	VTYPE_number, OCCUR_Once, FLAG_None, 0, new Expr_Value(0));
	DeclareAttr(Gura_Symbol(icase));
	DeclareAttr(Gura_Symbol(rev));
	AddHelp(
		Gura_Symbol(en), 
		"Finds a sub string from the string and returns its position.\n"
		"\n"
		"Number of position starts from zero. You can specify a position to start\n"
		"finding by an argument pos. It returns nil if finding fails.\n"
		"\n"
		"With an attribute `:icase`, case of characters are ignored while finding.\n"
		"\n"
		"When an attribute `:rev`, finding starts from tail of the string\n");
}

Gura_ImplementMethod(string, find)
{
	return FindString(env, arg.GetValueThis().GetString(), arg.GetString(0), arg.GetInt(1),
					  arg.IsSet(Gura_Symbol(icase)), arg.IsSet(Gura_Symbol(rev)),
					  arg.IsResultList());
}

// string#fold(len:number, step?:number):[neat] {block?}
Gura_DeclareMethod(string, fold)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "len", VTYPE_number);
	DeclareArg(env, "step", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareAttr(Gura_Symbol(neat));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), 
		"Creates an iterator that folds the source string by the specified length.\n"
		"\n"
		"The argument `step` specifies the length of advancement for the next folding point.\n"
		"If omitted, it would be the same amount as `len`.\n"
		"\n"
		GURA_HELPTEXT_ITERATOR_en());
}

Gura_ImplementMethod(string, fold)
{
	int cntPerFold = arg.GetInt(0);
	int cntStep = arg.Is_number(1)? arg.GetInt(1) : cntPerFold;
	bool neatFlag = arg.IsSet(Gura_Symbol(neat));
	Iterator *pIterator = new Class_string::IteratorFold(
		arg.GetValueThis().GetStringSTL(), cntPerFold, cntStep, neatFlag);
	return ReturnIterator(env, arg, pIterator);
}

// string#foldw(width:number):[padding] {block?}
Gura_DeclareMethod(string, foldw)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "width", VTYPE_number);
	DeclareAttr(Gura_Symbol(padding));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), 
		"Creates an iterator that folds the source string by the specified width.\n"
		"\n"
		"This method takes into account the character width based on the specification\n"
		"of East Asian Width.\n"
		"\n"
		GURA_HELPTEXT_ITERATOR_en());
}

Gura_ImplementMethod(string, foldw)
{
	int widthPerFold = arg.GetInt(0);
	bool paddingFlag = arg.IsSet(Gura_Symbol(padding));
	Iterator *pIterator = new Class_string::IteratorFoldw(
		arg.GetValueThis().GetStringSTL(), widthPerFold, paddingFlag);
	return ReturnIterator(env, arg, pIterator);
}

// string#format(values*):map
Gura_DeclareMethod(string, format)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "values", VTYPE_any, OCCUR_ZeroOrMore);
	AddHelp(
		Gura_Symbol(en),
		"Taking the string instance as a printf-styled formatter string,\n"
		"it converts `values` into a string depending on formatter specifiers in it.\n");
}

Gura_ImplementMethod(string, format)
{
	Signal &sig = env.GetSignal();
	return Value(Formatter::FormatValueList(sig, arg.GetValueThis().GetString(), arg.GetList(0)));
}

// string#isalnum()
Gura_DeclareMethod(string, isalnum)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en),
		"Returns `true` if all the characters in the string are alphabet and digit.");
}

Gura_ImplementMethod(string, isalnum)
{
	return Value(CheckCType(arg.GetValueThis().GetString(), CTYPE_Alpha | CTYPE_Digit));
}

// string#isalpha()
Gura_DeclareMethod(string, isalpha)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en),
		"Returns `true` if all the characters in the string are alphabet.");
}

Gura_ImplementMethod(string, isalpha)
{
	return Value(CheckCType(arg.GetValueThis().GetString(), CTYPE_Alpha));
}

// string#isdigit()
Gura_DeclareMethod(string, isdigit)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en),
		"Returns `true` if all the characters in the string are digit.");
}

Gura_ImplementMethod(string, isdigit)
{
	return Value(CheckCType(arg.GetValueThis().GetString(), CTYPE_Digit));
}

// string#isempty()
Gura_DeclareMethod(string, isempty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en),
		"Returns `true` if the string is empty.");
}

Gura_ImplementMethod(string, isempty)
{
	return Value(*arg.GetValueThis().GetString() == '\0');
}

// string#isspace()
Gura_DeclareMethod(string, isspace)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en),
		"Returns `true` if all the characters in the string are space.");
}

Gura_ImplementMethod(string, isspace)
{
	return Value(CheckCType(arg.GetValueThis().GetString(), CTYPE_Space));
}

// string#left(len?:number):map
Gura_DeclareMethod(string, left)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "len", VTYPE_number, OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Extracts the specified length of string from left of the source string.\n"
		"\n"
		"If the argument is omitted, it would return whole the source string.\n");
}

Gura_ImplementMethod(string, left)
{
	if (!arg.Is_number(0)) return arg.GetValueThis();
	return Value(Left(arg.GetValueThis().GetString(), arg.GetSizeT(0)));
}

// string#len()
Gura_DeclareMethod(string, len)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en),
		"Returns the length of the string in characters.");
}

Gura_ImplementMethod(string, len)
{
	return Value(static_cast<UInt>(Length(arg.GetValueThis().GetString())));
}

// string#lower()
Gura_DeclareMethod(string, lower)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en),
		"Converts upper-case to lower-case characters.\n");
}

Gura_ImplementMethod(string, lower)
{
	return Value(Lower(arg.GetValueThis().GetString()));
}

// string#mid(pos:number => 0, len?:number):map {block?}
Gura_DeclareMethod(string, mid)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once, FLAG_None, 0, new Expr_Value(0));
	DeclareArg(env, "len", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), 
		"Extracts the specified length of string from the position `pos` and returns the result.\n"
		"\n"
		"If an argument `len` is omitted, it returns a string from `pos` to the end.\n"
		"The number of an argument `pos` starts from zero.\n"
		"\n"
		"Below are examples:\n"
		"\n"
		"    'Hello world'.mid(3, 2) // 'lo'\n"
		"    'Hello world'.mid(5)    // 'world'\n");
}

Gura_ImplementMethod(string, mid)
{
	return ReturnValue(env, arg, Value(Middle(arg.GetValueThis().GetString(), arg.GetInt(0),
											  arg.Is_number(1)? arg.GetInt(1) : -1)));
}

// string#print(stream?:stream:w):void
Gura_DeclareMethodPrimitive(string, print)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_ZeroOrOnce, FLAG_Write);
	AddHelp(
		Gura_Symbol(en),
		"Prints out the string to the specified `stream`.\n"
		"\n"
		"If the argument is omitted, it would print to the standard output.\n");
}

Gura_ImplementMethod(string, print)
{
	Signal &sig = env.GetSignal();
	Stream *pStream = arg.IsInstanceOf(0, VTYPE_stream)?
								&arg.GetStream(0) : env.GetConsole();
	pStream->Print(sig, arg.GetValueThis().GetString());
	return Value::Nil;
}

// string#println(stream?:stream:w):void
Gura_DeclareMethodPrimitive(string, println)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_ZeroOrOnce, FLAG_Write);
	AddHelp(
		Gura_Symbol(en),
		"Prints out the string and a line-break to the specified `stream`.\n"
		"\n"
		"If the argument is omitted, it would print to the standard output.\n");
}

Gura_ImplementMethod(string, println)
{
	Signal &sig = env.GetSignal();
	Stream *pStream = arg.IsInstanceOf(0, VTYPE_stream)?
								&arg.GetStream(0) : env.GetConsole();
	pStream->Println(sig, arg.GetValueThis().GetString());
	return Value::Nil;
}

// string#reader() {block?}
Gura_DeclareMethod(string, reader)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Returns a `stream` instance that reads the string content as a binary sequence.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("s", "stream"));
}

Gura_ImplementMethod(string, reader)
{
	return ReturnValue(env, arg, Value(new Object_stream(env,
		new Stream_StringReader(env, arg.GetValueThis().GetStringSTL()))));
}

// string#replace(match:string, sub:string, count?:number):map:[icase] {block?}
Gura_DeclareMethod(string, replace)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "match",	VTYPE_string);
	DeclareArg(env, "sub",		VTYPE_string);
	DeclareArg(env, "count",	VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareAttr(Gura_Symbol(icase));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), 
		"Replaces sub strings that matches the string `match` with a string specified by `sub`\n"
		"and returns the result.\n"
		"\n"
		"The argument `count` limits the maximum number of substitution.\n"
		"If omitted, there's no limit of the work.\n"
		"\n"
		"With an attribute `:icase`, character cases are ignored while matching strings.\n"
		"\n"
		"If `block` is specified, it would be evaluated with a block parameter `|result:string, replaced:boolean|`,\n"
		"where `result` is the result string and `replaced` indicates if there is any change\n"
		"between the result and its original string.\n"
		"In this case, the block's result would become the function's returned value.\n");
}

Gura_ImplementMethod(string, replace)
{
	String result = Replace(
		arg.GetValueThis().GetString(),
		arg.GetString(0), arg.GetString(1),
		arg.IsValid(2)? arg.GetInt(2) : -1, arg.IsSet(Gura_Symbol(icase)));
	if (!arg.IsBlockSpecified()) return Value(result);
	ValueList valListArg;
	valListArg.reserve(2);
	valListArg.push_back(Value(result));
	valListArg.push_back(Value(result != arg.GetValueThis().GetStringSTL()));
	return ReturnValues(env, arg, valListArg);
}

// string#replaces(map[]:string, count?:number):map:[icase] {block?}
Gura_DeclareMethod(string, replaces)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "map",		VTYPE_string, OCCUR_Once, FLAG_ListVar);
	DeclareArg(env, "count",	VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareAttr(Gura_Symbol(icase));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), 
		"Replaces string parts according to a list of pairs of a matching and a substituting string\n"
		"and returns the result.\n"
		"\n"
		"The argument `map` is a `list` of match-substitution paris like `[match1, sub1, match2, sub2, ..]`\n"
		"with which a sub string that matches `match`*n* would be replaced with `sub`*n*.\n"
		"\n"
		"The argument `count` limits the maximum number of substitution.\n"
		"If omitted, there's no limit of the work.\n"
		"\n"
		"With an attribute `:icase`, character cases are ignored while matching strings.\n"
		"\n"
		"If `block` is specified, it would be evaluated with a block parameter `|result:string, replaced:boolean|`,\n"
		"where `result` is the result string and `replaced` indicates if there is any change\n"
		"between the result and its original string.\n"
		"In this case, the block's result would become the function's returned value.\n");
}

Gura_ImplementMethod(string, replaces)
{
	Signal &sig = env.GetSignal();
	const ValueList &valList = arg.GetList(0);
	if (valList.size() & 1) {
		sig.SetError(ERR_ValueError, "the list must contain match-sub pairs");
		return Value::Nil;
	}
	int nMaxReplace = arg.IsValid(1)? arg.GetInt(1) : -1;
	String result = Replaces(arg.GetValueThis().GetString(),
							 valList, nMaxReplace, arg.IsSet(Gura_Symbol(icase)));
	if (!arg.IsBlockSpecified()) return Value(result);
	ValueList valListArg;
	valListArg.reserve(2);
	valListArg.push_back(Value(result));
	valListArg.push_back(Value(result != arg.GetValueThis().GetStringSTL()));
	return ReturnValues(env, arg, valListArg);
}

// string#right(len?:number):map {block?}
Gura_DeclareMethod(string, right)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "len", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Extracts the specified length of string from right of the source string.\n"
		"\n"
		"If the argument is omitted, it would return whole the source string.\n");
}

Gura_ImplementMethod(string, right)
{
	if (!arg.Is_number(0)) return arg.GetValueThis();
	return ReturnValue(env, arg, Value(Right(arg.GetValueThis().GetString(), arg.GetSizeT(0))));
}

// string#split(sep?:string, count?:number):[icase] {block?}
Gura_DeclareMethod(string, split)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "sep", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "count", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareAttr(Gura_Symbol(icase));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), 
		"Creates an iterator generating sub strings extracted from the original one\n"
		"separated by a specified string `sep`.\n"
		"With an attribute `:icase`, character cases are ignored while finding the separator.\n"
		"\n"
		GURA_HELPTEXT_ITERATOR_en());
}

Gura_ImplementMethod(string, split)
{
	int maxSplit = arg.Is_number(1)? arg.GetInt(1) : -1;
	Iterator *pIterator = nullptr;
	if (arg.Is_string(0) && *arg.GetString(0) != '\0') {
		const char *sep = arg.GetString(0);
		bool ignoreCaseFlag = arg.IsSet(Gura_Symbol(icase));
		pIterator = new Class_string::IteratorSplit(
						arg.GetValueThis().GetStringSTL(), sep, maxSplit, ignoreCaseFlag);
	} else {
		pIterator = new Class_string::IteratorEach(arg.GetValueThis().GetStringSTL(),
							maxSplit, Class_string::IteratorEach::ATTR_None);
	}
	return ReturnIterator(env, arg, pIterator);
}

// string#startswith(prefix:string, pos:number => 0):map:[rest,icase]
Gura_DeclareMethod(string, startswith)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "prefix",	VTYPE_string);
	DeclareArg(env, "pos",		VTYPE_number, OCCUR_Once, FLAG_None, 0, new Expr_Value(0));
	DeclareAttr(Gura_Symbol(rest));
	DeclareAttr(Gura_Symbol(icase));
	AddHelp(
		Gura_Symbol(en), 
		"Returns `true` if the string starts with `prefix`.\n"
		"\n"
		"If attribute `:rest` is specified,\n"
		"it returns the rest part if the string starts with prefix, or `nil` otherewise.\n"
		"You can specify a top position for the matching by an argument `pos`.\n"
		"\n"
		"With an attribute `:icase`, character cases are ignored while matching.");
}

Gura_ImplementMethod(string, startswith)
{
	const char *rtn = StartsWith(arg.GetValueThis().GetString(), arg.GetString(0),
					arg.GetInt(1), arg.IsSet(Gura_Symbol(icase)));
	if (arg.IsSet(Gura_Symbol(rest))) {
		if (rtn == nullptr) return Value::Nil;
		return Value(rtn);
	}
	return rtn != nullptr;
}

// string#strip():[both,left,right] {block?}
Gura_DeclareMethod(string, strip)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareAttr(Gura_Symbol(both));
	DeclareAttr(Gura_Symbol(left));
	DeclareAttr(Gura_Symbol(right));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), 
		"Returns a string that removes space characters on the left, the right or the both sides\n"
		"of the original string.\n"
		"\n"
		"The following attributes would specify which side of spaces should be removed:\n"
		"\n"
		"- `:both` .. Removes spaces on both sides. This is the default.\n"
		"- `:left` .. Removes spaces on the left side.\n"
		"- `:right` .. Removes spaces on the right side.\n");
}

Gura_ImplementMethod(string, strip)
{
	bool stripLeftFlag = true, stripRightFlag = true;
	if (arg.IsSet(Gura_Symbol(both))) {
		// nothing to do
	} else if (arg.IsSet(Gura_Symbol(left)) && !arg.IsSet(Gura_Symbol(right))) {
		stripRightFlag = false;
	} else if (!arg.IsSet(Gura_Symbol(left)) && arg.IsSet(Gura_Symbol(right))) {
		stripLeftFlag = false;
	}
	return ReturnValue(env, arg,
					   Value(Strip(arg.GetValueThis().GetString(), stripLeftFlag, stripRightFlag)));
}

// string#template():[noindent,lasteol] {block?}
Gura_DeclareMethodAlias(string, template_, "template")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareAttr(Gura_Symbol(noindent));
	DeclareAttr(Gura_Symbol(lasteol));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), 
		"Parses the content of the string as a text containing embedded scripts\n"
		"and returns a `template` instance.\n");
}

Gura_ImplementMethod(string, template_)
{
	bool autoIndentFlag = !arg.IsSet(Gura_Symbol(noindent));
	bool appendLastEOLFlag = arg.IsSet(Gura_Symbol(lasteol));
	AutoPtr<Template> pTemplate(new Template());
	if (!pTemplate->Parse(env, arg.GetValueThis().GetString(), nullptr,
						  autoIndentFlag, appendLastEOLFlag)) return Value::Nil;
	return ReturnValue(env, arg,
					Value(new Object_template(env, pTemplate.release())));
}

// string#tosymbol() {block?}
Gura_DeclareMethod(string, tosymbol)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Convers the string into a symbol.\n");
}

Gura_ImplementMethod(string, tosymbol)
{
	return ReturnValue(env, arg, Value(Symbol::Add(arg.GetValueThis().GetString())));
}

// string.translator():void {block}
Gura_DeclareClassMethod(string, translator)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareBlock(OCCUR_Once);
	AddHelp(
		Gura_Symbol(en),
		"Register a procedure evaluated when a string literal\n"
		"appears with a suffix symbol \"`$`\",\n"
		"which is meant to translate the string into another language.\n"
		"\n"
		"The procedure is described in `block` takes a block parameter `|str:string|`\n"
		"where `str` is the original string, and is expected to return a string\n"
		"translated from the original.\n");
}

Gura_ImplementClassMethod(string, translator)
{
	SuffixMgr &suffixMgr = env.GetGlobal()->GetSuffixMgrForString();
	const Function *pFuncBlock = arg.GetBlockFunc(env, GetSymbolForBlock());
	if (pFuncBlock == nullptr) return Value::Nil;
	const Symbol *pSymbol = Symbol::Dollar;
	SuffixMgrEntryCustom *pSuffixMgrEntry =
					new SuffixMgrEntryCustom(Function::Reference(pFuncBlock));
	suffixMgr.Assign(pSymbol, pSuffixMgrEntry);
	return Value::Nil;
}

// string#unescapehtml() {block?}
Gura_DeclareMethod(string, unescapehtml)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), 
		"Converts escape sequences into readable characters.");
}

Gura_ImplementMethod(string, unescapehtml)
{
	return ReturnValue(env, arg, Value(UnescapeHtml(arg.GetValueThis().GetString())));
}

// string#upper() {block?}
Gura_DeclareMethod(string, upper)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Converts lower-case to upper-case characters.\n");
}

Gura_ImplementMethod(string, upper)
{
	return ReturnValue(env, arg, Value(Upper(arg.GetValueThis().GetString())));
}

// string#width()
Gura_DeclareMethod(string, width)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en),
		"Returns the width of the string.\n"
		"\n"
		"This method takes into account the character width based on the specification\n"
		"of East Asian Width.\n"
		"For example, a kanji-character of Japanese occupies two characters in width.\n");
}

Gura_ImplementMethod(string, width)
{
	return Value(static_cast<UInt>(Width(arg.GetValueThis().GetString())));
}

// string#zentohan() {block?}
Gura_DeclareMethod(string, zentohan)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Converts zenkaku to hankaku characters.");
}

Gura_ImplementMethod(string, zentohan)
{
	return ReturnValue(env, arg, Value(ZenToHan(arg.GetValueThis().GetString())));
}

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_string::Class_string(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_string)
{
}

void Class_string::DoPrepare(Environment &env)
{
	// class assignment
	Gura_AssignValue(string, Value(Reference()));
	// method assignment
	Gura_AssignMethod(string, align);
	Gura_AssignMethod(string, binary);
	Gura_AssignMethod(string, capitalize);
	Gura_AssignMethod(string, chop);
	Gura_AssignMethod(string, decodeuri);
	Gura_AssignMethod(string, each);
	Gura_AssignMethod(string, eachline);
	Gura_AssignMethod(string, embed);
	Gura_AssignMethod(string, encode);
	Gura_AssignMethod(string, encodeuri);
	Gura_AssignMethod(string, endswith);
	Gura_AssignMethod(string, escape);
	Gura_AssignMethod(string, escapehtml);
	Gura_AssignMethod(string, find);
	Gura_AssignMethod(string, fold);
	Gura_AssignMethod(string, foldw);
	Gura_AssignMethod(string, format);
	Gura_AssignMethod(string, isalnum);
	Gura_AssignMethod(string, isalpha);
	Gura_AssignMethod(string, isdigit);
	Gura_AssignMethod(string, isempty);
	Gura_AssignMethod(string, isspace);
	Gura_AssignMethod(string, left);
	Gura_AssignMethod(string, len);
	Gura_AssignMethod(string, lower);
	Gura_AssignMethod(string, mid);
	Gura_AssignMethod(string, print);
	Gura_AssignMethod(string, println);
	Gura_AssignMethod(string, reader);
	Gura_AssignMethod(string, replace);
	Gura_AssignMethod(string, replaces);
	Gura_AssignMethod(string, right);
	Gura_AssignMethod(string, split);
	Gura_AssignMethod(string, startswith);
	Gura_AssignMethod(string, strip);
	Gura_AssignMethod(string, template_);
	Gura_AssignMethod(string, tosymbol);
	Gura_AssignMethod(string, translator);
	Gura_AssignMethod(string, unescapehtml);
	Gura_AssignMethod(string, upper);
	Gura_AssignMethod(string, width);
	Gura_AssignMethod(string, zentohan);
	// suffix manager assignment
	Gura_AssignSuffixMgrForString($);
	// help document
	AddHelpTemplate(env, Gura_Symbol(en), helpDoc_en);
}

Value Class_string::IndexGetPrimitive(Environment &env,
						const Value &valueThis, const Value &valueIdx) const
{
	Signal &sig = GetSignal();
	if (!valueIdx.Is_number()) {
		sig.SetError(ERR_IndexError, "index must be a number for string");
		return Value::Nil;
	}
	int idx = valueIdx.GetInt();
	int len = static_cast<int>(Length(valueThis.GetString()));
	if (idx >= 0) {
		if (idx >= len) {
			sig.SetError(ERR_IndexError, "index is out of range");
			return Value::Nil;
		}
		return Value(PickChar(valueThis.GetStringSTL(), idx));
	} else {
		if (-idx > len) {
			sig.SetError(ERR_IndexError, "index is out of range");
			return Value::Nil;
		}
		return Value(PickChar(valueThis.GetStringSTL(), len + idx));
	}
}

bool Class_string::CastFrom(Environment &env, Value &value, ULong flags)
{
	Signal &sig = GetSignal();
	value = Value(value.ToString(false));
	return !sig.IsSignalled();
}

bool Class_string::Serialize(Environment &env, Stream &stream, const Value &value) const
{
	Signal &sig = GetSignal();
	return stream.SerializeString(sig, value.GetString());
}

bool Class_string::Deserialize(Environment &env, Stream &stream, Value &value) const
{
	Signal &sig = GetSignal();
	String str;
	if (!stream.DeserializeString(sig, str)) return false;
	value = Value(str);
	return true;
}

Object *Class_string::CreateDescendant(Environment &env, Class *pClass)
{
	return nullptr;
}

//-----------------------------------------------------------------------------
// Class_string::IteratorEach
//-----------------------------------------------------------------------------
Class_string::IteratorEach::IteratorEach(const String &str, int cntMax, Attr attr) :
	Iterator(Finite), _str(str), _cnt(cntMax), _attr(attr)
{
	_pCur = _str.begin();
}

Class_string::IteratorEach::~IteratorEach()
{
}

Iterator *Class_string::IteratorEach::GetSource()
{
	return nullptr;
}

bool Class_string::IteratorEach::DoNext(Environment &env, Value &value)
{
	if (_pCur == _str.end()) return false;
	if (_attr == ATTR_UTF8) {
		UInt64 codeUTF8;
		_pCur = NextUTF8(_str, _pCur, codeUTF8);
		value = Value(codeUTF8);
	} else if (_attr == ATTR_UTF32) {
		UInt32 codeUTF32;
		_pCur = NextUTF32(_str, _pCur, codeUTF32);
		value = Value(codeUTF32);
	} else {
		String::const_iterator pLeft = _pCur;
		if (_cnt == 0) {
			_pCur = _str.end();
		} else {
			_pCur = NextChar(_str, _pCur);
			if (_cnt > 0) _cnt--;
		}
		value = Value(String(pLeft, _pCur));
	}
	return true;
}

String Class_string::IteratorEach::ToString() const
{
	return String("string#each");
}

void Class_string::IteratorEach::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

//-----------------------------------------------------------------------------
// Class_string::IteratorLine
//-----------------------------------------------------------------------------
Class_string::IteratorLine::IteratorLine(const String &str,
											int cntMax, bool includeEOLFlag) :
			Iterator(Finite), _str(str), _cnt(cntMax),
			_includeEOLFlag(includeEOLFlag)
{
	_pCur = _str.begin();
}

Class_string::IteratorLine::~IteratorLine()
{
}

Iterator *Class_string::IteratorLine::GetSource()
{
	return nullptr;
}

bool Class_string::IteratorLine::DoNext(Environment &env, Value &value)
{
	if (_pCur == _str.end() || _cnt == 0) return false;
	String::const_iterator pLeft = _pCur;
	String::const_iterator pNext = _str.end();
	for ( ; _pCur != _str.end(); _pCur++) {
		if (*_pCur == '\r') {
			pNext = _pCur + 1;
			if (pNext != _str.end() && *pNext == '\n') pNext++;
			break;
		} else if (*_pCur == '\n') {
			pNext = _pCur + 1;
			break;
		}
	}
	value = Value(String(pLeft, _includeEOLFlag? pNext : _pCur));
	_pCur = pNext;
	if (_cnt > 0) _cnt--;
	return true;
}

String Class_string::IteratorLine::ToString() const
{
	return String("string#eachline");
}

void Class_string::IteratorLine::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

//-----------------------------------------------------------------------------
// Class_string::IteratorSplit
//-----------------------------------------------------------------------------
Class_string::IteratorSplit::IteratorSplit(const String &str, const char *sep,
											int cntMax, bool ignoreCaseFlag) :
	Iterator(Finite), _str(str), _sep(sep), _cnt(cntMax),
	_ignoreCaseFlag(ignoreCaseFlag), _doneFlag(false)
{
	_pCur = _str.begin();
}

Class_string::IteratorSplit::~IteratorSplit()
{
}

Iterator *Class_string::IteratorSplit::GetSource()
{
	return nullptr;
}

bool Class_string::IteratorSplit::DoNext(Environment &env, Value &value)
{
	if (_doneFlag) {
		return false;
	} else if (_pCur == _str.end()) {
		value = Value("");
		_doneFlag = true;
	} else if (_cnt == 0) {
		String::const_iterator pEnd = _str.end();
		value = Value(String(_pCur, pEnd));
		_pCur = _str.end();
		_doneFlag = true;
	} else {
		String::const_iterator pRight =
							FindString(_pCur, _str.end(), _sep, _ignoreCaseFlag);
		value = Value(String(_pCur, pRight));
		if (pRight == _str.end()) {
			_pCur = _str.end();
			_doneFlag = true;
		} else {
			_pCur = pRight + _sep.size();
		}
		if (_cnt > 0) _cnt--;
	}
	return true;
}

String Class_string::IteratorSplit::ToString() const
{
	return String("string#split");
}

void Class_string::IteratorSplit::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

//-----------------------------------------------------------------------------
// Class_string::IteratorFold
//-----------------------------------------------------------------------------
Class_string::IteratorFold::IteratorFold(const String &str,
							size_t lenPerFold, size_t lenStep, bool neatFlag) :
	Iterator(Finite), _str(str), _lenPerFold(lenPerFold), _lenStep(lenStep), _neatFlag(neatFlag)
{
	_pCur = _str.begin();
}

Class_string::IteratorFold::~IteratorFold()
{
}

Iterator *Class_string::IteratorFold::GetSource()
{
	return nullptr;
}

bool Class_string::IteratorFold::DoNext(Environment &env, Value &value)
{
	if (_pCur == _str.end()) return false;
	size_t lenForward = 0;
	String::const_iterator pNext, pTail;
	if (_lenStep <= _lenPerFold) {
		size_t lenForwardSub = 0;
		pNext = Forward(_pCur, _str.end(), _lenStep, &lenForward);
		pTail = Forward(pNext, _str.end(), _lenPerFold - _lenStep, &lenForwardSub);
		lenForward += lenForwardSub;
	} else {
		pTail = Forward(_pCur, _str.end(), _lenPerFold, &lenForward);
		pNext = Forward(pTail, _str.end(), _lenStep - _lenPerFold);
	}
	if (_neatFlag && lenForward < _lenPerFold) return false;
	value = Value(String(_pCur, pTail));
	_pCur = pNext;
	return true;
}

String Class_string::IteratorFold::ToString() const
{
	return String("string#fold");
}

void Class_string::IteratorFold::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

//-----------------------------------------------------------------------------
// Class_string::IteratorFoldw
//-----------------------------------------------------------------------------
Class_string::IteratorFoldw::IteratorFoldw(const String &str,
							size_t widthPerFold, bool paddingFlag) :
	Iterator(Finite), _str(str), _widthPerFold(widthPerFold), _paddingFlag(paddingFlag)
{
	_pCur = _str.begin();
}

Class_string::IteratorFoldw::~IteratorFoldw()
{
}

Iterator *Class_string::IteratorFoldw::GetSource()
{
	return nullptr;
}

bool Class_string::IteratorFoldw::DoNext(Environment &env, Value &value)
{
	UInt32 codeUTF32 = 0;
	size_t width = 0; 
	if (_pCur == _str.end()) return false;
	String::const_iterator pHead = _pCur;
	while (_pCur != _str.end()) {
		String::const_iterator pNext = NextUTF32(_str, _pCur, codeUTF32);
		Codec::WidthProp widthProp = Codec::GetWidthProp(codeUTF32);
		width += (widthProp == Codec::WIDTHPROP_A ||
				  widthProp == Codec::WIDTHPROP_W ||
				  widthProp == Codec::WIDTHPROP_F)? 2 : 1;
		if (width > _widthPerFold) {
			String str(pHead, _pCur);
			if (_paddingFlag) str += ' ';
			value = Value(str);
			if (pHead == _pCur) _pCur = pNext;
			return true;
		}
		_pCur = pNext;
		if (width == _widthPerFold) break;
	}
	value = Value(String(pHead, _pCur));
	return true;
}

String Class_string::IteratorFoldw::ToString() const
{
	return String("string#foldw");
}

void Class_string::IteratorFoldw::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

}
