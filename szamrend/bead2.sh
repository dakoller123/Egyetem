#!/bin/bash

file=$1

while read line; do
        IFS=","
        i=0
        for number in $line
        do
                numbers[i]=$number
                i=$i+1
        done
        unset IFS

        originalNumSys=${numbers[0]}
        targetNumSys=${numbers[1]}

        for ((i=2;i<${#numbers[@]};i++))
        do
                number=${numbers[i]}
                #echo $($number/10)
                for ((j=0;j<${#number[@]};j++))
                do
                        echo A${number[j]}
                done
        done
done <$file
