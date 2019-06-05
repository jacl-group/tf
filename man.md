# man tf

### Name

tf -- trash files

### Synopsis

tf [OPTION]… FILE…

### Description

tf trashes each specified file or directory (moves to XDG trashcan). By default, it does not trash directories.

If the -I or --interactive=once option is given, and there are more than three files or the -r, -R, or --recursive are given, then tf prompts the user for whether to proceed with the entire operation. If the response is not affirmative, the entire command is aborted.

Otherwise, if a file is unwritable, standard input is a terminal, and the -f or --force option is not given, or the -i or --interactive=always option is given, tf prompts the user for whether to trash the file. If the response is not affirmative, the file is skipped.

### Options

Move the FILE(s) to the XDG trash directory.

#### rm-compatible options

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
    do not trash '/' (default) 
-r, -R, --recursive
    trash directories and their contents recursively 
-v, --verbose
    explain what is being done 
--help
    display this help and exit 
--version

    output version information and exit

By default, tf does not trash directories. Use the --recursive (-r or -R) option to trash each listed directory, too, along with all of its contents.

To trash a file whose name starts with a '-', for example '-foo', use one of these commands:

tf -- -foo
tf ./-foo


#### tf-specific options

--trash-empty
    empty the XDG trash

--trash-restore FILE...
    restore file from trash FILE specifies which file to restore. Can be multiple.

--trash-undo
    Undo last file(s) that were trashed.

### Contributions
Alexandria P. (author)
Cassie E. Nicol (author)

### Report Bugs
Report tf bugs to cassieenicol@gmail.com (Cassie) or alxpettit@gmail.com (Alexandria).

### Copyright
License GPLv3+: GNU GPL version 3 <http://gnu.org/licenses/gpl.html>.
This is free software: you are free to change and redistribute it. There is NO WARRANTY, to the extent permitted by law. 

### See Also
rm(1)
