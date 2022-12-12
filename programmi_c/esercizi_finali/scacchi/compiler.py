import os

path = os.getcwd()

cmd = 'gcc '

dirlist = os.listdir(path)

for file in dirlist:
    if file != 'compiler.py' and file != 'output':
        cmd = cmd + ' ' + file

cmd = cmd + ' -o output -lm'

os.system(cmd)
