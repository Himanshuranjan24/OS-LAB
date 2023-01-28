<<Question
Write  a Program to Take two numbers from user and do the following Operations:-
1.Addition
2.Subtraction
3.Multiplication
4.Division
Question

#!/bin/sh
echo "Enter The Numbers:-"
read n1 n2
ans1=$((n1+n2))
ans2=$((n1-n2))
ans3=$((n1*n2))
ans4=$((n1/n2))
echo "The sum of numbers is $ans1"
echo "The sub of numbers is $ans2"
echo "The mul of numbers is $ans3"
echo "The Div of numbers is $ans4"
