def computeLPS(pattern):
	lps = [0]*len(pattern)
	j = 0
	for i in range(1, len(pattern)):
		if pattern[i] == pattern[j]:
			lps[i] = j+1;
			j += 1
		else:
			while j !=0 and pattern[i] != pattern[j]:
				j = lps[j-1]
			if j!=0:
				j+=1
			lps[i] = j
	return lps
def anotherComputeLPS(pattern):
	lps = [0]*len(pattern)
	j = 0
	i = 1
	while i < len(pattern):
		if pattern[i] == pattern[j]:
			j += 1;
			lps[i] = j;
			i += 1
		else:
			if j==0:
				lps[i] = j
				i += 1
			else:
				j = lps[j-1]
	return lps

def textPattern(text, pattern):
	lps = computeLPS(pattern)
	i = 0
	j = 0
	while i < len(text):
		if text[i] == pattern[j]:
			i += 1
			j += 1

		if j == len(pattern):
			print "pattern found at", i-j
			j = lps[j-1]

		elif pattern[j] != text[i] and i < len(text):
			if j != 0:
				j = lps[j-1]
			else:
				i += 1				

if __name__ == '__main__':
	#textPattern(raw_input(), raw_input())
	print anotherComputeLPS(raw_input())