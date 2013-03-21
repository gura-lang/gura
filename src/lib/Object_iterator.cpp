//
// Object_iterator
//

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

String Object_iterator::ToString(Signal sig, bool exprFlag)
{
	return _pIterator->ToString(sig);
}

void Object_iterator::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
	if (_cntRef == 1) {
		_pIterator->GatherFollower(pFrame, envSet);
	}
}

//-----------------------------------------------------------------------------
// Global functions
//-----------------------------------------------------------------------------
// iterator(value+) {block?}
Gura_DeclareFunction(iterator)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "value", VTYPE_any, OCCUR_OnceOrMore);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(env.LookupClass(VTYPE_iterator));
}

Gura_ImplementFunction(iterator)
{
	Iterator_Concat *pIterator = new Iterator_Concat();
	foreach_const (ValueList, pValue, args.GetList(0)) {
		Iterator *pIteratorArg = NULL;
		if (pValue->IsList() || pValue->IsIterator()) {
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
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "num",		VTYPE_number);
	DeclareArg(env, "num_end",	VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "step",		VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(range)
{
	Number numBegin = 0.;
	Number numEnd = 0.;
	Number numStep = 1.;
	if (args.GetValue(1).IsInvalid()) {
		numEnd = args.GetValue(0).GetNumber();
		if (numBegin > numEnd) numStep = -1.;
	} else if (args.GetValue(2).IsInvalid()) {
		numBegin = args.GetValue(0).GetNumber();
		numEnd = args.GetValue(1).GetNumber();
		if (numBegin > numEnd) numStep = -1.;
	} else {
		numBegin = args.GetValue(0).GetNumber();
		numEnd = args.GetValue(1).GetNumber();
		numStep = args.GetValue(2).GetNumber();
		if (numStep == 0.) {
			sig.SetError(ERR_ValueError, "step cannot be specified as zero");
			return Value::Null;
		}
	}
	return ReturnIterator(env, sig, args,
						new Iterator_Range(numBegin, numEnd, numStep));
}

// interval(a:number, b:number, samples:number):map:[open,open_l,open_r] {block?}
Gura_DeclareFunction(interval)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "a", VTYPE_number);
	DeclareArg(env, "b", VTYPE_number);
	DeclareArg(env, "samples", VTYPE_number);
	DeclareAttr(Gura_Symbol(open));
	DeclareAttr(Gura_Symbol(open_l));
	DeclareAttr(Gura_Symbol(open_r));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(interval)
{
	const ValueList &valListArg = args.GetArgs();
	Number numBegin = valListArg[0].GetNumber();
	Number numEnd = valListArg[1].GetNumber();
	int numSamples = valListArg[2].GetInt();
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

// fill(n:number, value?) {block?}
Gura_DeclareFunction(fill)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "n", VTYPE_number);
	DeclareArg(env, "value", VTYPE_any, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(fill)
{
	Iterator *pIterator = new Iterator_Fill(args.GetInt(0), args.GetValue(1));
	return ReturnIterator(env, sig, args, pIterator);
}

// zipv(values+) {block?}
Gura_DeclareFunction(zipv)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "values", VTYPE_any, OCCUR_OnceOrMore);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), 
	"Creates an iterator generating lists that bind given argument values.\n"
	"When the value is a list or an iterator, each item in it would be zipped.\n"
	ITERATOR_HELP);
}

Gura_ImplementFunction(zipv)
{
	IteratorOwner iterOwner;
	bool iteratorFlag = false;
	foreach_const (ValueList, pValue, args.GetList(0)) {
		if (pValue->IsList() || pValue->IsIterator()) {
			iteratorFlag = true;
			break;
		}
	}
	if (!iteratorFlag) {
		Value result;
		ValueList &valList = result.InitAsList(env);
		foreach_const (ValueList, pValue, args.GetList(0)) {
			valList.push_back(*pValue);
		}
		return result;
	}
	foreach_const (ValueList, pValue, args.GetList(0)) {
		Iterator *pIteratorArg = NULL;
		if (pValue->IsList() || pValue->IsIterator()) {
			pIteratorArg = pValue->CreateIterator(sig);
			if (sig.IsSignalled()) return Value::Null;
		} else {
			pIteratorArg = new Iterator_Constant(*pValue);
		}
		iterOwner.push_back(pIteratorArg);
	}
	Iterator *pIterator = new Iterator_Zipv(iterOwner);
	return ReturnIterator(env, sig, args, pIterator);
}

