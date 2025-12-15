#pragma once
#include<windows.h>

//Settings and constants
using namespace std;

enum enEntity{enBlock,enEmpty,enPlayer,enMonster,enKey};

enum MovementDirection
{E_up = 72,E_left = 75,E_right = 77,E_down = 80};

void setColor(int color){
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color);
 }

void SetCursor(int x, int y) {
    std::cout << "\033[" << y + 1 << ";" << x + 1 << "H";
}

void HideCursor() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(consoleHandle, &cursorInfo);
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}

template <class T>
class Vector
{
  T *arr;
  int capacity;
  int current_size;
  using iterator = T*;

  void expand()
  {
    capacity *= 2;
    T *newArr = new T[capacity];
    for (int i = 0; i < current_size; i++)
    {
      newArr[i] = arr[i];
    }
    delete[] arr;
    arr = newArr;
  }

public:
  Vector()
  {
    capacity = 10;
    current_size = 0;
    arr = new T[capacity];
  }

  Vector(int size)
  {
    if (size < 0)
      size = 10;
    current_size = size;
    capacity = size * 2;
    arr = new T[capacity];

    for (int i = 0; i < current_size; i++)
      arr[i] = T();
  }

  ~Vector()
  {
    delete[] arr;
  }

  void push_back(T element)
  {
    if (current_size == capacity)
    {
      expand();
    }
    arr[current_size++] = element;
  }

  int size()
  {
    return current_size;
  }

  T &operator[](int index)
  {
    if (index < 0 || index >= current_size)
    {
      cout << "Out of range!\n";
      return arr[0];
    }
    return arr[index];
  }
  iterator erase(int index)
    {
        iterator position = arr + index;
        if (position < arr || position >= arr + current_size)
        {
           return arr + current_size;
        }
        int index_to_erase = position - arr;
        for (int i = index_to_erase; i < current_size - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        current_size--;

        return position;
    }
};

template <class t>
class Stack
{
    struct node
    {
        t item;
        node* next;
    };

    node* Top;

public:
    Stack()
    {
        Top = NULL;
    }

    // Destructor: Cleans up memory when the Stack object is destroyed
    ~Stack()
    {
        while (!empty())
        {
            pop(); // Reusing pop to delete nodes one by one
        }
    }

    void push(t newItem)
    {
        node* newItemPtr = new node;

        // Always check for memory allocation failure
        if (newItemPtr == NULL)
            cout << "Stack push cannot allocate memory";
        else
        {
            newItemPtr->item = newItem;
            newItemPtr->next = Top;
            Top = newItemPtr;
        }
    }

    bool empty()
    {
        return Top == NULL;
    }

    t top()
    {
        // Safety check to prevent crashing on empty stack
        if (empty())
        {
            cout << "Stack is empty, returning default value.\n";
            return t(); // Returns default value (e.g., 0 for int)
        }
        return Top->item;
    }

    void pop()
    {
        if (empty())
            cout << "Stack empty on pop";
        else
        {
            node* temp = Top;
            Top = Top->next;
            temp->next = NULL;
            delete temp;
        }
    }
};



