# XModule Reference: patch
Patch external sources with **patch**



## Feature

* **xpatch** _patchfile_  
  After a repository target is finished constructing its contents, targets with properties with this feature will run the **patch** utility on the repository with the given _patchfile_.  
  The first directory in the patch file paths will be ignored ( "-p1" ).


