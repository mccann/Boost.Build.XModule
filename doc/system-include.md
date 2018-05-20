# Ancillary Module Reference: system-include

Include "system" directories use like the Boost.Build <**include**> feature.

Thirdparty headers often have code that will generate warnings with stricter compiler modes. Use of this feature allows you to have these strict warnings enabled without having to see warnings from included thirdparty sources.  

This is accomplished by use of the **-isystem** compiler flag instead of **-I** to indicate include directories.

## How to use

Make rules available in your current module.
```
import system-include ;
```

include a directory

```
exe example : main.c : <system-include>/usr/include/example ;

```
