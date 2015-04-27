# Mapping Process

## About This Chapter

This chapter explains about Gura's mapping process, Implicit Mapping and Member Mapping.
In the documentation, following terms are used to describe species of values.

* scalar &mdash; an instance of any type except for `list` and `iterator`
* list &mdash; an instance of `list`
* iterator &mdash; an instance of `iterator`
* iterable &mdash; list or iterator

## Implicit Mapping

### Overview

**Implicit Mapping** is a feature that evaluates a function or an operator repeatedly
when it's given with a list or an iterator.

A function that is capable of Implicit Mapping is marked with an attribute `:map`.
Consider a function `f(n:number):map` that takes a number value and returns a squared number of it.
You can call it like `f(3)`, which is expected to return a number `9`.
Here, using Implicit Mapping, you can call it with a list of numbers like below:

    f([2, 3, 4])

This will result in a list `[4, 9, 16]` after evaluating each number in the list.

Implicit Mapping also works with operators.
The example below applies an operation that adds three to each value in the list using Implicit Mapping:

    [2, 3, 4] + 3

This will result in `[5, 6, 7]`.
Of course, you can also apply Implicit Mapping on an operation between two lists.
See the following example:

    [2, 3, 4] + [3, 4, 5]

As you might expect, it returns a list `[5, 7, 9]`.

The above example may just look like a vector calculation.
Actually, this type of operation,
which applies some operations on a set of numbers at once,
is known as "vectorization", and has been implemented in languages and libraries
that compute vectors and matrices.

Implicit Mapping enhances that idea so that it has the following capabilities:

1. Implicit Mapping can handle any type of objects other than number.

   Consider a function `g(str:string):map` that takes a string and returns a result
   after converting alphabet characters in the string to upper case.
   When you call it with a single value, it will return one result.

        str = 'hello'
        x = g(str)
        // x is 'HELLO'

   You can call it with a list of string
   to get a list of results by using Implicit Mapping feature.

        strs = ['hello', 'Gura', 'world']
        x = g(strs)
        // x is ['HELLO', 'GURA', 'WORLD']

2. Implicit Mapping can operate with an iterator as well.

   Consider the function `g(str:string):map` that has been mentioned above.
   If you call it with an iterator, it will return an iterator as its result.
   
        strs = ('hello', 'Gura', 'world') // creates an iterator
        x = g(strs)
        // x is an iterator that equivalent with ('HELLO', 'GURA', 'WORLD')
   
   It means that the actual evaluation of the function `g()` will be postponed
   by the time when the created iterator is evaluated or destroyed.
   This is important because using an iterator will enable you to
   avoid unnecessary calculation and memory consumption.

3. You can use Implicit Mapping to repeat a function call without an explicit repeat procedure.

   A built-in function `println():map` prints a content of the given value
   before putting out a line-feed.
   Consider a case that you need to print each value in the list `strs`
   that contains `['hello', 'Gura', 'world']`.
   With an ordinary idea, you may use `for()` to process each item in a list.

        for (str in strs) {
            println(str)
        }

   Using Implicit Mapping, you can simply do it like below:

        println(strs)

4. Implicit Mapping can work on any number of lists and iterators
   given in an argument list of a function call.
   
   Consider that there's a function `f(a:string, b:number, c:string):map`,
   and you give it lists as its arguments like below:

        as = ['first', 'second', 'third', 'fourth']
        bs = [1, 2, 3, 4]
        cs = ['one', 'two', 'three', 'four']
        f(as, bs, cs)

   This has the same effect as below:

        f('first', 1, 'one')
        f('second', 2, 'two')
        f('third', 3, 'three')
        f('fourth', 4, 'four')


### Mapping Rule with Operator

Implicit Mapping works on most of the operators even though there are several exceptions.
In the description below, a symbol `o` is used to represent a certain operator.

With a Prefixed Unary Operator,
species of the result is the same as that of the given value.
Below is a summary table:

Operation    | Result
-------------|----------------
`o scalar`   | scalar
`o list`     | list
`o iterator` | iterator

Examples are shown below:

Example                      | Result
-----------------------------|------------------------------------------
`!true`                      | `false`
`![true, true, false, true]` | `[false, false, true, false]`
`!(true, true, false, true)` | `(false, false, true, false)`

With a Suffixed Unary Operator,
species of the result is the same as that of the given value.
Below is a summary table:

