# XModule Reference: curl

Download files from urls with [curl](https://curl.haxx.se/) 

## Main target rules

* **xfile**  
  Constructs an XFILE target from the source.  
  Actual type of result can change and be determined by the type of the file itself.
  
* **alias**  
  Pass through source(s) as the target(s) associated the the main target name.  
  This can be useful with _curl URLs_ for when _xfile_ doesn't work due to generator ambiguity.
  
## Features

### Curl 

* <**xurl**> _url_  
   Alternative method for specifying a URL source.

* <**xcurl-arg**> _option_  
   **curl** tool receives _option_ arguments when executed on XCURL_URL source  
   If not set, location redirection (**-L**) is enabled.  
   Consult [curl manpage](https://curl.haxx.se/docs/manpage.html) for valid _options_  
   
* <**xcurl-retry**> _N_  
   Number of times to invoke **curl** to try and fetch the remote file.  
   Default: 3  
   This is not the same as the **--retry** argument.  
   
* <**xcurl-output-name**> _name_  
   Target filename.  
   Defaults to mangled form of source URL.  
   Result type is deduced from output name.
   
* <**xcurl-file-type**> _type_  
   Explicitly set the result type.

### XModule

* <[xworkspace](xmodule.md#workspaces)> and related features  
  By default, the workspace for a XCURL_FILE target is invariant.  
  It has an implicit ``<xinvariant>.*`` property.
  
## Notes

### Logs

* _workspace_/_output-name_**.curl-log**


## Boost.Build Type Reference

 Type | Base Type | Infer from source | Generate from
 :---: | :---: | :---: | :---: 
XCURL_URL | XURL | Valid URL
XCURL_FILE | XFILE | | XCURL_URL


 Example URL | Note
 --- | ---
 http://host/path/file | local http host
 http://host.tld/path/file | fully qualified domain http url
 http://host.tld/path/file?arg&arg2=value&arg3=value | url arguments also valid
 https://host.tld/path/file | https support
 ftp://ftp.domain.tld/path/file | ftp support
 file:///absolute/path/to/file | local file url 
 
