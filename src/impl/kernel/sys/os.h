#pragma once

#define OS "BoboOS"
#define OSVER "0.0.1"
#define SUCCESS 0
#define ERROR -1

#define STATUS_OK 0
#define STATUS_BUSY 1
#define STATUS_FAIL 2
#define STATUS_NOT_READY 3

#define STATUS_OK_STR "STATUS : OK"
#define STATUS_BUSY_STR "STATUS: BUSY"
#define STATUS_FAIL_STR "STATUS: FAIL"
#define STATUS_NOT_READY_STR "STATUS: NOT READY"

#define NULL_PTR ((void *)0)        
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0])) 
#define BIT(n) (1U << (n))         
#define MAX(a, b) ((a) > (b) ? (a) : (b)) 
#define MIN(a, b) ((a) < (b) ? (a) : (b)) 
#define CLAMP(x, low, high) (MAX(low, MIN(x, high))) 
#define SWAP(x, y) do { typeof(x) temp = (x); (x) = (y); (y) = temp; } while (0) 