/*
* Cedarx framework.
* Copyright (c) 2008-2015 Allwinner Technology Co. Ltd.
* Copyright (c) 2014 BZ Chen <bzchen@allwinnertech.com>
*
* This file is part of Cedarx.
*
* Cedarx is free software; you can redistribute it and/or
* modify it under the terms of the GNU Lesser General Public
* License as published by the Free Software Foundation; either
* version 2.1 of the License, or (at your option) any later version.
*
* This program is distributed "as is" WITHOUT ANY WARRANTY of any
* kind, whether express or implied; without even the implied warranty
* of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU Lesser General Public License for more details.
*/
#ifndef LOG_H
#define LOG_H


#ifndef LOG_TAG
#define LOG_TAG "awplayer"
#endif

#include <stdio.h>
#include <string.h>

#define LOG_LEVEL_ERROR     "error  "
#define LOG_LEVEL_WARNING   "warning"
#define LOG_LEVEL_INFO      "info   "
#define LOG_LEVEL_VERBOSE   "verbose"
#define LOG_LEVEL_DEBUG     "debug  "
    
#define AWLOG(level, fmt, arg...)  \
	printf("%s: %s <%s:%u>: "fmt"\n", level, LOG_TAG, __FILE__, __LINE__, ##arg)

#define loge(fmt, arg...) \
    do { \
        AWLOG(LOG_LEVEL_ERROR, "\033[40;31m"fmt"\033[0m", ##arg) ; \
    } while (0)
    
#define logw(fmt, arg...) AWLOG(LOG_LEVEL_WARNING, fmt, ##arg)
#define logi(fmt, arg...) AWLOG(LOG_LEVEL_INFO, fmt, ##arg)
#define logd(fmt, arg...) AWLOG(LOG_LEVEL_DEBUG, fmt, ##arg)
#define logv(fmt, arg...) AWLOG(LOG_LEVEL_VERBOSE, fmt, ##arg)

//#define CEDARX_UNUSE(param) (void)param

#endif

