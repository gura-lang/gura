# Mathematic Functions

This section summarizes mathematic functions.

## Complex Number

A number literal followed by suffix `j` becomes an imaginary part of a `complex` value.

    >>> (1 - 2j) * (3 + 1j)
    5 - 5j


## Rational Number

A number literal followed by suffix `r` becomes a `rational` value
with which you can do faction calculations.

    >>> 2 / 3r + 1 / 2r
    7/6r


## Big Number

Importing `gmp` module would add following suffixes:

- Suffix `L` creates a `gmp.mpz` or `gmp.mpf` instances that can calculate numbers
  with variable-length digits.

- Suffix `Lr` creates a `gmp.mpq` instance that can calculate rational value
  with variable-length digits.


## Differentiation Formula

When a function is declared with a body that contains math calculation,
you can get a differentiation formula from it using `function#mathdiff()` method.
Assumes that you have the following function:

    >>> f(x) = math.sin(x ** 2)

Then, you can call `function#mathdiff()` method for it like following:

    >>> g = f.mathdiff()

The newly created function `g(x)` is one that does differential calculation of `f(x)`.
You can examine what body it has by seeing `function#expr` property.

	>>> g.expr
	`(math.cos(x ** 2) * (2 * x))
	
The table below shows what differentiation formulas are obtained from original math functions:

<table>
<tr><th>Original</th><th>Differentiation Forumula</th></tr>
<tr><td><code>x ** 2</code></td><td><code>2 * x</code></td></tr>
<tr><td><code>x ** 3</code></td><td><code>3 * x ** 2</code></td></tr>
<tr><td><code>x ** 4</code></td><td><code>4 * x ** 3</code></td></tr>
<tr><td><code>a ** x</code></td><td><code>math.log(a) * a ** x</code></td></tr>
<tr><td><code>math.sin(x)</code></td><td><code>math.cos(x)</code></td></tr>
<tr><td><code>math.cos(x)</code></td><td><code>-math.sin(x)</code></td></tr>
<tr><td><code>math.tan(x)</code></td><td><code>1 / math.cos(x) ** 2</code></td></tr>
<tr><td><code>math.exp(x)</code></td><td><code>math.exp(x)</code></td></tr>
<tr><td><code>math.log(x)</code></td><td><code>1 / x</code></td></tr>
<tr><td><code>math.log10(x)</code></td><td><code>1 / (x * math.log(10))</code></td></tr>
<tr><td><code>math.asin(x)</code></td><td><code>1 / math.sqrt(1 - x ** 2)</code></td></tr>
<tr><td><code>math.acos(x)</code></td><td><code>(-1) / math.sqrt(1 - x ** 2)</code></td></tr>
<tr><td><code>math.atan(x)</code></td><td><code>1 / (1 + x ** 2)</code></td></tr>
<tr><td><code>math.sqrt(x)</code></td><td><code>1 / (2 * math.sqrt(x))</code></td></tr>
<tr><td><code>math.sin(x) ** 2</code></td><td><code>math.cos(x) * 2 * math.sin(x)</code></td></tr>
<tr><td><code>math.sin(x ** 2)</code></td><td><code>math.cos(x ** 2) * (2 * x) </code></td></tr>
<tr><td><code>math.log(math.sin(x))</code></td><td><code>math.cos(x) / math.sin(x)</code></td></tr>
<tr><td><code>x ** 2 * math.sin(x)</code></td><td><code>2 * x * math.sin(x) + x ** 2 * math.cos(x)</code></td></tr>
<tr><td><code>math.sin(x) / (x ** 2)</code></td><td><code>(math.cos(x) * x ** 2 - math.sin(x) * (2 * x)) / (x ** 4)</code></td></tr>
<tr><td><code>3 ** (2 * x)</code></td><td><code>2 * math.log(3) * 3 ** (2 * x)</code></td></tr>
<tr><td><code>math.log(x ** 2 + 1)</code></td><td><code>2 * x / (x ** 2 + 1)</code></td></tr>
<tr><td><code>((x - 1) ** 2 * (x - 2) ** 3) / ((x - 5) ** 2)</code></td><td><code>(((2 * (x - 1) * (x - 2) ** 3 + (x - 1) ** 2 * (3 * (x - 2) ** 2)) * (x - 5) ** 2 - (x - 1) ** 2 * (x - 2) ** 3 * (2 * (x - 5))) / (x - 5) ** 4)</code></td></tr>
<tr><td><code>math.sin(2 * x - 3)</code></td><td><code>math.cos(2 * x - 3) * 2</code></td></tr>
<tr><td><code>math.cos(x) ** 2</code></td><td><code>-(math.sin(x) * 2 * math.cos(x))</code></td></tr>
<tr><td><code>(2 * x - 1) ** 3</code></td><td><code>6 * (2 * x - 1) ** 2</code></td></tr>
<tr><td><code>math.sqrt(x ** 2 + 2 * x + 3)</code></td><td><code>(2 * x + 2) / (2 * math.sqrt(x ** 2 + 2 * x + 3))</code></td></tr>
<tr><td><code>1 / x</code></td><td><code>(-1) / x ** 2</code></td></tr>
<tr><td><code>math.exp(x) + math.exp(-x)</code></td><td><code>math.exp(x) - math.exp(-x)</code></td></tr>
<tr><td><code>math.exp(x) - math.exp(-x)</code></td><td><code>math.exp(x) + math.exp(-x)</code></td></tr>
<tr><td><code>(math.sin(x + 2) + x + 2) * (math.sin(x + 3) + x + 3)</code></td><td><code>(math.cos(x + 2) + 1) * (math.sin(x + 3) + x + 3) + (math.sin(x + 2) + x + 2) * (math.cos(x + 3) + 1)</code></td></tr>
<tr><td><code>math.sin(math.sin(x ** 2 / 3))</code></td><td><code>math.cos(math.sin(x ** 2 / 3)) * (math.cos(x ** 2 / 3) * (2 * x * 3 / 9))</code></td></tr>
<tr><td><code>(2 * x - 1) / x ** 2</code></td><td><code>(2 * x ** 2 - (2 * x - 1) * (2 * x)) / x ** 4</code></td></tr>
</table>
