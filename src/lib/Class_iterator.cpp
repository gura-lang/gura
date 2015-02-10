//=============================================================================
// Gura class: iterator
//=============================================================================
#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Object_iterator
//-----------------------------------------------------------------------------
Object_iterator::Object_iterator(const Object_iterator &obj) :
							Object(obj), _pIterator(obj._pIterator->Clone())
{
}

Object_iterator::~Object_iterator()
{
	Iterator::Delete(_pIterator);
}

Object *Object_iterator::Clone() const
{
	return new Object_iterator(*this);
}

Iterator *Object_iterator::CreateIterator(Signal sig)
{
	return _pIterator->Clone();
}

String Object_iterator::ToString(bool exprFlag)
{
	String rtn;
	rtn += "<iterator:";
	rtn += _pIterator->ToString();
	if (_pIterator->IsRepeater()) rtn += ":repeater";
	rtn += ">";
	return rtn;
}

void Object_iterator::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
	if (_cntRef == 1) {
		_pIterator->GatherFollower(pFrame, envSet);
	}
}

//-----------------------------------------------------------------------------
// Implementation of functions
//-----------------------------------------------------------------------------
// iterator(value+) {block?}
Gura_DeclareFunction(iterator)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "value", VTYPE_any, OCCUR_OnceOrMore);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(env.LookupClass(VTYPE_iterator));
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(iterator)
{
	Iterator_Concat *pIterator = new Iterator_Concat();
	foreach_const (ValueList, pValue, args.GetList(0)) {
		Iterator *pIteratorArg = NULL;
		if (pValue->Is_iterator()) {
			pIteratorArg = pValue->CreateIterator(sig);
			if (sig.IsSignalled()) return Value::Null;
		} else {
			pIteratorArg = new Iterator_OneShot(*pValue);
		}
		pIterator->Add(pIteratorArg);
	}
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
		"");
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

// interval(a:number, b:number, samples:number):map:[open,open_l,open_r] {block?}
Gura_DeclareFunction(interval)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "a", VTYPE_number);
	DeclareArg(env, "b", VTYPE_number);
	DeclareArg(env, "samples", VTYPE_number);
	DeclareAttr(Gura_Symbol(open));
	DeclareAttr(Gura_Symbol(open_l));
	DeclareAttr(Gura_Symbol(open_r));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
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

// consts(value, num?:number) {block?}
Gura_DeclareFunction(consts)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "value", VTYPE_any);
	DeclareArg(env, "num", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
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

// rands(range?:number, num?:number) {block?}
Gura_DeclareFunction(rands)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "range", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "num", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Creates an iterator that returns random numbers between `0` and `range - 1`.\n"
		"If argument `range` is not specified, it generates random numbers in a range of [0, 1).\n"
		"\n"
		"In default, the created iterator infinitely generates random numbers.\n"
		"The argument `num` specifies how many numbers should be generated.\n");
}

Gura_ImplementFunction(rands)
{
	Iterator *pIterator = new Iterator_Rand(
				args.Is_number(0)? args.GetInt(0) : 0,
				args.Is_number(1)? args.GetInt(1) : -1);
	return ReturnIterator(env, sig, args, pIterator);
}

//-----------------------------------------------------------------------------
// Implementation of methods
//-----------------------------------------------------------------------------
// iterator#delay(delay:number) {block?}
Gura_DeclareMethod(iterator, delay)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "delay", VTYPE_number);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementMethod(iterator, delay)
{
	Object_iterator *pThis = Object_iterator::GetThisObj(args);
	Iterator *pIterator =
		new Iterator_Delay(pThis->GetIterator()->Clone(), args.GetNumber(0));
	return ReturnIterator(env, sig, args, pIterator);
}

// iterator#isinfinite()
Gura_DeclareMethod(iterator, isinfinite)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementMethod(iterator, isinfinite)
{
	Object_iterator *pThis = Object_iterator::GetThisObj(args);
	return Value(pThis->GetIterator()->IsInfinite());
}

// iterator#next()
Gura_DeclareMethod(iterator, next)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementMethod(iterator, next)
{
	Object_iterator *pThis = Object_iterator::GetThisObj(args);
	Value value;
	if (pThis->GetIterator()->Next(env, sig, value)) return value;
	return Value::Null;
}

// iterator#repeater()
Gura_DeclareMethod(iterator, repeater)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementMethod(iterator, repeater)
{
	Object_iterator *pThis = Object_iterator::GetThisObj(args);
	pThis->GetIterator()->SetRepeaterFlag(true);
	return args.GetThis();
}

