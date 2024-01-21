
#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include <iostream>
using namespace std;

class Str {
private:
    char* text;
    int size;

public:
    //-------------------КОНСТРУКТОРИ---------------------//

    Str() : text{ nullptr }, size{ 0 } {}
    Str(const char* text) {
        this->size = strlen(text);
        this->text = new char[size + 1];
        for (int i = 0; i < size; i++)
        {
            this->text[i] = text[i];
        }
        this->text[size] = '\0';

    }
    Str(const Str& str1) {
        this->size = strlen(str1.text);
        this->text = new char[size + 1];
        for (int i = 0; i < size; i++)
        {
            this->text[i] = str1.text[i];
        }
        this->text[size] = '\0';

    }

    //-------------------ОПЕРАТОРИ---------------------//

    //виведення <<
    friend std::ostream& operator<<(std::ostream& out, const Str& text) {
        out << text.text;
        return out;
    }

    //введення >>
    friend istream& operator>>(istream& in, Str& str1)
    {

        str1.clear();
        char* tmp = new char[10000];
        in.getline(tmp, 10000);
        str1.pushback(tmp);
        return in;
    }

    //додавання +=
    friend Str& operator+=(Str& s1, const Str& s2)
    {
        int new_size = (s1.size - 1) + (s2.size - 1);
        char* tmp = new char[new_size + 1];

        int j = 0;
        for (int i = 0; i < s1.size - 1; i++)
        {
            tmp[i] = s1.text[i];
        }

        for (int i = s1.size - 1; i < new_size; i++)
        {
            tmp[i] = s2.text[j];
            j++;
        }

        tmp[new_size] = '\0';

        delete[] s1.text;
        s1.text = tmp;
        s1.size = new_size;

        return s1;
    }

    //додавання +
    Str operator+(Str& str1)
    {
        Str result(text);
        result.pushback(str1.text);
        return result;
    }
    Str operator+(const char* c)
    {
        Str result(text);
        result.pushback(c);
        return result;
    }
    friend Str operator+(const char* c, Str& str_right)
    {
        int new_size = strlen(c) + str_right.size;
        char* tmp = new char[new_size + 1];
        int k = 0, m = 0;
        for (int i = 0; i < new_size; i++)
        {
            tmp[i] = c[k];
            k++;

            if (i >= strlen(c))
            {
                tmp[i] = str_right.text[m];
                m++;
            }
        }

        tmp[new_size] = '\0';
        delete[] str_right.text;
        str_right.size = new_size;
        str_right.text = tmp;
        return str_right;
    }

    //порівняння ==
    bool operator==(const Str& str)
    {
        if (size != str.size)
        {
            return false;
        }

        for (int i = 0; i < size; i++)
        {
            if (text[i] != str.text[i])
            {
                return false;
            }

        }

        return true;

    }

    //більше >
    friend bool operator>(const Str& str1, const Str& str2)
    {


        if (str1.text == str2.text)
        {
            return false;
        }

        int sum1 = 0, sum2 = 0; //n1 відповідає за лівий операнд, n2 - за правий
        // пояснюю чому сума, тому що кожне літера - це якесь число і якщо пройтися дебагером то можна це яскраво побачити, тому серед рядків з різними розмірами більшим буде той у кого біля сума його елементів;


        for (int i = 0; i < str1.size; i++)
        {
            sum1 += str1.text[i];
        }
        for (int i = 0; i < str2.size; i++)
        {
            sum2 += str2.text[i];
        }

        if (sum1 <= sum2)
        {
            return false;
        }

        return true;
    }

    //менше <
    friend bool operator<(const Str& str1, const Str& str2)
    {


        if (str1.text == str2.text)
        {
            return false;
        }

        int sum1 = 0, sum2 = 0; //n1 відповідає за лівий операнд, n2 - за правий

        for (int i = 0; i < str1.size; i++)
        {
            sum1 += str1.text[i];
        }
        for (int i = 0; i < str2.size; i++)
        {
            sum2 += str2.text[i];
        }

        if (sum1 >= sum2)
        {
            return false;
        }

        return true;
    }

    //більше >=
    friend bool operator>=(const Str& str1, const Str& str2)
    {


        if (str1.text != str2.text)
        {
            return false;
        }

        int sum1 = 0, sum2 = 0; //n1 відповідає за лівий операнд, n2 - за правий
        // пояснюю чому сума, тому що кожне літера - це якесь число і якщо пройтися дебагером то можна це яскраво побачити, тому серед рядків з різними розмірами більшим буде той у кого біля сума його елементів;


        for (int i = 0; i < str1.size; i++)
        {
            sum1 += str1.text[i];
        }
        for (int i = 0; i < str2.size; i++)
        {
            sum2 += str2.text[i];
        }

        if (sum1 < sum2)
        {
            return false;
        }

        return true;
    }

    //більше <=
    friend bool operator<=(const Str& str1, const Str& str2)
    {


        if (str1.text != str2.text)
        {
            return false;
        }

        int sum1 = 0, sum2 = 0; //n1 відповідає за лівий операнд, n2 - за правий
        // пояснюю чому сума, тому що кожне літера - це якесь число і якщо пройтися дебагером то можна це яскраво побачити, тому серед рядків з різними розмірами більшим буде той у кого біля сума його елементів;


        for (int i = 0; i < str1.size; i++)
        {
            sum1 += str1.text[i];
        }
        for (int i = 0; i < str2.size; i++)
        {
            sum2 += str2.text[i];
        }

        if (sum1 > sum2)
        {
            return false;
        }

        return true;
    }
  
