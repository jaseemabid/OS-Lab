#! /bin/bash

# Program 4
# Author : Jaseem Abid <jaseemabid@gmail.com>

lineCount=0
while read line
do
	lineCount=`expr $lineCount + 1`
	if [ $lineCount -ge $2 -a $lineCount -le $3 ]
	then
		echo $line
	fi
done < $1
