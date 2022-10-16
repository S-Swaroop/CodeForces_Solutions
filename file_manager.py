import os
import sys
from urllib.parse import urlparse

def parse_url (url) : 
    split_url = url.split('/')
    res = dict()
    res['host_name'] = urlparse(url).hostname.split('.')[0]
    if (split_url.count('contest') == 0) :  # means the contest_id is the second last item and problem_id is the last element
        res['contest_id'] = split_url[-2] 
        res['problem_id'] = split_url[-1]
    else :                                  # means contest_id is 3rd last element and problem_id is last element
        res['contest_id'] = split_url[-3]
        res['problem_id'] = split_url[-1]
    return res

def validate_path (path) : 
    if not os.path.exists(path) :
        os.makedirs(path)

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

def main () :
    host_folder = dict()
    host_folder['codeforces'] = 'CodeForces'
    host_folder['codechef'] = 'CodeChef'
    host_folder['atcoder'] = 'AtCoder'

    args = (sys.argv)
    n = len(args)

    for i in range(1 , n) : 
        file_name = args[i] + '.cpp'
        file = read(file_name)
        if file != None :
            url = file.readline()
            url = (url[url.find('https://'):]).strip()
            parsed_url = parse_url(url)
            new_path = host_folder[parsed_url['host_name']] + '/' + parsed_url['contest_id']  
            validate_path(new_path)
            write(new_path + '/' + parsed_url['problem_id'] + '.cpp', file.readlines()) 
            file.close()

main()
