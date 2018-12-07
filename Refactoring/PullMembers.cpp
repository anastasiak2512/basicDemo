// Pull up produceMilk member
// Check related members will be suggested
//

#include <string>
#include <iostream>

namespace Milk {

    enum class MilkType {
        NoMilk,
        SomeMilk,
        TonsMilk
    };

    class Maml {
    public:
        virtual void makeLoudSound() = 0;
    };

    class Person : public Maml {
    protected:
        float weight{};
        MilkType mf;
        std::string name;
    public:
        void sayHello() {
            std::cout << "Hello, " + name + "\n";
        }

        float some_magic_num(float weight) {
            return 0;
        }

        float produceMilk() {
            switch (mf) {
                case MilkType::NoMilk:
                    return 0;
                case MilkType::SomeMilk:
                    return some_magic_num(weight);
                case MilkType::TonsMilk:
                    return some_magic_num(2 * weight);
            }
        }
    };
}  // namespace Milk