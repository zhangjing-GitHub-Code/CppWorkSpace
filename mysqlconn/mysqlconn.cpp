#include<cstdio>
#include<iostream>
#include<string>
#include<mysql.h>
using namespace std;
MYSQL * mysql;
//typedef cout std::cout;
//typedef cin std::cin;
bool exeSQL(string sql,int show=0)
{
	MYSQL_RES *result;    //指向查询结果的指针
	MYSQL_ROW row;
    //mysql_query()执行成功返回0,执行失败返回非0值。
    if (mysql_query(mysql,sql.c_str()))
    {
        cout<<"Query Error: "<<mysql_error(mysql);
        return false;
    }
    else // 查询成功
    {
		if (show==1){
        result = mysql_store_result(mysql);  //获取结果集
        if (result)  // 返回了结果集
        {
           int  num_fields = mysql_num_fields(result);
           int  num_rows=mysql_num_rows(result);
           for(int i=0;i<num_rows;i++) //输出每一行
            {
                //获取下一行数据
                row=mysql_fetch_row(result);
                if(!row) break;
                for(int j=0;j<num_fields;j++)  //输出每一字段
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
	char name[45],sex[6];
	cout << "ID:";
	cin >> id;
	cout << "name:";
	cin >> name;
	cout << "sex(in chinese):";
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
	else printf("已取消\n");
}
void funcmod(){
	;
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
		printf("操作(1:添加,2:修改,3:删除,0:退出): ");
		scanf("%d",&opt);
		switch(opt){
			case 1:
			  funcadd();
			  printf("now:\nID\tname\tsex\n");
			  exeSQL("select * from user;",1);
			  break;
			case 2:
			  funcmod();
			  break;
			case 3:
			  funcdel();
			  break;
			case 0:
			  break;
			default:
			  printf("操作无效!\n");
			  break;
		}
	}
	mysql_close(mysql);
	return 0;
}
