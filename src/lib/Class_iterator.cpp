//=============================================================================
// Gura class: iterator
//=============================================================================
#include "stdafx.h"

namespace Gura {

static const char *helpDoc_en = R"**(
)**";

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

Iterator *Object_iterator::CreateIterator(Signal &sig)
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

bool Object_iterator::DoDirProp(Environment &env, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, symbols)) return false;
	return _pIterator->DoDirProp(env, symbols);
}

Value Object_iterator::DoGetProp(Environment &env, const Symbol *pSymbol,
								 const SymbolSet &attrs, bool &evaluatedFlag)
{
	return _pIterator->DoGetProp(env, pSymbol, attrs, evaluatedFlag);
}

Value Object_iterator::DoSetProp(Environment &env, const Symbol *pSymbol, const Value &value,
								 const SymbolSet &attrs, bool &evaluatedFlag)
{
	return _pIterator->DoSetProp(env, pSymbol, value, attrs, evaluatedFlag);
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
		Gura_Symbol(en),
		"Creates an iterator that combines iterators given in the argument.\n"
		"\n"
		"If an argument is not an iterator, that would be added as an element.\n"
		"\n"
		GURA_HELPTEXT_ITERATOR_en());
}

Gura_ImplementFunction(iterator)
{
	Signal &sig = env.GetSignal();
	Iterator_Concat *pIterator = new Iterator_Concat();
	foreach_const (ValueList, pValue, arg.GetList(0)) {
		Iterator *pIteratorArg = nullptr;
		if (pValue->Is_iterator()) {
			pIteratorArg = pValue->CreateIterator(sig);
			if (sig.IsSignalled()) return Value::Nil;
		} else {
			pIteratorArg = new Iterator_OneShot(*pValue);
		}
		pIterator->Add(pIteratorArg);
	}
	return ReturnIterator(env, arg, pIterator);
}

//-----------------------------------------------------------------------------
// Implementation of methods specific to iterator
//-----------------------------------------------------------------------------
// iterator#delay(delay:number) {block?}
Gura_DeclareMethod(iterator, delay)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "delay", VTYPE_number);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Creates an iterator that returns each element with an interval time\n"
		"specified by the argument `delay` in seconds.\n");
}

Gura_ImplementMethod(iterator, delay)
{
	Object_iterator *pThis = Object_iterator::GetObjectThis(arg);
	Iterator *pIterator =
		new Iterator_Delay(pThis->GetIterator()->Clone(), arg.GetNumber(0));
	return ReturnIterator(env, arg, pIterator);
}

// iterator#finite():reduce
Gura_DeclareMethod(iterator, finite)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	AddHelp(
		Gura_Symbol(en),
		"Marks the iterator as a finite one by clearing its infinite flag.\n"
		"\n"
		"This method returns the target instance itself.\n");
}

Gura_ImplementMethod(iterator, finite)
{
	Object_iterator *pThis = Object_iterator::GetObjectThis(arg);
	Iterator *pIterator = pThis->GetIterator();
	if (pIterator->IsInfinite()) {
		pIterator->SetFiniteness(Iterator::Finite);
	}
	return arg.GetValueThis();
}

// iterator#infinite():reduce
Gura_DeclareMethod(iterator, infinite)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	AddHelp(
		Gura_Symbol(en),
		"Marks the iterator as an infinite one by setting its infinite flag.\n"
		"\n"
		"This method returns the target instance itself.\n");
}

Gura_ImplementMethod(iterator, infinite)
{
	Object_iterator *pThis = Object_iterator::GetObjectThis(arg);
	pThis->GetIterator()->SetFiniteness(Iterator::Infinite);
	return arg.GetValueThis();
}

// iterator#isinfinite()
Gura_DeclareMethod(iterator, isinfinite)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en),
		"Returns `true` if the iterator is infinite one.\n"
		"\n"
		"The trait of iterator's infinity is used to avoid an endless process\n"
		"by evaluating an infinite iterator.\n"
		"An attempt to evaluate an infinite iterator such as creation of a list from it\n"
		"would occur an error.\n");
}

Gura_ImplementMethod(iterator, isinfinite)
{
	Object_iterator *pThis = Object_iterator::GetObjectThis(arg);
	return Value(pThis->GetIterator()->IsInfinite());
}

// iterator#next()
Gura_DeclareMethod(iterator, next)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en),
		"Returns a next element of the iterator.\n"
		"This operation updates the iterator's internal status.\n");
}

Gura_ImplementMethod(iterator, next)
{
	Object_iterator *pThis = Object_iterator::GetObjectThis(arg);
	Value value;
	if (pThis->GetIterator()->Next(env, value)) return value;
	return Value::Nil;
}

// iterator#repeater()
Gura_DeclareMethod(iterator, repeater)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en),
		"Makes the iterator behave as a \"repeater\".\n"
		"This would allow the iterator be evaulated when it appears as an element\n"
		"of another \"repeater\" iterator.\n"
		"\n"
		"Below is an example:\n"
		"\n"
		"    x = repeat(3):iter {\n"
		"        ['apple', 'orange', 'grape'].each()\n"
		"    }\n"
		"    println(x)\n"
		"    // Just prints iterator instance three times\n"
		"    // since x can't evaluate the internal iterator.\n"
		"    \n"
		"    x = repeat(3):iter {\n"
		"        ['apple', 'orange', 'grape'].each().repeater()\n"
		"    }\n"
		"    println(x)\n"
		"    // Prints 'apple', 'orange' and  'grape' three times\n"
		"    // after evaluating the internal iterator.\n");
}

Gura_ImplementMethod(iterator, repeater)
{
	Object_iterator *pThis = Object_iterator::GetObjectThis(arg);
	pThis->GetIterator()->SetRepeaterFlag(true);
	return arg.GetValueThis();
}

//-----------------------------------------------------------------------------
// Implementation of methods that are common between iterator and list
//-----------------------------------------------------------------------------
// iterator#after(criteria) {block?}
Gura_DeclareMethod(iterator, after)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "criteria", VTYPE_any);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), 
		"Creates an iterator that picks up elements that appear\n"
		"at positions after the criteria is evaluated to be `true`.\n"
		"\n"
		"You can specify a function, a list or an iterator as the criteria.\n"
		"\n"
		GURA_HELPTEXT_ITERATOR_en());
}

Gura_ImplementMethod(iterator, after)
{
	Signal &sig = env.GetSignal();
	Object_iterator *pThis = Object_iterator::GetObjectThis(arg);
	Iterator *pIteratorSrc = pThis->GetIterator()->Clone();
	Iterator *pIterator = pIteratorSrc->Since(env, arg.GetValue(0), false);
	if (sig.IsSignalled()) return Value::Nil;
	return ReturnIterator(env, arg, pIterator);
}

// iterator#align(n:number, value?) {block?}
Gura_DeclareMethod(iterator, align)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "n", VTYPE_number);
	DeclareArg(env, "value", VTYPE_any, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Creates an iterator that returns the specified number of elements in the source iterator.\n"
		"If the number is larger than the length of the source iterator,\n"
		"the lacking part is filled with `value`.\n"
		"If the argument `value` is omitted, `nil` is used for the filling.\n"
		"\n"
		"Below is an example to specify a number less than the source length:\n"
		"\n"
		"    x = [`A, `B, `C, `D, `E, `F].align(3)\n"
		"    // x generates `A, `B, `C.\n"
		"\n"
		"Below is an example to specify a number that exceeds the source length:\n"
		"\n"
		"    x = [`A, `B, `C, `D, `E, `F].align(8)\n"
		"    // x generates `A, `B, `C, `D, `E, `F, nil, nil.\n");
}

