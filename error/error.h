/**
  * @file       error.h
  * @brief      errorͷ�ļ�
  * @author     redoc <619675912@qq.com>
  * @version    v1.0
  * @date       2018-07-23
  *
  * @note
  * [2018-07-23] <redoc> v1.0
  * ��ʼ�汾
  *
  * @remark
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __ERROR_H
#define __ERROR_H

/* Includes ------------------------------------------------------------------*/
#include "stdint.h"
#include "stdio.h"
#include "error_define.h"

/* types ------------------------------------------------------------*/

/* ����ṹ�� */
typedef union
{
    uint16_t value;
    
    struct 
    {
        uint8_t     level       :  2;       /*<!  ����ȼ�,��ʱδ������   */
        uint8_t     exist       :  1;       /*<!  �ڵ���ڱ�־            */
        uint8_t     used        :  1;       /*<!  �ڵ��Ƿ񱻴���          */
        uint16_t    id          : 10;       /*<!  �������  ���1024��    */
        uint8_t     reserveed   :  2;       /*<!  Ԥ��                    */
    }var;
    
}error_t;


/* ��������ṹ�� */
typedef struct error_node_t
{
    error_t error;                        /*<!  ����                    */
    struct error_node_t *next;            /*<!  ָ����һ���ڵ��ָ��    */
    
}error_node_t;

/* define -----------------------------------------------------------*/
/*   error pintf debug   */
//#define ERRROR_PRINT

/* variables --------------------------------------------------------*/


/* macro ------------------------------------------------------------*/
/* functions --------------------------------------------------------*/
int8_t error_exist(error_node_t *s_error_code);
int8_t error_insert(error_node_t *s_error_code);
int8_t error_delete(error_node_t *s_error_code);
void error_process(void);

#endif