Operation    | Result
-------------|----------------
`scalar o`   | scalar
`list o`     | list
`iterator o` | iterator

With a Binary Operator, the folloiwing rules are applied.

* If both of left and right values are of scalar species, the result becomes a scalar.
* If either of left or right value is of iterator species, the result becomes an iterator.
* Otherwise, the result becomes a list.

Below is a summary table:

Operation             | Result
----------------------|----------------
`scalar o scalar`     | scalar
`scalar o list`       | list
`scalar o iterator`   | iterator
`list o scalar`       | list
`list o list`         | list
`list o iterator`     | iterator
`iterator o scalar`   | iterator
`iterator o list`     | iterator
`iterator o iterator` | iterator

If both of left and right values are iterable and they have different length,
Implicit Mapping would be applied on a range of a shorter length.

Some operators expect lists or iterators in their own operations
and inhibit Implicit Mapping. See the table below:

Operation|Note
---------|--------------------------------------------------------------
`x?`     | It deters Implicit Mapping because it needs to check if `x` itself can be determined as `true` or not.
`x*`     | It expects `x` may take an iterator or a list.
`x * y` where `x` is `function` | It may take a list as a value of `y`.
`x % y` where `x` is `string`   | It may take a list as a value of `y`.
`x in y` | It expects `x` and `y` may take list values.
`x => y` | It expects `y` may take a list value.


### Mapping Rule with Function

A function with `:map` attribute in its declaration is capable of Implicit Mapping.

Here are function definitions that return a square value of the given number
to see the effect of `:map` attribute.

    f_nomap(x:number) = x * x
    f_map(x:number):map = x * x

The function delcared with `:map` attribute is capable of Implicit Mapping
and can take a list for an argument that expects a `number` value.

    f_nomap([1, 2, 3]) // Error
    f_map([1, 2, 3])   // Implicit Mapping works on each item and returns [1, 4, 9]

As for a function `f(x):map` that takes one argument,
the mapping rule is the same as that of Unary Operator.
See the following summary table:

Operation     | Result
--------------|----------------
`f(scalar)`   | scalar
`f(list)`     | list
`f(iterator)` | iterator

A function `f(x, y):map` that takes two arguments behaves in the same manner with Binary Operator.
Below is a summary table:

Operation               | Result
------------------------|----------------
`f(scalar, scalar)`     | scalar
`f(scalar, list)`       | list
`f(scalar, iterator)`   | iterator
`f(list, scalar)`       | list
`f(list, list)`         | list
`f(list, iterator)`     | iterator
`f(iterator, scalar)`   | iterator
`f(iterator, list)`     | iterator
`f(iterator, iterator)` | iterator

In general, if a function takes more than one argument, the following rules are appplied.

* If all of the argument values are of scalar species, the result becomes a scalar.
* If one of the argument values is of iterator species, the result becomes an iterator.
* Otherwise, the result becomes a list.

Here are some example cases with a function `f(x, y, z):map`:

Operation                      | Result
-------------------------------|----------------
`f(scalar, scalar, sholar)`    | scalar
`f(scalar, scalar, list)`      | list
`f(scalar, scalar, iterator)`  | iterator
`f(scalar, list, iterator)`    | iterator

If an argument list contains iterables that have different length each other,
Implicit Mapping would be applied on a range of the shortest length.
For example, the code below repeats the process three times.

    f([1, 2, 3], ['a', 'b', 'c', 'd'], [4, 5, 6])

Implicit Mapping does not work with arguments that match the following case:

* If a function contains an argument that expects `list` or `iterator`,
  Implicit Mapping would not work with that argument.
  In the following example, putting a list or an iterator to argument `z`,
  which expects a list or an iterator as its value, is not considered as
  a criteria for Implicit Mapping.

        f(x, y, z:list):map     = { /* body */ }
        f(x, y, z:iterator):map = { /* body */ }
        f(x, y, z[]):map        = { /* body */ }

* Putting an attribute `:nomap` to an argument declaration
  would exclude it from Implicit Mapping criteria.
  In the example below, specifying a list or an iterator to argument `z` is
  not considered as a criteria for Implicit Mapping.

        f(x, y, z:nomap):map = { /* body */ }


### Result Control on List

Consider a function `f(n:number):map` that is defined as below:

    f(n:number):map = println('n = ', n)

