//-----------------------------------------------------------------------------
// Gura module: basement
//-----------------------------------------------------------------------------
#include "stdafx.h"
#include <gura.h>

Gura_BeginModuleBody(basement)

#define REPEATER_HELP \
"It returns the last evaluated value in the block as its own result,\n" \
"but, if one of `:list`, `:xlist`, `:set`, `:xset` or `:iter` is specified,\n" \
"it returns a list or evaluated value or an iterator. The rule is as follows:\n" \
"\n" \
"- `:list` .. returns a list of result values\n" \
"- `:xlist` .. returns a list of result values eliminating `nil`\n" \
"- `:set` .. returns a list of unique values of results\n" \
"- `:xset` .. returns a list of unique values of results eliminating `nil`\n" \
"- `:iter` .. returns an iterator that executes the block\n" \
"- `:xiter` .. returns an iterator that executes the block, skipping `nil`\n"

//-----------------------------------------------------------------------------
// Formatting and Printing of Text
//-----------------------------------------------------------------------------
// format(format, value*):map
Gura_DeclareFunction(format)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "format", VTYPE_string);
	DeclareArg(env, "values", VTYPE_any, OCCUR_ZeroOrMore);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Converts `values` into string depending on formatter specifications\n"
		"in `format` and returns the result in string.\n"
		"For a detail information about formatter specications,\n"
		"refer to the document of `printf()` function.");
}

Gura_ImplementFunction(format)
{
	return Value(Formatter::Format(sig, args.GetString(0), args.GetList(1)));
}

// print(value*):map:void
Gura_DeclareFunction(print)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "values", VTYPE_any, OCCUR_ZeroOrMore);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Prints out `values` to standard output."
	);
}

Gura_ImplementFunction(print)
{
	Stream *pConsole = env.GetConsole();
	if (pConsole == NULL) return Value::Null;
	foreach_const (ValueList, pValue, args.GetList(0)) {
		pConsole->Print(sig, pValue->ToString(false).c_str());
		if (sig.IsSignalled()) break;
	}
	return Value::Null;
}

// printf(format, values*):map:void
Gura_DeclareFunction(printf)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "format", VTYPE_string);
	DeclareArg(env, "values", VTYPE_any, OCCUR_ZeroOrMore);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Prints out `values` to standard output depending on formatter specifiers in `format`.\n"
		"The format specifier has a format of `%[flags][width][.precision]specifier`.\n"
		"\n"
		"The `specifier` takes one of the following characters:\n"
		"\n"
		"- `d`, `i` .. decimal integer number with a sign mark\n"
		"- `u` .. decimal integer number wihout a sign mark\n"
		"- `b` .. binary integer number without a sign mark\n"
		"- `o` .. octal integer number without a sign mark\n"
		"- `x` .. hexadecimal integer number in lower character without a sign mark\n"
		"- `X` .. hexadecimal integer number in upper character without a sign mark\n"
		"- `e` .. floating number in exponential form\n"
		"- `E` .. floating number in exponential form (in upper character)\n"
		"- `f` .. floating number in decimal form\n"
		"- `F` .. floating number in decimal form (in upper character)\n"
		"- `g` .. better form between `e` and `f`\n"
		"- `G` .. better form between `E` and `F`\n"
		"- `s` .. string\n"
		"- `c` .. character\n"
		"\n"
		"The `flags` takes one of the following characters.\n"
		"\n"
		"- `+` .. Appends a character \"`+`\" before a positive number.\n"
		"- `-` .. Adjust a string to left.\n"
		"- `[SPC]` .. Appends a space character before a positive number.\n"
		"- `#` .. Appends a prefix before a numbers \"`0b`\" for a binary,\n"
		"         \"`0`\" for an octal and \"`0x`\" for a hexadecimal number.\n"
		"- `0` .. Fills lacking columns with \"`0`\" instead of space characters.`\n"
		"\n"
		"The `width` is a decimal number that specifies a minimum character.\n"
		"If the width of the corresponding field is less than this number,\n"
		"the lacking part will be filled with space characters or \"`0`\".\n"
		"If the width is equal to or more than this number, there's nothing to be processed.\n"
		"If an asterisk character \"`*`\" is specified for `width`,\n"
		"the minimum character width will be retrieved from the argument list.\n"
		"\n"
		"The `width` it a character width that appears on a console,\n"
		"and it takes into account each character width based on the specification\n"
		"of East Asian Width. This means that a kanji-character occupies two characters in width.\n"
		"\n"
		"The `precision` is a decimal number and has different effects depending on `specifier`.\n"
		"\n"
		"For specifiers that formats integer numbers, it specifies a minimum character width\n"
		"and fills `0` for the lacking column.\n"
		"Format specifiers \"`%03d`\" and \"`%.3d`\" have the same effect.\n"
		"When it works in combination with `width`,\n"
		"`precision` fills `0` in the lacking space before `width` does padding.\n"
		"An example is shown below:\n"
		"\n"
		"    printf('%5.3d', 23) .. prints \"  023\"\n"
		"\n"
		"For specifiers `e`, `f` and `g`, it specifies a digit number after a decimal point.\n"
		"Examples are shown below:\n"
		"\n"
		"    printf('%.3f', 1 / 3) .. prints \"0.333\"\n"
		"    printf('%.5f', 1 / 3) .. prints \"0.33333\"\n"
		"\n"
		"For other specifiers, it has no effect.\n");
}

Gura_ImplementFunction(printf)
{
	Stream *pConsole = env.GetConsole();
	if (pConsole == NULL) return Value::Null;
	pConsole->PrintFmt(sig, args.GetString(0), args.GetList(1));
	return Value::Null;
}

// println(value*):map:void
Gura_DeclareFunction(println)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "values", VTYPE_any, OCCUR_ZeroOrMore);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Prints out `values` and a line-break to the standard output.\n");
}

Gura_ImplementFunction(println)
{
	Stream *pConsole = env.GetConsole();
	if (pConsole == NULL) return Value::Null;
	foreach_const (ValueList, pValue, args.GetList(0)) {
		pConsole->Print(sig, pValue->ToString(false).c_str());
		if (sig.IsSignalled()) break;
	}
	pConsole->Print(sig, "\n");
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Repetition
//-----------------------------------------------------------------------------
// cross (`expr+) {block}
Gura_DeclareFunction(cross)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "expr", VTYPE_quote, OCCUR_OnceOrMore);
	DeclareBlock(OCCUR_Once);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Executes the block until it evaluates all the combinations of results from exprs\n"
		"\"`var in iteratable`.\" You can specify one or more such exprs as arguments and\n"
		"they are counted up from the one on the right side.\n"
		"Iterators and lists are the most popular iteratables, but even any objects that\n"
		"are cable of generating iterators can be specified as such.\n"
		"\n"
		REPEATER_HELP
		"\n"
		"Block parameter format is `|idx:number, i0:number, i1:number, ..|`\n"
		"where `idx` indicates an index of the whole loop\n"
		"and each of `i0`, `i1` .. indicates an index of each corresponding iterable.\n");
}

Gura_ImplementFunction(cross)
{
	AutoPtr<Environment> pEnvBlock(new Environment(&env, ENVTYPE_block));
	const Function *pFuncBlock =
						args.GetBlockFunc(*pEnvBlock, sig, GetSymbolForBlock());
	if (pFuncBlock == NULL) return Value::Null;
	bool skipInvalidFlag = args.IsRsltXList() || args.IsRsltXSet() || args.IsRsltXIterator();
	bool genIterFlag = args.IsRsltIterator() || args.IsRsltXIterator();
	Iterator *pIterator = new Iterator_cross(pEnvBlock->Reference(), sig, Function::Reference(pFuncBlock),
				skipInvalidFlag, genIterFlag, args.GetList(0));
	return ReturnIterator(env, sig, args, pIterator);
}

// for (`expr+) {block}
Gura_DeclareFunctionAlias(for_, "for")
{
	DeclareArg(env, "expr", VTYPE_quote, OCCUR_OnceOrMore);
	DeclareBlock(OCCUR_Once);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Executes the block until any of the exprs of \"`var in iteratable`\" reach at\n"
		"their ends. You can specify one or more such exprs as arguments.\n"
		"Iterators and lists are the most popular iteratables, but even any objects that\n"
		"are cable of generating iterators can be specified as such.\n"
		"\n"
		REPEATER_HELP
		"\n"
		"Block parameter format is `|idx:number|` where `idx` indicates an index of the loop.\n");
}

Gura_ImplementFunction(for_)
{
	AutoPtr<Environment> pEnvBlock(new Environment(&env, ENVTYPE_block));
	const Function *pFuncBlock =
						args.GetBlockFunc(*pEnvBlock, sig, GetSymbolForBlock());
	if (pFuncBlock == NULL) return Value::Null;
	bool skipInvalidFlag = args.IsRsltXList() || args.IsRsltXSet() || args.IsRsltXIterator();
	bool genIterFlag = args.IsRsltIterator() || args.IsRsltXIterator();
	Iterator *pIterator = new Iterator_for(pEnvBlock->Reference(), sig, Function::Reference(pFuncBlock),
				skipInvalidFlag, genIterFlag, args.GetList(0));
	return ReturnIterator(env, sig, args, pIterator);
}

// repeat (n?:number) {block}
Gura_DeclareFunction(repeat)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "n", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_Once);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Executes the block for `n` times. If `n` is omitted, it repeats the block\n"
		"execution forever.\n"
		"\n"
		REPEATER_HELP
		"\n"
		"Block parameter format is `|idx:number|` where `idx` indicates an index of the loop.\n");
}

