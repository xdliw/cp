from queue import PriorityQueue


def _bin_pow(a, b, m):
    c = 1
    while b > 0:
        if b % 2 == 1:
            c = c * a % m
        a = a * a % m
        b //= 2
    return c


# x^2 = a (mod p)
def _tonelli_shanks(a, p):
    assert a % p != 0
    assert p > 2
    q = p - 1
    s = 0
    while q % 2 == 0:
        q //= 2
        s += 1
    assert s > 0
    if _bin_pow(a, (p - 1) // 2, p) != 1:
        return []
    z = 2
    while _bin_pow(z, (p - 1) // 2, p) != p - 1:
        z += 1
        assert z < p
    c = _bin_pow(z, q, p)
    r = _bin_pow(a, (q + 1) // 2, p)
    t = _bin_pow(a, q, p)
    while t != 1:
        i = 1
        while i < s and _bin_pow(t, 2 ** i, p) != 1:
            i += 1
        assert i < s
        b = _bin_pow(c, 2 ** (s - i - 1), p)
        r = r * b % p
        t = t * b * b % p
        c = b * b % p
        s = i
    return sorted([r, p - r])


# x^2 = a (mod p^k)
def _generalized_tonelli_shanks(a, p, k):
    assert a % p != 0
    assert p > 2
    assert k > 0
    ans = []
    m = p ** k
    d = _bin_pow(a, (m - 2 * m // p + 1) // 2, m)
    for x in _tonelli_shanks(a, p):
        ans.append(_bin_pow(x, m // p, m) * d % m)
    return sorted(ans)


# x^2 = a (mod 2^k)
def _discrete_sqrt_2(a, k):
    assert k > 0
    assert a > 0
    if k == 1:
        return [1]
    if a % 8 != 1:
        return []
    ans = set()
    for x in [1, 3]:
        for i in range(3, k):
            j = ((x * x - a) // (2 ** i) % 2 + 2) % 2
            x = x + j * 2 ** (i - 1)
        ans.add(x)
        ans.add(2 ** k - x)
    return sorted(list(ans))


# x^2 = 0 (mod p^k)
def _discrete_sqrt_zero(p, k):
    assert p > 1
    assert k > 0
    ans = [0]
    x = p ** ((k + 1) // 2)
    for i in range(1, (p ** k) // x):
        ans.append(x * i)
    return ans


# x^2 = a (mod p^k)
def _discrete_sqrt_prime(a, p, k):
    assert p > 1
    assert k > 0
    if a == 0:
        return _discrete_sqrt_zero(p, k)
    q, s = a, 0
    while q % p == 0:
        q //= p
        s += 1
    if s == 0:
        if p == 2:
            return _discrete_sqrt_2(a, k)
        return _generalized_tonelli_shanks(a, p, k)
    if s % 2 != 0:
        return []
    xq = _discrete_sqrt_prime(q, p, k)
    x0 = p ** (s // 2)
    d = p ** max((k + 1) // 2, k - s // 2 - (1 if p == 2 else 0))
    ans = set()
    for i in range((p ** k) // d):
        for x in xq:
            ans.add((x0 + i * d) * x % (p ** k))
    return sorted(list(ans))


def _ex_gcd(a, b):
    x, xp = 1, 0
    y, yp = 0, 1
    while b != 0:
        q = a // b
        a, b = b, a - q * b
        x, xp = xp, x - q * xp
        y, yp = yp, y - q * yp
    return (a, x, y)


def _factorize(n):
    assert n > 0
    ans = []
    i = 2
    while i * i <= n:
        if n % i != 0:
            i += 1
            continue
        ans.append(i)
        n //= i
    if n > 1:
        ans.append(n)
    return ans


# x^2 = a (mod m)
def discrete_sqrt(a, m):
    assert m > 0
    ans = [0]
    mans = 1
    fm = _factorize(m)
    it = 0
    while it < len(fm):
        jt = it
        while jt < len(fm) and fm[jt] == fm[it]:
            jt += 1
        p = fm[it]
        k = jt - it
        pk = p ** k
        x = _discrete_sqrt_prime(a % pk, p, k)
        g, x1, _ = _ex_gcd(mans, pk)
        assert g == 1
        nans = []
        for r0 in ans:
            for r1 in x:
                nans.append(((r0 + x1 * (r1 - r0) % pk * mans) % (mans * pk) + (mans * pk)) % (mans * pk))
        ans = nans
        mans *= pk
        it = jt
    return sorted(ans)


def floor_sqrt(n):
    l, r = 0, n + 1
    while l < r:
        m = (l + r) // 2
        if m * m <= n:
            l = m + 1
        else:
            r = m
    return l - 1


# x^2 - d * y^2 = 1
def solve_pell(d):
    assert d > 0
    r = floor_sqrt(d)
    assert r * r < d
    a2, a1 = 0, 1
    b2, b1 = 1, 0
    p, q = 0, 1
    for _ in range(d + 1):
        a = (p + r) // q
        a0 = a * a1 + a2
        b0 = a * b1 + b2
        if a0 * a0 - b0 * b0 * d == 1:
            return (a0, b0)
        a2, a1 = a1, a0
        b2, b1 = b1, b0
        p = a * q - p
        q = (d - p * p) // q
    assert False


# x^2 - d * y^2 = n
def solve_generalized_pell(d, n):
    assert d > 0
    assert n != 0
    r = floor_sqrt(d)
    assert r * r < d
    ans = []
    for f in range(1, floor_sqrt(abs(n)) + 1):
        if n % (f * f) != 0:
            continue
        m = n // (f * f)
        for z in discrete_sqrt(d, abs(m)):
            if z > abs(m) // 2:
                z -= abs(m)
            assert z >= -((abs(m) - 1) // 2)
            assert z <= abs(m) // 2
            a2, a1 = 0, 1
            b2, b1 = 1, 0
            p, q = z, abs(m)
            g2, g1 = -p, q
            cnt = {}
            valid = False
            for i in range(4 * d + 1):
                a = (p + r) // q
                a0 = a * a1 + a2
                b0 = a * b1 + b2
                g0 = a * g1 + g2
                if i > 0:
                    if abs(q) == 1:
                        if g1 * g1 - b1 * b1 * d == m:
                            x = g1 * f
                            y = b1 * f
                            if x < 0 and y < 0:
                                x, y = -x, -y
                            ans.append((x, y))
                            valid = True
                            break
                        else:
                            assert g1 * g1 - b1 * b1 * d == -m
                    cnt[(p, q)] = cnt.get((p, q), 0) + 1
                    if cnt[(p, q)] > 2:
                        valid = True
                        break
                a2, a1 = a1, a0
                b2, b1 = b1, b0
                g2, g1 = g1, g0
                p = a * q - p
                q = (d - p * p) // q
            assert valid
    for i in range(len(ans)):
        for j in range(i + 1, len(ans)):
            a = ans[i][0] * ans[j][0] - ans[i][1] * ans[j][1] * d
            b = ans[i][0] * ans[j][1] - ans[i][1] * ans[j][0]
            assert a % n != 0 or b % n != 0
    return sorted(ans)


def solve(k):
    if k == 1:
        return 1
    a = k
    b = k * (k - 1)
    c = k * (k - 1) * (2 * k - 1) // 6
    pn = b * b - 4 * a * c
    pd = 4 * a
    r = floor_sqrt(pd)
    if r * r == pd:
        ans = None
        # x^2 - (r * y)^2 = pn
        # (x - r * y) * (x + r * y) = pn
        for p in range(1, floor_sqrt(abs(pn)) + 1):
            if pn % p != 0:
                continue
            q = pn // p
            # x - r * y = q
            # x + r * y = p
            # x = (p + q) / 2
            # y = (p - q) / (2 * r)
            if (p + q) % 2 == 0 and (p - q) % (2 * r) == 0:
                x = abs((p + q) // 2)
                y = abs((p - q) // (2 * r))
                assert x * x - y * y * pd == pn
                # x = 2 * a * n - b
                if (x - b) % (2 * a) == 0:
                    n = (x - b) // (2 * a)
                    if n > 0 and (not ans or n < ans):
                        ans = n
        return ans
    x0 = solve_generalized_pell(pd, pn)
    if not x0:
        return None
    dx = solve_pell(pd)
    q = PriorityQueue()
    for i, (x, y) in enumerate(x0):
        q.put((x, y, i))
    cnt = {}
    while not q.empty():
        x, y, i = q.get()
        assert x * x - pd * y * y == pn
        rx = (x - b) % (2 * a)
        ry = y % (2 * a)
        if rx == 0:
            n = (x - b) // (2 * a)
            if n > 0:
                return n
        cnt[(i, rx, ry)] = cnt.get((i, rx, ry), 0) + 1
        if cnt[(i, rx, ry)] > 2:
            return None
        if dx:
            nx = x * dx[0] + y * dx[1] * pd
            ny = x * dx[1] + y * dx[0]
            assert nx > x
            q.put((nx, ny, i))
    assert False


t = int(input())
for _ in range(t):
    k = int(input())
    ans = solve(k)
    if ans:
        print("Yes")
        print(ans)
    else:
        print("No")


# for i in range(1, 10000):
#     if floor_sqrt(i)**2 != i:
#         print(solve_pell(i))


# for i in range(1, 1000):
#     if floor_sqrt(i)**2 == i:
#         continue
#     for j in range(1, 1000):
#         ans = solve_generalized_pell(i, j)
#         for x, y in ans:
#             assert y > 0
#         print(ans)


# print(solve_generalized_pell(13, 27))
# print(solve_generalized_pell(157, 12))
# print(solve_generalized_pell(13, 108))

