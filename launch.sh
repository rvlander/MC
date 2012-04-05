#!/bin/bash

make
./compile exemples/test.m
javac -cp MCJavaCore/dist/MCJavaCore.jar MatCode.java
mv MatCode.class javaout/
java -cp MCJavaCore/dist/MCJavaCore.jar:. javaout.MatCode 

