# Operator

## Overview

There are three types of Operators.

* **Prefixed Unary Operator** takes an input value specified after it.
* **Suffixed Unary Operator** takes an input value specified before it.
* **Binary Operator** takes two input values specified on both sides of them.

An Operator has a table of procedures that are indexed by Data Types of given values,
one Data Type indexing for Unary Operators and two Data Types for Binary Operators.
For instance, operator `+` has a procedure to calculate between values of `number` and `number`
and also a procecure beween values of `string` and `string`.
These procedures are isolated each other
as long as combination of the given Data Types is different.

Users can overload operators' procedures through `operator` instance.
If combination of Data Types of the overloading procedure
is the same as that of existing one,
it would override the registered procedure.
Otherwise, it would add a new procedure to the operator.


## Precedence

The following table shows operators' precedence order from the lowest to the highest.

 Precedence | Operators
------------|---------------------------------------------------
 Lower      | `=>`
            | `||`
            | `&&`
            | `!`
            | `in`
            | `<   >   <=   >=   <=>   ==   !=`
            | `..`
            | `|`
            | `^`
            | `&`
            | `<<   >>`
            | `+   -`
            | `*   /   %  ?`
            | `~`
 Higher     | `**`


## Calculation Operators

Basically, Operators are used for mathematical and logical calculation.
This subsection explains such functions of operators.


### Prefixed Unary Operators

Operation `+x` returns the value of `x` itself.

<table>
<tr><th>Operation</th><th>Result Data Type</th></tr>
<tr><td><code>+number</code></td><td><code>number</code></td></tr>
<tr><td><code>+complex</code></td><td><code>complex</code></td></tr>
<tr><td><code>+rational</code></td><td><code>rational</code></td></tr>
<tr><td><code>+matrix</code></td><td><code>matrix</code></td></tr>
<tr><td><code>+timedelta</code></td><td><code>timedelta</code></td></tr>
</table>


Operation `-x` returns a negaive value of `x`.

<table>
<tr><th>Operation</th><th>Result Data Type</th></tr>
<tr><td><code>-number</code></td><td><code>number</code></td></tr>
<tr><td><code>-complex</code></td><td><code>complex</code></td></tr>
<tr><td><code>-rational</code></td><td><code>rational</code></td></tr>
<tr><td><code>-matrix</code></td><td><code>matrix</code></td></tr>
<tr><td><code>-timedelta</code></td><td><code>timedelta</code></td></tr>
</table>


Operation `~x` returns a bit-inverted value of `x`.

<table>
<tr><th>Operation</th><th>Result Data Type</th></tr>
<tr><td><code>~number</code></td><td><code>number</code></td></tr>
</table>


Operation `!x` returns a logically inverted value of `x`
after evaluating it as a boolean value.

<table>
<tr><th>Operation</th><th>Result Data Type</th></tr>
<tr><td><code>!any</code></td><td><code>boolean</code></td></tr>
</table>

### Suffixed Unary Operators

Operation `x..` returns an infinite iterator
that starts from `x` and is increased by one.

<table>
<tr><th>Operation</th><th>Result Data Type</th></tr>
<tr><td><code>number..</code></td><td><code>iterator</code></td></tr>
</table>


Operation `x?` returns `false` if `x` is `false` or `nil`, and `true` otherwise.
This operator is not affected by Implicit Mapping
and returns `true` if `x` is of `list` or `iterator` type.

<table>
<tr><th>Operation</th><th>Result Data Type</th></tr>
<tr><td><code>any?</code></td><td><code>boolean</code></td></tr>
</table>


### Binary Operators

Operation `x + y` returns an added result of `x` and `y`.

