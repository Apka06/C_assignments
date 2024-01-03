police_array = eval(input())
police_range = int(input())

captured_thief = []

# m is range and n is array length the time complexity is O(m*n)
def arrest(police_and_thiefs, police_range, captured):
    for idx in range(len(police_and_thiefs)):
        if police_and_thiefs[idx] == "P":
            try:
                for thief_idx in range(idx-police_range, idx+police_range+1):
                    if (thief_idx not in captured) and (police_and_thiefs[thief_idx] == "T"):
                        captured.append(thief_idx)
                        break
            except:
                pass
    print(len(captured), end="")

arrest(police_array, police_range, captured_thief)
