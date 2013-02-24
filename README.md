![banner](http://jxg.github.com/gura/images/banner.png)

Gura is an iterator-oriented programming language
that focuses on iterators with improved functions
for calculation and data processing.
It makes you be able to write an artificial code
for what used to need a lot of codes of repeat syntax.

Official Site
-------------
http://www.gura-lang.org/

Build for Windows
-----------------
1. Check if Visual Studio 2010 has been installed. You can use Express version as well.
2. Run a batch file gura\src\setup-gura-guest.bat, which downloads necessary packages
   from Git repository (https://github.com/ypsitau/gura-guest.git) and build them.
   The batch file may occur an error that says it cannot find vcvarsall.bat.
   In such a case, you have to edit gura\gura-guest\setup.bat
   and modify VCVARSALL variable so that it points to a right directory of Visual Studio.
3. Open gura\src\gura.sln with Visual Studio 2010, switch the configuration to Release
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

3. The default install path is /usr/local. Execute cmake as follows to change the path.

        $ cmake -D CMAKE_INSTALL_PREFIX=/usr ../src
