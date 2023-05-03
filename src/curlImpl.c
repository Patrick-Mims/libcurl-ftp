#include <curl/curl.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#include "lc.h"

struct Curl
{
    CURL *curl;
    CURLcode response;
};
