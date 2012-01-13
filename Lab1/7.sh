#! /bin/bash

# Program 7
# Author : Jaseem Abid <jaseemabid@gmail.com>

num=0
until test $num -eq 10
do
	num=$(( $num + 1 ))
	echo $num
done

