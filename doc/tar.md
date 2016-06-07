# XModule Reference: tar 

Create repositories from "_tarballs_" with [tar](https://en.wikipedia.org/wiki/Tar_(computing)) 

## Main target rules

* **xrepo**  
  Construct an XREPO Repository target from the _tar_ file.  
  
## Features

### Tar 

* <**xtar-arg**> _option_  
   **tar** tool receives _option_ arguments when executed on XTAR source.  
   Consult your system's tar manpage for valid _options_.  

### XModule

* <[xworkspace](xmodule.md#workspaces)> and related features  
  By default, the workspace for a **tar** XREPO target is invariant.  
  It has an implicit ``<xinvariant>.*`` property.

* <[xpatch](patch.md)> _patch-file_  

* <[xaction](action.md)> _@rule-or-action_  
  
## Notes

### Compression

The **tar** utility will determine which decompression type to use, if any, automatically from the _tar_ file via the **-f** arg.

### Curl

The ability to create repositories with **tar** is not terribly useful alone. It is, however, especially useful when combined with the **curl** utility. Since XCURL_URL sources are resolved to their downloaded type automatically, you can use a URL to a _tarball_ directly.
 
Example:
```
xrepo myrepo 
    : https://host.tld/path/project-4.3.tar.xz 
    : <xtar-arg>"--strip-components 1" # remove initial path component (project-X.X)
    ;
```

### Logs

* _workspace_/_tar-file-name_**.untar-log**

## Boost.Build Type Reference

Type | Base Type | Infer from source | Generate from
:---: | :---: | :---: | :---:
XTAR | | ``*.tar``, ``*.tar.*``, ``*.tgz``, ``*.zip``
XREPO | XMODULE | | XTAR
