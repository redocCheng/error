/**
  * @file       error.c
  * @brief      error����
  * @author     redoc
  * @version    v1.0
  * @date       2018-07-23
  *
  * @note
  * [2018-07-23] <redoc> (v1.0) 
  * ��ʼ�汾
  *
  * @remark
  */


/* Includes ------------------------------------------------------------------*/
#include "error.h"

/* types ------------------------------------------------------------*/

/* define -----------------------------------------------------------*/
/* variables --------------------------------------------------------*/
static error_node_t* error_handle = NULL;


/* macro ------------------------------------------------------------*/
/* functions --------------------------------------------------------*/



/* ��ѯ�ڵ��Ƿ���� */
int8_t error_exist(error_node_t *s_error_code)
{
    error_node_t* target = error_handle;
    
    while(target) 
    {
        if(target == s_error_code)
        {
            return -1;    //already exist.
        }
        target = target->next;
    }
    
    return 0;
}

/* ����ڵ� */
int8_t error_insert(error_node_t *s_error_code)
{
    if(true == s_error_code->error.var.exist)
    {
        return -1;
    }
    
    if(-1 == error_exist(s_error_code))
    {
        return -1;
    }
    
    s_error_code->next = error_handle;
    error_handle = s_error_code;
    s_error_code->error.var.exist = true;
    
    return 0;
}

/* ɾ���ڵ� */
int8_t error_delete(error_node_t *s_error_code)
{
    if(false == s_error_code->error.var.exist)
    {
        return -1;
    }
    
    if(0 == error_exist(s_error_code))
    {
        return -1;
    }
    
    struct error_node_t** curr;
    
    for(curr = &error_handle; *curr; ) 
    {
        struct error_node_t* entry = *curr;
        if (entry == s_error_code) 
        {
            *curr = entry->next;

        } 
        else
        {
            curr = &entry->next;
        }     
    }
    
    s_error_code->error.var.exist = false;
    s_error_code->error.var.used = false;
    
    return 0;
}

/* �����ڵ� */
void error_process(void)
{
    static error_node_t* target_tr = NULL;
    
    if(target_tr == NULL)
    {
        target_tr = error_handle;
    }
    
    if(target_tr)
    {
        if(false == target_tr->error.var.used)
        {
            //ִֻ�е�һ��
            //error_do_first(target_tr->error.var.id);
            
        #ifdef ERRROR_PRINT
            DEBUG_OUTPUT("error id:%d\r\n",target_tr->error.var.id);
        #endif

            target_tr->error.var.used = true;
        }
        else
        {
            //���ϵش������  
            //error_do(target_tr->error.var.id);
        }

        target_tr = target_tr->next;
    }
}
