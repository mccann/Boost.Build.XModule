# XModule Reference: xaction
Execute arbitrary actions on external sources with **xaction**



## Feature

* **xaction** _@boost-rule_  
  After a repository target is finished constructing its contents, targets with properties with this feature will run the given _boost-rule_ and or _boost-actions_ by the same name.

  argument | description
  ---  | ---
  $(<) | log file
  $(>) | repository directory
  
  
  Example template:
  
    * In requirements for some xmodule repository target
    
    ```
    <xaction>@myAction
    ```
  
    * If your 'myAction' needs to execute as a Boost.Build _rule_, in the same module:
    
    ```
    rule myAction ( target : source : properties * )
    {
        # Take some action here.
        
        # Example:
        #   Set custom value on target from boost rule
        CUSTOM_VALUE on $(target) = "whatever" ;
    }
    ```
    
    * If your 'myAction' needs to execute as a Boost.Build _actions_ block, in the same module:
  
    ```
    import xmodule ; # if not already imported
    MyXLOG = [ xmodule.logfile-action ] ; # create variable that contains shell script details
    
    actions myAction
    {
        $(MyXLOG[1])="$(<)"
        (
            # setup logging (add -e if you want to abort on error)
            set -x
            : "comment that will be in log file"
         
            # shell-code-that-does-your-action HERE
            # example:
            cd $(>) # change to repository
            ln -s path/to/file link
         
            # maybe reference 'custom value' added from the myAction rule
            # In this case, both rule and actions blocks are specified
            echo $(CUSTOM_VALUE)
      
        ) $(MyXLOG[2])
    }
  
    ```
    
    In particular, the ``MyXLOG`` portions of the template handle the writing of the log file and error handling.
    
    ```
    actions myLoggingAction
    {
        $(MyXLOG[1])="$(<)"
        (
            echo "This is written to log file."
            
        ) $(MyXLOG[2])
    }
    ```
