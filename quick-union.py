# this algo is for dynamically connected components where to predict that two points
# are connected or not is is slow in comparison for quick-find but the time to connect them has incresed to O(N)
#now connected components it is represended as tree

def root(p, id):
    while p != id[p]:
        p = id[p]
    return p

def union(p, q, id):
    p = root(p, id)
    id[p] = root(q, id)
    return id

def connected(p, q, id):
    if root(p, id) == root(q, id):
        return True
    return False

def initialize(numbers):
    id = []
    for i in range(numbers):
        id.append(i)
    return id

n = int(raw_input("Enter number of inputs"))
id = initialize(n)
print id
id = union(9, 8, id)
print id
id = union(3, 4, id)
print id
id = union(6, 8, id)
print id
id = union(0, 1, id)
print id
id = union(2, 7, id)
print id
id = union(2, 1, id)
print id
id = union(3, 9, id)
print id
id = union(6, 5, id)
print id
id = union(5, 1, id)
print id
#answer to quiz1 question1 : 1 1 7 4 8 1 8 1 5 8
