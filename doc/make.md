# XModule Reference: make
Build external sources with **make**

Generally, you'll need to generate a Makefile from an external configuration tool. 

#### Makefile generators

* [configure](configure.md)
* [cmake](cmake.md)

## Main target rules

* **xbuild**  
  When given a ``Makefile`` source (directly or indirectly), **make** will _build_ external sources. The target that this rule names is the directory and repository in which this build occurs  

* **xdist**  
  When given an XBUILD repository source generated from a ``Makefile``, **make** will _install_ the external sources binaries, libraries, headers, and, or whichever actions it performs into the configured installation target directory. The target that this rule names is that installation directory and repository  


## Features

### XModule

For all **make** derived XBUILD and XDIST targets the following list of documented features are relevant.

* <[xpatch](patch.md)> _patch-file_  
 
* <[xaction](action.md)> _@rule-or-action_  

### XBUILD 

Control **make** _build_ actions of the XBUILD derived types: XMAKE_SRC_BUILD and XMAKE_EXO_BUILD with properties based on these features:
  
* <**xmake-env**> _VAR=value_  
  set environment variable _VAR_ to _value_  
      
* <**xbuild-arg**> _ARG_  
  _ARG_ passed to **make** plainly
  When not set, **make** receives no argument, taking default action  

* <**xbuild-jobs**> _N_  
  Passed to **make** with the ``-j`` flag  
  Defaults to a value proportional to invoked boost.build executable's ``-j`` value  

### XDIST

Control **make** _install_ actions of the XDIST derived type XMAKE_DIST with properties based on these features:

* <**xdist-arg**> _ARG_  
  _ARG_ passed to **make** plainly  
  When not set, **make** receives an ``install`` argument  
 
* <**xdist-jobs**> _N_  
  Passed to **make** as the ``-j`` flag  
  Defaults to ``1``  
  When _N_ has the value: ``%default%``, **make** will receive a `-j` flag which has the same value as default for <**xbuild-jobs**> feature  

* <**xdist-location**>  
  Control location of 'xdist' directory. 
  TODO: Document & Test 

* <**xdist-staged**> _no_ | _yes_  
  If _yes_, use ``DESTDIR={xdist-directory}`` as argument to **make**  
  Defaults to _no_  


## Notes

### Logs

* _workspace_/**log**/make-build.log
* _workspace_/**log**/make-install.log

### Serialization
XBUILD and XDIST actions execute in serial by using a [JAM_SEMAPHORE](http://www.boost.org/build/doc/html/jam/language.html#jam.language.variables.builtins.semaphores). This mitigates CPU, memory and other resource utilization.

## Boost.Build Type Reference

Type | Base Type | Infer from source file | Generate from | Notes
--- | --- | :---: | :---: | --- 
XMAKEFILE | | | | base type 
XMAKEFILE_SRC | XMAKEFILE | ``Makefile`` | | source Makefile (not generated) 
XMAKEFILE_EXO | XMAKEFILE | | [Makefile Generators](#makefile-generators) | generated Makefile 
XMAKE_SRC_BUILD | XBUILD | | XMAKEFILE_SRC | build in source directory
XMAKE_EXO_BUILD | XBUILD | | XMAKEFILE_EXO | build out-of-source in clean build directory
XMAKE_DIST | XDIST | | XMAKE_SRC_BUILD \| XMAKE_EXO_BUILD
