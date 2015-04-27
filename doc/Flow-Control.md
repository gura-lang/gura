## Flow Control


## Branch

Branch may be the most common flow-control in a program.
Just like other programming language,
Gura also provides `if` - `elsif` - `else` sequence.
However, they're realized as functions, not as statements.

These elements are implemented by the following functions.

Function `if()`:

    if (`cond):leader {block}

Function `elsif()`:

    elsif (`cond):leader:trailer {block}

Function `else()`:

    else():trailer {block}

They are concatenated with leader-trailer relationship,
which means that a closing curly bracket of the preceding function
must be in the same line as the top of the succceding one.

    if (x) { /* branch 1 */ } elsif (y) { /* branch 2 */ } else { /* branch 3 */ }

Of course, content in a block embraced by a pair of curly brackets may contain multiple lines.
This enables you to write a script in a similar syntax as other languages.

    if (x) {
        
        /* branch 1 */
        
    } elsif (y) {
        
        /* branch 2 */
        
    } else {
        
        /* branch 3 */
        
    }

Function `if()` and `elsif()` check the evaluated result of the expression `cond`.
If it's determined as `true`, the block procedure will be evaluated,
otherwise, the trailing function will be evaluated.
Function `else()` always evaluates its block procedure.

Branch sequence has a result value as well. Consider the following code:

    result = if (x < 0) {
        'less than zero'
    } elsif (x > 0) {
        'greater than zero'
    } else {
        'equal to zero'
    }

In this case, if `x` is less than zero,
the sequence would have a string `'less than zero'` as its result.
It would have `'greater than zero'` for `x` with number greater than zero and
`'equal to zero'` otherwise.

If function `if()` and `elsif()` have no following `else()` and their conditions are not evaluated as `true`,
the result value will be `nil`.

    x = 3
    result = if (x < 0) {
        'less than zero'
    }
    // result is nil


## Repeat


### Repeating Functions

This subsection explains about some representative functions
that evaluate a procedure repeatedly while it meets a given condition.

A function `repeat()` repeats a procedure for a specific number of times.

    repeat (n?:number) {block}

If argument `n` is omitted, it will repeat the procedure indefinitely.

A function `while()` repeats a procedure while the condition is evaluated as `true`.

    while (`cond) {block}

As a variable `cond` is an expression, it will be evaluated each time in the loop.
In the following example, the function is given with an expression `n < 10`,
which is to be evaluated during the repeating process.

    n = 0
    while (n < 10) {
        println('hello')
        n += 1
    }

A function `for()` takes one or more expressions of iterable assignments,
where an iterable means what can iterate elements including a list and an iterator instance.

    for (`expr+) {block}

An iterator assignment is expressed with an operator <code>in</code> like below.

<pre><code><em>symbol</em> in <em>iterable</em>
[<em>symbol1</em>, <em>symbol2</em> ..] in <em>iterable</em>
</code></pre>

In the first format, it assigns `symbol` with a value in `iterable` each time in the loop.
Below is an example.

    for (name in ['apple', 'grape', 'banana']) {
        // any process
    }

In the second format, if each element in the iterable is a list,
corresponding values in the list are assigned to `symbol1`, `symbol2`, and so on.
An example is shown below.

    for ([name, yen] in [['apple', 100], ['grape', 200], ['banana', 90]]) {
        // any process
    }

When a function `for()` takes more than one iterable assignment,
it advances all the iterables one by one at each loop
and repeats a procedure until one of the iterables reaches to the end.
This means that the loop count is limited up to the smallest length of the iterables.
The example below repeats the process three times.

    for (x in [1, 2, 3, 4], y in [1, 2, 3], z in [1, 2, 3, 4, 5]) {
        // any process
    }