<table>
<tr><th>Operation</th><th>Result Data Type</th></tr>
<tr><td><code>number + number</code></td><td><code>number</code></td></tr>
<tr><td><code>number + complex</code></td><td><code>complex</code></td></tr>
<tr><td><code>number + rational</code></td><td><code>rational</code></td></tr>
<tr><td><code>complex + number</code></td><td><code>complex</code></td></tr>
<tr><td><code>complex + complex</code></td><td><code>complex</code></td></tr>
<tr><td><code>complex + rational</code></td><td>(error)</td></tr>
<tr><td><code>rational + number</code></td><td><code>rational</code></td></tr>
<tr><td><code>rational + complex</code></td><td>(error)</td></tr>
<tr><td><code>rational + rational</code></td><td><code>rational</code></td></tr>
<tr><td><code>matrix + matrix</code></td><td><code>matrix</code></td></tr>
<tr><td><code>datetime + timedelta</code></td><td><code>datetime</code></td></tr>
<tr><td><code>timedelta + datetime</code></td><td><code>datetime</code></td></tr>
<tr><td><code>timedelta + timedelta</code></td><td><code>timedelta</code></td></tr>
</table>

If `x` and `y` are of `string` or `binary` type,
Operation `x + y` returns concatenated result of `x` and `y`.

<table>
<tr><th>Operation</th><th>Result Data Type</th></tr>
<tr><td><code>string + string</code></td><td><code>string</code></td></tr>
<tr><td><code>binary + binary</code></td><td><code>binary</code></td></tr>
<tr><td><code>string + binary</code></td><td><code>binary</code></td></tr>
<tr><td><code>binary + string</code></td><td><code>binary</code></td></tr>
<tr><td><code>string + any</code></td><td><code>string</code> (`any` will be converted to `string` before concatenation)</td></tr>
<tr><td><code>any + string</code></td><td><code>string</code> (`any` will be converted to `string` before concatenation)</td></tr>
</table>


Operation `x - y` returns a subtracted result of `x` and `y`.

<table>
<tr><th>Operation</th><th>Result Data Type</th></tr>
<tr><td><code>number - number</code></td><td><code>number</code></td></tr>
<tr><td><code>number - complex</code></td><td><code>complex</code></td></tr>
<tr><td><code>number - rational</code></td><td><code>rational</code></td></tr>
<tr><td><code>complex - number</code></td><td><code>complex</code></td></tr>
<tr><td><code>complex - complex</code></td><td><code>complex</code></td></tr>
<tr><td><code>complex - rational</code></td><td>(error)</td></tr>
<tr><td><code>rational - number</code></td><td><code>rational</code></td></tr>
<tr><td><code>rational - complex</code></td><td>(error)</td></tr>
<tr><td><code>rational - rational</code></td><td><code>rational</code></td></tr>
<tr><td><code>matrix - matrix</code></td><td><code>matrix</code></td></tr>
<tr><td><code>datetime - timedelta</code></td><td><code>datetime</code></td></tr>
<tr><td><code>datetime - datetime</code></td><td><code>timedelta</code></td></tr>
<tr><td><code>timedelta - timedelta</code></td><td><code>timedelta</code></td></tr>
</table>


Operation `x * y` returns a multiplied result of `x` and `y`.

<table>
<tr><th>Operation</th><th>Result Data Type</th></tr>
<tr><td><code>number * number</code></td><td><code>number</code></td></tr>
<tr><td><code>number * complex</code></td><td><code>complex</code></td></tr>
<tr><td><code>number * rational</code></td><td><code>rational</code></td></tr>
<tr><td><code>complex * number</code></td><td><code>complex</code></td></tr>
<tr><td><code>complex * complex</code></td><td><code>complex</code></td></tr>
<tr><td><code>complex * rational</code></td><td>(error)</td></tr>
<tr><td><code>rational * number</code></td><td><code>rational</code></td></tr>
<tr><td><code>rational * complex</code></td><td>(error)</td></tr>
<tr><td><code>rational * rational</code></td><td><code>rational</code></td></tr>
<tr><td><code>matrix * matrix</code></td><td><code>matrix</code></td></tr>
<tr><td><code>matrix * list</code></td><td><code>list</code></td></tr>
<tr><td><code>list * matrix</code></td><td><code>list</code></td></tr>
<tr><td><code>timedelta * number</code></td><td><code>timedelta</code></td></tr>
<tr><td><code>number * timedelta</code></td><td><code>timedelta</code></td></tr>
</table>

