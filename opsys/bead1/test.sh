#!/bin/bash
echo "Reseting vaccination for everyone"
./vakcinacio r;
echo "Setting vaccination flag to true for entry #2, #4, #10"
./vakcinacio V 2;
./vakcinacio V 4;
./vakcinacio V 10;

./vakcinacio L;

./oltobusz;

./vakcinacio L
