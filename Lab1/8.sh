#! /bin/bash

# Program to move hidden files to hidden/
# Author : Jaseem Abid <jaseemabid@gmail.com>

if test -d hidden
then
	echo "hidden/ Exists"
else
	mkdir hidden
fi

mv .* hidden/
