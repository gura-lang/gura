# Function

## Definition and Evaluation

The figure below shows an example of function definition with each part's designation.

        +-- declaration
        |
    ----------
    f(x, y, z) = printf('x = %s, y = %s, z = %s\n', x, y, z)
    - -------    -------------------------------------------
    |   |                            |
    |   +-- argument list            +-- body
    +-- identifier

It composes of a declaration and a body with an assignment operator,
and the declaration is made up with an identifier and an argument list.

The body must be a single expression.
If you want to describe more than one expression,
you have to use a Block expression embracing them like following.

    f(x, y, z) = {
        printf('x = %s, y = %s, z = %s\n', x, y, z)
    }

After defining a function, a `function` instance is assigned
in the scope environment with the identifier.
If the same identifier already exists in the environment,
the existing one is overwritten no matter whether it's a `function` instance or other.

You can see a function's declaration by simply printing the instance like following.

    println(f)

The argument list is a list of Identifier expressions.
If no argument is necessary, specify an empty list.

    g() = { /* body */ }

You can evaluate a `function` instance by passing it values as its arguments.
The number of passed values must be the same as that of declared arguments.

    f(1, 2, 3)    // OK
    f(1, 2, 3, 4) // Error; too many arguments
    f(1, 2)       // Error; insufficient arguments

If the Caller doesn't pass any argument for evaluation, specify an empty list.

    g()


## Returned Value

An evaluation result of the last expression in a function body becomes its returned value.

The function below returns a string `'hello'` as its result:

    f() = {
        // any process
        'hello'
    }

The function below returns a returned value of `g()` as its result:

    f() = {
        // any process
        g()
    }

A function can return any types of value including `list`.
This feature enables a function to return more than one value.

    f() = {
        // any process
        [3, 4, 5]
    }
    
    [a, b, c] = f()  // a = 3, b = 4, c = 5

You can also use a function `return()` to explicitly specify the returned value
even though its use is not recommended unless you need to quit a process in the middle.

    f() = {
        // any process
        return('hello')
    }

An attribute `:void` indicates that the function always return `nil`
no matter what value is resulted at last in the process.
A call for a function below returns `nil`, not a string `'hello'`.

    f():void = {
        'hello'
    }

You should put `:reduce` attribute if the function is supposed to return a unchanged value.
Attributes `:void` and `:reduce` have a significant effect with Implicit Mapping.

## Arguments


### Type Name Declaration

You can specify a type name by describing it as an attribute
after an Identifier's symbol.

    f(x:number) = { /* body */ }

When calling a function that has arguments with type name,
the Interpreter first check the data type of the given value and try to cast it
into specified data type if possible.
If the type doesn't match and also fails to be casted correctly,
it would occur an error.

If you expect an argument to take a list,
specify a pair of square brackets that has no content after an Identifer's symbol.

    f(x[]) = { /* body */ }

A type name can be described after the bracket pair.

    f(x[]:number) = { /* body */ }

In this case, the Interpreter checks types of all the items in the list
and applies casting on them if possible.


### Data Type Casting

If the data type of a value given as an argument
doesn't match with that that is specified in an argument list,
the value will be casted to the expected data type if possible.

For instance, a value of `string` type can be casted to `number`
if the string contains a valid text of number.

    f(n:number) = {
        // any process
    }
    f('100')  // string will be casted to number

Casting feature can also be applied to other data types. Consider the following function:

    f(in:stream) = {
        // process to read data from in
    }

Since it expects to take a `stream` instance as its argument,
you can call it with the instance created by `open()` function like below.

    f(open('foo.txt'))

Now, you can also call it much easily
using a casting feature that converts from `string` to `stream`.

    f('foo.txt')

If a `string` value is passed to an argument that expects a `stream` value,
the Interpreter opens a stream with a path name specified by the string
and creates a `stream` instance for it.

In default, casting opens a stream with reading mode.
You need to append `:w` attribute in a function declaration
to get a stream with writing mode.

    g(out:stream:w) = {
        // process to write data to out
    }

An attribute `:r` is also prepared
to explicitly indicate the stream is to be opened for reading.

    f(in:stream:r) = {
        // process to read data from in
    }

Let's see another case of casting. Consider a function that takes a value of `image` type,
which also has a casting ability from `stream` data type.

    f(img:image) = {
        // process on img
    }

A function `image()` takes a value of `stream` data type and creates an `image` instance.
With the most explicit way, the function above can be called as below.

    f(image(open('foo.jpg')))

An `image` data type can be casted from a value of `stream` type.

    f(open('foo.jpg'))

Using a feature to convert `string` to `stream`, it will be rewritten like following.

    f('foo.jpg')