// rands(num?:number, range?:number) {block?}
Gura_DeclareFunction(rands)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "num", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "range", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(rands)
{
	Iterator *pIterator = new Iterator_Rand(
				args.IsNumber(0)? args.GetInt(0) : -1,
				args.IsNumber(1)? args.GetInt(1) : 0);
	return ReturnIterator(env, sig, args, pIterator);
}

//-----------------------------------------------------------------------------
// Gura interfaces for Object_iterator
//-----------------------------------------------------------------------------
// iterator#print(stream?:stream:w)
Gura_DeclareMethod(iterator, print)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_ZeroOrOnce, FLAG_Write);
}

Gura_ImplementMethod(iterator, print)
{
	Object_iterator *pThis = Object_iterator::GetThisObj(args);
	Stream *pConsole = args.IsInstanceOf(0, VTYPE_stream)?
				&args.GetStream(0) : env.GetConsole();
	if (pConsole == NULL) return Value::Null;
	Iterator *pIterator = pThis->GetIterator()->Clone();
	Value value;
	while (pIterator->Next(env, sig, value)) {
		String str(value.ToString(sig, false));
		if (sig.IsSignalled()) return Value::Null;
		pConsole->Print(sig, str.c_str());
		if (sig.IsSignalled()) return Value::Null;
	}
	return Value::Null;
}

// iterator#println(stream?:stream:w)
Gura_DeclareMethod(iterator, println)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_ZeroOrOnce, FLAG_Write);
}

Gura_ImplementMethod(iterator, println)
{
	Object_iterator *pThis = Object_iterator::GetThisObj(args);
	Stream *pConsole = args.IsInstanceOf(0, VTYPE_stream)?
				&args.GetStream(0) : env.GetConsole();
	if (pConsole == NULL) return Value::Null;
	Iterator *pIterator = pThis->GetIterator()->Clone();
	Value value;
	while (pIterator->Next(env, sig, value)) {
		String str(value.ToString(sig, false));
		if (sig.IsSignalled()) return Value::Null;
		pConsole->Println(sig, str.c_str());
		if (sig.IsSignalled()) return Value::Null;
	}
	return Value::Null;
}

// iterator#printf(format:string, stream?:stream:w)
Gura_DeclareMethod(iterator, printf)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "format", VTYPE_string);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_ZeroOrOnce, FLAG_Write);
}

Gura_ImplementMethod(iterator, printf)
{
	Object_iterator *pThis = Object_iterator::GetThisObj(args);
	const char *format = args.GetString(0);
	Stream *pConsole = args.IsInstanceOf(1, VTYPE_stream)?
				&args.GetStream(1) : env.GetConsole();
	if (pConsole == NULL) return Value::Null;
	Iterator *pIterator = pThis->GetIterator()->Clone();
	Value value;
	while (pIterator->Next(env, sig, value)) {
		if (value.IsList()) {
			pConsole->Printf(sig, format, value.GetList());
		} else {
			pConsole->Printf(sig, format, ValueList(value));
		}
		if (sig.IsSignalled()) return Value::Null;
	}
	return Value::Null;
}

// iterator#delay(delay:number) {block?}
Gura_DeclareMethod(iterator, delay)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "delay", VTYPE_number);
	DeclareBlock(OCCUR_ZeroOrOnce);
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
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(iterator, isinfinite)
{
	Object_iterator *pThis = Object_iterator::GetThisObj(args);
	return Value(pThis->GetIterator()->IsInfinite());
}

// iterator#next()
Gura_DeclareMethod(iterator, next)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(iterator, next)
{
	Object_iterator *pThis = Object_iterator::GetThisObj(args);
	Value value;
	if (pThis->GetIterator()->Next(env, sig, value)) return value;
	return Value::Null;
}

// iterator#len()
Gura_DeclareMethod(iterator, len)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), "Returns the length of the iterator.");
}

