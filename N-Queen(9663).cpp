#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
typedef unsigned u;
typedef double d;
int n, count = 0;
int col[27] = { 0, };//����
int diag1[27] = { 0, };//�밢�� 1
int diag2[27] = { 0, };//�밢�� 2
void search(int x);
int main() {
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);//����� �ӵ� ����
    cin >> n;//n �Է�
    search(0);//��Ʈ��ŷ ����
    cout << count;//�Լ� ���� �� ���
}
void search(int y) {
    if (y == n) {//���� ������
        count += 1;//+1
        return;
    }
    for (int x = 0; x < n; x++) {
        if (col[x] || diag1[y + x] || diag2[x - y + n - 1]) continue;//���� �밢��1or�밢��2or���� => �Ѿ
        col[x] = diag1[y + x] = diag2[x - y + n - 1] = 1;//�밢��1,�밢��2,���ο� �߰�
        search(y + 1);//���� y+1��° �ٷ� ��
        col[x] = diag1[y + x] = diag2[x - y + n - 1] = 0;//���� ����� ���� �ʱ�ȭ
    }
}
