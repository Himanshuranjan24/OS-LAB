<<question
 3.a)swapping of two number without using third variables.
question
#!/bin/sh
echo Enter two numbers-:
read num1
read num2
echo "Before Swapping"
echo "Num1: $num1"
echo "Num2: $num2"
num1=$((num1+num2))
num2=$((num1-num2))
num1=$((num1-num2))
echo "After Swapping"
echo "Num1: $num1"
echo "Num2: $num2"