Gura_ImplementFunction(repeat)
{
	AutoPtr<Environment> pEnvBlock(new Environment(&env, ENVTYPE_block));
	const Function *pFuncBlock =
						args.GetBlockFunc(*pEnvBlock, sig, GetSymbolForBlock());
	if (pFuncBlock == NULL) return Value::Null;
	bool skipInvalidFlag = args.IsRsltXList() || args.IsRsltXSet() || args.IsRsltXIterator();
	bool genIterFlag = args.IsRsltIterator() || args.IsRsltXIterator();
	Iterator *pIterator = new Iterator_repeat(pEnvBlock->Reference(), sig, Function::Reference(pFuncBlock),
			skipInvalidFlag, genIterFlag, args.Is_number(0)? args.GetInt(0) : -1);
	return ReturnIterator(env, sig, args, pIterator);
}

// while (`cond) {block}
Gura_DeclareFunctionAlias(while_, "while")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "cond", VTYPE_quote);
	DeclareBlock(OCCUR_Once);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Executes the block while the evaluation result of `cond` is true.\n"
		"\n"
		REPEATER_HELP
		"\n"
		"Block parameter format is `|idx:number|` where `idx` indicates an index of the loop.\n");
}

Gura_ImplementFunction(while_)
{
	AutoPtr<Environment> pEnvBlock(new Environment(&env, ENVTYPE_block));
	const Function *pFuncBlock =
						args.GetBlockFunc(*pEnvBlock, sig, GetSymbolForBlock());
	if (pFuncBlock == NULL) return Value::Null;
	bool skipInvalidFlag = args.IsRsltXList() || args.IsRsltXSet() || args.IsRsltXIterator();
	bool genIterFlag = args.IsRsltIterator() || args.IsRsltXIterator();
	Iterator *pIterator = new Iterator_while(pEnvBlock->Reference(), sig, Function::Reference(pFuncBlock),
			skipInvalidFlag, genIterFlag, Expr::Reference(args.GetExpr(0)));
	return ReturnIterator(env, sig, args, pIterator);
}

//-----------------------------------------------------------------------------
// Value Generator
//-----------------------------------------------------------------------------
// consts(value, num?:number) {block?}
Gura_DeclareFunction(consts)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "value", VTYPE_any);
	DeclareArg(env, "num", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Creates an iterator that generates the same value specified by the argument `value`.\n"
		"\n"
		"The argument `num` specifies the number of elements to be generated.\n"
		"If omitted, it would generate the value infinitely.\n"
		"\n"
		GURA_ITERATOR_HELP
		"\n"
		"Below is an example:\n"
		"\n"
		"    x = consts('hello', 10)\n"
		"    // x generates 'hello' for 10 times\n");
}

Gura_ImplementFunction(consts)
{
	Iterator *pIterator = NULL;
	if (args.Is_number(1)) {
		pIterator = new Iterator_ConstantN(args.GetValue(0), args.GetInt(1));
	} else {
		pIterator = new Iterator_Constant(args.GetValue(0));
	}
	return ReturnIterator(env, sig, args, pIterator);
}

// dim(n+:number) {block?}
Gura_DeclareFunction(dim)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "n", VTYPE_number, OCCUR_OnceOrMore);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns a list that contains `n` values of `nil`.\n"
		"If you pass multiple numbers for `n`, it would create a nested list.\n"
		"\n"
		"Example:\n"
		"\n"
		"    x = dim(3)     // x is [nil, nil, nil]\n"
		"    x = dim(3, 2)  // x is [[nil, nil], [nil, nil], [nil, nil]]\n"
		"\n"
		"The optional `block` provides values for each element\n"
		"and takes a block parameters: `|i0:number, i1:number, ..|`.\n"
		"\n"
		"Example:\n"
		"\n"
		"    x = dim(3) {'Hi'}\n"
		"    // x is ['Hi', 'Hi', 'Hi']\n"
		"    x = dim(3, 2) {|i, j| format('%d-%d', i, j) }\n"
		"    // x is [['0-0', '0-1'], ['1-0', '1-1'], ['2-0', '2-1']]\n");
}

bool Func_dim_Sub(Environment &env, Signal sig, const Function *pFuncBlock, ValueList &valListParent,
	IntList &cntList, IntList::iterator pCnt, IntList &idxList, IntList::iterator pIdx)
{
	if (pCnt + 1 == cntList.end()) {
		if (pFuncBlock == NULL) {
			for (*pIdx = 0; *pIdx < *pCnt; (*pIdx)++) {
				valListParent.push_back(Value::Null);
			}
		} else {
			for (*pIdx = 0; *pIdx < *pCnt; (*pIdx)++) {
				AutoPtr<Args> pArgs(new Args());
				pArgs->ReserveValueListArg(idxList.size());
				foreach (IntList, pIdxWk, idxList) {
					pArgs->AddValue(Value(*pIdxWk));
				}
				Value result = pFuncBlock->Eval(env, sig, *pArgs);
				if (sig.IsSignalled()) return false;
				valListParent.push_back(result);
			}
		}
	} else {
		for (*pIdx = 0; *pIdx < *pCnt; (*pIdx)++) {
			Value result;
			ValueList &valList = result.InitAsList(env);
			valListParent.push_back(result);
			if (!Func_dim_Sub(env, sig, pFuncBlock, valList,
									cntList, pCnt + 1, idxList, pIdx + 1)) {
				return false;
			}
		}
	}
	return true;
}

Gura_ImplementFunction(dim)
{
	AutoPtr<Environment> pEnvBlock(new Environment(&env, ENVTYPE_block));
	const Function *pFuncBlock =
						args.GetBlockFunc(*pEnvBlock, sig, GetSymbolForBlock());
	const ValueList &valListArg = args.GetList(0);
	size_t nArgs = valListArg.size();
	IntList cntList, idxList;
	cntList.reserve(nArgs);
	idxList.reserve(nArgs);
	foreach_const (ValueList, pValArg, valListArg) {
		cntList.push_back(pValArg->GetInt());
		idxList.push_back(0);
	}
	Value result;
	ValueList &valList = result.InitAsList(env);
	if (!Func_dim_Sub(*pEnvBlock, sig, pFuncBlock, valList,
						cntList, cntList.begin(), idxList, idxList.begin())) {
		return Value::Null;
	}
	return result;
}

// interval(begin:number, end:number, samples:number):map:[open,open_l,open_r] {block?}
Gura_DeclareFunction(interval)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "begin", VTYPE_number);
	DeclareArg(env, "end", VTYPE_number);
	DeclareArg(env, "samples", VTYPE_number);
	DeclareAttr(Gura_Symbol(open));
	DeclareAttr(Gura_Symbol(open_l));
	DeclareAttr(Gura_Symbol(open_r));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Creates an iterator that generates a sequence of numbers\n"
		"by specifying the beginning and ending numbers, and the number of samples between them.\n"
		
		"\n"
		"In default, it creates a sequence that contains the beginning and ending numbers.\n"
		"Following attributes would generate the following numbers:\n"
		"\n"
		"- `:open` .. Numbers in range of `(begin, end)` that doesn't contain either `begin` or `end`.\n"
		"- `:open_l` .. Numbers in range of `(begin, end]` that doesn't contain `begin`.\n"
		"- `:open_r` .. Numbers in range of `[begin, end)` that doesn't contain `end`.\n");
}

Gura_ImplementFunction(interval)
{
	Number numBegin = args.GetNumber(0);
	Number numEnd = args.GetNumber(1);
	int numSamples = args.GetInt(2);
	if (numSamples <= 1) {
		sig.SetError(ERR_ValueError, "samples must be more than one");
		return Value::Null;
	}
	bool openFlag = args.IsSet(Gura_Symbol(open));
	bool openLeftFlag = args.IsSet(Gura_Symbol(open_l));
	bool openRightFlag = args.IsSet(Gura_Symbol(open_r));
	int iFactor = 0;
	Number numDenom = numSamples - 1;
	if (openFlag || (openLeftFlag && openRightFlag)) {
		numDenom = numSamples + 1;
		iFactor = 1;
	} else if (openLeftFlag) {
		numDenom = numSamples;
		iFactor = 1;
	} else if (openRightFlag) {
		numDenom = numSamples;
		iFactor = 0;
	}
	Iterator *pIterator =
		new Iterator_Interval(numBegin, numEnd, numSamples, numDenom, iFactor);
	return ReturnIterator(env, sig, args, pIterator);
}

// range(num:number, num_end?:number, step?:number):map {block?}
Gura_DeclareFunction(range)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "num",		VTYPE_number);
	DeclareArg(env, "num_end",	VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "step",		VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Creates an iterator that generates a sequence of integer numbers.\n"
		"\n"
		"This function can be called in three formats that generate following numbers:\n"
		"\n"
		"- `range(num)` .. Numbers between `0` and `(num - 1)`.\n"
		"- `range(num, num_end)` .. Numbers between `num` and `(num_end - 1)`.\n"
		"- `range(num, num_end, step)` .. Numbers between `num` and `(num_end - 1)`\n"
		"  incremented by `step`.\n"
		"\n"
		GURA_ITERATOR_HELP
		"\n"
		"Below are examples:\n"
		"\n"
		"    x = range(10)\n"
		"    // x generates 0, 1, 2, 3, 4, 5, 6, 7, 8, 9\n"
		"    \n"
		"    x = range(3, 10)\n"
		"    // x generates 3, 4, 5, 6, 7, 8, 9\n"
		"    \n"
		"    x = range(3, 10, 2)\n"
		"    // x generates 3, 5, 7, 9\n"
		);
}

