#!/bin/bash

function build() {
    if ! [ -d "build" ]; then
        mkdir build
    fi

    cd build

    cmake ..
    make

    cd ..
}

function run() {
    build
    ./bin/algorithms_test
}

function clean() {
    rm -rf bin lib build cmake-build-debug
}

if [ -z "$1" ]; then
    echo "This script needs an argument!"
    exit 1
elif [ "$1" == "build" ]; then
    build
elif [ "$1" == "run" ]; then
    run
elif [ "$1" == "clean" ]; then
    clean
else
    echo "Invalid argument: \"$1\"!"
fi