It takes a number value and just prints it.

    f(3)  // prints 'n = 3'

Here, function `println()` is defined with an attribute `:void`
that is meant to always return `nil` as its result.
So, the function `f()` that evaluates `println()` at last would return `nil` as well.

As the function `f()` is capable of Implicit Mapping,
you can call it with a list for repeating process.

    f([1, 2, 3])  // prints 'n = 1', 'n = 2' and 'n = 3'

As you've already seen above,
when a function with `:map` attribute takes a list,
it will evaluate each value in the list immediately and returns a list containing the results.
Considering that rule, you may think the calling it as above could return `[nil, nil, nil]`.

But, in reality, it returns a single `nil`.

Implicit Mapping is designed to work as a generic repeating mechanism.
If a function is expected to always return some meaningless value such as `nil`,
creating a list that contains such values through a repeating process
absolutely makes no sense.
To avoid that vain process, Implicit Mapping would only create a list
when a valid value appears in the result.

Consider a function below that simply returns the given value as its result.

    g(n):map = n

The table below summarizes what result you get from `g()`
when it's given with a list containing valid and `nil` values.

Script                        | Result
------------------------------|----------------------------
`g([])`                       | `[]`
`g([nil])`                    | `nil`
`g([nil, nil])`               | `nil`
`g([nil, nil, 3])`            | `[nil, nil, 3]`
`g([nil, nil, 3, 5])`         | `[nil, nil, 3, 5]`
`g([nil, nil, 3, 5, 3])`      | `[nil, nil, 3, 5, 3]`
`g([nil, nil, 3, 5, 3, nil])` | `[nil, nil, 3, 5, 3, nil]`

Note that, when you give an empty list to a function with Implicit Mapping,
it would return an empty list as its result.

There are some attributes that control how Implicit Mapping generates the result
even when it's expected to generate a list by default.

* Attribute `:list` always creates a list even if it only contains `nil` values.

  Script                             | Result
  -----------------------------------|----------------------------
  `g([]):list`                       | `[]`
  `g([nil]):list`                    | `[nil]`
  `g([nil, nil]):list`               | `[nil, nil]`
  `g([nil, nil, 3]):list`            | `[nil, nil, 3]`
  `g([nil, nil, 3, 5]):list`         | `[nil, nil, 3, 5]`
  `g([nil, nil, 3, 5, 3]):list`      | `[nil, nil, 3, 5, 3]`
  `g([nil, nil, 3, 5, 3, nil]):list` | `[nil, nil, 3, 5, 3, nil]`

* Attribute `:xlist` always creates a list after excluding `nil` value from the result.

  Script                              | Result
  ------------------------------------|----------------------------
  `g([]):xlist`                       | `[]`
  `g([nil]):xlist`                    | `[]`
  `g([nil, nil]):xlist`               | `[]`
  `g([nil, nil, 3]):xlist`            | `[3]`
  `g([nil, nil, 3, 5]):xlist`         | `[3, 5]`
  `g([nil, nil, 3, 5, 3]):xlist`      | `[3, 5, 3]`
  `g([nil, nil, 3, 5, 3, nil]):xlist` | `[3, 5, 3]`

* Attribute `:set` always creates a list after excluding duplicated values.

  Script                            | Result
  ----------------------------------|----------------------------
  `g([]):set`                       | `[]`
  `g([nil]):set`                    | `[nil]`
  `g([nil, nil]):set`               | `[nil]`
  `g([nil, nil, 3]):set`            | `[nil, 3]`
  `g([nil, nil, 3, 5]):set`         | `[nil, 3, 5]`
  `g([nil, nil, 3, 5, 3]):set`      | `[nil, 3, 5]`
  `g([nil, nil, 3, 5, 3, nil]):set` | `[nil, 3, 5]`

* Attribute `:xset` always creates a list after excluding `nil` and duplicated values.

  Script                             | Result
  -----------------------------------|----------------------------
  `g([]):xset`                       | `[]`
  `g([nil]):xset`                    | `[]`
  `g([nil, nil]):xset`               | `[]`
  `g([nil, nil, 3]):xset`            | `[3]`
  `g([nil, nil, 3, 5]):xset`         | `[3, 5]`
  `g([nil, nil, 3, 5, 3]):xset`      | `[3, 5]`
  `g([nil, nil, 3, 5, 3, nil]):xset` | `[3, 5]`