Gura_ImplementMethod(iterator, len)
{
	Object_iterator *pThis = Object_iterator::GetThisObj(args);
	Value value;
	int cnt;
	AutoPtr<Iterator> pIterator(pThis->GetIterator()->Clone());
	for (cnt = 0; pIterator->Next(env, sig, value); cnt++) ;
	if (sig.IsSignalled()) return Value::Null;
	return Value(static_cast<Number>(cnt));
}

// iterator#min():[index,last_index,indices]
Gura_DeclareMethod(iterator, min)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareAttr(Gura_Symbol(index));
	DeclareAttr(Gura_Symbol(last_index));
	DeclareAttr(Gura_Symbol(indices));
	AddHelp(Gura_Symbol(en), 
	"Returns the minimum value in the iterator when no attribute is specified.\n"
	"With an attribute :index, it returns an index of the minimum value.\n"
	"With an attribute :last_index, it returns the last index of the minimum value\n"
	"when more than one elements have the same value.\n"
	"With an attribute :indices, it returns a list of indices of elements that\n"
	"has the minimum value.");
}

Gura_ImplementMethod(iterator, min)
{
	Object_iterator *pThis = Object_iterator::GetThisObj(args);
	AutoPtr<Iterator> pIterator(pThis->GetIterator()->Clone());
	Value result = pIterator->MinMax(env, sig, false, args.GetAttrs());
	if (sig.IsSignalled()) return Value::Null;
	return result;
}

// iterator#max():[index,last_index,indices]
Gura_DeclareMethod(iterator, max)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareAttr(Gura_Symbol(index));
	DeclareAttr(Gura_Symbol(last_index));
	DeclareAttr(Gura_Symbol(indices));
	AddHelp(Gura_Symbol(en), 
	"Returns the maximum value in the iterator when no attribute is specified.\n"
	"With an attribute :index, it returns an index of the maximum value.\n"
	"With an attribute :last_index, it returns the last index of the maximum value\n"
	"when more than one elements have the same value.\n"
	"With an attribute :indices, it returns a list of indices of elements that\n"
	"has the maximum value.");
}

Gura_ImplementMethod(iterator, max)
{
	Object_iterator *pThis = Object_iterator::GetThisObj(args);
	AutoPtr<Iterator> pIterator(pThis->GetIterator()->Clone());
	Value result = pIterator->MinMax(env, sig, true, args.GetAttrs());
	if (sig.IsSignalled()) return Value::Null;
	return result;
}

// iterator#sum()
Gura_DeclareMethod(iterator, sum)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), "Returns a sum of values in the iterator.");
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

// iterator#average()
Gura_DeclareMethod(iterator, average)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), "Returns an average of values in the iterator.");
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

// iterator#variance()
Gura_DeclareMethod(iterator, variance)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), "Returns a variance of values in the iterator.");
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

// iterator#stddev()
Gura_DeclareMethod(iterator, stddev)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), "Returns a standard deviation of values in the iterator.");
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

// iterator#and()
Gura_DeclareMethodAlias(iterator, and_, "and")
{
	SetMode(RSLTMODE_Normal, FLAG_None);
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

// iterator#or()
Gura_DeclareMethodAlias(iterator, or_, "or")
{
	SetMode(RSLTMODE_Normal, FLAG_None);
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

// iterator#iscontain(value)
Gura_DeclareMethod(iterator, iscontain)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "value", VTYPE_any);
	AddHelp(Gura_Symbol(en), 
	"Returns true if a specified value exists in the iterated elements.");
}

Gura_ImplementMethod(iterator, iscontain)
{
	Object_iterator *pThis = Object_iterator::GetThisObj(args);
	AutoPtr<Iterator> pIterator(pThis->CreateIterator(sig));
	if (sig.IsSignalled()) return Value::Null;
	bool result = pIterator->IsContain(env, sig, args.GetValue(0));
	if (sig.IsSignalled()) return Value::Null;
	return Value(result);
}

// iterator#filter(criteria?) {block?}
Gura_DeclareMethod(iterator, filter)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "criteria", VTYPE_any, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
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

