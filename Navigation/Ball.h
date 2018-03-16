//- Go to Class (Ctrl+N on Windows/Linux, Cmd+O on macOS)
//- Go to Symbol (Ctrl+Shift+Alt+N on Windows/Linux, Alt+Cmd+O on macOS)
//- Go to File (Ctrl+Shift+N on Windows/Linux, Shift+Cmd+O on macOS)

class Ball {
private:
    int diameter;
};

class colorBall : public Ball {
private:
    int color;
public:
    void colorBallCall() { }
};

class metaBall {
private:
    int diameter;
};