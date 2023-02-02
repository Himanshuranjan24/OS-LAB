<<question
 swapping of two number with using third variables.
question
#!/bin/sh
echo "Enter first number(A) Of Your Choice :"
read a
echo "Enter Second number(B) Of Your Choice :"
read b
echo "_________________Before Swapping_______________"
#swapping
echo "First number: $a"
echo "Second number: $b"
temp=$a
a=$b
b=$temp
echo "________________After Swapping_______________"
echo "First number: $a"
echo "Second number: $b"