# https://www.codechef.com/problems/QUADROOT
import math

a = int(input())
b = int(input())
c = int(input())

d = b ** 2 - 4 * a * c

root1 = (-b + math.sqrt(d)) / (2 * a)
root2 = (-b - math.sqrt(d)) / (2 * a)

print(int(round(root1, 6)))
print(int(round(root2, 6)))
