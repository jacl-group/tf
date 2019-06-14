# tf trash file utility

The idea is to make a command line tool that is a drop-in replacement for rm which follows the trash standard used by Linux desktops. 

To Build and Run

	git clone git@github.com:jacl-group/tf.git
	cd tf
	mkdir build
	cd build
	cmake ../src
	make
	./tf
	
Useful make flags

	-j4
run 4 processes at a time

	VERBOSE=1

display commands as they are executed
		
Setting **VERBOSE** is good to see which directories are included (-I&lt;dir&gt;) and which libraries (-l&lt;name&gt;) are included.

