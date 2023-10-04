def z_function(s, n):
    z = [0] * n
    l, r = 0, 0
    for i in range(1, n):
        if i < r:
            z[i] = min(r - i, z[i - l])
        while i + z[i] < n and s[z[i]] == s[i + z[i]]:
            z[i] += 1
        if i + z[i] > r:
            l = i
            r = i + z[i]
    return z


def password(s):
    n = len(s)
    z = z_function(s, n)
    ans = "Just a legend"
    for i in range(1, n):
        if z[i] == n - i:
            for j in range(1, n - z[i]):
                if z[j] >= z[i]:
                    ans = s[0 : z[i]]
                    print(ans)
                    return
    print(ans)


if __name__ == "__main__":
    s = input()
    password(s)
