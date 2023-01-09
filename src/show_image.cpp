#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv; // Faz com que n seja necessário ficar utilizando o préfixo cv:: (cv::Mat image)
using namespace std;
// O Arquivos e pastas não devem conter espaços e/ou acentos

void grayScaleImage(Mat image_gray)
{
    namedWindow("Display Gray City", WINDOW_AUTOSIZE);
    imshow("Display Color City", image_gray);
    waitKey(0);
}

void manipulandoPixelColor(Mat image_color)
{
    // O objetivo no for é saltar a cada 10 pixels ao percorrer as linhas e mais 10 pixels ao percorrer as colunas. A cada salto é criado um quadrado amarelo de 5x5 pixels. Desta vez parte da imagem orignal é preservada e podemos ainda observar a ponte por baixo da grade de quadrados amarelos.
    for (int row = 0; row < image_color.rows; row += 5)
    {
        for (int col = 0; col < image_color.cols; col += 5)
        {
            // Esse método retorna os valores em sequêmcia BGR e não RGB
            image_color.at<Vec3b>(row, col)[0] = 0;   // B - Azul
            image_color.at<Vec3b>(row, col)[1] = 255; // G - Verde
            image_color.at<Vec3b>(row, col)[2] = 255; // R - Vermelho
        }
    }
    namedWindow("Display Color City", WINDOW_AUTOSIZE);
    imshow("Display Color City", image_color);
    waitKey(0);
}

void filtroBlurImage(Mat image_color)
{
    // Filtro Blurring - TENTATIVA N DEU MUITO CERTO
    for (int row = 0; row < image_color.rows; row++)
    {
        for (int col = 0; col < image_color.cols; col++)
        {
            // Esse método retorna os valores em sequêmcia BGR e não RGB
            image_color.at<Vec3b>(row, col)[0] = image_color.at<Vec3b>(row, col)[0] / 9; // B - Azul
            image_color.at<Vec3b>(row, col)[1] = image_color.at<Vec3b>(row, col)[1] / 9; // G - Verde
            image_color.at<Vec3b>(row, col)[2] = image_color.at<Vec3b>(row, col)[2] / 9; // R - Vermelho
        }
    }
    namedWindow("Display Color City", WINDOW_AUTOSIZE);
    imshow("Display Color City", image_color);
    waitKey(0);
}

void drawGeometricFormsText(Mat image_color)
{
    // Fatiamente de Imagem, desenhado algumas formas geométricas com algumas funções do OpenCV
    Point p1(100, 50), p2(50, 150);
    Point p3(300, 175), p4(500, 350);
    line(image_color, p1, p2, Scalar(255, 0, 0), 2, LINE_8);
    rectangle(image_color, p3, p4, Scalar(0, 255, 0), 4, LINE_8);
    int X_image = image_color.rows / 2;
    int Y_image = image_color.cols / 2;
    Point center(Y_image, X_image);

    for (int i = 0; i < 250; i += 15)
    {
        circle(image_color, center, i, Scalar(0, 0, 255), 2, LINE_8);
    }

    // Implementando Texto na imagem
    putText(image_color, "OpenCV", Point(10, 25), FONT_HERSHEY_DUPLEX, 0.8, Scalar(255, 255, 255));

    namedWindow("Display Color City", WINDOW_AUTOSIZE);
    imshow("Display Color City", image_color);
    waitKey(0);
}

void cropResizeImage(Mat image_color)
{
    // Cortando a imagem pela técnica de Slicing, fazendo um crop
    Mat crop = image_color(Range(100, 300), Range(200, 400)); // cropped = img[start_row:end_row, start_col:end_col]
    namedWindow("Crop", WINDOW_AUTOSIZE);
    imshow("Crop", crop);

    // Realizando um redimensionamento da imagem
    Mat resized_up;
    Mat resized_down;

    resize(image_color, resized_up, Size(800, 500), INTER_LINEAR); // INTER_LINEAR é uma especificação do cálculo matemático para demimensionar a imagem, existem outras propriedades
    resize(image_color, resized_down, Size(400, 180), INTER_LINEAR);

    // Criando a janela e exibindo a imagem gerada
    namedWindow("Display Color City", WINDOW_AUTOSIZE);
    imshow("Display Color City", image_color);
    imshow("Display Color City Up", resized_up);
    imshow("Display Color City Down", resized_down);
    waitKey(0); // Espera apertar em qualquer tecla para fechar a imagem
}

