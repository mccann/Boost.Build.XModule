# XModule Reference: git


Create local git repository from remote git URLS with [git](https://en.wikipedia.org/wiki/Git_(software))


## Main target rules

* **xrepo**  
  Construct an XREPO Repository target from the _gir url_.
  
  This tool will attempt to create a shallow clone when possible. Use a ``<xgit-clone>no-shallow`` property to disable shallow clone.  Shallow clone is only possible for the HEAD revision, tags, and branch references. Unfortunately any SHA reference will force a non-shallow clone.  
  
## Features

### Git 

* <**xurl**> _git-url_  
  Alternative method for specifying a URL source.

* <**xgit-ref**> HEAD | _SHA_ | **revision:**_SHA_ | **branch:**_name_ | **tag:**_name_  
  Indicate which revision to clone.  
  Default is HEAD.

* <**xgit-clone**> _option_  
   **git clone** tool receives _option_ arguments when executing clone on XGIT (url) source.  
   Special _option_ **no-shallow** makes **git clone** actions to not attempt to perform a shallow clone of the remote repository. This option is not passed on to **git clone**.  
   

### XModule

* <[xworkspace](xmodule.md#workspaces)> and related features  
  By default, the workspace for a **git clone** target is invariant.  
  It has an implicit ``<xinvariant>.*`` property.
  
* <[xpatch](patch.md)> _patch-file_  

* <[xaction](action.md)> _@rule-or-action_  
  
## Notes

### --xrepo-reset 

If a commandline argument ``--xrepo-reset`` is specified, all git repositories managed by this XModule tool will be hard reset to their original cloned state. 

### Logs

* _workspace_/**log**/**git-clone.log**
* _workspace_/**log**/**git-reset.log**

### Src Hash

**git** is also used to construct an XSRCHASH for sources.  
This is used to track potential changes in external sources. 

## Boost.Build Type Reference

 Type | Base Type | Infer from source | Generate from
 :---: | :---: | :---: | :---: 
XGIT | | ``*.git``, ``URL/*.git``
XREPO | XMODULE | | XGIT