    //-------------------МЕТОДИ---------------------//


    void insert(int index, const char* c) //вставляє рядок : )
    {
        int NEWsize = size + strlen(c);
        int j = 0, k = 0;
        char* tmp = new char[NEWsize + 1];

        for (int i = 0; i < NEWsize; i++)
        {

            if (i == index)
            {
                while (c[k] != '\0')
                {
                    tmp[i] = c[k];
                    k++;
                    i++;
                }
                i--;//якщо не додати то виведеться Kuziv(сміття)HelloSergi;
            }

            else
            {

                tmp[i] = text[j];
                j++;
            }

        }
        tmp[NEWsize] = '\0';


        delete[] text;
        size = NEWsize;
        text = tmp;
    }

    void pop_back()
    {
        if (size > 0)
        {
            int new_size = size - 1;
            char* tmp = new char[new_size + 1];

            for (int i = 0; i < new_size; i++)
            {
                tmp[i] = text[i];
            }

            tmp[new_size] = '\0';

            delete[] text;
            size = new_size;
            text = tmp;
        }
    }

    void pushback(const char c)
    {
        int new_size = size + 1;
        char* tmp = new char[new_size + 1];

        strncpy(tmp, text, size);
        tmp[new_size - 1] = c;
        tmp[new_size] = '\0';

        delete[]text;
        text = tmp;
        size = new_size;

    }

    void pushback(const char* c)
    {
        int new_size = size + strlen(c);
        char* tmp = new char[new_size + 1];

        strncpy(tmp, text, size);
        int k = 0;
        for (int i = size; i < new_size; i++)
        {
            tmp[i] = c[k];
            k++;
        }

        tmp[new_size] = '\0';
        delete[]text;
        text = tmp;
        size = new_size;
    }

    void resize(int new_size)
    {
        char* tmp = new char[new_size + 1];
        strncpy(tmp, text, new_size);
        tmp[new_size] = '\0';

        delete[]text;
        size = new_size;
        text = tmp;

    }

    void resize(int new_size, const char a)
    {

        char* tmp = new char[new_size + 1];
        if (new_size > size)
        {
            strncpy(tmp, text, size);
            for (int i = size; i < new_size; i++)
            {
                tmp[i] = a;
            }
        }
        else { strncpy(tmp, text, new_size); }
        tmp[new_size] = '\0';

        delete[]text;
        size = new_size;
        text = tmp;

    }

    void erase(int index_begin, int count)//int index_begin - з якого елемента починати вирізання, int count - скільки елементів вирізати;
    {
        if (count > size - 1)
        {
            cout << "\Error";
        }
        else
        {
            int new_size = size - count - 1;
            char* tmp = new char[new_size + 1];
            int x = 0;



            for (int i = 0; i < new_size; i++)
            {


                if (i == index_begin)
                {
                    while (x < count)
                    {
                        tmp[i] = text[i + count];
                        x++;
                    }
                }

                else
                {
                    if (x == 0)
                    {
                        tmp[i] = text[i];
                    }

                    else
                    {
                        tmp[i] = text[i + count];
                    }
                }
            }
            tmp[new_size] = '\0';

            delete[]text;
            text = tmp;
            size = new_size;
        }
    }

    void replace(int index_begin, int index_end, char c)
    {
        if (index_begin < 0 || index_begin >= size - 1)
        {
            cout << "\nError" << endl;
        }
        else if (index_end < 0 || index_end >= size - 1 || index_end < index_begin)
        {
            cout << "\nError" << endl;
        }
        else
        {
            for (int i = index_begin; i <= index_end; i++)
            {
                text[i] = c;
            }
        }
    }

    void replace(int index_begin, int index_end, const char* c)
    {
        if (index_begin < 0 || index_begin >= size - 1)
        {
            cout << "\nError" << endl;
        }
        else if (index_end < 0 || index_end >= size || index_end < index_begin)
        {
            cout << "\nError" << endl;
        }

        else
        {
            int k = 0;
            for (int i = index_begin; i <= index_end; i++)
            {
                if (strlen(c) <= index_end)
                {
                    if (k < strlen(c))
                    {
                        text[i] = c[k];
                        k++;
                    }
                    else
                    {
                        text[i] = text[i];
                    }
                }

                else
                {
                    text[i] = c[k];
                    k++;
                }
            }
        }
    }

    void push_front(const char c)
    {
        int new_size = size + 1;
        char* tmp = new char[new_size + 1];

        for (int i = 0; i < new_size; i++)
        {
            tmp[0] = c;
            tmp[i + 1] = text[i];
        }
        tmp[new_size] = '\0';
        delete[] text;
        size = new_size;
        text = tmp;
    }

    void push_front(const char* c)
    {
        int new_size = size + strlen(c);
        char* tmp = new char[new_size + 1];
        int k = 0;
        for (int i = 0; i < new_size; i++)
        {
            tmp[i] = c[i];
            if (i >= strlen(c))
            {
                tmp[i] = text[k];
                k++;
            }

        }
        tmp[new_size] = '\0';
        delete[] text;
        size = new_size;
        text = tmp;
    }

    void clear()
    {
        delete[] text;
        size = 0;
    }


    //-------------------ДЕСТРУКТОР---------------------//

    ~Str()
    {
        clear();
    }
};

int main()
{
    Str k = "ladno";
    k.push_front("jijiji");
    cout << k;
}