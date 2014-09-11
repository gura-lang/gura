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
   Release and build it.


Build for Mac OSX
-----------------
1. Make sure that Xcode, Command Line Developer Tools
   and [CMake](http://www.cmake.org/download/) have been installed in your system.

2. Download Gura source code from GitHub repository.

        $ git clone https://github.com/gura-lang/gura.git

3. Run the following commands to build guest libraries and copy their dynamic libraries
   to the specified directory.

        $ pushd gura/guests
        $ ./prepare-for-darwin
		$ sudo ./prepare-for-darwin install
        $ popd

4. Run the following commands to build **Gura** library and executable.

		$ cd gura
        $ mkdir build
        $ cd build
        $ ../configure
        $ make
        $ ./build-modules

5. Run the following command to install **Gura** library and executable.

        $ sudo make install
        $ sudo ./build-modules install


Build for Linux
---------------
1. Check if build tools such as C++ compiler, make, cmake and necessary
   libraries have been installed.

   For Ubuntu, do the following command.

        $ sudo apt-get install build-essential cmake libreadline-dev rpm

   For Fedora, do the following command.

        # yum install gcc gcc-c++ make cmake readline-devel rpm-build

2. Run the following commands to build **Gura** library and executable.

        $ git clone https://github.com/gura-lang/gura.git
        $ cd gura
        $ mkdir build
        $ cd build
        $ ../configure
        $ make
        $ sudo ./setup-guest
        $ ./build-modules

4. Run the following command to build **Gura** modules files.

        $ ./build-modules

3. Run the following command to install **Gura** library and executable.

        $ sudo make install
        $ sudo ldconfig     # only necessary for the first install
        $ sudo ./build-modules install

Generated Makefile is capable of creating both Debian and RPM install packages.

Run the following command to create Debian and RPM packages.

    $ make package

You can install the package using an appropriate package manager as following.

For Ubuntu:

    $ sudo dpkg -i gura-x.x.x-Linux.deb

For Fedora:

    $ sudo rpm -i gura-x.x.x-Linux.rpm
