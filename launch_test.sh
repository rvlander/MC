#!/bin/bash
# 
# File:   launch_test.sh
# Author: rvlander
#
# Created on 23 mai 2012, 11:04:42
#

MC_HOME=/home/rvlander/MC/
MC_CORE=$MC_HOME/MCJavaCore/dist/MCJavaCore.jar

files=`find test_suite/ |grep .m$`
make >compile.log

mkfifo tomatlab
matlab -nodesktop < tomatlab > matlaboutput &


for i in $files; do
#    echo $i
    ./lmsrj $i >tomatlab
    ./compile $i > compiler.log
    basefile=`basename $i`
    dirfile=`dirname $i`
    sourc=`echo $i|sed "s/\.m$/.java/"`
#    echo $sourc
    javac -cp $MC_CORE $sourc> compile.log
    cd $dirfile
    java -cp $MC_CORE:. `echo $basefile |sed "s/\.m$//"`
    cd $MC_HOME
done




echo "exit" > tomatlab 
rm tomatlab