* Attribute `:iter` creates an iterator.

  Script                             | Result
  -----------------------------------|----------------------------
  `g([]):iter`                       | equivalent of `[].each()`
  `g([nil]):iter`                    | equivalent of `(nil,)`
  `g([nil, nil]):iter`               | equivalent of `(nil, nil)`
  `g([nil, nil, 3]):iter`            | equivalent of `(nil, nil, 3)`
  `g([nil, nil, 3, 5]):iter`         | equivalent of `(nil, nil, 3, 5)`
  `g([nil, nil, 3, 5, 3]):iter`      | equivalent of `(nil, nil, 3, 5, 3)`
  `g([nil, nil, 3, 5, 3, nil]):iter` | equivalent of `(nil, nil, 3, 5, 3, nil)`

* Attribute `:xiter` creates an iterator that excludes `nil` value from the result.

  Script                              | Result
  ------------------------------------|----------------------------
  `g([]):xiter`                       | equivalent of `[].each()`
  `g([nil]):xiter`                    | equivalent of `[].each()`
  `g([nil, nil]):xiter`               | equivalent of `[].each()`
  `g([nil, nil, 3]):xiter`            | equivalent of `(3,)`
  `g([nil, nil, 3, 5]):xiter`         | equivalent of `(3, 5)`
  `g([nil, nil, 3, 5, 3]):xiter`      | equivalent of `(3, 5, 3)`
  `g([nil, nil, 3, 5, 3, nil]):xiter` | equivalent of `(3, 5, 3)`

* Attribute `:void` indicates the function always returns `nil`
  regardless of its original result.

  Script                             | Result
  -----------------------------------|----------------------------
  `g([]):void`                       | `nil`
  `g([nil]):void`                    | `nil`
  `g([nil, nil]):void`               | `nil`
  `g([nil, nil, 3]):void`            | `nil`
  `g([nil, nil, 3, 5]):void`         | `nil`
  `g([nil, nil, 3, 5, 3]):void`      | `nil`
  `g([nil, nil, 3, 5, 3, nil]):void` | `nil`

* Attribute `:reduce` indicates the function returns the last evaluated value
  and doesn't create a list.

  Script                               | Result
  -------------------------------------|----------------------------
  `g([]):reduce`                       | `nil`
  `g([nil]):reduce`                    | `nil`
  `g([nil, nil]):reduce`               | `nil`
  `g([nil, nil, 3]):reduce`            | `3`
  `g([nil, nil, 3, 5]):reduce`         | `5`
  `g([nil, nil, 3, 5, 3]):reduce`      | `3`
  `g([nil, nil, 3, 5, 3, nil]):reduce` | `nil`

* Attribute `:xreduce` indicates the function returns the last evaluated value
  and doesn't create a list. The returned value is updated only when the result is valid.

  Script                                | Result
  --------------------------------------|----------------------------
  `g([]):xreduce`                       | `nil`
  `g([nil]):xreduce`                    | `nil`
  `g([nil, nil]):xreduce`               | `nil`
  `g([nil, nil, 3]):xreduce`            | `3`
  `g([nil, nil, 3, 5]):xreduce`         | `5`
  `g([nil, nil, 3, 5, 3]):xreduce`      | `3`
  `g([nil, nil, 3, 5, 3, nil]):xreduce` | `3`


### Result Control on Iterator

Consider a function below that simply returns the given value as its result.

    g(n):map = n

When you give it an iterator,
it would return an iterator as well following after Implicit Mapping rule.

Script                        | Result
------------------------------|----------------------------
`g([].each())`                | equivalent of `[].each()`
`g((nil,))`                   | equivalent of `(nil,)`
`g((nil, nil))`               | equivalent of `(nil, nil)`
`g((nil, nil, 3))`            | equivalent of `(nil, nil, 3)`
`g((nil, nil, 3, 5))`         | equivalent of `(nil, nil, 3, 5)`
`g((nil, nil, 3, 5, 3))`      | equivalent of `(nil, nil, 3, 5, 3)`
`g((nil, nil, 3, 5, 3, nil))` | equivalent of `(nil, nil, 3, 5, 3, nil)`

There are some attributes that control how Implicit Mapping generates the result
even when it's expected to generate an iterator by default.