// iterator#while(criteria) {block?}
Gura_DeclareMethodAlias(iterator, while_, "while")
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "criteria", VTYPE_any);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(iterator, while_)
{
	Object_iterator *pThis = Object_iterator::GetThisObj(args);
	Iterator *pIteratorSrc = pThis->GetIterator()->Clone();
	Iterator *pIterator = pIteratorSrc->While(env, sig, args.GetValue(0));
	if (sig.IsSignalled()) return Value::Null;
	return ReturnIterator(env, sig, args, pIterator);
}

// iterator#since(criteria) {block?}
Gura_DeclareMethod(iterator, since)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "criteria", VTYPE_any);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(iterator, since)
{
	Object_iterator *pThis = Object_iterator::GetThisObj(args);
	Iterator *pIteratorSrc = pThis->GetIterator()->Clone();
	Iterator *pIterator = pIteratorSrc->Since(env, sig, args.GetValue(0), true);
	if (sig.IsSignalled()) return Value::Null;
	return ReturnIterator(env, sig, args, pIterator);
}

// iterator#after(criteria) {block?}
Gura_DeclareMethod(iterator, after)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "criteria", VTYPE_any);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(iterator, after)
{
	Object_iterator *pThis = Object_iterator::GetThisObj(args);
	Iterator *pIteratorSrc = pThis->GetIterator()->Clone();
	Iterator *pIterator = pIteratorSrc->Since(env, sig, args.GetValue(0), false);
	if (sig.IsSignalled()) return Value::Null;
	return ReturnIterator(env, sig, args, pIterator);
}

// iterator#until(criteria) {block?}
Gura_DeclareMethod(iterator, until)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "criteria", VTYPE_any);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(iterator, until)
{
	Object_iterator *pThis = Object_iterator::GetThisObj(args);
	Iterator *pIteratorSrc = pThis->GetIterator()->Clone();
	Iterator *pIterator = pIteratorSrc->Until(env, sig, args.GetValue(0), true);
	if (sig.IsSignalled()) return Value::Null;
	return ReturnIterator(env, sig, args, pIterator);
}

// iterator#before(criteria) {block?}
Gura_DeclareMethod(iterator, before)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "criteria", VTYPE_any);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(iterator, before)
{
	Object_iterator *pThis = Object_iterator::GetThisObj(args);
	Iterator *pIteratorSrc = pThis->GetIterator()->Clone();
	Iterator *pIterator = pIteratorSrc->Until(env, sig, args.GetValue(0), false);
	if (sig.IsSignalled()) return Value::Null;
	return ReturnIterator(env, sig, args, pIterator);
}

// iterator#map(func:Function) {block?}
Gura_DeclareMethod(iterator, map)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "func", VTYPE_function);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(iterator, map)
{
	Object_iterator *pThis = Object_iterator::GetThisObj(args);
	Iterator *pIterator = new Iterator_ExplicitMap(env, sig,
			pThis->GetIterator()->Clone(),
			Object_function::Reference(Object_function::GetObject(args, 0)));
	return ReturnIterator(env, sig, args, pIterator);
}

// iterator#reduce(accum) {block}
Gura_DeclareMethod(iterator, reduce)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "accum", VTYPE_any);
	DeclareBlock(OCCUR_Once);
}

Gura_ImplementMethod(iterator, reduce)
{
	Object_iterator *pThis = Object_iterator::GetThisObj(args);
	AutoPtr<Iterator> pIterator(pThis->GetIterator()->Clone());
	Environment envBlock(&env, ENVTYPE_block);
	const Function *pFuncBlock =
						args.GetBlockFunc(envBlock, sig, GetSymbolForBlock());
	if (pFuncBlock == NULL) {
		return Value::Null;
	}
	Value result = pIterator->Reduce(env, sig, args.GetValue(0), pFuncBlock);
	if (sig.IsSignalled()) return Value::Null;
	return result;
}

// iterator#find(criteria?):[index]
Gura_DeclareMethod(iterator, find)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareAttr(Gura_Symbol(index));
	DeclareArg(env, "criteria", VTYPE_any, OCCUR_ZeroOrOnce);
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
	if (args.IsSet(Gura_Symbol(index))) return Value(static_cast<unsigned int>(idx));
	return value;
}