Gura_ImplementFunction(range)
{
	AutoPtr<Iterator> pIterator;
	Number numBegin = 0.;
	Number numEnd = 0.;
	Number numStep = 1.;
	if (args.IsInvalid(1)) {
		if (args.IsValid(2)) {
			numBegin = args.GetNumber(0);
			numStep = args.GetNumber(2);
			if (numStep == 0.) {
				sig.SetError(ERR_ValueError, "step cannot be specified as zero");
				return Value::Null;
			}
			pIterator.reset(new Iterator_SequenceInf(numBegin, numStep));
		} else {
			numEnd = args.GetNumber(0);
			if (numBegin > numEnd) numStep = -1.;
			pIterator.reset(new Iterator_Range(numBegin, numEnd, numStep));
		}
	} else if (args.IsInvalid(2)) {
		numBegin = args.GetNumber(0);
		numEnd = args.GetNumber(1);
		if (numBegin > numEnd) numStep = -1.;
		pIterator.reset(new Iterator_Range(numBegin, numEnd, numStep));
	} else {
		numBegin = args.GetNumber(0);
		numEnd = args.GetNumber(1);
		numStep = args.GetNumber(2);
		if (numStep == 0.) {
			sig.SetError(ERR_ValueError, "step cannot be specified as zero");
			return Value::Null;
		}
		if (numBegin < numEnd && numStep < 0) {
			sig.SetError(ERR_ValueError, "step value must be positive");
			return Value::Null;
		}
		if (numBegin > numEnd && numStep > 0) {
			sig.SetError(ERR_ValueError, "step value must be negative");
			return Value::Null;
		}
		pIterator.reset(new Iterator_Range(numBegin, numEnd, numStep));
	}
	return ReturnIterator(env, sig, args, pIterator.release());
}

//-----------------------------------------------------------------------------
// Flow Control
//-----------------------------------------------------------------------------
// break(value?):void:symbol_func
Gura_DeclareFunctionAlias(break_, "break")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_SymbolFunc);
	DeclareArg(env, "value", VTYPE_any, OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Exits from an inside of a loop that is formed with functions `repeat()`, `while()`,\n"
		"`for()` and `cross()`. If it takes an argument, that value is treated as a result of\n"
		"the loop function. Otherwise, the result is nil and an argument list can be omitted.\n"
		"\n"
		"If the loop function is called with one of attributes, `:list`, `:xlist`, `:set`,\n"
		"`:xset`, `:iter` and `:xiter`,\n"
		"the argument value of `break()` is NOT included as an element in the list or iterator.");
}

Gura_ImplementFunction(break_)
{
	sig.SetSignal(SIGTYPE_Break, args.GetValue(0));
	return Value::Null;
}

// continue(value?):void:symbol_func
Gura_DeclareFunctionAlias(continue_, "continue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_SymbolFunc);
	DeclareArg(env, "value", VTYPE_any, OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"In a loop that is formed with functions `repeat()`, `while()`, `for()` and `cross()`,\n"
		"skips the following part of it and gets to the top of its process.\n"
		"If it takes an argument, that value is treated as a result of the loop function.\n"
		"Otherwise, the result is nil and an argument list can be omitted.\n"
		"\n"
		"If the loop function is specified with one of `:list`, `:xlist`, `:set`,\n"
		"`:xset`, `:iter` and `:xiter`,\n"
		"the argument value of `continue()` is included as an element in the list or iterator.");
}

Gura_ImplementFunction(continue_)
{
	sig.SetSignal(SIGTYPE_Continue, args.GetValue(0));
	return Value::Null;
}

// return(value?):void:symbol_func
Gura_DeclareFunctionAlias(return_, "return")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_SymbolFunc);
	DeclareArg(env, "value", VTYPE_any, OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Skips the remaining procedure of the current function and returns to context that calls it.\n"
		"If it takes an argument, the value is treated as a result of the function.\n"
		"Otherwise, the returned value would be `nil`.");
}

Gura_ImplementFunction(return_)
{
	sig.SetSignal(SIGTYPE_Return, args.GetValue(0));
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Branch Sequence
//-----------------------------------------------------------------------------
// if (`cond):leader {block}
Gura_DeclareFunctionAlias(if_, "if")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Leader);
	DeclareArg(env, "cond", VTYPE_quote);
	DeclareBlock(OCCUR_Once);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Specify an \"if\" block within a statement of `if-elsif-else`.\n"
		"\n"
		"If the evaluation result of `cond` is determined as true, the block would be executed,\n"
		"and its evaluation result would become the returned value of the function.\n"
		"\n"
		"Otherwise, if the function is followed by a trailer `elsif` or `else`, that would be evaluated.\n"
		"If no trailer exists, the function returns `nil` value.\n");
}

Gura_ImplementFunction(if_)
{
	SeqPostHandler *pSeqPostHandlerArg = NULL;
	AutoPtr<Environment> pEnvBlock(new Environment(&env, ENVTYPE_block));
	Value value = args.GetExpr(0)->Exec2(*pEnvBlock, sig, pSeqPostHandlerArg);
	if (value.GetBoolean()) {
		SeqPostHandler *pSeqPostHandler = NULL;
		args.QuitTrailer();
		const Expr_Block *pExprBlock = args.GetBlock(*pEnvBlock, sig);
		if (sig.IsSignalled()) return Value::Null;
		return pExprBlock->Exec2(*pEnvBlock, sig, pSeqPostHandler);
	}
	return Value::Null;
}

// elsif (`cond):leader:trailer {block}
Gura_DeclareFunctionTrailerAlias(elsif_, "elsif")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Leader | FLAG_Trailer);
	DeclareArg(env, "cond", VTYPE_quote);
	DeclareBlock(OCCUR_Once);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Specify an \"elsif\" block within a statement of `if-elsif-else`.\n"
		"\n"
		"If the evaluation result of `cond` is determined as true, the block would be executed,\n"
		"and its evaluation result would become the returned value of the function.\n"
		"\n"
		"Otherwise, if the function is followed by a trailer `elsif` or `else`, that would be evaluated.\n"
		"If no trailer exists, the function returns `nil` value.\n");
}

Gura_ImplementFunction(elsif_)
{
	SeqPostHandler *pSeqPostHandlerArg = NULL;
	AutoPtr<Environment> pEnvBlock(new Environment(&env, ENVTYPE_block));
	Value value = args.GetExpr(0)->Exec2(*pEnvBlock, sig, pSeqPostHandlerArg);
	if (value.GetBoolean()) {
		SeqPostHandler *pSeqPostHandler = NULL;
		const Expr_Block *pExprBlock = args.GetBlock(*pEnvBlock, sig);
		if (sig.IsSignalled()) return Value::Null;
		args.QuitTrailer();
		return pExprBlock->Exec2(*pEnvBlock, sig, pSeqPostHandler);
	}
	return Value::Null;
}

// else ():trailer {block}
Gura_DeclareFunctionTrailerAlias(else_, "else")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Trailer);
	DeclareBlock(OCCUR_Once);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Specify an \"else\" block within a statement of `if-elsif-else` or `try-catch-else`.\n");
}

Gura_ImplementFunction(else_)
{
	SeqPostHandler *pSeqPostHandler = NULL;
	// this function works as a terminater of if-else and try-catch
	if (sig.IsErrorSuspended()) return Value::Null;
	AutoPtr<Environment> pEnvBlock(new Environment(&env, ENVTYPE_block));
	const Expr_Block *pExprBlock = args.GetBlock(*pEnvBlock, sig);
	if (sig.IsSignalled()) return Value::Null;
	return pExprBlock->Exec2(*pEnvBlock, sig, pSeqPostHandler);
}

// end (dummy*):void:symbol_func:trailer:end_marker
Gura_DeclareFunction(end)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_SymbolFunc | FLAG_Trailer | FLAG_EndMarker);
	DeclareArg(env, "dummy", VTYPE_any, OCCUR_ZeroOrMore);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Specify an end of a sequence. This is supposed to appear in a template script.\n");
}

Gura_ImplementFunction(end)
{
	return Value::Null;
}

// switch {block}
Gura_DeclareFunctionAlias(switch_, "switch")
{
	DeclareBlock(OCCUR_Once);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Form a switch block that contains `case()` and `default()` function calls.\n"
		"It calls these functions sequentially and exits the execution\n"
		"when one of the conditions is evaluated as true.");
}

Gura_ImplementFunction(switch_)
{
	SeqPostHandler *pSeqPostHandler = NULL;
	AutoPtr<Environment> pEnvBlock(new Environment(&env, ENVTYPE_block));;
	const Expr_Block *pExprBlock = args.GetBlock(*pEnvBlock, sig);
	if (sig.IsSignalled()) return Value::Null;
	pExprBlock->Exec2(*pEnvBlock, sig, pSeqPostHandler);
	if (sig.IsSwitchDone()) {
		Value result = sig.GetValue();
		sig.ClearSignal();
		return result;
	}
	return Value::Null;
}

// case (`cond) {block}
Gura_DeclareFunctionAlias(case_, "case")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "cond", VTYPE_quote);
	DeclareBlock(OCCUR_Once);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Specify an case block within a switch block.\n"
		"After evaluating an expr object cond, the block shall be executed\n"
		"if it has a value of true.");
}

Gura_ImplementFunction(case_)
{
	SeqPostHandler *pSeqPostHandlerArg = NULL;
	AutoPtr<Environment> pEnvBlock(new Environment(&env, ENVTYPE_block));
	Value value = args.GetExpr(0)->Exec2(*pEnvBlock, sig, pSeqPostHandlerArg);
	if (value.GetBoolean()) {
		SeqPostHandler *pSeqPostHandler = NULL;
		const Expr_Block *pExprBlock = args.GetBlock(*pEnvBlock, sig);
		if (sig.IsSignalled()) return Value::Null;
		Value result = pExprBlock->Exec2(*pEnvBlock, sig, pSeqPostHandler);
		if (sig.IsSignalled()) return Value::Null;
		sig.SetSignal(SIGTYPE_SwitchDone, result);
		return result;
	}
	return Value::Null;
}

// default {block}
Gura_DeclareFunctionAlias(default_, "default")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_Once);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Specify a default block within a switch block.\n"
		"If all the preceding condition of case block are not evaluated as true,\n"
		"this block shall be executed.\n");
}