* Attribute `:list` creates a list.

  Script                             | Result
  -----------------------------------|----------------------------
  `g([].each()):list`                | `[]`
  `g((nil,)):list`                   | `[nil]`
  `g((nil, nil)):list`               | `[nil, nil]`
  `g((nil, nil, 3)):list`            | `[nil, nil, 3]`
  `g((nil, nil, 3, 5)):list`         | `[nil, nil, 3, 5]`
  `g((nil, nil, 3, 5, 3)):list`      | `[nil, nil, 3, 5, 3]`
  `g((nil, nil, 3, 5, 3, nil)):list` | `[nil, nil, 3, 5, 3, nil]`

* Attribute `:xlist` creates a list after excluding `nil` value from the result.

  Script                              | Result
  ------------------------------------|----------------------------
  `g([].each()):xlist`                | `[]`
  `g((nil,)):xlist`                   | `[]`
  `g((nil, nil)):xlist`               | `[]`
  `g((nil, nil, 3)):xlist`            | `[3]`
  `g((nil, nil, 3, 5)):xlist`         | `[3, 5]`
  `g((nil, nil, 3, 5, 3)):xlist`      | `[3, 5, 3]`
  `g((nil, nil, 3, 5, 3, nil)):xlist` | `[3, 5, 3]`

* Attribute `:set` creates a list after excluding duplicated values.

  Script                            | Result
  ----------------------------------|----------------------------
  `g([].each()):set`                | `[]`
  `g((nil,)):set`                   | `[nil]`
  `g((nil, nil)):set`               | `[nil]`
  `g((nil, nil, 3)):set`            | `[nil, 3]`
  `g((nil, nil, 3, 5)):set`         | `[nil, 3, 5]`
  `g((nil, nil, 3, 5, 3)):set`      | `[nil, 3, 5]`
  `g((nil, nil, 3, 5, 3, nil)):set` | `[nil, 3, 5]`

* Attribute `:xset` creates a list after excluding `nil` and duplicated values.

  Script                             | Result
  -----------------------------------|----------------------------
  `g([].each()):xset`                | `[]`
  `g((nil,)):xset`                   | `[]`
  `g((nil, nil)):xset`               | `[]`
  `g((nil, nil, 3)):xset`            | `[3]`
  `g((nil, nil, 3, 5)):xset`         | `[3, 5]`
  `g((nil, nil, 3, 5, 3)):xset`      | `[3, 5]`
  `g((nil, nil, 3, 5, 3, nil)):xset` | `[3, 5]`

* Attribute `:iter` creates an iterator.
  This is a default behavior of Implicit Mapping for an iterator.

* Attribute `:xiter` creates an iterator that excludes `nil` value from the result.

  Script                              | Result
  ------------------------------------|----------------------------
  `g([].each()):xiter`                | equivalent of `[].each()`
  `g((nil,)):xiter`                   | equivalent of `[].each()`
  `g((nil, nil)):xiter`               | equivalent of `[].each()`
  `g((nil, nil, 3)):xiter`            | equivalent of `(3,)`
  `g((nil, nil, 3, 5)):xiter`         | equivalent of `(3, 5)`
  `g((nil, nil, 3, 5, 3)):xiter`      | equivalent of `(3, 5, 3)`
  `g((nil, nil, 3, 5, 3, nil)):xiter` | equivalent of `(3, 5, 3)`

* Attribute `:void` indicates the function will always return `nil`
  regardless of its original result.

  Script                             | Result
  -----------------------------------|----------------------------
  `g([].each()):void`                | `nil`
  `g((nil,)):void`                   | `nil`
  `g((nil, nil)):void`               | `nil`
  `g((nil, nil, 3)):void`            | `nil`
  `g((nil, nil, 3, 5)):void`         | `nil`
  `g((nil, nil, 3, 5, 3)):void`      | `nil`
  `g((nil, nil, 3, 5, 3, nil)):void` | `nil`

* Attribute `:reduce` indicates the function returns the last evaluated value
  and doesn't create an iterator.

  Script                               | Result
  -------------------------------------|----------------------------
  `g([].each()):reduce`                | `nil`
  `g((nil)):reduce`                    | `nil`
  `g((nil, nil)):reduce`               | `nil`
  `g((nil, nil, 3)):reduce`            | `3`
  `g((nil, nil, 3, 5)):reduce`         | `5`
  `g((nil, nil, 3, 5, 3)):reduce`      | `3`
  `g((nil, nil, 3, 5, 3, nil)):reduce` | `nil`

