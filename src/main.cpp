#include <iostream>

class Nothing {
   private:
    std::string output = "Nothing so default.";

   public:
    void printOutput() { std::cout << output << std::endl; }
};

class Any {
   private:
    std::string output;

   public:
    explicit Any(const std::string& out) : output(out) {}
    void printOutput() { std::cout << output << std::endl; }
};

class Default {
   private:
    std::string output = "Default.";

   public:
    Default() = default;
    void printOutput() { std::cout << output << std::endl; }
};

class Destructor {
   private:
    std::string output = "Destructor.";

   public:
    ~Destructor() { printOutput(); }
    void printOutput() { std::cout << output << std::endl; }
};

class CopyConstructor {
   private:
    std::string output = "Copy Constructor.";

   public:
    CopyConstructor(const CopyConstructor&) {}
    void printOutput() { std::cout << output << std::endl; }
};

class CopyAssignment {
   private:
    std::string output = "Copy Assignment.";

   public:
    CopyAssignment& operator=(const CopyAssignment&) = default;
    void printOutput() { std::cout << output << std::endl; }
};

class MoveConstructor {
   private:
    std::string output = "Move Constructor.";

   public:
    MoveConstructor(MoveConstructor&&) = default;
    void printOutput() { std::cout << output << std::endl; }
};

class MoveAssignment {
   private:
    std::string output = "Move Assignment.";

   public:
    MoveAssignment& operator=(MoveAssignment&&) = default;
    void printOutput() { std::cout << output << std::endl; }
};

int main() {
    Nothing n;
    n.printOutput();

    Any a("any");
    a.printOutput();
    // Any b;  doesn't compile

    Default def;
    def.printOutput();

    Destructor des;
    des.~Destructor();

    // CopyConstructor copyCon1; gives error
}