Gura_ImplementMethod(iterator, align)
{
	Object_iterator *pThis = Object_iterator::GetObjectThis(arg);
	Iterator *pIterator = new Iterator_Align(pThis->GetIterator()->Clone(),
			static_cast<int>(arg.GetNumber(0)), arg.GetValue(1));
	return ReturnIterator(env, arg, pIterator);
}

// iterator#and()
Gura_DeclareMethodAlias(iterator, and_, "and")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en), 
		"Calculates a logical AND result of all the values in the iterable.\n");
}

Gura_ImplementMethod(iterator, and_)
{
	Signal &sig = env.GetSignal();
	Object_iterator *pThis = Object_iterator::GetObjectThis(arg);
	AutoPtr<Iterator> pIterator(pThis->CreateIterator(sig));
	if (sig.IsSignalled()) return Value::Nil;
	Value result = pIterator->And(env);
	if (sig.IsSignalled()) return Value::Nil;
	return result;
}

// iterator#argmax():[last_index,indices]
Gura_DeclareMethod(iterator, argmax)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareAttr(Gura_Symbol(last_index));
	DeclareAttr(Gura_Symbol(indices));
	AddHelp(
		Gura_Symbol(en), 
		"Returns a position index where the maximum value is found at first.\n"
		"\n"
		"The following attributes modify the behavior:\n"
		"\n"
		"- `:last_index` .. returns an index where the maximum value is found at last.\n"
		"- `:indices` .. returns a list of all indices where the maximum value is found.\n"
		"\n"
		"Calling of methods `iterable#argmas()` and `iteraboe#max()` have the same effect\n"
		"when attributes are specified as follows:\n"
		"\n"
		"- `iterable.argmax()` and `iterable.max():index\n"
		"- `iterable.argmax():last_index` and `iterable.max():last_index\n"
		"- `iterable.argmax():indices` and `iterable.max():indices\n");
}

Gura_ImplementMethod(iterator, argmax)
{
	Object_iterator *pThis = Object_iterator::GetObjectThis(arg);
	AutoPtr<Iterator> pIterator(pThis->GetIterator()->Clone());
	return
		arg.IsSet(Gura_Symbol(last_index))? pIterator->FindMinMaxLastIndex(env, true) :
		arg.IsSet(Gura_Symbol(indices))? pIterator->FindMinMaxIndices(env, true) :
		pIterator->FindMinMaxIndex(env, true);
}

// iterator#argmin():[last_index,indices]
Gura_DeclareMethod(iterator, argmin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareAttr(Gura_Symbol(last_index));
	DeclareAttr(Gura_Symbol(indices));
	AddHelp(
		Gura_Symbol(en), 
		"Returns a position index where the minimum value is found at first.\n"
		"\n"
		"The following attributes modify the behavior:\n"
		"\n"
		"- `:last_index` .. returns an index where the minimum value is found at last.\n"
		"- `:indices` .. returns a list of all indices where the minimum value is found.\n"
		"\n"
		"Calling of methods `iterable#argmas()` and `iteraboe#max()` have the same effect\n"
		"when attributes are specified as follows:\n"
		"\n"
		"- `iterable.argmax()` and `iterable.max():index\n"
		"- `iterable.argmax():last_index` and `iterable.max():last_index\n"
		"- `iterable.argmax():indices` and `iterable.max():indices\n");
}

Gura_ImplementMethod(iterator, argmin)
{
	Object_iterator *pThis = Object_iterator::GetObjectThis(arg);
	AutoPtr<Iterator> pIterator(pThis->GetIterator()->Clone());
	return
		arg.IsSet(Gura_Symbol(last_index))? pIterator->FindMinMaxLastIndex(env, false) :
		arg.IsSet(Gura_Symbol(indices))? pIterator->FindMinMaxIndices(env, false) :
		pIterator->FindMinMaxIndex(env, false);
}

// iterator#before(criteria) {block?}
Gura_DeclareMethod(iterator, before)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "criteria", VTYPE_any);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), 
		"Creates an iterator that extracts elements in the iterable before criteria\n"
		"is evaluated as true. You can specify a function object, a list or an iterator\n"
		"as the criteria.\n"
		"\n"
		GURA_HELPTEXT_ITERATOR_en());
}

Gura_ImplementMethod(iterator, before)
{
	Signal &sig = env.GetSignal();
	Object_iterator *pThis = Object_iterator::GetObjectThis(arg);
	Iterator *pIteratorSrc = pThis->GetIterator()->Clone();
	AutoPtr<Iterator> pIterator(pIteratorSrc->Until(env, arg.GetValue(0), false));
	if (sig.IsSignalled()) return Value::Nil;
	return ReturnIterator(env, arg, pIterator.release());
}

// iterator#contains(value)
Gura_DeclareMethod(iterator, contains)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "value", VTYPE_any);
	AddHelp(
		Gura_Symbol(en), 
		"Returns `true` if the specified value appears in the iterable.");
}

Gura_ImplementMethod(iterator, contains)
{
	Signal &sig = env.GetSignal();
	Object_iterator *pThis = Object_iterator::GetObjectThis(arg);
	AutoPtr<Iterator> pIterator(pThis->CreateIterator(sig));
	if (sig.IsSignalled()) return Value::Nil;
	bool result = pIterator->DoesContain(env, arg.GetValue(0));
	if (sig.IsSignalled()) return Value::Nil;
	return Value(result);
}

// iterator#count(criteria?)
Gura_DeclareMethod(iterator, count)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "criteria", VTYPE_any, OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), 
		"Returns a number of elements that matches the given criteria which is a single-argument\n"
		"function or a value.\n"
		"\n"
		"When a function is applied, it counts the number of true after\n"
		"evaluating element value with the function. If a value is applied, it counts the number\n"
		"of elements that are equal to the value.");
}

Gura_ImplementMethod(iterator, count)
{
	Signal &sig = env.GetSignal();
	Object_iterator *pThis = Object_iterator::GetObjectThis(arg);
	AutoPtr<Iterator> pIterator(pThis->GetIterator()->Clone());
	size_t cnt = arg.IsValid(0)?
		pIterator->Count(env, arg.GetValue(0)) : pIterator->CountTrue(env);
	if (sig.IsSignalled()) return Value::Nil;
	return Value(static_cast<UInt>(cnt));
}

// iterator#cycle(n?:number) {block?}
Gura_DeclareMethod(iterator, cycle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "n", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Creates an iterator that iterates elements in the source iterator cyclically.\n"
		"\n"
		"The argument `n` specifies the number of elements the created iterator returns.\n"
		"If omitted, it would iterates elements infinitely.\n"
		"\n"
		"Below is an example:\n"
		"\n"
		"    x = [`A, `B, `C, `D, `E].cycle()\n"
		"    // x generates `A, `B, `C, `D, `E, `A, `B, `C, `D, `E, `A, `B, ..\n");

}

