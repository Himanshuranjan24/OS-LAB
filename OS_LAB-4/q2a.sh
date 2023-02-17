<<question
write a program in shell scripting to take array as input from the user and print it in reverse order.
question
#!/bin/bash
echo "Enter the array elements, separated by space:"
read -a arr
len=${#arr[@]}
for ((i=$len-1; i>=0; i--)); do
    echo "${arr[i]}"
done
