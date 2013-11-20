![banner](http://www.gura-lang.org/images/banner.png)

**Gura** is an iterator-oriented programming language that focuses on iterators
with improved functions for calculation and data processing.
It makes you be able to write an artificial code
for what used to need a lot of codes of repeat syntax.

The following **Gura** code prints content of a text file with line numbers.

    printf('%d %s', 1.., readlines('foo.txt'))

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
1. Check if build tools such as C++ compiler, make, cmake and necessary libraries
   have been installed.

   For Ubuntu, do the following command.

        $ sudo apt-get install build-essential cmake libreadline-dev

   For Fedora, do the following command.

        $ sudo yum install gcc gcc-c++ make cmake readline-devel

2. Run the following commands to build gura library and executable.

        $ git clone https://github.com/ypsitau/gura.git
        $ cd gura
        $ mkdir build
        $ cd build
        $ ../src/configure
        $ make

3. Make packages of Debian and RPM. Installation of following packages is necessary.

        $ sudo apt-get install rpm

   Run the following command.

        $ make package

   You can install package using an appropriate package manager.

   For Ubuntu:

        $ sudo dpkg -i gura-x.x.x-Linux.deb

   For RedHat:

        $ sudo rpm -i gura-x.x.x-Linux.rpm

4. Run the following command to build gura modules.

        $ ../src/build-modules.gura

  This may occur an error because of lacking packages. The script `build-modules.gura`
  generates shell scripts so that you can easily setup necessary packages.
  Run `install-deb.sh` for Ubuntu and `install-rpm.sh` for RedHat.

5. After you successfully build modules, do the following command to install them.

        $ sudo ../src/build-modules.gura install

Source URLs of Guest Libraries
------------------------------

<table>
<tr><td>dSFMT-src-2.2.1.zip</td><td>http://www.math.sci.hiroshima-u.ac.jp/~m-mat/MT/SFMT/index.html</td></tr>
<tr><td>combination.hpp</td><td>http://photon.poly.edu/~hbr/boost/combinations.html</td></tr>
</table>
