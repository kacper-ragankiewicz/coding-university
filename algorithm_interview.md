# Checking if int is palindrome
#Python
def isPalindrome(self, x: int) -> bool:
	string = str(x)
	n = len(string)

	for i in range(n // 2):
	    if string[i] != string[n - i - 1]:
		return False

	return True
	
# Checking for pair where (n,n + 1 ) then return max len of elements in array
#Python
def pickingNumbers(a):
    a = sorted(a)
    n = len(a)
    max_length = 0
    
    for i in range(n):
        current_length = 1  # Length of the current subarray
        
        # Check for elements with a difference of 1
        for j in range(i+1, n):
            if a[j] - a[i] <= 1:
                current_length += 1
            else:
                break
        
        max_length = max(max_length, current_length)  # Update the maximum length
    
    return max_length
    
# Counting how many pages need to be swapped to get od direction when if p > mid, n - i
#Python
def pageCount(n, p):
    
    mid = n // 2
    i = 0
    j = 1
    count = 0
    
    if p > mid:
        if n % 2 == 1:
            j = n
            i = n - 1
        else:
            i = n
            j = n + 1 
        while True:
            if i == p or j == p:
                break
            i -= 2
            j -= 2
            count += 1
    else:
        while True:
            if i == p or j == p:
                break
            print(i, j)
            i += 2
            j += 2
            count += 1   
  
    return count
    
# Creating ZigZag sequence from numbers in an array
#Python
def findZigZagSequence(a, n):
    a.sort()
    mid = int((n - 1)/2)
    a[mid], a[n-1] = a[n-1], a[mid]

    st = mid + 1
    ed = n - 2
    while(st <= ed):
        a[st], a[ed] = a[ed], a[st]
        st = st + 1
        ed = ed - 1

    for i in range (n):
        if i == n-1:
            print(a[i])
        else:
            print(a[i], end = ' ')
    return
    
# Checking if givern numbers can make triangle
#Python
def maximumPerimeterTriangle(sticks):
    sticks = sorted(sticks)
    n = len(sticks)
    j = 0
    max_value = 0
    index = 0
    tria = {}
    
    for i in range(n - 2):
        if sticks[i] + sticks[i+1] > sticks[i+2] and sticks[i] + sticks[i+2] > sticks[i+1] and sticks[i+1] + sticks[i+2] > sticks[i]:
            tria[j] = [sticks[i], sticks[i+1], sticks[i+2]]
            j += 1
        
    for x, element in enumerate(tria.values()):
        if sum(element) > max_value:
            max_value = sum(element)
            index = x
        
    if len(tria) == 0:
        return (-1,)
    else:
        return tria[index]
        
# Looking for pairs in the numbers in an array
#Python
def sockMerchant(n, ar):
    sock_count = {}
    pairs = 0
    
    for sock in ar:
        if sock in sock_count:
            sock_count[sock] += 1
        else:
            sock_count[sock] = 1
    for count in sock_count.values():
        pairs += count//2
        
    return pairs
    
#making XOR from input, in example for binary
#Python
def strings_xor(s, t):
    res = ""
    for i in range(len(s)):
        if s[i] == t[i]:
            res += '0';
        else:
            res += '1';

    return res

# Checking if the sum of the values (number if values depends on the month) is sum of a day
#Python
def birthday(s, d, m):
    ways = [sum(s[i:i+m]) for i in range(len(s)-m+1)]
    return ways.count(d)
    
# Array permutation, checking if A[i] + B[i] > k
def twoArrays(k, A, B):

    sA = sorted(A,reverse=True)
    sB = sorted(B)
  
    for i in range(len(A)):
        if (sA[i] + sB[i] < k):
            return "NO"
  
    return "YES"
    
# Adding two numbers in linked list
#Python
def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
	head = None
	temp = None
	carry = 0

	while l1 is not None or l2 is not None:

	    sum_value = carry
	    if l1 is not None:
		sum_value += l1.val
		l1 = l1.next
	    if l2 is not None:
		sum_value += l2.val
		l2 = l2.next

	    node = ListNode(sum_value % 10)
	    carry = sum_value // 10
	    if temp is None:
		temp = head = node
	    else:
		temp.next = node
		temp = temp.next
	if carry > 0:
	    temp.next = ListNode(carry)
	return head
	
# Longest substring
#Python
def lengthOfLongestSubstring(self, s: str):
	max_len = 0
	current_len = 0
	seen = {}

	for i, char in enumerate(s):
	    if char in seen and seen[char] >= i - current_len:
		current_len = i - seen[char]
	    else:
		current_len += 1
	    
	    seen[char] = i
	    max_len = max(current_len, max_len)

	return max_len
	
# Checikg mediana for two arrays
#Python
def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        merged_arr = sorted(nums1 + nums2)
        length = len(merged_arr)
        if length % 2 == 0:
            return (merged_arr[length//2] + merged_arr[length//2 - 1]) / 2
        else:
            return merged_arr[length//2]
            
# Longest paliandrom substring
#Python
def longestPalindrome(self, s: str) -> str:
        if s == s[::-1]:
            return s
        start, size = 0, 1
        for i in range(1, len(s)):
            l, r = i - size, i + 1
            s1, s2 = s[l-1:r], s[l:r]
            if l >= 1 and s1 == s1[::-1]:
                size += 2
                start = l - 1
            elif s2 == s2[::-1]:
                size += 1
                start = l
        return s[start: start + size]
        
#Zig zack convertion for string
#Python
def convert(self, s: str, numRows: int) -> str:
        if s is None and numRows <= 0:
            return ""
        if numRows == 1:
            return s

        result = ""
        step = 2 * numRows - 2

        for i in range(0, numRows):
            for j in range(i, len(s), step):
                result += s[j]
                if i != 0 and i != numRows - 1 and (j + step - 2 * i) < len(s):
                    result += s[j + step - 2 * i]
        return result
        
# Revering int
#Python
def reverse(self, x: int) -> int:
        maxInt = 2 ** 31 - 1
        minInt = -1 * 2 ** 31
        s = str(x) if x >= 0 else str(x)[1:]
        rev = s[::-1] if x >= 0 else '-' + s[::-1]
        revInt = int(rev)
        if revInt > maxInt or revInt < minInt:
            return 0
        return revInt
        
# Atoi funtion
#Python
def myAtoi(self, s: str) -> int:
        if s is None or len(s) < 1:
            return 0
        INT_MAX = 2147483647
        INT_MIN = -2147483648
        s = s.lstrip()
        i = 0
        isNegative = len(s) > 1 and s[0] == '-'
        isPositive = len(s) > 1 and s[0] == '+'
        if isNegative:
            i += 1
        elif isPositive:
            i += 1
        number = 0
        while i < len(s) and '0' <= s[i] <= '9':
            number = number * 10 + (ord(s[i]) - ord('0'))
            i += 1
        if isNegative:
            number = -number
        if number < INT_MIN:
            return INT_MIN
        if number > INT_MAX:
            return INT_MAX
        return number
        
# Checking for start position if two kangarus will land at the same place after some time {

# Python
	def kangaroo(x1, v1, x2, v2):
	    i = 0
	    sum1 = x1
	    sum2 = x2
	    
	    while i <= 5000:
		sum1 += v1
		sum2 += v2
		if sum1 == sum2:
		    return "YES"
		i += 1
	    return "NO"
           
# C++
	string kangaroo(int x1, int v1, int x2, int v2) {
	    int sum1 = x1;
	    int sum2 = x2;
	    int i = 0;
	    while ( i <= 5000 ) {
		sum1 += v1;
		sum2 += v2;
		
		if (sum1 == sum2) {
		    return "YES";
		}
		i += 1;
	    }
	    return "NO";
	}
	
}

# Checking if the number is an palindrome {

# Python
	def isPalindrome(self, x: int) -> bool:
		string = str(x)
		n = len(string)

		for i in range(n // 2):
		    if string[i] != string[n - i - 1]:
			return False

	return True
# Python [Optimazed]
    def isPalindrome(self, x: int) -> bool:
        x = str(x)
        return x == x[::-1]
}

# Checking if string is matching to the pathern {

# Python [Requrention]
def isMatch(self, s: str, p: str) -> bool:
        memo = {}
    
        def dp(i: int, j: int) -> bool:
            if (i, j) in memo:
                return memo[(i, j)]
        
            if j == len(p):
                return i == len(s)
        
            first_match = i < len(s) and (p[j] == s[i] or p[j] == '.')
        
            if j + 1 < len(p) and p[j+1] == '*':
                ans = dp(i, j+2) or (first_match and dp(i+1, j))
            else:
                ans = first_match and dp(i+1, j+1)
        
            memo[(i, j)] = ans
            return ans
    
        return dp(0, 0)

# Python [Library]
import re
    
def isMatch(self, s: str, p: str) -> bool:
        pattern = "^" + p + "$"
        match = re.match(pattern, s)
        if match:
            return True
        else:
            return False



}

# Binary Search {
# Python
def binary_search(arr, target):
	left = 0
	right = len(arr) - 1
	
	while left <= right:
		mid = (right+left) // 2
		if mid == target:
			return target
		if mid < target:
			left = mid + 1
		else:
			right = mid - 1
	return -1
	
# Python [recursive]
def binary_search(arr, target, left right):
	if left > right:
		return -1
	mid = (left + right) // 2
	
	if arr[mid] == target:
		return mid
	elif arr[mid] < target:
		return binary_search(arr, target, mid+1, right)
	else:
		return binary_search(arr, target, left, mid-1)
}

# Bubble Sort {
# Python
def buble_sort(arr):
    n = len(arr)
    for i in range(n):
        for j in range(n-i-1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
    return(arr)
   
# Python [recursive]
def bubble_sort(arr):
    n = len(arr)

    # Base case: If the array is already sorted, return
    if n <= 1:
        return arr

    # Perform a single pass of bubble sort
    for i in range(n - 1):
        if arr[i] > arr[i + 1]:
            arr[i], arr[i + 1] = arr[i + 1], arr[i]

    # Recursively call bubble_sort on the reduced array
    bubble_sort(arr[:n - 1])

    return arr 

}

# Binary Trees {

graph = {
'A' : ['B', 'G'],
'B' : ['C', 'D', 'E'],
'C' : [], 
'D' : [],
'E' : ['F'],
'F' : [],
'G' : ['H'],
'H' : ['I'],
'I' : [],
}

# Python Breadth-First Search
def bfs(graph, node):
	visited = []
	queue = []
	
	visited.append(node)
	queue.append(node)
	
	while queue:
		s = queue.pop(0)
		print(s, end = " ")
		
		for n in graph[s]:
			if n not in visited:
				visited.append(n)
				queue.append(n) 

# Python Depth-First Search (DFS)
from collections import deque

def dfs(graph, node):
	visited = []
	stack = deque()
	
	visited.append(node)
	stack.append(node)
	
	while stack:
		s = stack.pop()
		print(s, end = " ")
		
		for n in reversed(graph[s]):
			if n not in visited:
				visited.append(n)
				stack.append(n)
}

