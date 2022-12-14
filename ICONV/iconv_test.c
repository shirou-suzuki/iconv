/*
 * iconv_test.c
 *
 *  Created on: 2000/10/29
 *      Author: shiro
 *      iconvsample.c
 *
 * Copyright (C) 2006 Slogical Corporation
 */

#define MYBUFSZ 1024

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iconv.h>

int main (int argc, char **argv) {

        /* 変数定義 */
        iconv_t ic;
        char    str_in[MYBUFSZ+1];
        char    str_out[MYBUFSZ+1];
        char    *ptr_in  = str_in;
        char    *ptr_out = str_out;
        int     ret;
        size_t  mybufsz = (size_t) MYBUFSZ;

        /* 変換元文字列を作成（このソースはEUCで書かれていて、変換元文字列もEUCで作成される）
         */
        strcpy(str_in, "  " );

        /* 文字コード変換処理
         */
        ic = iconv_open("SJIS", "UTF-8");
        if ( ic == ((iconv_t)-1) )
        {
        	printf( "***** iconv_open ERROR ***** \n");
        	return 1;
        }else{
        	printf( "iconv_open SUCCESS!!  \n");
        }
        // シフトJIS変換
        ret = iconv(ic, &ptr_in, &mybufsz, &ptr_out, &mybufsz);
        if ( -1 == ret )
        {
        	printf( "***** iconv DATA CONVERT ERROR *****\n");
        	return 1;
        }
        iconv_close(ic);

        /* 文字コード変換された文字列を出力
         */
        printf("%s\n", str_out);

        return 0;
}