// iterator#count(criteria?)
Gura_DeclareMethod(iterator, count)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "criteria", VTYPE_any, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(iterator, count)
{
	Object_iterator *pThis = Object_iterator::GetThisObj(args);
	AutoPtr<Iterator> pIterator(pThis->GetIterator()->Clone());
	size_t cnt = args.IsValid(0)?
		pIterator->Count(env, sig, args.GetValue(0)) : pIterator->CountTrue(env, sig);
	if (sig.IsSignalled()) return Value::Null;
	return Value(static_cast<unsigned int>(cnt));
}

// iterator#sort(directive?, keys[]?):[stable] {block?}
Gura_DeclareMethod(iterator, sort)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "directive", VTYPE_any, OCCUR_ZeroOrOnce);
	DeclareArg(env, "keys", VTYPE_any, OCCUR_ZeroOrOnce, FLAG_List);
	DeclareAttr(Gura_Symbol(stable));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(iterator, sort)
{
	Object_iterator *pThis = Object_iterator::GetThisObj(args);
	AutoPtr<Iterator> pIteratorSrc(pThis->GetIterator()->Clone());
	Value value = pIteratorSrc->Eval(env, sig, args);
	if (sig.IsSignalled()) return Value::Null;
	if (value.IsInvalid()) return args.GetThis();
	GURA_ASSUME(env, value.IsList());
	Object_list *pObj = Object_list::GetObject(value)->SortRank(sig, args.GetValue(0),
						args.IsList(1)? &args.GetList(1) : NULL,
						false, args.IsSet(Gura_Symbol(stable)));
	if (sig.IsSignalled()) return Value::Null;
	Iterator *pIterator = new Object_list::IteratorEach(pObj);
	return ReturnIterator(env, sig, args, pIterator);
}

// iterator#rank(directive?):[stable] {block?}
Gura_DeclareMethod(iterator, rank)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "directive", VTYPE_any, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(iterator, rank)
{
	Object_iterator *pThis = Object_iterator::GetThisObj(args);
	AutoPtr<Iterator> pIteratorSrc(pThis->GetIterator()->Clone());
	Value value = pIteratorSrc->Eval(env, sig, args);
	if (sig.IsSignalled() || value.IsInvalid()) return Value::Null;
	GURA_ASSUME(env, value.IsList());
	Object_list *pObj = Object_list::GetObject(value)->SortRank(sig, args.GetValue(0), NULL,
							true, args.IsSet(Gura_Symbol(stable)));
	if (sig.IsSignalled()) return Value::Null;
	Iterator *pIterator = new Object_list::IteratorEach(pObj);
	return ReturnIterator(env, sig, args, pIterator);
}

// iterator#join(sep?:string)
Gura_DeclareMethod(iterator, join)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "sep", VTYPE_string, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(iterator, join)
{
	Object_iterator *pThis = Object_iterator::GetThisObj(args);
	const char *sep = args.IsString(0)? args.GetString(0) : "";
	AutoPtr<Iterator> pIterator(pThis->GetIterator()->Clone());
	String rtn;
	Value value;
	if (pIterator->Next(env, sig, value)) {
		rtn += value.ToString(sig, false);
		if (sig.IsSignalled()) {
			return Value::Null;
		}
		while (pIterator->Next(env, sig, value)) {
			rtn += sep;
			rtn += value.ToString(sig, false);
			if (sig.IsSignalled()) {
				return Value::Null;
			}
		}
	}
	if (sig.IsSignalled()) return Value::Null;
	return Value(env, rtn.c_str());
}

// iterator#joinb()
Gura_DeclareMethod(iterator, joinb)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(iterator, joinb)
{
	Object_iterator *pThis = Object_iterator::GetThisObj(args);
	const char *sep = args.IsString(0)? args.GetString(0) : "";
	AutoPtr<Iterator> pIterator(pThis->GetIterator()->Clone());
	Binary buff;
	Value value;
	while (pIterator->Next(env, sig, value)) {
		if (!value.IsBinary()) {
			sig.SetError(ERR_ValueError, "invalid value type");
			return Value::Null;
		}
		buff += value.GetBinary();
	}
	if (sig.IsSignalled()) return Value::Null;
	Value result;
	result.InitAsBinary(env, buff, true);
	return result;
}

