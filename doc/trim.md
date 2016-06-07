# Ancillary Module Reference: trim

Trim strings.

## How to use

Make rules available in your current module.
```
import trim ;
```

Trim a string.

```

test-str = "    hello world     " ;

left-trimed  = [ trim.left $(test-str) ] ;
right-trimed = [ trim.left $(test-str) ] ;
fully-trimed = [ trim.trim $(test-str) ] ;

```


Trim a shell cmd.

```
trimmed-result = [ trim.sh $(SHELL-CMD) ] ;
```

## rules
 

* rule **trim-left-regex** ( )

    Return regex pattern that matches all but left whitespace.

* rule **trim-right-regex** ( )

    Return regex pattern that matches all but the right whitespace.
    
* rule **trim-regex** ( )

    Return regex pattern that matches all but the left and right whitespace.
    

* rule **left** ( _strs_ * )

    Return _strs_ with left most whitespace removed from each item.
    
* rule **right** ( _strs_ * )

    Return _strs_ with right most whitespace removed from each item.
    
* rule **trim** ( _strs_ * )

    Return _strs_ with left and right whitespace removed from each item.
    
    
* rule **sh** ( _command_ : * )

    Just like [Boost.Build's SHELL](http://www.boost.org/build/doc/html/jam/language.html#jam.language.rules.builtins.utility._shell__) only left and right whitespace removed from the result.

## Test examples

In the unit-test **rule __test__** in source:

```
trim.jam
```

