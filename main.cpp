//#include <iostream>
//
//
//std::pair<float, float>
//linear2(float left_right_diff) {
//    float eps = 0.3;
//    float degree2 = 2;
//    float degree4 = 4;
//    float y_eps = 0.2;
//    float y_2 = 0.2;
//    float y_4 = 0.2;
//    float k1 = (y_2 - y_eps) / (degree2 - eps);
//    float k2 = (y_4 - y_2) / (degree4 - degree2);
//    float l = 1;
//    float r = 1;
//
//    if (left_right_diff < -degree4) {           // left is upper -4o+  -> freeze right;
//        l = 1 - y_4;
//    } else if (left_right_diff < -degree2) {    // left is upper -2 .. -4  -> freeze right;
//        float k = (left_right_diff + degree4) * k2 - y_4;
//        l = 1 + k;
//    } else if (left_right_diff < -eps) {    // left is upper  -> freeze right;
//        float k = (left_right_diff + degree2) * k1 - y_2;
//        l = 1 + k;
//    } else if (left_right_diff < eps) {    // -eps ... eps
//        // pass
//        r = l = 1;
//    } else if (left_right_diff < degree2) {    // left is upper  -> freeze left;
//        float k = (left_right_diff - degree2) * k1 + y_2;
//        r = 1 - k;
//    } else if (left_right_diff < degree4) {    // left is upper  -> freeze left;
//        float k = (left_right_diff - degree4) * k2 + y_4;
//        r = 1 - k;
//    } else {
//        r = 1 - y_4;
//    }
//    return {l, r};
//}
//
//int main_linear() {
//    float fr, fl, rl, rr;
//
//    for (float degree = -5; degree < 5; degree += 0.1) {
//        fr = fl = rl = rr = 1;
//        //linear2(fl,rl,rr,fr,degree); //left-right
//        //linear2(fl,fr,rl,rr,degree);  //rear-front
//
//        auto [l, r] = linear2(degree);
//
//        std::cout << l << " [" << degree << "] " << r << std::endl;
////        std::cout << rl << " [" << degree << "] " << fl << std::endl;
////        std::cout << rr << " [" << degree << "] " << fr << std::endl;
//    }
//    std::cout << "Hello, World!" << std::endl;
//    return 0;
//}
//
//#include <assert.h>
//#include <stdio.h>
//#include <stdlib.h>
//
//long long gcd_r(long long x, long long y) {
//    long long q;
//    x = abs(x);
//    y = abs(y);
//
//    if (y > x)
//        return gcd_r(y, x);
//
//    q = x % y;
//    if (q == 0)
//        return y;
//    return gcd_r(y, q);
//}
//
//long long gcd(long long x, long long y) {
//    long long q;
//    x = abs(x);
//    y = abs(y);
//    if (y > x) {
//        q = x;
//        x = y;
//        y = q;
//    }
//    do {
//        q = x % y;
//        x = y;
//        y = q;
//    } while (q != 0);
//    return x;
//}
//
//static unsigned long int next = 1;
//
//int rand() {
//    next = next * 1103515245 + 12345;
//    return (unsigned int) (next / 65536) % 32768;
//}
//
//long long rand_64() {
//    int64_t value = rand();
//    value <<= 15; // сдвиг на 15, так как 7FFF покрывает 15 бит
//    value |= rand();
//    value <<= 15;
//    value |= rand();
//    value <<= 15;
//    value |= rand();
//    value <<= 3;
//    value |= rand() & 0b111; // дополнительные 3 случайных бита
//    return value;
//}
//long long data_test[3][3] = {
//        {698917, -102089, 7853},
//        {-417143, -455947, 9701},
//        {-659323, 727699, 7}
//};
//
//void test_arr()
//{
//    for(int i = 0; i < 3; ++i)
//    {
//        auto a = data_test[i][0];
//        auto b = data_test[i][1];
//        auto r = data_test[i][2];
//        auto gcd1 = gcd_r(a,b);
//        auto gcd2 = gcd(a,b);
//        if(gcd1 != r || gcd2 != r)
//        {
//            printf("%d:for a=%lld, b=%lld gdb_r = %lld, gdb = %lld, expected=%lld\n", i, a, b, gcd1, gcd2, r);
//
//        }
//    }
//}
//
//void test(int count) {
//    for (int i = 0; i < count; ++i) {
//        auto a = rand_64();
//        auto b = rand_64();
//        auto gcd1 = gcd_r(a, b);
//        auto gcd2 = gcd(a, b);
//        if (gcd1 != gcd2 || gcd1 < 0) {
//            printf("%d:for a=%llu, b=%llu gdb_r = %llu, gdb = %llu\n", i, a, b, gcd1, gcd2);
//        }
//    }
//}
//
//int main() {
//    test_arr();
//    test(10);
//    return 0;
//    unsigned long long x = 0, y = 0, g;
//    int res;
//
//    res = scanf("%llu %llu", &x, &y);
//    assert(res == 2);
//    g = gcd_r(x, y);
//    printf("%llu\n", g);
//    return 0;
//}