Gura_ImplementFunction(default_)
{
	SeqPostHandler *pSeqPostHandler = NULL;
	AutoPtr<Environment> pEnvBlock(new Environment(&env, ENVTYPE_block));
	const Expr_Block *pExprBlock = args.GetBlock(*pEnvBlock, sig);
	if (sig.IsSignalled()) return Value::Null;
	Value result = pExprBlock->Exec2(*pEnvBlock, sig, pSeqPostHandler);
	if (sig.IsSignalled()) return Value::Null;
	sig.SetSignal(SIGTYPE_SwitchDone, result);
	return result;
}

//-----------------------------------------------------------------------------
// Exception Handling
//-----------------------------------------------------------------------------
// try ():leader {block}
Gura_DeclareFunctionAlias(try_, "try")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Leader);
	DeclareBlock(OCCUR_Once);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Specify a try block of a statement of try-catch-else.\n"
		"It catches signals that occur in the block and executes a corresponding\n"
		"`catch()` or `else()` function that follow after it.");
}

Gura_ImplementFunction(try_)
{
	SeqPostHandler *pSeqPostHandler = NULL;
	AutoPtr<Environment> pEnvBlock(new Environment(&env, ENVTYPE_block));
	const Expr_Block *pExprBlock = args.GetBlock(*pEnvBlock, sig);
	if (sig.IsSignalled()) return Value::Null;
	Value result = pExprBlock->Exec2(*pEnvBlock, sig, pSeqPostHandler);
	if (sig.IsError()) {
		sig.SuspendError();
	} else {
		//args.FinalizeTrailer();
	}
	return result;
}

// catch (errors*:error):leader:trailer {block}
Gura_DeclareFunctionTrailerAlias(catch_, "catch")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Leader | FLAG_Trailer);
	DeclareArg(env, "errors", VTYPE_error, OCCUR_ZeroOrMore);
	DeclareBlock(OCCUR_Once);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Specify an catch block of a statement of try-catch-else.\n"
		"It can take multiple numbers of arguments of error objects to handle.\n"
		"If there's no error objects specified, it handles all the errors that are\n"
		"not handled in the preceding `catch()` function calls.\n"
		"Block parameter format: `|error:error|`\n"
		"`error` is an error object that contains information of the handled error.");
}

Gura_ImplementFunction(catch_)
{
	if (!sig.IsErrorSuspended()) return Value::Null;
	bool handleFlag = false;
	if (args.GetList(0).empty()) {
		handleFlag = true;
	} else {
		foreach_const (ValueList, pValue, args.GetList(0)) {
			if (pValue->GetErrorType() == sig.GetError().GetType()) {
				handleFlag = true;
				break;
			}
		}
	}
	if (!handleFlag) return Value::Null;
	//args.FinalizeTrailer();
	args.QuitTrailer();
	Object_error *pObj = new Object_error(env, sig.GetError());
	sig.ClearSignal(); // clear even the suspended state
	const Function *pFuncBlock =
						args.GetBlockFunc(env, sig, GetSymbolForBlock());
	if (sig.IsSignalled()) return Value::Null;
	AutoPtr<Environment> pEnvBlock(new Environment(&env, ENVTYPE_block));
	AutoPtr<Args> pArgsSub(new Args());
	pArgsSub->SetValue(Value(pObj));
	return pFuncBlock->Eval(*pEnvBlock, sig, *pArgsSub);
}

// finally ():trailer:finalizer {block}
Gura_DeclareFunctionTrailerAlias(finally_, "finally")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Trailer | FLAG_Finalizer);
	DeclareBlock(OCCUR_Once);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(finally_)
{
	SeqPostHandler *pSeqPostHandler = NULL;
	AutoPtr<Environment> pEnvBlock(new Environment(&env, ENVTYPE_block));
	const Expr_Block *pExprBlock = args.GetBlock(*pEnvBlock, sig);
	if (sig.IsSignalled()) return Value::Null;
	return pExprBlock->Exec2(*pEnvBlock, sig, pSeqPostHandler);
}

// raise(error:error, msg:string => "error", value?)
Gura_DeclareFunction(raise)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "error", VTYPE_error);
	DeclareArg(env, "msg", VTYPE_string, OCCUR_Once, FLAG_None, new Expr_Value(Value("error")));
	DeclareArg(env, "value", VTYPE_any, OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Raises an error signal with a specified error object, a message string and\n"
		"an additional value.");
}

Gura_ImplementFunction(raise)
{
	sig.SetError(args.GetErrorType(0), "%s", args.GetString(1));
	sig.SetValue(args.GetValue(2));
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Data Converter
//-----------------------------------------------------------------------------
// chr(num:number):map:[nil]
Gura_DeclareFunction(chr)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "num", VTYPE_number);
	DeclareAttr(Gura_Symbol(nil));
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Converts a UTF-8 code into a string.\n"
		"\n"
		"A number between 128 and 255 is an invalid number and is converted to a null string.\n"
		"If attribute `:nil` is specified, it returns `nil` for that case.\n");
}

Gura_ImplementFunction(chr)
{
	ULong num = args.GetULong(0);
	int i = 0;
	UChar buff[4];
	buff[i++] = static_cast<UChar>(num & 0xff);
	num >>= 8;
	for ( ; num != 0; num >>= 8) {
		buff[i++] = static_cast<UChar>(num & 0xff);
	}
	String str;
	if (i != 1 || (0x00 < buff[0] && buff[0] < 0x7f)) {
		for ( ; i > 0; i--) {
			str.push_back(static_cast<char>(buff[i - 1]));
		}
	} else if (args.IsSet(Gura_Symbol(nil))) {
		return Value::Null;
	}
	return Value(str);
}

// hex(num:number, digits?:number):map:[upper]
Gura_DeclareFunction(hex)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "num", VTYPE_number);
	DeclareArg(env, "digits", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareAttr(Gura_Symbol(upper));
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Converts a number into a hexadecimal string.\n"
		"Argument `digits` specifies a minimum columns of the converted result\n"
		"and fills `0` in the lacking space.\n"
		"\n"
		"In default, it uses lower-case characters in its conversion,\n"
		"while it uses upper-case ones when `:upper` attribute is specified.\n");
}

Gura_ImplementFunction(hex)
{
	int digits = args.Is_number(1)? args.GetInt(1) : 0;
	bool upperFlag = args.IsSet(Gura_Symbol(upper));
	String str;
	if (digits <= 0) {
		str = Formatter::Format(sig, upperFlag? "%X" : "%x",
						ValueList(args.GetValue(0)));
	} else {
		str = Formatter::Format(sig, upperFlag? "%0*X" : "%0*x",
						ValueList(Value(digits), args.GetValue(0)));
	}
	if (sig.IsSignalled()) return Value::Null;
	return Value(str);
}

// int(value):map
Gura_DeclareFunctionAlias(int_, "int")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "value", VTYPE_any);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Converts a value into an integer number like below:\n"
		"\n"
		"- For a number value, it would be converted into an integer number.\n"
		"- For a compex value, its absolute number would be converted into an integer number.\n"
		"- For a string value, it would be parsed as an integer number.\n"
		"  An error occurs if it has an invalid format.\n"
		"- For other values, an error occurs.\n");
}

Gura_ImplementFunction(int_)
{
	const Value &value = args.GetValue(0);
	Value result;
	if (value.Is_number()) {
		result.SetNumber(value.GetLong());
	} else if (value.Is_complex()) {
		result.SetNumber(static_cast<long>(std::abs(value.GetComplex())));
	} else if (value.Is_string()) {
		bool successFlag;
		Number num = value.ToNumber(true, successFlag);
		if (!successFlag) {
			sig.SetError(ERR_ValueError, "failed to convert to a number");
			return Value::Null;
		}
		result.SetNumber(static_cast<long>(num));
	} else if (value.IsValid()) {
		SetError_InvalidValType(sig, value);
	}
	return result;
}

// ord(str:string):map
Gura_DeclareFunction(ord)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "str", VTYPE_string);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Converts the first character of a string into a number of UTF-8 code.\n"
		"If the string contains more than one characters, it simply neglects trailing ones.\n");
}

Gura_ImplementFunction(ord)
{
	const char *str = args.GetString(0);
	ULong num = static_cast<UChar>(*str);
	if (IsUTF8First(*str)) {
		str++;
		for ( ; IsUTF8Follower(*str); str++) {
			num = (num << 8) | static_cast<UChar>(*str);
		}
	}
	return Value(num);
}

// tonumber(value):map:[strict,raise,zero,nil]
Gura_DeclareFunction(tonumber)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "value", VTYPE_any);
	DeclareAttr(Gura_Symbol(strict));
	DeclareAttr(Gura_Symbol(raise));
	DeclareAttr(Gura_Symbol(zero));
	DeclareAttr(Gura_Symbol(nil));
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Converts a string value into a number by a lexical parsing.\n"
		"If the value is not a string, it first tries to convert the value into a string.\n"
		"\n"
		"If the string starts with a sequence of characters that can be parsed as a number literal,\n"
		"it's not a failure even when it contains other characters following them.\n"
		"Specifying an attribute `:strict` doesn't allow such a case and fails the process.\n"
		"\n"
		"If it fails the conversion, it would return `nil` value.\n"
		"Attributes described below are prepared to customize the behaviour in the case of a failure.\n"
		"\n"
		"- `:raise` .. raises an error\n"
		"- `:zero` .. returns zero value\n"
		"- `:nil` .. returns `nil` value (default)\n");
}

Gura_ImplementFunction(tonumber)
{
	bool allowPartFlag = !args.IsSet(Gura_Symbol(strict));
	bool successFlag;
	Number num = args.GetValue(0).ToNumber(allowPartFlag, successFlag);
	if (successFlag) {
		return Value(num);
	} else if (args.IsSet(Gura_Symbol(raise))) {
		sig.SetError(ERR_ValueError, "failed to convert to a number");
		return Value::Null;
	} else if (args.IsSet(Gura_Symbol(zero))) {
		return Value(0.);
	} else { // args.IsSet(Gura_UserSymbol(nil)
		return Value::Null;
	}
}

