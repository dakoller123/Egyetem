#!/bin/bash
gcc ./vakcinacio_db.c -std=c99 -Wall -Werror -W -o ./vakcinacio
gcc ./vakcinacio_oltobusz.c -Wall -Werror -W -lrt -o ./oltobusz
