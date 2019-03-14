#include <iostream>
#include <stack>
using namespace std;
void goodjack(int, int); // 小克

int main() {
    int n = 0, m = 0;
    cout << "請輸入書的總數量以及動作次數(以空格隔開):";
    cin >> n >> m;

    // 把一切丟給小克做
    goodjack(n, m);
}


// 這是小克
void goodjack(int n, int m) {
    char d;
    int t = 0, num = 1/* 幫書編號用 */, k = 0/* 控制陣列 */, outputer[n]/* 存拿出的書 */;
    stack <int> books;

    // 讓小克做m次動作
    for(int i = 0; i < m; i++) {
        cout << "請輸入動作以及書本數量(放入輸入 a，拿出輸入 b)(以空格隔開):";
        cin >> d >> t;

        // 判斷到底是放入還是拿出
        if(d == 'a') {
            // 放入
            for(int j = 0; j < t; j++) {
                if(num <= n) {
                    books.push(num);
                    num++;
                }   
            }
        }else if(d == 'b') {
            // 拿出
            for(int j = 0; j < t; j++) {
                if(! books.empty()) {
                    outputer[k] = books.top();
                    books.pop();
                    k++;
                } 
            }
        }
    }

    // 輸出
    cout << "拿出的書編號依序為：";
    for(int i = 0; i < k; i++) {
        printf("%i ", outputer[i]);
    }
}