Gura_ImplementMethod(iterator, cycle)
{
	Object_iterator *pThis = Object_iterator::GetObjectThis(arg);
	int cnt = arg.Is_number(0)? arg.GetInt(0) : -1;
	AutoPtr<Iterator> pIterator(pThis->GetIterator()->Clone());
	ResultComposer resultComposer(env, arg);
	if (!resultComposer.StoreValues(env, pIterator.get())) return Value::Nil;
	const Value &value = resultComposer.GetValueResult();
	if (value.IsInvalid()) return Value::Nil;
	GURA_ASSUME(env, value.Is_list());
	Object_list *pObj = Object_list::Reference(Object_list::GetObject(value));
	return ReturnIterator(env, arg,
							new Object_list::IteratorCycle(pObj, cnt));
}

// iterator#each() {block?}
Gura_DeclareMethod(iterator, each)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), 
		"Creates an iterator that iterates each element in the list.\n"
		"\n"
		GURA_HELPTEXT_ITERATOR_en());
}

Gura_ImplementMethod(iterator, each)
{
	Object_iterator *pThis = Object_iterator::GetObjectThis(arg);
	Iterator *pIterator = pThis->GetIterator()->Clone();
	return ReturnIterator(env, arg, pIterator);
}

// iterator#filter(criteria?) {block?}
Gura_DeclareMethod(iterator, filter)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "criteria", VTYPE_any, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), 
		"Creates an iterable that filters values in the source iterable by a criteria.\n"
		"\n"
		"A criteria can be an iterable or a function instance.\n"
		"\n"
		"- When the criteria is an iterable, the created iterator would scan the source and\n"
		"  the criteria iterable simultaneously and would return a value of the source\n"
		"  when the corresponding criteria value is evaluated as `true`.\n"
		"\n"
		"- When the criteria is a function instance, the created iterator would give it\n"
		"  a value of the source as an argument and would return the value\n"
		"  when the function has returned `true`.\n"
		"\n"
		"Below is an example to use an iterable as its criteria:\n"
		"\n"
		"    x = [3, 1, 4, 1, 5, 9]\n"
		"    y = filter(x > 3)\n"
		"    // (x > 3) makes a list [false, false, true, false, true, true]\n"
		"    // y generates 4, 5, 9\n"
		"\n"
		"Below is an example to use a function as its criteria:\n"
		"\n"
		"    x = [3, 1, 4, 1, 5, 9]\n"
		"    y = filter(&{$x > 3})\n"
		"    // y generates 4, 5, 9\n");
}

Gura_ImplementMethod(iterator, filter)
{
	Signal &sig = env.GetSignal();
	Object_iterator *pThis = Object_iterator::GetObjectThis(arg);
	Iterator *pIteratorSrc = pThis->GetIterator()->Clone();
	AutoPtr<Iterator> pIterator;
	if (arg.IsValid(0)) {
		pIterator.reset(pIteratorSrc->Filter(env, arg.GetValue(0)));
		if (sig.IsSignalled()) return Value::Nil;
	} else {
		pIterator.reset(new Iterator_SkipFalse(pIteratorSrc));
	}
	return ReturnIterator(env, arg, pIterator.release());
}

// iterator#find(criteria?):[index]
Gura_DeclareMethod(iterator, find)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareAttr(Gura_Symbol(index));
	DeclareArg(env, "criteria", VTYPE_any, OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementMethod(iterator, find)
{
	Object_iterator *pThis = Object_iterator::GetObjectThis(arg);
	AutoPtr<Iterator> pIterator(pThis->GetIterator()->Clone());
	Value value;
	size_t idx = arg.IsValid(0)?
			pIterator->Find(env, arg.GetValue(0), value) :
			pIterator->FindTrue(env, value);
	if (idx == InvalidSize) return Value::Nil;
	if (arg.IsSet(Gura_Symbol(index))) return Value(static_cast<UInt>(idx));
	return value;
}

// iterator#flatten():[dfs,bfs] {block?}
Gura_DeclareMethod(iterator, flatten)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareAttr(Gura_Symbol(dfs));
	DeclareAttr(Gura_Symbol(bfs));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Creates an iterator that searches items recursively if they are lists or iterators.\n"
		"\n"
		"Specifying an attribute could customize searching order as below:\n"
		"\n"
		"- `:dfs` .. Searches in depth-first order. This is the default behavior.\n"
		"- `:bfs` .. Searches in breadth-first order.\n"
		"\n"
		GURA_HELPTEXT_ITERATOR_en()
		"\n"
		"Below is an example:\n"
		"\n"
		"    x = [[`A, `B, `C], [`D, `E, [`F, `G, `H], `I, `J], `K, `L]\n"
		"    \n"
		"    y = x.flattten():dfs\n"
		"    // y generates `A, `B, `C, `D, `E, `F, `G, `H, `I, `J, `K, `L\n"
		"    \n"
		"    y = x.flatten():bfs\n"
		"    // y generates `K, `L, `A, `B, `C, `D, `E, `I, `J, `F, `G, `H\n");
}

Gura_ImplementMethod(iterator, flatten)
{
	Object_iterator *pThis = Object_iterator::GetObjectThis(arg);
	Iterator_Flatten::Mode mode = arg.IsSet(Gura_Symbol(bfs))?
		Iterator_Flatten::MODE_BreadthFirstSearch : Iterator_Flatten::MODE_DepthFirstSearch;
	AutoPtr<Iterator> pIterator(new Iterator_Flatten(pThis->GetIterator()->Clone(), mode));
	return ReturnIterator(env, arg, pIterator.release());
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
		Gura_Symbol(en),
		"Creates an iterator that packs `n` elements of the source iterator into a list\n"
		"and returns it as its element.\n"
		"\n"
		"The argument `nstep` specifies the shift amount to the next packing."
		"If omitted, the next packing is shifted by `n` elements.\n"
		"\n"
		"Specifying the attribute `:iteritem` returns an iterator as its element instead of a list\n"
		"\n"
		"If the last packing doesn't satisfy `n` elements, its list would be shorter than `n`.\n"
		"When specifying the attribute `:neat`, such an immature list would be eliminated.\n"
		"\n"
		"Following is an example to fold elements by 3:\n"
		"\n"
		"    x = [`A, `B, `C, `D, `E, `F, `G, `H].fold(3)\n"
		"    // x generates [`A, `B, `C], [`D, `E, `F], [`G, `H].\n"
		"\n"
		"Following is an example to fold elements by 3 with a step of 2:\n"
		"\n"
		"    x = [`A, `B, `C, `D, `E, `F, `G, `H].fold(3, 2)\n"
		"    // x generates [`A, `B, `C], [`C, `D, `E], [`E, `F, `G], [`G, `H].\n");
}

Gura_ImplementMethod(iterator, fold)
{
	Object_iterator *pThis = Object_iterator::GetObjectThis(arg);
	size_t cnt = arg.GetSizeT(0);
	size_t cntStep = arg.Is_number(1)? arg.GetSizeT(1) : cnt;
	bool listItemFlag = !arg.IsSet(Gura_Symbol(iteritem));
	bool neatFlag = arg.IsSet(Gura_Symbol(neat));
	Iterator *pIterator = new Iterator_Fold(pThis->GetIterator()->Clone(),
											cnt, cntStep, listItemFlag, neatFlag);
	return ReturnIterator(env, arg, pIterator);
}

// iterator#format(format:string):map {block?}
Gura_DeclareMethod(iterator, format)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "format", VTYPE_string);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), 
		"Creates an iterator that converts element values in the source iterable into strings\n"
		"depending on formatter specifier in `format`.\n"
		"\n"
		GURA_HELPTEXT_ITERATOR_en());
}

