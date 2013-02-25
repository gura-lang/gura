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

   For Ubuntu, do the following command.

        $ sudo apt-get install build-essential cmake libreadline-dev

2. Run the following commands to build gura library and executable.

        $ git clone https://github.com/ypsitau/gura.git
        $ cd gura
        $ mkdir build
        $ cd build
        $ cmake -D CMAKE_INSTALL_PREFIX=/usr ../src
        $ make
        $ sudo make install
        $ sudo ldconfig

3. Run the following command to build gura modules.

        $ ../src/build_modules.gura

  This may occur an error because of lacking packages. The script build_modules.gura
  generates shell scripts so that you can easily setup necessary packages.
  Run `install-deb.sh` for Ubuntu and `install-rpm.sh` for RedHat.

4. After you successfully build modules, do the following command to install them.

        $ sudo ../src/build_modules.gura install

