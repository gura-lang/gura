# {{ page.chapter }}. Iterator/List Operation

## {{ page.chapter }}.1. Overview

An iterator and a list are quite similar in terms of
handling multiple values in a flat structure.
In fact, many of their methods share the same names and functions each other.

The difference is that a list is a container that actually owns its element values
while an iterator only provides a method that retrieves a "next" value of a sequence
and doesn't necessarily have to own values.
This feature leads to the following principles:

* An iterator can handle a sequence of data that continues indefinitely
  because it doesn't need to keep all the values in it.
* An iterator consumes less memory than a list in many cases.
* A list provides an indexing method that enables random access for its elements.
* A list provides methods to append or remove values.

Note that Gura makes it a rule to implement most functions to return an iterator by default
if they have multiple values as its result.
Even with such functions, you can easily get a list as their result
by calling it with `:list` attribute.


## {{ page.chapter }}.2. Iteration on Iterators and Lists

Consider a task that prints elements in the list shown below:

    words = ['one', 'two', 'three', 'four', 'five', 'six', 'seven', 'eight', 'nine', 'ten']

There are several ways to iterate elements in an iterator or a list.

* As you've already seen a previous chapter,
  iterators and lists can work with functions, methods and operators through Implicit Mapping.
  You can simply call `printf()` function with iterators or lists
  that causes a repetitive evaluation of the function.

        printf('%s\n', words)

  A function with Implicit Mapping is capable of iterating multiple iterables provided as its arguments.
  In addition to the list of words, you can specify an iterator
  that generates numbers starting from zero to print indexing numbers as shown below.

        printf('%d: %s\n', 0.., words)

* Using `for()` function, you can iterate a list or an iterator
  in a way that you may have been familiar with in other languages.

        for (word in words) {
            printf('%s\n', word)
        }

  You can get a loop index starting from zero by specifying a block parameter.

        for (word in words) {|i|
            printf('%d: %s\n', i, word)
        }

* You can also use method `iterator#each()` or `list#each()` to iterate elements on them.
  In this case, the block parameter contains an iterated element as its first value.

        words.each {|word|
            printf('%s\n', word)
        }
  
  It provides a loop index as the second value in the block parameters as below.

        words.each {|word, i|
            printf('%d: %s\n', i, word)
        }

Most functions and methods that return an iterator as their result
are designed to iterate elements when they take a block.
Actually, methods `iterator#each()` and `list#each()`, which are mentioned above,
simply return an iterator when they're called without a block.

    rtn = words.each()
    // rtn is an iterator that iterates each element in words

To see other examples that have the same feature,
consider methods `iterator#filter()` and `list#filter()`,
which returns an iterator that pick up elements satisfying a criteria specified in the argument.

    rtn = words.filter(&{$word.startswith('t')})
    // rtn is an iterator that generates 'two', 'three' and 'ten'

Specifying a block with the method would repetitively evaluate it
while iterating elements of the result.

    words.filter(&{$word.startswith('t')}) {|word, i|
        printf('%d: %s\n', i, word)
    }

The result comes as below:

    0: two
    1: three
    2: ten


## {{ page.chapter }}.3. Iterator-specific Manipulation

### {{ page.chapter }}.3.1. About This Section

This section explains about methods and ohter manipulation that are specific to iterators.


### {{ page.chapter }}.3.2. Finite Iterator vs. Infinite Iterator

Iterators that generate a limited numer of elements are called Finite Iterator.
An iterator `0..5` is a representative one that is definitely expected to generate 6 elements.
It's possible that you convert a Finite Iterator into a list.

Iterators that generate elements indefinitely
or couldn't predict when elements drain out are called Infinite Iterator.
Among them, there's an iterator `0..` that generates numbers starting from 0 and increasing for ever.
It would occur an error if you try to convert Infinite Iterator into a list.

You can use method `iterator#isinfinite()` to check if an iterator is an infinite one or not.

    (0..5).isinfinite()  // returns false
    (0..).isinfinite()   // returns true

Some functions may possibly create either Finite or Infinite Iterator depending on their arguments.
The second argument in function `rands()` specify how many random values it should generate,
and, if omitted, the function would generate values without end.

    rands(100)     // returns an Infinite Iterator
    rands(100, 80) // returns a Finite Iterator that is expected to generate 80 elements

