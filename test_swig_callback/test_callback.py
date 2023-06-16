import my_lib
import time
class pyResponder(my_lib.my_api_responder):
    def __init__(self):
        my_lib.my_api_responder.__init__(self)
    def on_query_order_books(self, order_id, symbol, qty, price):
        print('on_query_order_books')
        print('order_id:', order_id)
        print('symbol:', symbol)
        print('qty:', qty)
        print('price:', price)
        print('--------------')
    def on_sub_marketdata_rsp(self, symbol, result):
        print('on_sub_marketdata_rsp:', symbol, result)
        print('--------------')
    
if __name__ == '__main__':
    rsp=pyResponder()
    api=my_lib.my_api_requester(rsp)
    api.sub_marketdata("a2305")
    api.query_order_books("m2305");
    api.open()
    input('press enter to exit\n')
    api.close()