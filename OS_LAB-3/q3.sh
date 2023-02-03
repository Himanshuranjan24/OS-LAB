<<question
3 :  WAP to take a 4 digit number as an input and swap the 1st and the 3rd digit number and swap the 2nd 
and the 4th digit number , after this display the final number ,if the user does not enter a 4 digit number 
display a corresponding error message.
question
#!/bin/sh
echo "Enter a four-digit number:-"
read num
first=${num:0:1}
second=${num:1:1}
third=${num:2:1}
fourth=${num:3:1}
swapped_num=$third$fourth$first$second
echo "The swapped number is: $swapped_num"