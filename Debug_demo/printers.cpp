//Check custom LLDB printers
//(lldb) type summary add --python-script "height = valobj.GetChildMemberWithName('height').GetValueAsUnsigned(0);width = valobj.GetChildMemberWithName('width').GetValueAsUnsigned(0); return 'Area: %d' % (height*width)" Rectangle
//(lldb) frame variable

//Another sample: QString viewer
//Add to ~/.lldbinit:
//command script import ~/.lldb/qstring.py
//

class Rectangle
{
private:
    int height;
    int width;
public:
    Rectangle() : height(3), width(5) {}
    Rectangle(int H) : height(H), width(H*2-1) {}
    Rectangle(int H, int W) : height(H), width(W) {}

    int GetHeight() { return height; }
    int GetWidth() { return width; }
};

int main() {
    Rectangle rect;
    Rectangle rect2(7);
    Rectangle rect3(11, 13);

    return 0;
}