# Separate the numbers and check if they are beutifule {
def separateNumbers(s):    
    if len(s)==1:
        print("NO")
        return    
    for i in range(1, len(s)//2+1): 
        genstr = s[:i]
        prev = int(genstr)        
        while len(genstr) < len(s):             
            next = prev+1
            genstr+=str(next)
            prev = next        
        if genstr == s:
            print("YES", s[:i])
            return    
    print("NO")
}

# Getting thr biggest field of value for graf:
def maxArea(self, height: List[int]) -> int:
        left,right,answer=0,len(height)-1,0
        while left<=right:
            area=min(height[right],height[left])*(right-left)
            answer=max(answer,area)
            if height[right]>height[left]:
                left+=1
            else:
                right-=1
        return answer
        
# Looking for pairs that have min difference between them in an array
# Python
def closestNumbers(arr):
    arr = sorted(arr)
    n = len(arr)
    seen = {}
    j = 0
    dif = 10000
    for i in range(len(arr)-1):
        dif = min(arr[i + 1] - arr[i], dif)
        if arr[i + 1] - arr[i] <= dif:
            dif = arr[i + 1] - arr[i]
            seen[j] = [arr[i], arr[i+1]]
            j += 1
        print(dif)
    array = []
    for i in range(len(seen.values())):
        if seen[i][1] - seen[i][0] != dif:
            del seen[i]
        else:
            array.append(seen[i][0])
            array.append(seen[i][1])
    return array
    
# Coverting int to roman numbers:
# Python hash table
def romanToInt(self, s: str) -> int:
        roman={"I":1,"V":5,"X":10,"L":50,"C":100,"D":500,"M":1000}
        number=0
        for i in range(len(s)-1):
            if roman[s[i]] < roman[s[(i+1)]]:
                number-=roman[s[i]]
            else:
                number+=roman[s[i]]
        return number+roman[s[-1]]
        
# Checking the longest char patern in the array of strings

# Python
def longestCommonPrefix(v: List[str]) -> str:
	ans = ""
	v = sorted(v)
	first = v[0]
	last = v[-1]
	
	for i in range(min(len(first), len(last)):
		if first[i]!=last[i]:
			return ans
		ans += first[i]
	return ans



