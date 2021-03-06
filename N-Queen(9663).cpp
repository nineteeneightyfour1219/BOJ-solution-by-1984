#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
typedef unsigned u;
typedef double d;
int n, count = 0;
int col[27] = { 0, };//세로
int diag1[27] = { 0, };//대각선 1
int diag2[27] = { 0, };//대각선 2
void search(int x);
int main() {
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);//입출력 속도 증가
    cin >> n;//n 입력
    search(0);//백트래킹 시작
    cout << count;//함수 실행 후 출력
}
void search(int y) {
    if (y == n) {//만약 성립시
        count += 1;//+1
        return;
    }
    for (int x = 0; x < n; x++) {
        if (col[x] || diag1[y + x] || diag2[x - y + n - 1]) continue;//만약 대각선1or대각선2or세로 => 넘어감
        col[x] = diag1[y + x] = diag2[x - y + n - 1] = 1;//대각선1,대각선2,세로에 추가
        search(y + 1);//다음 y+1번째 줄로 감
        col[x] = diag1[y + x] = diag2[x - y + n - 1] = 0;//다음 계산을 위해 초기화
    }
}
