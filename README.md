# Quickcheck for Erlang's C interface
Example code demonstrating how to use QuickCheck for Erlang via
Quviq's [QuickCheck CI](http://quickcheck-ci.com) service to check some C code.

[<img src="http://quickcheck-ci.com/p/kfl/quickcheck-c-interface.png" alt="Build Status" width="160px">](http://quickcheck-ci.com/p/kfl/quickcheck-c-interface)

## Example(s)

The `src` directory contains a number of examples. (Right now there is
only one example, but the plan is that eventually there will be more.)

* The file `bsearch.c` contains a number of implementations of binary
  search, many of them are buggy. The file `bsearch_eqc.erl` contains
  a number of properties for testing the C functions. In particular
  it shows how to use the `?SETUP` macro to compile the C file before
  calling any functions and how to use `catch` to deal with
  segmentation faults.
