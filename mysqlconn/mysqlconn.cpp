#include<cstdio>
#include<iostream>
#include<string>
#include "mysql.h"
//#pragma comment(lib,��libmysql.lib��)
using namespace std;
MYSQL * mysql;
//typedef cout std::cout;
//typedef cin std::cin;
bool exeSQL(string sql,int show=0)
{
	MYSQL_RES *result;    //ָ���ѯ�����ָ��
	MYSQL_ROW row;
    //mysql_query()ִ�гɹ�����0,ִ��ʧ�ܷ��ط�0ֵ��
    if (mysql_query(mysql,sql.c_str()))
    {
        cout<<"Query Error: "<<mysql_error(mysql);
        return false;
    }
    else // ��ѯ�ɹ�
    {
		if (show==1){
        result = mysql_store_result(mysql);  //��ȡ�����
        if (result)  // �����˽����
        {
           int  num_fields = mysql_num_fields(result);
           int  num_rows=mysql_num_rows(result);
           for(int i=0;i<num_rows;i++) //���ÿһ��
            {
                //��ȡ��һ������
                row=mysql_fetch_row(result);
                if(!row) break;
                for(int j=0;j<num_fields;j++)  //���ÿһ�ֶ�
                {
                    cout<<row[j]<<"\t";
                }
                cout<<endl;
            }
        }
        else  // result==NULL
        {
            if(mysql_field_count(mysql) == 0){
                // (it was not a SELECT)
                int num_rows = mysql_affected_rows(mysql);
            }
            else
            {
                cout<<"Get result error: "<<mysql_error(mysql);
                return false;
            }
        }
		}
    }
    return true;
}
void funcadd(){
	string id;
	char name[45],sex[6];//no chinese because can't set encoding in Windows7
	cout << "ID:";
	cin >> id;
	cout << "name:";
	cin >> name;
	cout << "sex(male/famale):";
	cin>>sex;
	string exe;
	exe="insert into `user` values(";
	exe+=id;
	exe+=",'";
	exe+=name;
	exe+="','";
	exe+=sex;
	exe+="');";
	cout << "will execute: "<<exe<<endl<<"confrim?(y/n)";
	string yn;
	cin>>yn;
	if (yn=="y"){
		exeSQL(exe);
	}
	else printf("��ȡ��\n");
}
void funcmod(){
	printf("������Ҫ�޸���Ϣ��ID: ");
	string id;
	cin >> id;
	printf("������Ҫ�޸ĵ���Ϣ��1:����,2:�Ա�: ");
	int opr=0;
	cin >> opr;
	if (opr==1){
		printf("������Ҫ�޸ĵ�����: ");
		string name;
		cin >> name;
		string exec="update user set name='";
		exec+=name;
		exec+="' where id=";
		exec+=id;
		exec+=";";
		exeSQL(exec);
	}else if (opr==2){
		printf("������Ҫ�޸ĵ��Ա�: ");
		string sex;
		cin >> sex;
		string exec="update user set sex='";
		exec+=sex;
		exec+="' where id=";
		exec+=id;
		exec+=";";
		exeSQL(exec);
	}else{
		printf("������Ч����ȡ��\n");
	}
}
void funcdel(){
	;
}
int main(){
	mysql=mysql_init(NULL);
	mysql = mysql_real_connect(mysql, "localhost","root", "root", "family", 0, NULL, 0);
	if (mysql==NULL){
		cout << "Error: " << mysql_error(mysql);
        exit(1);
	}
	printf("ID\tname\t\tsex\n");
	exeSQL("select * from user;",1);
	int opt=1;
	while(opt){
		printf("����(1:���,2:�޸�,3:ɾ��,0:�˳�): ");
		scanf("%d",&opt);
		switch(opt){
			case 1:
			  funcadd();
			  printf("now:\nID\t\tname\tsex\n");
			  exeSQL("select * from user;",1);
			  break;
			case 2:
			  funcmod();
			  printf("now:\nID\t\tname\tsex\n");
			  exeSQL("select * from user;",1);
			  break;
			case 3:
			  funcdel();
			  printf("now:\nID\t\tname\tsex\n");
			  exeSQL("select * from user;",1);
			  break;
			case 0:
			  break;
			default:
			  printf("������Ч!\n");
			  break;
		}
	}
	mysql_close(mysql);
	return 0;
}
