import bisect

def solve():
    # Read inputs
    n, k = map(int, input().split())
    s = input().strip()
    q = int(input().strip())
    
    # Preprocess the string `s` to build position lists for each allowed letter
    positions = {chr(ord('a') + i): [] for i in range(k)}
    
    # Populate the positions array with positions of each allowed character in `s`
    for i in range(n):
        positions[s[i]].append(i)
    
    # Process each query
    for _ in range(q):
        t = input().strip()
        
        # We need to check if `t` can be a subsequence of `s`
        last_position = -1  # The last matched position in `s`
        for char in t:
            # Find the smallest index in positions[char] which is greater than last_position
            pos_list = positions[char]
            idx = bisect.bisect_right(pos_list, last_position)
            if idx == len(pos_list):
                # If no valid position is found, t cannot be a subsequence anymore
                break
            # Otherwise, update the last_position to this position
            last_position = pos_list[idx]
        else:
            # If we were able to match all characters, it is still a subsequence
            print(0)
            continue
        
        # Calculate how many letters we need to append
        # last_position was the last match in s, and we need to break the subsequence
        append_count = len(t) - (last_position + 1)
        print(append_count)

# Run the function
solve()