Gura_ImplementMethod(iterator, format)
{
	Object_iterator *pThis = Object_iterator::GetObjectThis(arg);
	Iterator *pIterator =
		new Iterator_Format(pThis->GetIterator()->Clone(), arg.GetString(0));
	return ReturnIterator(env, arg, pIterator);
}

// iterator#head(n:number):map {block?}
Gura_DeclareMethod(iterator, head)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Creates an iterator that takes the first `n` elements from the source iterable.\n"
		"\n"
		GURA_HELPTEXT_ITERATOR_en());
}

Gura_ImplementMethod(iterator, head)
{
	Object_iterator *pThis = Object_iterator::GetObjectThis(arg);
	Iterator *pIterator = new Iterator_Head(pThis->GetIterator()->Clone(),
									static_cast<int>(arg.GetNumber(0)));
	return ReturnIterator(env, arg, pIterator);
}

// iterator#join(sep?:string):map
Gura_DeclareMethod(iterator, join)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "sep", VTYPE_string, OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), 
		"Joins all the elements in the iterable as strings while inserting\n"
		"the specified separator `sep` and returns the result.\n"
		"\n"
		"If an element is not a `string` value, it would be converted to a `string`\n"
		"before being joined.\n");
}

Gura_ImplementMethod(iterator, join)
{
	Signal &sig = env.GetSignal();
	Object_iterator *pThis = Object_iterator::GetObjectThis(arg);
	const char *sep = arg.Is_string(0)? arg.GetString(0) : "";
	AutoPtr<Iterator> pIterator(pThis->GetIterator()->Clone());
	String rtn = pIterator->Join(env, sep);
	if (sig.IsSignalled()) return Value::Nil;
	return Value(rtn);
}

// iterator#joinb()
Gura_DeclareMethod(iterator, joinb)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en), 
		"Joins all the `binary` values in the iterable and returns the result.\n");
}

Gura_ImplementMethod(iterator, joinb)
{
	Signal &sig = env.GetSignal();
	Object_iterator *pThis = Object_iterator::GetObjectThis(arg);
	AutoPtr<Iterator> pIterator(pThis->GetIterator()->Clone());
	Binary rtn = pIterator->Joinb(env);
	if (sig.IsSignalled()) return Value::Nil;
	return Value(new Object_binary(env, rtn, true));
}

// iterator#len()
Gura_DeclareMethod(iterator, len)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en),
		"Returns the length of the iterable.");
}

Gura_ImplementMethod(iterator, len)
{
	Object_iterator *pThis = Object_iterator::GetObjectThis(arg);
	size_t len = pThis->GetIterator()->GetLengthEx(env);
	if (env.IsSignalled()) return Value::Nil;
	return Value(len);
#if 0
	if (pThis->GetIterator()->IsInfinite()) {
		Iterator::SetError_InfiniteNotAllowed(sig);
		return Value::Nil;
	}
	size_t cnt = 0;
	if (pThis->GetIterator()->IsFinitePredictable()) {
		cnt = pThis->GetIterator()->GetLength();
	} else {
		AutoPtr<Iterator> pIterator(pThis->GetIterator()->Clone());
		Value value;
		for ( ; pIterator->Next(env, value); cnt++) ;
		if (sig.IsSignalled()) return Value::Nil;
	}
	return Value(cnt);
#endif
}

// iterator#map(func:function) {block?}
Gura_DeclareMethod(iterator, map)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "func", VTYPE_function);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), 
		"Creates an iterator that generates element values after applying the specfied\n"
		"function on them. The function must take one argument.\n"
		"\n"
		GURA_HELPTEXT_ITERATOR_en());
}

Gura_ImplementMethod(iterator, map)
{
	Object_iterator *pThis = Object_iterator::GetObjectThis(arg);
	Iterator *pIterator = new Iterator_ExplicitMap(env.Clone(),
			pThis->GetIterator()->Clone(),
			Object_function::Reference(Object_function::GetObject(arg, 0)));
	return ReturnIterator(env, arg, pIterator);
}

// iterator#max():[index,last_index,indices]
Gura_DeclareMethod(iterator, max)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareAttr(Gura_Symbol(index));
	DeclareAttr(Gura_Symbol(last_index));
	DeclareAttr(Gura_Symbol(indices));
	AddHelp(
		Gura_Symbol(en), 
		"Returns the maximum value in the iterable.\n"
		"\n"
		"It would return a position index where the maximum value is found\n"
		"when one of the following attributes is specified:\n"
		"\n"
		"- `:index` .. an index of the maximum value.\n"
		"- `:last_index` .. an index where the maximum value is found at last.\n"
		"- `:indices` .. a list of all indices where the maximum value is found.\n");
}

Gura_ImplementMethod(iterator, max)
{
	Object_iterator *pThis = Object_iterator::GetObjectThis(arg);
	AutoPtr<Iterator> pIterator(pThis->GetIterator()->Clone());
	return
		arg.IsSet(Gura_Symbol(index))? pIterator->FindMinMaxIndex(env, true) :
		arg.IsSet(Gura_Symbol(last_index))? pIterator->FindMinMaxLastIndex(env, true) :
		arg.IsSet(Gura_Symbol(indices))? pIterator->FindMinMaxIndices(env, true) :
		pIterator->FindMinMax(env, true);
}

// iterator#mean()
Gura_DeclareMethod(iterator, mean)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en),
		"Calculates an average of elements in the iterable.\n"
		"\n"
		"It can work on an iterable with elements of type that supports addition and division operators.\n"
		"Below is a list of acceptable value types:\n"
		"\n"
		"- `number`\n"
		"- `complex`\n"
		"- `rational`\n");
}

Gura_ImplementMethod(iterator, mean)
{
	Signal &sig = env.GetSignal();
	Object_iterator *pThis = Object_iterator::GetObjectThis(arg);
	AutoPtr<Iterator> pIterator(pThis->CreateIterator(sig));
	if (sig.IsSignalled()) return Value::Nil;
	size_t cnt;
	Value result = pIterator->Average(env, cnt);
	if (sig.IsSignalled()) return Value::Nil;
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
		Gura_Symbol(en), 
		"Returns the minimum value in the iterable.\n"
		"\n"
		"It would return a position index where the minimum value is found\n"
		"when one of the following attributes is specified:\n"
		"\n"
		"- `:index` .. an index of the minimum value.\n"
		"- `:last_index` .. an index where the minimum value is found at last.\n"
		"- `:indices` .. a list of all indices where the minimum value is found.\n");
}

Gura_ImplementMethod(iterator, min)
{
	Object_iterator *pThis = Object_iterator::GetObjectThis(arg);
	AutoPtr<Iterator> pIterator(pThis->GetIterator()->Clone());
	return
		arg.IsSet(Gura_Symbol(index))? pIterator->FindMinMaxIndex(env, false) :
		arg.IsSet(Gura_Symbol(last_index))? pIterator->FindMinMaxLastIndex(env, false) :
		arg.IsSet(Gura_Symbol(indices))? pIterator->FindMinMaxIndices(env, false) :
		pIterator->FindMinMax(env, false);
}

// iterator#nilto(replace) {block?}
Gura_DeclareMethod(iterator, nilto)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "replace", VTYPE_any);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Creates an iterator that converts `nil` in the source iterable to the specified value.\n");
}

