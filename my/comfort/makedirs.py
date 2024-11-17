'''
makes directory argv[1] and fills it with template directories [A;argv[2]]
'''

import sys, os, shutil

#argv[1] = foldername
#argv[2] = letter up to which to create folders like A, B, ..., letter
if len(sys.argv) != 3:
	print("Please specify folder name and last task letter")
	exit(0)

letter = sys.argv[2]
if len(letter) != 1 or letter < 'A' or letter > 'Z':
	print("The second argument has to be a capital latin letter")
	exit(0)

#directory to create
to_create = sys.argv[1]
os.makedirs(to_create)
os.chdir(to_create)

#contents of which directory to copy
to_copy = "template"
src = os.path.join(os.path.dirname(__file__), to_copy)
for task in range(ord('A'), ord(letter) + 1):
	t = chr(task)
	
	#copies contents to cwd/chr(task)/
	shutil.copytree(src, t)
	#so that name of cpp is also t
	os.rename(os.path.join(t, "template.cpp"), os.path.join(t, t + ".cpp"))
