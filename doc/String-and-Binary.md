---
layout: page
lang: en
title: String and Binary
chapter: 12
---

# {{ page.chapter }}. {{ page.title }}

## {{ page.chapter }}.1. Overview

A string is a sequence of character codes in UTF-8 format and is represented by `string` class.
Class `string` is a primitive type,
which means there's no operation that could modify the content of `string` instances.
This leads to the following principles:

* It's not allowed to edit each character in a string content through index access.
* Modification methods are supposed to return a new `string` instance with modified result.

The interpreter itself provides fundamental operations for strings.
Importing module named `re` expand the capability so that it can process string data
using regular expressions.

Meanwhile, a binary is a byte sequence of data that has any format and is represented by `binary` class.
Class `binary` is an object type, so you can modify the content of the instance.
A `binary` instance can be used as a plain memory image capable of containing any data.


## {{ page.chapter }}.2. Operation on String


### {{ page.chapter }}.2.1. Character Manipulation

You can specify an index number starting from zero embraced by a pair of square brackets
to retrieve a character as a sub string at the specified position.
Multiple numbers for indexing can also be specified to get a list of sub strings.

    str = 'abcdefghijklmnopqrstuvwxyz'
    str[6]            // returns 'g'
    str[20]           // returns 'u'
    str[17]           // returns 'r'
    str[0]            // returns 'a'
    str[6, 20, 17, 0] // returns ['g', 'u', 'r', 'a']

You can also specify iterators and lists to get a list of sub strings.
Numbers and iterators can be mixed together as indexing items.

    str = 'The quick brown fox jumps over the lazy dog'
    str[10..14]       // returns ['b', 'r', 'o', 'w', 'n']
    str[4..8, 35..38] // returns ['q', 'u', 'i', 'c', 'k', 'l', 'a', 'z', 'y']

If you specify an infinite iterator as an indexing item,
you would get sub strings within an available range.

    str = 'The quick brown fox jumps over the lazy dog'
    str[35..]       // returns ['l', 'a', 'z', 'y', ' ', 'd', 'o', 'g']

An index with a negative number points the position from the bottom,
where `-1` is the last position.

    str = 'The quick brown fox jumps over the lazy dog'
    str[-3]         // returns 'd'
    str[-2]         // returns 'o'
    str[-1]         // returns 'g'

Function `chr()` returns a string that contains a character of the given UTF-8 character code.

    chr(65)         // returns 'A'

Function 'ord()` takes a string and returns UTF-8 character code of its first character.

    ord('A')        // returns 65


### {{ page.chapter }}.2.2. Iteration

Method `string#each()` creates an iterator that returns each character as a sub string.

    str = 'The quick brown fox jumps over the lazy dog'
    x = str.each()
    // x is an iterator that returns 'T', 'h', 'e' ...

A call of `string#each()` with attribute `:utf8` or `:utf32` would create an iterator
that returns character code numbers in UTF-8 or UTF-32 instead of sub strings.

    str = 'XXX'  // assumes it contains kanji characters 'ni-hon-go'
    x = str.each():utf8
    // x is an iterator that returns 0xe697a5, 0xe69cac and 0xe7aa9e

    x = str.each():utf32
    // x is an iterator that returns 0x65e5, 0x672c and 0x8a9e

Method `string#eachline()` creates an iterator that splits a string by a newline character
and returns strings of each line.

    str = R'''
    1st
    2nd
    3rd
    '''
    lines = str.eachline()
    // lines is an iterator that returns '1st\n', '2nd\n' and '3rd\n'

Method `string#chop()` is useful when you want to remove a newline character
appended at the bottom.

    x = str.eachline()
    lines = x:*chop()  // an iterator to apply string#chop() to each value in x
    // lines is an iterator that returns '1st', '2nd' and '3rd'

Method `string#eachline()` and others that split a multi-lined text into strings of each line
like `readlines()` are equipped with an attribute `:chop`
that applies the same process as `string#chop()`.

    lines = str.eachline():chop
    // lines is an iterator that returns '1st', '2nd' and '3rd'

