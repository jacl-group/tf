# man tf

### Name
tf remove files or directories

### Synopsis

tf [OPTION]… FILE…
### Description

## man rm
tf - remove files or directories
Synopsis
tf [OPTION]... FILE...
### Description
This manual page documents the GNU version of tf. tf removes each specified file. By default, it does not remove directories.

If the -I or --interactive=once option is given, and there are more than three files or the -r, -R, or --recursive are given, then tf prompts the user for whether to proceed with the entire operation. If the response is not affirmative, the entire command is aborted.

Otherwise, if a file is unwritable, standard input is a terminal, and the -f or --force option is not given, or the -i or --interactive=always option is given, tf prompts the user for whether to remove the file. If the response is not affirmative, the file is skipped.

### Options

Remove (unlink) the FILE(s).

-f, --force
    ignore nonexistent files, never prompt 
-i
    prompt before every removal 
-I
    prompt once before removing more than three files, or when removing recursively. Less intrusive than -i, while still giving protection against most mistakes 
--interactive[=WHEN]
    prompt according to WHEN: never, once (-I), or always (-i). Without WHEN, prompt always 
--one-file-system
    when removing a hierarchy recursively, skip any directory that is on a file system different from that of the corresponding command line argument 
--no-preserve-root
    do not treat '/' specially 
--preserve-root
    do not remove '/' (default) 
-r, -R, --recursive
    remove directories and their contents recursively 
-v, --verbose
    explain what is being done 
--help
    display this help and exit 
--version
    output version information and exit

By default, tf does not remove directories. Use the --recursive (-r or -R) option to remove each listed directory, too, along with all of its contents.

To remove a file whose name starts with a '-', for example '-foo', use one of these commands:

tf -- -foo
tf ./-foo

### Author
Written by Cassie E. Nicol, and Alexandria Pettit

### Report Bugs
Report tf bugs to cassieenicol@gmail.com

### Copyright
Copyright Â© 2010 Free Software Foundation, Inc. License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>.
This is free software: you are free to change and redistribute it. There is NO WARRANTY, to the extent permitted by law. 

### See Also
rm(1)
