/**
  * @file       error_demo.c
  * @brief      error实例
  * @author     redoc
  * @version    v1.0
  * @date       2019-04-02
  *
  * @note
  * [2019-04-02] <redoc> (v1.0) 
  * 创建
  *
  * @remark
  */

/* Includes ------------------------------------------------------------------*/
#include "error.h"


void main(void)
{

    while(1)
    {
        error_insert(&error_node_error_1);
        error_insert(&error_node_error_2);
        error_insert(&error_node_error_3);
        delay_ms(2000);
        error_delete(&error_node_error_1);
        error_delete(&error_node_error_2);
        error_delete(&error_node_error_3);
    }
}


void __int_1000ms(void)
{
    error_process();
}

