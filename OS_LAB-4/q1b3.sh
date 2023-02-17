<<question
write a program in shell scripting using switch case to take number input from the user and find whether the 
number is perfect number or not.
question
#!/bin/bash
echo "Enter the number"
read number
sum=0
for ((i=1; i<$number; i++)); do
    if [ $((number%i)) -eq 0 ]; then
        (( sum += i ))
    fi
done
case $sum in
    $number) echo "$number is a perfect number.";;
    *) echo "$number is not a perfect number.";;
esac
