#include "iostream"

void PrintInjected() {
    std::cout << "div {\n"
                 "    border: 1px solid black;\n"
                 "}" << std::endl;

    std::cout << "<!DOCTYPE html>\n"
                 "<html>\n"
                 "<body>\n"
                 "\n"
                 "<h2>Size Attributes</h2>\n"
                 "<p>Images in HTML have a set of size attributes, which specifies the width and height of the image:</p>\n"
                 "\n"
                 "<img src=\"img_girl.jpg\"  height=\"600\">\n"
                 "\n"
                 "</body>\n"
                 "</html>" << std::endl;

    const char *main_file = "file_\\d\\d.cc{2}";
}