void flipImage(Mat image_color)
{
    Mat image_color_rotate;
    flip(image_color, image_color_rotate, -1); // 0 - Flip Vertical || 1 - Flip Horizontal || -1 - Flip Horizontal e Vertical

    namedWindow("Display Color City ", WINDOW_AUTOSIZE);
    imshow("Display Color City", image_color);
    imshow("Display Color City Rotate", image_color_rotate);
    waitKey(0);
}

void rotateImage(Mat image_color)
{
    Point2f center((image_color.cols - 1) / 2.0, (image_color.rows - 1) / 2.0);
    // usando getRotationMatrix2D() para se obter a matriz rotação
    Mat matriz_rotate = getRotationMatrix2D(center, 45, 1.0);

    Mat image_color_rotate;
    // Rodatacionando a imagem usando a função warpAffine()
    warpAffine(image_color, image_color_rotate, matriz_rotate, image_color.size());

    namedWindow("Display Color City ", WINDOW_AUTOSIZE);
    imshow("Display Color City", image_color_rotate);
    waitKey(0);
}

void makeMask(Mat image_color)
{
    int X_image = image_color.rows / 2;
    int Y_image = image_color.cols / 2;
    Point center(Y_image, X_image);

    Mat mascara = Mat::zeros(Size(image_color.cols, image_color.rows), CV_8UC1);
    
    // mascara(Range(0, X_image), Range(0, Y_image)) = 255;
    circle(mascara, center, 100, Scalar(255,255,255), 1, LINE_8);
    imshow("mask", mascara);
    
    Mat res;
    bitwise_and(image_color, mascara, res);
    imshow("AND", res);

    // imshow("Mask", mask);

    /* Mat drawing1 = Mat::zeros(Size(400, 200), CV_8UC1);
    Mat drawing2 = Mat::zeros(Size(400, 200), CV_8UC1);

    drawing1(Range(0, drawing1.rows), Range(0, drawing1.cols / 2)) = 255;
    imshow("drawing1", drawing1);
    drawing2(Range(100, 150), Range(150, 350)) = 255;
    imshow("drawing2", drawing2); */

    // bitwise_and(image_color, mask, res);

    /* for (int i = 0; i < 150; i++)
    {
        circle(image_color, center, i, Scalar(0, 0, 255), 2, LINE_8);
    } */

    // namedWindow("Display Color City ", WINDOW_AUTOSIZE);
    /* imshow("Display Color City With Mask", image_color);
    imshow("Display Color City With Mask", res); */
    waitKey(0);
}

int main(int, char **)
{
    Mat image_color;
    Mat image_gray;
    // W:626 || H: 351
    image_color = imread("C:\\Users\\joaoe\\Desktop\\Cursos\\YouTube\\VisaoComputacional\\C++\\ShowImage\\assets\\city.jpg");
    image_gray = imread("C:\\Users\\joaoe\\Desktop\\Cursos\\YouTube\\VisaoComputacional\\C++\\ShowImage\\assets\\city.jpg", IMREAD_GRAYSCALE);

    cout << "Width : " << image_color.cols << endl;
    cout << "Height: " << image_color.rows << endl;

    if (!image_color.data)
    {
        printf("No image data \n");
        return -1;
    }

    // grayScaleImage(image_gray);

    // manipulandoPixelColor(image_color);

    // filtroBlurImage(image_color);

    // drawGeometricFormsText(image_color);

    // cropResizeImage(image_color);

    // flipImage(image_color);

    // rotateImage(image_color);

    makeMask(image_color);

    return 0;
}