// iterator#after(criteria) {block?}
Gura_DeclareMethod(iterator, after)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "criteria", VTYPE_any);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementMethod(iterator, after)
{
	Object_iterator *pThis = Object_iterator::GetThisObj(args);
	Iterator *pIteratorSrc = pThis->GetIterator()->Clone();
	Iterator *pIterator = pIteratorSrc->Since(env, sig, args.GetValue(0), false);
	if (sig.IsSignalled()) return Value::Null;
	return ReturnIterator(env, sig, args, pIterator);
}

// iterator#align(n:number, value?) {block?}
Gura_DeclareMethod(iterator, align)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "n", VTYPE_number);
	DeclareArg(env, "value", VTYPE_any, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementMethod(iterator, align)
{
	Object_iterator *pThis = Object_iterator::GetThisObj(args);
	Iterator *pIterator = new Iterator_Align(pThis->GetIterator()->Clone(),
			static_cast<int>(args.GetNumber(0)), args.GetValue(1));
	return ReturnIterator(env, sig, args, pIterator);
}

// iterator#and()
Gura_DeclareMethodAlias(iterator, and_, "and")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementMethod(iterator, and_)
{
	Object_iterator *pThis = Object_iterator::GetThisObj(args);
	AutoPtr<Iterator> pIterator(pThis->CreateIterator(sig));
	if (sig.IsSignalled()) return Value::Null;
	Value result = pIterator->And(env, sig);
	if (sig.IsSignalled()) return Value::Null;
	return result;
}

// iterator#average()
Gura_DeclareMethod(iterator, average)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns an average of values in the iterator.");
}

Gura_ImplementMethod(iterator, average)
{
	Object_iterator *pThis = Object_iterator::GetThisObj(args);
	AutoPtr<Iterator> pIterator(pThis->CreateIterator(sig));
	if (sig.IsSignalled()) return Value::Null;
	size_t cnt;
	Value result = pIterator->Average(env, sig, cnt);
	if (sig.IsSignalled()) return Value::Null;
	return result;
}

// iterator#before(criteria) {block?}
Gura_DeclareMethod(iterator, before)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "criteria", VTYPE_any);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementMethod(iterator, before)
{
	Object_iterator *pThis = Object_iterator::GetThisObj(args);
	Iterator *pIteratorSrc = pThis->GetIterator()->Clone();
	Iterator *pIterator = pIteratorSrc->Until(env, sig, args.GetValue(0), false);
	if (sig.IsSignalled()) return Value::Null;
	return ReturnIterator(env, sig, args, pIterator);
}

// iterator#contains(value)
Gura_DeclareMethod(iterator, contains)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "value", VTYPE_any);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown, 
		"Returns true if a specified value exists in the iterated elements.");
}

Gura_ImplementMethod(iterator, contains)
{
	Object_iterator *pThis = Object_iterator::GetThisObj(args);
	AutoPtr<Iterator> pIterator(pThis->CreateIterator(sig));
	if (sig.IsSignalled()) return Value::Null;
	bool result = pIterator->DoesContain(env, sig, args.GetValue(0));
	if (sig.IsSignalled()) return Value::Null;
	return Value(result);
}

// iterator#count(criteria?)
Gura_DeclareMethod(iterator, count)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "criteria", VTYPE_any, OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementMethod(iterator, count)
{
	Object_iterator *pThis = Object_iterator::GetThisObj(args);
	AutoPtr<Iterator> pIterator(pThis->GetIterator()->Clone());
	size_t cnt = args.IsValid(0)?
		pIterator->Count(env, sig, args.GetValue(0)) : pIterator->CountTrue(env, sig);
	if (sig.IsSignalled()) return Value::Null;
	return Value(static_cast<UInt>(cnt));
}