// iterator#format(format:string) {block?}
Gura_DeclareMethod(iterator, format)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "format", VTYPE_string);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(iterator, format)
{
	Object_iterator *pThis = Object_iterator::GetThisObj(args);
	Iterator *pIterator =
		new Iterator_Format(pThis->GetIterator()->Clone(), args.GetString(0));
	return ReturnIterator(env, sig, args, pIterator);
}

// iterator#pack(format:string) {block?}
Gura_DeclareMethod(iterator, pack)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "format", VTYPE_string);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(iterator, pack)
{
	Object_iterator *pThis = Object_iterator::GetThisObj(args);
	Iterator *pIterator =
		new Iterator_Pack(pThis->GetIterator()->Clone(), args.GetString(0));
	return ReturnIterator(env, sig, args, pIterator);
}

// iterator#each() {block?}
Gura_DeclareMethod(iterator, each)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(iterator, each)
{
	Object_iterator *pThis = Object_iterator::GetThisObj(args);
	Iterator *pIterator = pThis->GetIterator()->Clone();
	return ReturnIterator(env, sig, args, pIterator);
}

// iterator#offset(n:number) {block?}
Gura_DeclareMethod(iterator, offset)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "n", VTYPE_number);
	DeclareBlock(OCCUR_ZeroOrOnce);
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

// iterator#runlength() {block?}
Gura_DeclareMethod(iterator, runlength)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(iterator, runlength)
{
	Object_iterator *pThis = Object_iterator::GetThisObj(args);
	Iterator *pIterator = new Iterator_RunLength(pThis->GetIterator()->Clone());
	return ReturnIterator(env, sig, args, pIterator);
}

// iterator#align(n:number, value?) {block?}
Gura_DeclareMethod(iterator, align)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "n", VTYPE_number);
	DeclareArg(env, "value", VTYPE_any, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(iterator, align)
{
	Object_iterator *pThis = Object_iterator::GetThisObj(args);
	Iterator *pIterator = new Iterator_Align(pThis->GetIterator()->Clone(),
			static_cast<int>(args.GetNumber(0)), args.GetValue(1));
	return ReturnIterator(env, sig, args, pIterator);
}

// iterator#skip(n:number) {block?}
Gura_DeclareMethod(iterator, skip)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "n", VTYPE_number);
	DeclareBlock(OCCUR_ZeroOrOnce);
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
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(iterator, skipnil)
{
	Object_iterator *pThis = Object_iterator::GetThisObj(args);
	Iterator *pIterator = new Iterator_SkipInvalid(pThis->GetIterator()->Clone());
	return ReturnIterator(env, sig, args, pIterator);
}

// iterator#roundoff(threshold:number => 1e-10) {block?}
Gura_DeclareMethod(iterator, roundoff)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "threshold", VTYPE_number, OCCUR_Once, FLAG_None,
											new Expr_Value(RoundOffThreshold));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(iterator, roundoff)
{
	Object_iterator *pThis = Object_iterator::GetThisObj(args);
	Iterator *pIterator = new Iterator_RoundOff(
						pThis->GetIterator()->Clone(), args.GetNumber(0));
	return ReturnIterator(env, sig, args, pIterator);
}

// iterator#nilto(replace) {block?}
Gura_DeclareMethod(iterator, nilto)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "replace", VTYPE_any);
}

Gura_ImplementMethod(iterator, nilto)
{
	Object_iterator *pThis = Object_iterator::GetThisObj(args);
	Iterator *pIterator = new Iterator_ReplaceInvalid(pThis->GetIterator()->Clone(),
															args.GetValue(0));
	return ReturnIterator(env, sig, args, pIterator);
}

// iterator#replace(value, replace) {block?}
Gura_DeclareMethod(iterator, replace)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "value", VTYPE_any);
	DeclareArg(env, "replace", VTYPE_any);
}

Gura_ImplementMethod(iterator, replace)
{
	Object_iterator *pThis = Object_iterator::GetThisObj(args);
	Iterator *pIterator = new Iterator_Replace(pThis->GetIterator()->Clone(),
									args.GetValue(0), args.GetValue(1));
	return ReturnIterator(env, sig, args, pIterator);
}

