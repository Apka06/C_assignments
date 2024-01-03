x_raw = input()
y_raw = input()
z = input()
try:
	x = x_raw[:-1]
	y = y_raw[:-1]
except:
	pass

length_of_z = len(z)
length_of_x = len(x)
length_of_y = len(y)


# Time complexity is O(n). Bottom-up dynamic algorithm.

def is_matching(x, y, z, length_z, length_x, length_y):
    idx_x, idx_y = 0, 0
    if length_z != len(x) + len(y):
        return False
    for idx in range(len(z)):
        if (idx_x < length_x) and (z[idx] == x[idx_x]):
            idx_x += 1
        elif (idx_y < length_y) and (z[idx] == y[idx_y]):
            idx_y += 1
        else:
            break
    else:
        return True
    return False

if is_matching(x, y, z, length_of_z, length_of_x, length_of_y):
    print("YES", end = "")
else:
    print("NO", end = "") 
