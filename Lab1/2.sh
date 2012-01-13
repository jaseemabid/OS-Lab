#! /bin/bash

# Program to find out if the arg given is odd or even
# Author : Jaseem Abid <jaseemabid@gmail.com>

rc=`expr $1 % 2`
if test $rc -eq 0 
then
	echo "Even"
else 
	echo "Odd"
fi

