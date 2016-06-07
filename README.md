# Boost.Build XModule

**Boost.Build XModule** is a [Boost.Build](http://www.boost.org/build/) plugin that makes it easy to integrate external source-based projects into your Boost.Build project.

Boost.Build claims to "make it easy to build C++ projects, everywhere". In practice, this is largely true, except when attempting to integrate third party sources that don't support being built with Boost.Build out of the box (which is the common case). Integration of external sources is especially painful when they are complex and use other build systems such as CMake or a "./configure" makefile generator. XModule tries to solve these problems by providing Boost.Build rules that download, patch, configure, build, and export files from external sources and their respective generated file trees.

Building external projects from source as part of your project's build process is one way to control exactly what goes into your builds. This allows you to avoid depending on external libraries installed at the system level, and becomes especially useful when building large projects that may depend on different versions of the same library, or on a different version than the system itself uses. It also allows you to build patched versions of external sources, when getting your patch merged upstream may not be feasible.

#####Requirements & Known Issues
* Your codebase resides inside a git managed directory
  * Removal of this requirement would be trivial
* You are building on a Linux or OSX host
  * Support for Windows is possible
  * Support for Windows and other hosts requires writing functioning build 'actions' that will execute on those hosts


# How to install

The only hard requirement is that the Xmodule sources are present and available to your build system at run-time, and then that you load ``/xmodule.jam`` as 'xmodule' in your build system.

A good place to do this is in your ``project-config.jam`` or ``Jamroot`` file. Doing this in project root ensures that all ``Jamfile``s in your project will have access to xmodule rules.

It is also recommended that you place the XModule sources into your build tree so that they do not become an external dependency of your build. Using Git's submodule feature is one tested method for doing this.

Here is an example assuming that the sources are located at ``build/jams/xmodule``, relative to your project root.

```
# ROOT becomes absolute basepath of this file.
path-constant ROOT : . ;

# load module from the given path and name it 'xmodule'
modules.load xmodule : $(ROOT)/build/jams/xmodule/xmodule.jam ;
```

Check that the installation is working by running ``b2`` in the ``test/xmodule/`` directory of these sources. All tests/targets should build.


# Examples


### Library from local source tree

```
lib iconv   : iconv/configure
            : <name>lib/iconv

              # config
              <xconfig>--enable-static
              <xconfig>--enable-shared

              # headers
              <xinclude>include

              # only distinct per toolset
              <xvariant>toolset.*
              <xinvariant>.*
            ;
```

This tells boost.build to create a lib target named **iconv** from a local source file named **configure**.

* ``<xconfig>`` properties instruct the **configure** script to enable static and shared libraries
* ``<xvariant>`` and ``<xinvariant>`` properties declare that the iconv library is only built once per toolset, regardless of link or variant
* ``<xinclude>`` property causes any sources that depend on **iconv** lib target to have the **include** sub-directory of the external build in their include path
* ``<name>`` property identifies the target library file


### Library from remote tarball, with toolset options

```
lib glpk
    :   [ xfile configure
            : http://ftp.gnu.org/gnu/glpk/glpk-4.60.tar.gz
            : <xtar-arg>"--strip-components 1" # avoid version specific prefix path
        ]
    :
        <name>lib/glpk

        <xinclude>include

        # generate optimized 'lto' slim objects
        <xtoolset-cflags>-O3
        <xtoolset-cflags>-flto
        <xtoolset-linkflags>-O3
        <xtoolset-linkflags>-flto

        # only distinct per toolset
        <xvariant>toolset.*
        <xinvariant>.*
    ;
```

This example introduces the ability to specify external archives as a source.

* ``[ xfile configure ..... ]`` source defines a configure file contained within the remote sources.
* ``<xtoolset-cflags>`` and ``<xtoolset-linkflags>`` properties specify additional flags for the external build tool's cflags and linkflags respectively. In this example, they enable optimization and link-time-optimization

### Library from remote git repo, with patch file

```
lib  stxxl  : [ xfile CMakeLists.txt
                : https://github.com/stxxl/stxxl.git
                : <xgit-ref>5b9663e6b769
                  <xpatch>noexcept.patch
              ]
            : <name>lib/stxxl
              <xinclude>include

              <xvariant>toolset.* # compiler/toolset matters
              <xvariant>link      # link matters for cmake
              <xinvariant>.*      # nothign else matters (debug/release/lto/etc)
            ;
```

In this example, the stxxl library builds from a github repository via cmake.

* ``<xgit-ref>`` checks out the specific revision
* ``<xpatch>`` patches the locally cloned git repository with the local source file ``noexcept.patch``

# Documentation

* XModule Core  
   * [target types](doc/xmodule.md#xmodule-target-types)
   * [repository targets as projects](doc/xmodule.md#repository-targets-as-projects)
   * [workspaces](doc/xmodule.md#workspaces)
   * [xtoolset](doc/xmodule.md#xtoolset)
   
* XModule Tools
   * [make](doc/make.md)
     * [configure](doc/configure.md)
     * [cmake](doc/cmake.md)
   * [b2](doc/b2.md)
   * [curl](doc/curl.md)
   * [tar](doc/tar.md)
   * [git](doc/git.md)
   * [xpatch](doc/patch.md)
   * [xaction](doc/action.md)
   * [dpkg](doc/dpkg.md)
* Ancillary Modules 
   * [tty](doc/tty.md)
   * [trim](doc/trim.md)
   * [graphviz](doc/graphviz.md)
   * [build-job-args](doc/build-jobs-args.md)
   * [system-libs](doc/system-libs.md)

# How to Contribute

We welcome contributions. Please file issues and submit pull requests via GitHub.

