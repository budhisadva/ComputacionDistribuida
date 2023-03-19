#!/bin/bash
# --oversubscribe -np 4
mpicc prac01.c
# mpirun --oversubscribe -np 3 a.out
for (( i = 0; i < 10; i++ )); do
  echo "${i}"
  mpirun --oversubscribe -np 3 a.out
done
