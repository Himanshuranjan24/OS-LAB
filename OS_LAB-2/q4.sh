<<question
Take the marks of 5 subjects as input and find average percentage
question
#!/bin/sh
echo "Enter the marks of five subjects of any students :"
read m1 m2 m3 m4 m5 
sum=$((m1+m2+m3+m4+m5))
avg=$((sum/5))
per=$((avg/100))
echo "The Average Marks is  $avg"
echo "The Average Percentage is  $per%"