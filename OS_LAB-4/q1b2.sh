<<question
write a program in shell scripting using switch case to take number input from the user and find whether the 
number is Armstrong number or not.
question
#!/bin/bash
echo "Enter the number"
read number
numdigits=${#number}
sum=0
for ((i=0; i<$numdigits; i++)); do
    digit=${number:i:1}
    (( sum += digit**num_digits ))
done
case $number in
    $sum) echo "$number is an Armstrong number.";;
    *) echo "$number is not an Armstrong number.";;
esac