This means that, if a function expects `image` data type,
you can call it with a value of either `image`, `stream` or `string` data type.

You can find information about what data type can be casted from which data type
in **Gura Library Reference**.


### Optional Argument

You can declare an optional argument by putting `?` right after an Identifier's symbol.

    f(x?) = { /* body */ }

If you want to declare a type name for an optional argument, specify it like following.

    f(x?:number) = { /* body */ }

For such a function, you can call it like following.

    f(3)
    f()

If the Caller omits a value for an optional argument,
a variable for the argument would be in undefined state.
You can use `isdefined()` function to check if the variable is defined or not.

    f(x?) = {
        if (isdefined(x)) {
            // when x is specified
        } else {
            // when x is omitted
        }
    }

You can specify more than one optional argument.
Note that it's inhibited to declare any non-optional arguments following after optional one.

    f(x?, y?, z?) = { /* body */ }  // OK
    f(x, y?, z?)  = { /* body */ }  // OK
    f(x?, y?, z)  = { /* body */ }  // Error


### Argument with Default Value

An argument with a default value can be declared with an operator `=>`.

    f(x => -1) = { /* body */ }

If you want to declare a type name for an argument with a default value, specify it like following.

    f(x:number => -1) = { /* body */ }

For such a function, you can call it like following.

    f(3)
    f()

If the Caller omits a value for an argument with a default value,
a variable for the argument would be set to the specified default value.

You can specify more than one arguments with default value.
Note that any arguments that don't have a default value can not
follow after one with a default value.

    f(x => 1, y => 2, z => 3) = { /* body */ }  // OK
    f(x, y => 2, z => 3)      = { /* body */ }  // OK
    f(x => 1, y => 2, z)      = { /* body */ }  // Error

Optional arguments and arguments with default value
follow the same positioning rule each other in an argument list.

    f(x => 1, y => 2, z?) = { /* body */ }  // OK


### Variable-length Argument

You can declare a variable-length argument by putting `+` or `*`
right after an Identifier's symbol.

    f(x+) = { /* body */ }
    g(x*) = { /* body */ }

For the first one, the Caller can call it with **one** or more values.
If it doesn't specify any value for the argument, it would occur an error.

    f(1)           // OK
    f(1, 2, 3, 4)  // OK
    f()            // Error

For the second one, the Caller can call it with **zero** or more values.
It can even call it without any argument.

    g(1)           // OK
    g(1, 2, 3, 4)  // OK
    g()            // OK

If you want to declare a type name for a variable-length argument, specify it like following.

    f(x+:number) = { /* body */ }

The variable-length argument can only be declared once and must be placed at the last.

    f(x, y, z+)  = { /* body */ }  // OK
    f(x, y+, z+) = { /* body */ }  // Error
    f(x, y+, z)  = { /* body */ }  // Error

In the function body, a variable of variable-length argument takes a list of values.

    f(x*) = {
        println('number of arguments: ', x.len())
        for (item in x) {
            sum += item
        }
    }

If there are other arguments before a variable-length one,
variables of those arguments are assigned in order
before the rests are stored in a variable-length argument.
For instance, consider the code below:

    f(x, y, z+) = { /* body */ }
    f(1, 2, 3, 4, 5)

In function `f`, variables `x`, `y` and `z` are set to `1`, `2` and `[3, 4, 5]` respectively.


### Named Argument

Consider the following function:

    f(x, y, z) = { /* body */ }

To evaluate it, you can explicitly specify variable names in the argument list like below:

    f(x => 1, y => 2, z => 3)

Such arguments are called named arguments,
which are useful when you want to specify only relevant one among many optional arguments.

If a function declaration contains an argument suffixed by `%`,
it can take a all the values of named arguments that are not assigned to other arguments.

Consider the following function:

    f(a, b, x%) = { /* body */ }

When you evaluate it like below:

    f(a => 1, b => 2, c => 3, d => 4)

Then, variables `a`, `b` and `x` are set to `1`, `2` and `%{c => 3, d => 4}`.


### Argument Expansion



    f(x*)

    f(1, 2, 3, 4)


    f(x%)


### Quoted Argument

Sometimes, there's a need to pass a function a procedure, not an evaluated result.
For such a purpose, you can use a Quote operator that creates `expr` instance from any code,

See an exmple below:

    f(x:expr) = {
        x.eval()
    }
    
    x = `println('hello')
    f(x)

The variable `x` that holds an `expr` instance contaning expression of `println('hello')`
will be passed to function `f` as its argument, which then actually evaluates it.

Of course, you can also specify the quoted value directly in the argument.

    f(`println('hello'))

