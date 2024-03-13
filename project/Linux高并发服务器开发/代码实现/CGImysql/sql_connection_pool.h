#ifndef _CONNECTION_POOL_
#define _CONNECTION_POOL_

#include <stdio.h>
#include <list>
#include <mysql/mysql.h>
#include <error.h>
#include <string.h>
#include <iostream>
#include <string>
#include "../lock/locker.h"
#include "../log/log.h"

using namespace std;

class connection_pool{
public:
    MYSQL *GetConnection();   // ��ȡ���ݿ�����
    bool ReleaseConnection(MYSQL *conn);   // �ͷ�����
    int GetFreeConn();   // ��ȡ����
    void DestroyPool();   // ������������

    // ����ģʽ
    static connection_pool *GetInstance();

    void init(string url, string User, string PassWord, string DataBaseName, int Port, int MaxConn, int close_log);

private:
    connection_pool();
    ~connection_pool();

    int m_MaxConn;  //���������
	int m_CurConn;  //��ǰ��ʹ�õ�������
	int m_FreeConn; //��ǰ���е�������
	locker lock;
	list<MYSQL *> connList; //���ӳ�
	sem reserve;

public:
    string m_url;			 //������ַ
	string m_Port;		 //���ݿ�˿ں�
	string m_User;		 //��½���ݿ��û���
	string m_PassWord;	 //��½���ݿ�����
	string m_DatabaseName; //ʹ�����ݿ���
	int m_close_log;	//��־����
};

class connectionRAII{
public:
    connectionRAII(MYSQL **con, connection_pool *connPool);
    ~connectionRAII();

private:
    MYSQL *conRAII;
    connection_pool *poolRAII;
};

#endif