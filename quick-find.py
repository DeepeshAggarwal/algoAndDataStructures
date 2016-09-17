# this algo is for dynamically connected components where to predict that two points
# are connected or not is fast but the time to connect them is slow

def union(p, q, id):
    if id[p] == id[q]:
        return id
    component_number = id[p]
    count = 0
    for number in id:
        if number == component_number:
            id[count] = id[q]
        count += 1
    return id

def connected(p, q, id):
    if id[p] == id[q]:
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
id = union(3, 7, id)
print id
id = union(6, 7, id)
print id
id = union(0, 9, id)
print id
id = union(2, 4, id)
print id
id = union(8, 7, id)
print id
id = union(6, 5, id)
print id
#answer to quiz1 question1 : 3 5 2 3 3 5 3 7 3 7
