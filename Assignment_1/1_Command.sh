#!/bin/sh
# echo, ls, read, cat, touch, test, arithmetic comparison, conditional, loops, grep, sed etc. 


touch file.txt
mkdir newDir
mkdir newDirTwo

nano file.txt

# ADD CONTENT

# Hello
# This is content of the file
# Hello there
# Nihao
# Hello HELLO HEY
# Hi there. Greetings!

echo "Hello world!"
echo "This content is appended to file" >> file.txt

ls
ls -alt

read $usr_input
# ADD INPUT
echo $usr_input

read -sp "Enter sensitive data: "
echo $REPLY

cat file.txt
cat file.txt > newFile.txt
cat newFile.txt


a=20
b=20
if test "$a" -eq "$b" 
then
   echo "a is equal to b"
else
   echo "a is not equal to b"
fi

c="Hello World!"
d="Bye!"
if test "$c" = "$d"
then
   echo "c is equal to c"
else
   echo "d is not equal to d"
fi


s=("football" "cricket" "hockey") 
for n in ${s[@]}; 
do
    echo $n
done

t=7
for (( i=1 ; i<=$n ; i++ )); 
do
    echo $i
done

u=7
while [ $u -gt 4 ];
do
    echo $u
    ((u--))
done

grep -i "hello" file.txt
grep -iv "hello" file.txt
grep -c "H" file.txt

sed 's/hello/ciao/g' file.txt