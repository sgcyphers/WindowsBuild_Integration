
# WindowsBuild Maintainer Documentation



These are the instructions for maintaining and updating the files used to build Windows versions of the OpenSIMH emulators.

The essential files for building Windows based emulators are located in the WindowsBuild and Visual Studio Projects
directories of the OpenSIMH master repository.


The WindowsBuild directory contains about 150 mb of files used by Visual Studio and by Makefile (which uses gcc by default).

However, the packages used to build the Libraries, Header fuiles and Include files comprise 800 mb (before actually building 
the Libraries.)  This is too large to try to include in the OpenSIMH repository, so only the essential files are included.
Building updated versions need to be performed separately and then copied to WindowsBuild.

The scratch directory that I used to compile and link the libaries used close to 2.5 gb, far to large to even put in the 
Maintainer repository.  So, the maintainer repository includes just the files and packages needed by the Maintainer to
perform any upgrades. It is recommended to copy the Maintainer-Files to a scratch directory and perform compiling, linking 
and testing there.


The packages used by OpenSIMH for compiling and linking the simulators are:

	libpng
	zlib
	PCRE
	pthreads
	winpcap / pcap
	SDL2
	SDL2_ttf
	Windows DirectX SDK
	
	
	
 ***
 ***
 
## LibPNG
------

	Portable Network Graphics:

	https://www.libpng.org/

