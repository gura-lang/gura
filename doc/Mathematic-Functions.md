# {{ page.chapter }}. Mathematic Functions

## Complex Number

suffix `j`

## Rational Number

suffix `r`

    4 / 7r + 3 / 10r
	3 / 5r + 3 / 10r
	2 / 3r - 3 / 5r
	6 / 7r - 1 / 3r


## Big Number

`gmp` module

suffix `q`

suffix `L`

## Differential

`function#mathdiff`

    >>> f(x) = math.sin(x ** 2)
    >>> g = f.mathdiff()
	>>> g.expr
	`(math.cos(x ** 2) * (2 * x))
	

<table>
<tr><th>Function</th><th>Derivative</th></tr>
<tr><td><pre>x ** 2</pre></td><td><pre>2 * x</pre></td></tr>
<tr><td><pre>x ** 3</pre></td><td><pre> </pre></td></tr>
<tr><td><pre>x ** 4</pre></td><td><pre> </pre></td></tr>
<tr><td><pre>a ** x</pre></td><td><pre> </pre></td></tr>
<tr><td><pre>math.sin(x)</pre></td><td><pre> </pre></td></tr>
<tr><td><pre>math.cos(x)</pre></td><td><pre> </pre></td></tr>
<tr><td><pre>math.tan(x)</pre></td><td><pre> </pre></td></tr>
<tr><td><pre>math.exp(x)</pre></td><td><pre> </pre></td></tr>
<tr><td><pre>math.log(x)</pre></td><td><pre> </pre></td></tr>
<tr><td><pre>math.log10(x)</pre></td><td><pre> </pre></td></tr>
<tr><td><pre>math.asin(x)</pre></td><td><pre> </pre></td></tr>
<tr><td><pre>math.acos(x)</pre></td><td><pre> </pre></td></tr>
<tr><td><pre>math.atan(x)</pre></td><td><pre> </pre></td></tr>
<tr><td><pre>math.sqrt(x)</pre></td><td><pre> </pre></td></tr>
<tr><td><pre>math.sin(x) ** 2</pre></td><td><pre> </pre></td></tr>
<tr><td><pre>math.sin(x ** 2)</pre></td><td><pre> </pre></td></tr>
<tr><td><pre>math.log(math.sin(x))</pre></td><td><pre> </pre></td></tr>
<tr><td><pre>x ** 2 * math.sin(x)</pre></td><td><pre> </pre></td></tr>
<tr><td><pre>math.sin(x) / (x ** 2)</pre></td><td><pre> </pre></td></tr>
<tr><td><pre>3 ** (2 * x)</pre></td><td><pre> </pre></td></tr>
<tr><td><pre>math.log(x ** 2 + 1)</pre></td><td><pre> </pre></td></tr>
<tr><td><pre>((x - 1) ** 2 * (x - 2) ** 3) / ((x - 5) ** 2)</pre></td><td><pre> </pre></td></tr>
<tr><td><pre>math.sin(2 * x - 3)</pre></td><td><pre> </pre></td></tr>
<tr><td><pre>math.cos(x) ** 2</pre></td><td><pre> </pre></td></tr>
<tr><td><pre>(2 * x - 1) ** 3</pre></td><td><pre> </pre></td></tr>
<tr><td><pre>math.sqrt(x ** 2 + 2 * x + 3)</pre></td><td><pre> </pre></td></tr>
<tr><td><pre>1 / x</pre></td><td><pre> </pre></td></tr>
<tr><td><pre>math.exp(x) + math.exp(-x)</pre></td><td><pre> </pre></td></tr>
<tr><td><pre>math.exp(x) - math.exp(-x)</pre></td><td><pre> </pre></td></tr>
<tr><td><pre>(math.sin(x + 2) + x + 2) * (math.sin(x + 3) + x + 3)</pre></td><td><pre> </pre></td></tr>
<tr><td><pre>math.sin(math.sin(x ** 2 / 3))</pre></td><td><pre> </pre></td></tr>
<tr><td><pre>(2 * x - 1) / x ** 2</pre></td><td><pre> </pre></td></tr>
</table>
