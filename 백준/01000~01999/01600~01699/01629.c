#include <stdio.h>

typedef long long LL;

LL PowerMod(LL a, LL b, LL c) {
    if (b == 0) {
        return 1;
    }

    // 분할 정복을 이용하여 거듭제곱 수행
    LL temp = PowerMod(a, b / 2, c);
    LL result = ((temp % c) * (temp % c)) % c;

    // b가 홀수인 경우 추가적으로 a를 한 번 더 곱해줌
    if (b & 1LL) {
        result = (result * a) % c;
    }

    return result;
}

int main() {
	LL ans;
	LL A, B, C;
	scanf("%lld %lld %lld", &A, &B, &C);
	ans = PowerMod(A, B, C);
	printf("%lld\n", ans);

	return 0;
}