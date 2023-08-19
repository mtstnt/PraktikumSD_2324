#!/bin/sh

dirName=$1
fileName=$2

g++ -o ./$dirName/$fileName ./$dirName/$fileName.cpp

echo "Running $fileName"
./$dirName/$fileName

rm ./$dirName/$fileName.exe
