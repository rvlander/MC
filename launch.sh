#!/bin/bash

make
./compile exemples/test.m
../jdk1.7.0_03/bin/javac -cp MCJavaCore/dist/MCJavaCore.jar -d javaout MatCode.java
../jdk1.7.0_03/bin/java -cp MCJavaCore/dist/MCJavaCore.jar:. javaout.MatCode 

