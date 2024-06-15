s = [*input()]
s2 = ''.join([i for i in s if i.isalpha()]).lower()
for j in range(len(s2)):
    for i in range(j):
        if s2[i:j+1] == s2[i:j+1][::-1]:
            print("Palindrome")
            exit(0)
print("Anti-Palindrome")