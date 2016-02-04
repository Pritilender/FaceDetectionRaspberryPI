#include <stdlib.h>
#include <unistd.h>
//#include <chrono>
//#include <ctime>
#include <wait.h>
//#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	//auto t_start = chrono::high_resolution_clock::now();

	if(fork() == 0){
		char* outp = argv[1];
		char jpgQuality[] = "100";
		char mode[] = "2";
		char metering[] = "average";
		char exposition[] = "auto";
		char width[] = "2592";
		char height[] = "1944";
		char rotation[] = "270";
		char timeout[] = "500";
		execlp("raspistill", "raspistill", "-o", outp, /*"-q", jpgQuality, "-md", mode, "-mm", metering, "-ex", exposition, */"-w", width, "-h", height, "-rot", rotation, "-t", timeout, NULL);
		exit(0);
	}
	wait(NULL);

	//auto t_end = chrono::high_resolution_clock::now();
	//cout << "Chrono: " << chrono::duration<double, milli>(t_end - t_start).count() << " ms" << endl;
	return 0;
}
