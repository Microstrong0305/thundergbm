#ifndef CUDAMACRO_H_
#define CUDAMACRO_H_

#define _DEBUG

#define BLOCK_SIZE 64
#define LARGE_REAL_NUM 2147483647.0

//get global thread id
#define GLOBAL_TID() (blockIdx.y * gridDim.x + blockIdx.x) * blockDim.x + threadIdx.x

//get cuda last error
#ifndef _DEBUG
#define GETERROR(x) ((void)0)
#else
#define GETERROR(x) do {						\
		if(cudaGetLastError() != cudaSuccess) {	\
			printf("cuda error in: %s\n", x);	\
			printf(">>> REACH %s(%s:%d) <<<\n",	\
			       __func__,__FILE__, __LINE__);\
			exit(0);							\
		}										\
	} while (0)
#endif//_DEBUG

#ifndef _DEBUG
#define ECHECKER(value) ((void)0)
#else
#define ECHECKER(value) do{											\
	if(value < 0){													\
		printf("Error in %s(%s:%d)\n", __func__,__FILE__, __LINE__);\
	}																\
}while(0)
#endif//_DEBUG

#ifndef _DEBUG
#define CONCHECKER(condition) ((void)0)
#else
#define CONCHECKER(condition) do{									\
	if((condition) == false){											\
		printf("Error in %s(%s:%d)\n", __func__,__FILE__, __LINE__);\
	}																\
}while(0)
#endif//_DEBUG

#endif /*CUDAMACRO_H_*/
