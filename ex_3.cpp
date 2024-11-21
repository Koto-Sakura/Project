#include <iostream>
#include <vector>

using namespace std;

int Available[3]; // 可用资源A、B、C的总数量
int Max[5][3];    // 五个进程的最大需求量
int Allocation[5][3]; // 五个进程的已分配资源
int Need[5][3];   // 还需要的资源量

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
            Available[j] -= Allocation[i][j]; // 计算已分配资源量
        }
    }
}

void PrintResourceStatus(int n, int m) {
    cout << "当前资源分配状态：" << endl;
    cout << "进程\t分配\t最大\t需要\t可用" << endl;

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
    cout << "开始检查安全性" << endl;
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
                        cout << "进程P" << i << "，Request[";
                        for (int k = 0; k < m; k++) {
                            cout << Need[i][k];
                            if (k < m - 1) {
                                cout << "，";
                            }
                        }
                        cout << "]>Available[";
                        for (int k = 0; k < m; k++) {
                            cout << Available[k];
                            if (k < m - 1) {
                                cout << "，";
                            }
                        }
                        cout << "]，分配失败" << endl;
                        break;
                    }
                }
                if (j == m) {
                    safeSeq.push_back(i);
                    safeCount++;

                    cout << "进程P" << i << "，Request[";
                    for (int k = 0; k < m; k++) {
                        cout << Need[i][k];
                        if (k < m - 1) {
                            cout << "，";
                        }
                    }
                    cout << "]<=Available[";
                    for (int k = 0; k < m; k++) {
                        cout << Available[k];
                        if (k < m - 1) {
                            cout << "，";
                        }
                    }
                    cout << "]，成功分配" << endl;

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
            cout << "系统不安全" << endl;
            return;
        }
    }

    cout << "系统安全，安全序列为 ：";
    for (int i = 0; i < safeSeq.size(); i++) {
        cout << "P" << safeSeq[i] << " ";
    }
    cout << endl;
}

void GetUserInput(int n, int m) {
    cout << "请输入可用资源数量（A B C）: ";
    for (int i = 0; i < m; i++) {
        cin >> Available[i];
    }

    for (int i = 0; i < n; i++) {
        cout << "请输入进程 P" << i << " 的最大需求量（A B C）: ";
        for (int j = 0; j < m; j++) {
            cin >> Max[i][j];
        }

        cout << "请输入进程 P" << i << " 的已分配资源量（A B C）: ";
        for (int j = 0; j < m; j++) {
            cin >> Allocation[i][j];
        }
    }
}








int main() {
    int n = 5; // 进程数
    int m = 3; // 资源种类
    
    GetUserInput(n, m); // 用户输入资源和进程信息
    NeedMatrix(Allocation, Max, n, m);
    AvailableMatrix(); // 计算初始可用资源

    cout << "初始状态：" << endl;
    PrintResourceStatus(n, m);

    SafeSequence(Need, Available, n, m);

    return 0;
}