Method `string#split()` creates an iterator that splits a string
by a separator string specified in the argument.

    str = 'The quick brown fox jumps over the lazy dog'
    x = str.split(' ')
    // x is an iterator that returns 'The', 'quick', 'brown', 'fox' ...

If you want to split a string into segments with the same length,
use `string#fold()` method.

    str = 'abcdefghijklmnopqrstuvwxyz'
    x = str.fold(5)
    // x is an iterator that returns 'abcde', 'fghij', 'klmno', 'pqrst', 'uvwxy' and 'z'


### {{ page.chapter }}.2.3. Modification and Conversion

Applying an operator `+` between two `string` instances would concatenate them together.

    str1 = 'abcd'
    str2 = 'efgh'
    str1 + str2   // returns 'abcdefgh'

An operator `*` between a `string` and a `number` value would concatenate the string the specified number of times.

    str = 'abcd'
    str * 3      // returns 'abcdabcdabcd'

Method `list#join()` joins all the string in the list and returns the result.
If it contains elements other than `string`, they're converted to strings before joined.

    ['abcd', 'efgh', 'ijkl'].join()    // returns 'abcdefghijkl'

The method can take a separator string as its argument that is inserted between elements.

    ['abcd', 'efgh', 'ijkl'].join(', ') // returns 'abcd, efgh, ijkl'

Method `string#capitalize()` returns a string with the top alphabet converted to uppper case.

    str = 'hello, WORLD'
    str.capitalize()  // returns 'Hello, WORLD'

Methods `string#upper()` and `string#lower()` return a string after converting
all the alphabet characters to upper and lower case respectively.

    str = 'hello, WORLD'
    str.upper()       // returns 'HELLO, WORLD'
    str.lower()       // returns 'hello, world'

Method `string#binary()` returns a `binary` instance
that contains a binary sequence of the string in UTF-8 format.

    str = 'XXX'    // assumes it contains kanji characters 'ni-hon-go'
    str..binary()  // returns a binary b'\xe6\x97\xa5\xe6\x9c\xac\xe8\xaa\x9e'

You can use `string#encode()` to get a binary sequence in other codec other than UTF-8.

    str = 'XXX'              // assumes it contains kanji characters 'ni-hon-go'
    str.encode('shift_jis')  // returns a b'\x93\xfa\x96\x7b\x8c\xea'

Method `string#reader()` returns a `stream` instance
that reads a binary sequence of the string in UTF-8 format.

    str = 'The quick brown fox jumps over the lazy dog'
    x = str.reader()
    // x is a stream instance for reading

Method `string#encodeuri()` converts characters that can not be described in URI
by a percent-encoding rule,
while method `string#decodeuri()` converts such encoded string into normal characters.

Method `string#escapehtml()` escapes characters that can not be described in HTML
with character entities prefixed by an ampersand,
while method `string#unescapehtml()`converts such escaped ones into normal characters.


### {{ page.chapter }}.2.4. Extraction

Method `string#strip()` removes space characters that exist on both sides of the string.
Attributes `:left` and `:right` would specify the side to remove spaces.

    str = '    hello  '
    str.strip()        // returns 'hello'
    str.strip():left   // returns 'hello  '
    str.strip():right  // returns '    hello'

Method `string#left()` returns a sub string
that has extracted specified number of characters from the left side,
while method `string#right()`extracts from the right side.

    str = 'The quick brown fox jumps over the lazy dog'
    str.left(3)  // returns 'The'
    str.right(3) // returns 'dog'

Method `string#mid()` returns a sub string
that has extracted specified number of characters from the specified position.

    str = 'The quick brown fox jumps over the lazy dog'
    str.mid(10, 5)  // returns 'brown'


### {{ page.chapter }}.2.5. Search, Replace and Inspection

To see the length of a string, `string#len()` is available.
Note that `string#len()` returns the number of characters, not the size in byte.

    str = 'abcdefghijklmnopqrstuvwxyz'
    n = str.len()
    // n is 26

Method `string#find()` searches the specified sub string in the target string
and returns the found position starting from zero. If not found, it returns `nil`.

    str = 'The quick brown fox jumps over the lazy dog'
    str.find('fox')  // returns 16
    str.find('cat')  // returns nil

