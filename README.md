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
1. Check if Visual Studio 2010 has been installed. You can use Express version as well.
2. Build necessary libraries by executing gura/guest/setup.bat.
3. Open gura/src/gura.sln with Visual Studio 2010, switch the configuration to Release
   and build it.

Build for Linux
-----------------
1. Check if build tools such as g++, make and cmake have been installed.
2. Run the following commands.

        $ cd gura
        $ mkdir build
        $ cd build
        $ cmake ../src
        $ make
        $ sudo make install
        $ sudo ldconfig
        $ ../src/build_modules.gura
        $ sudo ../src/build_modules.gura install
