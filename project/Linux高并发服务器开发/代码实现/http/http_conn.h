#ifndef HTTPCONNECTION_H
#define HTTPCONNECTION_H

#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/epoll.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <assert.h>
#include <sys/stat.h>
#include <string.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <stdarg.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/uio.h>
#include <map>

#include "../lock/locker.h"
#include "../CGImysql/sql_connection_pool.h"
#include "../timer/lst_timer.h"
#include "../log/log.h"

// http�ඨ��
class http_conn{
public:
    // ���ö�ȡ�ļ�������m_real_file��С
    static const int FILENAME_LEN=200;
    // ���ö�������m_read_buf��С
    static const int READ_BUFFER_SIZE=2048;
    // ����д������m_write_buf��С
    static const int WRITE_BUFFER_SIZE=1024;
    // ���ĵ����󷽷�������Ŀֻ�õ�GET��POST
    enum METHOD{
        GET=0,
        POST,
        HEAD,
        PUT,
        DELETE,
        TRACE,
        OPTIONS,
        CONNECT,
        PATH
    };
    //��״̬����״̬
    enum CHECK_STATE{
        CHECK_STATE_REQUESTLINE=0,
        CHECK_STATE_HEADER,
        CHECK_STATE_CONTENT
    };
    //���Ľ����Ľ��
    enum HTTP_CODE{
        NO_REQUEST,
        GET_REQUEST,
        BAD_REQUEST,
        NO_RESOURCE,
        FORBIDDEN_REQUEST,
        FILE_REQUEST,
        INTERNAL_ERROR,
        CLOSED_CONNECTION
    };
    //��״̬����״̬
    enum LINE_STATUS{
        LINE_OK=0,
        LINE_BAD,
        LINE_OPEN
    };

public:
    http_conn() {}
    ~http_conn() {}

public:
    // ��ʼ���׽��ֵ�ַ�������ڲ������˽�з���init
    void init(int sockfd, const sockaddr_in &addr, char *, int, int, string user, string passwd, string sqlname);
    // �ر�http����
    void close_conn(bool real_close = true);
    void process();
    // ��ȡ������˷�����ȫ������
    bool read_once();
    // ��Ӧ����д�뺯��
    bool write();
    sockaddr_in *get_address()
    {
        return &m_address;
    }
    // ͬ���̳߳�ʼ�����ݿ��ȡ��
    void initmysql_result(connection_pool *connPool);
    int timer_flag;
    int improv;

private:
    void init();
    // ��m_read_buf��ȡ��������������
    HTTP_CODE process_read();
    // ��m_write_bufд����Ӧ��������
    bool process_write(HTTP_CODE ret);
    // ��״̬�����������е�����������
    HTTP_CODE parse_request_line(char *text);
    // ��״̬�����������е�����ͷ����
    HTTP_CODE parse_headers(char *text);
    // ��״̬�����������е���������
    HTTP_CODE parse_content(char *text);
    // ������Ӧ����
    HTTP_CODE do_request();

    // m_start_line���Ѿ��������ַ�
    // get_line���ڽ�ָ�����ƫ�ƣ�ָ��δ������ַ�
    char *get_line() { 
        return m_read_buf + m_start_line; 
    };

    // ��״̬����ȡһ�У������������ĵ���һ����
    LINE_STATUS parse_line();

    void unmap();

    // ������Ӧ���ĸ�ʽ�����ɶ�Ӧ8�����֣����º�������do_request����
    bool add_response(const char *format, ...);
    bool add_content(const char *content);
    bool add_status_line(int status, const char *title);
    bool add_headers(int content_length);
    bool add_content_type();
    bool add_content_length(int content_length);
    bool add_linger();
    bool add_blank_line();

public:
    static int m_epollfd;
    static int m_user_count;
    MYSQL *mysql;
    int m_state;  

private:
    int m_sockfd;
    sockaddr_in m_address;

    // �洢��ȡ������������
    char m_read_buf[READ_BUFFER_SIZE];
    // ��������m_read_buf�����ݵ����һ���ֽڵ���һ��λ��
    long m_read_idx;
    // m_read_buf��ȡ��λ��m_checked_idx
    long m_checked_idx;
    // m_read_buf���Ѿ��������ַ�����
    int m_start_line;

    // �洢��������Ӧ��������
    char m_write_buf[WRITE_BUFFER_SIZE];
    // ָʾbuffer�еĳ���
    int m_write_idx;

    // ��״̬����״̬
    CHECK_STATE m_check_state;
    // ���󷽷�
    METHOD m_method;

    // ����Ϊ�����������ж�Ӧ��6������
    // �洢��ȡ�ļ�������
    char m_real_file[FILENAME_LEN];
    char *m_url;
    char *m_version;
    char *m_host;
    long m_content_length;
    bool m_linger;


    char *m_file_address;  // ��ȡ�������ϵ��ļ���ַ
    struct stat m_file_stat;
    struct iovec m_iv[2];  // io��������iovec
    int m_iv_count;
    int cgi;        // �Ƿ����õ�POST
    char *m_string;   // �洢����ͷ����
    int bytes_to_send;  // ʣ�෢���ֽ���
    int bytes_have_send;  // �ѷ����ֽ���
    char *doc_root;

    map<string, string> m_users;
    int m_TRIGMode;  // LT:0 or ET:1 ��ȡ����
    int m_close_log;

    char sql_user[100];
    char sql_passwd[100];
    char sql_name[100];
};

#endif