Infinity of the result of function `readlines()` depends on the attribute of the source stream:
it would be an Infinite Iterator if the stream is infinite
while it would be a Finite Iterator for a finite stream.

An iterator's infinity may be derived from one to another.
This happens with iterators that are designed to manipulate values
after retrieving them from other source iterator.
For example, method `iterator#filter()` returns an iterator that picks up elements
based on the given criteria. In the following code, `y` is a Finite Iterator
that generates numbers 0, 2, 4, 6, 8 and 10.

    tbl = 0..10
    rtn = tbl.filter(&{$x % 2 == 0})
    // rtn is finite

If the source iterator is infinite, the result iterator will be infinite too.
In the code below, `y` is an Infinite Iterator that generates even numbers indefinitely.

    tbl = 0..
    rtn = tbl.filter(&{$x % 2 == 0})
    // rtn is infinite


### {{ page.chapter }}.3.3. Conversion into List

Embracing iterators with a pair of square brackets would make a list from them.

    [0..5]               // creates [0, 1, 2, 3, 4, 5]

You can specify any numbers of iterators in it as below.

    [0..2, 5..7, 8..10]  // creates [0, 1, 2, 5, 6, 7, 8, 9, 10]

It would occur an error if you try to create a list from Infinite Iterators.

    [0..]                // error!

Another way to create a list from an iterator is to use `iterator#each()` method with `:list` attribute.

    tbl = 0..5
    tbl.each():list      // returns [0, 1, 2, 3, 4, 5]


### {{ page.chapter }}.3.4. Operation on Elements

You can retrieve elements from an iterator by using method `iterator#next()`.

    tbl = 0..5
    tbl.next()   // returns 0
    tbl.next()   // returns 1
    tbl.next()   // returns 2


## {{ page.chapter }}.4. List-specific Manipulation

### {{ page.chapter }}.4.1. About This Section

This section explains about methods and ohter manipulation that are specific to lists.


### {{ page.chapter }}.4.2. Indexing Read from List

You can specify an index number starting from zero embraced by a pair of square brackets
to retrieve an element at the specified position.
Multiple numbers for indexing can also be specified to get a list of elements.

    tbl = ['zero', 'one', 'two', 'three', 'four', 'five', 'six', 'seven']
    tbl[2]        // returns 'two'
    tbl[4]        // returns 'four'
    tbl[1, 3, 5]  // returns ['one', 'three', 'five']

You can also specify iterators and lists to get a list of elements.
Numbers and iterators can be mixed together as indexing items.

    tbl = ['zero', 'one', 'two', 'three', 'four', 'five', 'six', 'seven']
    tbl[2..4]        // returns ['two', 'three', 'four']
    tbl[1..3, 5..7]  // returns ['one', 'two', 'three', 'five', 'six', 'seven']

If you specify an infinite iterator as an indexing item,
you would get elements within an available range.

    tbl = ['zero', 'one', 'two', 'three', 'four', 'five', 'six', 'seven']
    tbl[5..]        // returns ['five', 'six', 'seven']

An index with a negative number points the position from the bottom,
where `-1` is the last position.

    tbl = ['zero', 'one', 'two', 'three', 'four', 'five', 'six', 'seven']
    tbl[-1]         // returns 'seven'
    tbl[-2]         // returns 'six'

Method `list#first()` returns the first item in the list
and method `list#last()` the last item.
These have the same effect with index accesses by numbers 0 and -1 respectively.

    tbl = ['zero', 'one', 'two', 'three', 'four', 'five', 'six', 'seven']
    tbl.first()     // returns 'zero'
    tbl.last()      // returns 'seven'

You can use method `list#get()` for index access,
which would be useful when used with Member Mapping.

    tbl = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
    tbl::get(0)     // returns [1, 4, 7]


### {{ page.chapter }}.4.3. Indexing Modification on List

An assignment to elements in a list through indexing access is also available.

If an indexing item is a single number, the element at the specified position will be modified.

    tbl = ['zero', 'one', 'two', 'three', 'four', 'five', 'six', 'seven']
    tbl[2] = '2'
    tbl[4] = '4'
    // tbl is ['zero', 'one', '2', 'three', '4', 'five', 'six', 'seven']

