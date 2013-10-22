MML Syntax
==========
Note character is one of `A`, `B`, `C`, `D`, `E`, `F` and `G`,
which is followed by halftone spcifier `#`, `+` or `-`.
You can take the tone half up by `#` or `+` and down by `-`.

After that, a number that indicates a note length follows.
For example, `C4` means it make a sound of C during a time of a quoter note.

A dot character follows the length number for dotted note.
For example, `C4.` is a dotted quoter note.

If a length number is omitted, a default length speicified by `L` operater would be used.
The length of that operater is described in the same manner with notes as above.
For example, `L8` set the default length to a eighth note.
If `L` operater doesn't exist, a quarter length is used as a default.

Optionally, a gate time can be specified in a number of eighth.
For example, `C4,1` means that it occupies a time of a quoter note
but actually sounds during a eighth of that.
The number of gate time is between 0 and 8,
where 0 means no sound and 8 means the full length.
A gate time is meant to be used to indicate a staccato.

Rest can be specified by a character `R` followed by a length in the same manner as notes.
For example, `R4` means a rest of a quoter time.
As like notes, the length of note can also be omitted.
In that case, the default length specified by `L` would be used.


`(..)n`


Repeat of 
`[`*body*`|`*last*`]`*n*


Octave is temporarily turned up and down by specifying `~` and `_` before a note character.
`On`
`<`, `>`

`:`

`&`


`Qn`



`Vn`

`@n` `@{name}

`Tn`

Each track is separated with a character `;`.

You can write comments either in an inline format or a block format.
An inline comment begins with `//` and ends with end of line.
A block comment begins with `/*` and ends with `*/` and can contain more than one line.
