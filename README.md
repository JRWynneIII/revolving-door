# Revolving Doors
*Learning the Illumos Doors API*

Illumos Doors are a novel form of inter-process communication. They allow a
thread in a client process to call a function in a server process, automatically
spawning a handler thread in the server process if needed.

This repository includes a set of annotated code examples of increasing
complexity, each of which discusses a different aspect of the doors API. Though
unusual, this API is not very big. The goal of this project is to help folks
become comfortable with the doors API in a single sitting.

### Prerequisites
You should know a little C, and have an interest in systems programming. More
specifically, this tutorial assumes you either understand or can teach yourself
about the following:

* When a process opens a file, it gets back a "file descriptor" which is an int
* Making a "System Call" is really just asking the OS to do something for you
* C represents arrays by a pointer to the beginning of some data, and its length
* `printf` takes some funky arguments, and you have to look those up sometimes.

### Sources
I am writing this because there seems to be so little about doors on the 
internet. Here is what I have been able to gather, in order of usefulness:

* Chapter 15 "Doors" of *UNIX Network Programming, Volume 2, Second Edition: Interprocess Communications*, Prentice Hall, 1999, ISBN 0-13-081081-9.
* [DOOR_CREATE(3C)](https://illumos.org/man/3C/door_create)
* ["Doors" in SolarisTM: Lightweight RPC using File Descriptors](http://www.kohala.com/start/papers.others/doors.html)
* [Door API Details](https://blogs.oracle.com/tucker/door-api-details)
* [illumos-fuse2](https://bitbucket.org/gwr/illumos-fuse2)
* [Linux Doors](http://ldoor.sourceforge.net) 
