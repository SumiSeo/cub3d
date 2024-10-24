#! /bin/bash

WRONG_DIRECTORY_MESSAGE="Wrong directory. Please run the script again if you want to do the tests."
RUN_TEST="valgrind -q --leak-check=full --show-leak-kinds=all --track-fds=yes ../.././cub3D"
GREEN="\033[0;32m"
RED="\e[1;31m"
DEFAULT="\033[0m"
OUTPUT_FILE=output.txt