Multiple numbers can also be specified for indexing.
In this case, if the assigned value is an iterable,
each element in the iterable will be stored at the specified positions in the target list.

    tbl = ['zero', 'one', 'two', 'three', 'four', 'five', 'six', 'seven']
    tbl[1, 3, 5] = ['1', '3', '5']
    // tbl is ['zero', '1', 'two', '3', 'four', '5', 'six', 'seven']

If the assigned value is a scalar, the same value is stored at the positions.

    tbl = ['zero', 'one', 'two', 'three', 'four', 'five', 'six', 'seven']
    tbl[1, 3, 5] = '1'
    // tbl is ['zero', '1', 'two', '1', 'four', '1', 'six', 'seven']

You can also specify an iterator as indexing item.

    tbl = ['zero', 'one', 'two', 'three', 'four', 'five', 'six', 'seven']
    tbl[1..3, 5..7] = ['1', '2', '3', '5', '6', '7']
    // tbl is ['zero', '1', '2', '3', 'four', '5', '6', '7']

When you specify an Infinite Iterator for an indexing item,
all the elements in the assigned iterable are stored at the specified position.

    tbl = ['zero', 'one', 'two', 'three', 'four', 'five', 'six', 'seven']
    tbl[5..] = ['5', '6']
    // tbl is ['zero', 'one', 'two', 'three', 'four', '5', '6', 'seven']

Negative number can also be specified for indexing.

    tbl = ['zero', 'one', 'two', 'three', 'four', 'five', 'six', 'seven']
    tbl[-1] = '7'
    tbl[-2] = '6'
    // tbl is ['zero', 'one', 'two', 'three', 'four', 'five', '6', '7']


You can use method `list#put()` for index modification,
which would be useful when used with Member Mapping.

    tbl = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
    tbl::put(2, 99)
    // tbl is [[1, 2, 99], [4, 5, 99], [7, 8, 99]]


### {{ page.chapter }}.4.4. Conversion into Iterator

Method `list#each()` returns an iterator that generates values based on the list's elements.

    tbl = ['one', 'two', 'three', 'four']
    rtn = tbl.each()
    // rtn is an iterator that generates 'one', 'two', 'three' and 'four'.


### {{ page.chapter }}.4.5. Operation on Elements

Method `list#isempty()` will check if a list is empty or not.

    tbl = []
    tbl.isempty()    // returns true

Both of methods `list#add()` and `list#append()` will add values to the target list.
They have the same behavior when they try to add a scalar value.
Below is a sample of `list#add()`:

    tbl = ['one', 'two', 'three']
    tbl.add('four')
    // tbl is ['one', 'two', 'three', 'four']

And a sample of `list#append()` is shown below:

    tbl = ['one', 'two', 'three']
    tbl.append('four')
    // tbl is ['one', 'two', 'three', 'four']

They have different results when they're given with a list as an element to add.
Method `list#add()` adds the list itself to the target list as one of its elements.

    tbl = ['one', 'two', 'three']
    tbl.add(['four', 'five', 'six'])
    // tbl is ['one', 'two', 'three', ['four', 'five', 'six']]

Method `list#append()` adds each of the list's element to the target list.

    tbl = ['one', 'two', 'three']
    tbl.append(['four', 'five', 'six'])
    // tbl is ['one', 'two', 'three', 'four', 'five', 'six']

Method `list#clear()` will create all the contet of the target list.

    tbl = ['one', 'two', 'three']
    tbl.clear()
    // tbl is []

Method `list#erase()` will erase elements at positions specified by its arguments.
You can specify multiple indices at which elements are erased.

    tbl = ['zero', 'one', 'two', 'three', 'four', 'five', 'six', 'seven']
    tbl.erase(2, 4, 6)
    // tbl is ['zero', 'one', 'three', 'five', 'seven']

Method `list#shift()` erase the first element before it returns that value.

    tbl = ['one', 'two', 'three']
    rtn = tbl.shift()  // returns 'one'
    // tbl is ['two', 'three']


`list#flat()`

`list.zip()`

## {{ page.chapter }}.5. Common Manipulation for Iterator and List

### {{ page.chapter }}.5.1. About This Section

