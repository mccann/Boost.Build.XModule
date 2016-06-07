# XModule Reference: cmake

Generate Makefiles from [cmake](https://cmake.org/) projects 

## Main target rules 

This rule is available primarily for testing and completeness. Typically, this target is an intermediate and has no need to be a named main target.

* **xmakefile**  
  Constructs an XMAKEFILE_EXO target.  

## Features

### CMake 

* <**xconfig**> _option_  
   **cmake** tool receives _option_ arguments when executed on XCMAKE source  
   Consult [cmake docs](https://cmake.org/) and external sources documentation for valid _options_  
   
### XModule

* <[xworkspace](xmodule.md#workspaces)> and related features  
  By default, the workspace created for the XMAKEFILE_EXO target is variant.
  It has no implicit ``<xinvariant>`` property.
 
### XToolset

* [xtoolset](xmodule.md#xtoolset)  
  Control the toolset used by external build system.
  
  In the specific case of **cmake** based builds, each relevant [xtoolset](xmodule.md#xtoolset) _subfeature_ is set as its corresponding environment variable or commandline option when executing **cmake**.

  By default, all configured toolset properties are inherited from the Boost.Build toolset associated with the target. If you are trying to set one or more of these properties instead of adding additional values, use the _xtoolset-forfeit_ feature to prevent inheritance.

  The table below shows the mapping between xtoolset subfeature, environment variable, and commanline option for **cmake** builds.

  xtoolset subfeature  | environment variable | commandline option
--------- | --- | ---
cc        | CC
cxx       | CXX
ld        | LD
ar        | | -DCMAKE_AR
nm        | | -DCMAKE_NM
ranlib    | | -DCMAKE_RANLIB
cflags    | CFLAGS
cxxflags  | CXXFLAGS
linkflags | LDFLAGS


### CMake Options

#### CMAKE_BUILD_TYPE

This option is set automatically depending upon Boost.Build's **variant** feature.  
If the **variant** feature is filtered by [xworkspace's](xmodule.md#workspaces) _xinvariant_ feature, the default value will be used.

\<variant> | Value | Note
--- | --- | ---
debug | Debug
 | Release | Default

#### BUILD_SHARED_LIBS

This option is set automatically depending upon Boost.Build's **link** feature.  
If **link** is filtered by [xworkspace's](xmodule.md#workspaces) _xinvariant_ feature, no value will be set.

\<link> | Value 
--- | --- 
static | OFF
shared | ON

## Notes

### Logs

* _workspace_/**log**/_xcmake-lists-txt-name_**.configure-log**


### Out of source clean builds

Configuration and subsequent build are performed from the **xbuild** target directory. This is an **out-of-source** build. This **xbuild** target directory is cleaned before configuration and building.

### Staged Builds and -DCMAKE_INSTALL_PREFIX

If the string ``-DCMAKE_INSTALL_PREFIX=`` is not found in the start of any ``<xconfig>`` property value then **cmake** recieves a ``-DCMAKE_INSTALL_PREFIX=`` argument with the **xdist** directory location. If you want the install action to write files into the **xdist** repository, and you have provided a custom ``-DCMAKE_INSTALL_PREFIX=`` argument you will need to ensure that the **xdist** generator has the ``<xdist-staged>yes`` property.

## Boost.Build Type Reference

 Type | Base Type | Infer from source file | Generate from | Notes
 --- | --- | :---: | :---: | --- 
XCMAKE | | ``CMakeLists.txt`` | | source file for **cmake** that builds ``Makefile``
[XMAKEFILE_EXO](make.md#boost.build-type-reference) | XMAKEFILE | | XCMAKE | [make](make.md) tool's build instructions for out-of-source build
