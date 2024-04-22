#include<iostream>
#include<conio.h>
#include<cstring>
#include<cassert>

class String {
private:
    char* str; // Указатель на C-строку
    size_t size; // Размер строки (без учета завершающего нулевого символа)
public:
    // Конструктор, который принимает C-style строку
    String(const char* c_str)
    {
        size = strlen(c_str);
        str = new char[size + 1];
        strcpy(str, c_str);
    }

    size_t getSize() 
    {
        return size;
    }
    const char* getCString() 
    {
            return str;
    }

    String(size_t count, char ch) 
    {
        size = count;
        str = new char[size + 1];
        for (size_t i = 0; i < size; i++)
            str[i] = ch;
        str[size] = '\0';

    }
    void append(const char* other_str) 
    {
        size_t other_size = strlen(other_str);
        char* res = new char[size + other_size + 1];
        strcpy(res, str);
        strcpy(res + size, other_str);
        delete[] str;
        str = res;
        size += other_size;
    }
    String concat(const String& otherString) {
        char* res = new char[size + otherString.size + 1];
        strcpy(res, str);
        strcpy(res + size, otherString.str);
        String result(res);
        return result;
    }

    int compare(const String& otherString) {
        int i = 0;
        if (str == otherString.str) return 0;
        else
            while (str[i] != NULL || otherString.str[i] != NULL)
            {
                if (str[i] < otherString.str[i]) return -1;
                if (str[i] > otherString.str[i]) return 1;
                i++;
            }
    }
    void toUpper() {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < (int)'z' - (int)'a' + 1; j++)
                if (str[i] == 'a' + j)
                    str[i] = str[i] - 32;
        }
    }

    void toLower() {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < (int)'Z' - (int)'A' + 1; j++)
                if (str[i] == 'A' + j)
                    str[i] = str[i] + 32;
        }
    }


    ~String()
    {
        delete[]  str;
    }
};
void test()
{
    const char* c_str = "Hello, World!";
    String ss(c_str);
    assert(ss.getSize() == 13);
}


int main()
{
    test();
    const char* c_str = "Hello, World!";
    String myString(c_str);

    String myString2(5, 'c');

    const char* initial_str = "Hello ";
    const char* append_str = "World!";

    String myString3(initial_str);
    myString3.append(append_str);

    const char* hello = "Hello ";
    const char* world = "World";

    String helloStr(hello);
    String worldStr(world);
    String combined = helloStr.concat(worldStr);
    std::cout << "String content: " << combined.getCString() << std::endl;
    combined.toLower();
    std::cout << "Uppercase String: " << combined.getCString() << std::endl;
}
