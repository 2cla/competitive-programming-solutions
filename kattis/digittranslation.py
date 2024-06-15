"""zero -> one
one -> eight
two -> one
three -> eight
four ->
five -> eight
six ->
seven -> nine
eight -> two, three
nine -> eight"""

def search(idx, word):
    chain = [dd[len(word)][word]]
    while idx < l:
        end = True
        for b, c in graph[dd[len(word)][word]]:
            if idx + b + c <= l:
                w = s[idx+b:idx+b+c]
                if w in dd[c]:
                    word = w
                    chain.append(dd[c][w])
                    idx += b
                    end = False
                    break
        if end: break
    return idx+len(word)-1, chain
                
import sys; input = sys.stdin.readline
s = input()[:-1]
l, targ, ways = len(s), len(s), 1
threes, fours, fives = {"one": 1, "two": 2, "six": 6}, {"zero": 0, "four": 4, "five": 5, "nine": 9}, {"three": 3, "seven": 7, "eight": 8}
dd = {3: threes, 4: fours, 5: fives}
revmap = {0: "zero", 1: "one", 2: "two", 3: "three", 4: "four", 5: "five", 6: "six", 7: "seven", 8: "eight", 9: "nine"}
graph = {0: [(3, 3)], 1: [(2, 5)], 2: [(2, 3)], 3: [(4, 5)], 4: [], 5: [(3, 5)], 6: [], 7: [(4, 4)], 8: [(4, 3), (4, 5)], 9: [(3, 5)]}
chains = []
i = 0   
while i < l:
    for j in range(3, 6):
        if i+j <= l: 
            w = s[i:i+j]
            if w in dd[j]: 
                i, chain = search(i, w)
                chains.append(chain)
                break
    i += 1

for chain in chains:
    chainl = len(chain)
    if chainl < 2:
        l -= len(revmap[chain[0]]) - 1
        continue
    dp, factor = [0]*chainl, [0]*chainl
    dp[0], dp[1] = len(revmap[chain[0]]) - 1, max(len(revmap[chain[0]]), len(revmap[chain[1]])) - 1
    factor[0] = 1
    if len(revmap[chain[0]]) == len(revmap[chain[1]]): factor[1] = 2
    else: factor[1] = 1

    for i in range(2, chainl):
        dp[i] = max(dp[i-2] + len(revmap[chain[i]]) - 1, dp[i-1])
        if dp[i-2] + len(revmap[chain[i]]) - 1 > dp[i-1]: factor[i] = factor[i-2] % 9302023
        elif dp[i-2] + len(revmap[chain[i]]) - 1 == dp[i-1]: factor[i] = (factor[i-2] + factor[i-1]) % 9302023
        else: factor[i] = factor[i-1] % 9302023
    l -= max(dp)
    ways *= factor[-1] % 9302023

print(l)
print(ways % 9302023)