// tostring(value):map
Gura_DeclareFunction(tostring)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "value", VTYPE_any);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Converts a value into a string.");
}

Gura_ImplementFunction(tostring)
{
	return Value(args.GetValue(0).ToString(false));
}

// tosymbol(str:string):map
Gura_DeclareFunction(tosymbol)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "str", VTYPE_string);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Converts a string into a symbol.");
}

Gura_ImplementFunction(tosymbol)
{
	return Value(Symbol::Add(args.GetString(0)));
}

//-----------------------------------------------------------------------------
// Class Operations
//-----------------------------------------------------------------------------
// class(superclass?) {block?}
Gura_DeclareFunctionAlias(class_, "class")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "superclass", VTYPE_function, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns a function object of a constructor for a class\n"
		"that includes methods and properties described in the content of the `block`.\n"
		"For a detail on how to describe the block content for this function,\n"
		"refer to \"Gura Language Manual\".\n"
		"\n"
		"Example:\n"
		"\n"
		"    Person = class {\n"
		"        __init__(name:string, age:number) = {\n"
		"            this.name = name\n"
		"            this.age = age\n"
		"        }\n"
		"        Print() = {\n"
		"            printf('name:%s age:%d\\n', this.name, this.age)\n"
		"        }\n"
		"    }\n"
		"    person = Person('Smith', 26)\n"
		"    person.Print()\n"
		"\n"
		"If argument `superclass`,\n"
		"which is expected to be a constructor function of a super class, is specified,\n"
		"the created class shall inherits methods and properties from the specified class.\n");
}

Gura_ImplementFunction(class_)
{
	const Expr_Block *pExprBlock = args.GetBlock(env, sig);
	if (sig.IsSignalled()) return Value::Null;
	Class *pClassSuper = env.LookupClass(VTYPE_object);
	const Value &valueSuper = args.GetValue(0);
	if (valueSuper.Is_function()) {
		pClassSuper = valueSuper.GetFunction()->GetClassToConstruct();
		if (pClassSuper == NULL) {
			valueSuper.GetFunction()->SetError_NotConstructor(sig);
			return Value::Null;
		}
	}
	ClassCustom *pClassCustom = new ClassCustom(&env, pClassSuper,
			pClassSuper->GetValueType(),
			dynamic_cast<Expr_Block *>(Expr::Reference(pExprBlock)), sig);
	return Value(pClassCustom);
}

// classref(type+:expr):map {block?}
Gura_DeclareFunction(classref)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "type", VTYPE_expr, OCCUR_OnceOrMore);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Looks up a class by an expression of a type name.");
}

Gura_ImplementFunction(classref)
{
	const ValueTypeInfo *pValueTypeInfo = env.LookupValueType(sig, args.GetList(0));
	if (pValueTypeInfo == NULL) return Value::Null;
	Value result(Class::Reference(pValueTypeInfo->GetClass()));
	return ReturnValue(env, sig, args, result);
}

// struct(`args*):[loose] {block?}
// if :loose attribute is specified, arguments in the generated function
// will get the following modification.
// - Once attribute will be modified to ZeroOrOnce.
// - OnceOrMore attribute will be modified to ZeroOrMore
Gura_DeclareFunctionAlias(struct_, "struct")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "args", VTYPE_quote, OCCUR_OnceOrMore);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareAttr(Gura_Symbol(loose));
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns a function object of a constructor for a structure that\n"
		"contains properties specified by `args`. It can optionally take block\n"
		"which declares methods and properties just like `class` function.\n"
		"\n"
		"An element in `args` is an expression that has the same format with\n"
		"one in the argument list of a function's declaration.\n"
		"Each variable name becomes a member name in the created instance.\n"
		"\n"
		"Example:\n"
		"\n"
		"    Person = struct(name:string, age:number)\n"
		"    person = Person('Smith', 26)\n"
		"    printf('name:%s age:%d\\n', person.name, person.age)\n"
		"\n"
		"If `:loose` attribute is speicied, the generated constructor\n"
		"would take all the arguments as optional.\n"
		"Omitted variables are set to `nil`\n");
}

Gura_ImplementFunction(struct_)
{
	const Expr_Block *pExprBlock = args.GetBlock(env, sig);
	if (sig.IsSignalled()) return Value::Null;
	Class *pClassSuper = env.LookupClass(VTYPE_Struct);
	ClassCustom *pClassCustom = new ClassCustom(&env, pClassSuper,
			pClassSuper->GetValueType(),
			dynamic_cast<Expr_Block *>(Expr::Reference(pExprBlock)), sig);
	AutoPtr<ExprOwner> pExprOwnerArg(new ExprOwner());
	foreach_const (ValueList, pValue, args.GetList(0)) {
		pExprOwnerArg->push_back(pValue->GetExpr()->Reference());
	}
	AutoPtr<ClassOfStruct::Constructor> pFunc(new ClassOfStruct::Constructor(env));
	pFunc->SetClassToConstruct(pClassCustom); // constructor is registered in this class
	pFunc->DeclareBlock(OCCUR_ZeroOrOnce);
	AutoPtr<Args> pArgsSub(new Args());
	pArgsSub->SetExprOwnerArg(pExprOwnerArg.release());
	pArgsSub->SetAttrs(args.GetAttrs());
	if (!pFunc->CustomDeclare(env, sig, _attrsOpt, *pArgsSub)) return false;
	if (args.IsSet(Gura_Symbol(loose))) {
		pFunc->GetDeclOwner().SetAsLoose();
	}
	return Value(pClassCustom);
}

// super(obj) {block?}
Gura_DeclareFunction(super)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "obj", VTYPE_any, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns a reference to `obj` that searches methods in a scope of the super class of its own.\n"
		"\n"
		"Example:\n"
		"\n"
		"    A = class {\n"
		"        func() = {}\n"
		"    }\n"
		"    \n"
		"    B = class(A) {\n"
		"        func() = {}\n"
		"    }\n"
		"    \n"
		"    b = B()\n"
		"    b.func()         // B#func() is called.\n"
		"    super(b).func()  // A#func() is called.\n"
		);
}

Gura_ImplementFunction(super)
{
	Value rtn(args.GetValue(0));
	int cntSuperSkip = rtn.GetSuperSkipCount() + 1;
	if (cntSuperSkip > Value::MaxSuperSkipCount) {
		sig.SetError(ERR_SystemError,
			"number of super reference is limited under %d", Value::MaxSuperSkipCount);
		return Value::Null;
	}
	rtn.SetSuperSkipCount(cntSuperSkip);
	return ReturnValue(env, sig, args, rtn);
}

//-----------------------------------------------------------------------------
// Scope Operations
//-----------------------------------------------------------------------------
#if 0
// Scope problem: when a block tries to assign a variable that has been declared by extern()
// outside of it, it fails to do it.
// 
//     x = 0
//     f() = {
//         extern(x)
//         if (true) {
//             x = 3
//         }
//     }
//     println(x)  // print 0, not 3

// extern(`syms+)
Gura_DeclareFunctionAlias(extern_, "extern")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "syms", VTYPE_quote, OCCUR_OnceOrMore);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Declares symbols that is supposed to access variables in outer scopes.");
}

Gura_ImplementFunction(extern_)
{
	foreach_const (ValueList, pValue, args.GetList(0)) {
		const Expr *pExpr = pValue->GetExpr();
		if (!pExpr->IsIdentifier()) {
			sig.SetError(ERR_ValueError, "identifier must be specified");
			return Value::Null;
		}
		const Symbol *pSymbol = dynamic_cast<const Expr_Identifier *>(pExpr)->GetSymbol();
		if (env.LookupValue(pSymbol, ENVREF_Escalate) == NULL) {
			sig.SetError(ERR_ValueError, "undefined symbol '%s'", pSymbol->GetName());
		}
	}
	return Value::Null;
}
#endif

// local(`syms+)
Gura_DeclareFunction(local)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "syms", VTYPE_quote, OCCUR_OnceOrMore);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Declares symbols that is supposed to access variables in a local scope.");
}

Gura_ImplementFunction(local)
{
	foreach_const (ValueList, pValue, args.GetList(0)) {
		const Expr *pExpr = pValue->GetExpr();
		if (!pExpr->IsIdentifier()) {
			sig.SetError(ERR_ValueError, "identifier must be specified");
			return Value::Null;
		}
		const Symbol *pSymbol = dynamic_cast<const Expr_Identifier *>(pExpr)->GetSymbol();
		if (env.LookupValue(pSymbol, ENVREF_NoEscalate) == NULL) {
			env.AssignValue(pSymbol, Value::Null, EXTRA_Public);
		}
	}
	return Value::Null;
}

// locals(module?:module) {block?}
Gura_DeclareFunction(locals)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "module", VTYPE_Module, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns an environment object that belongs to a specified module.\n"
		"If module is omitted, it returns an environment object of the current scope.");
}

Gura_ImplementFunction(locals)
{
	Value value;
	if (args.IsModule(0)) {
		value = Value(new Object_environment(*args.GetModule(0)));
	} else {
		value = Value(new Object_environment(env));
	}
	return ReturnValue(env, sig, args, value);
}

// outers() {block?}
Gura_DeclareFunction(outers)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns an environment object that accesses to an outer scope.");
}

Gura_ImplementFunction(outers)
{
	AutoPtr<Environment> pEnvOuter(new Environment());
	pEnvOuter->AddOuterFrame(env.GetFrameOwner());
	return ReturnValue(env, sig, args, Value(new Object_environment(*pEnvOuter)));
}

// public():void {block}
Gura_DeclareFunctionAlias(public_, "public")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareBlock(OCCUR_Once);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Declares symbols as public ones that are accessible from outer scopes.\n"
		"\n"
		"If you want to make `foo` and `bar` accessible, call this function like below:\n"
		"\n"
		"    public { foo, bar }\n");
}

