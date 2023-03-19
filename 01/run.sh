#!/bin/bash
# --oversubscribe -np 4
mpicc prac01.c
# mpirun a.out
mpirun --oversubscribe -np 3 a.out