// iterator#head(n:number):map {block?}
Gura_DeclareMethod(iterator, head)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(iterator, head)
{
	Object_iterator *pThis = Object_iterator::GetThisObj(args);
	Iterator *pIterator = new Iterator_Head(pThis->GetIterator()->Clone(),
									static_cast<int>(args.GetNumber(0)));
	return ReturnIterator(env, sig, args, pIterator);
}

// iterator#tail(n:number) {block?}
Gura_DeclareMethod(iterator, tail)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "n", VTYPE_number);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(iterator, tail)
{
	Object_iterator *pThis = Object_iterator::GetThisObj(args);
	AutoPtr<Iterator> pIteratorSrc(pThis->GetIterator()->Clone());
	Value value = pIteratorSrc->Eval(env, sig, args);
	if (sig.IsSignalled() || value.IsInvalid()) return Value::Null;
	GURA_ASSUME(env, value.IsList());
	//Object_list *pObj = dynamic_cast<Object_list *>(value.GetListObj()->Clone());
	Object_list *pObj = Object_list::Reference(Object_list::GetObject(value));
	int cnt = args.GetInt(0);
	int cntMax = static_cast<int>(pObj->GetList().size());
	size_t offset = (cntMax > cnt)? cntMax - cnt : cntMax;
	Iterator *pIterator = new Object_list::IteratorEach(pObj, offset);
	return ReturnIterator(env, sig, args, pIterator);
}

// iterator#reverse() {block?}
Gura_DeclareMethod(iterator, reverse)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(iterator, reverse)
{
	Object_iterator *pThis = Object_iterator::GetThisObj(args);
	AutoPtr<Iterator> pIterator(pThis->GetIterator()->Clone());
	Value value = pIterator->Eval(env, sig, args);
	if (sig.IsSignalled() || value.IsInvalid()) return Value::Null;
	GURA_ASSUME(env, value.IsList());
	Object_list *pObj = Object_list::Reference(Object_list::GetObject(value));
	return ReturnIterator(env, sig, args,
							new Object_list::IteratorReverse(pObj));
}

// iterator#round(n?:number) {block?}
Gura_DeclareMethod(iterator, round)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "n", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(iterator, round)
{
	Object_iterator *pThis = Object_iterator::GetThisObj(args);
	int cnt = args.IsNumber(0)? args.GetInt(0) : -1;
	AutoPtr<Iterator> pIterator(pThis->GetIterator()->Clone());
	Value value = pIterator->Eval(env, sig, args);
	if (sig.IsSignalled() || value.IsInvalid()) return Value::Null;
	GURA_ASSUME(env, value.IsList());
	//Object_list *pObj = dynamic_cast<Object_list *>(value.GetListObj()->Clone());
	Object_list *pObj = Object_list::Reference(Object_list::GetObject(value));
	return ReturnIterator(env, sig, args,
							new Object_list::IteratorRound(pObj, cnt));
}

// iterator#pingpong(n?:number):[sticky,sticky_l,sticky_r] {block?}
Gura_DeclareMethod(iterator, pingpong)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "n", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareAttr(Gura_Symbol(sticky));
	DeclareAttr(Gura_Symbol(sticky_l));
	DeclareAttr(Gura_Symbol(sticky_r));
}

Gura_ImplementMethod(iterator, pingpong)
{
	Object_iterator *pThis = Object_iterator::GetThisObj(args);
	int cnt = args.IsNumber(0)? args.GetInt(0) : -1;
	bool stickyFlagL = args.IsSet(Gura_Symbol(sticky)) ||
						args.IsSet(Gura_Symbol(sticky_l));
	bool stickyFlagR = args.IsSet(Gura_Symbol(sticky)) ||
						args.IsSet(Gura_Symbol(sticky_r));
	AutoPtr<Iterator> pIterator(pThis->GetIterator()->Clone());
	Value value = pIterator->Eval(env, sig, args);
	if (sig.IsSignalled() || value.IsInvalid()) return Value::Null;
	GURA_ASSUME(env, value.IsList());
	//Object_list *pObj = dynamic_cast<Object_list *>(value.GetListObj()->Clone());
	Object_list *pObj = Object_list::Reference(Object_list::GetObject(value));
	return ReturnIterator(env, sig, args,
			new Object_list::IteratorPingpong(pObj, cnt, stickyFlagL, stickyFlagR));
}