This section explains about methods that are prepared for both iterators and lists.
To make descriptions simple, a pseudo class name `iterable` is used to represent `list` or `iterator` class.
For example, `iterable#len()` is an inclusive term for `list#len()` and `iterator#len()`.

### {{ page.chapter }}.5.2. Inspection and Reduce

Method `iterable#len()` return the number of elements in the iterable.

Method `iterable#count()` takes an optional argument `criteria`
with which elements would be filtered out, and return the number of elements matching it.
The method behaves differently depends on a value given to `criteria`.

* If no value is specified for `criteria`, it would return the number of elements
  that can be determined as `true`.

        [true, false, true, true}.count()          // returns 3

* If it takes a `function`, which takes one argument and returns a boolean value,
  it would call the given function with each element's value
  and count the number of `true` returned from it.

        [3, 1, 4, 1, 5, 9, 2, 6].count(&{$x < 4}) // returns 4

* If it takes a value other than `function`, it would return the number of elements
  that equals to the given value.

        [3, 1, 4, 1, 5, 9, 2, 6].count(1)         // returns 2

Method `iterable#contains()` checks if the iterable contains the specified value in it.

    tbl = [3, 1, 4, 1, 5, 9, 2, 6]
    tbl.contains(1)  // return true
    tbl.contains(7)  // return false

Methods `iterable#and()` and `iterable#or()` calculate logical AND and OR
on the iterable's elements repectively.
It regards `false` and `nil` as a false state, and other values as a true.

    [true, true, true].and()   // returns true
    [true, false, true].and()  // returns false
    [3, 1, 4, 1, 5].and()      // returns true
    [true, false, true].or()   // returns true
    [nil, false, nil].or()     // returns false

Classes `list` and `iterator` are equipped with some statistical operations described below:

* `iterable#sum()` calculates summation of elements in the iterable.
* `iterable#average()` calculates an average of elements in the iterable.
* `iterable#stddev()` calculates a standard deviation value of elements in the iterable.
* `iterable#variance()` calculates a variance value of elements in the iterable.
* `iterable#max()` and `iterable#min()` returns maximum and minimum value in the iterable.

Method `iterable#join()` would join all the strings in the iterable and returns the result.
If an element is not a `string` instance, it would be converted to a string before joined.
It takes an optional argument that specifies a string inserted between adjacent elements.

    ['abc', 'def', 'ghi'].join()      // returns 'abcdefhij'
    ['abc', 'def', 'ghi'].join('#')   // returns 'abc#def#hij'

Method `iterable#reduce()` is a generic one to summarize information from elements.
It takes a block procedure that is evaluated for each element with block parameters `|x, accum|`,
where `x` takes each element value and `accum` the result of the previous evaluation of the block.
The initial value of `accum` is specified by the method's argument.
For example, you can use `iterable#reduce()` to implement a function that works similar with `iterable#sum()` as below.

    my_sum(iter) = iter.reduce(0) {|x, accum| x + accum }


`iterable#find()`

### {{ page.chapter }}.5.3. Mapping Method

Method `iterable#nilto()` returns an iterator
that replaces `nil` existing in the iterable into a specified value.
Note that this method doesn't modify the target list.

    rtn = [nil, 1, 2, nil, 3, 4].nilto(99)
    // rtn is an iterator that generates 99, 1, 2, 99, 3, 4.

Method `iterable#replace()` returns an iterator
that replaces elements matching to its first argument with the value of its second argument.
Note that this method doesn't modify the target list.

    rtn = [3, 1, 4, 1, 5, 9, 2, 6].replace(1, 99)
    // rtn is an iterator that generates 3, 99, 4, 99, 5, 9, 2, 6.

Method `iterable#rank()` returns an iterator
that generates ranked number for each element after sorted.
The argument `directive` specifies sorting rule,
which is described in a document of `iterable#sort()`.

    rtn = ['apple', 'grape', 'orange', 'banana'].rank()
    // rtn is an iterator that generates 0, 2, 3, 1

Method `iterable#map()` returns an iterator that applies a function on each element.
In general, you can use Implicit Mapping to get the same result with this method.

### {{ page.chapter }}.5.4. Element Manipulation

