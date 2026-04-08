#!/bin/sh

echo "Enter a number:"
read n

flag=0

for i in 2 3 4 5 6 7 8 9 10
do
  if [ $i -le `expr $n / 2` ]
  then
    if [ `expr $n % $i` -eq 0 ]
    then
      flag=1
      break
    fi
  fi
done

if [ $n -le 1 ]
then
  echo "Not Prime"
elif [ $flag -eq 0 ]
then
  echo "$n is Prime"
else
  echo "$n is NOT Prime"
fi