* Attribute `:xreduce` indicates the function returns the last evaluated value
  and doesn't create an iterator. The returned value is updated only when the result is valid.

  Script                                | Result
  --------------------------------------|----------------------------
  `g([].each()):xreduce`                | `nil`
  `g((nil)):xreduce`                    | `nil`
  `g((nil, nil)):xreduce`               | `nil`
  `g((nil, nil, 3)):xreduce`            | `3`
  `g((nil, nil, 3, 5)):xreduce`         | `5`
  `g((nil, nil, 3, 5, 3)):xreduce`      | `3`
  `g((nil, nil, 3, 5, 3, nil)):xreduce` | `3`

An iterator created by Implicit Mapping has a special feature;
it will be evaluated automatically when it's destroyed.
Consider the following function:

    f(n:number):map = println('n = ', n)

And call it as below:

    f((3, 1, 4))

In Implicit Mapping rule, the call above would simply return an iterator
and is supposed not do any process unless the iterator is actually evaluated.
But usually, the above case is expected to print values in the iterator
at the timing of the function call.

Actually, the code above works as expected
because the returned iterator loses any reference from others
and is evaluated before destroyed.
The script below shows what happens in the above.

    x = f((3, 1, 4))
    x = nil  // iterator is destroyed after printing 'n = 3', 'n = 1' and 'n = 4'.

However, the timing to destroy an instance is sometimes unpredictable.
It's recommended that you specify `:void` attribute for an instant evaluation.

    f((3, 1, 4)):void

Attributes `:void`, `:reduce` and `:xreduce` don't return an iterator,
which cause the actual process on given values done immediately.

It may be the best that you specify `:void`, `:reduce` or `:xreduce` attribute in the function definition
if you know beforehand that the function always returns `nil` or other unchanged value.

    f(n:number):map:void = println('n = ', n)

Then, you can call the function with an iterator through Implicit Mapping
without any worry.

    f((3, 1, 4))


### Suspend Implicit Mapping

A function call with an attribute `:nomap` would suspend Implicit Mapping.

Consider a case that you need to print a content of `x` that contains `[1, 2, 3, 4]` as a list instance.
Simply executing `println(x)` would just print each value in the list through Implicit Mapping.
To avoid it, put `:nomap` for the call as below.

    println(x):nomap


## Member Mapping

### Overview

**Member Mapping** is a feature to access members of instances
that are stored in a list or are generated from an iterator.

There's an instance method `string#len()` that retrieves a length of a string.
With a single instance, you can call it like below:

    x = 'first'
    n = x.len()
    // n is 5

Using a member accessor `::`, you can apply the method on multiple instances in a list.

    xs = ['first', 'second', 'third', 'fourth']
    ns = xs::len()
    // ns is [5, 6, 5, 6]

A member accessor `:*` creates an iterator that gets results of member access.

    xs = ['first', 'second', 'third', 'fourth']
    ns = xs:*len()
    // ns is an iterator that generates (5, 6, 5, 6)


### Mapping Rule

There are three member accessors in Member Mapping as shown below:

Member Accessor |Name
----------------|------------------
`::`            |map-to-list
`:*`            |map-to-iterator
`:&`            |map-along

A map-to-list accessor `::` applies a member method or looks up a member variable
on instances in an iterable, a list or an iterator, and creates a list of the results.
Below shows examples:

    xs::variable
    xs::func()

A map-to-iterator accessor `:*` creates an iterator that applies a member method or looks up a member variable
on instances in an iterable, a list or an iterator.
Below shows examples:

    xs:*variable
    xs:*func()

A map-along accessor `:&` only has effect with a member method.
It iterates the iterable on the left along with iterables in its argument list
following after Iterator Mapping rule.
See the following example:

    xs = [x1, x2, x3]
    as = ['first', 'second', 'third']
    bs = [3, 1, 4]
    xs:&func(as, bs)

This has the same effect with shown below:

    [x1.func('first', 3), x2.func('second', 1), x3.func('third', 4)]

The mapping rule with map-along accessor is summarized below:

* If the target iterable or one of the argument values is of iterator species,
  the result becomes an iterator.
* Otherwise, the result becomes a list.
