#!/bin/bash

make
./compile exemples/test.m
javac -cp MCJavaCore/dist/MCJavaCore.jar:. MatCode.java
java -cp MCJavaCore/dist/MCJavaCore.jar:. MatCode 

