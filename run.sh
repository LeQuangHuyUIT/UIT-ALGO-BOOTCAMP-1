#!/bin/bash

g++ -o /tmp/1 $1 -std=c++11 -Wall -O2
/tmp/1 < input

