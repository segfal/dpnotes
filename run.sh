

#compile main.cpp
g++ main.cpp

#run file if compiled successfully
if [ $? -eq 0 ]; then
    ./a.out && rm a.out
    
fi

