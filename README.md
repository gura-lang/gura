# Gura Programming Language

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
1. You need to have installed Visual Studio 2015, which is now available
   as Visual Studio Community for FREE from
   [Visual Studio download page](https://www.visualstudio.com/downloads).

2. Clone Gura source code from GitHub repository.

        $ git clone https://github.com/gura-lang/gura.git

   I'm afraid that would take much time as it tries to retrieve all the commitment history.
   The following command could save your important time.

        $ git clone https://github.com/gura-lang/gura.git --depth 1

3. Run a batch file `gura\guest\prepare-for-mswin.bat`, which downloads
   necessary library packages from Gura's official site and build them.

   The batch file may occur an error that says it cannot find `vcvarsall.bat`.
   This is likely because you have installed Visual Studio environment in a directory
   different from the default one.
   In such a case, you have to edit `gura\guest\prepare-for-mswin.bat`
   and modify `VCVARSALL` variable so that it points to a right directory of
   Visual Studio.

4. Open `gura\gura.sln` with Visual Studio 2015, switch the configuration to
   `Release` and build it.

5. Now, you can find an installer file named like `gura-x.x.x-win32.msi` in `gura\dist` directory.

6. Just launch the installer for the installation.

7. You can find Gura folder in Start Menu. Launch `Gura Console` and try some scripts like:

        >>> println(1..5)
        1
        2
        3
        4
        5


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

3. Run the following commands that build guest libraries and copy their dynamic libraries
   to a specified directory.
   *You can skip this process if you just want to try Gura interpreter itself.*

        $ pushd gura/guests
        $ ./prepare-for-darwin
		$ sudo ./prepare-for-darwin install
        $ popd

4. Run the following commands to build **Gura** interpreter.

		$ cd gura
        $ mkdir build
        $ cd build
        $ ../configure
        $ make

5. Run the following commands to build **Gura** modules.
   *You can skip this process if you just want to try Gura interpreter itself.*

        $ ./build-modules

6. Run the following command to create a disk image file named like `gura-x.x.x.dmg`.

        $ make package

   Open it and install the content by dragging an icon `Gura.app`.

7. Launching `Gura.app` will open a terminal application with Gura console.
   Try some scripts:

		>>> println(1..5)
		1
		2
		3
		4
		5


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

3. Run the following commands to build **Gura** interpreter.

		$ cd gura
        $ mkdir build
        $ cd build
        $ ../configure
        $ make

4. Run the following commands to build **Gura** modules.
   *You can skip this process if you just want to try Gura interpreter itself.*

        $ sudo ./setup-guest
        $ ./build-modules

5. Run the following command to create a package file:
   DEB package file named like `gura-x.x.x-ubuntu.deb` for Ubuntu
   and RPM package file named like `gura-x.x.x-fedora.deb` for Fedora.

        $ make package

6. Install the package.

   For Ubuntu:

        $ sudo dpkg -i gura-x.x.x-ubuntu.deb

   For Fedora:

        $ sudo rpm -i gura-x.x.x-fedora.rpm

7. Execute `gura` and try some scripts:

		>>> println(1..5)
		1
		2
		3
		4
		5
