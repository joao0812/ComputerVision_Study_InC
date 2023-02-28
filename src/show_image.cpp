#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <vector>

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

    Mat mascara = Mat::zeros(image_color.size(), image_color.type());
    Mat res = Mat::zeros(image_color.size(), image_color.type());

    // mascara(Range(0, X_image), Range(0, Y_image)) = 255;
    circle(mascara, center, 150, Scalar(255, 255, 255), -1, 8, 0);

    image_color.copyTo(res, mascara);

    imshow("mask", res);
    waitKey(0);
}

void colorScales(Mat image_color)
{
    Mat src_img = image_color;

    Mat gray_img;
    cvtColor(src_img, gray_img, COLOR_BGR2GRAY);
    imshow("Gray", gray_img);

    Mat hsv_img;
    cvtColor(src_img, hsv_img, COLOR_BGR2HSV);
    imshow("hsv", hsv_img);

    Mat Lab_img;
    cvtColor(src_img, Lab_img, COLOR_BGR2Lab);
    imshow("Lab", Lab_img);

    waitKey(0);
}

void splitGrayColorChannels(Mat image_color)
{
    Mat bgr_array[3];
    split(image_color, bgr_array);

    imshow("Origin", image_color);
    imshow("Blue", bgr_array[0]);
    imshow("Green", bgr_array[1]);
    imshow("Red", bgr_array[2]);

    waitKey(0);
}

void splitColorChannels(Mat image_color)
{
    Mat bgr_array[3];
    Mat res;
    split(image_color, bgr_array);

    Mat z = Mat::zeros(Size(image_color.cols, image_color.rows), CV_8UC1);

    imshow("Origin", image_color);

    vector<Mat> channels_red;
    channels_red.push_back(z);
    channels_red.push_back(z);
    channels_red.push_back(bgr_array[2]);
    merge(channels_red, res);
    imshow("Red", res);

    vector<Mat> channels_green;
    channels_green.push_back(z);
    channels_green.push_back(bgr_array[1]);
    channels_green.push_back(z);
    merge(channels_green, res);
    imshow("Green", res);

    vector<Mat> channels_blue;
    channels_blue.push_back(bgr_array[0]);
    channels_blue.push_back(z);
    channels_blue.push_back(z);
    merge(channels_blue, res);
    imshow("Blue", res);

    waitKey(0);
}

void histogramEqualization(Mat image_color)
{
    MatND histogram;
    int histSize = 256;
    const int *channels_number = {0};
    float channel_range[] = {0.0, 256.0};
    const float *channel_ranges = channel_range;
    int number_bins = histSize;

    calcHist(&image_color, 1, 0, Mat(), histogram, 1, &number_bins, &channel_ranges);

    int hist_w = 626, hist_h = 351;
    int bin_w = cvRound((double)hist_w / histSize);
    Mat histImage(hist_h, hist_w, CV_8UC3, Scalar(0, 0, 0));
    normalize(histogram, histogram, 0, histImage.rows, NORM_MINMAX, -1, Mat());

    for (int i = 1; i < histSize; i++)
    {
        line(histImage, Point(bin_w * (i - 1), hist_h - cvRound(histogram.at<float>(i - 1))), Point(bin_w * (i), hist_h - cvRound(histogram.at<float>(i))), Scalar(255, 0, 0), 2, 8, 0);
    }

    imshow("Src Image", image_color);
    imshow("Hist", histImage);
    waitKey(0);
}

void smoothingImage(Mat image_color)
{
    Mat image_blur;
    Mat image_gaussian_blur;
    Mat image_median_blur;
    Mat image_bilateral_blur;

    blur(image_color, image_blur, Size(5, 5));
    GaussianBlur(image_color, image_gaussian_blur, Size(5, 5), 5.0);
    medianBlur(image_color, image_median_blur, 5);
    bilateralFilter(image_color, image_bilateral_blur, 5, 180, 180);

    imshow("Origin image", image_color);
    imshow("Blured image",image_blur);
    imshow("Gaussian Blur image",image_gaussian_blur);
    imshow("Gaussian Median Blur image",image_median_blur);
    imshow("Gaussian Bilateral Blur image", image_bilateral_blur);
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
    // 1.0
    // grayScaleImage(image_gray);

    // 2.0
    // manipulandoPixelColor(image_color);

    // Test
    // filtroBlurImage(image_color);

    // 3.0
    // drawGeometricFormsText(image_color);

    // 4.0 - 4.2
    // cropResizeImage(image_color);

    // 4.3
    // flipImage(image_color);

    // 4.4
    // rotateImage(image_color);

    // 4.5
    // makeMask(image_color);

    // 5.0
    // colorScales(image_color);

    // 5.1
    // splitGrayColorChannels(image_color);

    // 5.1
    // splitColorChannels(image_color);

    // 6.0
    // histogramEqualization(image_color);

    // 7.0
    smoothingImage(image_color);
    return 0;
}
