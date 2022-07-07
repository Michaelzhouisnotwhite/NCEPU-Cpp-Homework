#!/bin/bash

# SCRIPT=$(readlink -f "$0")
# BASEDIR=$(dirname "$SCRIPT")
# cd $BASEDIR

# if [ ! -d code ] || [ ! -f makelist.txt ]
# then
#     echo "wrong!"
#     exit -1
# fi
path=$(pwd)
FINAL=${path: -1}
rm -f "第$FINAL次作业 120191080318 周袁卿.zip"
zip -v "第$FINAL次作业 120191080318 周袁卿.zip" *.cpp