// iterator#cycle(n?:number) {block?}
Gura_DeclareMethod(iterator, cycle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "n", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementMethod(iterator, cycle)
{
	Object_iterator *pThis = Object_iterator::GetThisObj(args);
	int cnt = args.Is_number(0)? args.GetInt(0) : -1;
	AutoPtr<Iterator> pIterator(pThis->GetIterator()->Clone());
	Value value = pIterator->Eval(env, sig, args);
	if (sig.IsSignalled() || value.IsInvalid()) return Value::Null;
	GURA_ASSUME(env, value.Is_list());
	//Object_list *pObj = dynamic_cast<Object_list *>(value.GetListObj()->Clone());
	Object_list *pObj = Object_list::Reference(Object_list::GetObject(value));
	return ReturnIterator(env, sig, args,
							new Object_list::IteratorCycle(pObj, cnt));
}

// iterator#each() {block?}
Gura_DeclareMethod(iterator, each)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementMethod(iterator, each)
{
	Object_iterator *pThis = Object_iterator::GetThisObj(args);
	Iterator *pIterator = pThis->GetIterator()->Clone();
	return ReturnIterator(env, sig, args, pIterator);
}

// iterator#filter(criteria?) {block?}
Gura_DeclareMethod(iterator, filter)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "criteria", VTYPE_any, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementMethod(iterator, filter)
{
	Object_iterator *pThis = Object_iterator::GetThisObj(args);
	Iterator *pIteratorSrc = pThis->GetIterator()->Clone();
	Iterator *pIterator = NULL;
	if (args.IsValid(0)) {
		pIterator = pIteratorSrc->Filter(env, sig, args.GetValue(0));
		if (sig.IsSignalled()) return Value::Null;
	} else {
		pIterator = new Iterator_SkipFalse(pIteratorSrc);
	}
	return ReturnIterator(env, sig, args, pIterator);
}

// iterator#find(criteria?):[index]
Gura_DeclareMethod(iterator, find)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareAttr(Gura_Symbol(index));
	DeclareArg(env, "criteria", VTYPE_any, OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementMethod(iterator, find)
{
	Object_iterator *pThis = Object_iterator::GetThisObj(args);
	AutoPtr<Iterator> pIterator(pThis->GetIterator()->Clone());
	Value value;
	size_t idx = args.IsValid(0)?
			pIterator->Find(env, sig, args.GetValue(0), value) :
			pIterator->FindTrue(env, sig, value);
	if (idx == InvalidSize) return Value::Null;
	if (args.IsSet(Gura_Symbol(index))) return Value(static_cast<UInt>(idx));
	return value;
}

// iterator#flat():[dfs,bfs] {block?}
Gura_DeclareMethod(iterator, flat)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareAttr(Gura_Symbol(dfs));
	DeclareAttr(Gura_Symbol(bfs));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns an iterator that searches items recursively if they are lists or iterators.\n"
		"Searching is done in order of depth-first-search by default.\n"
		"Specifying attribute `:bfs` will process in breadth-first-search order.\n"
		"Unlike `iterator#walk`, this always returns an iterator without an infinite flag.\n");
}

Gura_ImplementMethod(iterator, flat)
{
	Object_iterator *pThis = Object_iterator::GetThisObj(args);
	Iterator_Walk::Mode mode = args.IsSet(Gura_Symbol(bfs))?
		Iterator_Walk::MODE_BreadthFirstSearch : Iterator_Walk::MODE_DepthFirstSearch;
	bool walkListFlag = true;
	bool walkIteratorFlag = true;
	Iterator *pIteratorSrc = pThis->GetIterator()->Clone();
	Iterator *pIterator = new Iterator_Walk(pIteratorSrc, mode, walkListFlag, walkIteratorFlag);
	pIterator->SetInfiniteFlag(false);
	return ReturnIterator(env, sig, args, pIterator);
}

// iterator#fold(n:number, nstep?:number):map:[iteritem,neat] {block?}
Gura_DeclareMethod(iterator, fold)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number);
	DeclareArg(env, "nstep", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareAttr(Gura_Symbol(iteritem));
	DeclareAttr(Gura_Symbol(neat));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementMethod(iterator, fold)
{
	Object_iterator *pThis = Object_iterator::GetThisObj(args);
	size_t cnt = args.GetSizeT(0);
	size_t cntStep = args.Is_number(1)? args.GetSizeT(1) : cnt;
	bool listItemFlag = !args.IsSet(Gura_Symbol(iteritem));
	bool neatFlag = args.IsSet(Gura_Symbol(neat));
	Iterator *pIterator = new Iterator_Fold(pThis->GetIterator()->Clone(),
											cnt, cntStep, listItemFlag, neatFlag);
	return ReturnIterator(env, sig, args, pIterator);
}

// iterator#format(format:string):map {block?}
Gura_DeclareMethod(iterator, format)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "format", VTYPE_string);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementMethod(iterator, format)
{
	Object_iterator *pThis = Object_iterator::GetThisObj(args);
	Iterator *pIterator =
		new Iterator_Format(pThis->GetIterator()->Clone(), args.GetString(0));
	return ReturnIterator(env, sig, args, pIterator);
}

// iterator#head(n:number):map {block?}
Gura_DeclareMethod(iterator, head)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementMethod(iterator, head)
{
	Object_iterator *pThis = Object_iterator::GetThisObj(args);
	Iterator *pIterator = new Iterator_Head(pThis->GetIterator()->Clone(),
									static_cast<int>(args.GetNumber(0)));
	return ReturnIterator(env, sig, args, pIterator);
}

