# XModule Reference: dpkg / checkinstall

Create **.deb** packages from xmodule repositories with [checkinstall](https://debian-administration.org/article/147/Installing_packages_from_source_code_with_checkinstall) 

## Main target rules

* **xdpkg**  
  Construct a package file from one or more xmodule repository sources.  
  
## Features

### Checkinstall 

See checkinstall manpage for details on these features:

* <**xdpkg-name**> _name_  

* <**xdpkg-version**> _version_  

* <**xdpkg-description**> _description_  
  Can have newlines
  
* <**xdpkg-release**> _release_  

* <**xdpkg-arch**> _arch_  

* <**xdpkg-maintainer**> _maintainer_  

* <**xdpkg-license**> _license_  

* <**xdpkg-group**> _group_  

* <**xdpkg-provides**> _provides_  

* <**xdpkg-requires**> _dependency_  
  Multiple dependencies will be joined with ``,`` and ``()<>`` characters will be escaped automatically.  
  See http://stackoverflow.com/questions/18365600/how-to-manage-multiple-package-dependencies-with-checkinstall for syntax.  

* <**xdpkg-strip**> yes | no  
  Default: yes

* <**xdpkg-stripso**> yes | no  
  Default: yes


The following two filtering features are like the checkinstall named arguments, but are implemented differently.  
Instead, these patterns are path GLOB patterns as documented in **find** utility

* <**xdpkg-exclude**> _exclude-pattern_  

* <**xdpkg-include**> _exclude-pattern_  
   
 
This feature is not from checkinstall.

* <**xdpkg-sysroot**> _path_  
  System root path.  
  Default: **/**
  
  
### XModule

* <[xworkspace](xmodule.md#workspaces)> and related features  
  By default, the workspace for an XDPKG target is variant.  
  It has no implicit ``<xinvariant>`` property.

## Commandline Arguments

* **--xdpkg-target-path=**_PATH_  
  Path is relative to the CWD and indicates where to put the generated package.  
  By default this is the normal build-dir location generated for targets.
  
* **--xdpkg-**_FEATURE_**=**_VALUE_  
  Where _FEATURE_ is a lowercase string matching any of the <**xdpkg-**_FEATURE_> from above.  
  When specified, such commandline property will override any properties of the same feature for all XDPKG targets generated.  
  This is useful for package generation builds that build just one target.
  
## Notes

### Logs

* _workspace_/**log**/_name_**-checkinstall.log**


## Boost.Build Type Reference

Type | Base Type | Infer from source | Generate from
:---: | :---: | :---: | :---:
XDPKG | | ``*.deb`` | XDIST, XBUILD, XREPO
