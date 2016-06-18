#include <iostream>
#include <fstream>

#include <stdlib.h> 
using namespace std;

FILE *f;

int height = 500;
int width = 500;

int main(){
    
    unsigned char bmpfileheader[14] = {'B','M', 0,0,0,0, 0,0, 0,0, 54,0,0,0};
    unsigned char bmpinfoheader[40] = {40,0,0,0, 
                                        height,0,0,0, 
                                        width,0,0,0, 
                                        1,0, 
                                        24,0,
                                        0,0,0,0,
                                        16,0,0,0,
                                        0,0,0,0,
                                        0,0,0,0,
                                        0,0,0,0,
                                        0,0,0,0
                                        };
                                        
                                        
    int data_length = (height * width) * 4;      
    unsigned char data[data_length];
                                        
    int counter = 1;
    
    for (int i = 0; i < data_length; i ++){
        if (counter < 7) {
            data[i] = rand() % 255;
        }
        else {
            data[i] = 0;
            counter++;
        }
        
        if (counter > 7) {
            counter = 0;
        }
        //cout << i << endl;
        
        
    }
                            
    bmpfileheader[2] = sizeof(bmpfileheader) + sizeof(bmpinfoheader) + sizeof(data);
    
    
    f = fopen("img.bmp","wb");
    fwrite(bmpfileheader,1,14,f);
    fwrite(bmpinfoheader,1,40,f);
    fwrite(data,1,sizeof(data), f);

  return 0; 
}