Gura_ImplementMethod(iterator, nilto)
{
	Object_iterator *pThis = Object_iterator::GetObjectThis(arg);
	Iterator *pIterator = new Iterator_ReplaceInvalid(pThis->GetIterator()->Clone(),
															arg.GetValue(0));
	return ReturnIterator(env, arg, pIterator);
}

// iterator#offset(n:number) {block?}
Gura_DeclareMethod(iterator, offset)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "n", VTYPE_number);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Creates an iterator that returns skips the first `n` elements in the source iterable.\n"
		"\n"
		GURA_HELPTEXT_ITERATOR_en()
		"\n"
		"Below is an example:\n"
		"\n"
		"    x = [`A, `B, `C, `D, `E, `F, `G, `H].offset(3)\n"
		"    // x generates `D, `E, `F, `G, `H\n");
}

Gura_ImplementMethod(iterator, offset)
{
	Object_iterator *pThis = Object_iterator::GetObjectThis(arg);
	Iterator *pIterator = pThis->GetIterator()->Clone();
	for (int cnt = static_cast<int>(arg.GetNumber(0)); cnt > 0; cnt--) {
		Value value;
		pIterator->Next(env, value);
	}
	return ReturnIterator(env, arg, pIterator);
}

// iterator#or()
Gura_DeclareMethodAlias(iterator, or_, "or")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en), 
		"Calculates a logical OR result of all the values in the iterable.\n");
}

Gura_ImplementMethod(iterator, or_)
{
	Signal &sig = env.GetSignal();
	Object_iterator *pThis = Object_iterator::GetObjectThis(arg);
	AutoPtr<Iterator> pIterator(pThis->CreateIterator(sig));
	if (sig.IsSignalled()) return Value::Nil;
	Value result = pIterator->Or(env);
	if (sig.IsSignalled()) return Value::Nil;
	return result;
}

// iterator#pack(format:string) {block?}
Gura_DeclareMethod(iterator, pack)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "format", VTYPE_string);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Creates a `binary` instance that has packed elements in the iterable\n"
		"according to specifiers in the `format`.\n"
		"\n"
		"A specifier has a format of \"`nX`\" where `X` is a format character\n"
		"that represents a packing format and `n` is a number of packing size.\n"
		"The number can be omitted, and it would be treated as `1` in that case.\n"
		"\n"
		"Following format characters would take a `number` value from the argument list\n"
		"and pack them into a binary sequence.\n"
		"\n"
		"- `b` .. A one-byte signed number.\n"
		"- `B` .. A one-byte unsigned number.\n"
		"- `h` .. A two-byte signed number.\n"
		"- `H` .. A two-byte unsigned number.\n"
		"- `i` .. A four-byte signed number.\n"
		"- `I` .. A four-byte unsigned number.\n"
		"- `l` .. A four-byte signed number.\n"
		"- `L` .. A four-byte unsigned number.\n"
		"- `q` .. A eight-byte signed number.\n"
		"- `Q` .. A eight-byte unsigned number.\n"
		"- `f` .. A float-typed number occupying four bytes.\n"
		"- `d` .. A double-typed number occupying eight bytes.\n"
		"\n"
		"As for them, the packing size `n` means the number of values to be packed.\n"
		"\n"
		"Following format characters would take a `string` value from the argument list\n"
		"and pack them into a binary sequence.\n"
		"\n"
		"- `s` .. Packs a sequence of UTF-8 codes in the string.\n"
		"         The packing size `n` means the size of the room in bytes\n"
		"         where the character codes are to be packed.\n"
		"         Only the sequence within the allocated room would be packed.\n"
		"         If the string length is smaller than the room,\n"
		"         the lacking part would be filled with zero.\n"
		"- `c` .. Picks the first byte of the string and packs it as a one-byte unsigned number.\n"
		"         The packing size `n` means the number of values to be packed.\n"
		"\n"
		"Following format character would take no value from the argument list.\n"
		"\n"
		"- `x` .. Fills the binary with zero.\n"
		"         The packing size `n` means the size of the room in bytes\n"
		"         to be filled with zero.\n"
		"\n"
		"The default byte-order for numbers of two-byte, four-byte and eight-byte\n"
		"depends on the system the interpreter is currently running.\n"
		"You can change it by the following specifiers:\n"
		"\n"
		"- `@` .. System-dependent order.\n"
		"- `=` .. System-dependent order.\n"
		"- `<` .. Little endian\n"
		"- `>` .. Big endian\n"
		"- `!` .. Big endian\n"
		"\n"
		"You can specify an asterisk character \"`*`\" for the number of packing size\n"
		"that picks that number from the argument list.\n"
		"\n"
		"You can specify encoding name embraced with \"`{`\" and \"`}`\" in the format\n"
		"to change coding character set while packing a string with format character \"`s`\"\n"
		"from UTF-8.\n");
}

Gura_ImplementMethod(iterator, pack)
{
	Object_iterator *pThis = Object_iterator::GetObjectThis(arg);
	Iterator *pIterator =
		new Iterator_Pack(pThis->GetIterator()->Clone(), arg.GetString(0));
	return ReturnIterator(env, arg, pIterator);
}

// iterator#pingpong(n?:number):[sticky,sticky@top,sticky@btm] {block?}
Gura_DeclareMethod(iterator, pingpong)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "n", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareAttr(Gura_Symbol(sticky));
	DeclareAttr(Gura_Symbol(sticky_at_top));
	DeclareAttr(Gura_Symbol(sticky_at_btm));
	AddHelp(
		Gura_Symbol(en),
		"Creates an iterator that iterates elements in the source iterator from top to bottom,\n"
		"and then from bottom to top repeatedly.\n"
		"\n"
		"The argument `n` specifies the number of elements the created iterator returns.\n"
		"If omitted, it would iterates elements infinitely.\n"
		"\n"
		"Below is an example:\n"
		"\n"
		"    x = [`A, `B, `C, `D, `E].pingpong()\n"
		"    // x generates `A, `B, `C, `D, `E, `D, `C, `B, `A, `B, ..\n"
		"\n"
		"The following attributes specify whether the elements on top and bottom are duplicated:\n"
		"\n"
		"- `:sticky` .. Duplicate the top and bottom elements.\n"
		"- `:sticky@top` .. Duplicate the top element.\n"
		"- `:sticky@btm` .. Duplicate the bottom element.\n"
		"\n"
		"Below is an example:\n"
		"\n"
		"    x = [`A, `B, `C, `D, `E].pingpong():sticky\n"
		"    // x generates `A, `B, `C, `D, `E, `E, `D, `C, `B, `A, `A, `B, ..\n");
}

Gura_ImplementMethod(iterator, pingpong)
{
	Object_iterator *pThis = Object_iterator::GetObjectThis(arg);
	int cnt = arg.Is_number(0)? arg.GetInt(0) : -1;
	bool stickyFlagTop = arg.IsSet(Gura_Symbol(sticky)) ||
						arg.IsSet(Gura_Symbol(sticky_at_top));
	bool stickyFlagBtm = arg.IsSet(Gura_Symbol(sticky)) ||
						arg.IsSet(Gura_Symbol(sticky_at_btm));
	AutoPtr<Iterator> pIterator(pThis->GetIterator()->Clone());
	ResultComposer resultComposer(env, arg);
	if (!resultComposer.StoreValues(env, pIterator.get())) return Value::Nil;
	const Value &value = resultComposer.GetValueResult();
	if (value.IsInvalid()) return Value::Nil;
	GURA_ASSUME(env, value.Is_list());
	Object_list *pObj = Object_list::Reference(Object_list::GetObject(value));
	return ReturnIterator(env, arg,
			new Object_list::IteratorPingpong(pObj, cnt, stickyFlagTop, stickyFlagBtm));
}

