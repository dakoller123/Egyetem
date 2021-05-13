#!/bin/bash
rm -f ./zh
gcc ./zh.c -Wall -Werror -W -o ./zh
./zh
