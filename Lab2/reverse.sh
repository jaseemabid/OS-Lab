#!/bin/bash

# Revberse print a file
# Author : Jaseem Abid <jaseemabid@gmail.com>


len=$(cat $1 | wc -l);
count=$len;

while [ $count -gt 0 ]
	do
	sed -n $count"p" $1
	count=$(echo "$count -1 " | bc);
done

