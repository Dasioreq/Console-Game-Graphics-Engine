#include "./convert.hpp"
#include "./vector.hpp"

int main()
{
    Vector2 vec = {6, 3};
    std::cout << (2.5 * vec).print();

    int height, width, channels;

    std::string imgPath = "";
    std::cout << "Input path to image (Accepted formats: .jpeg, .png, .bmp, .hdr, .psd, .tga, .gif, .pic, .pgm, .ppm): ";
    std::cin >> imgPath;
    std::cin.clear();

    uchar* imgBuffer = stbi_load(imgPath.c_str(), &width, &height, &channels, 0);
    while(imgBuffer == NULL)
    {
        std::cout << "Failure reason: " << stbi_failure_reason() << '\n';
        std::cout << "Invalid path, unsupported image format (.jpeg, .png, .bmp, .hdr, .psd, .tga, .gif, .pic, .pgm, .ppm) or corrupted file. Input correct path: ";
        std::cin >> imgPath;
        std::cin.clear();
    
        imgBuffer = stbi_load(imgPath.c_str(), &width, &height, &channels, 0);
    }

    std::cout << convert(imgBuffer, width, height, channels);
}