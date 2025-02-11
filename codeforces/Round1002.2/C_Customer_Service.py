def calculate_mex(test_cases):
    results = []
    for case in test_cases:
        n, a = case
        # 计算后缀和
        suffix_sums = [[0] * n for _ in range(n)]
        for i in range(n):
            suffix_sums[i][-1] = a[i][-1]
            for j in range(n-2, -1, -1):
                suffix_sums[i][j] = suffix_sums[i][j+1] + a[i][j]
        
        # 按照后缀和排序
        sorted_queues = sorted(range(n), key=lambda x: suffix_sums[x][0])
        
        # 选择服务顺序
        x = [0] * n
        for i in range(n):
            x[sorted_queues[i]] = i
        
        # 计算 MEX
        mex = 0
        while mex in x:
            mex += 1
        results.append(mex)
    return results

# 读取输入
t = int(input())
test_cases = []
for _ in range(t):
    n = int(input())
    a = []
    for _ in range(n):
        a.append(list(map(int, input().split())))
    test_cases.append((n, a))

# 计算结果
results = calculate_mex(test_cases)

# 输出结果
for res in results:
    print(res)