Gura_ImplementFunction(public_)
{
	SeqPostHandler *pSeqPostHandler = NULL;
	SymbolSet &symbolsPublic = env.PrepareSymbolsPublic();
	const Expr_Block *pExprBlock = args.GetBlock(env, sig);
	foreach_const (ExprOwner, ppExpr, pExprBlock->GetExprOwner()) {
		const Expr *pExpr = *ppExpr;
		if (pExpr->IsIdentifier()) {
			const Expr_Identifier *pExprIdentifier = dynamic_cast<const Expr_Identifier *>(pExpr);
			symbolsPublic.Insert(pExprIdentifier->GetSymbol());
		} else if (pExpr->IsAssign()) {
			const Expr_Assign *pExprAssign = dynamic_cast<const Expr_Assign *>(pExpr);
			if (!pExprAssign->GetLeft()->IsIdentifier()) {
				sig.SetError(ERR_ValueError, "invalid element for public");
				return Value::Null;
			}
			const Expr_Identifier *pExprIdentifier = dynamic_cast<const Expr_Identifier *>(pExprAssign->GetLeft());
			symbolsPublic.Insert(pExprIdentifier->GetSymbol());
			pExpr->Exec2(env, sig, pSeqPostHandler);
			if (sig.IsSignalled()) return Value::Null;
		} else {
			sig.SetError(ERR_ValueError, "invalid element for public");
			return Value::Null;
		}
	}
	return Value::Null;
}

// scope(target?) {block}
Gura_DeclareFunction(scope)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "target", VTYPE_any, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_Once);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Evaluates block with a local scope.");
}

Gura_ImplementFunction(scope)
{
	if (args.IsInvalid(0)) {
		SeqPostHandler *pSeqPostHandler = NULL;
		AutoPtr<Environment> pEnvBlock(new Environment(&env, ENVTYPE_local));
		const Expr_Block *pExprBlock = args.GetBlock(*pEnvBlock, sig);
		if (sig.IsSignalled()) return Value::Null;
		return pExprBlock->Exec2(*pEnvBlock, sig, pSeqPostHandler);
	} else {
		SeqPostHandler *pSeqPostHandler = NULL;
		Environment *pEnv = NULL;
		if (args.IsModule(0)) {
			pEnv = args.GetModule(0);
		} else if (args.IsClass(0)) {
			pEnv = args.GetValue(0).GetClassItself();
		} else if (args.Is_function(0)) {
			pEnv = args.GetFunction(0)->GetClassToConstruct();
		} else if (args.IsType(0, VTYPE_environment)) {
			pEnv = &Object_environment::GetObject(args, 0)->GetEnv();
		}
		if (pEnv != NULL) {
			const Expr_Block *pExprBlock = args.GetBlock(*pEnv, sig);
			if (sig.IsSignalled()) return Value::Null;
			return pExprBlock->Exec2(*pEnv, sig, pSeqPostHandler);
		}
	}
	sig.SetError(ERR_ValueError, "module or environment must be specified");
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Module Operations
//-----------------------------------------------------------------------------
// module {block}
Gura_DeclareFunction(module)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_Once);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Creates a module that contains functions and variables defined in the block\n"
		"and returns it as a module object. This can be used to realize a namespace.");
}

Gura_ImplementFunction(module)
{
	SeqPostHandler *pSeqPostHandler = NULL;
	const Expr_Block *pExprBlock = args.GetBlock(env, sig);
	if (sig.IsSignalled()) return Value::Null;
	Module *pModule = new Module(&env, Gura_Symbol(_anonymous_), "", NULL, NULL);
	pExprBlock->Exec2(*pModule, sig, pSeqPostHandler);
	return Value(pModule);
}

// import(`module, `alias?):void:[binary,overwrite,mixin_type] {block?}
Gura_DeclareFunctionAlias(import_, "import")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "module", VTYPE_quote);
	DeclareArg(env, "alias", VTYPE_quote, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareAttr(Gura_Symbol(overwrite));
	DeclareAttr(Gura_Symbol(binary));
	DeclareAttr(Gura_Symbol(mixin_type));
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Imports a module stored in directories specified by a variable sys.path\n"
		"and creates a variable that represents the imported module.\n"
		"There are three format of calling this function like follow:\n"
		"\n"
		"- `import(foo)` .. imports `foo` module and creates a module object named `foo`\n"
		"- `import(foo, bar)` .. imports `foo` module and creates a module object named `bar`\n"
		"- `import(foo) {symbol1, symbol2, symbol3}` .. imports `foo` and\n"
		"  mixes up properties `symbol1`, `symbol2` and `symbol3` in the current scope,\n"
		"  which are defined in the module.\n"
		"\n"
		"In the third format, you can specify an asterisk character\n"
		"to mixes up all the symbols defined in the module like below:\n"
		"\n"
		"    import(foo) {*}\n"
		"\n"
		"If a specified symbol conflicts with what already exists in the current scope,\n"
		"it will cause an error.\n"
		"Specifying the attribute `:overwrite` will avoid such an error\n"
		"and allow overwriting of symbols.\n"
		"\n"
		"If the argument `module` is prefixed by a minus operator like `-foo`,\n"
		"it will not create a variable that represents the imported module.\n"
		"\n"
		"If the argument `module` is prefixed by an and operator like `&foo`,\n"
		"the trailing expression will be evaluated and its result, which must be a string,\n"
		"is treated as a module name to be imported. Below is a sample to import `foo` module\n"
		"through a variable that contains that name:\n"
		"\n"
		"    var = 'foo'\n"
		"    import(&var)\n");
}

Gura_ImplementFunction(import_)
{
	SymbolSet symbolsToMixIn;
	SymbolSet *pSymbolsToMixIn = NULL;
	if (args.IsBlockSpecified()) {
		const Expr_Block *pExprBlock = args.GetBlock(env, sig);
		if (sig.IsSignalled()) return Value::Null;
		foreach_const (ExprList, ppExpr, pExprBlock->GetExprOwner()) {
			if (!(*ppExpr)->IsIdentifier()) {
				sig.SetError(ERR_SyntaxError,
					"wrong format for an element in import list");
				return Value::Null;
			}
			const Expr_Identifier *pExprIdentifier =
							dynamic_cast<const Expr_Identifier *>(*ppExpr);
			symbolsToMixIn.insert(pExprIdentifier->GetSymbol());
		}
		pSymbolsToMixIn = &symbolsToMixIn;
	}
	const Symbol *pSymbolAlias = NULL;
	if (!args.Is_expr(1)) {
		// nothing to do
	} else if (!args.GetExpr(1)->IsIdentifier()) {
		sig.SetError(ERR_ValueError, "identifier is expected as a module name");
		return Value::Null;
	} else {
		pSymbolAlias = dynamic_cast<const Expr_Identifier *>(args.GetExpr(1))->GetSymbol();
	}
	bool overwriteFlag = args.IsSet(Gura_Symbol(overwrite));
	bool binaryOnlyFlag = args.IsSet(Gura_Symbol(binary));
	bool mixinTypeFlag = args.IsSet(Gura_Symbol(mixin_type));
	if (env.ImportModule(sig, args.GetExpr(0), pSymbolAlias, pSymbolsToMixIn,
						overwriteFlag, binaryOnlyFlag, mixinTypeFlag) == NULL) {
		return Value::Null;
	}
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Value Type Information
//-----------------------------------------------------------------------------
// isdefined(`identifier)
Gura_DeclareFunction(isdefined)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "identifier", VTYPE_quote);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns `true` if `identifier` is defined, and `false` otherwise.");
}

Gura_ImplementFunction(isdefined)
{
	bool definedFlag = false;
	const Expr *pExpr = args.GetExpr(0);
	if (pExpr->IsIdentifier() || pExpr->IsMember()) {
		SeqPostHandler *pSeqPostHandler = NULL;
		Value result = pExpr->Exec2(env, sig, pSeqPostHandler);
		if (sig.IsSignalled() && !sig.IsError()) return Value::Null;
		definedFlag = !sig.IsError() && result.IsDefined();
		sig.ClearSignal();
	} else {
		sig.SetError(ERR_ValueError, "argument must be an identifier");
		return Value::Null;
	}
	return Value(definedFlag);
}

// istype*(value)
class Gura_Function(istype_) : public Function {
private:
	ValueType _valType;
public:
	Gura_Function(istype_)(Environment &env, const char *name, ValueType valType);
	virtual Value DoEval(Environment &env, Signal sig, Args &args) const;
};
Gura_Function(istype_)::Gura_Function(istype_)(
					Environment &env, const char *name, ValueType valType) :
	Function(env, Symbol::Add(name), FUNCTYPE_Function, FLAG_None), _valType(valType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "value", VTYPE_any);
	char buff[1024];
	::sprintf(buff, "Returns `true` if the type of the specified `value` is %s, and `false` otherwise.",
		ValueTypePool::GetInstance()->Lookup(_valType)->MakeFullName().c_str());
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		buff);
}

Gura_ImplementFunction(istype_)
{
	ValueType valType = args.GetValue(0).GetValueType();
	ValueType valTypeCmp = _valType;
	if ((valType == VTYPE_number || valType == VTYPE_rational) &&
								valTypeCmp == VTYPE_complex) return Value(true);
	if (valType == VTYPE_rational && valTypeCmp == VTYPE_number) return Value(true);
	return Value(valType == valTypeCmp);
}

// istype(value, type+:expr):map
Gura_DeclareFunction(istype)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "value", VTYPE_any);
	DeclareArg(env, "type", VTYPE_expr, OCCUR_OnceOrMore);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns `true` if `value` is of the type of `type`, and `false` otherwise.\n");
}

