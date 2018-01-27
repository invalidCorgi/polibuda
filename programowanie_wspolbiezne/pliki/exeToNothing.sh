#!/bin/bash
exes='*.exe'
for i in $exes
do
    j=$(basename $i .exe)
    mv $i $j
done
