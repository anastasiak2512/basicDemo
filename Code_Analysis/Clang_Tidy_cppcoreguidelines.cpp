// To enable only Google checks in Clang-Tidy
// go to Settings/Preferences | Editor | Inspections | C/C++ | Clang-Tidy
// and provide: -*,google-* in options

void avoid_c_style_cast(char ch, double d, long long lng)
{
    int my_ch = (int)ch;
    int my_d = (int)d;
    int my_lng = (int)lng;
}

namespace my_namespace {
    class My_Class {
    public:
        My_Class(int x) :x(x) {

        }
        My_Class* operator&() {
            return this;
        }
    private:
        int x;
    };
}