There's another way to pass an expression in a function call,
and that is to put a Quoted operator in an argument list
of a function definition like below.

    g(`x) = {
        x.eval()
    }

For such a function, the Caller doesn't have to put a Quote operator
for the expression that you want to pass.

    g(println('hello'))


## Block

A block can be seen as a special form of an argument.
It appears after an argument list and contains a procedure embraced by a pair of curly braces.

A function definition with a block comes like below:

    f() {block} = { /* body */ }

And you can call the function like folowing:

    f() { /* block procedure */ }

The function `f` takes a function instance of a block procedure with a variable named `block`,
and it can call the procedure just like an ordinary function.

Consider the following function:

    three_times() {block} = {
        block()
        block()
        block()
    }

Then, you can call it like following:

    three_times() {
        println('hello world')
    }

This results in three print-outs of `'hello world'`.

As for a function that is declared to take a mandatory block,
a call without specifying a block procedure would occur an error.

    three_times()  // Error because of lacking block

The block procedure can have a list of block parameters
that appears right after the opening curly brace and is embraced by a pair of vertical bars.

    f() {|/* block parameters */| /* block procedure */ }

A declaration of block parameters is almost the same with that of function arguments.
In fact, a function created from a block procedure has an argument list
that are specified as block parameters.

Consider the following function:

    three_times() {block} = {
        block(0, 'zero')
        block(1, 'one')
        block(2, 'two')
    }

The function provides two block parameters, values of `number` and `string` type.

The function can be called like below:

    three_times() {|idx, str|
        println(idx, ' ', str)
    }

The caller can also specify a value type for each block parameter just like function's arguments.

    three_times() {|idx:number, str:string|
        println(idx, ' ', str)
    }

The caller doesn't have to declare all the block parameters that are provided by the function
if it doesn't require them. In the case of calling the above function, declaraing
only one block parameter like below is permitted:

    three_times() {|idx|
        println(idx)
    }

And having no block parameter like below is also allowed:

    three_times() {
        println('hello')
    }

You can specify an optional block by putting `?` after an identifier for the block procedure.

    f() {block?} = { /* body */ }

You can call such a function either with or without a block.

    f() {}  // OK
    f()     // OK

If a block is not specified, the variable `block` takes `nil` value.

    f() {block?} = {
        if (block) {
            // block is specified
        } else {
            // block is not specified
        }
    }

If an Identifer for the block procedure is prefixed by Quote operator,
the variable takes the procedure as an `expr` instance, not an `function` one.

    f() {`block} = { /* body */ }

You need to use `expr#eval()` method to evaluate the block.

    f() {`block} = {
        block.eval()
    }

This feature is useful when you need to delegate a block to other function.
If a Caller specifies a block that only has a block parameter containing a value of `expr` type,
that value would be passed as a block procedure.

See a sample code below:

    repeat_delegate(n) {`block} = {
        println('begin')
        repeat(n) {|block|}
        println('end')
    }

Function `repeat_delegate()` takes a block procedure in `expr` type,
which is passed to `repeat()` function in a delegation manner.

In general, a function call must be accompanied with an argument list even if it's empty.
Though, if the call doesn't have any argument but has a block procedure,
you can omit the list like below.

    f { /* body */ }


## Attribute


### User-defined Attribute

An attribute works as another way to pass information to a function.
In a function definition,
acceptable attributes are listed within a pair of square brackets
that follow after an argument list and a colon character.

    f():[attr1,attr2,attr3] = { /* body */ }

You can call such a function like below. You can specify any number of attributes in any order.

    f():attr1
    f():attr2
    f():attr1:attr3

In a function body, a variable named `__args__` of `args` type is defined,
and you can use `args#isset()` method to check if an attribute is set.

    f():[foo,bar] = {
        if (__args__.isset(`foo)) {
            // :foo is specified
        }
        if (__args__.isset(`bar)) {
            // :bar is specified
        }
    }


### Predefined Attributes


