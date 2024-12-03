# string

This folder contains functions related to the string category of the library.

## Functions

- List of functions will go here.
#differnece between strcpy|duplicate
|property         |strdup                                        |strcpy                               |
|-----------------|----------------------------------------------|-------------------------------------|
|memory allocation|NULL                                          |allocate dynamically the space       |
|memory freed     |not necessary                                 |after the execution, need to be freed|
|simplicity       |Quick but necessary to handle the Buffer size |Simple to copy a string dynamically  |
|performance      |Faster, no allocation                         |slower because we use `malloc`       |
|error handlings  |might provok a memory overflow                |return NULL if allocation fails      |