// iterator#join(sep?:string):map
Gura_DeclareMethod(iterator, join)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "sep", VTYPE_string, OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementMethod(iterator, join)
{
	Object_iterator *pThis = Object_iterator::GetThisObj(args);
	if (pThis->GetIterator()->IsInfinite()) {
		Iterator::SetError_InfiniteNotAllowed(sig);
		return Value::Null;
	}
	const char *sep = args.Is_string(0)? args.GetString(0) : "";
	AutoPtr<Iterator> pIterator(pThis->GetIterator()->Clone());
	String rtn;
	Value value;
	if (pIterator->Next(env, sig, value)) {
		rtn += value.ToString(false);
		if (sig.IsSignalled()) {
			return Value::Null;
		}
		while (pIterator->Next(env, sig, value)) {
			rtn += sep;
			rtn += value.ToString(false);
			if (sig.IsSignalled()) {
				return Value::Null;
			}
		}
	}
	if (sig.IsSignalled()) return Value::Null;
	return Value(rtn);
}

// iterator#joinb()
Gura_DeclareMethod(iterator, joinb)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementMethod(iterator, joinb)
{
	Object_iterator *pThis = Object_iterator::GetThisObj(args);
	if (pThis->GetIterator()->IsInfinite()) {
		Iterator::SetError_InfiniteNotAllowed(sig);
		return Value::Null;
	}
	const char *sep = args.Is_string(0)? args.GetString(0) : "";
	AutoPtr<Iterator> pIterator(pThis->GetIterator()->Clone());
	Binary buff;
	Value value;
	while (pIterator->Next(env, sig, value)) {
		if (!value.Is_binary()) {
			sig.SetError(ERR_ValueError, "invalid value type");
			return Value::Null;
		}
		buff += value.GetBinary();
	}
	if (sig.IsSignalled()) return Value::Null;
	return Value(new Object_binary(env, buff, true));
}

// iterator#len()
Gura_DeclareMethod(iterator, len)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns the length of the iterator.");
}

Gura_ImplementMethod(iterator, len)
{
	Object_iterator *pThis = Object_iterator::GetThisObj(args);
	if (pThis->GetIterator()->IsInfinite()) {
		Iterator::SetError_InfiniteNotAllowed(sig);
		return Value::Null;
	}
	Value value;
	int cnt;
	AutoPtr<Iterator> pIterator(pThis->GetIterator()->Clone());
	for (cnt = 0; pIterator->Next(env, sig, value); cnt++) ;
	if (sig.IsSignalled()) return Value::Null;
	return Value(static_cast<Number>(cnt));
}

// iterator#map(func:function) {block?}
Gura_DeclareMethod(iterator, map)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "func", VTYPE_function);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementMethod(iterator, map)
{
	Object_iterator *pThis = Object_iterator::GetThisObj(args);
	Iterator *pIterator = new Iterator_ExplicitMap(new Environment(env), sig,
			pThis->GetIterator()->Clone(),
			Object_function::Reference(Object_function::GetObject(args, 0)));
	return ReturnIterator(env, sig, args, pIterator);
}

// iterator#max():[index,last_index,indices]
Gura_DeclareMethod(iterator, max)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareAttr(Gura_Symbol(index));
	DeclareAttr(Gura_Symbol(last_index));
	DeclareAttr(Gura_Symbol(indices));
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown, 
		"Returns the maximum value in the iterator.\n"
		"\n"
		"It would return a position index where the maximum value is found\n"
		"when one of the following attribute is specified:\n"
		"\n"
		"- `:index` .. an index of the maximum value.\n"
		"- `:indices` .. a list of indices where the maximum value is found.\n"
		"- `:last_index` .. the last index of the maximum value\n"
		"                   when the value exists at multiple positions.\n");
}

Gura_ImplementMethod(iterator, max)
{
	Object_iterator *pThis = Object_iterator::GetThisObj(args);
	AutoPtr<Iterator> pIterator(pThis->GetIterator()->Clone());
	Value result = pIterator->MinMax(env, sig, true, args.GetAttrs());
	if (sig.IsSignalled()) return Value::Null;
	return result;
}

// iterator#min():[index,last_index,indices]
Gura_DeclareMethod(iterator, min)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareAttr(Gura_Symbol(index));
	DeclareAttr(Gura_Symbol(last_index));
	DeclareAttr(Gura_Symbol(indices));
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown, 
		"Returns the minimum value in the iterator.\n"
		"\n"
		"It would return a position index where the minimum value is found\n"
		"when one of the following attribute is specified:\n"
		"\n"
		"- `:index` .. an index of the minimum value.\n"
		"- `:indices` .. a list of indices where the minimum value is found.\n"
		"- `:last_index` .. the last index of the minimum value\n"
		"                   when the value exists at multiple positions.\n");
}

Gura_ImplementMethod(iterator, min)
{
	Object_iterator *pThis = Object_iterator::GetThisObj(args);
	AutoPtr<Iterator> pIterator(pThis->GetIterator()->Clone());
	Value result = pIterator->MinMax(env, sig, false, args.GetAttrs());
	if (sig.IsSignalled()) return Value::Null;
	return result;
}