Applying `*` operator between `string`/`binary` and `number`
will join the `string`/`binary` for `number` times.

<table>
<tr><th>Operation</th><th>Result Data Type</th></tr>
<tr><td><code>string * number</code></td><td><code>string</code></td></tr>
<tr><td><code>number * string</code></td><td><code>string</code></td></tr>
<tr><td><code>binary * number</code></td><td><code>binary</code></td></tr>
<tr><td><code>number * binary</code></td><td><code>binary</code></td></tr>
</table>


Operation `x / y` returns a divided result of `x` and `y`.

<table>
<tr><th>Operation</th><th>Result Data Type</th></tr>
<tr><td><code>number / number</code></td><td><code>number</code></td></tr>
<tr><td><code>number / complex</code></td><td><code>complex</code></td></tr>
<tr><td><code>number / rational</code></td><td><code>rational</code></td></tr>
<tr><td><code>complex / number</code></td><td><code>complex</code></td></tr>
<tr><td><code>complex / complex</code></td><td><code>complex</code></td></tr>
<tr><td><code>complex / rational</code></td><td>(error)</td></tr>
<tr><td><code>rational / number</code></td><td><code>rational</code></td></tr>
<tr><td><code>rational / complex</code></td><td>(error)</td></tr>
<tr><td><code>rational / rational</code></td><td><code>rational</code></td></tr>
<tr><td><code>matrix / matrix</code></td><td><code>matrix</code></td></tr>
</table>


Operation `x % y` returns a remainder after dividing `x` by `y`.

<table>
<tr><th>Operation</th><th>Result Data Type</th></tr>
<tr><td><code>number % number</code></td><td><code>number</code></td></tr>
</table>


Operation `x ** y` returns a powered result of `x` and `y`.

<table>
<tr><th>Operation</th><th>Result Data Type</th></tr>
<tr><td><code>number ** number</code></td><td><code>number</code></td></tr>
<tr><td><code>number ** complex</code></td><td><code>complex</code></td></tr>
<tr><td><code>complex ** number</code></td><td><code>complex</code></td></tr>
<tr><td><code>complex ** complex</code></td><td><code>complex</code></td></tr>
</table>


Operation `x == y` returns `true` when `x` equals to `y`, and `false` otherwise.

<table>
<tr><th>Operation</th><th>Result Data Type</th></tr>
<tr><td><code>any == any</code></td><td><code>boolean</code></td></tr>
</table>


Operation `x < y` returns `true` when `x` is less than `y`, and `false` otherwise.

<table>
<tr><th>Operation</th><th>Result Data Type</th></tr>
<tr><td><code>any &lt; any</code></td><td><code>boolean</code></td></tr>
</table>


Operation `x > y` returns `true` when `x` is greater than `y`, and `false` otherwise.

<table>
<tr><th>Operation</th><th>Result Data Type</th></tr>
<tr><td><code>any > any</code></td><td><code>boolean</code></td></tr>
</table>


Operation `x <= y` returns `true` when `x` is less than or equal to `y`, and `false` otherwise.

<table>
<tr><th>Operation</th><th>Result Data Type</th></tr>
<tr><td><code>any &lt;= any</code></td><td><code>boolean</code></td></tr>
</table>


Operation `x >= y` returns `true` when `x` is greater than or equal to `y`, and `false` otherwise.

<table>
<tr><th>Operation</th><th>Result Data Type</th></tr>
<tr><td><code>any >= any</code></td><td><code>boolean</code></td></tr>
</table>


Operation `x <=> y` returns `0` when `x` is equal to `y`,
`-1` when `x` is less than `y` and `1` when `x` is greater than `y`.

<table>
<tr><th>Operation</th><th>Result Data Type</th></tr>
<tr><td><code>any <=> any</code></td><td><code>number</code></td></tr>
</table>


