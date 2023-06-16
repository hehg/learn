#pragma once

class my_api_responder;
//请求接口
class my_api_requester
{
    public:
    my_api_requester(my_api_responder*callback);
    virtual ~my_api_requester();
    void open();
    void close();
    //模拟订阅行情
    int sub_marketdata(const char* contract);
    //模拟查询订单
    int query_order_books(const char* symbol);
private:
    void run();
    my_api_responder*callback_=nullptr; //回调函数
    bool m_flag=false;
};

//回调接口
class my_api_responder
{
    public:
    virtual ~my_api_responder(){};
    virtual void on_query_order_books(int order_id,const char* symbol,int qty,double price)=0;
    virtual void on_sub_marketdata_rsp(const char*symbol,int ret)=0;
};