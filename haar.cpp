#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

#include <iostream>
#include <pthread.h>
#include <wait.h>
#include <unistd.h>

using namespace std;
using namespace cv;

struct ThreadInput{
	Mat frame;
	bool isFirst;
	bool isFace;
};
static CascadeClassifier eye;
static CascadeClassifier face1;
static CascadeClassifier face2;

void* detectAndDisplay(void*);

int main(void)
{
    Mat frame;

    struct ThreadInput arg1, arg2;

    if(!face1.load("lice1.xml")){
    	cout << "Greska prilikom ucitavanja odredjivaca lica!" << endl;
    	exit(1); 
    }
    if(!face2.load("lice2.xml")){
    	cout << "Greska prilikom ucitavanja odredjivaca lica!" << endl;
    	exit(1);
    }
    if(!eye.load("naocare.xml")){
    	cout << "Greska prilikom ucitavanja odredjivaca lica!" << endl;
    	exit(1);
    }
    arg1.isFirst = true;
    arg2.isFirst = false;

    while(true){
        if(fork() == 0){
    		execl("/home/pi/camera/Camera", "/home/pi/camera/Camera", "/home/pi/haar/image.jpg", NULL);
    		exit(0);
    	}

    	wait(NULL);

    	frame = imread("image.jpg", CV_LOAD_IMAGE_COLOR);
	    frame.copyTo(arg1.frame);
    	frame.copyTo(arg2.frame);
    	arg1.isFace = arg2.isFace = false;
    	
        if(!frame.data){
    		cout << "Greska prilikom ucitavanja slike!" << endl;
	    }

	    pthread_t face_detection_thread[2];

	    pthread_create(&face_detection_thread[0], NULL, detectAndDisplay, (void*)&arg1);
	    pthread_create(&face_detection_thread[1], NULL, detectAndDisplay, (void*)&arg2);

		pthread_join(face_detection_thread[0], NULL);
	    pthread_join(face_detection_thread[1], NULL);

	    if(arg1.isFace || arg2.isFace){
	    	cout << "Lice nadjeno!" << endl;
	    } else {
	    	cout << "Nema lica. (Verovatno nije detekotvano 2 ili vise oka)" << endl;
	    }
	}

    return 0;
}

void* detectAndDisplay(void* arg)
{
    std::vector<Rect> faces;
    Mat frame_gray;
    struct ThreadInput input = *((struct ThreadInput*)arg);
    cvtColor(input.frame, frame_gray, COLOR_BGR2GRAY);
    equalizeHist(frame_gray, frame_gray);

    // Ocitaj lice
    if(input.isFirst){
    	face1.detectMultiScale(frame_gray, faces, 1.1, 2, 0|CASCADE_SCALE_IMAGE, Size(500, 500));
    } else {
    	face2.detectMultiScale(frame_gray, faces, 1.1, 2, 0|CASCADE_SCALE_IMAGE, Size(500, 500));
    }
    

    //cout << "Broj lica: " << faces.size() << endl;

    for(int i = 0; i < faces.size(); i++)
    {
    	// iscrtavanje kruga oko lica
        /*Point center( faces[i].x + faces[i].width/2, faces[i].y + faces[i].height/2 );
        ellipse( frame_tmp, center, Size( faces[i].width/2, faces[i].height/2), 0, 0, 360, Scalar( 255, 0, 255 ), 4, 8, 0 );*/

        Mat faceROI = frame_gray(faces[i]);
        std::vector<Rect> eyes;

        // Detektovanje ociju; Size-ovi mogu da se menjaju!
        eye.detectMultiScale(faceROI, eyes, 1.1, 2, 0 |CASCADE_SCALE_IMAGE, Size(50, 50), Size(500, 500));

        //cout << "Broj ociju: " << eyes.size() << endl;
        //iscrtavanje ociju
        /*for(int j = 0; j < eyes.size(); j++ )
        {
            Point eye_center( faces[i].x + eyes[j].x + eyes[j].width/2, faces[i].y + eyes[j].y + eyes[j].height/2 );
            int radius = cvRound( (eyes[j].width + eyes[j].height)*0.25 );
            circle( frame_tmp, eye_center, radius, Scalar( 255, 0, 0 ), 4, 8, 0 );
            if (j == 1){
            	break;
            }
        }*/
        if(eyes.size() >= 2){
        	((struct ThreadInput*)arg)->isFace = true;
        	//cout << "Jeste lice! " << input.face << endl;
        }
    }

    //sta je gde detektovalo
  	//imwrite(inpface + eye + ".jpg", frame_tmp);

}
