#!/bin/bash

MC_HOME=/home/rvlander/MC/
MC_CORE=$MC_HOME/MCJavaCore/dist/MCJavaCore.jar

make

if [ -z $1]
then
infile=exemples/test.m
else
infile="$1"
fi

./compile -v $infile

javac -cp $MC_CORE `echo $infile|sed "s/\.m$/.java/"`
cd `dirname $infile`
basefile=`basename $infile`
java -cp $MC_CORE:. `echo $basefile |sed "s/\.m$//"`
cd $MC_HOME

