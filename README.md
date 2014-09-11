![banner](http://www.gura-lang.org/images/banner.png)

**Gura** is an iterator-oriented programming language that focuses on
iterators with improved functions for calculation and data processing.
It makes you be able to write an artificial code for what used to need a lot
of codes of repeat syntax.

The following **Gura** code prints content of a text file with line numbers.

    printf('%d %s', 1.., readlines('foo.txt'))

Official Site
-------------
http://www.gura-lang.org/


Build for Windows
-----------------
1. Check if you have installed Visual Studio 2010 and applied Visual Studio 2010 Service Pack 1 on it.
   Service Pack 1 is necessary to avoid LNK1123 error.
   
   You can use Express version of Visual Studio 2010 as well.

2. Run a batch file `gura\src\setup-env-mswin.bat`, which downloads document
   files and necessary packages from Git repository and build libraries.

   The batch file may occur an error that says it cannot find `vcvarsall.bat`.
   In such a case, you have to edit `gura\gura-guest\setup.bat`
   and modify `VCVARSALL` variable so that it points to a right directory of
   Visual Studio.

3. Open `gura\gura.sln` with Visual Studio 2010, switch the configuration to
   `Release` and build it.


Build for Mac OSX
-----------------
1. Make sure that Xcode, Command Line Developer Tools
   and [CMake](http://www.cmake.org/download/) have been installed in your system.

   If you've installed CMake by a Disk Image File (*.dmg),
   create a link to the `cmake` executable in a directory that is in your PATH.

        $ sudo ln -s /Applications/CMake.app/Contents/bin/cmake /usr/bin/cmake

2. Clone Gura source code from GitHub repository.

        $ git clone https://github.com/gura-lang/gura.git

   I'm afraid that would take much time as it tries to retrieve all the history.
   The following command could save your important time.
   
        $ git clone https://github.com/gura-lang/gura.git --depth 1

3. Run the following commands to build guest libraries and copy their dynamic libraries
   to a specified directory.
   *You can skip this process if you just want to try Gura interpreter itself.*

        $ pushd gura/guests
        $ ./prepare-for-darwin
		$ sudo ./prepare-for-darwin install
        $ popd

4. Run the following commands to build and install **Gura** interpreter.

		$ cd gura
        $ mkdir build
        $ cd build
        $ ../configure
        $ make
        $ sudo make install

5. Run the following commands to build and install **Gura** modules.
   *You can skip this process if you just want to try Gura interpreter itself.*

        $ ./build-modules
        $ sudo ./build-modules install

6. Execute `gura` to check if it's been properly built.

        $ gura
		Gura x.x.x [GNUC v.x.x, xxx xx xxxx] Copyright (C) 2011-2014 ypsitau
		>>>

   Enter a short script:
   
		>>> println(1..5)
		1
		2
		3
		4
		5

Installed files and directories are shown below.
Remove them when you need to uninstall Gura.

    /usr/bin/gura
    /usr/lib/libguracore.*
    /usr/lib/gura/
    /usr/include/gura/
    /usr/share/gura/


Build for Linux
---------------
1. Check if build tools such as C++ compiler, make, cmake and necessary
   libraries have been installed.

   For Ubuntu, do the following command.

        $ sudo apt-get install build-essential cmake libreadline-dev rpm

   For Fedora, do the following command.

        # yum install gcc gcc-c++ make cmake readline-devel rpm-build

2. Clone Gura source code from GitHub repository.

        $ git clone https://github.com/gura-lang/gura.git

   I'm afraid that would take much time as it tries to retrieve all the history.
   The following command could save your important time.
   
        $ git clone https://github.com/gura-lang/gura.git --depth 1

3. Run the following commands to build and install **Gura** interpreter.

		$ cd gura
        $ mkdir build
        $ cd build
        $ ../configure
        $ make
        $ sudo make install
        $ sudo ldconfig     # only necessary for the first install

4. Run the following commands to build and install **Gura** modules.
   *You can skip this process if you just want to try Gura interpreter itself.*

        $ sudo ./setup-guest
        $ ./build-modules
        $ sudo ./build-modules install

5. Execute `gura` to check if it's been properly built.

        $ gura
		Gura x.x.x [GNUC v.x.x, xxx xx xxxx] Copyright (C) 2011-2014 ypsitau
		>>>

   Enter a short script:
   
		>>> println(1..5)
		1
		2
		3
		4
		5

Generated Makefile is capable of creating both Debian and RPM install packages.

Run the following command to create Debian and RPM packages.

    $ make package

You can install the package using an appropriate package manager as following.

For Ubuntu:

    $ sudo dpkg -i gura-x.x.x-Linux.deb

For Fedora:

    $ sudo rpm -i gura-x.x.x-Linux.rpm
