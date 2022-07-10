This dirctory contains a set of Visual Studio 2008 build projects for the 
current simh code base.  When used (with Visual Studio Express 2008 or 
or a later Visual Studio version) it populates a directory tree under the 
BIN directory of the Simh distribution for temporary build files and 
produces resulting executables in the BIN/NT/Win32-Debug or 
BIN/NT/Win32-Release directories (depending on whether you target a Debug 
or Release build).

These projects, when used with Visual Studio 2008, will produce Release 
build binaries that will run on Windows versions from XP onward.  Building
with later versions of Visual Studio will have different Windows version
compatibility.

The Visual Studio Projects expect that various dependent packages that
the SIMH code depends on are available in a sub-directories of the 
simh directory.  

For Example, the directory structure should look like:

    ...\simh\VAX\vax_cpu.c
    ...\simh\scp.c
    ...\simh\Visual Studio Projects\simh.sln
    ...\simh\Visual Studio Projects\VAX.vcproj
    ...\simh\BIN\Nt\Win32-Release\vax.exe
    ...\simh\WindowsBuild\include\SDL2\SDL.h
    ...\simh\WindowsBuild\pthreads\pthread.h
    ...\simh\WindowsBuild\winpcap\WpdPack\Lib\wpcap.lib

Network devices are capable of using pthreads to enhance their performance.  
To realize these benefits, you must build the desire simulator with 
USE_READER_THREAD defined.  The relevant simulators which have network 
support are all of the VAX simulators, the PDP11 simulator and the various
PDP10 simulators.

Additionally, simulators which contain devices that use the asynchronous
APIs in sim_disk.c and sim_tape.c can also achieve greater performance by
leveraging pthreads to perform blocking I/O in separate threads.  Currently
the simulators which have such devices are all of the VAX simulators and 
the PDP11.  To achieve these benefits the simulators must be built with 
SIM_ASYNCH_IO defined.

The project files in this directory build these simulators with support for
both network and asynchronous I/O.

To build any of the supported simulators you should open the simh.sln file 
in this directory.

---

The installer for Visual Studio 2008 SP1 is available from:

http://download.microsoft.com/download/E/8/E/E8EEB394-7F42-4963-A2D8-29559B738298/VS2008ExpressWithSP1ENUX1504728.iso

Then install Visual Studio Express Visual C++ by executing VCExpress\setup.exe 
on that DVD image.  No need to install "Silverlight Runtime" or 
"Microsoft SQL Server 2008 Express Edition".  Depending on your OS Version 
you may be prompted to install an older version of .NET Framework which should 
be installed.

Note: VS2008 can readily coexist on Windows systems that also have later 
versions of Visual Studio installed.

---

If you are using a version of Visual Studio beyond Visual Studio 2008, then 
your later version of Visual Studio will automatically convert the Visual 
Studio 2008 project files.  You should ignore any warnings produced by the 
conversion process.

The current version of Visual Studio is available at:  https://visualstudio.microsoft.com/

	The free Community version is sufficient for building the SIMH simulators

---

If you have Visual Studio installed and want to build all the
simulators from a command prompt, the file build_vstudio.bat in the root
of the simh source tree will do that without any furthur interaction.

---


| 	WindowsBuild integration into SIMH Base project - 06-10-2022 - SgC
|		Windows Build files are now part of the Base repository