// iterator#nilto(replace) {block?}
Gura_DeclareMethod(iterator, nilto)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "replace", VTYPE_any);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementMethod(iterator, nilto)
{
	Object_iterator *pThis = Object_iterator::GetThisObj(args);
	Iterator *pIterator = new Iterator_ReplaceInvalid(pThis->GetIterator()->Clone(),
															args.GetValue(0));
	return ReturnIterator(env, sig, args, pIterator);
}

// iterator#offset(n:number) {block?}
Gura_DeclareMethod(iterator, offset)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "n", VTYPE_number);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementMethod(iterator, offset)
{
	Object_iterator *pThis = Object_iterator::GetThisObj(args);
	Iterator *pIterator = pThis->GetIterator()->Clone();
	for (int cnt = static_cast<int>(args.GetNumber(0)); cnt > 0; cnt--) {
		Value value;
		pIterator->Next(env, sig, value);
	}
	return ReturnIterator(env, sig, args, pIterator);
}

// iterator#or()
Gura_DeclareMethodAlias(iterator, or_, "or")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementMethod(iterator, or_)
{
	Object_iterator *pThis = Object_iterator::GetThisObj(args);
	AutoPtr<Iterator> pIterator(pThis->CreateIterator(sig));
	if (sig.IsSignalled()) return Value::Null;
	Value result = pIterator->Or(env, sig);
	if (sig.IsSignalled()) return Value::Null;
	return result;
}

// iterator#pack(format:string) {block?}
Gura_DeclareMethod(iterator, pack)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "format", VTYPE_string);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementMethod(iterator, pack)
{
	Object_iterator *pThis = Object_iterator::GetThisObj(args);
	Iterator *pIterator =
		new Iterator_Pack(pThis->GetIterator()->Clone(), args.GetString(0));
	return ReturnIterator(env, sig, args, pIterator);
}

// iterator#pingpong(n?:number):[sticky,sticky_l,sticky_r] {block?}
Gura_DeclareMethod(iterator, pingpong)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "n", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareAttr(Gura_Symbol(sticky));
	DeclareAttr(Gura_Symbol(sticky_l));
	DeclareAttr(Gura_Symbol(sticky_r));
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementMethod(iterator, pingpong)
{
	Object_iterator *pThis = Object_iterator::GetThisObj(args);
	int cnt = args.Is_number(0)? args.GetInt(0) : -1;
	bool stickyFlagL = args.IsSet(Gura_Symbol(sticky)) ||
						args.IsSet(Gura_Symbol(sticky_l));
	bool stickyFlagR = args.IsSet(Gura_Symbol(sticky)) ||
						args.IsSet(Gura_Symbol(sticky_r));
	AutoPtr<Iterator> pIterator(pThis->GetIterator()->Clone());
	Value value = pIterator->Eval(env, sig, args);
	if (sig.IsSignalled() || value.IsInvalid()) return Value::Null;
	GURA_ASSUME(env, value.Is_list());
	//Object_list *pObj = dynamic_cast<Object_list *>(value.GetListObj()->Clone());
	Object_list *pObj = Object_list::Reference(Object_list::GetObject(value));
	return ReturnIterator(env, sig, args,
			new Object_list::IteratorPingpong(pObj, cnt, stickyFlagL, stickyFlagR));
}

// iterator#print(stream?:stream:w):void
Gura_DeclareMethod(iterator, print)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_ZeroOrOnce, FLAG_Write);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementMethod(iterator, print)
{
	Iterator *pIterator = Object_iterator::GetThisObj(args)->GetIterator()->Clone();
	Stream *pStream = args.IsValid(0)? &args.GetStream(0) : env.GetConsole();
	pIterator->PrintEach(env, sig, pStream);
	return Value::Null;
}

// iterator#printf(format:string, stream?:stream:w):void
Gura_DeclareMethod(iterator, printf)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "format", VTYPE_string);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_ZeroOrOnce, FLAG_Write);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementMethod(iterator, printf)
{
	Iterator *pIterator = Object_iterator::GetThisObj(args)->GetIterator()->Clone();
	const char *format = args.GetString(0);
	Stream *pStream = args.IsValid(1)? &args.GetStream(1) : env.GetConsole();
	pIterator->PrintfEach(env, sig, pStream, format);
	return Value::Null;
}

// iterator#println(stream?:stream:w):void
Gura_DeclareMethod(iterator, println)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_ZeroOrOnce, FLAG_Write);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementMethod(iterator, println)
{
	Iterator *pIterator = Object_iterator::GetThisObj(args)->GetIterator()->Clone();
	Stream *pStream = args.IsValid(0)? &args.GetStream(0) : env.GetConsole();
	pIterator->PrintlnEach(env, sig, pStream);
	return Value::Null;
}