This subsection explains about methods that changes the order of elements
and extracts elements by a certain condition.

Method `iterable#align()` creates an iterator that picks up the specified number of elements from the iterable.

    rtn = [3, 1. 4, 1, 5, 9].align(3)
    // rtn is an iterator that generates 3, 1, 4.

If the specified number is more than the length of the source iterable, the rests are filled with `nil` value.

    rtn = [3, 1. 4, 1, 5, 9].align(10)
    // rtn is an iterator that generates 3, 1, 4, 1, 5, 9, nil, nil, nil, nil.

Method `iterable#fold()` creates an iterator that segments the iterable into group of lists
containing the specified number of elements.

    rtn = [3, 1, 4, 1, 5, 9, 2, 6, 5, 3].fold(3)
    // rtn is an iterator that generates [3, 1, 4], [1, 5, 9], [2, 6, 5], [3].

Method `iterable#filter()` returns an iterator that picks up elements
where the given argument `criteria`, a function or an iterable, is evaluated as `true`.

A function for `criteria` has a single argument that takes each element value
and returns `true` when it wants the value picked up.

    f(x) = x < 4
    tbl = [3, 1, 4, 1, 5, 9, 2]
    rtn = tbl.filter(f)
    // rtn is an iterator that generates 3, 1, 1, 2.

Using an anonymous function would make the code more simple.

    tbl = [3, 1, 4, 1, 5, 9, 2]
    rtn = tbl.filter(&{$x < 4})
    // rtn is an iterator that generates 3, 1, 1, 2.

Method `iterable#filter()` can also take an iterator or a list of `boolean` elements as the `criteria`.
Using this feature, you can call the function as below:

    tbl = [3, 1, 4, 1, 5, 9, 2]
    rtn = tbl.filter(tbl < 4)
    // rtn is an iterator that generates 3, 1, 1, 2.

Implicit Mapping works on the expression `tbl < 4` that creates a list `[true, true, false, true, false, false, true]`.
Then, the method picks up elements of which corresponding boolean value is `true`.

Method `iterable#skipnil()` creates an iterator that skips `nil` value.

    rtn = [3, 1, nil, 4, 1, nil, nil, 5].skipnil()
    // rtn is an iterator that generates 3, 1, 4, 1, 5.

Method `iterable#skip()` creates an iterator that skip the specified number between elements.

    rtn = [3, 1, 4, 1, 5, 9, 2, 6, 5, 3].skip(2)
    // rtn is an iterator that generates 3, 1, 2, 3.

Method `iterable#head()` creates an iterator that picks up the specified number of elements from the top.

    rtn = [3, 1, 4, 1, 5, 9, 2, 6, 5, 3].head(4)
    // rtn is an iterator that generates 3, 1, 4, 1.

Method `iterable#tail()` creates an iterator that picks up the specified number of elements from the bottom.

    rtn = [3, 1, 4, 1, 5, 9, 2, 6, 5, 3].tail(4)
    // rtn is an iterator that generates 2, 6, 5, 3.

Method `iterable#offset()` creates an iterator that skip the specified number of elements from the top.

    rtn = [3, 1, 4, 1, 5, 9, 2, 6, 5, 3].offset(5)
    // rtn is an iterator that generates 9, 2, 6, 5, 3.

Method `iterable#pingpong()` creates an iterator that seeks elements from the top to the bottom,
then from the bottom to the top, and repeats.

    rtn = [1, 2, 3, 4, 5].pingpong()
    // rtn is an iterator that generates 1, 2, 3, 4, 5, 4, 3, 2, 1, 2, 3, ...

Method `iterable#cycle()` creates an iterator that repeatedly seeks elements from the top to the bottom.

    rtn = [1, 2, 3, 4, 5].cycle()
    // rtn is an iterator that generates 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, ...

Method `iterable#reverse()` creates an iterator that seeks elements from the bottom to the top.

    rtn = [1, 2, 3, 4, 5].reverse()
    // rtn is an iterator that generates 5, 4, 3, 2, 1.

Method `iterable#runlength()` examines how many times the same values continue.
It creates an iterator that generates a pair containing
the number of how many times a value appears and the value itself.

    rtn = ['A', 'A', 'B', 'B', 'B', 'C', 'D', 'D'].runlength()
    // rtn is an iterator that generates [2, 'A'], [3, 'B'], [1, 'C'], [2, 'D']

