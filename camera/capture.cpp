#include <stdlib.h>
#include <unistd.h>
#include <chrono>
#include <ctime>
#include <wait.h>
#include <iostream>
#include <string.h>
using namespace std;

int main(int argc, char const *argv[])
{
	auto t_start = chrono::high_resolution_clock::now();

	for(int i = 1; i <= 10; i++){
		if(fork() == 0){
			char buf[10];
			sprintf(buf, "%d.jpg", i);
				execlp("raspistill", "raspistill", "-o", buf, "-t", "500", "-q", "85", "-md", "2", "-mm", "average", "-ex", "auto","-w", "92", "-h", "112", NULL);
			exit(0);
		}
		wait(NULL);
	}
		/*
		if(fork() == 0){
				execlp("raspistill", "raspistill", "-o", "imageSpot.jpg", "-t", "500", "-q", "85", "-md", "2", "-mm", "spot", "-ex", "auto", NULL);
			exit(0);
		}
		wait(NULL);
		if(fork() == 0){
				execlp("raspistill", "raspistill", "-o", "imageBacklit.jpg", "-t", "500", "-q", "85", "-md", "2", "-mm", "backlit", "-ex", "auto", NULL);
			exit(0);
		}
		wait(NULL);
		if(fork() == 0){
				execlp("raspistill", "raspistill", "-o", "imageMatrix.jpg", "-t", "500", "-q", "85", "-md", "2", "-mm", "matrix", "-ex", "auto", NULL);
			exit(0);
		}*/
	//}

	auto t_end = chrono::high_resolution_clock::now();
	cout << "Chrono: " << chrono::duration<double, milli>(t_end - t_start).count() << " ms" << endl;
	return 0;
}