# About This Reference

This reference explains about functions and classes that are shipped with Gura interpreter.
Refer to Gura Language Manual if you want information
about syntax and specifications of Gura language itself.

# Explanatory Note

Functions in this reference are described in a generic expression.
For example, if there is a reference described like `func(num:number)`,
it means that `func` function takes one argument named `num` with value type of `number`.
You can call it like `func(3)`.

If an argument is optional, the argument name is followed by a symbol `?`.
For example: `func(num?:number)`.
You can call it as `func(2)` or can omit the arugument like `func()`.

If the the arument name has `*` symbol followed, the arument takes zero or more values.
For a function that has a generic expression `func(args*:number)`,
it can be called like `func()`, `func(3)`, `func(3, 4)`, `func(3, 4, 2)`, and so on.

If the the arument name has `+` symbol followed, the arument takes one or more values.
For a function that has a generic expression `func(args+:number)`,
it can be called like `func(3)`, `func(3, 4)`, `func(3, 4, 2)`, and so on.
In difference with `*`, it must take at least one value.

An argument may have a default value.
The default value is described with `=>` operator like `func(num:number => 4)`.
In such a case, if `num` is omitted, the default value `4` shall be used.

# Predefined Variables

<table>
<tr><th>Variable</th><th>Type</th><th>Explanation</th></tr>

<tr><td><code>*</code></td><td><code>iterator</code></td>
<td>An iterator instance equivalent with "<code>0..</code>".</td></tr>

<tr><td><code>-</code></td><td><code>nil</code></td>
<td>Value of <code>nil</code>.</td></tr>

<tr><td><code>@rem</code></td><td><code>nil</code></td>
<td>Value of <code>nil</code>.</td></tr>

<tr><td><code>__name__</code></td><td><code>string</code></td>
<td>If the current script is a main one that the interpreter launches, this variable is set to <code>'__main__'</code>.
If it is imported by another as a module, this variable is set to that module name.</td></tr>

<tr><td><code>false</code></td><td><code>boolean</code></td>
<td>Value of false.</td></tr>

<tr><td><code>nil</code></td><td><code>nil</code></td>
<td>Value of <code>nil</code>.</td></tr>

<tr><td><code>root</code></td><td><code>environment</code></td>
<td>Top level scope.</td></tr>

<tr><td><code>true</code></td><td><code>boolean</code></td>
<td>Value of true.</td></tr>

</table>
