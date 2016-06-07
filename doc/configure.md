# XModule Reference: configure

Generate Makefiles from "Autotools Like" projects 

## Main target rules 

These rules are available primarily for testing and completeness. Typically, these targets are intermediates and have no need to be named main targets.

* **xconfigure**  
  Constructs a named XCONFIGURE target.  
  
* **xmakefile**  
  Constructs an XMAKEFILE_EXO target.  


## Features


### Configure

* <**xbuildconf-arg**> _option_  
   XBUILDCONF script receives _option_ arguments when executed


* <**xconfig**> _option_  
   XCONFIGURE script receives _option_ arguments when executed  
   Discover possible _options_ with the following command: ``./configure --help``

### XModule

* <[xworkspace](xmodule.md#workspaces)> and related features  
  By default, the workspace created for the XMAKEFILE_EXO target is variant.
  It has no implicit ``<xinvariant>`` property.

### XToolset

* [xtoolset](xmodule.md#xtoolset)  
  Control the toolset used by external build system.
  
  In the specific case of ``configure`` based builds, the relevant [xtoolset](xmodule.md#xtoolset) _subfeatures_ are set as their corresponding environment variables for the script's execution.
  
  By default, all configured toolset properties are inherited from the Boost.Build toolset associated with the target. If you are trying to set one or more of these properties instead of adding additional values, use the _xtoolset-forfeit_ feature to prevent inheritance.

  The table below shows the mapping between xtoolset subfeature and environment variable for ``configure`` scripts.

  xtoolset subfeature  | environment variable 
  --------- | ---
  cc        | CC
  cxx       | CXX
  ld        | LD
  ar        | AR
  nm        | NM
  ranlib    | RANLIB
  cflags    | CFLAGS
  cxxflags  | CXXFLAGS
  linkflags | LDFLAGS

## Notes

### Logs

* _workspace_/**log**/_xbuildconf-script-name_**.log**
* _workspace_/**log**/_xconfigure-script-name_**.configure-log**


### Serialization

Execution of these scripts is serialized per ``Makefile`` target with a [JAM_SEMAPHORE](http://www.boost.org/build/doc/html/jam/language.html#jam.language.variables.builtins.semaphores). This prevents bugs that can arise from configure and pre-configure scripts executing from the same sources simultaneously.

### Out of source clean builds

Configuration and subsequent build are performed from the **xbuild** target directory. This is an **out-of-source** build. This **xbuild** target directory is cleaned before configuration and building.

### Timestamp Skew Fix

For external sources that may have problems building due to timestamps not being preserved properly, the XCONFIGURE to XMAKEFILE generator will perform a **"Skew Fix"** procedure on timestamps of sources when it finds ``aclocal.m4`` files.

The procedure is similar to the one proposed and explained in more detail at: https://www.gnu.org/software/automake/manual/html_node/CVS.html

### Staged Builds and --prefix

If the string ``--prefix=`` is not found in the start of any ``<xconfig>`` property value then the ``configure`` script recieves a ``--prefix=`` argument with the **xdist** directory location. If you want the install action to write files into the **xdist** repository, and you have provided a custom ``--prefix=`` argument you will need to ensure that the **xdist** generator has the ``<xdist-staged>yes`` property.

## Boost.Build Type Reference

 Type | Base Type | Infer from source file | Generate from | Notes
 --- | --- | :---: | :---: | --- 
XBUILDCONF | | ``buildconf``, ``autogen.sh``, ``bootstrap`` | | pre-configure / bootstrap scripts 
XCONFIGURE | | ``configure`` | XBUILDCONF | script that builds ``Makefile``
[XMAKEFILE_EXO](make.md#boost.build-type.details) | XMAKEFILE | | XCONFIGURE | [make](make.md) tool's build instructions for out-of-source build
