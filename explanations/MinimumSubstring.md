# MINIMIM SUBSTRING (SMALLEST SUBSTRING SEARCH)

We search for a minimum substring containing the chars given in 
another string.

Understanding how to solve this problem was really hard for me. My brain just freezed as usual.

The trick is keeping a hashtable for both strings and initializing two pointers while traversing first string (left and right)

The area between left and right pointers is our window.

We first move right pointer to the right and try to find a valid window. If we find a valid window, then we try to minimize it by moving left pointer to the right as much as we can. And then we update minimum length window.

Lastly we take the substring by reading minimum window length and start index.
