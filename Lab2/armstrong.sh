#!/bin/bash

# Armstrong number
# Author : Jaseem Abid <jaseemabid@gmail.com>

Number=$1 
Length=${#Number}
Sum=0
OldNumber=$Number

while [ $Number -ne 0 ]
do
	Rem=$((Number%10))
	Number=$((Number/10))
	Power=$(echo "$Rem ^ $Length" | bc )
	Sum=$((Sum+$Power))
done

if [ $Sum -eq $OldNumber ]
then
	echo "$OldNumber is an Armstrong number"
else
	echo "$OldNumber is not an Armstrong number"
fi