A function `cross()` takes one or more expressions of iterable assignment
and repeats a procedure with all the conceivable combination of elements from the iterables.

    cross (`expr+) {block}

In `cross()` function, an iterable on the right advances at each loop
and, when it reaches to its end, it will be rounded up to its first
and causes an iterable on its left advance.

See the example below:

    cross (x in ['A', 'B', 'C'], y in [1, 2, 3, 4]) {
        print(x, '-', y, ' ')
    }

The result is:

    A-1 A-2 A-3 A-4 B-1 B-2 B-3 B-4 C-1 C-2 C-3 C-4

Using `for()` function, the above code can be writen like below.

    for (x in ['A', 'B', 'C']) {
        for (y in [1, 2, 3, 4]) {
            print(x, '-', y, ' ')
        }
    }

Of course, you can specify any number of iterable assignments.

    cross (x in ['A', 'B', 'C'], y in [1, 2, 3, 4], z in ['a', 'b', 'c']) {
        print(x, '-', y, '-', z, ' ')
    }


### Block Parameter

When calling `for()`, `while()` and `for()`,
you can specify a block parameter in a format of `|i:number|`
that takes an index number of loop starting from zero.
In the following example,
the parameter `i` takes `0`, `1`, `2`, `3` and `4` at each loop.

    repeat (5) {|i|
        // any process
    }

A block parameter for `cross()` function has a format of
`|i:number, i1:number, i2:number, ..|` where `i` indicates an index number of loop,
and each of `i1`, `i2` and so on takes an index number of corresponding iterable.

    cross (x in ['A', 'B', 'C'], y in [1, 2, 3, 4], z in ['a', 'b', 'c']) {|i, ix, iy, iz|
        // any process
    }

If you don't need indices information, you can omit whole the block parameter
or part of its parameters.


### Result Value of Repeat

Like a branch sequence, a repeat sequence also has a result value
that comes from an evaluation of the last expression in the block procedure.

In default, among result values that have been generated from each loop,
only the last one becomes the final result.

    x = repeat (10) {|i|
        // any process
        i * 10
    }
    // x is 90

When you call a repeat function with `:list` attribute,
it will return a list that contains result values in the loop.

    x = repeat (10):list {|i|
        // any process
        i * 10
    }
    // x is [0, 10, 20, 30, 40, 50, 60, 70, 80, 90]

With an attribute `:xlist`, you can remove `nil` value from the created list.

    x = repeat (10):xlist {|i|
        // any process
        if (i % 2 == 0) {
            i * 10
        }
    }
    // x is [0, 20, 40, 60, 80]

Using this feature, you can create a list that only contains elements
that suit some conditions.

Attributes `:set` and `:xset` work in a similar way with `:list` and `:xlist` respectively,
but they would create a list that contains unique values
by rejecting a value that already exists in the list.


### Flow Control in Repeat Sequence

If you want to quit a repeat sequence, you can use `break()` function.
Aiming for a similar appearance with C and Java,
you can call `break()` without a pair of parenthesis for an argument list.

    repeat (10) {|i|
        // any process
        if (i == 5) {
            break
        }
        // not evaluated when break() is called
    }

The function `break()` takes an argument of any type
that affects a result value of the repeat.
When `break()` is called without an argument,
the repeat's result doesn't contain a value of the last loop.

    x = repeat (10):list {|i|
        if (i == 5) {
            break
        }
        i
    }
    // x is [0, 1, 2, 3, 4]

If you call `break()` with a valid argument, that will be included in the repeat's result.

    x = repeat (10):list {|i|
        if (i == 5) {
            break(99)
        }
        i
    }
    // x is [0, 1, 2, 3, 4, 99]

If you need to go to the next turn of the loop after skipping remaining procedure,
you can use `continue()` function.
As with the function `break`, you can omit a pair of parentheses for an argument list when calling it.

    repeat (10) {|i|
        // any process
        if (i % 2 == 0) {
            continue
        }
        // not evaluated when continue() is called
    }

When you call `continue()` with no argument,
the repeat's result doesn't contain a value of that loop.

    x = repeat (10):list {|i|
        if (i % 2 == 0) {
            continue
        }
        i
    }
    // x is [1, 3, 5, 7, 9]

If you call `continue()` with a valid argument,
that value will be included in the repeat's result.

    x = repeat (10):list {|i|
        if (i % 2 == 0) {
            continue(99)
        }
        i
    }
    // x is [99, 1, 99, 3, 99, 5, 99, 7, 99, 9]


### Generate Iterator

As you've already seen in the above,
appending an attribute `:list` causes the repeating process to create a list
that contains evaluated result of each loop as its element.
In the following example, `x` will be a list of `[0, 10, 20, 30, 40, 50, 60, 70, 80, 90]`.

    x = repeat (10):list {|i|
        // any process
         i * 10
    }

An attribute `:iter` would have a more interesting result. Take a look at the code below:

    x = repeat (10):iter {|i|
        // any process
         i * 10
    }

In this case, repeating process is not executed when the `repeat` function is evaluated.
`x` is an *iterator* that generates values of 0, 10, 20, 30, 40, 50, 60, 70, 80 and 90,
and these values are available only when the iterator is actually evaluated.

The following code shows how to get values from the iterator using Implicit Mapping:

    println(x)

Following code evaluates `x` step by step to confirm that it actually works as an iterator.

    println(x.next())
    println(x.next())
    println(x.next())
    println(x.next())
    println(x.next())

An attribute `:xiter` works as `:iter` except that it will eliminate `nil` value from its element.

    x = repeat (10):xiter {|i|
        // any process
        if (i % 2 == 0) {
            i * 10
        }
    }

In the above case, `x` is an *iterator* that generates values of 0, 20, 40, 60 and 80.

You can also use `break()` and `continue()` in an iterator created by a repeating function.
Such an iterator yields elements in the same way as a repeating process that creates a list.
See subsection for detail.

An iterator created by a repeat function and a closure generated within a function
are similar in that they postpone their actual jobs.
They also have similarity in a manner to handle variable environments.
Consider the following code.

    f() = {
        n = 0
        while (n < 5):iter {
            n += 1
            n
        }
    }
    x = f()

The function `f` returns an iterator created by `while`,
which is expected to generate values of 1, 2, 3, 4 and 5.
In this case, the repeat body has a reference to a variable named `n` that belongs
to the scope of function `f`.
Can an iterator refer to a variable that may be destroyed at the end of a function?

Actually, it's OK. An iterator created by a repeating function owns an environment
in which that function has been called.
In the above example, the variable `n` is owned by the returned iterator.

You'll see more practical usage of this feature in [this](../articles/Script-to-Generate-Prime-Numbers.html).

You can also implement a nested loop in an iterator created by a repeat function.

    x = for (a in ['A', 'B', 'C']):iter {
        
        // any process
        
        for (b in [0, 1, 2]):iter {
            a + b
        }
    }
    // x will generate 'A0', 'A1', 'A2', 'B0', 'B1', 'B2', 'C0', 'C1' and 'C2'

A nested loop with an iterator generation
must be placed at the last in the repeat procedure.

You can also place any iterators in the repeat function
that are to be iterated when the outer iterator is evaluated.
But, there's one point you have to be careful with. See the following code:

    x = repeat (2):iter {
        range(3)
    }

It's expected that the iterator `x` will generate numbers of 0, 1, 2, 0, 1 and 2
after the outer iterator iterates an iterator created by `range(3)` for twice.
But, in reality, it will just generate two iterator instances without iterating them.

Iterators created by repeat functions have a "repeater" flag
that enable them to be iterated in a nested block.
Since other ordinary interators don't have this flag,
you have to call `iterator#repeater()` method to turn it on as shown below.

    x = repeat (2):iter {
        range(3).repeater()
    }


### Repeat Process with Function that Creates Iterator

Many of functions that creates an iterator as their result may take an optional block procedure.
For such functions, you can specify a block that is to be evaluated repeatedly
while iterating values in the created iterator.

For instance, consider a function `readlines()`,
which creates an iterator that reads content of a stream and returns strings of each line.
Without a block, it simply returns the created iterator.

    x = readlines('foo.txt')

Specifying a block would evaluate the block procedure repeatedly.

    readlines('foo.txt') {
        // any process
    }

You can get each value from the iterator by specifying a block parameter.

    readlines('foo.txt') {|line|
        print(line)
    }

A second argument in the block parameter takes an index number of the loop.

    readlines('foo.txt') {|line, i|
        printf('%d: %s', i + 1, line)
    }

When you specify a block procedure to an iterator creating function,
it behaves in the same way as repeating functions such as `for()` and `repeat()`.
This means that you can use flow control functions `break()` and `continue()` in that loop.

    readlines('foo.txt') {|line|
        // any process
        if (line.chop() == '') {
            break
        }
        // any process
    }

You can also specify attributes `:list`, `:xlist`, `:set` and `:xset` to
indicate it to create a list.

    x = readlines('foo.txt'):list {|line|
        line.upper()
    }
    // x is a list containing each line's string in uppercase.

And attributes `:iter` and `:xiter` that create an iterator are also available.

    x = readlines('foo.txt'):iter {|line|
        line.upper()
    }
    // x is an iterator that generates each line's string in uppercase.


## Error Handling

You can use `try-catch` sequence to capture errors.
Any process that may occur errors is written in a block of `try()` function
and error handling processes are written in blocks of `catch()` function trailing after that.

    try {
        // any process
    } catch (error.ValueError) {
        // handling ValueError
    } catch (error.IndexError, error.IOError) {
        // handling IndexError and IOError
    } catch {
        // handling of other errors
    }

A function `catch()` takes one or more arguments that specify `error` instances that are to be handled.
If no argument is specified, any type of errors are handled in the function.

Here are some of the `error` instances that can be specified for `catch()` argument.

<table>
<tr><th>Error Instance</th><th>Note</th></tr>
<tr><td><code>error.ValueError</code></td><td>Invalid argument is specified.</td></tr>
<tr><td><code>error.IndexError</code></td><td>Invalid value for indexing.</td></tr>
<tr><td><code>error.IOError</code></td><td>Error occurs while accessing I/O devices.</td></tr>
</table>

A block in the `catch()` function has a block parameter in a format of `|err:error|`
where `err` takes a value of `error` type that contains error information
such as an error message and a file name and a line position at which the error occurs.

<table>
<tr><th>Property</th><th>Data Type</th><th>Note</th></tr>
<tr><td><code>error#lineno</code></td><td><code>number</code></td><td>Line number</td></tr>
<tr><td><code>error#source</code></td><td><code>string</code></td><td>Source of the code that occurs an error</td></tr>
<tr><td><code>error#text</code></td><td><code>string</code></td><td>Error message</td></tr>
</table>

An example code is shown below:

    try {
        // any process
    } catch {|err|
        printf('%s at %s:%d\n', err.text, err.source, err.lineno)
    }
