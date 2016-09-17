import random as rnd
import sys

def generateArray(n):
	a = []
	for i in range(n):
		a.append(rnd.randint(1, n*100))
	return a

def heapify(a):
	b = range(len(a)/2)
	b.reverse()
	for i in b:
		heapifyUtil(a, i)

def heapifyUtil(a, i):
	left = 2*i + 1
	right = 2*i + 2
	greater = i
	if left < len(a) and a[greater] > a[left]:
	    greater = left
	if right < len(a) and a[greater] > a[right]:
	    greater = right
	if a[i] > a[greater]:
	    a[i], a[greater] = a[greater], a[i]
	    heapifyUtil(a, greater)


print sys.argv
number_of_elements = 10;
if len(sys.argv) > 1:
	number_of_elements = int(sys.argv[1])
a = generateArray(number_of_elements)
print a
heapify(a)
print a