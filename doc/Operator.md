---
layout: page
lang: en
title: Operator
chapter: 4
---

# {{ page.chapter }}. {{ page.title }}

## {{ page.chapter }}.1. Overview

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


## {{ page.chapter }}.2. Precedence

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


## {{ page.chapter }}.3. Calculation Operators

Basically, Operators are used for mathematical and logical calculation.
This subsection explains such functions of operators.


### {{ page.chapter }}.3.1 Prefixed Unary Operators

**Operation `+x`** returns the value of `x` itself.









When Operator `=>` is used in an argument declaration of any function definition,
it would work as an assignment for a default value.
And, when it is used in an argument list of any function call,
it would work as a named argument.
See [Chapter.7. Function](Function.html) for their detail.


## {{ page.chapter }}.4. Other Operators

**Operation `string % any`** returns a result formatted
by the string containing specifiers of `printf` format.
The value of `any` must be a list if more than one argument are necessary.

    'Name: %s, Age: %d' % [name, age]

The code above has the same result as the following.

    format('Name: %s, Age: %d', name, age)

**Operation `function * any`** applies the function on `any`.

**Operation `stream << any`** outputs `any` to the `stream`.

    sys.stdout << 'Hello World\n'


## {{ page.chapter }}.5. Operator Overload

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
Specifying a symbol ``unary` as its argument would return a list of unary operators.

    op = operator(`-)
    println(op.entries(`unary))
