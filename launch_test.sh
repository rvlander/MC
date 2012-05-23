#!/bin/bash
# 
# File:   launch_test.sh
# Author: rvlander
#
# Created on 23 mai 2012, 11:04:42
#

make

mkfifo tomatlab
matlab -nodesktop < tomatlab > matlaboutput &
if [ -z $1]
then
./lmsrj test_suite/test.m >tomatlab
else
./lmsrj "$1" tomatlab >tomatlab
fi

echo "exit" > tomatlab 
rm tomatlab