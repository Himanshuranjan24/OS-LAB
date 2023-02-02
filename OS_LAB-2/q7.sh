<<question
7.Enter the value of base and exponents and find the final answer.(hint:-m^n)
question
#!/bin/sh
echo "Enter the value of base:"
read base
echo "Enter the value of exponent:"
read exponent
answer=$((base ** exponent))
echo "The final answer is: $answer"