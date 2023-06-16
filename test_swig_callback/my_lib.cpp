#include "my_lib.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <thread>
/**
 * 模拟一个与交易系统进行交互的api模块，内部会启动一个线程，
 * 接收请求，收到请求后模拟收到应答数据，进行回调
*/
static bool sim_sub_request=false; //是否收到了订阅请求
static bool sim_qry_request=false; //是否收到了查询请求
static std::thread* 	sim_thread=nullptr;

my_api_requester::my_api_requester(my_api_responder*callback)
 : callback_(callback)
 {

 }
 my_api_requester::~my_api_requester()
 {
    callback_=nullptr;
 }
 void my_api_requester::run()
 {
    /**
     * 线程运行时定时检查sim_sub_request 和sim_qry_request 两个变量
     * 如果有请求到来，则调用callback_ 回调
    */
    while (m_flag)
    {
        if (callback_)
        {
            if (sim_sub_request)
            {
                sim_sub_request = false;
                callback_->on_sub_marketdata_rsp("a2305", 1);
            }
            if (sim_qry_request)
            {
                sim_qry_request = false;
                callback_->on_query_order_books(1, "a2305", 1, 100.25);
            }
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
 }
 void my_api_requester::open()
 {
    printf("start thread\n");
    m_flag = true;
    // 模拟一个线程收到交易所数据
    sim_thread = new std::thread(std::bind(&my_api_requester::run,this));
 }
void my_api_requester::close()
{
    m_flag = false;
    sim_thread->join();
}

 int  my_api_requester::sub_marketdata(const char* contract)
 {
    printf( "sub_marketdata:%s\n",  (char*)contract);
    sim_sub_request=true;
    //callback_->on_sub_marketdata_rsp("a2305", 1);
    return 0;
 }
int  my_api_requester::query_order_books(const char* symbol)
{
    printf( "query_order_books:%s\n",  (char*)symbol);
    sim_qry_request=true;
    return 0;
}
