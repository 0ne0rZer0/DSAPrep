from sys import stdout, stdin
t = int(stdin.readline())
for _ in range(t):
    s = input()
    vowels = {"A": 0, "U": 0, "O": 0,"I": 0,"E": 0}
    vowelcount = 0
    vow = {}
    consonentcount = 0
    consonents = {}
    for i in s:
        if i not in vowels:
            if i not in consonents:
                consonents[i] = 0
            consonents[i] += 1
            consonentcount += 1
        else:
            vowels[i] += 1  
            vowelcount += 1
    maxvowel = max(vowels.values())
    if consonentcount > 0:
        maxconsonent = max(consonents.values())
    else:
        maxconsonent = 0
    # print(vowelcount, maxvowel, consonentcount, maxconsonent)
    ans1 = (vowelcount - maxvowel)*2 + consonentcount
    ans2 = (consonentcount - maxconsonent)*2 + vowelcount;
    print("Case #{}: {}".format(_+1,min(ans1,ans2)))