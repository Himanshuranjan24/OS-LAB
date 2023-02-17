<<question
write a program in shell scripting to take array as input from the user and print it in descending order.
question
#!/bin/bash
echo "Enter the array elements, separated by space:"
read -a arr
sorted=($(echo "${arr[@]}" | tr ' ' '\n' | sort -nr))
echo "Sorted array in descending order:"
for i in "${sorted[@]}"; do
    echo $i
done
