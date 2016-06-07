# Ancillary Module Reference: tty

Make ANSI color output to console easier from jam scripts.  Will only output ANSI escape sequences if the output device is detected to be a color capable TTY.


Read more about ANSI colors at https://en.wikipedia.org/wiki/ANSI_escape_code


## How to use

Make rules available in your current module.
```
import tty ;
```

Echo content with color markup:

```
tty.coded-echo "If the current environment supports color then the following will be true, otherwise just like regular echo.\n" 
               <red> This is red.\n 
               <bold> This is bold red.\n
               <reset> This is normal, and not red. ;
```


## rules
 

* rule **type** ( )

    Return the detected output device type.  
    
    Value | Note
    --- | ---
    "color tty" | Is a TTY, and supports ANSI colors
    "tty" | Is a TTY, and does not support ANSI colors
    "not a tty" | Not a TTY, and does not support ANSI colors

* rule **join** ( _args_ * : _join-str_ ? )
  
      Join a markup encoded set of arguments into a single string.  
      
      Result is an empty list if only markup was found in _args_.  
      _join-str_ will be used to join whenever left and right side are not markup.  
      _join-str_ defaults to a single space: `` ``  
  


* rule **coded-echo** ( _args_ * )

      Like **echo**, but permits coded markup.  

* rule **coded-exit** ( _args_ * : _errorcode_ ? )

      Like **exit**, but permits coded markup.  
  

## markup codes

### Foreground Codes

Color | Normal Code | Intense Code  
---   | --- | ---
black | \<black> | \<BLACK>
red   | \<red>   | \<RED>
green | \<green> | \<GREEN>
yellow  | \<yellow>  | \<YELLOW>
blue    | \<blue>    | \<BLUE>
magenta | \<magenta> | \<MAGENTA>
cyan    | \<cyan>    | \<CYAN>
white   | \<white>   | \<WHITE>

### Background Codes

Color   | Normal Code   | Intense Code  
---     | ---           | ---
black   | \<bg:black>   | \<bg:BLACK>
red     | \<bg:red>     | \<bg:RED>
green   | \<bg:green>   | \<bg:GREEN>
yellow  | \<bg:yellow>  | \<bg:YELLOW>
blue    | \<bg:blue>    | \<bg:BLUE>
magenta | \<bg:magenta> | \<bg:MAGENTA>
cyan    | \<bg:cyan>    | \<bg:CYAN>
white   | \<bg:white>   | \<bg:WHITE>

### Named Control Codes
Code | Meaning
--- | ---
\<bold> | Set intensity state.
\<normal> | Set Normal intensity state.
\<reset> | Set all ANSI states to default.


## Test examples

In the unit-test **rule __test__** in source:

```
tty.jam
```

