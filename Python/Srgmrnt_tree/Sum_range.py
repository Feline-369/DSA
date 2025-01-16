# Define the NumArray class as provided
#mutable data find the sum of rANGE
from typing import List
class NumArray:
    def __init__(self, nums: List[int]):
        self.nums = nums
        self.n = len(self.nums)
        if self.n > 0:
            self.tree = [0] * (4 * self.n)  # Ensure the tree is large enough
            self.build(1, 0, self.n - 1)
        else:
            self.tree = []

    def build(self, i, l, r):
        if l == r:
            self.tree[i] = self.nums[l]
        else:
            m = (l + r) // 2
            self.build(2 * i, l, m)
            self.build(2 * i + 1, m + 1, r)
            self.tree[i] = self.tree[2 * i] + self.tree[2 * i + 1]

    def t_update(self, i, l, r, val, pos):
        if l == r:
            self.tree[i] = val
        else:
            m = (l + r) // 2
            if pos <= m:
                self.t_update(2 * i, l, m, val, pos)
            else:
                self.t_update(2 * i + 1, m + 1, r, val, pos)
            self.tree[i] = self.tree[2 * i] + self.tree[2 * i + 1]

    def Sum(self, i, l, r, tl, tr):
        if tl > tr:
            return 0
        if l == tl and r == tr:
            return self.tree[i]
        m = (l + r) // 2
        return (self.Sum(2 * i, l, m, tl, min(tr, m)) + 
                self.Sum(2 * i + 1, m + 1, r, max(tl, m + 1), tr))

    def update(self, index: int, val: int) -> None:
        if self.n > 0:
            self.t_update(1, 0, self.n - 1, val, index)

    def sumRange(self, left: int, right: int) -> int:
        if self.n > 0:
            return self.Sum(1, 0, self.n - 1, left, right)
        return 0

# Test case sequence
obj = NumArray([1, 3, 5])
print(obj.sumRange(0, 2))  # Expected output: 9
obj.update(1, 2)  # Update index 1 to value 2
print(obj.sumRange(0, 2))  # Expected output: 8