// iterator#rank(directive?):[stable] {block?}
Gura_DeclareMethod(iterator, rank)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "directive", VTYPE_any, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementMethod(iterator, rank)
{
	Object_iterator *pThis = Object_iterator::GetThisObj(args);
	AutoPtr<Iterator> pIteratorSrc(pThis->GetIterator()->Clone());
	Value value = pIteratorSrc->Eval(env, sig, args);
	if (sig.IsSignalled() || value.IsInvalid()) return Value::Null;
	GURA_ASSUME(env, value.Is_list());
	Object_list *pObj = Object_list::GetObject(value)->SortRank(sig, args.GetValue(0), NULL,
							true, args.IsSet(Gura_Symbol(stable)));
	if (sig.IsSignalled()) return Value::Null;
	Iterator *pIterator = new Object_list::IteratorEach(pObj);
	return ReturnIterator(env, sig, args, pIterator);
}

// iterator#reduce(accum) {block}
Gura_DeclareMethod(iterator, reduce)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "accum", VTYPE_any);
	DeclareBlock(OCCUR_Once);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementMethod(iterator, reduce)
{
	Object_iterator *pThis = Object_iterator::GetThisObj(args);
	AutoPtr<Iterator> pIterator(pThis->GetIterator()->Clone());
	AutoPtr<Environment> pEnvBlock(new Environment(&env, ENVTYPE_block));
	const Function *pFuncBlock =
						args.GetBlockFunc(*pEnvBlock, sig, GetSymbolForBlock());
	if (pFuncBlock == NULL) {
		return Value::Null;
	}
	Value result = pIterator->Reduce(env, sig, args.GetValue(0), pFuncBlock);
	if (sig.IsSignalled()) return Value::Null;
	return result;
}

// iterator#replace(value, replace) {block?}
Gura_DeclareMethod(iterator, replace)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "value", VTYPE_any);
	DeclareArg(env, "replace", VTYPE_any);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementMethod(iterator, replace)
{
	Object_iterator *pThis = Object_iterator::GetThisObj(args);
	Iterator *pIterator = new Iterator_Replace(pThis->GetIterator()->Clone(),
									args.GetValue(0), args.GetValue(1));
	return ReturnIterator(env, sig, args, pIterator);
}

// iterator#reverse() {block?}
Gura_DeclareMethod(iterator, reverse)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementMethod(iterator, reverse)
{
	Object_iterator *pThis = Object_iterator::GetThisObj(args);
	AutoPtr<Iterator> pIterator(pThis->GetIterator()->Clone());
	Value value = pIterator->Eval(env, sig, args);
	if (sig.IsSignalled() || value.IsInvalid()) return Value::Null;
	GURA_ASSUME(env, value.Is_list());
	Object_list *pObj = Object_list::Reference(Object_list::GetObject(value));
	return ReturnIterator(env, sig, args,
							new Object_list::IteratorReverse(pObj));
}

// iterator#roundoff(threshold:number => 1e-10) {block?}
Gura_DeclareMethod(iterator, roundoff)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "threshold", VTYPE_number, OCCUR_Once, FLAG_None,
											new Expr_Value(RoundOffThreshold));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementMethod(iterator, roundoff)
{
	Object_iterator *pThis = Object_iterator::GetThisObj(args);
	Iterator *pIterator = new Iterator_RoundOff(
						pThis->GetIterator()->Clone(), args.GetNumber(0));
	return ReturnIterator(env, sig, args, pIterator);
}

// iterator#runlength() {block?}
Gura_DeclareMethod(iterator, runlength)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementMethod(iterator, runlength)
{
	Object_iterator *pThis = Object_iterator::GetThisObj(args);
	Iterator *pIterator = new Iterator_RunLength(pThis->GetIterator()->Clone());
	return ReturnIterator(env, sig, args, pIterator);
}

// iterator#since(criteria) {block?}
Gura_DeclareMethod(iterator, since)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "criteria", VTYPE_any);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementMethod(iterator, since)
{
	Object_iterator *pThis = Object_iterator::GetThisObj(args);
	Iterator *pIteratorSrc = pThis->GetIterator()->Clone();
	Iterator *pIterator = pIteratorSrc->Since(env, sig, args.GetValue(0), true);
	if (sig.IsSignalled()) return Value::Null;
	return ReturnIterator(env, sig, args, pIterator);
}

// iterator#skip(n:number) {block?}
Gura_DeclareMethod(iterator, skip)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "n", VTYPE_number);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementMethod(iterator, skip)
{
	Object_iterator *pThis = Object_iterator::GetThisObj(args);
	Iterator *pIterator =
		new Iterator_Skip(pThis->GetIterator()->Clone(), static_cast<int>(args.GetNumber(0)));
	return ReturnIterator(env, sig, args, pIterator);
}