// iterator#print(stream?:stream:w):void
Gura_DeclareMethod(iterator, print)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_ZeroOrOnce, FLAG_Write);
	AddHelp(
		Gura_Symbol(en),
		"Prints elements to the specified `stream`.\n"
		"\n"
		"If omitted, they are printed to the standard output.\n");
}

Gura_ImplementMethod(iterator, print)
{
	Iterator *pIterator = Object_iterator::GetObjectThis(arg)->GetIterator()->Clone();
	Stream *pStream = arg.IsValid(0)? &arg.GetStream(0) : env.GetConsole();
	pIterator->PrintEach(env, pStream);
	return Value::Nil;
}

// iterator#printf(format:string, stream?:stream:w):void
Gura_DeclareMethod(iterator, printf)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "format", VTYPE_string);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_ZeroOrOnce, FLAG_Write);
	AddHelp(
		Gura_Symbol(en),
		"Prints items in the iterable by using the format.");
}

Gura_ImplementMethod(iterator, printf)
{
	Iterator *pIterator = Object_iterator::GetObjectThis(arg)->GetIterator()->Clone();
	const char *format = arg.GetString(0);
	Stream *pStream = arg.IsValid(1)? &arg.GetStream(1) : env.GetConsole();
	pIterator->PrintfEach(env, pStream, format);
	return Value::Nil;
}

// iterator#println(stream?:stream:w):void
Gura_DeclareMethod(iterator, println)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_ZeroOrOnce, FLAG_Write);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementMethod(iterator, println)
{
	Iterator *pIterator = Object_iterator::GetObjectThis(arg)->GetIterator()->Clone();
	Stream *pStream = arg.IsValid(0)? &arg.GetStream(0) : env.GetConsole();
	pIterator->PrintlnEach(env, pStream);
	return Value::Nil;
}

// iterator#prod()
Gura_DeclareMethod(iterator, prod)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en),
		"Calculates a product of elements in the iterable.\n"
		"\n"
		"It can work on an iterable with elements of a value type that supports multiplier operator.\n"
		"Below is a list of acceptable value types:\n"
		"\n"
		"- `number`\n"
		"- `complex`\n"
		"- `rational`\n");
}

Gura_ImplementMethod(iterator, prod)
{
	Signal &sig = env.GetSignal();
	Object_iterator *pThis = Object_iterator::GetObjectThis(arg);
	AutoPtr<Iterator> pIterator(pThis->CreateIterator(sig));
	if (sig.IsSignalled()) return Value::Nil;
	Value result = pIterator->Prod(env);
	if (sig.IsSignalled()) return Value::Nil;
	return result;
}

// iterator#rank(directive?):[stable] {block?}
Gura_DeclareMethod(iterator, rank)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "directive", VTYPE_any, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), 
		"Creates an iterable of rank numbers for elements after sorting them.\n"
		"\n"
		"In default, they are sorted in an ascending order.\n"
		"This means that, if two elements `x` and `y` has the relationship of `x < y`,\n"
		"`x` would be placed before `y`.\n"
		"You can change the order by specifying the argument `directive`\n"
		"with the following symbols:\n"
		"\n"
		"- `` `ascend`` .. Sorts in an ascending order. This is the default.\n"
		"- `` `descend`` .. Sorts in a descending order.\n"
		"\n"
		"You can also put a function to the argument `directive`\n"
		"that takes two arguments `x` and `y` and is expected to return numbers below:"
		"\n"
		"- `x == y` .. Zero.\n"
		"- `x < y` .. A number less than zero.\n"
		"- `x > y` .. A number greater than zero.\n"
		"\n"
		"When an attribute :stable is specified, the original order shall be kept for\n"
		"elements that are determined as the same.");
}

Gura_ImplementMethod(iterator, rank)
{
	Signal &sig = env.GetSignal();
	Object_iterator *pThis = Object_iterator::GetObjectThis(arg);
	AutoPtr<Iterator> pIteratorSrc(pThis->GetIterator()->Clone());
	ResultComposer resultComposer(env, arg);
	if (!resultComposer.StoreValues(env, pIteratorSrc.get())) return Value::Nil;
	const Value &value = resultComposer.GetValueResult();
	if (value.IsInvalid()) return Value::Nil;
	GURA_ASSUME(env, value.Is_list());
	Object_list *pObj = Object_list::GetObject(value)->SortRank(sig, arg.GetValue(0), nullptr,
							true, arg.IsSet(Gura_Symbol(stable)));
	if (sig.IsSignalled()) return Value::Nil;
	Iterator *pIterator = new Object_list::IteratorEach(pObj);
	return ReturnIterator(env, arg, pIterator);
}

// iterator#reduce(accum) {block}
Gura_DeclareMethod(iterator, reduce)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "accum", VTYPE_any);
	DeclareBlock(OCCUR_Once);
	AddHelp(
		Gura_Symbol(en), 
		"Evaluates a block with a parameter format `|value, accum|` and leaves the result\n"
		"as the next `accum` value.\n"
		"\n"
		"It returns the final `accum` value as its result.\n"
		"\n"
		"Below is an example to calculate summation of the elements:\n"
		"\n"
		"    x = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]\n"
		"    n = x.reduce(0) {|value, accum| value + accum}\n"
		"    // n is 55\n");
}

Gura_ImplementMethod(iterator, reduce)
{
	Signal &sig = env.GetSignal();
	Object_iterator *pThis = Object_iterator::GetObjectThis(arg);
	AutoPtr<Iterator> pIterator(pThis->GetIterator()->Clone());
	AutoPtr<Environment> pEnvBlock(env.Derive(ENVTYPE_block));
	const Function *pFuncBlock =
						arg.GetBlockFunc(*pEnvBlock, GetSymbolForBlock());
	if (pFuncBlock == nullptr) {
		return Value::Nil;
	}
	Value result = pIterator->Reduce(env, arg.GetValue(0), pFuncBlock);
	if (sig.IsSignalled()) return Value::Nil;
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
		Gura_Symbol(en),
		"Creates an iterator that replaces the `value` in the original iterable"
		"with the value of `replace`.\n"
		"\n"
		GURA_HELPTEXT_ITERATOR_en());
}

Gura_ImplementMethod(iterator, replace)
{
	Object_iterator *pThis = Object_iterator::GetObjectThis(arg);
	Iterator *pIterator = new Iterator_Replace(pThis->GetIterator()->Clone(),
									arg.GetValue(0), arg.GetValue(1));
	return ReturnIterator(env, arg, pIterator);
}

// iterator#reverse() {block?}
Gura_DeclareMethod(iterator, reverse)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Creates an iterator that iterates elements in the source iterable from tail to top.\n"
		"\n"
		GURA_HELPTEXT_ITERATOR_en());
}

Gura_ImplementMethod(iterator, reverse)
{
	Object_iterator *pThis = Object_iterator::GetObjectThis(arg);
	AutoPtr<Iterator> pIterator(pThis->GetIterator()->Clone());
	ResultComposer resultComposer(env, arg);
	if (!resultComposer.StoreValues(env, pIterator.get())) return Value::Nil;
	const Value &value = resultComposer.GetValueResult();
	if (value.IsInvalid()) return Value::Nil;
	GURA_ASSUME(env, value.Is_list());
	Object_list *pObj = Object_list::Reference(Object_list::GetObject(value));
	return ReturnIterator(env, arg,
							new Object_list::IteratorReverse(pObj));
}