Method `iterable#sort()` sorts iterable's elements in an ascending order.

    rtn = [3, 1, 4, 1, 5, 9, 2, 6].sort()
    // rtn is an iterator that generates 1, 1, 2, 3, 4, 5, 6, 9.

Specifying a symbol ``descend` in an argument of the method will sort elements in a descending order.

    rtn = [3, 1, 4, 1, 5, 9, 2, 6].sort(`descend)
    // rtn is an iterator that generates 9, 6, 5, 4, 3, 2, 1, 1.

Methods `iterable#after()`, `iterable#since()`, `iterable#before()`, `iterable#until()`
and `iterable#while()` create an iterator that picks up elements within a certain range.
They take an argument `criteria` that prompts where the range begins and ends.
The `criteria` is the same as that of `iterable#filter()` and may take a function or an iterable.

* An iterator by `iterable#after()` starts extraction of elements
  right after the `criteria` is evaluated as `true`.

        tbl = [3, 1, 4, 1, 5, 9, 2, 6, 5]
        rtn = tbl.after(&{$x >= 5})
        // rtn is an iterator that generates 9, 2, 6, 5.

* An iterator by `iterable#since()` starts extraction of elements
  at the point where the `criteria` is evaluated as `true`.

        tbl = [3, 1, 4, 1, 5, 9, 2, 6, 5]
        rtn = tbl.since(&{$x >= 5})
        // rtn is an iterator that generates 5, 9, 2, 6, 5.

* An iterator by `iterable#before()` carrys on extraction of elements
  until right before the `criteria` is evaluated as `true`.

        tbl = [3, 1, 4, 1, 5, 9, 2, 6, 5]
        rtn = tbl.before(&{$x >= 5})
        // rtn is an iterator that generates 3, 1, 4, 1.
        
* An iterator by `iterable#until()` carrys on extraction of elements
  until the point where the `criteria` is evaluated as `true`.

        tbl = [3, 1, 4, 1, 5, 9, 2, 6, 5]
        rtn = tbl.until(&{$x >= 5})
        // rtn is an iterator that generates 3, 1, 4, 1, 5.
    
* An iterator by `iterable#while()` carrys on extraction of elements
  while the `criteria` is evaluated as `true`.

        tbl = [3, 1, 4, 1, 5, 9, 2, 6, 5]

        rtn = tbl.while(&{$x < 5})
        // rtn is an iterator that generates 3, 1, 4, 1.

Method `list#combination()` creates an iterator
that returns a group of all combinations of elements extracted from the target list.
It takes an argument that specifies the number of elements to extarct.

    rtn = [1, 2, 3, 4].combination(3)
    // rtn is an iterator that generates [1, 2, 3], [1, 2, 4], [1, 3, 4], [2, 3, 4]

Method `list#permutation()` creates an iterator 
that returns a group of all permutations of elements extracted from the target list.
It takes an argument that specifies the number of elements to extarct.

    rtn = [1, 2, 3].permutation(2)
    // rtn is an iterator that generates [1, 2], [1, 3], [2, 1], [2, 3], [3, 1], [3, 2]

If it omits the argument, all the elements would be extracted.

    rtn = [1, 2, 3].permutation()
    // rtn is an iterator that generates [1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 1, 2], [3, 2, 1]

Method `list#shuffle()` returns a list in which elements are shuffled in a random order.


## {{ page.chapter }}.6. Iterator Generation

Function `range()` returns an iterator that generates numbers within the specified range.

    range(10)          // 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
    range(4, 10)       // 4, 5, 6, 7, 8, 9, 10, 11, 12, 13
    range(0, 10, 2)    // 0, 2, 4, 6, 8

Function `interval()` returns an iterator that generates the specified number of `number` values
between the prescribed range.

    interval(1, 3, 5)  // 1, 1.5, 2, 2.5, 3

Function `consts()` returns an iterator that generates the specified number of a constant value of any type.

    consts('foo', 3)   // 'foo', 'foo', 'foo'

Function `rands()` returns an iterator that generates random number values.

    rands(100)         // random numbers between 0 and 99