// iterator#skipnil() {block?}
Gura_DeclareMethod(iterator, skipnil)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementMethod(iterator, skipnil)
{
	Object_iterator *pThis = Object_iterator::GetThisObj(args);
	Iterator *pIterator = new Iterator_SkipInvalid(pThis->GetIterator()->Clone());
	return ReturnIterator(env, sig, args, pIterator);
}

// iterator#sort(directive?, keys[]?):[stable] {block?}
Gura_DeclareMethod(iterator, sort)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "directive", VTYPE_any, OCCUR_ZeroOrOnce);
	DeclareArg(env, "keys", VTYPE_any, OCCUR_ZeroOrOnce, FLAG_List);
	DeclareAttr(Gura_Symbol(stable));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementMethod(iterator, sort)
{
	Object_iterator *pThis = Object_iterator::GetThisObj(args);
	AutoPtr<Iterator> pIteratorSrc(pThis->GetIterator()->Clone());
	Value value = pIteratorSrc->Eval(env, sig, args);
	if (sig.IsSignalled()) return Value::Null;
	if (value.IsInvalid()) return args.GetThis();
	GURA_ASSUME(env, value.Is_list());
	Object_list *pObj = Object_list::GetObject(value)->SortRank(sig, args.GetValue(0),
						args.Is_list(1)? &args.GetList(1) : NULL,
						false, args.IsSet(Gura_Symbol(stable)));
	if (sig.IsSignalled()) return Value::Null;
	Iterator *pIterator = new Object_list::IteratorEach(pObj);
	return ReturnIterator(env, sig, args, pIterator);
}

// iterator#stddev()
Gura_DeclareMethod(iterator, stddev)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns a standard deviation of values in the iterator.");
}

Gura_ImplementMethod(iterator, stddev)
{
	Object_iterator *pThis = Object_iterator::GetThisObj(args);
	AutoPtr<Iterator> pIterator(pThis->CreateIterator(sig));
	if (sig.IsSignalled()) return Value::Null;
	size_t cnt;
	Value result = pIterator->StandardDeviation(env, sig, cnt);
	if (sig.IsSignalled()) return Value::Null;
	return result;
}

// iterator#sum()
Gura_DeclareMethod(iterator, sum)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns a sum of values in the iterator.");
}

Gura_ImplementMethod(iterator, sum)
{
	Object_iterator *pThis = Object_iterator::GetThisObj(args);
	AutoPtr<Iterator> pIterator(pThis->CreateIterator(sig));
	if (sig.IsSignalled()) return Value::Null;
	size_t cnt;
	Value result = pIterator->Sum(env, sig, cnt);
	if (sig.IsSignalled()) return Value::Null;
	return result;
}

// iterator#tail(n:number) {block?}
Gura_DeclareMethod(iterator, tail)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "n", VTYPE_number);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementMethod(iterator, tail)
{
	Object_iterator *pThis = Object_iterator::GetThisObj(args);
	AutoPtr<Iterator> pIteratorSrc(pThis->GetIterator()->Clone());
	Value value = pIteratorSrc->Eval(env, sig, args);
	if (sig.IsSignalled() || value.IsInvalid()) return Value::Null;
	GURA_ASSUME(env, value.Is_list());
	//Object_list *pObj = dynamic_cast<Object_list *>(value.GetListObj()->Clone());
	Object_list *pObj = Object_list::Reference(Object_list::GetObject(value));
	int cnt = args.GetInt(0);
	int cntMax = static_cast<int>(pObj->GetList().size());
	size_t offset = (cntMax > cnt)? cntMax - cnt : cntMax;
	Iterator *pIterator = new Object_list::IteratorEach(pObj, offset);
	return ReturnIterator(env, sig, args, pIterator);
}

// iterator#until(criteria) {block?}
Gura_DeclareMethod(iterator, until)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "criteria", VTYPE_any);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementMethod(iterator, until)
{
	Object_iterator *pThis = Object_iterator::GetThisObj(args);
	Iterator *pIteratorSrc = pThis->GetIterator()->Clone();
	Iterator *pIterator = pIteratorSrc->Until(env, sig, args.GetValue(0), true);
	if (sig.IsSignalled()) return Value::Null;
	return ReturnIterator(env, sig, args, pIterator);
}

// iterator#variance()
Gura_DeclareMethod(iterator, variance)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns a variance of values in the iterator.");
}

Gura_ImplementMethod(iterator, variance)
{
	Object_iterator *pThis = Object_iterator::GetThisObj(args);
	AutoPtr<Iterator> pIterator(pThis->CreateIterator(sig));
	if (sig.IsSignalled()) return Value::Null;
	size_t cnt;
	Value result = pIterator->Variance(env, sig, cnt);
	if (sig.IsSignalled()) return Value::Null;
	return result;
}

