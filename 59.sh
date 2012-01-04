#! /bin/bash

unsorted=""

for i in {0..94}
do
	num=`grep -o "^$i$" 59.txt | wc -l`
	unsorted="$unsorted\n$num occurrences:$i"
done

sorted=`echo -e $unsorted | sort -n`

echo -e $sorted