Operation `x in y` checks if `x` is contained in `y`.

When Operator `in` takes a value of any type other than `list` and `iterator` at its left,
it will check if the value is contained in the container specified at its right.
If the right value is not of `list` or `iterator`,
it would act in the same way as Operator `==`.

<table>
<tr><th>Operation</th><th>Result Data Type</th></tr>
<tr><td><code>any in list</code></td><td><code>boolean</code></td></tr>
<tr><td><code>any in iterator</code></td><td><code>boolean</code></td></tr>
<tr><td><code>any in any</code></td><td><code>boolean</code></td></tr>
</table>

When Operator `in` takes a value of `list` or `iterator` type at its left,
it will check if each value of the container's element is contained in the container
specified at its right,
and return a list of `boolean` indicating the result of each containing check.

<table>
<tr><th>Operation</th><th>Result Data Type</th></tr>
<tr><td><code>list in list</code></td><td><code>list</code></td></tr>
<tr><td><code>list in iterator</code></td><td><code>list</code></td></tr>
<tr><td><code>list in any</code></td><td><code>list</code></td></tr>
<tr><td><code>iterator in list</code></td><td><code>list</code></td></tr>
<tr><td><code>iterator in iterator</code></td><td><code>list</code></td></tr>
<tr><td><code>iterator in any</code></td><td><code>list</code></td></tr>
</table>

When Operator `in` is used in an argument of `for()` and `cross()` function,
it would work as an iterable assignment.
See [Chapter.8. Flow Control](Flow-Control.html) for detail.


Operation `x & y` returns an AND calculation result of `x` and `y`.

* If `x` and `y` are of `number` type, it calculates bitwise AND between them.
* If `x` and `y` are of `boolean` type, it calculates logical AND between them.
* If either `x` or `y` is `nil, it returns `nil`.

<table>
<tr><th>Operation</th><th>Result Data Type</th></tr>
<tr><td><code>number &amp; number</code></td><td><code>number</code></td></tr>
<tr><td><code>boolean &amp; boolean</code></td><td><code>boolean</code></td></tr>
<tr><td><code>nil &amp; any</code></td><td><code>nil</code></td></tr>
<tr><td><code>any &amp; nil</code></td><td><code>nil</code></td></tr>
</table>


Operation `x | y` returns an OR calculation result of `x` and `y`.

* If `x` and `y` are of `number` type, it calculates bitwise OR between them.
* If `x` and `y` are of `boolean` type, it calculates logical OR between them.
* If either `x` or `y` is `nil, it returns one of their values that is not `nil`.

<table>
<tr><th>Operation</th><th>Result Data Type</th></tr>
<tr><td><code>number | number</code></td><td><code>number</code></td></tr>
<tr><td><code>boolean | boolean</code></td><td><code>boolean</code></td></tr>
<tr><td><code>nil | any</code></td><td><code>nil</code></td></tr>
<tr><td><code>any | nil</code></td><td><code>nil</code></td></tr>
</table>


Operation `x ^ y` returns a XOR calculation result of `x` and `y`.

* If `x` and `y` are of `number` type, it calculates bitwise XOR between them.
* If `x` and `y` are of `boolean` type, it calculates logical XOR between them.

<table>
<tr><th>Operation</th><th>Result Data Type</th></tr>
<tr><td><code>number ^ number</code></td><td><code>number</code></td></tr>
<tr><td><code>boolean ^ boolean</code></td><td><code>boolean</code></td></tr>
</table>


Operation `x << y` returns a value of `x` shifted left by `y` bits.

<table>
<tr><th>Operation</th><th>Result Data Type</th></tr>
<tr><td><code>number &lt;&lt; number</code></td><td><code>number</code></td></tr>
</table>


Operation `x >> y` returns a value of `x` shifted right by `y` bits.

<table>
<tr><th>Operation</th><th>Result Data Type</th></tr>
<tr><td><code>number >> number</code></td><td><code>number</code></td></tr>
</table>