Gura_ImplementFunction(istype)
{
	const ValueTypeInfo *pValueTypeInfo = env.LookupValueType(sig, args.GetList(1));
	if (pValueTypeInfo == NULL) return Value::Null;
	ValueType valType = args.GetValue(0).GetValueType();
	ValueType valTypeCmp = pValueTypeInfo->GetValueType();
	if ((valType == VTYPE_number || valType == VTYPE_rational) &&
								valTypeCmp == VTYPE_complex) return Value(true);
	if (valType == VTYPE_rational && valTypeCmp == VTYPE_number) return Value(true);
	return Value(valType == valTypeCmp);
}

// isinstance(value, type+:expr):map
Gura_DeclareFunction(isinstance)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "value", VTYPE_any);
	DeclareArg(env, "type", VTYPE_expr, OCCUR_OnceOrMore);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns `true` if `value` is an instance of `type` or its descendant, and `false` otherwise.\n");
}

Gura_ImplementFunction(isinstance)
{
	const ValueTypeInfo *pValueTypeInfo = env.LookupValueType(sig, args.GetList(1));
	if (pValueTypeInfo == NULL) return Value::Null;
	return args.GetValue(0).IsInstanceOf(pValueTypeInfo->GetValueType());
}

// typename(`value)
Gura_DeclareFunctionAlias(typename_, "typename")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "value", VTYPE_quote);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns a type name of the value.");
}

Gura_ImplementFunction(typename_)
{
	const Expr *pExpr = args.GetExpr(0);
	String typeName = "unknown";
	if (pExpr->IsIdentifier() || pExpr->IsMember()) {
		SeqPostHandler *pSeqPostHandler = NULL;
		Value value = pExpr->Exec2(env, sig, pSeqPostHandler);
		if (sig.IsSignalled() && !sig.IsError()) return Value::Null;
		if (sig.IsError()) {
			typeName = "undefined";
		} else {
			typeName = value.MakeValueTypeName();
		}
		sig.ClearSignal();
	} else {
		SeqPostHandler *pSeqPostHandler = NULL;
		Value value = pExpr->Exec2(env, sig, pSeqPostHandler);
		if (sig.IsSignalled()) return Value::Null;
		typeName = value.MakeValueTypeName();
	}
	return Value(typeName);
}

// undef(`identifier+):[raise]
Gura_DeclareFunctionAlias(undef_, "undef")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "identifier", VTYPE_quote, OCCUR_OnceOrMore);
	DeclareAttr(Gura_Symbol(raise));
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Undefines `identifier` in the current scope.");
}

Gura_ImplementFunction(undef_)
{
	bool raiseFlag = args.IsSet(Gura_Symbol(raise));
	foreach_const (ValueList, pValueArg, args.GetList(0)) {
		const Expr *pExpr = pValueArg->GetExpr();
		Environment *pEnv = &env;
		const Symbol *pSymbol = NULL;
		if (pExpr->IsIdentifier()) {
			pSymbol = dynamic_cast<const Expr_Identifier *>(pExpr)->GetSymbol();
		} else {
			SymbolList symbolList;
			if (!Parser::ParseDottedIdentifier(pExpr, symbolList)) {
				sig.SetError(ERR_ValueError, "invalid identifier name");
				return Value::Null;
			}
			for (SymbolList::iterator ppSymbol = symbolList.begin();
								ppSymbol + 1 != symbolList.end(); ppSymbol++) {
				Value *pValue = pEnv->LookupValue(*ppSymbol, ENVREF_NoEscalate);
				if (pValue == NULL) {
					if (raiseFlag) {
						sig.SetError(ERR_ValueError, "undefined identifier");
					}
					return Value::Null;
				}
				if (pValue->IsModule()) {
					pEnv = pValue->GetModule();
				} else if (pValue->IsClass()) {
					pEnv = pValue->GetClassItself();
				} else if (pValue->IsObject()) {
					pEnv = pValue->GetObject();
				} else {
					sig.SetError(ERR_ValueError, "invalid identifier name");
					return Value::Null;
				}
			}
			pSymbol = symbolList.back();
		}
		if (raiseFlag && !pEnv->LookupValue(pSymbol, ENVREF_NoEscalate)) {
			sig.SetError(ERR_ValueError, "undefined identifier");
			return Value::Null;
		}
		pEnv->RemoveValue(pSymbol);
	}
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Data Processing
//-----------------------------------------------------------------------------
// choose(index:number, values+):map
Gura_DeclareFunction(choose)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "index", VTYPE_number);
	DeclareArg(env, "values", VTYPE_any, OCCUR_OnceOrMore);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Picks up a value placed at `index` in the argument list `values`.\n"
		"\n"
		"Sample:\n"
		"\n"
		"    choose(0, 'apple', 'orange', 'banana') // returns 'apple'\n"
		"    choose(2, 'apple', 'orange', 'banana') // returns 'banana'\n");
}

Gura_ImplementFunction(choose)
{
	size_t index = args.GetSizeT(0);
	const ValueList &valList = args.GetList(1);
	if (index >= valList.size()) {
		sig.SetError(ERR_IndexError, "index is out of range");
		return Value::Null;
	}
	return valList[index];
}

// cond(flag:boolean, value1:nomap, value2:nomap?):map
Gura_DeclareFunction(cond)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "flag", VTYPE_boolean);
	DeclareArg(env, "value1", VTYPE_any, OCCUR_Once, FLAG_NoMap);
	DeclareArg(env, "value2", VTYPE_any, OCCUR_ZeroOrOnce, FLAG_NoMap);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns `value1` if `flag` is determined as true, and `value2` otherwise.\n"
		"If the argument `value2` is omitted, it will return `nil` when `flag` is determined as false.\n"
		"\n"
		"This function behaves in a similar way with `if` function when it's called like below:\n"
		"\n"
		"    if (flag) { value1 } else { value2 }\n"
		"\n"
		"Notice that they have the following differences:\n"
		"\n"
		"- Function `cond()` always evaluates arguments `value1` and `value2`\n"
		"  no matter what `flag` value is,\n"
		"  while function `if()` doesn't evaluate `value1` expression\n"
		"  when `flag` is determined as `false`.\n"
		"- Function `cond()` works with implicit mapping,\n"
		"  which means that the argument `flag` may be a list or an iterator\n"
		"  that are to be processed with the implicit mapping.\n"
		"\n"
		"The arguments `value1` and `value2` are not processed by the implicit mapping,\n"
		"so you can specify a list or an iterator for them as selected items.\n");
}

Gura_ImplementFunction(cond)
{
	return args.GetBoolean(0)? args.GetValue(1) : args.GetValue(2);
}

// conds(flag:boolean, value1, value2?):map
Gura_DeclareFunction(conds)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "flag", VTYPE_boolean);
	DeclareArg(env, "value1", VTYPE_any, OCCUR_Once);
	DeclareArg(env, "value2", VTYPE_any, OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns `value1` if `flag` is determined as true, and `value2` otherwise.\n"
		"If argument `value2` is omitted, it will return `nil` when `flag` is determined as false.\n"
		"\n"
		"This function behaves in a similar way with `if` function when it's called like below:\n"
		"\n"
		"    if (flag) { value1 } else { value2 }\n"
		"\n"
		"Notice that they have the following differences:\n"
		"\n"
		"- Function `conds()` always evaluates arguments `value1` and `value2`\n"
		"  no matter what `flag` value is,\n"
		"  while function `if()` doesn't evaluate `value1` expression\n"
		"  when `flag` is determined as false.\n"
		"- Function `conds()` works with implicit mapping,\n"
		"  which means that the arguments `flag`, `value1` and `value2` may be lists or iterators\n"
		"  that are to be processed with the implicig mapping.\n"
		"\n"
		"If you want to specify a list or an iterator for `value1` and `value2` as selected values,\n"
		"use `cond()` function instead.\n");
}

Gura_ImplementFunction(conds)
{
	return args.GetBoolean(0)? args.GetValue(1) : args.GetValue(2);
}

// max(values+):map
Gura_DeclareFunction(max)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "values", VTYPE_any, OCCUR_OnceOrMore);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns the maximum value among the given arguments.");
}

Gura_ImplementFunction(max)
{
	const ValueList &valList = args.GetList(0);
	ValueList::const_iterator pValue = valList.begin();
	Value result = *pValue++;
	for ( ; pValue != valList.end(); pValue++) {
		int cmp = Value::Compare(env, sig, result, *pValue);
		if (sig.IsSignalled()) return Value::Null;
		if (cmp < 0) result = *pValue;
	}
	return result;
}

// min(values+):map
Gura_DeclareFunction(min)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "values", VTYPE_any, OCCUR_OnceOrMore);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns the minimum value among the given arguments.");
}

Gura_ImplementFunction(min)
{
	const ValueList &valList = args.GetList(0);
	ValueList::const_iterator pValue = valList.begin();
	Value result = *pValue++;
	for ( ; pValue != valList.end(); pValue++) {
		int cmp = Value::Compare(env, sig, result, *pValue);
		if (sig.IsSignalled()) return Value::Null;
		if (cmp > 0) result = *pValue;
	}
	return result;
}

//-----------------------------------------------------------------------------
// Random
//-----------------------------------------------------------------------------
// rand(range?:number) {block?}
Gura_DeclareFunction(rand)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "range", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns a random number between `0` and `(range - 1)`.\n"
		"If argument `range` is not specified, it generates random numbers in a range of [0, 1).");
}

Gura_ImplementFunction(rand)
{
	if (args.Is_number(0)) {
		ULong num = args.GetULong(0);
		Number result = static_cast<ULong>(Random::Real2() * num);
		return Value(result);
	}
	return ReturnValue(env, sig, args, Value(Random::Real2()));
}