Method `string#replace()` replaces the sub string with the specified one.

    str = 'The quick brown fox jumps over the lazy dog'
    str.replace('fox', 'cat') // returns 'The quick brown cat jumps over the lazy dog'

Method `string#startswith()` returns `ture` if the string starts with the specified sub string,
and returns `false` otherwise.
Method `string#endswith()` checks if the string ends with the specified sub string.

    str = 'abcdefghijklmnopqrstuvwxyz'
    str.startswith('abcde') // returns true
    str.startswith('hoge')  // returns false
    str.endswith('vwxyz')   // returns true
    str.endswith('hoge')    // returns false

Specifying an attribute `:rest` indicates that these functions return a string
excluding the specified sub string when that matches the head or the bottom part.
If the sub string doesn't match, they would return `nil`.

    str.startswith('abcde):rest // returns 'fghijklmnopqrstuvwxyz'
    str.startswith('hoge'):rest // returns nil
    str.endswith('vwxyz'):rest  // returns 'abcdefghijklmnopqrstu'
    str.endswith('hoge'):rest   // returns nil


## {{ page.chapter }}.3. Formatter

## {{ page.chapter }}.3.1. Functions Equipped with Formatter

You can use format specifiers in some functions that are similar to what are realized in C language's `printf`
to convert objects like numbers into readable strings.

Function `printf()` takes a string containing format specifiers
and values you want to print in its argument list
and put the result out to `sys.stdout` stream.

    printf('x = %d, y = %d\n', x, y)

Method `stream#printf()` has the same argument declaration with `printf()`
and puts the result to the target stream capable of writing
instead of `sys.stdout` stream.

    open('foo.txt', 'w').printf('x = %d, y = %d\n', x, y)

Method `list#printf()` is another form of `printf()`,
which takes values to print in the list of the target instance, not in the argument list.

    [x, y].printf('x = %d, y = %d\n')

Function `format()` takes arguments in the same way as `printf()`
but it returns the result as a `string` instance.

    str = format('x = %d, y = %d\n', x, y)

You can also use `%` operator to get the same result with `format()`,
which takes a format string on the left and a list containing values for printing on the right.

    str = 'x = %d, y = %d\n' % [x, y]

If there's only one value for printing,
you can even give the operator the value without a list.

    str = 'x = %d\n' % x


## {{ page.chapter }}.3.2. Syntax of Format Specifier

A format specifier begins with a percent character and has the syntax below,
where optional fields are embraced by square brackets:

    %[flags][width][.precision]specifier

You always have to specify one of the following characters for the `specifier` field.

<table>
<tr><th>specifier</th><th>Note</th></tr>
<tr><td><code>d</code>, <code>i</code></td><td>decimal integer number with a sign mark</td></tr>
<tr><td><code>u</code></td><td>decimal integer number wihout a sign mark</td></tr>
<tr><td><code>b</code></td><td>binary integer number without a sign mark</td></tr>
<tr><td><code>o</code></td><td>octal integer number without a sign mark</td></tr>
<tr><td><code>x</code></td><td>hexadecimal integer number in lower character without a sign mark</td></tr>
<tr><td><code>X</code></td><td>hexadecimal integer number in upper character without a sign mark</td></tr>
<tr><td><code>e</code></td><td>floating number in exponential form</td></tr>
<tr><td><code>E</code></td><td>floating number in exponential form (in upper character)</td></tr>
<tr><td><code>f</code></td><td>floating number in decimal form</td></tr>
<tr><td><code>g</code></td><td>better form between e and f</td></tr>
<tr><td><code>G</code></td><td>better form between E and F</td></tr>
<tr><td><code>s</code></td><td>string</td></tr>
<tr><td><code>c</code></td><td>character</td></tr>
</table>

You can specify one of the following characters for the optional `flags` field.

<table>
<tr><th>flags</th><th>Note</th></tr>
<tr><td><code>+</code></td><td><code>+</code> precedes for positive numbers</td></tr>
<tr><td><code>-</code></td><td>adjust a string to left</td></tr>
<tr><td>(space)</td><td>space character precedes for positive numbers</td></tr>
<tr><td><code>#</code></td><td>converted results of binary, octdecimal and hexadecimal are
  preceded by <code>'0b'</code>, <code>'0'</code> and <code>'0x'</code> respectively</td></tr>
<tr><td><code>0</code></td><td>fill lacking columns with <code>'0'</code></td></tr>
</table>

The optional field `width` takes a decimal number that specifies a minimum width for the corresponding value.
If the value's length is shorter than the specified width, the rest would be filled with space characters.
If you specify `*` for that field, the formatter would try to get the minimum width from the argument list.

The optional field `precision` has different meanings depending on the specifier as below:

<table>
<tr><th>specifier</th><th>Note</th></tr>
<tr><td><code>d</code>, <code>i</code>, <code>u</code>, <code>b</code>, <code>o</code>, <code>x</code>, <code>X</code></td>
  <td>It specifies the minimum number of digits. If the value is shorter than this number,
    lacking digits are filled with zero.</td></tr>
<tr><td><code>e</code>, <code>E</code>, <code>f</code></td>
  <td>It specifies the number of digits after a decimal point.</td></tr>
<tr><td><code>g</code>, <code>G</code></td>
  <td>It specifies the maximum number of digits for significand part.</td></tr>
<tr><td><code>s</code></td>
  <td>It specifies the maximum number of characters to print.</td></tr>
</table>


## {{ page.chapter }}.4. Regular Expression

You can import module `re` to use regular expression for string search and substition,
which supports a syntax based on POSIX Extended Regular Expression.

Importing module `re` would equip `string` class with methods that can handle regular expressions.
See the sample code below:

    import(re)
    
    str = '12:34:56'
    
    m = str.match(r'(\d\d):(\d\d):(\d\d)')
    if (m) {
        printf('hour=%s, min=%s, sec=%s\n', m[1], m[2], m[3])
    } else {
        println('not match')
    }

Method `string#match()` that is provided by `re` module takes a regular expression pattern.
It would return `re.match` instance if the pattern matches, and return `nil` otherwise.
As regular expressions often contain back slash as a meta character,
it would be convenient to use an expression `r'` &hellip; `'` for a pattern string
to avoid recognizing a backslash as an escaping character.

An instance of `re.match` contains information about matching result.
It supports indexing access where `m[0]` has a string that matches the whole pattern
and `m[1]`, `m[2]` &hellip; returns a string of each group.
You can specify a string instead of a number to index each group
when you use `?<name>` specifier for the group in a regular expression pattern.

    m = str.match(r'(?<hour>\d\d):(?<min>\d\d):(?<sec>\d\d)')
    if (m) {
        printf('hour=%s, min=%s, sec=%s\n', m['hour'], m['min'], m['sec'])
    } else {
        println('not match')
    }

Although you can pass a string containing a pattern to method `string#match()`,
it actually takes `re.pattern` instance in its argument that is capable of
accepting a `string` instance through casting feature.
Above example is equivalent with below:

    pat = re.pattern(r'(\d\d):(\d\d):(\d\d)')
    m = str.match(pat)

When you give a string to a function or a method that expects `re.pattern`,
it always compile the string to create `re.pattern` instance,
which may cause some overhead in a process of huge amount of data.
In such a case, it may be a good idea to call a function with a `re.pattern` instance
that has explicitly been created by `re.pattern()` function in advance like shown above.

Method `string#sub()` takes a `re.pattern` instance
and replaces the matched part with the given substitution value.

A subsitution item can be either a string or a function.
When you give a string for it, the method replaces the matched part with the string.

    str = 'The quick brown fox jumps over the lazy dog'
    str.sub(r'[Tt]he', 'THE') // returns 'THE quick brown fox jumps over THE lazy dog'

You can specify a group reference `\`*n* in a subsitution string where *n* indicates the group index.

If you specify a function for the substitution value,
which takes a `re.match` value as its argument and to return a substitution string,
it would be called when the matching succeeds.

    str = '### #### ##### ## #####'
    f(m:re.match) = format('%d', m[0].len())
    str.sub('#+', f)                             // returns '3 4 5 2 5'

An anonymous function would make the code more simple.

    str = '### #### ##### ## #####'
    str.sub('#+', &{format('%d', $m[0].len())})  // returns '3 4 5 2 5'


## {{ page.chapter }}.5. Operation on Binary

### {{ page.chapter }}.5.1. Creation of Instance

You can create a `binary` instance by put a prefix `b` to a string literal.

    b'AB\x01\x00\xff'

The example above is a `binary` instance that contains a sequence of byte data:
0x41, 0x42, 0x01, 0x00 and 0xff.
As an instance created by a string literal prefixed by `b` can not be modified,
it would occur an error when you try some modification operations on such an instance.

There are several ways to create a `binary` instance that accepts modification.

* Constructor function `binary()` creates an empty `binary` instance.

        buff = binary()

* Class method `binary.alloc()` creates a `binary` instance of the specified size.

        buff = binary.alloc(1000)
        // buff has a memory of 1000 bytes

* Class method `binary.pack()` packs values into a binary sequence according to the packing specifier.

        buff = binary.pack('Bl', 0xaa, 0x12345678)
        // buff has a byte sequence: 0xaa, 0x78, 0x56, 0x34, 0x12.

You can use method `binary#dump()` to print out a content of a `binary` in a hexadecimal dump format.


### {{ page.chapter }}.5.2. Byte Manipulation

An index access on a `binary` would return a number value at the specified position.

    buff = b'\xaa\xbb\xcc\xdd\xee'
    buff[0] // returns 0xaa
    buff[1] // returns 0xbb

You can also specify an iterator as an indexing item for a binary just like a string.

    buff[1..3] // returns [0xbb, 0xcc, 0xdd]

Modification through an indexer on a writable binary is also possible.

    buff = binary.alloc(8)
    buff[0] = 0x12
    buff[1] = 0x34
    buff[3..] = 0..4
    // buff has a byte sequence: 0x12, 0x34, 0x00, 0x00, 0x01, 0x02, 0x03, 0x04.

Method `binary#each()` creates an iterator that returns each 8-bit number value in the binary.

    buff = b'\xaa\xbb\xcc\xdd\xee'
    x = buff.each()
    // x is an iterator that returns 0xaa, 0xbb, 0xcc, 0xdd and 0xee.


### {{ page.chapter }}.5.3. Pack and Unpack

Using an indexer and `binary#each()` method, you can retrieve and modify the content of a binary by a unit of 8-bit number.
To store and extract values such as number that consits of multiple octets
and string that contains a sequence of character codes,
the following methods are provided.

* Class method `binary.pack()` to create a binary sequence that contains numbers and strings.
* Method `binary#unpack()` to extract numbers and strings from a binary sequence.

Class method `binary.pack()` takes a formatter string containing specifiers and values to store as its argument.
For example:

    rtn = binary.pack('H', 0x1234)

The specifier `H` means an unsigned 16-bit number,
so the result `rtn` is a `binary` instance that contains a binary sequence of 0x34 and 0x12.

You can write any number of specifiers in the format.

    rtn = binary.pack('HHH', 0x1234, 0xaabb, 0x5678)

The result contains a binary sequence of 0x34, 0x12, 0xbb, 0xaa, 0x78 and 0x56.

If there's a sequence of the same specifier like above,
you can brackets them together by specifying the number ahead of that specifier.

    rtn = binary.pack('3H', 0x1234, 0xaabb, 0x5678)

This has the same result as the previous example.

Meanwhile, method `binary#unpack()` takes a formatter string and returns a list containing unpacked result.
For example:

    buff = b'\x34\x12'
    rtn = buff.unpack('H')

The result `rtn` is a list `[0x1234]`.
Note that you always get a list as the result even when it contains only one value.

Below is an example of a format that contains multiple specifiers:

    buff = b'\x34\x12\xbb\xaa\x78\x56'
    rtn = buff.unpack('HHH')
    // rtn is [0x1234, 0xaabb, 0x5678]

Just like the packing rule, you can specify the number of succeeding specifiers.

    buff = b'\x34\x12\xbb\xaa\x78\x56'
    rtn = buff.unpack('3H')

Using an assignment to lister expression may often be helpful,
since you can assign extracted values to independent variables.

    buff = b'\x34\x12\xbb\xaa\x78\x56'
    [x, y, z] = buff.unpack('3H')

The table below summarizes specifiers that are used to pack or unpack number values.

<table>
<tr><th>Specifier</th><th>Unit Size</th><th>Note</th></tr>
<tr><td><code>b</code></td><td>1 byte</td><td>Packs or unpacks a signed 8-bit number (-128 to 127).</td></tr>
<tr><td><code>B</code></td><td>1 byte</td><td>Packs or unpacks an unsigned 8-bit number (0 to 255)</td></tr>
<tr><td><code>h</code></td><td>2 bytes</td><td>Packs or unpacks a signed 16-bit number (-32768 to 32767)</td></tr>
<tr><td><code>H</code></td><td>2 bytes</td><td>Packs or unpacks an unsigned 16-bit number (0 to 65535)</td></tr>
<tr><td><code>i</code></td><td>4 bytes</td><td>Packs or unpacks a signed 32-bit number (-2147483648 to 2147483648)</td></tr>
<tr><td><code>I</code></td><td>4 bytes</td><td>Packs or unpacks an unsigned 32-bit number (0 to 4294967295)</td></tr>
<tr><td><code>l</code></td><td>4 bytes</td><td>Packs or unpacks a signed 32-bit number (-2147483648 to 2147483648)</td></tr>
<tr><td><code>L</code></td><td>4 bytes</td><td>Packs or unpacks an unsigned 32-bit number (0 to 4294967295)</td></tr>
<tr><td><code>q</code></td><td>8 bytes</td><td>Packs or unpacks a signed 64-bit number (-9223372036854775808 to 9223372036854775807)</td></tr>
<tr><td><code>Q</code></td><td>8 bytes</td><td>Packs or unpacks an unsigned 64-bit number (0 to 18446744073709551615)</td></tr>
<tr><td><code>f</code></td><td>4 bytes</td><td>Packs or unpacks a single precision floating point number.</td></tr>
<tr><td><code>d</code></td><td>8 bytes</td><td>Packs or unpacks a double precision floating point number.</td></tr>
</table>

By default, byte order of numbers in 16-bit, 32-bit and 64-bit size is a little endian.
You can change the order by using the following specifiers:

<table>
<tr><th>Specifier</th><th>Note</th></tr>
<tr><td><code>@</code></td><td>Turns to a system-dependent endian.</td></tr>
<tr><td><code>=</code></td><td>Turns to a system-dependent endian.</td></tr>
<tr><td><code>&lt;</code></td><td>Turns to a little endian.</td></tr>
<tr><td><code>&gt;</code></td><td>Turns to a big endian.</td></tr>
<tr><td><code>!</code></td><td>Turns to a big endian.</td></tr>
</table>

    rtn = binary.pack('H>H', 0x1234, 0x1234)
    // rtn contains 0x34, 0x12, 0x12, 0x34.

Specifier `x` only advances pointer ahead for specified size without packing or unpacking of values.
When packing, the skipped area would be filled with zero.

    rtn = binary.pack('H3xH', 0x1234, 0x1234)
    // rtn contains 0x34, 0x12, 0x00, 0x00, 0x00, 0x34, 0x12.

Specifiers `c` and `s` are prepared to pack or unpack string data.

<table>
<tr><th>Specifier</th><th>Note</th></tr>
<tr><td><code>c</code></td><td>Packs a first character code in a string,
 or unpack a 8-bit number as a chracter code and returns a string containing it.</td></tr>
<tr><td><code>s</code></td><td>Packs character codes in a string according to the specified codec,
 or unpack 8-bit numbers as character codes according the specified codec and returns a string containing them.</td></tr>
</table>

You can specify a codec for `s` specifier by surrounding its name with `{` and `}`.


### {{ page.chapter }}.5.4. Pointer

`binary#pointer()`

`pointer#unpack()`

`pointer#pack()`


### {{ page.chapter }}.5.5. Binary as Stream

`binary#writer()`

`binary#reader()`

cast from `binary` to `stream`