Operation `x && y` returns a conditional AND result of `x` and `y` as described below:

* If `x` is not of `list` nor `iterator` type,
  it would return the value of `x` when `x` is determined as `false`,
  and return the value of `y` otherwise.
  It won't evaluate `y` when `x` comes out to be in `false` state.
* If `x` is of `list` type, it applies the above operation on each value of the list's elements and
  returns a list containing the results.
* If `x` is of `iterator` type, it returns an iterator that is to apply the above operation
  on each value of the iterator's elements.

<table>
<tr><th>Operation</th><th>Result Data Type</th></tr>
<tr><td><code>any && any</code></td><td><code>any</code></td></tr>
<tr><td><code>list && any</code></td><td><code>list</code></td></tr>
<tr><td><code>iterator && any</code></td><td><code>iterator</code></td></tr>
</table>


Operation `x || y` returns a conditional OR result of `x` and `y` as described below:

* If `x` is not of `list` nor `iterator` type,
  it would return the value of `x` when `x` is determined as `true`,
  and return the value of `y` otherwise.
  It won't evaluate `y` when `x` comes out to be in `true` state.
* If `x` is of `list` type, it applies the above operation on each value of the list's elements and
  returns a list containing the results.
* If `x` is of `iterator` type, it returns an iterator that is to apply the above operation
  on each value of the iterator's elements.

<table>
<tr><th>Operation</th><th>Result Data Type</th></tr>
<tr><td><code>any || any</code></td><td><code>any</code></td></tr>
<tr><td><code>list || any</code></td><td><code>list</code></td></tr>
<tr><td><code>iterator || any</code></td><td><code>iterator</code></td></tr>
</table>


Operation `x..y` creates an iterator that returns `number` value
that starts from `x` and is increased by one until `y`.

<table>
<tr><th>Operation</th><th>Result Data Type</th></tr>
<tr><td><code>number..number</code></td><td><code>iterator</code></td></tr>
</table>


Operation `x => y` returns a list `[x, y]`.

<table>
<tr><th>Operation</th><th>Result Data Type</th></tr>
<tr><td><code>number => any</code></td><td><code>list</code></td></tr>
<tr><td><code>string => any</code></td><td><code>list</code></td></tr>
<tr><td><code>symbol => any</code></td><td><code>list</code></td></tr>
</table>

When Operator `=>` is used in an argument declaration of any function definition,
it would work as an assignment for a default value.
And, when it is used in an argument list of any function call,
it would work as a named argument.
See [Chapter.7. Function](Function.html) for their detail.


## Other Operators

Operation `string % any` returns a result formatted
by the string containing specifiers of `printf` format.
The value of `any` must be a list if more than one argument are necessary.

    'Name: %s, Age: %d' % [name, age]

The code above has the same result as the following.

    format('Name: %s, Age: %d', name, age)

Operation `function * any` applies the function on `any`.

Operation `stream << any` outputs `any` to the `stream`.

    sys.stdout << 'Hello World\n'


## Operator Overload

You can assign your own functions to operators through `operator` instance.
The example below assings `string - string` operation by using `operator#assign()` method.

    op = operator(`-)
    op.assign(`string, `string) {|x, y|
        x.replace(y, '')
    }

After this assignment, the following code results in `'Hello, world'`.

    'Hello, 1234world' - '1234'

If you want to assign a function of a unary operator,
specify one argument in `operator#assign()` method like below.

    op = operator(`-)
    op.assign(`string) {|x|
        x.each().reverse().join()
    }

Then, the code below has a result `'987654321'`.

    -'123456789'

You can also override existing operators.

You can use `operator#entries()` method to get all of the functions registered in the operator.

    op = operator(`-)
    println(op.entries())

The method returns entries registered as binary operators.
Specifying a symbol `` `unary`` as its argument would return a list of unary operators.

    op = operator(`-)
    println(op.entries(`unary))