<table>
<tr><th>Attribute</th><th>Note</th></tr>
<tr><td><code>:map</code></td><td></td></tr>
<tr><td><code>:nomap</code></td><td></td></tr>
<tr><td><code>:flat</code></td><td></td></tr>
<tr><td><code>:noflat</code></td><td></td></tr>
<tr><td><code>:list</code></td><td></td></tr>
<tr><td><code>:xlist</code></td><td></td></tr>
<tr><td><code>:iter</code></td><td></td></tr>
<tr><td><code>:xiter</code></td><td></td></tr>
<tr><td><code>:set</code></td><td></td></tr>
<tr><td><code>:xset</code></td><td></td></tr>
<tr><td><code>:void</code></td><td></td></tr>
<tr><td><code>:reduce</code></td><td></td></tr>
<tr><td><code>:xreduce</code></td><td></td></tr>
<tr><td><code>:static</code></td><td></td></tr>
<tr><td><code>:dynamic_scope</code></td><td></td></tr>
<tr><td><code>:symbol_func</code></td><td></td></tr>
<tr><td><code>:leader</code></td><td></td></tr>
<tr><td><code>:trailer</code></td><td></td></tr>
<tr><td><code>:finalizer</code></td><td></td></tr>
<tr><td><code>:end_marker</code></td><td></td></tr>
<tr><td><code>:public</code></td><td></td></tr>
<tr><td><code>:private</code></td><td></td></tr>
</table>


## Help Block

You can add a help block to a function by appending `%` and a block containing help information
to a function declaration.

    add(x, y) = {
        x + y
    } % {
        `en, 'markdown', 'Takes two numbers and returns an added result.'
    }

The content in the block has a format of `{lang:symbol, format:string, help:string}`
which takes following values.

- `lang:symbol` .. Specifies a symbol for the used language: `en` for English and `ja` for Japanese, etc.
- `format:string` .. Specifies a syntax format. Only `markdown` is available so far.
- `help:string` .. Help string formatted in a syntax specified by `format`.

You can access the help information by following ways:

- In the interactive mode, evaluating the operator `~` with a function instance
  would print its help information on the console.
- Calling function `function.gethelp()` would return a `help` instance
  that provides information about the used language, syntax format and help string.

A function may have multiple help blocks that contain explanatory texts written
in different languages.
Below is a function example that has helps written in English and Japanese:

    add(x, y) = {
        x + y
    } % {`en, 'markdown', R'''
    Takes two numbers and returns an added result.
    
    Below is an example:

        ans = add(3, 4)
    '''
    } % {`ja, 'markdown', R'''
    2 つの数値をとり、加算した結果を返します。

    例を以下に示します:

        ans = add(3, 4)
    '''
    }

A predefined variable `sys.langcode` determines which help should be printed by default.
If a function doesn't have a help in the specified language,
what appears at first in the declaration will be used.

You can also pass a language symbol to `function.gethelp` function as below.

    function.gethelp(add, `en)
    function.gethelp(add, `ja)


## Anonymous Function

A function `function()` creates an anonymous function instance
from an argument list and a block that contains its function body.

    function(x, y, z) { /* body */ }

When the function instance is assigned to a variable, that symbol is bound to the instance.
The following two codes are equivalent each other.

    f = function(x, y, z) { /* body */ }
    f(x, y, z) = { /* body */ }

If you create a function that doesn't have arguments,
you can call `function()` without an argument list like below.

    function { /* body */ }

Since a special symbol `&` is also bound to the `function()` function,
you can create a function instance as below.

    &{ /* body */ }

When `function()` creates a function instance,
it seeks variable symbols in the function body that start with `$` character,
which are used as argument variables. For instance, see the following code:

    function { printf('x = %s, y = %s, z = %s\n', $x, $y, $z) }

This is equivalent with the function creation shown below:

    function($x, $y, $z) { printf('x = %s, y = %s, z = %s\n', $x, $y, $z) }

The order of arguments is the same with the order in which the variables appear in the body.


## Closure

You can define a function inside another function body.
In that case, the inner function can access variables in the outer function.

    f() = {
        x = 3
        g() = {
            println('x = ', x)
        }
        g()  // evaluate the function
    }

A function can also return a `function` instance that it creates as its result.
The environment of the outer function will be held in the inner function.

    f() = {
        x = 3
        g() = {
            println('x = ', x)
        }
        g
    }
    
    h = f()
    h()


## Leader-trailer Relationship

When a Caller expression is described at the same line with the end of a preceding one,
they have a leader-trailer relationship
with the preceding one as a leader and the following one as a trailer.

    f() g()
    --- ---
     |   |
     |   +-- trailer
     +-- leader

In an ordinary case, these functions are evaluated sequentially
in the same way that they're described in different lines.

The leader function has a right to control whether the trailer one should be evaluated or not.
A method `args#quit_trailer()` will quit its trailer from being evaluated.
Take a look at the following simple function to see how a trailer is controlled.

    do_trailer(flag:boolean) = {
        if (!flag) {
            __args__.quit_trailer()
        }
    }

Then the following code will print `hello` but no `good-bye`.

    do_trailer(true) println('hello')
    do_trailer(false) println('good-bye')

Some functions that govern sequence flow like `if-elsif-else` and `try-catch` utilizes
this trailer control mechanism.
