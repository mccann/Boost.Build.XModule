# Ancillary Module Reference: build-job-args


Utilities related to ``-j`` arguments of build systems.


## How to use

Make rules available in your current module.
```
import build-job-args ;
```

## rules
 

* rule **jobs-arg-from-options** ( _options_ * )

    Find the ``-j`` option value in the _options_ list.  
    Returns empty list if not found.


* rule **current-boost-build-jobs-arg** ( _default_ ? )

    Find the ``-j`` option value for the current invocation.  
    Returns _default_ if not set.
    

* rule **compute-external-build-jobs-arg** ( _boost-j_ ? : _limit_ ? )

    Find the ``-j`` option value for external builds from _boost-j_ and _limit_.  
    Will use one less than _boost-j_ or _limit_, whichever is lower.


* rule **host-num-cores** ( )

    Return the current host's number of cores.  
    Returns 1 if it couldn't find out.


* rule **external-build-jobs-arg** ( _distributed-build_ ? )

    Return ``-j`` option value for external builds from current environment.  
    If _distributed-build_ is a boolean _true_ value, then the result will not be limited to the value returned by **host-num-cores**.  
    

* rule **distributed-build-default** ( _distributed-build_ ? )

    Use to indicate default value for _distributed-build_ argument of the above rule **external-build-jobs-arg**.  
    
