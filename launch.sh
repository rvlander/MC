#!/bin/bash

make

if [ -z $1]
then
./compile exemples/test.m
else
./compile "$1"
fi
javac -cp MCJavaCore/dist/MCJavaCore.jar MatCode.java
java -cp MCJavaCore/dist/MCJavaCore.jar:. MatCode 

