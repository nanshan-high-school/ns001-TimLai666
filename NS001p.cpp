#include <iostream>
#include <stack>
#include <queue>
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
    int num = 1;
    queue <char> out/* 存拿出的書 */;
    stack <int> books;

    // 讓小克做m次動作
    for(int i = 0; i < m; i++) {
        char d, name;
        int t = 0;
        cout << "請輸入動作以及書本數量(放入輸入 a，拿出輸入 b)以及書本名稱(按順序輸入)(以空格隔開):";
        cin >> d >> t;

        // 判斷到底是放入還是拿出
        switch(d) {
            case 'a':
                // 放入
                for(int j = 0; j < t; j++) {
                    if(num <= n) {
                        cin >> name;
                        books.push(name);
                        num++;
                    }   
                }
                break;
            case 'b':
                // 拿出
                for(int j = 0; j < t; j++) {
                    if(! books.empty()) {
                        out.push(books.top());
                        books.pop();
                    } 
                }
        }
    }

    // 輸出
    cout << "拿出的書編號依序為：";
    for(int i = 0; ! out.empty(); i++) {
        cout << out.front();
        out.pop();
        if(! out.empty()) {
            cout << " ";
        }
    }
}
