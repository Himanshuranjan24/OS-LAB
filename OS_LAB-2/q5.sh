<<question
5.Find the area of the circle
question
echo "Enter Radius of Circle"
read radius
#area=`echo 3.14\*$radius\*$radius |bc`  #method 1 
#area=$((3.14\*$radius\*$radius ))
area=`expr 3 \* $radius \* $radius `   #method 2
echo "The Area of Circle  is: " $area