// rands(range?:number, num?:number) {block?}
Gura_DeclareFunction(rands)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "range", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "num", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Creates an iterator that returns random numbers between `0` and `(range - 1)`.\n"
		"\n"
		"If argument `range` is not specified, it generates random numbers in a range of [0, 1).\n"
		"\n"
		"In default, the created iterator infinitely generates random numbers.\n"
		"The argument `num` specifies how many elements should be generated.\n"
		"\n"
		GURA_ITERATOR_HELP
		"\n"
		"Below is an example:\n"
		"\n"
		"    x = rands(100)\n"
		"    // x is an infinite iterator to generates random numbers between 0 and 99\n");
}

Gura_ImplementFunction(rands)
{
	Iterator *pIterator = new Iterator_Rand(
				args.Is_number(0)? args.GetInt(0) : 0,
				args.Is_number(1)? args.GetInt(1) : -1);
	return ReturnIterator(env, sig, args, pIterator);
}

// randseed(seed:number):void
Gura_DeclareFunction(randseed)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "seed", VTYPE_number);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Initializes random seed with a specified number.");
}

Gura_ImplementFunction(randseed)
{
	Random::Initialize(args.GetULong(0));
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Property Listing
//-----------------------------------------------------------------------------
// dir(obj?):[noesc]
Gura_DeclareFunction(dir)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "obj", VTYPE_any, OCCUR_ZeroOrOnce);
	DeclareAttr(Gura_Symbol(noesc));
	//DeclareAttr(Gura_Symbol(nosort));
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns a symbol list of variables and functions\n"
		"that are assigned in the environment of `obj`.\n"
		"\n"
		"In default, when the `obj` is an instance of a class,\n"
		"it also searches symbols assigned in the class that it belongs to and its parent classes.\n"
		"Specifying attribute `:noesc` avoids that behavior.\n");
}

Gura_ImplementFunction(dir)
{
	bool escalateFlag = !args.IsSet(Gura_Symbol(noesc));
	bool sortFlag = !args.IsSet(Gura_Symbol(nosort));
	SymbolList symbolList;
	if (args.IsValid(0)) {
		SymbolSet symbols;
		if (!args.GetValue(0).DirProp(env, sig, symbols, escalateFlag)) return Value::Null;
		foreach_const (SymbolSet, ppSymbol, symbols) {
			const Symbol *pSymbol = *ppSymbol;
			symbolList.push_back(pSymbol);
		}
	} else {
		foreach_const (ValueMap, iter, env.GetBottomFrame()->GetValueMap()) {
			const Symbol *pSymbol = iter->first;
			symbolList.push_back(pSymbol);
		}
	}
	if (sortFlag) symbolList.SortByName();
	Value result;
	ValueList &valList = result.InitAsList(env);
	valList.reserve(symbolList.size());
	foreach_const (SymbolList, ppSymbol, symbolList) {
		const Symbol *pSymbol = *ppSymbol;
		valList.push_back(Value(pSymbol));
	}
	return result;
}

// dirtype(obj?):[noesc]
Gura_DeclareFunction(dirtype)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "obj", VTYPE_any, OCCUR_ZeroOrOnce);
	DeclareAttr(Gura_Symbol(noesc));
	//DeclareAttr(Gura_Symbol(nosort));
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns a symbol list of value types\n"
		"that are assigned in the environment of `obj`.\n"
		"\n"
		"In default, when the `obj` is an instance of a class,\n"
		"it also searches symbols assigned in the class that it belongs to and its parent classes.\n"
		"Specifying attribute `:noesc` inhibits avoids behavior.\n");
}

Gura_ImplementFunction(dirtype)
{
	bool escalateFlag = !args.IsSet(Gura_Symbol(noesc));
	bool sortFlag = !args.IsSet(Gura_Symbol(nosort));
	SymbolList symbolList;
	if (args.IsValid(0)) {
		SymbolSet symbols;
		args.GetValue(0).DirValueType(symbols, escalateFlag);
		foreach_const (SymbolSet, ppSymbol, symbols) {
			const Symbol *pSymbol = *ppSymbol;
			symbolList.push_back(pSymbol);
		}
	} else {
		foreach_const (ValueTypeMap, iter, env.GetBottomFrame()->GetValueTypeMap()) {
			const Symbol *pSymbol = iter->first;
			symbolList.push_back(pSymbol);
		}
	}
	if (sortFlag) symbolList.SortByName();
	Value result;
	ValueList &valList = result.InitAsList(env);
	valList.reserve(symbolList.size());
	foreach_const (SymbolList, ppSymbol, symbolList) {
		const Symbol *pSymbol = *ppSymbol;
		valList.push_back(Value(pSymbol));
	}
	return result;
}

// Module entry
Gura_ModuleEntry()
{
	// value assignment
	Gura_AssignValue(__name__,	Value("__main__"));
	Gura_AssignValue(nil,		Value::Null);
	Gura_AssignValueEx("-",		Value::Null);
	Gura_AssignValueEx("@rem",	Value::Null); // dummy for MS-DOS batch
	Gura_AssignValueEx("true",	Value(true));
	Gura_AssignValueEx("false",	Value(false));
	Gura_AssignValueEx("*",		Value(new Object_iterator(env, new Iterator_SequenceInf(0))));
	do {
		Object_environment *pObj = new Object_environment(env);
		Gura_AssignValue(root, Value(pObj));
	} while (0);
	// Formatting and Printing of Text
	Gura_AssignFunction(format);
	Gura_AssignFunction(print);
	Gura_AssignFunction(printf);
	Gura_AssignFunction(println);
	// Repetition
	Gura_AssignFunction(cross);
	Gura_AssignFunction(for_);
	Gura_AssignFunction(repeat);
	Gura_AssignFunction(while_);
	// Value Generator
	Gura_AssignFunction(consts);
	Gura_AssignFunction(dim);
	Gura_AssignFunction(interval);
	Gura_AssignFunction(range);
	// Flow Control
	Gura_AssignFunction(break_);
	Gura_AssignFunction(continue_);
	Gura_AssignFunction(return_);
	// Branch Sequence
	Gura_AssignFunction(if_);
	Gura_AssignFunction(elsif_);
	Gura_AssignFunction(else_);
	Gura_AssignFunction(end);
	Gura_AssignFunction(switch_);
	Gura_AssignFunction(case_);
	Gura_AssignFunction(default_);
	// Exception Handling
	Gura_AssignFunction(try_);
	Gura_AssignFunction(catch_);
	Gura_AssignFunction(finally_);
	Gura_AssignFunction(raise);
	// Data Converter
	Gura_AssignFunction(chr);
	Gura_AssignFunction(hex);
	Gura_AssignFunction(int_);
	Gura_AssignFunction(ord);
	Gura_AssignFunction(tonumber);
	Gura_AssignFunction(tostring);
	Gura_AssignFunction(tosymbol);
	// Class Operation
	Gura_AssignFunction(class_);
	Gura_AssignFunction(classref);
	Gura_AssignFunction(struct_);
	Gura_AssignFunction(super);
	// Scope Operation
	//Gura_AssignFunction(extern_);
	Gura_AssignFunction(local);
	Gura_AssignFunction(locals);
	Gura_AssignFunction(outers);
	Gura_AssignFunction(public_);
	Gura_AssignFunction(scope);
	// Module Operation
	Gura_AssignFunction(import_);
	Gura_AssignFunction(module);
	// Value Type Information
	Gura_AssignFunctionExx(istype_, "isbinary",		VTYPE_binary);
	Gura_AssignFunctionExx(istype_, "isboolean",	VTYPE_boolean);
	Gura_AssignFunctionExx(istype_, "isclass",		VTYPE_Class);
	Gura_AssignFunctionExx(istype_, "iscomplex",	VTYPE_complex);
	Gura_AssignFunctionExx(istype_, "isdatetime",	VTYPE_datetime);
	Gura_AssignFunctionExx(istype_, "isdict",		VTYPE_dict);
	Gura_AssignFunctionExx(istype_, "isenvironment",VTYPE_environment);
	Gura_AssignFunctionExx(istype_, "iserror",		VTYPE_error);
	Gura_AssignFunctionExx(istype_, "isexpr",		VTYPE_expr);
	Gura_AssignFunctionExx(istype_, "isfunction",	VTYPE_function);
	Gura_AssignFunctionExx(istype_, "isiterator",	VTYPE_iterator);
	Gura_AssignFunctionExx(istype_, "islist",		VTYPE_list);
	Gura_AssignFunctionExx(istype_, "ismatrix",		VTYPE_matrix);
	Gura_AssignFunctionExx(istype_, "ismodule",		VTYPE_Module);
	Gura_AssignFunctionExx(istype_, "isnil",		VTYPE_nil);
	Gura_AssignFunctionExx(istype_, "isnumber",		VTYPE_number);
	Gura_AssignFunctionExx(istype_, "isrational",	VTYPE_rational);
	Gura_AssignFunctionExx(istype_, "issemaphore",	VTYPE_semaphore);
	Gura_AssignFunctionExx(istype_, "isstring",		VTYPE_string);
	Gura_AssignFunctionExx(istype_, "issymbol",		VTYPE_symbol);
	Gura_AssignFunctionExx(istype_, "istimedelta",	VTYPE_timedelta);
	Gura_AssignFunctionExx(istype_, "isuri",		VTYPE_uri);
	Gura_AssignFunction(isdefined);
	Gura_AssignFunction(isinstance);
	Gura_AssignFunction(istype);
	Gura_AssignFunction(typename_);
	Gura_AssignFunction(undef_);
	// Data Processing
	Gura_AssignFunction(choose);
	Gura_AssignFunction(cond);
	Gura_AssignFunction(conds);
	Gura_AssignFunction(max);
	Gura_AssignFunction(min);
	// Random
	Gura_AssignFunction(rand);
	Gura_AssignFunction(rands);
	Gura_AssignFunction(randseed);
	// Property Listing
	Gura_AssignFunction(dir);
	Gura_AssignFunction(dirtype);
	return true;
}

Gura_ModuleTerminate()
{
}

Gura_EndModuleBody(basement, basement)

Gura_RegisterModule(basement)
