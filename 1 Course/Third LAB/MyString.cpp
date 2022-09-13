#include "MyString.h"

//Конструкторы
MyString::MyString() {
    len = 0;
    string = 0;
}

MyString::MyString(char *_string) {
    if(_string != 0) {
        len = StrLen(_string);
        string = new char[len + 1];
        for(int i = 0; i < len; i++ ) {
            string[i] = _string[i];
        }
        string[len] = '\0';
    }
}

MyString::MyString(int _len) {
    len = _len;
    string = new char[len + 1];
    for(int i = 0; i < len; i++) {
        string[i] = ' ';
    }
    string[len] = '\0';
}

MyString::MyString(MyString& obj) {
    len = obj.len;
    string = new char[len + 1];
    for (int i = 0; i < len + 1; i++) {
        string[i] = obj.string[i];
    }
}

MyString::~MyString() {
    if(string != 0) {
        delete [] string;
    }
    string = 0;
}
//Методы

int MyString::GetLen() {
    return len;
}

char MyString::GetChar(int index) {
    return string[index];
}

int MyString::StrLen(char *string) {
    if(string == 0)
        return -1;
    int i = 0;
    while(string[i] != '\0')
        i++;
    return i;
}


void MyString::SetStr(int _len, char *_string) {
    len = _len;
    delete [] string;
    string = new char[len + 1];
    for(int i = 0; i < len; i ++) {
        string[i] = _string[i];
    }
    string[len] = '\0';
}

bool MyString::operator<(const MyString& p) {
    if(len < p.len)
        return true;
    return false;
}

bool MyString::operator>(const MyString& p) {
    if(len > p.len)
        return true;
    return false;
}

bool operator==(const MyString& p, const MyString& q) {
    if(p.len == q.len) {
        int k = 0;
        while(p.string[k] == q.string[k]) {
            k++;
        }
        if((k - 1) == p.len)
            return true;
    }
    return false;
}

MyString& MyString::operator=(const MyString& p) {
    delete [] string;
    len = p.len;
    string = new char[len + 1];
    for(int i = 0; i < len + 1; i ++) {
        string[i] = p.string[i];
    }
    return *this;
}

char& MyString::operator[](const int index) {
    return string[index];
}

const char& MyString::operator[](const int index) const {
    return string[index];
}

MyString operator+(const MyString& p, const MyString& q) {
    int leng = p.len + q.len;
    MyString temp(leng);
    if(leng == 0)
        return temp;
    for(int i = 0; i < p.len; i ++) {
        temp[i] = p[i];
    }
    for(int i = p.len - 1; i < leng; i ++) {
        temp[i] = q[i - p.len + 1];
    }
    return temp;
}
MyString operator+(const MyString& p, const char c) {
    int leng = p.len + 1;
    MyString temp(leng);
    for(int i = 0; i < p.len; i++) {
        temp[i] = p[i];
    }
    temp[leng] = c;
    return temp;
}

ostream& operator<<(ostream& t, const MyString& p) {
    for(int i = 0; i < p.len; i++) {
        t << p[i];
    }
    return t;
}

istream& operator>>(istream& t, MyString& p) {
    char *s = new char[256];
    t >> s;
    int k = 0;
    while(s[k] != '\0'){
        k++;
    }

    MyString temp;
    temp.SetStr(k, s);
    p = temp;
    return t;

}

MyString MyString::operator*(int k) {
    MyString temp(*this);

    if (k == 1)
        return *this;

    for(int i = 0; i < k - 1; i++) {
        temp = temp + *this;
    }
    return temp;

}

int MyString::Find(char c) {

    for(int i = 0; i < len; i++) {
        if(string[i] == c)
            return i;
    }
    return -1;

}

int MyString::Find(const MyString word) {

    int count;

    for(int i = 0; i < len; i++) {
        count = 0;
        for(int j = 0; j < word.len; j ++) {
            if(this[j + i] == word[j])
                count++;
        }
        if(count == word.len)
            return i;
    }
    return -1;

}

void MyString::Split(MyString **p, int& counter, char c) {
    if (p != 0) {
        delete [] p;
        p = 0;
    }
    int count = 0, pointer = 0, k, e;
    for(int i = 0; i < len; i++) {
        if(string[i] == c)
            count++;
    }

    if (count == 0) {
        p = new MyString*(this);
    }
    p = new MyString*[count + 1];
    counter = count;


    for(int i = 0; i < count; i++) {
        k = pointer;
        while(string[pointer] != c)
            pointer++;

        p[i] = new MyString(pointer - k);
        e = 0;
        for(int j = k; j < pointer; j++) {
            p[i][e] = this[j];
            e++;
        }

    }

}

void MyString::FindAll(const MyString word, int& counter, int *index) {
    if (word == 0) {
        counter = 0;
        index = 0;
        return;
    }
    if (index != 0) {
        delete [] index;
        index = 0;
    }
    counter = 0;
    int check, count = 0;

    for(int i = 0; i < len; i++) {
        check = 0;
        for(int j = 0; j < word.len; j++) {
            if (this[j + i] == word[j])
                check++;
        }
        if (check == word.len)
            counter++;
    }

    index = new int[counter];

    for(int i = 0; i < len; i++) {
        check = 0;
        for(int j = 0; j < word.len; j++) {
            if (this[j + i] == word[j])
                check++;
        }
        if (check == word.len) {
            index[count] = i;
            count++;
        }

    }

}

void MyString::Characters(char *&l, int& size) {
    if(this == 0) {
        l = 0;
        size = 0;
        return;
    }
    if(l != 0) {
        delete [] l;
        l = 0;
    }
    char *temp = new char[len];
    int count = len, k = 0;


    for(int i = 0; i < len; i ++) {
        if(temp[i] == -1)
            continue;

        temp[i] = string[i];

        for(int j = i + 1; j < len; j++) {
            if(temp[i] == string[j]) {
                temp[j] = -1;
                count--;
            }
        }
    }

    l = new char[count + 1];
    size = count;


    for(int i = 0; i < len; i++) {
        if(temp[i] != -1) {
            l[k] = temp[i];
            k++;
        }
    }
    l[count] = '\0';
}

void MyString::CharQuantity(char *&l, int *&u, int& size) {
    Characters(l, size);
    if(size == 0)
        return;
    if(u == 0) {
        delete [] u;
        u = 0;
    }

    u = new int[size];

    for(int i = 0; i < size; i++) {
        u[i] = 0;
        for(int j = 0; j < len; j++) {
            if(l[i] == string[j])
                u[i]++;
        }
    }
}

char MyString::MostFreq() {
    char *l;
    int *u;
    int size, max = 0;
    CharQuantity(l, u, size);

    for(int i = 0; i < size; i++) {
        if(u[i] >= max)
            max = u[i];
    }
    return l[max];
}