<<question
write a program  to take number as a input from the user and display it into words.
question
#!/bin/bash
echo "enter the number"
read number
case $number in
    0) echo "zero";;
    1) echo "one";;
    2) echo "two";;
    3) echo "three";;
    4) echo "four";;
    5) echo "five";;
    6) echo "six";;
    7) echo "seven";;
    8) echo "eight";;
    9) echo "nine";;
    *) echo "Number out of range";;
esac
