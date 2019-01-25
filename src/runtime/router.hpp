#ifndef FROSTMOURNE_ROUTER_HPP
#define FROSTMOURNE_ROUTER_HPP
//NOTE: мотивация вот в чем void some(){ int kekich = some2(); bool flag = false; if(flag){ std::cout << kekich << std::endl; } }
//Следущая моливация int var1 = kek(3); ……. int var2 = kek(3);
//Следующая мотивация int var1 = kekich(3,5); int var2 = kekich(10,16); может оказаться что выполняя отложенно мы сможем разрешить обе переменные kekich(int,int){ return 2; }
//Или как то генерализировать вычисления тоесть посчитать одновременно и для var1 и для var2 даже если есть вычисления может оказаться что дешевле считать вместе
//Еще мотивация factorial(3) factorial(4). Тоесть рекурсивные функции так убивать можно

#include "../ast/ast.hpp"

//Tracking sheduler. Отвечате за то сколько мы отслеживаем трассу, трассы...
class tracking_sheduler_t {
    
};
//Обшего времени
//Частно трассового времени

//Manage control flow
class router_t {
    std::vector<ast::func_body_t*> _tracks;
    
public:
    //Next executable operator chunk
    void next_exc(ast::func_body_t& func) noexcept {}

    //Called when variable value depends on call. Ex: int x = 3 + some()
    void lazy_bond() noexcept {}

    void tracks() noexcept {}
};

#endif //FROSTMOURNE_ROUTER_HPP

/*  
int kekich(){
    int cals1 = 42+f1(); 
    int cals = 200+f2();
*/

// Code example

// int k;
// std::cin >> k; //90
// int m=0;
// .....

// while 1000000

// if(k > 1000){ //
//    k = k-1
// }else(k < 100){
//     k = k+3;
//     m = m+2;    
// }

//     k = k+3; 93
//     k = k+3; 96    
//     k = k+3; 99 <-|
//     k = k+3; 102  |
//     k = k-1       |
//     k = k-1       |
//     k = k-1       |  
//     k = k+3; 99 --|
    
//     100000%8