// iterator#roundoff(threshold:number => 1e-10) {block?}
Gura_DeclareMethod(iterator, roundoff)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "threshold", VTYPE_number, OCCUR_Once, FLAG_None, 0,
											new Expr_Value(RoundOffThreshold));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Creates an iterator that replaces a number with zero\n"
		"if it is less than the specified `threshold`.\n"
		"\n"
		GURA_HELPTEXT_ITERATOR_en());
}

Gura_ImplementMethod(iterator, roundoff)
{
	Object_iterator *pThis = Object_iterator::GetObjectThis(arg);
	Iterator *pIterator = new Iterator_RoundOff(
						pThis->GetIterator()->Clone(), arg.GetNumber(0));
	return ReturnIterator(env, arg, pIterator);
}

// iterator#runlength() {block?}
Gura_DeclareMethod(iterator, runlength)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Creates an iterator that counts the number of consecutive same value\n"
		"and generates elements in a form of `[cnt, value]` where `cnt` indicates\n"
		"how many `value` appears in a row.\n"
		"\n"
		GURA_HELPTEXT_ITERATOR_en()
		"\n"
		"Below is an example:\n"
		"\n"
		"    x = [`A, `A, `B, `C, `C, `C, `D, `D].runlength()\n"
		"    // x generates [2, `A], [1, `B], [3, `C], [2, `D]\n");
}

Gura_ImplementMethod(iterator, runlength)
{
	Object_iterator *pThis = Object_iterator::GetObjectThis(arg);
	Iterator *pIterator = new Iterator_RunLength(pThis->GetIterator()->Clone());
	return ReturnIterator(env, arg, pIterator);
}

// iterator#since(criteria) {block?}
Gura_DeclareMethod(iterator, since)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "criteria", VTYPE_any);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), 
		"Creates an iterator that picks up each element in the iterable since criteria\n"
		"is evaluated as true. You can specify a function object, a list or an iterator\n"
		"as the criteria.\n"
		"\n"
		GURA_HELPTEXT_ITERATOR_en());
}

Gura_ImplementMethod(iterator, since)
{
	Signal &sig = env.GetSignal();
	Object_iterator *pThis = Object_iterator::GetObjectThis(arg);
	Iterator *pIteratorSrc = pThis->GetIterator()->Clone();
	Iterator *pIterator = pIteratorSrc->Since(env, arg.GetValue(0), true);
	if (sig.IsSignalled()) return Value::Nil;
	return ReturnIterator(env, arg, pIterator);
}

// iterator#skip(n:number) {block?}
Gura_DeclareMethod(iterator, skip)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "n", VTYPE_number);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Creates an iterator that skips `n` elements before picking up next element.\n"
		"\n"
		GURA_HELPTEXT_ITERATOR_en()
		"\n"
		"Below is an example:\n"
		"\n"
		"    x = [`A, `B, `C, `D, `E, `F, `G, `H].skip(2)\n"
		"    // x generates `A, `D, `G\n");
}

Gura_ImplementMethod(iterator, skip)
{
	Object_iterator *pThis = Object_iterator::GetObjectThis(arg);
	Iterator *pIterator =
		new Iterator_Skip(pThis->GetIterator()->Clone(), static_cast<int>(arg.GetNumber(0)));
	return ReturnIterator(env, arg, pIterator);
}

// iterator#skipnil() {block?}
Gura_DeclareMethod(iterator, skipnil)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Creates an iterator that skips `nil` in the source iterable.\n"
		"\n"
		GURA_HELPTEXT_ITERATOR_en()
		"\n"
		"Below is an example:\n"
		"\n"
		"    x = [`A, nil, `C, nil, nil, `F, nil, `H].skipnil()\n"
		"    // x generates `A, `C, `F, `H\n");
}

Gura_ImplementMethod(iterator, skipnil)
{
	Object_iterator *pThis = Object_iterator::GetObjectThis(arg);
	Iterator *pIterator = new Iterator_SkipInvalid(pThis->GetIterator()->Clone());
	return ReturnIterator(env, arg, pIterator);
}

// iterator#sort(directive?, keys[]?):[stable] {block?}
Gura_DeclareMethod(iterator, sort)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "directive", VTYPE_any, OCCUR_ZeroOrOnce);
	DeclareArg(env, "keys", VTYPE_any, OCCUR_ZeroOrOnce, FLAG_ListVar);
	DeclareAttr(Gura_Symbol(stable));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), 
		"Creates an iterator of elements after sorting them.\n"
		"\n"
		"In default, they are sorted in an ascending order.\n"
		"This means that, if two elements `x` and `y` has the relationship of `x < y`,\n"
		"`x` would be placed before `y`.\n"
		"You can change the order by specifying the argument `directive`\n"
		"with the following symbols:\n"
		"\n"
		"- `` `ascend`` .. Sorts in an ascending order. This is the default.\n"
		"- `` `descend`` .. Sorts in a descending order.\n"
		"\n"
		"You can also put a function to the argument `directive`\n"
		"that takes two arguments `x` and `y` and is expected to return numbers below:"
		"\n"
		"- `x == y` .. Zero.\n"
		"- `x < y` .. A number less than zero.\n"
		"- `x > y` .. A number greater than zero.\n"
		"\n"
		"When an attribute :stable is specified, the original order shall be kept for\n"
		"elements that are determined as the same."
		"\n"
		"If the argument `keys` is specified, it would be used as a key instead of element values.\n");
}

Gura_ImplementMethod(iterator, sort)
{
	Signal &sig = env.GetSignal();
	Object_iterator *pThis = Object_iterator::GetObjectThis(arg);
	AutoPtr<Iterator> pIteratorSrc(pThis->GetIterator()->Clone());
	ResultComposer resultComposer(env, arg);
	if (!resultComposer.StoreValues(env, pIteratorSrc.get())) return Value::Nil;
	const Value &value = resultComposer.GetValueResult();
	if (value.IsInvalid()) return arg.GetValueThis();
	GURA_ASSUME(env, value.Is_list());
	Object_list *pObj = Object_list::GetObject(value)->SortRank(sig, arg.GetValue(0),
						arg.Is_list(1)? &arg.GetList(1) : nullptr,
						false, arg.IsSet(Gura_Symbol(stable)));
	if (sig.IsSignalled()) return Value::Nil;
	Iterator *pIterator = new Object_list::IteratorEach(pObj);
	return ReturnIterator(env, arg, pIterator);
}

// iterator#std()
Gura_DeclareMethod(iterator, std)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en),
		"Calculates a standard deviation of elements in the iterable.\n");
}

Gura_ImplementMethod(iterator, std)
{
	Signal &sig = env.GetSignal();
	Object_iterator *pThis = Object_iterator::GetObjectThis(arg);
	AutoPtr<Iterator> pIterator(pThis->CreateIterator(sig));
	if (sig.IsSignalled()) return Value::Nil;
	size_t cnt;
	Value result = pIterator->StandardDeviation(env, cnt);
	if (sig.IsSignalled()) return Value::Nil;
	return result;
}