// iterator#fold(n:number):[iteritem] {block?}
Gura_DeclareMethod(iterator, fold)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "n", VTYPE_number);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareAttr(Gura_Symbol(iteritem));
}

Gura_ImplementMethod(iterator, fold)
{
	Object_iterator *pThis = Object_iterator::GetThisObj(args);
	int cnt = static_cast<int>(args.GetNumber(0));
	bool listItemFlag = !args.IsSet(Gura_Symbol(iteritem));
	Iterator *pIterator = new Iterator_Fold(pThis->GetIterator()->Clone(), cnt, listItemFlag);
	return ReturnIterator(env, sig, args, pIterator);
}

//-----------------------------------------------------------------------------
// Classs implementation
//-----------------------------------------------------------------------------
Class_iterator::Class_iterator(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_iterator)
{
	Gura_AssignMethod(iterator, isinfinite);
	Gura_AssignMethod(iterator, next);
	Gura_AssignMethod(iterator, print);
	Gura_AssignMethod(iterator, println);
	Gura_AssignMethod(iterator, printf);
	Gura_AssignMethod(iterator, delay);
	// common operations with list
	Gura_AssignMethod(iterator, len);
	Gura_AssignMethod(iterator, min);
	Gura_AssignMethod(iterator, max);
	Gura_AssignMethod(iterator, sum);
	Gura_AssignMethod(iterator, average);
	Gura_AssignMethod(iterator, variance);
	Gura_AssignMethod(iterator, stddev);
	Gura_AssignMethod(iterator, and_);
	Gura_AssignMethod(iterator, or_);
	Gura_AssignMethod(iterator, iscontain);
	Gura_AssignMethod(iterator, filter);
	Gura_AssignMethod(iterator, while_);
	Gura_AssignMethod(iterator, since);
	Gura_AssignMethod(iterator, after);
	Gura_AssignMethod(iterator, until);
	Gura_AssignMethod(iterator, before);
	Gura_AssignMethod(iterator, map);
	Gura_AssignMethod(iterator, reduce);
	Gura_AssignMethod(iterator, find);
	Gura_AssignMethod(iterator, count);
	Gura_AssignMethod(iterator, sort);
	Gura_AssignMethod(iterator, rank);
	Gura_AssignMethod(iterator, join);
	Gura_AssignMethod(iterator, joinb);
	Gura_AssignMethod(iterator, format);
	Gura_AssignMethod(iterator, pack);
	Gura_AssignMethod(iterator, each);
	Gura_AssignMethod(iterator, offset);
	Gura_AssignMethod(iterator, runlength);
	Gura_AssignMethod(iterator, align);
	Gura_AssignMethod(iterator, skip);
	Gura_AssignMethod(iterator, skipnil);
	Gura_AssignMethod(iterator, roundoff);
	Gura_AssignMethod(iterator, nilto);
	Gura_AssignMethod(iterator, replace);
	Gura_AssignMethod(iterator, head);
	Gura_AssignMethod(iterator, tail);
	Gura_AssignMethod(iterator, reverse);
	Gura_AssignMethod(iterator, round);
	Gura_AssignMethod(iterator, pingpong);
	Gura_AssignMethod(iterator, fold);
}

bool Class_iterator::CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl)
{
	Iterator *pIterator = value.CreateIterator(sig);
	if (pIterator != NULL) {
		value = Value(env, pIterator);
		return true;
	}
	return false;
}

Object *Class_iterator::CreateDescendant(Environment &env, Signal sig, Class *pClass)
{
	GURA_ERROREND(env, "this function must not be called");
	return NULL;
}

void Class_iterator::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(iterator);
	Gura_AssignFunction(range);
	Gura_AssignFunction(interval);
	Gura_AssignFunction(zipv);
	Gura_AssignFunction(fill);
	Gura_AssignFunction(rands);
}

}
