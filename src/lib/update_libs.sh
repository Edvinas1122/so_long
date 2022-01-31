#!/bin/bash
if [ "`dpkg -s libxext-dev | grep "Status" | wc -l`" == "0" ]
then
    sudo apt install libxext-dev
else
    echo "found libxext-dev"
fi
if [ "`dpkg -s libbsd-dev | grep "Status" | wc -l`" == "0" ]
then
    sudo apt install libbsd-dev
else
    echo "found libbsd-dev"
fi
if [ "`dpkg -s xorg | grep "Status" | wc -l`" == "0" ]
then
    sudo apt install xorg
else
    echo "found xorg"
fi