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

function clean() {
  rm -rf bin lib build cmake-build-debug
}

function run_tests() {
  clean
  build
  ./bin/algorithms_test
}

function _help() {
  echo -e "C-Algorithms CLI\n"
  echo "Usage: setup.sh [--options] [args] ʕ•ᴥ•ʔ"
  echo
  echo "General options"
  echo -e "\t-b, --build       Builds the project"
  echo -e "\t-t, --test        Run all tests"
  echo -e "\t-c, --clean       Remove unneeded files"
  echo -e "\t"
}

function run {
  if [ -z "$1" ]; then
    _help
    exit 1
  fi

  while [[ $# -gt 0 ]]
  do
    case $1 in
      -b|--build) build ;;
      -t|--test) run_tests ;;
      -c|--clean) clean ;;
      *) _help ;;
    esac
    shift
  done
}

run $*