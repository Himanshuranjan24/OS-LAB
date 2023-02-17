<<question
write a program in shell scripting using switch case to take number input from the user and find whether the
 number is prime number or not.
question
#!/bin/bash
echo "Enter the number"
read number
isprime=true
if [ $number -le 1 ]; then
    isprime=false
fi
for ((i=2; i<=$number/2; i++)); do
    if [ $((number%i)) -eq 0 ]; then
        isprime=false
        break
    fi
done
case $isprime in
    true) echo "$number is a prime number.";;
    false) echo "$number is not a prime number.";;
esac

