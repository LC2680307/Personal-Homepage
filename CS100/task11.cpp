#include <iostream>
#include <string>
#include<string.h>
#include <vector>
using namespace std;

class ReportParser
{
public:
    int rows;
    int columns;
    vector<vector<string>>table;
    vector<string>test;

    ReportParser(int numStudents, int numProblems){
        rows = numStudents;
        columns = numProblems;
    };
    ~ReportParser(){};
    void readReport(){
        string a;
        for(int i=0;i<rows;i++){
            for(int j=0;j<columns;j++){
                cin >> a;
                test.push_back(a);
            }
            table.push_back(test);
            test.clear();
        }
    }

    void writeStructuredReport(){
        //找出每一列最大单元格
        int* unit;
        memset(unit , 0, sizeof(int)*100);
        for(int j=0;j<columns;j++){
            for(int i=0;i<rows;i++){
                if(table[i][j].length() > unit[j])
                unit[j] = table[i][j].length();
                unit[j]= unit[j] + 2;
            }
        }

        //打印第一行
        cout << '/';
        for(int j=0;j<columns;j++){
            for(int k=0;k<unit[j];k++)
                cout << '-';
        }
        cout << '\\'<<'\n';
    
        //打印中间行
        //打印信息行
        for(int i=0;i<rows;i++){
            if(i!=rows-1){ 
                for(int j=0;j<columns;j++){
                    cout << '|' << ' ';
                    cout << table[i][j];
                    for(int k=0;k<unit[j]-table[i][j].length()-1;k++){
                        cout << ' ';
                    }
                cout << '|' << '\n';
                }
            
            //打印间隔行
                for(int j=0;j<columns;j++){
                    cout << '|';
                    for(int k=0;k<unit[j];k++){
                        cout << '-';
                        }
                }
                cout << '|' << '\n';
            }
            if(i=rows-1){
                //打印最后一行信息行
                for(int j=0;j<columns;j++){
                    cout << '|';
                    cout << table[rows][j];
                    for(int k=0;k<unit[j]-table[rows][j].length()-1;k++){
                        cout << ' ';
                    }
                }
                cout << '|' << '\n';

                //打印最后一行
                cout << '\\';
                for(int j=0;j<columns;j++){
                    for(int k=0;k<unit[j];k++)
                        cout << '-';
                }
                cout << '/';
            }
        }


    }
};
// DO NOT modify the main function
int main()
{
    int n, m;
    std::cin >> n >> m;
    getchar();
    ReportParser a(n, m);
    a.readReport();
    a.writeStructuredReport();
    return 0;
}