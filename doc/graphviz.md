# Ancillary Module Reference: graphviz

Graph targets and Boost.Build generators using Graphviz.


## How to use

Make rules available in your current module.
```
import graphviz ;
```

## Main target rules

* rule **graphviz-target** ( _sources_ * : _requirements_ * : _default-requirements_ * : _usage-requirements_ * )
  
  Generate a Graphviz **dot** file representing the dependency graph of the _sources_ target(s).  
  

* rule **graphviz-generator** ( _sources_ * : _requirements_ * : _default-requirements_ * : _usage-requirements_ * )

  Generate a Graphviz **dot** file representing the dependency graph of Boost.Build Types and Generators identified by properties specified with the _graphviz-type_ and _graphviz-generator_ features.
  
## Features

* <**graphviz-type**> _type_  
  Used by **graphviz-generator** rule.  
  Adds _type_ to the list of types to visualize the viable source types and generators for.
 
* <**graphviz-generator**> _generator-id_  
  Used by **graphviz-generator** rule.  
  Adds _generator-id_ to the list of Boost.Build generators to visualize the viable source types and generators for.
   
## Notes

### OSX

Actions for these targets will attempt to open **dot** file after generation with OSX [Graphviz.app](http://www.graphviz.org/Download_macos.php).

### Test examples

```
test/xmodule/graphviz.jam
```


## Boost.Build Type Reference

Type | Base Type | Infer from source | Generate from
:--- | :--- | :---: | :---:
GRAPHVIZ_DOT | | ``*.dot`` |
GRAPHVIZ_TARGET | GRAPHVIZ_DOT | | *
GRAPHVIZ_GENERATOR | GRAPHVIZ_DOT | | 

