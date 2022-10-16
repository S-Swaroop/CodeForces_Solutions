import os
import sys

# utility function to read from a given file
def read (path) :
    file = open(path , 'r')
    return file

# function to write to a given paths the lines 
def write (path , lines) : 
    file = open(path , 'w')
    file.flush()
    file.writelines(lines)
    return

def main() : 
    template = read('template.cpp').readlines()
    file = ['A.cpp' , 'B.cpp' , 'C.cpp' , 'D.cpp' , 'E.cpp' , 'F.cpp' , 'G.cpp'] 
    for i in range(0 , 7) :
        print(file[i])
        write(file[i] , template)

    # template.close() 
main()