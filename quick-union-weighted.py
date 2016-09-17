# this algo is for dynamically connected components where to predict that two points
# are connected or not is is slow in comparison for quick-find but the time to connect them has incresed to O(N)
# connected components it is represended as tree

def root(p, id):
    while p != id[0][p]:
        p = id[0][p]
    return p

def union(p, q, id):
    p = root(p, id)
    q = root(q, id)
    if id[1][p] < id[1][q] :  #size of q tree is greater than p hence p will be child
        id[0][p] = q
        id[1][q] += id[1][p]
    else :
        id[0][q] = p
        id[1][p] += id[1][q]
    return id

def connected(p, q, id):
    if root(p, id) == root(q, id):
        return True
    return False

def initialize(numbers):
    id = []
    size = []
    for i in range(numbers):
        id.append(i)
        size.append(1)
    return [id, size]

n = int(raw_input("Enter number of inputs"))
id = initialize(n)
print id
id = union(7, 6, id)
print id
id = union(3, 9, id)
print id
id = union(4, 5, id)
print id
id = union(6, 3, id)
print id
id = union(5, 0, id)
print id
id = union(1, 2, id)
print id
id = union(0, 1, id)
print id
id = union(9, 5, id)
print id
id = union(1, 8, id)
print id
#answer to quiz1 question2 :
