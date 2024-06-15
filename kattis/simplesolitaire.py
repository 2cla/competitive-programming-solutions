deck,hand = [],[]
for _ in range(4): deck.extend(input().split())
for _ in range(52):
    hand.append(deck.pop(0))
    mode = 1
    while mode:
        mode,idx = 0,-1
        for i in range(len(hand)-1,2,-1):
            if hand[i][0] == hand[i-3][0]: idx = i; mode = 2; break
            elif hand[i][1] == hand[i-3][1]: idx = max(idx,i); mode = 1
        if mode == 2: 
            for _ in range(4): hand.pop(idx-3)
        if mode == 1: hand.pop(idx); hand.pop(idx-3)
print("%d %s" % (len(hand), " ".join(hand)))