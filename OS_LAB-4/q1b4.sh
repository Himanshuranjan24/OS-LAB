<<question
write a program in shell scripting using switch case to take number input from the user and find whether
 the number is palindrome number or not
question
#!/bin/bash
echo "Enter the number"
read number
reverse=$(echo $number | rev)
case $number in
    $reverse) echo "$number is a palindrome number.";;
    *) echo "$number is not a palindrome number.";;
esac
