Gura Programming Language
=========================
Gura is an iterator-oriented programming language
that focuses on iterators with improved functions
for calculation and data processing.
It makes you be able to write an artificial code
for what used to need a lot of codes of repeat syntax.

Reference
---------
http://gura.sourceforge.jp/

Build for Windows
-----------------
At first, you have to build necessary libraries by executing gura/guest/setup.bat.
And then, open gura/src/gura.sln with Visual Studio 2010, change configuration to Release
and build it.

Build for Linux
-----------------
Run the following commands.

    $ cd gura
    $ mkdir build
    $ cd build
    $ cmake ../src
    $ make
    $ sudo make install
    $ sudo ldconfig
    $ ../src/build_modules.gura
    $ sudo ../src/build_modules.gura install
