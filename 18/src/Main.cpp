#include <opencv2/opencv.hpp>
#include <fstream>

void convert_to_ascii(const cv::Mat& a_image, int a_width, int a_height) 
{
    // Calculate the scaling factor for each dimension
    int width_scale{ a_image.cols / a_width };
    int height_scale{ a_image.rows / a_height };

    // Define a string of ASCII characters from most to least intense
    const std::string ascii_chars{ "  .:;-=+*?!&$%#@" };

    std::ofstream out{ "Ascii.txt" };

    // Iterate over each block of pixels
    for (int y = 0; y < a_height; ++y) 
    {
        for (int x = 0; x < a_width; ++x) 
        {
            // Extract the region of interest (ROI) that represents a block of pixels
            // x * width_scale, y * height_scale is the top left corner of the ROI
            // width_scale and height_scale are the width and height of the ROI
            cv::Rect roi(x * width_scale, y * height_scale, width_scale, height_scale);
            cv::Mat block{ a_image(roi) };

            // Calculate the average intensity of the block
            // This works because the image is in greyscale
            cv::Scalar mean_color = mean(block);
            // The greyscale intensity is found in the first channel
            int grey_value = mean_color[0];

            // Print the ASCII character based on intensity
            out << ascii_chars[static_cast<int>((grey_value / 255.0) * (ascii_chars.size() - 1))];
        }
        out << std::endl;
    }
    out.close();
}

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " <image path>" << std::endl;
        return -1;
    }

    // Load an image from the specified path
    cv::Mat image = cv::imread(argv[1]);

    if (image.empty()) 
    {
        std::cerr << "Error: Could not read the image." << std::endl;
        return -1;
    }

    // Resize the image to a reasonable size
    int target_width{ 80 };
    int target_height{ 40 };

    // Resize the image to the target dimensions
    cv::resize(image, image, cv::Size(target_width, target_height));

    // Convert the image to graywidth_scale
    cv::cvtColor(image, image, cv::COLOR_BGR2GRAY);

    // Convert the image to ASCII art
    convert_to_ascii(image, target_width, target_height);

    // Success message
    std::cout << "ASCII art saved successfully.\n";

    return 0;
}
