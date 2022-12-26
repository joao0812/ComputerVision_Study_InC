#include <iostream>
#include <opencv2/opencv.hpp>
#include<opencv2/highgui/highgui.hpp>

using namespace cv; // Faz com que n seja necessário ficar utilizando o préfixo cv:: (cv::Mat image)
// O Arquivos e pastas não devem conter espaços e/ou acentos
int main(int, char**) {
    Mat image_color;
    Mat image_gray;
    image_color = imread("C:\\Users\\joaoe\\Desktop\\Cursos\\YouTube\\VisaoComputacional\\C++\\ShowImage\\assets\\city.jpg");
    image_gray = imread("C:\\Users\\joaoe\\Desktop\\Cursos\\YouTube\\VisaoComputacional\\C++\\ShowImage\\assets\\city.jpg", IMREAD_GRAYSCALE);

    if(!image_color.data)
    {
        printf("No image data \n");
        return -1;
    }

    // O objetivo no for é saltar a cada 10 pixels ao percorrer as linhas e mais 10 pixels ao percorrer as colunas. A cada salto é criado um quadrado amarelo de 5x5 pixels. Desta vez parte da imagem orignal é preservada e podemos ainda observar a ponte por baixo da grade de quadrados amarelos.
    for (int row = 0; row < image_color.rows; row+=5)
    {
        for (int col = 0; col < image_color.cols; col+=5)
        {
            // Esse método retorna os valores em sequêmcia BGR e não RGB
            image_color.at<Vec3b>(row,col)[0] = 0; // B - Azul
            image_color.at<Vec3b>(row,col)[1] = 255; // G - Verde
            image_color.at<Vec3b>(row,col)[2] = 255; // R - Vermelho
        }        
    }
        
    
    namedWindow("Display Color City", WINDOW_AUTOSIZE);
    // namedWindow("Display Gray City", WINDOW_AUTOSIZE);
    imshow("Display Color City", image_color);
    // imshow("Display Gray City", image_gray);
    waitKey(0);
    return 0;
}