// iterator#walk():[dfs,bfs] {block?}
Gura_DeclareMethod(iterator, walk)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareAttr(Gura_Symbol(dfs));
	DeclareAttr(Gura_Symbol(bfs));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns an iterator that searches items recursively if they are lists or iterators.\n"
		"Searching is done in order of depth-first-search by default.\n"
		"Specifying attribute `:bfs` will process in breadth-first-search order.");
}

Gura_ImplementMethod(iterator, walk)
{
	Object_iterator *pThis = Object_iterator::GetThisObj(args);
	Iterator_Walk::Mode mode = args.IsSet(Gura_Symbol(bfs))?
		Iterator_Walk::MODE_BreadthFirstSearch : Iterator_Walk::MODE_DepthFirstSearch;
	bool walkListFlag = true;
	bool walkIteratorFlag = true;
	Iterator *pIteratorSrc = pThis->GetIterator()->Clone();
	Iterator *pIterator = new Iterator_Walk(pIteratorSrc, mode, walkListFlag, walkIteratorFlag);
	return ReturnIterator(env, sig, args, pIterator);
}

// iterator#while(criteria) {block?}
Gura_DeclareMethodAlias(iterator, while_, "while")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "criteria", VTYPE_any);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementMethod(iterator, while_)
{
	Object_iterator *pThis = Object_iterator::GetThisObj(args);
	Iterator *pIteratorSrc = pThis->GetIterator()->Clone();
	Iterator *pIterator = pIteratorSrc->While(env, sig, args.GetValue(0));
	if (sig.IsSignalled()) return Value::Null;
	return ReturnIterator(env, sig, args, pIterator);
}

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_iterator::Class_iterator(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_iterator)
{
}

void Class_iterator::Prepare(Environment &env)
{
	Gura_AssignFunction(iterator);
	Gura_AssignFunction(range);
	Gura_AssignFunction(interval);
	Gura_AssignFunction(consts);
	Gura_AssignFunction(rands);
	// assignment of methods specific to iterator
	Gura_AssignMethod(iterator, delay);
	Gura_AssignMethod(iterator, isinfinite);
	Gura_AssignMethod(iterator, next);
	Gura_AssignMethod(iterator, repeater);
	// assignment of common methods with list
	Gura_AssignMethod(iterator, after);
	Gura_AssignMethod(iterator, align);
	Gura_AssignMethod(iterator, and_);
	Gura_AssignMethod(iterator, average);
	Gura_AssignMethod(iterator, before);
	Gura_AssignMethod(iterator, contains);
	Gura_AssignMethod(iterator, count);
	Gura_AssignMethod(iterator, cycle);
	Gura_AssignMethod(iterator, each);
	Gura_AssignMethod(iterator, filter);
	Gura_AssignMethod(iterator, find);
	Gura_AssignMethod(iterator, flat);
	Gura_AssignMethod(iterator, fold);
	Gura_AssignMethod(iterator, format);
	Gura_AssignMethod(iterator, head);
	Gura_AssignMethod(iterator, join);
	Gura_AssignMethod(iterator, joinb);
	Gura_AssignMethod(iterator, len);
	Gura_AssignMethod(iterator, map);
	Gura_AssignMethod(iterator, max);
	Gura_AssignMethod(iterator, min);
	Gura_AssignMethod(iterator, nilto);
	Gura_AssignMethod(iterator, offset);
	Gura_AssignMethod(iterator, or_);
	Gura_AssignMethod(iterator, pack);
	Gura_AssignMethod(iterator, pingpong);
	Gura_AssignMethod(iterator, print);
	Gura_AssignMethod(iterator, println);
	Gura_AssignMethod(iterator, printf);
	Gura_AssignMethod(iterator, rank);
	Gura_AssignMethod(iterator, reduce);
	Gura_AssignMethod(iterator, replace);
	Gura_AssignMethod(iterator, reverse);
	Gura_AssignMethod(iterator, roundoff);
	Gura_AssignMethod(iterator, runlength);
	Gura_AssignMethod(iterator, since);
	Gura_AssignMethod(iterator, skip);
	Gura_AssignMethod(iterator, skipnil);
	Gura_AssignMethod(iterator, sort);
	Gura_AssignMethod(iterator, stddev);
	Gura_AssignMethod(iterator, sum);
	Gura_AssignMethod(iterator, tail);
	Gura_AssignMethod(iterator, until);
	Gura_AssignMethod(iterator, variance);
	Gura_AssignMethod(iterator, walk);
	Gura_AssignMethod(iterator, while_);
}

bool Class_iterator::CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl)
{
	Iterator *pIterator = value.CreateIterator(sig);
	if (pIterator != NULL) {
		value = Value(new Object_iterator(env, pIterator));
		return true;
	}
	return false;
}

Object *Class_iterator::CreateDescendant(Environment &env, Signal sig, Class *pClass)
{
	GURA_ERROREND(env, "this function must not be called");
	return NULL;
}

}
