#! /bin/bash

# Program 9
# Author : Jaseem Abid <jaseemabid@gmail.com>

if test -f $1
then
	echo "$1 : File exists"
	echo "Deleting $1"
	rm $1
else
	if test -d $1
	then
		echo "$1 : Directory exists"
	else 
		echo "Creating directory $1"
		mkdir $1
	fi
fi
