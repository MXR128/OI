/**
 * 2019.11.11【NOIP提高组】模拟 B 组
 * A 正确答案
 */

#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>

int n, m, p, q, pt = 0, qt = 0, ans = -1;
std::string s[30020], P[30020], Q[30020];

std::string _qf(std::string x) {
	for (int i = 0; i < m; ++i) {
		if (x[i] == 'Y')
			x[i] = 'N';
		else
			x[i] = 'Y';
	}
	return x;
}

char ss[600];
bool _is(std::string z) {
	for (int i = 1; i <= n; ++i)
		if (z == s[i] || z == _qf(s[i]))
			return true;
	return false;
}

int main() {
	freopen("answer2.in", "r", stdin);
	scanf("%d%d%d%d", &n, &m, &p, &q);
	for (int i = 1; i <= n; ++i)
		std :: cin >> s[i];
	std::sort(&s[1], &s[n + 1]);
	for (int i = 1, k = 1; i <= n + 1; ++i) {
		if (s[i] != s[i - 1]) {
			if (i - k == p)
				P[++pt] = s[i - 1];
			if (i - k == q)
				Q[++qt] = s[i - 1];
			k = i;
		}
	}
	if (p == 0) {
		if (q == 0) {
			s[0] = s[1];
			for (int i = 0; i < m; ++i)
				s[0][i] = 'N';
			while(_is(s[0])){
				
			}
			std::cout << s[0];
			return 0;
		}
		std::sort(&Q[1], &Q[qt + 1]);
		std::cout << _qf(Q[1]);
	}
	if (pt == 1)
		std::cout << P[1];
	else {
		std::sort(&P[1], &P[pt + 1]);
		for (int i = 1; i <= pt && ans == -1; ++i)
			for (int j = 1; j <= n && ans == -1; ++j)
				if (P[i] == _qf(Q[j]))
					ans = i;
		std::cout << P[ans];
	}

	return 0;
}