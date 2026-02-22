#include<bits/stdc++.h>
#include<unordered_set>
#include<ranges>
#include<print>

using namespace std;

using LL = long long;
using ULL = unsigned long long;
using Pii = pair<int, int>;
template<typename T> using V1 = vector<T>;
template<typename T> using V2 = V1<V1<T>>;
template<typename T> using V3 = V1<V2<T>>;

namespace CONSTS {
    constexpr string_view SEPS = " \n";
    constexpr bitset<1 << 11> MASK = bitset<1 << 11>().set();
    constexpr Pii DT4[4] = { {-1,0}, {0,1} ,{1,0} ,{0,-1} };
    constexpr ULL MOD = 1E+9 + 7, INF = 0x3f3f3f3f, MAX = 1E+5, SHIFT = 11, BUCKET = 1 << SHIFT;
    constexpr int DIGITS = 10, ALPHABETS = 26;
    constexpr auto Rng = views::iota;
    constexpr auto Step = views::stride;
}
using namespace CONSTS;

void FastIO();
void SetUp();
bool Input();
void Solve();
void Output();

bitset<BUCKET> bs[MAX / BUCKET + 1];
int counts[MAX / BUCKET + 1];
int N, M, q, a, b;

int main() {
    FastIO();
    SetUp();

    Input();
    Solve();
    Output();

    return 0;
}

void FastIO() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    return;
};

void SetUp() {
    return;
};

bool Input() {
    cin >> N >> M;

    return true;
};

void Solve() {
    auto Update = [&](int a, int b) {
        int q1 = a >> SHIFT, r1 = a & (BUCKET - 1);
        int q2 = b >> SHIFT, r2 = b & (BUCKET - 1);
        if (q1 == q2) {
            bs[q1] ^= (MASK << r1) & (MASK >> (BUCKET - 1 - r2)); 
            counts[q1] = bs[q1].count();
        }
        else {
            for (int b = q1 + 1; b < q2; b++) {
                bs[b].flip();
                counts[b] = BUCKET - counts[b];
            }
            bs[q1] ^= (MASK << r1);  
            counts[q1] = bs[q1].count();
            bs[q2] ^= (MASK >> (BUCKET - 1 - r2)); 
            counts[q2] = bs[q2].count();
        }
    };
    auto Query = [&](int a, int b) {
        int q1 = a >> SHIFT, r1 = a & (BUCKET - 1);
        int q2 = b >> SHIFT, r2 = b & (BUCKET - 1);
        int cnt = 0;
        if (q1 == q2) {
            auto mask = (MASK << r1) & (MASK >> (BUCKET - 1 - r2));
            cnt = (bs[q1] & mask).count();
        }
        else {
            for (int block = q1 + 1; block < q2; block++) {
                cnt += counts[block];
            }
            auto mask1 = (MASK << r1);
            auto mask2 = (MASK >> (BUCKET - 1 - r2));
            cnt += (bs[q1] & mask1).count();
            cnt += (bs[q2] & mask2).count();
        }
        return cnt;
    };
    for (int i = 0; i < M; i++) {
        cin >> q >> a >> b;
        a--, b--;
        if (q == 0) {
            Update(a, b);
        }
        else {
            println("{}", Query(a, b));
        }
    }
};

void Output() {
    return;
};
