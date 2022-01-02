def binarySearch(arr, x):
    left = 0
    right = len(arr) - 1

    while (left <= right):
        mid = (left + right)//2
        if (arr[mid] < x):
            left = mid + 1
        elif (arr[mid] > x):
            right = mid - 1
        else:
            return mid
    return -1


n = int(input("Enter the number of elements: "))
arr = []
print("Enter the elements of list")
for i in range(n):
    val = int(input())
    arr.append(val)
x = int(input("Enter the element you want to search for: "))
arr.sort()
ans = binarySearch(arr, x)

if (ans != -1):
    print(x, "is present")
else:
    print(x, "is not present")