Software is available under Open Source licensing (http://www.libpng.org/pub/png/src/libpng-LICENSE.txt)



The files can be found in http://www.libpng.org/pub/png/libpng.html under Source Code
	and
can be found at http://www.zlib.net/zlib-1.2.12.tar.gz

The latest version is v1.6.37.  (There are vulnerability warnings for previous versions, so use this version.)

Libpng also requires zlib to function.  The libpng Visual Studio projects also build the zlib libraries at the same time.

Files that have been modified from the base v1.6.37 distribution are also located in Maintainer-Files\libpng\ModifiedFiles

Assuming you are building the package in Maintainer-Files\libpng-1.6.37, you will need to put zlib in Maintainer-Files\zlib-1.2.12.
Then, when you build libpng from the libpng-1.6.37\projects\vstudio20nn\vstudio.sln, the following files are copied 
to the Maintainer-Files\include directory:

	png.h
	pngconf.h
	pnglibconf.h
	zconf.h
	zlib.h
	
It will also populate the Maintainer-Files\lib\vstudio20nn\release and debug directories with these library
files (and corresponding .pdb debug file):

	libpng16.lib
	zlib.ldb
	
If the builds are successfull you can then move the files to the respective WindowsBuild\include and \lib\vc20nn\release (\debug)
directories.

*** I still don't really understand why there's so many versions and what version of the files go into the WindowsBuild\lib\Release directory. ***
*** And since I have VC2008, VS2017, VS2019 and VS2022 all installed, I may not be able to determine that. ***
*** So, I build all four versions...  I also do the builds in a Scratch directory structure  so as to not pollute the repositories. ***

	
	
(The libpng.vcxproj files have been modified from the original windows-build versions to make the file
copying the same across Visual Studio versions)
(The zlib .vcproj and .vcxproj files have been updated to utilize zlib-1.2.12)
(Because older VS versions are obsolete and unavailable, windows-build project files for VS10, VS12 and VS15 have been dropped.)
	
	

***
***

## zlib
----

	zlib General Compression Software
	
	https://www.zlib.net
	
Software is available under Open Source licensing (http://www.zlib.net/zlib_license.html)

The latest version is v1.2.12.  This is the recommended due to bugs found in v1.2.11
(V1.2.11 was previously used by windows-build)

The libpng Visual Studio projects also build the zlib libraries at the same time.
See the libpng documentation for information on zlib.lib, zconf.h and zlib.h


***
***

## PCRE
----

	POSIX Compatible Regular Expressions

	https://www.pcre.org/

Software is available under BSD licensing (https://www.pcre.org/licence.txt)

PCRE is now at end of life, and is no longer being actively maintained. 
Version 8.45 is expected to be the final release of the older PCRE library, and new projects should use PCRE2 instead.

The last version of PCRE is v8.45
SIMH used PCRE version 8.43, it is now updated to v8.45 which has some important bugfixes.
There probably is not a need to upgrade to PCRE2.

The PCRE directory contains pcre-vsbuild which is modifiec code for SIMH.  It has been modified from the 
original windows-build to build pcre v8.45.  The librearies are built from:

	WindowsBuild_Integration\Maintainer-Files\PCRE\pcre-vsbuild\build\vc2008\pcre.sln
	
The resulting libraries are in subdirectories of \vc2008\  Only a few of the files need to be copied
to WindowsBuild\lib:

	WindowsBuild\lib\lib-2008\release\pcreposixstatic.lib
	WindowsBuild\lib\lib-2008\release\pcrestatic.lib
	WindowsBuild\lib\release\pcreposixstatic.lib
	WindowsBuild\lib\release\pcrestatic.lib
	WindowsBuild\lib\lib-2008\debug\pcreposixstaticd.lib and .pdb
	WindowsBuild\lib\lib-2008\debug\pcrestaticd.lib and .pdb
	WindowsBuild\lib\debug\pcreposixstaticd.lib and .pdb 
	WindowsBuild\lib\debug\pcrestaticd.lib and .pdb
	
The PCRE\include\pcre.h and pcreposix.h need to be copied to WindowsBuild\include

	
---

There will probably never be a need to update or change the .\WindowsBuild\include\pcre files
There will probably never be a need to update or change the .\WindowsBuild\lib\*\pcre libraries

***
***

## pthreads
--------


POSIX Threads for Windows implementation comes from:

	Sourceforge.net/projects/pthreads4w


Author is:	Ross P Johnson


SIMH uses version 2.11.1 

The current version on sourceforge.net/projects/pthreads4w is v3.0.0.
From what I can determine, it is major upgrade without major benefit to SIMH at this time.



WindowsBuild\include has four header files from pthreads:

	_ptw32.h, config.h, pthread.h and sched.h


WindowsBuild\pthreads\Pre-built.2\lib contains a files that is used in SIMH builds, generated by Mark Pizzolato
pthreads\Pre-Built.2\lib\libpthreadGC2.a is the gnu library file (compiled with gcc with no extrnal error handler).  
The pthreads\README explains this much better.

pthreads.c #INCLUDES most of the .c programs in pthreads\

pthreads\ and pthreads\Pre-Built.2 directories will (probably) not need to be updated in the near (or far?) future.


***
***

## PCAP / WinPCAP / NPCAP 
---------------------

The Windows Packet Capture API comes from:

	https://www.winpcap.org/

Software is available under license similar to MIT license (https://www.winpcap.org/misc/copyright.htm)


The files that are found in: 	.\WindowsBuild\include\pcap
come from: 	.\Maintiner-Files\PCAP\WpdPack\include\pcap


The rest of the files in .\Maintainer-Files\PCAP are not needed to build simulators

The last version available is:	v4.1.3 (08-Mar-2013)
The version used by SIMH is:	v4.1.2 (02-Jul-2010)
The seven files used by SIMH are identical between versions 4.1.2 and 4.1.3

---

There will probably never be a need to update or change the .\WindowsBuild\include\pcap files

---

IMPORTANT NOTE:

NPCAP is the Nmap Project's packet capture and sending library for Microsoft Windows that
replaces WinPCAP. It supports the new NDIS 6 API in Windows 10 and later.

Development on WinPCAP has ceased.  Windows 10 and later no longer have NDIS5 support and
WinPCAP will not work for users that want to use a PCAP capture library with a SIMH simulator.

The user will need to download NPCAP from https://npcap.com/#download and install it themselves, 
using the "WinPCAP API-compatible mode".

Note that NPCAP is free install for users (on up to 5 systems), but the SDK and developer code is not.
So SIMH uses the WinPCAP API which is still compatible with NPCAP, and has more faorable licensing.

More information is available at:

	https://npcap.com/
	https://npcap.com/windows-10.html


***
***

## SDL2
----

SDL - Simple Directmedia Layer implementation comes from:

	https://www.libsdl.org/


Software is available under the zlib license (https://www.zlib.net/zlib_license.html)

The latest supported version at libdsl.org is v2.0.22 (25-Apr-2022)
The version used by SIMH is v2.0.20 (11-Jan-2022)

If no incompatibilities are found, OpenSIMH will be updated to v2.0.22 with the
WindowsBuild Integration. (Better Wayland and Clang support, bug fixees)

The files in WindowsBuild\include\SDL2\ come from the SDL2 distribution, SDL2-2.0.22\include\



# ***Document this build process***

------

Version 2.0.22 can also be downloaded from:

	(Windows 32/64-bit)	https://www.libsdl.org/release/SDL2-2.0.22.zip
	(Mac OS X)		https://www.libsdl.org/release/SDL2-2.0.22.dmg

Linux code is available as as an installable package using  apt-get for Debian or yum for Fedora
or at:
	(Linux)			https://www.libsdl.org/release/SDL2-2.0.22.tar.gz

The Github site for ongoing development is at:

		https://github.com/libsdl-org/SDL


***
***

## SDL2_ttf
--------


SDL2 True Type Fonts (ttf) implementation comes from LIBDSL.org:

	https://github.com/libsdl-org/SDL_ttf
	https://www.libsdl.org/projects/SDL_ttf/release/

Software is available under the zlib license (https://www.zlib.net/zlib_license.html)

The latest supported version at libdsl.org is v2.0.18 (11-Jan-2022)
The version used by SIMH is v2.0.12 (17-Aug-2013)

If no incompatibilities are found, OpenSIMH will be updated to v2.0.18 with the
WindowsBuild Integration. 


Version 2.0.18 can also be downloaded from:

	(Windows 32/64-bit)	https://www.libsdl.org/projects/SDL_ttf/release/SDL2_ttf-2.0.18.zip
	(Mac OS X)		https://www.libsdl.org/projects/SDL_ttf/release/SDL2_ttf-2.0.18.dmg

Runtime Binaries are at:

	(Windows 32-bit)	https://www.libsdl.org/projects/SDL_ttf/release/SDL2_ttf-2.0.18-win32-x86.zip
	(Windows 64-bit)	https://www.libsdl.org/projects/SDL_ttf/release/SDL2_ttf-2.0.18-win32-x64.zip
				(64-bit is not used in the OpenSIMH implementations)

Development code is available at:

	(Visual C++ 32/64-bit)	https://www.libsdl.org/projects/SDL_ttf/release/SDL2_ttf-devel-2.0.18-VC.zip
	(MinGW 32/54-bit)	https://www.libsdl.org/projects/SDL_ttf/release/SDL2_ttf-devel-2.0.18-mingw.tar.gz

Linux code is available as as an installable package using  apt-get for Debian or yum for Fedora
or at:

	(Linux)			https://www.libsdl.org/projects/SDL_ttf/release/SDL2_ttf-2.0.18.tar.gz

The Github site for ongoing development is at:

		https://github.com/libsdl-org/SDL_ttf


The only simulator that uses SDL_ttf appears to be BESM6.


SDL2_ttf and freetype have not been updated at this time. (Can of worms)
SDL2_ttf v2.0.12 and Freetype v2.4.12 are the versions still used by OpenSIMH.

The include files have been moved to WindowsBuild\include\SDL2_ttf for consistency, instead of residing
in a directory that included version numbers.


***
***