// iterator#sum()
Gura_DeclareMethod(iterator, sum)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en),
		"Calculates a summation of elements in the iterable.\n"
		"\n"
		"It can work on an iterable with elements of a value type that supports addition operator.\n"
		"Below is a list of acceptable value types:\n"
		"\n"
		"- `number`\n"
		"- `complex`\n"
		"- `string`\n"
		"- `rational`\n"
		"- `timedelta`\n");
}

Gura_ImplementMethod(iterator, sum)
{
	Signal &sig = env.GetSignal();
	Object_iterator *pThis = Object_iterator::GetObjectThis(arg);
	AutoPtr<Iterator> pIterator(pThis->CreateIterator(sig));
	if (sig.IsSignalled()) return Value::Nil;
	size_t cnt;
	Value result = pIterator->Sum(env, cnt);
	if (sig.IsSignalled()) return Value::Nil;
	return result;
}

// iterator#tail(n:number) {block?}
Gura_DeclareMethod(iterator, tail)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "n", VTYPE_number);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Creates an iterator that takes the last `n` elements from the source iterable.\n"
		"\n"
		GURA_HELPTEXT_ITERATOR_en());
}

Gura_ImplementMethod(iterator, tail)
{
	Object_iterator *pThis = Object_iterator::GetObjectThis(arg);
	AutoPtr<Iterator> pIteratorSrc(pThis->GetIterator()->Clone());
	ResultComposer resultComposer(env, arg);
	if (!resultComposer.StoreValues(env, pIteratorSrc.get())) return Value::Nil;
	const Value &value = resultComposer.GetValueResult();
	if (value.IsInvalid()) return Value::Nil;
	GURA_ASSUME(env, value.Is_list());
	Object_list *pObj = Object_list::Reference(Object_list::GetObject(value));
	int cnt = arg.GetInt(0);
	int cntMax = static_cast<int>(pObj->GetList().size());
	size_t offset = (cntMax > cnt)? cntMax - cnt : cntMax;
	Iterator *pIterator = new Object_list::IteratorEach(pObj, offset);
	return ReturnIterator(env, arg, pIterator);
}

// iterator#until(criteria) {block?}
Gura_DeclareMethod(iterator, until)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "criteria", VTYPE_any);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), 
		"Creates an iterator that picks up each element in the list until criteria\n"
		"is evaluated as true. You can specify a function object, a list or an iterator\n"
		"as the criteria.\n"
		"\n"
		GURA_HELPTEXT_ITERATOR_en());
}

Gura_ImplementMethod(iterator, until)
{
	Signal &sig = env.GetSignal();
	Object_iterator *pThis = Object_iterator::GetObjectThis(arg);
	Iterator *pIteratorSrc = pThis->GetIterator()->Clone();
	Iterator *pIterator = pIteratorSrc->Until(env, arg.GetValue(0), true);
	if (sig.IsSignalled()) return Value::Nil;
	return ReturnIterator(env, arg, pIterator);
}

// iterator#var()
Gura_DeclareMethod(iterator, var)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en),
		"Calculates a variance of elements in the iterable.\n");
}

Gura_ImplementMethod(iterator, var)
{
	Signal &sig = env.GetSignal();
	Object_iterator *pThis = Object_iterator::GetObjectThis(arg);
	AutoPtr<Iterator> pIterator(pThis->CreateIterator(sig));
	if (sig.IsSignalled()) return Value::Nil;
	size_t cnt;
	Value result = pIterator->Variance(env, cnt);
	if (sig.IsSignalled()) return Value::Nil;
	return result;
}

// iterator#while(criteria) {block?}
Gura_DeclareMethodAlias(iterator, while_, "while")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "criteria", VTYPE_any);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), 
		"Creates an iterator that picks up each element in the list while criteria\n"
		"is evaluated as true. You can specify a function object, a list or an iterator\n"
		"as the criteria.\n"
		"\n"
		GURA_HELPTEXT_ITERATOR_en());
}

Gura_ImplementMethod(iterator, while_)
{
	Signal &sig = env.GetSignal();
	Object_iterator *pThis = Object_iterator::GetObjectThis(arg);
	Iterator *pIteratorSrc = pThis->GetIterator()->Clone();
	Iterator *pIterator = pIteratorSrc->While(env, arg.GetValue(0));
	if (sig.IsSignalled()) return Value::Nil;
	return ReturnIterator(env, arg, pIterator);
}

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_iterator::Class_iterator(Environment *pEnvOuter) : ClassFundamental(pEnvOuter, VTYPE_iterator)
{
}

void Class_iterator::DoPrepare(Environment &env)
{
	// Assignment of function
	Gura_AssignFunction(iterator);
	// Assignment of methods specific to iterator
	Gura_AssignMethod(iterator, delay);
	Gura_AssignMethod(iterator, finite);
	Gura_AssignMethod(iterator, infinite);
	Gura_AssignMethod(iterator, isinfinite);
	Gura_AssignMethod(iterator, next);
	Gura_AssignMethod(iterator, repeater);
	// Assignment of instance methods that are shared with list
	Gura_AssignMethod(iterator, after);
	Gura_AssignMethod(iterator, align);
	Gura_AssignMethod(iterator, and_);
	Gura_AssignMethod(iterator, argmax);
	Gura_AssignMethod(iterator, argmin);
	Gura_AssignMethod(iterator, before);
	Gura_AssignMethod(iterator, contains);
	Gura_AssignMethod(iterator, count);
	Gura_AssignMethod(iterator, cycle);
	Gura_AssignMethod(iterator, each);
	Gura_AssignMethod(iterator, filter);
	Gura_AssignMethod(iterator, find);
	Gura_AssignMethod(iterator, flatten);
	Gura_AssignMethod(iterator, fold);
	Gura_AssignMethod(iterator, format);
	Gura_AssignMethod(iterator, head);
	Gura_AssignMethod(iterator, join);
	Gura_AssignMethod(iterator, joinb);
	Gura_AssignMethod(iterator, len);
	Gura_AssignMethod(iterator, map);
	Gura_AssignMethod(iterator, max);
	Gura_AssignMethod(iterator, mean);
	Gura_AssignMethod(iterator, min);
	Gura_AssignMethod(iterator, nilto);
	Gura_AssignMethod(iterator, offset);
	Gura_AssignMethod(iterator, or_);
	Gura_AssignMethod(iterator, pack);
	Gura_AssignMethod(iterator, pingpong);
	Gura_AssignMethod(iterator, print);
	Gura_AssignMethod(iterator, println);
	Gura_AssignMethod(iterator, printf);
	Gura_AssignMethod(iterator, prod);
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
	Gura_AssignMethod(iterator, std);
	Gura_AssignMethod(iterator, sum);
	Gura_AssignMethod(iterator, tail);
	Gura_AssignMethod(iterator, until);
	Gura_AssignMethod(iterator, var);
	Gura_AssignMethod(iterator, while_);
	// help document
	AddHelpTemplate(env, Gura_Symbol(en), helpDoc_en);
}

bool Class_iterator::CastFrom(Environment &env, Value &value, ULong flags)
{
	Signal &sig = GetSignal();
	Iterator *pIterator = value.CreateIterator(sig);
	if (pIterator != nullptr) {
		value = Value(new Object_iterator(env, pIterator));
		return true;
	}
	return false;
}

Object *Class_iterator::CreateDescendant(Environment &env, Class *pClass)
{
	GURA_ERROREND(env, "this function must not be called");
	return nullptr;
}

}
