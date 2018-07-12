#include <cstdint>
#include <string>

int Square(int width, int height) {
    return width * height;
}

class Rectangle {
    int width;
    int height;
public:
    Rectangle(int w, int h) : width(w), height(h) {}

    int getWidth() const {
        return width;
    }

    int getHeight() const {
        return height;
    }
};

int CalculateSquareOutsideTheClass(const Rectangle& rect){
    return Square(rect.getHeight(), rect.getWidth());
}




struct User {
    int64_t user_id;
    int64_t company_id;
    std::string user_name;
};

const User* get_User(int64_t company_id, int64_t user_id) {
    return new User{company_id, user_id, "foo"};
}

void call_User(int64_t company_id, int64_t user_id) {
    const User* user = get_User(user_id, company_id);
    //...
}
