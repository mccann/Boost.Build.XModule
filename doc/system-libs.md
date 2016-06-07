# Ancillary Module Reference: system-libs

Link against System Librarys, without using search paths.

## How to use

Make rules available in your current module.
```
import system-libs ;
```

## Main target rules

* rule **system-libs** ( _names_ + : _properties_ * : _usage-requirements_ * )
  
  Scan search paths provided in _properties_ for the given _names_ libraries.
  
  _Names_ is a [glob](https://en.wikipedia.org/wiki/Glob_(programming)) pattern.
  
  _usage-requirements_ are passed to any created library as the respective argument.

  Returns the library names created.

### _Properties_

* <**path**> _path_  
  Search _path_ for libraries
  
* <**cc-search-dirs**>  
  If present search paths returned by ``cc -print-search-dirs``
  
* <**exclude**> _glob-pattern_  
  Exclude any libraries matched by _names_ and matched by _glob_pattern_.
  
* <_FEATURE_> _value_  
  Created lib will have <_FEATURE_>_value_ property in its requirements.  
  Libs that would conflict, are not created.
  
* <**target-prefix**> _prefix_  
  _prefix_ for the created main target name.
  
* <**threading-tag**> _tag_  
  postfix _tag_ of lib names that indicate threading distinction.  
  Specifically the _multi_ threaded type.  
  Boost example: **-mt**
  
* <**debug**>  
  Print debug information for each library made.

* <**headers-only**> _target_  
  Create a headers only alias target named _target_.

* <**system-lib-rpath**> **no** | **yes**  
  Default to **no**.  
  If **yes**, created lib will add its base-path to rpath for dependent linking targets.

#### OSX Specific

* <**homebrew**> _formula_  
  _formula_ to find library in.  
  If the _cellar_ for _formula_ has a **/include** path, it will be set as a property value for <**include**> feature of usage-requirements of created libraries.  
  Will prompt operate to brew install the formula if it isn't installed.
  
  
* <**homebrew-version**> _version_  
  Require formula identified by previous <**homebrew**> feature to be exact version identified by _version_.
  
* <**homebrew-with**> _arg-string_  
  Require formula identified by previous <**homebrew**> feature to have been installed **--with-**_arg-string_.
  
#### Debian Specific

* <**apt**> _package_  
  _package_ to find the library in.  
  If _package_ has a non-standard **include** path, it will be set as a property value for <**include**> feature of usage-requirements for created libraries.  
  

## Boost.Build Type Reference

Type | Base Type 
:--- | :--- 
SYSTEM_LIB | LIB 
