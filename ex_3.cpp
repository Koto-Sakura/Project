#include <iostream>
#include <vector>

using namespace std;

int Available[3]; // ������ԴA��B��C��������
int Max[5][3];    // ������̵����������
int Allocation[5][3]; // ������̵��ѷ�����Դ
int Need[5][3];   // ����Ҫ����Դ��

void NeedMatrix(int Allocation[][3], int Max[][3], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            Need[i][j] = Max[i][j] - Allocation[i][j];
        }
    }
}

void AvailableMatrix() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 3; j++) {
            Available[j] -= Allocation[i][j]; // �����ѷ�����Դ��
        }
    }
}

void PrintResourceStatus(int n, int m) {
    cout << "��ǰ��Դ����״̬��" << endl;
    cout << "����\t����\t���\t��Ҫ\t����" << endl;

    for (int i = 0; i < n; i++) {
        cout << "P" << i << "\t";
        for (int j = 0; j < m; j++) {
            cout << Allocation[i][j] << " ";
        }
        cout << "\t";
        for (int j = 0; j < m; j++) {
            cout << Max[i][j] << " ";
        }
        cout << "\t";
        for (int j = 0; j < m; j++) {
            cout << Need[i][j] << " ";
        }
        if (i == 0) {
            cout << "\t";
            for (int j = 0; j < m; j++) {
                cout << Available[j] << " ";
            }
        }
        cout << endl;
    }
    cout << endl;
}


void SafeSequence(int Need[][3], int Available[], int n, int m) {
    cout << "��ʼ��鰲ȫ��" << endl;
    vector<int> safeSeq;
    bool isFinished[n] = {false};
    int safeCount = 0;

    while (safeCount < n) {
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (!isFinished[i]) {
                int j = 0;
                for (; j < m; j++) {
                    if (Need[i][j] > Available[j]) {
                        cout << "����P" << i << "��Request[";
                        for (int k = 0; k < m; k++) {
                            cout << Need[i][k];
                            if (k < m - 1) {
                                cout << "��";
                            }
                        }
                        cout << "]>Available[";
                        for (int k = 0; k < m; k++) {
                            cout << Available[k];
                            if (k < m - 1) {
                                cout << "��";
                            }
                        }
                        cout << "]������ʧ��" << endl;
                        break;
                    }
                }
                if (j == m) {
                    safeSeq.push_back(i);
                    safeCount++;

                    cout << "����P" << i << "��Request[";
                    for (int k = 0; k < m; k++) {
                        cout << Need[i][k];
                        if (k < m - 1) {
                            cout << "��";
                        }
                    }
                    cout << "]<=Available[";
                    for (int k = 0; k < m; k++) {
                        cout << Available[k];
                        if (k < m - 1) {
                            cout << "��";
                        }
                    }
                    cout << "]���ɹ�����" << endl;

                    for (int k = 0; k < m; k++) {
                        Available[k] += Allocation[i][k];
                    }

                    PrintResourceStatus(n, m);

                    isFinished[i] = true;
                    found = true;
                }
            }
        }
        if (!found) {
            cout << "ϵͳ����ȫ" << endl;
            return;
        }
    }

    cout << "ϵͳ��ȫ����ȫ����Ϊ ��";
    for (int i = 0; i < safeSeq.size(); i++) {
        cout << "P" << safeSeq[i] << " ";
    }
    cout << endl;
}

void GetUserInput(int n, int m) {
    cout << "�����������Դ������A B C��: ";
    for (int i = 0; i < m; i++) {
        cin >> Available[i];
    }

    for (int i = 0; i < n; i++) {
        cout << "��������� P" << i << " �������������A B C��: ";
        for (int j = 0; j < m; j++) {
            cin >> Max[i][j];
        }

        cout << "��������� P" << i << " ���ѷ�����Դ����A B C��: ";
        for (int j = 0; j < m; j++) {
            cin >> Allocation[i][j];
        }
    }
}








int main() {
    int n = 5; // ������
    int m = 3; // ��Դ����
    
    GetUserInput(n, m); // �û�������Դ�ͽ�����Ϣ
    NeedMatrix(Allocation, Max, n, m);
    AvailableMatrix(); // �����ʼ������Դ

    cout << "��ʼ״̬��" << endl;
    PrintResourceStatus(n, m);

    SafeSequence(Need, Available, n, m);

    return 0;
}
