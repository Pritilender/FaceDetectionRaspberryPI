/*********************************************
* Detekcija lica i opciono pokretanje skripti
* pomocu Boosted Haar Detect algoritma.
* Isprogramirali i zivote dali:
*   Aleksa Njamb Jovanovic
*   Stefan Golubovic
*   Lazar Tonic
*   Mihajlo Ilijic
* Godine 2016. prema OpenCV dokumentaciji
*  za Haar Cascade Classifier za potrebe
*  ArhiMedia grupe
* Kontakt mejl: m.ilijic@elfak.rs
*********************************************/

#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

#include <iostream>
#include <pthread.h>
#include <wait.h>
#include <unistd.h>
#include <signal.h>

using namespace std;
using namespace cv;

/*******************************************
* Struktura ulaznog argumenta funkcije niti
*  frame je slika koja se obradjuje
*  isFirst je promenljiva koja odredjuje broj
*          detektora koji obradjuje sliku
*  isFace je promenljiva na osnovu koje se
*         odredjuje da li je lice nadjeno
*         ili ne
********************************************/
struct ThreadInput{
	Mat frame;
	bool isFirst;
	bool isFace;
};
// Definisanje globalnih promenljivih
//static CascadeClassifier eye;
static CascadeClassifier face1;
static CascadeClassifier face2;
bool detektovano = false;

void* detectAndDisplay(void*);

/********************************
* Funkcija koja poziva gasenje
* skripte koja trenutno radi.
*********************************/
void coolScriptAlarm(int sig){
	detektovano = false;
//    cout << "Alarmiran!" << endl;
   if(!fork()){
	execl("/root/killScript.sh", "/root/killScript.sh", NULL);
        //execl("/home/pi/skripte/coolscript", "/home/pi/skripte/coolscript", "0", NULL);
	//cout << "nema lica vec 10 sekundi" << endl;
	//execl("screen", "screen", "-X", "-S", "Tastatura", "stuff", "\"^C\"", NULL);
	//execl("killall", "killall", "screen", NULL);
       exit(0);
   }

   wait(NULL);
}

int main(void)
{
    Mat frame;

    struct ThreadInput arg1, arg2;

    /* registrovanje alarma za gasenje skripte
     * alarm se pali na svakih 10 sekundi ukoliko
     * lice nije pronadjeno */
    signal(SIGALRM, coolScriptAlarm);

    /* Ucitavanje detektora lica
     * Koriste se 2 detektora paralelno */
    if(!face1.load("/home/pi/haar/lice1.xml")){
    	cout << "Greska prilikom ucitavanja odredjivaca lica!" << endl;
    	exit(1);
    }
    if(!face2.load("/home/pi/haar/lice2.xml")){
    	cout << "Greska prilikom ucitavanja odredjivaca lica!" << endl;
    	exit(1);
    }

    /* Ucitavanje detektora ociju
     * Ukljuciti samo ako je neophodno
     * Prepoznavanje samo lica ubrzava rad sistema */
    // if(!eye.load("/home/pi/haar/naocare.xml")){
    // 	cout << "Greska prilikom ucitavanja odredjivaca lica!" << endl;
    // 	exit(1);
    // }

    // Priprema ulaznih argumenata
    arg1.isFirst = true;
    arg2.isFirst = false;

    while(true){
        // Pokretanje procesa za slikanje
        if(fork() == 0){
    	    execl("/home/pi/camera/Camera", "/home/pi/camera/Camera", "/home/pi/haar/image.jpg", NULL);
    	    exit(0);
    	}

    	wait(NULL);

        // Glavna logika detektovanja
    	frame = imread("/home/pi/haar/image.jpg", CV_LOAD_IMAGE_COLOR);
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
            alarm(10);
	    if(!detektovano && fork() == 0){
                execl("/home/pi/skripte/startScript", "/home/pi/skripte/startScript", NULL);
	       //	cout << "Evo lica!" << endl;
                exit(0);
            }
	    detektovano = true;
            // cout << "Helou!" << endl;
            //wait(NULL);
        } else {
            //cout << "Nema lica. (Verovatno nije detekotvano 2 ili vise oka)" << endl;
        }
    }

    return 0;
}

/***********************************
* Funkcija niti koja obradjuje lice
************************************/
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

    if(faces.size() > 0){
        ((struct ThreadInput*)arg)->isFace = true;
    }

    //cout << "Broj lica: " << faces.size() << endl;
    //Detekcija ociju
    // for(int i = 0; i < faces.size(); i++)
    // {
    // 	// iscrtavanje kruga oko lica
    //     /*Point center( faces[i].x + faces[i].width/2, faces[i].y + faces[i].height/2 );
    //     ellipse( frame_tmp, center, Size( faces[i].width/2, faces[i].height/2), 0, 0, 360, Scalar( 255, 0, 255 ), 4, 8, 0 );*/

    //     Mat faceROI = frame_gray(faces[i]);
    //     std::vector<Rect> eyes;

    //     // Detektovanje ociju; Size-ovi mogu da se menjaju!
    //     eye.detectMultiScale(faceROI, eyes, 1.1, 2, 0 |CASCADE_SCALE_IMAGE, Size(50, 50), Size(500, 500));

    //     //cout << "Broj ociju: " << eyes.size() << endl;
    //     //iscrtavanje ociju
    //     /*for(int j = 0; j < eyes.size(); j++ )
    //     {
    //         Point eye_center( faces[i].x + eyes[j].x + eyes[j].width/2, faces[i].y + eyes[j].y + eyes[j].height/2 );
    //         int radius = cvRound( (eyes[j].width + eyes[j].height)*0.25 );
    //         circle( frame_tmp, eye_center, radius, Scalar( 255, 0, 0 ), 4, 8, 0 );
    //         if (j == 1){
    //         	break;
    //         }
    //     }*/
    //     if(eyes.size() >= 2){
    //     	((struct ThreadInput*)arg)->isFace = true;
    //     	//cout << "Jeste lice! " << input.face << endl;
    //     }
    // }

    //sta je gde detektovalo
  	//imwrite(inpface + eye + ".jpg", frame_tmp);

}
